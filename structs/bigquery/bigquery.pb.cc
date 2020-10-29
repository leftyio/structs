// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: structs/bigquery/bigquery.proto

#include "structs/bigquery/bigquery.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_structs_2fbigquery_2fbigquery_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_BigQuerySchema_structs_2fbigquery_2fbigquery_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_structs_2fstructs_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_StructSchema_structs_2fstructs_2eproto;
namespace structs {
class BigQueryFieldDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<BigQueryField> _instance;
} _BigQueryField_default_instance_;
class BigQuerySchemaDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<BigQuerySchema> _instance;
} _BigQuerySchema_default_instance_;
class BigQuerySchemasDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<BigQuerySchemas> _instance;
} _BigQuerySchemas_default_instance_;
}  // namespace structs
static void InitDefaultsscc_info_BigQueryField_structs_2fbigquery_2fbigquery_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::structs::_BigQueryField_default_instance_;
    new (ptr) ::structs::BigQueryField();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::structs::BigQueryField::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_BigQueryField_structs_2fbigquery_2fbigquery_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_BigQueryField_structs_2fbigquery_2fbigquery_2eproto}, {}};

static void InitDefaultsscc_info_BigQuerySchema_structs_2fbigquery_2fbigquery_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::structs::_BigQuerySchema_default_instance_;
    new (ptr) ::structs::BigQuerySchema();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::structs::BigQuerySchema::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_BigQuerySchema_structs_2fbigquery_2fbigquery_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_BigQuerySchema_structs_2fbigquery_2fbigquery_2eproto}, {
      &scc_info_StructSchema_structs_2fstructs_2eproto.base,}};

static void InitDefaultsscc_info_BigQuerySchemas_structs_2fbigquery_2fbigquery_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::structs::_BigQuerySchemas_default_instance_;
    new (ptr) ::structs::BigQuerySchemas();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::structs::BigQuerySchemas::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_BigQuerySchemas_structs_2fbigquery_2fbigquery_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_BigQuerySchemas_structs_2fbigquery_2fbigquery_2eproto}, {
      &scc_info_BigQuerySchema_structs_2fbigquery_2fbigquery_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_structs_2fbigquery_2fbigquery_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_structs_2fbigquery_2fbigquery_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_structs_2fbigquery_2fbigquery_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_structs_2fbigquery_2fbigquery_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::structs::BigQueryField, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::structs::BigQuerySchema, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::structs::BigQuerySchema, structs_schema_),
  PROTOBUF_FIELD_OFFSET(::structs::BigQuerySchema, bigquery_table_name_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::structs::BigQuerySchemas, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::structs::BigQuerySchemas, schema_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::structs::BigQueryField)},
  { 5, -1, sizeof(::structs::BigQuerySchema)},
  { 12, -1, sizeof(::structs::BigQuerySchemas)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::structs::_BigQueryField_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::structs::_BigQuerySchema_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::structs::_BigQuerySchemas_default_instance_),
};

const char descriptor_table_protodef_structs_2fbigquery_2fbigquery_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\037structs/bigquery/bigquery.proto\022\007struc"
  "ts\032\025structs/structs.proto\"\017\n\rBigQueryFie"
  "ld\"\\\n\016BigQuerySchema\022-\n\016structs_schema\030\001"
  " \001(\0132\025.structs.StructSchema\022\033\n\023bigquery_"
  "table_name\030\002 \001(\t\":\n\017BigQuerySchemas\022\'\n\006s"
  "chema\030\001 \003(\0132\027.structs.BigQuerySchemab\006pr"
  "oto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_structs_2fbigquery_2fbigquery_2eproto_deps[1] = {
  &::descriptor_table_structs_2fstructs_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_structs_2fbigquery_2fbigquery_2eproto_sccs[3] = {
  &scc_info_BigQueryField_structs_2fbigquery_2fbigquery_2eproto.base,
  &scc_info_BigQuerySchema_structs_2fbigquery_2fbigquery_2eproto.base,
  &scc_info_BigQuerySchemas_structs_2fbigquery_2fbigquery_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_structs_2fbigquery_2fbigquery_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_structs_2fbigquery_2fbigquery_2eproto = {
  false, false, descriptor_table_protodef_structs_2fbigquery_2fbigquery_2eproto, "structs/bigquery/bigquery.proto", 244,
  &descriptor_table_structs_2fbigquery_2fbigquery_2eproto_once, descriptor_table_structs_2fbigquery_2fbigquery_2eproto_sccs, descriptor_table_structs_2fbigquery_2fbigquery_2eproto_deps, 3, 1,
  schemas, file_default_instances, TableStruct_structs_2fbigquery_2fbigquery_2eproto::offsets,
  file_level_metadata_structs_2fbigquery_2fbigquery_2eproto, 3, file_level_enum_descriptors_structs_2fbigquery_2fbigquery_2eproto, file_level_service_descriptors_structs_2fbigquery_2fbigquery_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_structs_2fbigquery_2fbigquery_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_structs_2fbigquery_2fbigquery_2eproto)), true);
namespace structs {

// ===================================================================

void BigQueryField::InitAsDefaultInstance() {
}
class BigQueryField::_Internal {
 public:
};

BigQueryField::BigQueryField(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:structs.BigQueryField)
}
BigQueryField::BigQueryField(const BigQueryField& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:structs.BigQueryField)
}

void BigQueryField::SharedCtor() {
}

BigQueryField::~BigQueryField() {
  // @@protoc_insertion_point(destructor:structs.BigQueryField)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void BigQueryField::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void BigQueryField::ArenaDtor(void* object) {
  BigQueryField* _this = reinterpret_cast< BigQueryField* >(object);
  (void)_this;
}
void BigQueryField::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void BigQueryField::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const BigQueryField& BigQueryField::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_BigQueryField_structs_2fbigquery_2fbigquery_2eproto.base);
  return *internal_default_instance();
}


void BigQueryField::Clear() {
// @@protoc_insertion_point(message_clear_start:structs.BigQueryField)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* BigQueryField::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* BigQueryField::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:structs.BigQueryField)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:structs.BigQueryField)
  return target;
}

size_t BigQueryField::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:structs.BigQueryField)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void BigQueryField::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:structs.BigQueryField)
  GOOGLE_DCHECK_NE(&from, this);
  const BigQueryField* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<BigQueryField>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:structs.BigQueryField)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:structs.BigQueryField)
    MergeFrom(*source);
  }
}

void BigQueryField::MergeFrom(const BigQueryField& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:structs.BigQueryField)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

}

void BigQueryField::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
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

void BigQueryField::InternalSwap(BigQueryField* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
}

::PROTOBUF_NAMESPACE_ID::Metadata BigQueryField::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void BigQuerySchema::InitAsDefaultInstance() {
  ::structs::_BigQuerySchema_default_instance_._instance.get_mutable()->structs_schema_ = const_cast< ::structs::StructSchema*>(
      ::structs::StructSchema::internal_default_instance());
}
class BigQuerySchema::_Internal {
 public:
  static const ::structs::StructSchema& structs_schema(const BigQuerySchema* msg);
};

const ::structs::StructSchema&
BigQuerySchema::_Internal::structs_schema(const BigQuerySchema* msg) {
  return *msg->structs_schema_;
}
void BigQuerySchema::clear_structs_schema() {
  if (GetArena() == nullptr && structs_schema_ != nullptr) {
    delete structs_schema_;
  }
  structs_schema_ = nullptr;
}
BigQuerySchema::BigQuerySchema(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:structs.BigQuerySchema)
}
BigQuerySchema::BigQuerySchema(const BigQuerySchema& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  bigquery_table_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_bigquery_table_name().empty()) {
    bigquery_table_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_bigquery_table_name(),
      GetArena());
  }
  if (from._internal_has_structs_schema()) {
    structs_schema_ = new ::structs::StructSchema(*from.structs_schema_);
  } else {
    structs_schema_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:structs.BigQuerySchema)
}

void BigQuerySchema::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_BigQuerySchema_structs_2fbigquery_2fbigquery_2eproto.base);
  bigquery_table_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  structs_schema_ = nullptr;
}

BigQuerySchema::~BigQuerySchema() {
  // @@protoc_insertion_point(destructor:structs.BigQuerySchema)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void BigQuerySchema::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  bigquery_table_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete structs_schema_;
}

void BigQuerySchema::ArenaDtor(void* object) {
  BigQuerySchema* _this = reinterpret_cast< BigQuerySchema* >(object);
  (void)_this;
}
void BigQuerySchema::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void BigQuerySchema::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const BigQuerySchema& BigQuerySchema::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_BigQuerySchema_structs_2fbigquery_2fbigquery_2eproto.base);
  return *internal_default_instance();
}


void BigQuerySchema::Clear() {
// @@protoc_insertion_point(message_clear_start:structs.BigQuerySchema)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  bigquery_table_name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  if (GetArena() == nullptr && structs_schema_ != nullptr) {
    delete structs_schema_;
  }
  structs_schema_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* BigQuerySchema::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .structs.StructSchema structs_schema = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_structs_schema(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string bigquery_table_name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_bigquery_table_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "structs.BigQuerySchema.bigquery_table_name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* BigQuerySchema::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:structs.BigQuerySchema)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .structs.StructSchema structs_schema = 1;
  if (this->has_structs_schema()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::structs_schema(this), target, stream);
  }

  // string bigquery_table_name = 2;
  if (this->bigquery_table_name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_bigquery_table_name().data(), static_cast<int>(this->_internal_bigquery_table_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "structs.BigQuerySchema.bigquery_table_name");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_bigquery_table_name(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:structs.BigQuerySchema)
  return target;
}

size_t BigQuerySchema::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:structs.BigQuerySchema)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string bigquery_table_name = 2;
  if (this->bigquery_table_name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_bigquery_table_name());
  }

  // .structs.StructSchema structs_schema = 1;
  if (this->has_structs_schema()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *structs_schema_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void BigQuerySchema::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:structs.BigQuerySchema)
  GOOGLE_DCHECK_NE(&from, this);
  const BigQuerySchema* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<BigQuerySchema>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:structs.BigQuerySchema)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:structs.BigQuerySchema)
    MergeFrom(*source);
  }
}

void BigQuerySchema::MergeFrom(const BigQuerySchema& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:structs.BigQuerySchema)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.bigquery_table_name().size() > 0) {
    _internal_set_bigquery_table_name(from._internal_bigquery_table_name());
  }
  if (from.has_structs_schema()) {
    _internal_mutable_structs_schema()->::structs::StructSchema::MergeFrom(from._internal_structs_schema());
  }
}

void BigQuerySchema::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
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

void BigQuerySchema::InternalSwap(BigQuerySchema* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  bigquery_table_name_.Swap(&other->bigquery_table_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(structs_schema_, other->structs_schema_);
}

::PROTOBUF_NAMESPACE_ID::Metadata BigQuerySchema::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void BigQuerySchemas::InitAsDefaultInstance() {
}
class BigQuerySchemas::_Internal {
 public:
};

BigQuerySchemas::BigQuerySchemas(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  schema_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:structs.BigQuerySchemas)
}
BigQuerySchemas::BigQuerySchemas(const BigQuerySchemas& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      schema_(from.schema_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:structs.BigQuerySchemas)
}

void BigQuerySchemas::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_BigQuerySchemas_structs_2fbigquery_2fbigquery_2eproto.base);
}

BigQuerySchemas::~BigQuerySchemas() {
  // @@protoc_insertion_point(destructor:structs.BigQuerySchemas)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void BigQuerySchemas::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void BigQuerySchemas::ArenaDtor(void* object) {
  BigQuerySchemas* _this = reinterpret_cast< BigQuerySchemas* >(object);
  (void)_this;
}
void BigQuerySchemas::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void BigQuerySchemas::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const BigQuerySchemas& BigQuerySchemas::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_BigQuerySchemas_structs_2fbigquery_2fbigquery_2eproto.base);
  return *internal_default_instance();
}


void BigQuerySchemas::Clear() {
// @@protoc_insertion_point(message_clear_start:structs.BigQuerySchemas)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  schema_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* BigQuerySchemas::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .structs.BigQuerySchema schema = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_schema(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* BigQuerySchemas::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:structs.BigQuerySchemas)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .structs.BigQuerySchema schema = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_schema_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_schema(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:structs.BigQuerySchemas)
  return target;
}

size_t BigQuerySchemas::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:structs.BigQuerySchemas)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .structs.BigQuerySchema schema = 1;
  total_size += 1UL * this->_internal_schema_size();
  for (const auto& msg : this->schema_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void BigQuerySchemas::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:structs.BigQuerySchemas)
  GOOGLE_DCHECK_NE(&from, this);
  const BigQuerySchemas* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<BigQuerySchemas>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:structs.BigQuerySchemas)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:structs.BigQuerySchemas)
    MergeFrom(*source);
  }
}

void BigQuerySchemas::MergeFrom(const BigQuerySchemas& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:structs.BigQuerySchemas)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  schema_.MergeFrom(from.schema_);
}

void BigQuerySchemas::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
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

void BigQuerySchemas::InternalSwap(BigQuerySchemas* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  schema_.InternalSwap(&other->schema_);
}

::PROTOBUF_NAMESPACE_ID::Metadata BigQuerySchemas::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace structs
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::structs::BigQueryField* Arena::CreateMaybeMessage< ::structs::BigQueryField >(Arena* arena) {
  return Arena::CreateMessageInternal< ::structs::BigQueryField >(arena);
}
template<> PROTOBUF_NOINLINE ::structs::BigQuerySchema* Arena::CreateMaybeMessage< ::structs::BigQuerySchema >(Arena* arena) {
  return Arena::CreateMessageInternal< ::structs::BigQuerySchema >(arena);
}
template<> PROTOBUF_NOINLINE ::structs::BigQuerySchemas* Arena::CreateMaybeMessage< ::structs::BigQuerySchemas >(Arena* arena) {
  return Arena::CreateMessageInternal< ::structs::BigQuerySchemas >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
