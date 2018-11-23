#include "structs/cassandra/message_gen.h"

#include <algorithm>
#include <list>

#include "glog/logging.h"
#include "google/protobuf/compiler/java/java_names.h"
#include "google/protobuf/descriptor.pb.h"

using google::protobuf::Descriptor;
using google::protobuf::FieldDescriptor;
using google::protobuf::FileDescriptor;

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
  if (schema_ != nullptr) {
    if (!schema_->java_class().empty()) {
      return schema_->java_class();
    }
  }

  return google::protobuf::compiler::java::ClassName(descriptor_) + "CassandraStruct";
}

std::string MessageGen::JavaClassOfMessage() const {
  return google::protobuf::compiler::java::ClassName(descriptor_);
}

const char* kDefaultPackage = "";
std::string MessageGen::JavaPkg() const {
  std::string result;
  const FileDescriptor* file = descriptor_->file();

  if (file->options().has_java_package()) {
    result = file->options().java_package();
  } else {
    result = kDefaultPackage;
    if (!file->package().empty()) {
      if (!result.empty()) result += '.';
      result += file->package();
    }
  }

  return result;
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
