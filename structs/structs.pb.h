// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: structs/structs.proto

#ifndef PROTOBUF_structs_2fstructs_2eproto__INCLUDED
#define PROTOBUF_structs_2fstructs_2eproto__INCLUDED

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
// @@protoc_insertion_point(includes)

namespace protobuf_structs_2fstructs_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsStructFieldImpl();
void InitDefaultsStructField();
void InitDefaultsStructSchemaImpl();
void InitDefaultsStructSchema();
inline void InitDefaults() {
  InitDefaultsStructField();
  InitDefaultsStructSchema();
}
}  // namespace protobuf_structs_2fstructs_2eproto
namespace structs {
class StructField;
class StructFieldDefaultTypeInternal;
extern StructFieldDefaultTypeInternal _StructField_default_instance_;
class StructSchema;
class StructSchemaDefaultTypeInternal;
extern StructSchemaDefaultTypeInternal _StructSchema_default_instance_;
}  // namespace structs
namespace structs {

// ===================================================================

class StructField : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:structs.StructField) */ {
 public:
  StructField();
  virtual ~StructField();

  StructField(const StructField& from);

  inline StructField& operator=(const StructField& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  StructField(StructField&& from) noexcept
    : StructField() {
    *this = ::std::move(from);
  }

  inline StructField& operator=(StructField&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const StructField& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const StructField* internal_default_instance() {
    return reinterpret_cast<const StructField*>(
               &_StructField_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(StructField* other);
  friend void swap(StructField& a, StructField& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline StructField* New() const PROTOBUF_FINAL { return New(NULL); }

  StructField* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const StructField& from);
  void MergeFrom(const StructField& from);
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
  void InternalSwap(StructField* other);
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

  // string path = 1;
  void clear_path();
  static const int kPathFieldNumber = 1;
  const ::std::string& path() const;
  void set_path(const ::std::string& value);
  #if LANG_CXX11
  void set_path(::std::string&& value);
  #endif
  void set_path(const char* value);
  void set_path(const char* value, size_t size);
  ::std::string* mutable_path();
  ::std::string* release_path();
  void set_allocated_path(::std::string* path);

  // bool structs_transient = 2;
  void clear_structs_transient();
  static const int kStructsTransientFieldNumber = 2;
  bool structs_transient() const;
  void set_structs_transient(bool value);

  // @@protoc_insertion_point(class_scope:structs.StructField)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr path_;
  bool structs_transient_;
  mutable int _cached_size_;
  friend struct ::protobuf_structs_2fstructs_2eproto::TableStruct;
  friend void ::protobuf_structs_2fstructs_2eproto::InitDefaultsStructFieldImpl();
};
// -------------------------------------------------------------------

class StructSchema : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:structs.StructSchema) */ {
 public:
  StructSchema();
  virtual ~StructSchema();

  StructSchema(const StructSchema& from);

  inline StructSchema& operator=(const StructSchema& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  StructSchema(StructSchema&& from) noexcept
    : StructSchema() {
    *this = ::std::move(from);
  }

  inline StructSchema& operator=(StructSchema&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const StructSchema& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const StructSchema* internal_default_instance() {
    return reinterpret_cast<const StructSchema*>(
               &_StructSchema_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(StructSchema* other);
  friend void swap(StructSchema& a, StructSchema& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline StructSchema* New() const PROTOBUF_FINAL { return New(NULL); }

  StructSchema* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const StructSchema& from);
  void MergeFrom(const StructSchema& from);
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
  void InternalSwap(StructSchema* other);
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

  // string message_name = 1;
  void clear_message_name();
  static const int kMessageNameFieldNumber = 1;
  const ::std::string& message_name() const;
  void set_message_name(const ::std::string& value);
  #if LANG_CXX11
  void set_message_name(::std::string&& value);
  #endif
  void set_message_name(const char* value);
  void set_message_name(const char* value, size_t size);
  ::std::string* mutable_message_name();
  ::std::string* release_message_name();
  void set_allocated_message_name(::std::string* message_name);

  // string java_package = 2;
  void clear_java_package();
  static const int kJavaPackageFieldNumber = 2;
  const ::std::string& java_package() const;
  void set_java_package(const ::std::string& value);
  #if LANG_CXX11
  void set_java_package(::std::string&& value);
  #endif
  void set_java_package(const char* value);
  void set_java_package(const char* value, size_t size);
  ::std::string* mutable_java_package();
  ::std::string* release_java_package();
  void set_allocated_java_package(::std::string* java_package);

  // string java_class = 3;
  void clear_java_class();
  static const int kJavaClassFieldNumber = 3;
  const ::std::string& java_class() const;
  void set_java_class(const ::std::string& value);
  #if LANG_CXX11
  void set_java_class(::std::string&& value);
  #endif
  void set_java_class(const char* value);
  void set_java_class(const char* value, size_t size);
  ::std::string* mutable_java_class();
  ::std::string* release_java_class();
  void set_allocated_java_class(::std::string* java_class);

  // @@protoc_insertion_point(class_scope:structs.StructSchema)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr message_name_;
  ::google::protobuf::internal::ArenaStringPtr java_package_;
  ::google::protobuf::internal::ArenaStringPtr java_class_;
  mutable int _cached_size_;
  friend struct ::protobuf_structs_2fstructs_2eproto::TableStruct;
  friend void ::protobuf_structs_2fstructs_2eproto::InitDefaultsStructSchemaImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// StructField

// string path = 1;
inline void StructField::clear_path() {
  path_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& StructField::path() const {
  // @@protoc_insertion_point(field_get:structs.StructField.path)
  return path_.GetNoArena();
}
inline void StructField::set_path(const ::std::string& value) {
  
  path_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:structs.StructField.path)
}
#if LANG_CXX11
inline void StructField::set_path(::std::string&& value) {
  
  path_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:structs.StructField.path)
}
#endif
inline void StructField::set_path(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  path_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:structs.StructField.path)
}
inline void StructField::set_path(const char* value, size_t size) {
  
  path_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:structs.StructField.path)
}
inline ::std::string* StructField::mutable_path() {
  
  // @@protoc_insertion_point(field_mutable:structs.StructField.path)
  return path_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* StructField::release_path() {
  // @@protoc_insertion_point(field_release:structs.StructField.path)
  
  return path_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void StructField::set_allocated_path(::std::string* path) {
  if (path != NULL) {
    
  } else {
    
  }
  path_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), path);
  // @@protoc_insertion_point(field_set_allocated:structs.StructField.path)
}

// bool structs_transient = 2;
inline void StructField::clear_structs_transient() {
  structs_transient_ = false;
}
inline bool StructField::structs_transient() const {
  // @@protoc_insertion_point(field_get:structs.StructField.structs_transient)
  return structs_transient_;
}
inline void StructField::set_structs_transient(bool value) {
  
  structs_transient_ = value;
  // @@protoc_insertion_point(field_set:structs.StructField.structs_transient)
}

// -------------------------------------------------------------------

// StructSchema

// string message_name = 1;
inline void StructSchema::clear_message_name() {
  message_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& StructSchema::message_name() const {
  // @@protoc_insertion_point(field_get:structs.StructSchema.message_name)
  return message_name_.GetNoArena();
}
inline void StructSchema::set_message_name(const ::std::string& value) {
  
  message_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:structs.StructSchema.message_name)
}
#if LANG_CXX11
inline void StructSchema::set_message_name(::std::string&& value) {
  
  message_name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:structs.StructSchema.message_name)
}
#endif
inline void StructSchema::set_message_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  message_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:structs.StructSchema.message_name)
}
inline void StructSchema::set_message_name(const char* value, size_t size) {
  
  message_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:structs.StructSchema.message_name)
}
inline ::std::string* StructSchema::mutable_message_name() {
  
  // @@protoc_insertion_point(field_mutable:structs.StructSchema.message_name)
  return message_name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* StructSchema::release_message_name() {
  // @@protoc_insertion_point(field_release:structs.StructSchema.message_name)
  
  return message_name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void StructSchema::set_allocated_message_name(::std::string* message_name) {
  if (message_name != NULL) {
    
  } else {
    
  }
  message_name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), message_name);
  // @@protoc_insertion_point(field_set_allocated:structs.StructSchema.message_name)
}

// string java_package = 2;
inline void StructSchema::clear_java_package() {
  java_package_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& StructSchema::java_package() const {
  // @@protoc_insertion_point(field_get:structs.StructSchema.java_package)
  return java_package_.GetNoArena();
}
inline void StructSchema::set_java_package(const ::std::string& value) {
  
  java_package_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:structs.StructSchema.java_package)
}
#if LANG_CXX11
inline void StructSchema::set_java_package(::std::string&& value) {
  
  java_package_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:structs.StructSchema.java_package)
}
#endif
inline void StructSchema::set_java_package(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  java_package_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:structs.StructSchema.java_package)
}
inline void StructSchema::set_java_package(const char* value, size_t size) {
  
  java_package_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:structs.StructSchema.java_package)
}
inline ::std::string* StructSchema::mutable_java_package() {
  
  // @@protoc_insertion_point(field_mutable:structs.StructSchema.java_package)
  return java_package_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* StructSchema::release_java_package() {
  // @@protoc_insertion_point(field_release:structs.StructSchema.java_package)
  
  return java_package_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void StructSchema::set_allocated_java_package(::std::string* java_package) {
  if (java_package != NULL) {
    
  } else {
    
  }
  java_package_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), java_package);
  // @@protoc_insertion_point(field_set_allocated:structs.StructSchema.java_package)
}

// string java_class = 3;
inline void StructSchema::clear_java_class() {
  java_class_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& StructSchema::java_class() const {
  // @@protoc_insertion_point(field_get:structs.StructSchema.java_class)
  return java_class_.GetNoArena();
}
inline void StructSchema::set_java_class(const ::std::string& value) {
  
  java_class_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:structs.StructSchema.java_class)
}
#if LANG_CXX11
inline void StructSchema::set_java_class(::std::string&& value) {
  
  java_class_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:structs.StructSchema.java_class)
}
#endif
inline void StructSchema::set_java_class(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  java_class_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:structs.StructSchema.java_class)
}
inline void StructSchema::set_java_class(const char* value, size_t size) {
  
  java_class_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:structs.StructSchema.java_class)
}
inline ::std::string* StructSchema::mutable_java_class() {
  
  // @@protoc_insertion_point(field_mutable:structs.StructSchema.java_class)
  return java_class_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* StructSchema::release_java_class() {
  // @@protoc_insertion_point(field_release:structs.StructSchema.java_class)
  
  return java_class_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void StructSchema::set_allocated_java_class(::std::string* java_class) {
  if (java_class != NULL) {
    
  } else {
    
  }
  java_class_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), java_class);
  // @@protoc_insertion_point(field_set_allocated:structs.StructSchema.java_class)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace structs

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_structs_2fstructs_2eproto__INCLUDED