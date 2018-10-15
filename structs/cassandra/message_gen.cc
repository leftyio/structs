#include "structs/cassandra/message_gen.h"

#include <algorithm>
#include <list>

#include "glog/logging.h"
#include "google/protobuf/descriptor.pb.h"

namespace structs {
MessageGen::MessageGen(const CassandraSchema* schema,
                       const Descriptor* descriptor) : schema_(schema),
                                                       descriptor_(descriptor) {
}

MessageGen::~MessageGen() {
}

void MessageGen::AddField(const FieldGen& field) {
  fields_.push_back(field);
}

const FieldGen* MessageGen::FieldNamedId() const {
  for (const auto& field : fields_) {
    if (field.CassandraName() == "id") {
      return &field;
    }
  }

  return nullptr;
}

struct ByIdCardinality {
  int operator()(const FieldGen* x, const FieldGen* y) {
    CHECK(x->IdCardinality() != y->IdCardinality()) << "duplicate cardinality, " << x->IdCardinality();
    return x->IdCardinality() < y->IdCardinality();
  }
};

std::string MessageGen::TableName() const {
  if (!schema_->table_name().empty()) {
    return schema_->table_name();
  }

  std::string full_name = descriptor_->full_name();
  for (std::size_t i = 0; i < full_name.size(); ++i) {
    if (full_name[i] == '.') {
      full_name[i] = '_';
    }
  }

  return full_name;
}

std::string MessageGen::Pkg() const {
  return descriptor_->file()->package();
}

std::string MessageGen::JavaClass() const {
  return descriptor_->name();
}

std::string MessageGen::JavaPkg() const {
  std::string java_pkg = "";
  if (!schema_->java_package().empty()) {
    java_pkg = schema_->java_package();
  } else {
    const auto& opts = descriptor_->file()->options();
    if (!opts.java_package().empty()) {
      java_pkg = opts.java_package();
    } else {
      java_pkg = descriptor_->file()->package();
    }
  }
  
  return java_pkg;
}

std::string MessageGen::CompressionStrategy() const {
  if (!schema_->compression_strategy().empty()) {
    return schema_->compression_strategy();
  } else {
    return "SnappyCompressor";
  }
}

std::string MessageGen::CompactionStrategy() const {
  if (!schema_->compaction_strategy().empty()) {
    return schema_->compaction_strategy();
  } else {
    return "LeveledCompactionStrategy";
  }
}

std::vector<const FieldGen*> MessageGen::Fields() const {
  std::vector<const FieldGen*> res;

  for (const auto& field : fields_) {
    res.push_back(&field);
  }

  return res;
}

std::vector<std::string> MessageGen::Ids() const {
  std::vector<std::string> ids;

  for (const auto* field : IdFields()) {
    ids.push_back(field->CassandraName());
  }

  return ids;
}

std::vector<const FieldGen*> MessageGen::IdFields() const {
  std::vector<const FieldGen*> id_fields;

  for (const auto& field : fields_) {
    if (field.IsId()) {
      id_fields.push_back(&field);
    }
  }

  if (id_fields.empty()) {
    const FieldGen* field_named_id = FieldNamedId();
    if (field_named_id != nullptr) {
      LOG(INFO) << "no id was defined, we will use the field named \"id\" as an id";
      id_fields.push_back(field_named_id);
    } else {
      LOG(FATAL) << "couldn't build a PRIMARY KEY for table: " << TableName();
    }
  }

  if (id_fields.size() > 1) {
    for (const FieldGen* field : id_fields) {
      int cardinality = field->IdCardinality();
      CHECK(cardinality > 0) << "Multiple ids are defined so cardinality must be set on field: "
          << field->CassandraName();
    }

    std::sort(id_fields.begin(), id_fields.end(), ByIdCardinality());
  }

  return id_fields;
}
}  // namespace structs
