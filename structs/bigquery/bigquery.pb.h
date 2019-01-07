// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: structs/bigquery/bigquery.proto

#ifndef PROTOBUF_structs_2fbigquery_2fbigquery_2eproto__INCLUDED
#define PROTOBUF_structs_2fbigquery_2fbigquery_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "structs/structs.pb.h"
// @@protoc_insertion_point(includes)

namespace protobuf_structs_2fbigquery_2fbigquery_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[3];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsBigQueryFieldImpl();
void InitDefaultsBigQueryField();
void InitDefaultsBigQuerySchemaImpl();
void InitDefaultsBigQuerySchema();
void InitDefaultsBigQuerySchemasImpl();
void InitDefaultsBigQuerySchemas();
inline void InitDefaults() {
  InitDefaultsBigQueryField();
  InitDefaultsBigQuerySchema();
  InitDefaultsBigQuerySchemas();
}
}  // namespace protobuf_structs_2fbigquery_2fbigquery_2eproto
namespace structs {
class BigQueryField;
class BigQueryFieldDefaultTypeInternal;
extern BigQueryFieldDefaultTypeInternal _BigQueryField_default_instance_;
class BigQuerySchema;
class BigQuerySchemaDefaultTypeInternal;
extern BigQuerySchemaDefaultTypeInternal _BigQuerySchema_default_instance_;
class BigQuerySchemas;
class BigQuerySchemasDefaultTypeInternal;
extern BigQuerySchemasDefaultTypeInternal _BigQuerySchemas_default_instance_;
}  // namespace structs
namespace structs {

// ===================================================================

class BigQueryField : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:structs.BigQueryField) */ {
 public:
  BigQueryField();
  virtual ~BigQueryField();

  BigQueryField(const BigQueryField& from);

  inline BigQueryField& operator=(const BigQueryField& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  BigQueryField(BigQueryField&& from) noexcept
    : BigQueryField() {
    *this = ::std::move(from);
  }

  inline BigQueryField& operator=(BigQueryField&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const BigQueryField& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BigQueryField* internal_default_instance() {
    return reinterpret_cast<const BigQueryField*>(
               &_BigQueryField_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(BigQueryField* other);
  friend void swap(BigQueryField& a, BigQueryField& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline BigQueryField* New() const PROTOBUF_FINAL { return New(NULL); }

  BigQueryField* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const BigQueryField& from);
  void MergeFrom(const BigQueryField& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(BigQueryField* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:structs.BigQueryField)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  mutable int _cached_size_;
  friend struct ::protobuf_structs_2fbigquery_2fbigquery_2eproto::TableStruct;
  friend void ::protobuf_structs_2fbigquery_2fbigquery_2eproto::InitDefaultsBigQueryFieldImpl();
};
// -------------------------------------------------------------------

class BigQuerySchema : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:structs.BigQuerySchema) */ {
 public:
  BigQuerySchema();
  virtual ~BigQuerySchema();

  BigQuerySchema(const BigQuerySchema& from);

  inline BigQuerySchema& operator=(const BigQuerySchema& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  BigQuerySchema(BigQuerySchema&& from) noexcept
    : BigQuerySchema() {
    *this = ::std::move(from);
  }

  inline BigQuerySchema& operator=(BigQuerySchema&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const BigQuerySchema& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BigQuerySchema* internal_default_instance() {
    return reinterpret_cast<const BigQuerySchema*>(
               &_BigQuerySchema_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(BigQuerySchema* other);
  friend void swap(BigQuerySchema& a, BigQuerySchema& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline BigQuerySchema* New() const PROTOBUF_FINAL { return New(NULL); }

  BigQuerySchema* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const BigQuerySchema& from);
  void MergeFrom(const BigQuerySchema& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(BigQuerySchema* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string bigquery_table_name = 2;
  void clear_bigquery_table_name();
  static const int kBigqueryTableNameFieldNumber = 2;
  const ::std::string& bigquery_table_name() const;
  void set_bigquery_table_name(const ::std::string& value);
  #if LANG_CXX11
  void set_bigquery_table_name(::std::string&& value);
  #endif
  void set_bigquery_table_name(const char* value);
  void set_bigquery_table_name(const char* value, size_t size);
  ::std::string* mutable_bigquery_table_name();
  ::std::string* release_bigquery_table_name();
  void set_allocated_bigquery_table_name(::std::string* bigquery_table_name);

  // .structs.StructSchema structs_schema = 1;
  bool has_structs_schema() const;
  void clear_structs_schema();
  static const int kStructsSchemaFieldNumber = 1;
  const ::structs::StructSchema& structs_schema() const;
  ::structs::StructSchema* release_structs_schema();
  ::structs::StructSchema* mutable_structs_schema();
  void set_allocated_structs_schema(::structs::StructSchema* structs_schema);

  // @@protoc_insertion_point(class_scope:structs.BigQuerySchema)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr bigquery_table_name_;
  ::structs::StructSchema* structs_schema_;
  mutable int _cached_size_;
  friend struct ::protobuf_structs_2fbigquery_2fbigquery_2eproto::TableStruct;
  friend void ::protobuf_structs_2fbigquery_2fbigquery_2eproto::InitDefaultsBigQuerySchemaImpl();
};
// -------------------------------------------------------------------

class BigQuerySchemas : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:structs.BigQuerySchemas) */ {
 public:
  BigQuerySchemas();
  virtual ~BigQuerySchemas();

  BigQuerySchemas(const BigQuerySchemas& from);

  inline BigQuerySchemas& operator=(const BigQuerySchemas& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  BigQuerySchemas(BigQuerySchemas&& from) noexcept
    : BigQuerySchemas() {
    *this = ::std::move(from);
  }

  inline BigQuerySchemas& operator=(BigQuerySchemas&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const BigQuerySchemas& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BigQuerySchemas* internal_default_instance() {
    return reinterpret_cast<const BigQuerySchemas*>(
               &_BigQuerySchemas_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(BigQuerySchemas* other);
  friend void swap(BigQuerySchemas& a, BigQuerySchemas& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline BigQuerySchemas* New() const PROTOBUF_FINAL { return New(NULL); }

  BigQuerySchemas* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const BigQuerySchemas& from);
  void MergeFrom(const BigQuerySchemas& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(BigQuerySchemas* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .structs.BigQuerySchema schema = 1;
  int schema_size() const;
  void clear_schema();
  static const int kSchemaFieldNumber = 1;
  const ::structs::BigQuerySchema& schema(int index) const;
  ::structs::BigQuerySchema* mutable_schema(int index);
  ::structs::BigQuerySchema* add_schema();
  ::google::protobuf::RepeatedPtrField< ::structs::BigQuerySchema >*
      mutable_schema();
  const ::google::protobuf::RepeatedPtrField< ::structs::BigQuerySchema >&
      schema() const;

  // @@protoc_insertion_point(class_scope:structs.BigQuerySchemas)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::structs::BigQuerySchema > schema_;
  mutable int _cached_size_;
  friend struct ::protobuf_structs_2fbigquery_2fbigquery_2eproto::TableStruct;
  friend void ::protobuf_structs_2fbigquery_2fbigquery_2eproto::InitDefaultsBigQuerySchemasImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// BigQueryField

// -------------------------------------------------------------------

// BigQuerySchema

// .structs.StructSchema structs_schema = 1;
inline bool BigQuerySchema::has_structs_schema() const {
  return this != internal_default_instance() && structs_schema_ != NULL;
}
inline const ::structs::StructSchema& BigQuerySchema::structs_schema() const {
  const ::structs::StructSchema* p = structs_schema_;
  // @@protoc_insertion_point(field_get:structs.BigQuerySchema.structs_schema)
  return p != NULL ? *p : *reinterpret_cast<const ::structs::StructSchema*>(
      &::structs::_StructSchema_default_instance_);
}
inline ::structs::StructSchema* BigQuerySchema::release_structs_schema() {
  // @@protoc_insertion_point(field_release:structs.BigQuerySchema.structs_schema)
  
  ::structs::StructSchema* temp = structs_schema_;
  structs_schema_ = NULL;
  return temp;
}
inline ::structs::StructSchema* BigQuerySchema::mutable_structs_schema() {
  
  if (structs_schema_ == NULL) {
    structs_schema_ = new ::structs::StructSchema;
  }
  // @@protoc_insertion_point(field_mutable:structs.BigQuerySchema.structs_schema)
  return structs_schema_;
}
inline void BigQuerySchema::set_allocated_structs_schema(::structs::StructSchema* structs_schema) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(structs_schema_);
  }
  if (structs_schema) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      structs_schema = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, structs_schema, submessage_arena);
    }
    
  } else {
    
  }
  structs_schema_ = structs_schema;
  // @@protoc_insertion_point(field_set_allocated:structs.BigQuerySchema.structs_schema)
}

// string bigquery_table_name = 2;
inline void BigQuerySchema::clear_bigquery_table_name() {
  bigquery_table_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& BigQuerySchema::bigquery_table_name() const {
  // @@protoc_insertion_point(field_get:structs.BigQuerySchema.bigquery_table_name)
  return bigquery_table_name_.GetNoArena();
}
inline void BigQuerySchema::set_bigquery_table_name(const ::std::string& value) {
  
  bigquery_table_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:structs.BigQuerySchema.bigquery_table_name)
}
#if LANG_CXX11
inline void BigQuerySchema::set_bigquery_table_name(::std::string&& value) {
  
  bigquery_table_name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:structs.BigQuerySchema.bigquery_table_name)
}
#endif
inline void BigQuerySchema::set_bigquery_table_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  bigquery_table_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:structs.BigQuerySchema.bigquery_table_name)
}
inline void BigQuerySchema::set_bigquery_table_name(const char* value, size_t size) {
  
  bigquery_table_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:structs.BigQuerySchema.bigquery_table_name)
}
inline ::std::string* BigQuerySchema::mutable_bigquery_table_name() {
  
  // @@protoc_insertion_point(field_mutable:structs.BigQuerySchema.bigquery_table_name)
  return bigquery_table_name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* BigQuerySchema::release_bigquery_table_name() {
  // @@protoc_insertion_point(field_release:structs.BigQuerySchema.bigquery_table_name)
  
  return bigquery_table_name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void BigQuerySchema::set_allocated_bigquery_table_name(::std::string* bigquery_table_name) {
  if (bigquery_table_name != NULL) {
    
  } else {
    
  }
  bigquery_table_name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), bigquery_table_name);
  // @@protoc_insertion_point(field_set_allocated:structs.BigQuerySchema.bigquery_table_name)
}

// -------------------------------------------------------------------

// BigQuerySchemas

// repeated .structs.BigQuerySchema schema = 1;
inline int BigQuerySchemas::schema_size() const {
  return schema_.size();
}
inline void BigQuerySchemas::clear_schema() {
  schema_.Clear();
}
inline const ::structs::BigQuerySchema& BigQuerySchemas::schema(int index) const {
  // @@protoc_insertion_point(field_get:structs.BigQuerySchemas.schema)
  return schema_.Get(index);
}
inline ::structs::BigQuerySchema* BigQuerySchemas::mutable_schema(int index) {
  // @@protoc_insertion_point(field_mutable:structs.BigQuerySchemas.schema)
  return schema_.Mutable(index);
}
inline ::structs::BigQuerySchema* BigQuerySchemas::add_schema() {
  // @@protoc_insertion_point(field_add:structs.BigQuerySchemas.schema)
  return schema_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::structs::BigQuerySchema >*
BigQuerySchemas::mutable_schema() {
  // @@protoc_insertion_point(field_mutable_list:structs.BigQuerySchemas.schema)
  return &schema_;
}
inline const ::google::protobuf::RepeatedPtrField< ::structs::BigQuerySchema >&
BigQuerySchemas::schema() const {
  // @@protoc_insertion_point(field_list:structs.BigQuerySchemas.schema)
  return schema_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace structs

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_structs_2fbigquery_2fbigquery_2eproto__INCLUDED
