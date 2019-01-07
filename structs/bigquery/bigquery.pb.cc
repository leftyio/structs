// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: structs/bigquery/bigquery.proto

#include "structs/bigquery/bigquery.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace structs {
class BigQueryFieldDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<BigQueryField>
      _instance;
} _BigQueryField_default_instance_;
class BigQuerySchemaDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<BigQuerySchema>
      _instance;
} _BigQuerySchema_default_instance_;
class BigQuerySchemasDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<BigQuerySchemas>
      _instance;
} _BigQuerySchemas_default_instance_;
}  // namespace structs
namespace protobuf_structs_2fbigquery_2fbigquery_2eproto {
void InitDefaultsBigQueryFieldImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::structs::_BigQueryField_default_instance_;
    new (ptr) ::structs::BigQueryField();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::structs::BigQueryField::InitAsDefaultInstance();
}

void InitDefaultsBigQueryField() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsBigQueryFieldImpl);
}

void InitDefaultsBigQuerySchemaImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_structs_2fstructs_2eproto::InitDefaultsStructSchema();
  {
    void* ptr = &::structs::_BigQuerySchema_default_instance_;
    new (ptr) ::structs::BigQuerySchema();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::structs::BigQuerySchema::InitAsDefaultInstance();
}

void InitDefaultsBigQuerySchema() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsBigQuerySchemaImpl);
}

void InitDefaultsBigQuerySchemasImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_structs_2fbigquery_2fbigquery_2eproto::InitDefaultsBigQuerySchema();
  {
    void* ptr = &::structs::_BigQuerySchemas_default_instance_;
    new (ptr) ::structs::BigQuerySchemas();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::structs::BigQuerySchemas::InitAsDefaultInstance();
}

void InitDefaultsBigQuerySchemas() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsBigQuerySchemasImpl);
}

::google::protobuf::Metadata file_level_metadata[3];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::structs::BigQueryField, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::structs::BigQuerySchema, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::structs::BigQuerySchema, structs_schema_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::structs::BigQuerySchema, bigquery_table_name_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::structs::BigQuerySchemas, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::structs::BigQuerySchemas, schema_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::structs::BigQueryField)},
  { 5, -1, sizeof(::structs::BigQuerySchema)},
  { 12, -1, sizeof(::structs::BigQuerySchemas)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::structs::_BigQueryField_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::structs::_BigQuerySchema_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::structs::_BigQuerySchemas_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "structs/bigquery/bigquery.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 3);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\037structs/bigquery/bigquery.proto\022\007struc"
      "ts\032\025structs/structs.proto\"\017\n\rBigQueryFie"
      "ld\"\\\n\016BigQuerySchema\022-\n\016structs_schema\030\001"
      " \001(\0132\025.structs.StructSchema\022\033\n\023bigquery_"
      "table_name\030\002 \001(\t\":\n\017BigQuerySchemas\022\'\n\006s"
      "chema\030\001 \003(\0132\027.structs.BigQuerySchemab\006pr"
      "oto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 244);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "structs/bigquery/bigquery.proto", &protobuf_RegisterTypes);
  ::protobuf_structs_2fstructs_2eproto::AddDescriptors();
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_structs_2fbigquery_2fbigquery_2eproto
namespace structs {

// ===================================================================

void BigQueryField::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

BigQueryField::BigQueryField()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_structs_2fbigquery_2fbigquery_2eproto::InitDefaultsBigQueryField();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:structs.BigQueryField)
}
BigQueryField::BigQueryField(const BigQueryField& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:structs.BigQueryField)
}

void BigQueryField::SharedCtor() {
  _cached_size_ = 0;
}

BigQueryField::~BigQueryField() {
  // @@protoc_insertion_point(destructor:structs.BigQueryField)
  SharedDtor();
}

void BigQueryField::SharedDtor() {
}

void BigQueryField::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BigQueryField::descriptor() {
  ::protobuf_structs_2fbigquery_2fbigquery_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_structs_2fbigquery_2fbigquery_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const BigQueryField& BigQueryField::default_instance() {
  ::protobuf_structs_2fbigquery_2fbigquery_2eproto::InitDefaultsBigQueryField();
  return *internal_default_instance();
}

BigQueryField* BigQueryField::New(::google::protobuf::Arena* arena) const {
  BigQueryField* n = new BigQueryField;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void BigQueryField::Clear() {
// @@protoc_insertion_point(message_clear_start:structs.BigQueryField)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _internal_metadata_.Clear();
}

bool BigQueryField::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:structs.BigQueryField)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, _internal_metadata_.mutable_unknown_fields()));
  }
success:
  // @@protoc_insertion_point(parse_success:structs.BigQueryField)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:structs.BigQueryField)
  return false;
#undef DO_
}

void BigQueryField::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:structs.BigQueryField)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:structs.BigQueryField)
}

::google::protobuf::uint8* BigQueryField::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:structs.BigQueryField)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:structs.BigQueryField)
  return target;
}

size_t BigQueryField::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:structs.BigQueryField)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void BigQueryField::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:structs.BigQueryField)
  GOOGLE_DCHECK_NE(&from, this);
  const BigQueryField* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const BigQueryField>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:structs.BigQueryField)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:structs.BigQueryField)
    MergeFrom(*source);
  }
}

void BigQueryField::MergeFrom(const BigQueryField& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:structs.BigQueryField)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

}

void BigQueryField::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:structs.BigQueryField)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BigQueryField::CopyFrom(const BigQueryField& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:structs.BigQueryField)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BigQueryField::IsInitialized() const {
  return true;
}

void BigQueryField::Swap(BigQueryField* other) {
  if (other == this) return;
  InternalSwap(other);
}
void BigQueryField::InternalSwap(BigQueryField* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata BigQueryField::GetMetadata() const {
  protobuf_structs_2fbigquery_2fbigquery_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_structs_2fbigquery_2fbigquery_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void BigQuerySchema::InitAsDefaultInstance() {
  ::structs::_BigQuerySchema_default_instance_._instance.get_mutable()->structs_schema_ = const_cast< ::structs::StructSchema*>(
      ::structs::StructSchema::internal_default_instance());
}
void BigQuerySchema::clear_structs_schema() {
  if (GetArenaNoVirtual() == NULL && structs_schema_ != NULL) {
    delete structs_schema_;
  }
  structs_schema_ = NULL;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int BigQuerySchema::kStructsSchemaFieldNumber;
const int BigQuerySchema::kBigqueryTableNameFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

BigQuerySchema::BigQuerySchema()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_structs_2fbigquery_2fbigquery_2eproto::InitDefaultsBigQuerySchema();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:structs.BigQuerySchema)
}
BigQuerySchema::BigQuerySchema(const BigQuerySchema& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  bigquery_table_name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.bigquery_table_name().size() > 0) {
    bigquery_table_name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.bigquery_table_name_);
  }
  if (from.has_structs_schema()) {
    structs_schema_ = new ::structs::StructSchema(*from.structs_schema_);
  } else {
    structs_schema_ = NULL;
  }
  // @@protoc_insertion_point(copy_constructor:structs.BigQuerySchema)
}

void BigQuerySchema::SharedCtor() {
  bigquery_table_name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  structs_schema_ = NULL;
  _cached_size_ = 0;
}

BigQuerySchema::~BigQuerySchema() {
  // @@protoc_insertion_point(destructor:structs.BigQuerySchema)
  SharedDtor();
}

void BigQuerySchema::SharedDtor() {
  bigquery_table_name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete structs_schema_;
}

void BigQuerySchema::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BigQuerySchema::descriptor() {
  ::protobuf_structs_2fbigquery_2fbigquery_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_structs_2fbigquery_2fbigquery_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const BigQuerySchema& BigQuerySchema::default_instance() {
  ::protobuf_structs_2fbigquery_2fbigquery_2eproto::InitDefaultsBigQuerySchema();
  return *internal_default_instance();
}

BigQuerySchema* BigQuerySchema::New(::google::protobuf::Arena* arena) const {
  BigQuerySchema* n = new BigQuerySchema;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void BigQuerySchema::Clear() {
// @@protoc_insertion_point(message_clear_start:structs.BigQuerySchema)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  bigquery_table_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (GetArenaNoVirtual() == NULL && structs_schema_ != NULL) {
    delete structs_schema_;
  }
  structs_schema_ = NULL;
  _internal_metadata_.Clear();
}

bool BigQuerySchema::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:structs.BigQuerySchema)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .structs.StructSchema structs_schema = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_structs_schema()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string bigquery_table_name = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_bigquery_table_name()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->bigquery_table_name().data(), static_cast<int>(this->bigquery_table_name().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "structs.BigQuerySchema.bigquery_table_name"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:structs.BigQuerySchema)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:structs.BigQuerySchema)
  return false;
#undef DO_
}

void BigQuerySchema::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:structs.BigQuerySchema)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .structs.StructSchema structs_schema = 1;
  if (this->has_structs_schema()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, *this->structs_schema_, output);
  }

  // string bigquery_table_name = 2;
  if (this->bigquery_table_name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->bigquery_table_name().data(), static_cast<int>(this->bigquery_table_name().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "structs.BigQuerySchema.bigquery_table_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->bigquery_table_name(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:structs.BigQuerySchema)
}

::google::protobuf::uint8* BigQuerySchema::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:structs.BigQuerySchema)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .structs.StructSchema structs_schema = 1;
  if (this->has_structs_schema()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, *this->structs_schema_, deterministic, target);
  }

  // string bigquery_table_name = 2;
  if (this->bigquery_table_name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->bigquery_table_name().data(), static_cast<int>(this->bigquery_table_name().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "structs.BigQuerySchema.bigquery_table_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->bigquery_table_name(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:structs.BigQuerySchema)
  return target;
}

size_t BigQuerySchema::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:structs.BigQuerySchema)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string bigquery_table_name = 2;
  if (this->bigquery_table_name().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->bigquery_table_name());
  }

  // .structs.StructSchema structs_schema = 1;
  if (this->has_structs_schema()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *this->structs_schema_);
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void BigQuerySchema::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:structs.BigQuerySchema)
  GOOGLE_DCHECK_NE(&from, this);
  const BigQuerySchema* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const BigQuerySchema>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:structs.BigQuerySchema)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:structs.BigQuerySchema)
    MergeFrom(*source);
  }
}

void BigQuerySchema::MergeFrom(const BigQuerySchema& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:structs.BigQuerySchema)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.bigquery_table_name().size() > 0) {

    bigquery_table_name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.bigquery_table_name_);
  }
  if (from.has_structs_schema()) {
    mutable_structs_schema()->::structs::StructSchema::MergeFrom(from.structs_schema());
  }
}

void BigQuerySchema::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:structs.BigQuerySchema)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BigQuerySchema::CopyFrom(const BigQuerySchema& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:structs.BigQuerySchema)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BigQuerySchema::IsInitialized() const {
  return true;
}

void BigQuerySchema::Swap(BigQuerySchema* other) {
  if (other == this) return;
  InternalSwap(other);
}
void BigQuerySchema::InternalSwap(BigQuerySchema* other) {
  using std::swap;
  bigquery_table_name_.Swap(&other->bigquery_table_name_);
  swap(structs_schema_, other->structs_schema_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata BigQuerySchema::GetMetadata() const {
  protobuf_structs_2fbigquery_2fbigquery_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_structs_2fbigquery_2fbigquery_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void BigQuerySchemas::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int BigQuerySchemas::kSchemaFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

BigQuerySchemas::BigQuerySchemas()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_structs_2fbigquery_2fbigquery_2eproto::InitDefaultsBigQuerySchemas();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:structs.BigQuerySchemas)
}
BigQuerySchemas::BigQuerySchemas(const BigQuerySchemas& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      schema_(from.schema_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:structs.BigQuerySchemas)
}

void BigQuerySchemas::SharedCtor() {
  _cached_size_ = 0;
}

BigQuerySchemas::~BigQuerySchemas() {
  // @@protoc_insertion_point(destructor:structs.BigQuerySchemas)
  SharedDtor();
}

void BigQuerySchemas::SharedDtor() {
}

void BigQuerySchemas::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BigQuerySchemas::descriptor() {
  ::protobuf_structs_2fbigquery_2fbigquery_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_structs_2fbigquery_2fbigquery_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const BigQuerySchemas& BigQuerySchemas::default_instance() {
  ::protobuf_structs_2fbigquery_2fbigquery_2eproto::InitDefaultsBigQuerySchemas();
  return *internal_default_instance();
}

BigQuerySchemas* BigQuerySchemas::New(::google::protobuf::Arena* arena) const {
  BigQuerySchemas* n = new BigQuerySchemas;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void BigQuerySchemas::Clear() {
// @@protoc_insertion_point(message_clear_start:structs.BigQuerySchemas)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  schema_.Clear();
  _internal_metadata_.Clear();
}

bool BigQuerySchemas::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:structs.BigQuerySchemas)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .structs.BigQuerySchema schema = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(input, add_schema()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:structs.BigQuerySchemas)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:structs.BigQuerySchemas)
  return false;
#undef DO_
}

void BigQuerySchemas::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:structs.BigQuerySchemas)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .structs.BigQuerySchema schema = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->schema_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->schema(static_cast<int>(i)), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:structs.BigQuerySchemas)
}

::google::protobuf::uint8* BigQuerySchemas::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:structs.BigQuerySchemas)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .structs.BigQuerySchema schema = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->schema_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->schema(static_cast<int>(i)), deterministic, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:structs.BigQuerySchemas)
  return target;
}

size_t BigQuerySchemas::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:structs.BigQuerySchemas)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .structs.BigQuerySchema schema = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->schema_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->schema(static_cast<int>(i)));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void BigQuerySchemas::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:structs.BigQuerySchemas)
  GOOGLE_DCHECK_NE(&from, this);
  const BigQuerySchemas* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const BigQuerySchemas>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:structs.BigQuerySchemas)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:structs.BigQuerySchemas)
    MergeFrom(*source);
  }
}

void BigQuerySchemas::MergeFrom(const BigQuerySchemas& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:structs.BigQuerySchemas)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  schema_.MergeFrom(from.schema_);
}

void BigQuerySchemas::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:structs.BigQuerySchemas)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BigQuerySchemas::CopyFrom(const BigQuerySchemas& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:structs.BigQuerySchemas)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BigQuerySchemas::IsInitialized() const {
  return true;
}

void BigQuerySchemas::Swap(BigQuerySchemas* other) {
  if (other == this) return;
  InternalSwap(other);
}
void BigQuerySchemas::InternalSwap(BigQuerySchemas* other) {
  using std::swap;
  schema_.InternalSwap(&other->schema_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata BigQuerySchemas::GetMetadata() const {
  protobuf_structs_2fbigquery_2fbigquery_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_structs_2fbigquery_2fbigquery_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace structs

// @@protoc_insertion_point(global_scope)
