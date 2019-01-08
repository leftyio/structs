// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: structs/structs.proto

#include "structs/structs.pb.h"

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
class StructFieldDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<StructField>
      _instance;
} _StructField_default_instance_;
class StructSchemaDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<StructSchema>
      _instance;
} _StructSchema_default_instance_;
}  // namespace structs
namespace protobuf_structs_2fstructs_2eproto {
void InitDefaultsStructFieldImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::structs::_StructField_default_instance_;
    new (ptr) ::structs::StructField();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::structs::StructField::InitAsDefaultInstance();
}

void InitDefaultsStructField() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsStructFieldImpl);
}

void InitDefaultsStructSchemaImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::structs::_StructSchema_default_instance_;
    new (ptr) ::structs::StructSchema();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::structs::StructSchema::InitAsDefaultInstance();
}

void InitDefaultsStructSchema() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsStructSchemaImpl);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::structs::StructField, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::structs::StructField, path_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::structs::StructField, structs_transient_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::structs::StructSchema, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::structs::StructSchema, message_name_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::structs::StructSchema, java_package_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::structs::StructSchema, java_class_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::structs::StructField)},
  { 7, -1, sizeof(::structs::StructSchema)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::structs::_StructField_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::structs::_StructSchema_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "structs/structs.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\025structs/structs.proto\022\007structs\"6\n\013Stru"
      "ctField\022\014\n\004path\030\001 \001(\t\022\031\n\021structs_transie"
      "nt\030\002 \001(\010\"N\n\014StructSchema\022\024\n\014message_name"
      "\030\001 \001(\t\022\024\n\014java_package\030\002 \001(\t\022\022\n\njava_cla"
      "ss\030\003 \001(\tb\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 176);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "structs/structs.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_structs_2fstructs_2eproto
namespace structs {

// ===================================================================

void StructField::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int StructField::kPathFieldNumber;
const int StructField::kStructsTransientFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

StructField::StructField()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_structs_2fstructs_2eproto::InitDefaultsStructField();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:structs.StructField)
}
StructField::StructField(const StructField& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  path_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.path().size() > 0) {
    path_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.path_);
  }
  structs_transient_ = from.structs_transient_;
  // @@protoc_insertion_point(copy_constructor:structs.StructField)
}

void StructField::SharedCtor() {
  path_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  structs_transient_ = false;
  _cached_size_ = 0;
}

StructField::~StructField() {
  // @@protoc_insertion_point(destructor:structs.StructField)
  SharedDtor();
}

void StructField::SharedDtor() {
  path_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void StructField::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* StructField::descriptor() {
  ::protobuf_structs_2fstructs_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_structs_2fstructs_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const StructField& StructField::default_instance() {
  ::protobuf_structs_2fstructs_2eproto::InitDefaultsStructField();
  return *internal_default_instance();
}

StructField* StructField::New(::google::protobuf::Arena* arena) const {
  StructField* n = new StructField;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void StructField::Clear() {
// @@protoc_insertion_point(message_clear_start:structs.StructField)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  path_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  structs_transient_ = false;
  _internal_metadata_.Clear();
}

bool StructField::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:structs.StructField)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string path = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_path()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->path().data(), static_cast<int>(this->path().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "structs.StructField.path"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool structs_transient = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &structs_transient_)));
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
  // @@protoc_insertion_point(parse_success:structs.StructField)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:structs.StructField)
  return false;
#undef DO_
}

void StructField::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:structs.StructField)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string path = 1;
  if (this->path().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->path().data(), static_cast<int>(this->path().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "structs.StructField.path");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->path(), output);
  }

  // bool structs_transient = 2;
  if (this->structs_transient() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->structs_transient(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:structs.StructField)
}

::google::protobuf::uint8* StructField::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:structs.StructField)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string path = 1;
  if (this->path().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->path().data(), static_cast<int>(this->path().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "structs.StructField.path");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->path(), target);
  }

  // bool structs_transient = 2;
  if (this->structs_transient() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->structs_transient(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:structs.StructField)
  return target;
}

size_t StructField::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:structs.StructField)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string path = 1;
  if (this->path().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->path());
  }

  // bool structs_transient = 2;
  if (this->structs_transient() != 0) {
    total_size += 1 + 1;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void StructField::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:structs.StructField)
  GOOGLE_DCHECK_NE(&from, this);
  const StructField* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const StructField>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:structs.StructField)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:structs.StructField)
    MergeFrom(*source);
  }
}

void StructField::MergeFrom(const StructField& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:structs.StructField)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.path().size() > 0) {

    path_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.path_);
  }
  if (from.structs_transient() != 0) {
    set_structs_transient(from.structs_transient());
  }
}

void StructField::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:structs.StructField)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void StructField::CopyFrom(const StructField& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:structs.StructField)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool StructField::IsInitialized() const {
  return true;
}

void StructField::Swap(StructField* other) {
  if (other == this) return;
  InternalSwap(other);
}
void StructField::InternalSwap(StructField* other) {
  using std::swap;
  path_.Swap(&other->path_);
  swap(structs_transient_, other->structs_transient_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata StructField::GetMetadata() const {
  protobuf_structs_2fstructs_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_structs_2fstructs_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void StructSchema::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int StructSchema::kMessageNameFieldNumber;
const int StructSchema::kJavaPackageFieldNumber;
const int StructSchema::kJavaClassFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

StructSchema::StructSchema()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_structs_2fstructs_2eproto::InitDefaultsStructSchema();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:structs.StructSchema)
}
StructSchema::StructSchema(const StructSchema& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  message_name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.message_name().size() > 0) {
    message_name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.message_name_);
  }
  java_package_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.java_package().size() > 0) {
    java_package_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.java_package_);
  }
  java_class_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.java_class().size() > 0) {
    java_class_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.java_class_);
  }
  // @@protoc_insertion_point(copy_constructor:structs.StructSchema)
}

void StructSchema::SharedCtor() {
  message_name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  java_package_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  java_class_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _cached_size_ = 0;
}

StructSchema::~StructSchema() {
  // @@protoc_insertion_point(destructor:structs.StructSchema)
  SharedDtor();
}

void StructSchema::SharedDtor() {
  message_name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  java_package_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  java_class_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void StructSchema::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* StructSchema::descriptor() {
  ::protobuf_structs_2fstructs_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_structs_2fstructs_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const StructSchema& StructSchema::default_instance() {
  ::protobuf_structs_2fstructs_2eproto::InitDefaultsStructSchema();
  return *internal_default_instance();
}

StructSchema* StructSchema::New(::google::protobuf::Arena* arena) const {
  StructSchema* n = new StructSchema;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void StructSchema::Clear() {
// @@protoc_insertion_point(message_clear_start:structs.StructSchema)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  message_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  java_package_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  java_class_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

bool StructSchema::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:structs.StructSchema)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string message_name = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_message_name()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->message_name().data(), static_cast<int>(this->message_name().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "structs.StructSchema.message_name"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string java_package = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_java_package()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->java_package().data(), static_cast<int>(this->java_package().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "structs.StructSchema.java_package"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string java_class = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_java_class()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->java_class().data(), static_cast<int>(this->java_class().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "structs.StructSchema.java_class"));
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
  // @@protoc_insertion_point(parse_success:structs.StructSchema)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:structs.StructSchema)
  return false;
#undef DO_
}

void StructSchema::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:structs.StructSchema)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string message_name = 1;
  if (this->message_name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->message_name().data(), static_cast<int>(this->message_name().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "structs.StructSchema.message_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->message_name(), output);
  }

  // string java_package = 2;
  if (this->java_package().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->java_package().data(), static_cast<int>(this->java_package().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "structs.StructSchema.java_package");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->java_package(), output);
  }

  // string java_class = 3;
  if (this->java_class().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->java_class().data(), static_cast<int>(this->java_class().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "structs.StructSchema.java_class");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->java_class(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:structs.StructSchema)
}

::google::protobuf::uint8* StructSchema::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:structs.StructSchema)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string message_name = 1;
  if (this->message_name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->message_name().data(), static_cast<int>(this->message_name().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "structs.StructSchema.message_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->message_name(), target);
  }

  // string java_package = 2;
  if (this->java_package().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->java_package().data(), static_cast<int>(this->java_package().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "structs.StructSchema.java_package");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->java_package(), target);
  }

  // string java_class = 3;
  if (this->java_class().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->java_class().data(), static_cast<int>(this->java_class().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "structs.StructSchema.java_class");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->java_class(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:structs.StructSchema)
  return target;
}

size_t StructSchema::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:structs.StructSchema)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string message_name = 1;
  if (this->message_name().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->message_name());
  }

  // string java_package = 2;
  if (this->java_package().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->java_package());
  }

  // string java_class = 3;
  if (this->java_class().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->java_class());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void StructSchema::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:structs.StructSchema)
  GOOGLE_DCHECK_NE(&from, this);
  const StructSchema* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const StructSchema>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:structs.StructSchema)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:structs.StructSchema)
    MergeFrom(*source);
  }
}

void StructSchema::MergeFrom(const StructSchema& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:structs.StructSchema)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.message_name().size() > 0) {

    message_name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.message_name_);
  }
  if (from.java_package().size() > 0) {

    java_package_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.java_package_);
  }
  if (from.java_class().size() > 0) {

    java_class_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.java_class_);
  }
}

void StructSchema::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:structs.StructSchema)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void StructSchema::CopyFrom(const StructSchema& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:structs.StructSchema)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool StructSchema::IsInitialized() const {
  return true;
}

void StructSchema::Swap(StructSchema* other) {
  if (other == this) return;
  InternalSwap(other);
}
void StructSchema::InternalSwap(StructSchema* other) {
  using std::swap;
  message_name_.Swap(&other->message_name_);
  java_package_.Swap(&other->java_package_);
  java_class_.Swap(&other->java_class_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata StructSchema::GetMetadata() const {
  protobuf_structs_2fstructs_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_structs_2fstructs_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace structs

// @@protoc_insertion_point(global_scope)