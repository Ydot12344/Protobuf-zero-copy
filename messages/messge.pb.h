// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messge.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_messge_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_messge_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 3021000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 3021009 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_messge_2eproto

PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_messge_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable
    descriptor_table_messge_2eproto;
namespace tutorial {
class TFile;
struct TFileDefaultTypeInternal;
extern TFileDefaultTypeInternal _TFile_default_instance_;
class TFileSet;
struct TFileSetDefaultTypeInternal;
extern TFileSetDefaultTypeInternal _TFileSet_default_instance_;
class TReport;
struct TReportDefaultTypeInternal;
extern TReportDefaultTypeInternal _TReport_default_instance_;
}  // namespace tutorial
PROTOBUF_NAMESPACE_OPEN
template <>
::tutorial::TFile* Arena::CreateMaybeMessage<::tutorial::TFile>(Arena*);
template <>
::tutorial::TFileSet* Arena::CreateMaybeMessage<::tutorial::TFileSet>(Arena*);
template <>
::tutorial::TReport* Arena::CreateMaybeMessage<::tutorial::TReport>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

namespace tutorial {

// ===================================================================


// -------------------------------------------------------------------

class TFile final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:tutorial.TFile) */ {
 public:
  inline TFile() : TFile(nullptr) {}
  ~TFile() override;
  explicit PROTOBUF_CONSTEXPR TFile(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  TFile(const TFile& from);
  TFile(TFile&& from) noexcept
    : TFile() {
    *this = ::std::move(from);
  }

  inline TFile& operator=(const TFile& from) {
    CopyFrom(from);
    return *this;
  }
  inline TFile& operator=(TFile&& from) noexcept {
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

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
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
  static const TFile& default_instance() {
    return *internal_default_instance();
  }
  static inline const TFile* internal_default_instance() {
    return reinterpret_cast<const TFile*>(
               &_TFile_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(TFile& a, TFile& b) {
    a.Swap(&b);
  }
  inline void Swap(TFile* other) {
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
  void UnsafeArenaSwap(TFile* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TFile* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<TFile>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const TFile& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const TFile& from) {
    TFile::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(TFile* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "tutorial.TFile";
  }
  protected:
  explicit TFile(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kWeightsFieldNumber = 1,
    kHostsFieldNumber = 3,
    kNameFieldNumber = 2,
  };
  // repeated float Weights = 1;
  int weights_size() const;
  private:
  int _internal_weights_size() const;
  public:
  void clear_weights();
  private:
  float _internal_weights(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >&
      _internal_weights() const;
  void _internal_add_weights(float value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >*
      _internal_mutable_weights();
  public:
  float weights(int index) const;
  void set_weights(int index, float value);
  void add_weights(float value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >&
      weights() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >*
      mutable_weights();

  // repeated int32 Hosts = 3;
  int hosts_size() const;
  private:
  int _internal_hosts_size() const;
  public:
  void clear_hosts();
  private:
  ::int32_t _internal_hosts(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t >&
      _internal_hosts() const;
  void _internal_add_hosts(::int32_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t >*
      _internal_mutable_hosts();
  public:
  ::int32_t hosts(int index) const;
  void set_hosts(int index, ::int32_t value);
  void add_hosts(::int32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t >&
      hosts() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t >*
      mutable_hosts();

  // required string Name = 2;
  bool has_name() const;
  private:
  bool _internal_has_name() const;
  public:
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // @@protoc_insertion_point(class_scope:tutorial.TFile)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< float > weights_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t > hosts_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_messge_2eproto;
};// -------------------------------------------------------------------

class TFileSet final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:tutorial.TFileSet) */ {
 public:
  inline TFileSet() : TFileSet(nullptr) {}
  ~TFileSet() override;
  explicit PROTOBUF_CONSTEXPR TFileSet(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  TFileSet(const TFileSet& from);
  TFileSet(TFileSet&& from) noexcept
    : TFileSet() {
    *this = ::std::move(from);
  }

  inline TFileSet& operator=(const TFileSet& from) {
    CopyFrom(from);
    return *this;
  }
  inline TFileSet& operator=(TFileSet&& from) noexcept {
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

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
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
  static const TFileSet& default_instance() {
    return *internal_default_instance();
  }
  static inline const TFileSet* internal_default_instance() {
    return reinterpret_cast<const TFileSet*>(
               &_TFileSet_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(TFileSet& a, TFileSet& b) {
    a.Swap(&b);
  }
  inline void Swap(TFileSet* other) {
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
  void UnsafeArenaSwap(TFileSet* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TFileSet* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<TFileSet>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const TFileSet& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const TFileSet& from) {
    TFileSet::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(TFileSet* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "tutorial.TFileSet";
  }
  protected:
  explicit TFileSet(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFilesFieldNumber = 1,
    kHashFieldNumber = 2,
  };
  // repeated .tutorial.TFile Files = 1;
  int files_size() const;
  private:
  int _internal_files_size() const;
  public:
  void clear_files();
  ::tutorial::TFile* mutable_files(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::TFile >*
      mutable_files();
  private:
  const ::tutorial::TFile& _internal_files(int index) const;
  ::tutorial::TFile* _internal_add_files();
  public:
  const ::tutorial::TFile& files(int index) const;
  ::tutorial::TFile* add_files();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::TFile >&
      files() const;

  // required int64 Hash = 2;
  bool has_hash() const;
  private:
  bool _internal_has_hash() const;
  public:
  void clear_hash();
  ::int64_t hash() const;
  void set_hash(::int64_t value);
  private:
  ::int64_t _internal_hash() const;
  void _internal_set_hash(::int64_t value);
  public:

  // @@protoc_insertion_point(class_scope:tutorial.TFileSet)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::TFile > files_;
    ::int64_t hash_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_messge_2eproto;
};// -------------------------------------------------------------------

class TReport final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:tutorial.TReport) */ {
 public:
  inline TReport() : TReport(nullptr) {}
  ~TReport() override;
  explicit PROTOBUF_CONSTEXPR TReport(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  TReport(const TReport& from);
  TReport(TReport&& from) noexcept
    : TReport() {
    *this = ::std::move(from);
  }

  inline TReport& operator=(const TReport& from) {
    CopyFrom(from);
    return *this;
  }
  inline TReport& operator=(TReport&& from) noexcept {
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

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
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
  static const TReport& default_instance() {
    return *internal_default_instance();
  }
  static inline const TReport* internal_default_instance() {
    return reinterpret_cast<const TReport*>(
               &_TReport_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(TReport& a, TReport& b) {
    a.Swap(&b);
  }
  inline void Swap(TReport* other) {
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
  void UnsafeArenaSwap(TReport* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TReport* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<TReport>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const TReport& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const TReport& from) {
    TReport::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(TReport* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "tutorial.TReport";
  }
  protected:
  explicit TReport(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNumsFieldNumber = 1,
    kStringsFieldNumber = 2,
    kSetsOfFilesFieldNumber = 3,
  };
  // repeated int32 Nums = 1;
  int nums_size() const;
  private:
  int _internal_nums_size() const;
  public:
  void clear_nums();
  private:
  ::int32_t _internal_nums(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t >&
      _internal_nums() const;
  void _internal_add_nums(::int32_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t >*
      _internal_mutable_nums();
  public:
  ::int32_t nums(int index) const;
  void set_nums(int index, ::int32_t value);
  void add_nums(::int32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t >&
      nums() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t >*
      mutable_nums();

  // repeated string Strings = 2;
  int strings_size() const;
  private:
  int _internal_strings_size() const;
  public:
  void clear_strings();
  const std::string& strings(int index) const;
  std::string* mutable_strings(int index);
  void set_strings(int index, const std::string& value);
  void set_strings(int index, std::string&& value);
  void set_strings(int index, const char* value);
  void set_strings(int index, const char* value, ::size_t size);
  std::string* add_strings();
  void add_strings(const std::string& value);
  void add_strings(std::string&& value);
  void add_strings(const char* value);
  void add_strings(const char* value, ::size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& strings() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_strings();
  private:
  const std::string& _internal_strings(int index) const;
  std::string* _internal_add_strings();
  public:

  // repeated .tutorial.TFileSet SetsOfFiles = 3;
  int setsoffiles_size() const;
  private:
  int _internal_setsoffiles_size() const;
  public:
  void clear_setsoffiles();
  ::tutorial::TFileSet* mutable_setsoffiles(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::TFileSet >*
      mutable_setsoffiles();
  private:
  const ::tutorial::TFileSet& _internal_setsoffiles(int index) const;
  ::tutorial::TFileSet* _internal_add_setsoffiles();
  public:
  const ::tutorial::TFileSet& setsoffiles(int index) const;
  ::tutorial::TFileSet* add_setsoffiles();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::TFileSet >&
      setsoffiles() const;

  // @@protoc_insertion_point(class_scope:tutorial.TReport)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t > nums_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> strings_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::TFileSet > setsoffiles_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_messge_2eproto;
};
// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// TFile

// repeated float Weights = 1;
inline int TFile::_internal_weights_size() const {
  return _impl_.weights_.size();
}
inline int TFile::weights_size() const {
  return _internal_weights_size();
}
inline void TFile::clear_weights() {
  _impl_.weights_.Clear();
}
inline float TFile::_internal_weights(int index) const {
  return _impl_.weights_.Get(index);
}
inline float TFile::weights(int index) const {
  // @@protoc_insertion_point(field_get:tutorial.TFile.Weights)
  return _internal_weights(index);
}
inline void TFile::set_weights(int index, float value) {
  _impl_.weights_.Set(index, value);
  // @@protoc_insertion_point(field_set:tutorial.TFile.Weights)
}
inline void TFile::_internal_add_weights(float value) {
  _impl_.weights_.Add(value);
}
inline void TFile::add_weights(float value) {
  _internal_add_weights(value);
  // @@protoc_insertion_point(field_add:tutorial.TFile.Weights)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >&
TFile::_internal_weights() const {
  return _impl_.weights_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >&
TFile::weights() const {
  // @@protoc_insertion_point(field_list:tutorial.TFile.Weights)
  return _internal_weights();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >*
TFile::_internal_mutable_weights() {
  return &_impl_.weights_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >*
TFile::mutable_weights() {
  // @@protoc_insertion_point(field_mutable_list:tutorial.TFile.Weights)
  return _internal_mutable_weights();
}

// required string Name = 2;
inline bool TFile::_internal_has_name() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool TFile::has_name() const {
  return _internal_has_name();
}
inline void TFile::clear_name() {
  _impl_.name_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& TFile::name() const {
  // @@protoc_insertion_point(field_get:tutorial.TFile.Name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void TFile::set_name(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000001u;
 _impl_.name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:tutorial.TFile.Name)
}
inline std::string* TFile::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:tutorial.TFile.Name)
  return _s;
}
inline const std::string& TFile::_internal_name() const {
  return _impl_.name_.Get();
}
inline void TFile::_internal_set_name(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.name_.Set(value, GetArenaForAllocation());
}
inline std::string* TFile::_internal_mutable_name() {
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.name_.Mutable(GetArenaForAllocation());
}
inline std::string* TFile::release_name() {
  // @@protoc_insertion_point(field_release:tutorial.TFile.Name)
  if (!_internal_has_name()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* p = _impl_.name_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.name_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void TFile::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.name_.SetAllocated(name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.name_.IsDefault()) {
    _impl_.name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:tutorial.TFile.Name)
}

// repeated int32 Hosts = 3;
inline int TFile::_internal_hosts_size() const {
  return _impl_.hosts_.size();
}
inline int TFile::hosts_size() const {
  return _internal_hosts_size();
}
inline void TFile::clear_hosts() {
  _impl_.hosts_.Clear();
}
inline ::int32_t TFile::_internal_hosts(int index) const {
  return _impl_.hosts_.Get(index);
}
inline ::int32_t TFile::hosts(int index) const {
  // @@protoc_insertion_point(field_get:tutorial.TFile.Hosts)
  return _internal_hosts(index);
}
inline void TFile::set_hosts(int index, ::int32_t value) {
  _impl_.hosts_.Set(index, value);
  // @@protoc_insertion_point(field_set:tutorial.TFile.Hosts)
}
inline void TFile::_internal_add_hosts(::int32_t value) {
  _impl_.hosts_.Add(value);
}
inline void TFile::add_hosts(::int32_t value) {
  _internal_add_hosts(value);
  // @@protoc_insertion_point(field_add:tutorial.TFile.Hosts)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t >&
TFile::_internal_hosts() const {
  return _impl_.hosts_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t >&
TFile::hosts() const {
  // @@protoc_insertion_point(field_list:tutorial.TFile.Hosts)
  return _internal_hosts();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t >*
TFile::_internal_mutable_hosts() {
  return &_impl_.hosts_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t >*
TFile::mutable_hosts() {
  // @@protoc_insertion_point(field_mutable_list:tutorial.TFile.Hosts)
  return _internal_mutable_hosts();
}

// -------------------------------------------------------------------

// TFileSet

// repeated .tutorial.TFile Files = 1;
inline int TFileSet::_internal_files_size() const {
  return _impl_.files_.size();
}
inline int TFileSet::files_size() const {
  return _internal_files_size();
}
inline void TFileSet::clear_files() {
  _impl_.files_.Clear();
}
inline ::tutorial::TFile* TFileSet::mutable_files(int index) {
  // @@protoc_insertion_point(field_mutable:tutorial.TFileSet.Files)
  return _impl_.files_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::TFile >*
TFileSet::mutable_files() {
  // @@protoc_insertion_point(field_mutable_list:tutorial.TFileSet.Files)
  return &_impl_.files_;
}
inline const ::tutorial::TFile& TFileSet::_internal_files(int index) const {
  return _impl_.files_.Get(index);
}
inline const ::tutorial::TFile& TFileSet::files(int index) const {
  // @@protoc_insertion_point(field_get:tutorial.TFileSet.Files)
  return _internal_files(index);
}
inline ::tutorial::TFile* TFileSet::_internal_add_files() {
  return _impl_.files_.Add();
}
inline ::tutorial::TFile* TFileSet::add_files() {
  ::tutorial::TFile* _add = _internal_add_files();
  // @@protoc_insertion_point(field_add:tutorial.TFileSet.Files)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::TFile >&
TFileSet::files() const {
  // @@protoc_insertion_point(field_list:tutorial.TFileSet.Files)
  return _impl_.files_;
}

// required int64 Hash = 2;
inline bool TFileSet::_internal_has_hash() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool TFileSet::has_hash() const {
  return _internal_has_hash();
}
inline void TFileSet::clear_hash() {
  _impl_.hash_ = ::int64_t{0};
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline ::int64_t TFileSet::_internal_hash() const {
  return _impl_.hash_;
}
inline ::int64_t TFileSet::hash() const {
  // @@protoc_insertion_point(field_get:tutorial.TFileSet.Hash)
  return _internal_hash();
}
inline void TFileSet::_internal_set_hash(::int64_t value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.hash_ = value;
}
inline void TFileSet::set_hash(::int64_t value) {
  _internal_set_hash(value);
  // @@protoc_insertion_point(field_set:tutorial.TFileSet.Hash)
}

// -------------------------------------------------------------------

// TReport

// repeated int32 Nums = 1;
inline int TReport::_internal_nums_size() const {
  return _impl_.nums_.size();
}
inline int TReport::nums_size() const {
  return _internal_nums_size();
}
inline void TReport::clear_nums() {
  _impl_.nums_.Clear();
}
inline ::int32_t TReport::_internal_nums(int index) const {
  return _impl_.nums_.Get(index);
}
inline ::int32_t TReport::nums(int index) const {
  // @@protoc_insertion_point(field_get:tutorial.TReport.Nums)
  return _internal_nums(index);
}
inline void TReport::set_nums(int index, ::int32_t value) {
  _impl_.nums_.Set(index, value);
  // @@protoc_insertion_point(field_set:tutorial.TReport.Nums)
}
inline void TReport::_internal_add_nums(::int32_t value) {
  _impl_.nums_.Add(value);
}
inline void TReport::add_nums(::int32_t value) {
  _internal_add_nums(value);
  // @@protoc_insertion_point(field_add:tutorial.TReport.Nums)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t >&
TReport::_internal_nums() const {
  return _impl_.nums_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t >&
TReport::nums() const {
  // @@protoc_insertion_point(field_list:tutorial.TReport.Nums)
  return _internal_nums();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t >*
TReport::_internal_mutable_nums() {
  return &_impl_.nums_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::int32_t >*
TReport::mutable_nums() {
  // @@protoc_insertion_point(field_mutable_list:tutorial.TReport.Nums)
  return _internal_mutable_nums();
}

// repeated string Strings = 2;
inline int TReport::_internal_strings_size() const {
  return _impl_.strings_.size();
}
inline int TReport::strings_size() const {
  return _internal_strings_size();
}
inline void TReport::clear_strings() {
  _impl_.strings_.Clear();
}
inline std::string* TReport::add_strings() {
  std::string* _s = _internal_add_strings();
  // @@protoc_insertion_point(field_add_mutable:tutorial.TReport.Strings)
  return _s;
}
inline const std::string& TReport::_internal_strings(int index) const {
  return _impl_.strings_.Get(index);
}
inline const std::string& TReport::strings(int index) const {
  // @@protoc_insertion_point(field_get:tutorial.TReport.Strings)
  return _internal_strings(index);
}
inline std::string* TReport::mutable_strings(int index) {
  // @@protoc_insertion_point(field_mutable:tutorial.TReport.Strings)
  return _impl_.strings_.Mutable(index);
}
inline void TReport::set_strings(int index, const std::string& value) {
  _impl_.strings_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set:tutorial.TReport.Strings)
}
inline void TReport::set_strings(int index, std::string&& value) {
  _impl_.strings_.Mutable(index)->assign(std::move(value));
  // @@protoc_insertion_point(field_set:tutorial.TReport.Strings)
}
inline void TReport::set_strings(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);  _impl_.strings_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:tutorial.TReport.Strings)
}
inline void TReport::set_strings(int index, const char* value, ::size_t size) {
  _impl_.strings_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:tutorial.TReport.Strings)
}
inline std::string* TReport::_internal_add_strings() {
  return _impl_.strings_.Add();
}
inline void TReport::add_strings(const std::string& value) {
  _impl_.strings_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:tutorial.TReport.Strings)
}
inline void TReport::add_strings(std::string&& value) {
  _impl_.strings_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:tutorial.TReport.Strings)
}
inline void TReport::add_strings(const char* value) {
  GOOGLE_DCHECK(value != nullptr);  _impl_.strings_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:tutorial.TReport.Strings)
}
inline void TReport::add_strings(const char* value, ::size_t size) {
  _impl_.strings_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:tutorial.TReport.Strings)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
TReport::strings() const {
  // @@protoc_insertion_point(field_list:tutorial.TReport.Strings)
  return _impl_.strings_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
TReport::mutable_strings() {
  // @@protoc_insertion_point(field_mutable_list:tutorial.TReport.Strings)
  return &_impl_.strings_;
}

// repeated .tutorial.TFileSet SetsOfFiles = 3;
inline int TReport::_internal_setsoffiles_size() const {
  return _impl_.setsoffiles_.size();
}
inline int TReport::setsoffiles_size() const {
  return _internal_setsoffiles_size();
}
inline void TReport::clear_setsoffiles() {
  _impl_.setsoffiles_.Clear();
}
inline ::tutorial::TFileSet* TReport::mutable_setsoffiles(int index) {
  // @@protoc_insertion_point(field_mutable:tutorial.TReport.SetsOfFiles)
  return _impl_.setsoffiles_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::TFileSet >*
TReport::mutable_setsoffiles() {
  // @@protoc_insertion_point(field_mutable_list:tutorial.TReport.SetsOfFiles)
  return &_impl_.setsoffiles_;
}
inline const ::tutorial::TFileSet& TReport::_internal_setsoffiles(int index) const {
  return _impl_.setsoffiles_.Get(index);
}
inline const ::tutorial::TFileSet& TReport::setsoffiles(int index) const {
  // @@protoc_insertion_point(field_get:tutorial.TReport.SetsOfFiles)
  return _internal_setsoffiles(index);
}
inline ::tutorial::TFileSet* TReport::_internal_add_setsoffiles() {
  return _impl_.setsoffiles_.Add();
}
inline ::tutorial::TFileSet* TReport::add_setsoffiles() {
  ::tutorial::TFileSet* _add = _internal_add_setsoffiles();
  // @@protoc_insertion_point(field_add:tutorial.TReport.SetsOfFiles)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::TFileSet >&
TReport::setsoffiles() const {
  // @@protoc_insertion_point(field_list:tutorial.TReport.SetsOfFiles)
  return _impl_.setsoffiles_;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace tutorial


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_messge_2eproto_2epb_2eh