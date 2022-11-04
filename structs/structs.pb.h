// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: structs/structs.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_structs_2fstructs_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_structs_2fstructs_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021007 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_structs_2fstructs_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_structs_2fstructs_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_structs_2fstructs_2eproto;
namespace structs {
class StructField;
struct StructFieldDefaultTypeInternal;
extern StructFieldDefaultTypeInternal _StructField_default_instance_;
class StructSchema;
struct StructSchemaDefaultTypeInternal;
extern StructSchemaDefaultTypeInternal _StructSchema_default_instance_;
}  // namespace structs
PROTOBUF_NAMESPACE_OPEN
template<> ::structs::StructField* Arena::CreateMaybeMessage<::structs::StructField>(Arena*);
template<> ::structs::StructSchema* Arena::CreateMaybeMessage<::structs::StructSchema>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace structs {

// ===================================================================

class StructField final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:structs.StructField) */ {
 public:
  inline StructField() : StructField(nullptr) {}
  ~StructField() override;
  explicit PROTOBUF_CONSTEXPR StructField(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  StructField(const StructField& from);
  StructField(StructField&& from) noexcept
    : StructField() {
    *this = ::std::move(from);
  }

  inline StructField& operator=(const StructField& from) {
    CopyFrom(from);
    return *this;
  }
  inline StructField& operator=(StructField&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const StructField& default_instance() {
    return *internal_default_instance();
  }
  static inline const StructField* internal_default_instance() {
    return reinterpret_cast<const StructField*>(
               &_StructField_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(StructField& a, StructField& b) {
    a.Swap(&b);
  }
  inline void Swap(StructField* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(StructField* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  StructField* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<StructField>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const StructField& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const StructField& from) {
    StructField::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(StructField* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "structs.StructField";
  }
  protected:
  explicit StructField(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPathFieldNumber = 1,
    kStructsTransientFieldNumber = 2,
  };
  // string path = 1;
  void clear_path();
  const std::string& path() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_path(ArgT0&& arg0, ArgT... args);
  std::string* mutable_path();
  PROTOBUF_NODISCARD std::string* release_path();
  void set_allocated_path(std::string* path);
  private:
  const std::string& _internal_path() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_path(const std::string& value);
  std::string* _internal_mutable_path();
  public:

  // bool structs_transient = 2;
  void clear_structs_transient();
  bool structs_transient() const;
  void set_structs_transient(bool value);
  private:
  bool _internal_structs_transient() const;
  void _internal_set_structs_transient(bool value);
  public:

  // @@protoc_insertion_point(class_scope:structs.StructField)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr path_;
    bool structs_transient_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_structs_2fstructs_2eproto;
};
// -------------------------------------------------------------------

class StructSchema final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:structs.StructSchema) */ {
 public:
  inline StructSchema() : StructSchema(nullptr) {}
  ~StructSchema() override;
  explicit PROTOBUF_CONSTEXPR StructSchema(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  StructSchema(const StructSchema& from);
  StructSchema(StructSchema&& from) noexcept
    : StructSchema() {
    *this = ::std::move(from);
  }

  inline StructSchema& operator=(const StructSchema& from) {
    CopyFrom(from);
    return *this;
  }
  inline StructSchema& operator=(StructSchema&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const StructSchema& default_instance() {
    return *internal_default_instance();
  }
  static inline const StructSchema* internal_default_instance() {
    return reinterpret_cast<const StructSchema*>(
               &_StructSchema_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(StructSchema& a, StructSchema& b) {
    a.Swap(&b);
  }
  inline void Swap(StructSchema* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(StructSchema* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  StructSchema* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<StructSchema>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const StructSchema& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const StructSchema& from) {
    StructSchema::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(StructSchema* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "structs.StructSchema";
  }
  protected:
  explicit StructSchema(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMessageNameFieldNumber = 1,
    kJavaPackageFieldNumber = 2,
    kJavaClassFieldNumber = 3,
  };
  // string message_name = 1;
  void clear_message_name();
  const std::string& message_name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_message_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_message_name();
  PROTOBUF_NODISCARD std::string* release_message_name();
  void set_allocated_message_name(std::string* message_name);
  private:
  const std::string& _internal_message_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_message_name(const std::string& value);
  std::string* _internal_mutable_message_name();
  public:

  // string java_package = 2;
  void clear_java_package();
  const std::string& java_package() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_java_package(ArgT0&& arg0, ArgT... args);
  std::string* mutable_java_package();
  PROTOBUF_NODISCARD std::string* release_java_package();
  void set_allocated_java_package(std::string* java_package);
  private:
  const std::string& _internal_java_package() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_java_package(const std::string& value);
  std::string* _internal_mutable_java_package();
  public:

  // string java_class = 3;
  void clear_java_class();
  const std::string& java_class() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_java_class(ArgT0&& arg0, ArgT... args);
  std::string* mutable_java_class();
  PROTOBUF_NODISCARD std::string* release_java_class();
  void set_allocated_java_class(std::string* java_class);
  private:
  const std::string& _internal_java_class() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_java_class(const std::string& value);
  std::string* _internal_mutable_java_class();
  public:

  // @@protoc_insertion_point(class_scope:structs.StructSchema)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr message_name_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr java_package_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr java_class_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_structs_2fstructs_2eproto;
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
  _impl_.path_.ClearToEmpty();
}
inline const std::string& StructField::path() const {
  // @@protoc_insertion_point(field_get:structs.StructField.path)
  return _internal_path();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void StructField::set_path(ArgT0&& arg0, ArgT... args) {
 
 _impl_.path_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:structs.StructField.path)
}
inline std::string* StructField::mutable_path() {
  std::string* _s = _internal_mutable_path();
  // @@protoc_insertion_point(field_mutable:structs.StructField.path)
  return _s;
}
inline const std::string& StructField::_internal_path() const {
  return _impl_.path_.Get();
}
inline void StructField::_internal_set_path(const std::string& value) {
  
  _impl_.path_.Set(value, GetArenaForAllocation());
}
inline std::string* StructField::_internal_mutable_path() {
  
  return _impl_.path_.Mutable(GetArenaForAllocation());
}
inline std::string* StructField::release_path() {
  // @@protoc_insertion_point(field_release:structs.StructField.path)
  return _impl_.path_.Release();
}
inline void StructField::set_allocated_path(std::string* path) {
  if (path != nullptr) {
    
  } else {
    
  }
  _impl_.path_.SetAllocated(path, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.path_.IsDefault()) {
    _impl_.path_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:structs.StructField.path)
}

// bool structs_transient = 2;
inline void StructField::clear_structs_transient() {
  _impl_.structs_transient_ = false;
}
inline bool StructField::_internal_structs_transient() const {
  return _impl_.structs_transient_;
}
inline bool StructField::structs_transient() const {
  // @@protoc_insertion_point(field_get:structs.StructField.structs_transient)
  return _internal_structs_transient();
}
inline void StructField::_internal_set_structs_transient(bool value) {
  
  _impl_.structs_transient_ = value;
}
inline void StructField::set_structs_transient(bool value) {
  _internal_set_structs_transient(value);
  // @@protoc_insertion_point(field_set:structs.StructField.structs_transient)
}

// -------------------------------------------------------------------

// StructSchema

// string message_name = 1;
inline void StructSchema::clear_message_name() {
  _impl_.message_name_.ClearToEmpty();
}
inline const std::string& StructSchema::message_name() const {
  // @@protoc_insertion_point(field_get:structs.StructSchema.message_name)
  return _internal_message_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void StructSchema::set_message_name(ArgT0&& arg0, ArgT... args) {
 
 _impl_.message_name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:structs.StructSchema.message_name)
}
inline std::string* StructSchema::mutable_message_name() {
  std::string* _s = _internal_mutable_message_name();
  // @@protoc_insertion_point(field_mutable:structs.StructSchema.message_name)
  return _s;
}
inline const std::string& StructSchema::_internal_message_name() const {
  return _impl_.message_name_.Get();
}
inline void StructSchema::_internal_set_message_name(const std::string& value) {
  
  _impl_.message_name_.Set(value, GetArenaForAllocation());
}
inline std::string* StructSchema::_internal_mutable_message_name() {
  
  return _impl_.message_name_.Mutable(GetArenaForAllocation());
}
inline std::string* StructSchema::release_message_name() {
  // @@protoc_insertion_point(field_release:structs.StructSchema.message_name)
  return _impl_.message_name_.Release();
}
inline void StructSchema::set_allocated_message_name(std::string* message_name) {
  if (message_name != nullptr) {
    
  } else {
    
  }
  _impl_.message_name_.SetAllocated(message_name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.message_name_.IsDefault()) {
    _impl_.message_name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:structs.StructSchema.message_name)
}

// string java_package = 2;
inline void StructSchema::clear_java_package() {
  _impl_.java_package_.ClearToEmpty();
}
inline const std::string& StructSchema::java_package() const {
  // @@protoc_insertion_point(field_get:structs.StructSchema.java_package)
  return _internal_java_package();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void StructSchema::set_java_package(ArgT0&& arg0, ArgT... args) {
 
 _impl_.java_package_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:structs.StructSchema.java_package)
}
inline std::string* StructSchema::mutable_java_package() {
  std::string* _s = _internal_mutable_java_package();
  // @@protoc_insertion_point(field_mutable:structs.StructSchema.java_package)
  return _s;
}
inline const std::string& StructSchema::_internal_java_package() const {
  return _impl_.java_package_.Get();
}
inline void StructSchema::_internal_set_java_package(const std::string& value) {
  
  _impl_.java_package_.Set(value, GetArenaForAllocation());
}
inline std::string* StructSchema::_internal_mutable_java_package() {
  
  return _impl_.java_package_.Mutable(GetArenaForAllocation());
}
inline std::string* StructSchema::release_java_package() {
  // @@protoc_insertion_point(field_release:structs.StructSchema.java_package)
  return _impl_.java_package_.Release();
}
inline void StructSchema::set_allocated_java_package(std::string* java_package) {
  if (java_package != nullptr) {
    
  } else {
    
  }
  _impl_.java_package_.SetAllocated(java_package, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.java_package_.IsDefault()) {
    _impl_.java_package_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:structs.StructSchema.java_package)
}

// string java_class = 3;
inline void StructSchema::clear_java_class() {
  _impl_.java_class_.ClearToEmpty();
}
inline const std::string& StructSchema::java_class() const {
  // @@protoc_insertion_point(field_get:structs.StructSchema.java_class)
  return _internal_java_class();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void StructSchema::set_java_class(ArgT0&& arg0, ArgT... args) {
 
 _impl_.java_class_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:structs.StructSchema.java_class)
}
inline std::string* StructSchema::mutable_java_class() {
  std::string* _s = _internal_mutable_java_class();
  // @@protoc_insertion_point(field_mutable:structs.StructSchema.java_class)
  return _s;
}
inline const std::string& StructSchema::_internal_java_class() const {
  return _impl_.java_class_.Get();
}
inline void StructSchema::_internal_set_java_class(const std::string& value) {
  
  _impl_.java_class_.Set(value, GetArenaForAllocation());
}
inline std::string* StructSchema::_internal_mutable_java_class() {
  
  return _impl_.java_class_.Mutable(GetArenaForAllocation());
}
inline std::string* StructSchema::release_java_class() {
  // @@protoc_insertion_point(field_release:structs.StructSchema.java_class)
  return _impl_.java_class_.Release();
}
inline void StructSchema::set_allocated_java_class(std::string* java_class) {
  if (java_class != nullptr) {
    
  } else {
    
  }
  _impl_.java_class_.SetAllocated(java_class, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.java_class_.IsDefault()) {
    _impl_.java_class_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:structs.StructSchema.java_class)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace structs

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_structs_2fstructs_2eproto
