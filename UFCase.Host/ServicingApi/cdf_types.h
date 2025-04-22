#pragma once

#include "unknwn.h"
#include "oaidl.h"
#include "ocidl.h"

enum CMSSECTIONID
{
    CMSSECTIONID_FILE_SECTION = 1,
    CMSSECTIONID_CATEGORY_INSTANCE_SECTION = 2,
    CMSSECTIONID_COM_REDIRECTION_SECTION = 3,
    CMSSECTIONID_PROGID_REDIRECTION_SECTION = 4,
    CMSSECTIONID_CLR_SURROGATE_SECTION = 5,
    CMSSECTIONID_ASSEMBLY_REFERENCE_SECTION = 6,
    CMSSECTIONID_WINDOW_CLASS_SECTION = 8,
    CMSSECTIONID_STRING_SECTION = 9,
    CMSSECTIONID_ENTRYPOINT_SECTION = 10,
    CMSSECTIONID_PERMISSION_SET_SECTION = 11,
    CMSSECTIONENTRYID_METADATA = 12,
    CMSSECTIONID_ASSEMBLY_REQUEST_SECTION = 13,
    CMSSECTIONID_REGISTRY_KEY_SECTION = 16,
    CMSSECTIONID_DIRECTORY_SECTION = 17,
    CMSSECTIONID_FILE_ASSOCIATION_SECTION = 18,
    CMSSECTIONID_COMPATIBLE_FRAMEWORKS_SECTION = 19,
    CMSSECTIONID_EVENT_SECTION = 101,
    CMSSECTIONID_EVENT_MAP_SECTION = 102,
    CMSSECTIONID_EVENT_TAG_SECTION = 103,
    CMSSECTIONID_COUNTERSET_SECTION = 110,
    CMSSECTIONID_COUNTER_SECTION = 111,
};
    
enum CMS_ASSEMBLY_DEPLOYMENT_FLAG
{
    CMS_ASSEMBLY_DEPLOYMENT_FLAG_BEFORE_APPLICATION_STARTUP = 4,
    CMS_ASSEMBLY_DEPLOYMENT_FLAG_RUN_AFTER_INSTALL = 16,
    CMS_ASSEMBLY_DEPLOYMENT_FLAG_INSTALL = 32,
    CMS_ASSEMBLY_DEPLOYMENT_FLAG_TRUST_URL_PARAMETERS = 64,
    CMS_ASSEMBLY_DEPLOYMENT_FLAG_DISALLOW_URL_ACTIVATION = 128,
    CMS_ASSEMBLY_DEPLOYMENT_FLAG_MAP_FILE_EXTENSIONS = 256,
    CMS_ASSEMBLY_DEPLOYMENT_FLAG_CREATE_DESKTOP_SHORTCUT = 512,
};
    
enum CMS_ASSEMBLY_REFERENCE_FLAG
{
    CMS_ASSEMBLY_REFERENCE_FLAG_OPTIONAL = 1,
    CMS_ASSEMBLY_REFERENCE_FLAG_VISIBLE = 2,
    CMS_ASSEMBLY_REFERENCE_FLAG_FOLLOW = 4,
    CMS_ASSEMBLY_REFERENCE_FLAG_IS_PLATFORM = 8,
    CMS_ASSEMBLY_REFERENCE_FLAG_CULTURE_WILDCARDED = 16,
    CMS_ASSEMBLY_REFERENCE_FLAG_PROCESSOR_ARCHITECTURE_WILDCARDED = 32,
    CMS_ASSEMBLY_REFERENCE_FLAG_PREREQUISITE = 128,
};
    
enum CMS_ASSEMBLY_REFERENCE_DEPENDENT_ASSEMBLY_FLAG
{
    CMS_ASSEMBLY_REFERENCE_DEPENDENT_ASSEMBLY_FLAG_OPTIONAL = 1,
    CMS_ASSEMBLY_REFERENCE_DEPENDENT_ASSEMBLY_FLAG_VISIBLE = 2,
    CMS_ASSEMBLY_REFERENCE_DEPENDENT_ASSEMBLY_FLAG_PREREQUISITE = 4,
    CMS_ASSEMBLY_REFERENCE_DEPENDENT_ASSEMBLY_FLAG_RESOURCE_FALLBACK_CULTURE_INTERNAL = 8,
    CMS_ASSEMBLY_REFERENCE_DEPENDENT_ASSEMBLY_FLAG_INSTALL = 16,
    CMS_ASSEMBLY_REFERENCE_DEPENDENT_ASSEMBLY_FLAG_ALLOW_DELAYED_BINDING = 32,
};
    
enum CMS_FILE_FLAG
{
    CMS_FILE_FLAG_OPTIONAL = 1,
};
    
enum CMS_ENTRY_POINT_FLAG
{
    CMS_ENTRY_POINT_FLAG_HOST_IN_BROWSER = 1,
    CMS_ENTRY_POINT_FLAG_CUSTOMHOSTSPECIFIED = 2,
    CMS_ENTRY_POINT_FLAG_CUSTOMUX = 4,
};
    
enum CMS_COM_SERVER_FLAG
{
    CMS_COM_SERVER_FLAG_IS_CLR_CLASS = 1,
};

enum CMS_REGISTRY_KEY_FLAG
{
    CMS_REGISTRY_KEY_FLAG_OWNER = 1,
    CMS_REGISTRY_KEY_FLAG_LEAF_IN_MANIFEST = 2,
};
    
enum CMS_REGISTRY_VALUE_FLAG
{
    CMS_REGISTRY_VALUE_FLAG_OWNER = 1,
};
    
enum CMS_DIRECTORY_FLAG
{
    CMS_DIRECTORY_FLAG_OWNER = 1,
};
    
enum CMS_MANIFEST_FLAG
{
    CMS_MANIFEST_FLAG_ASSEMBLY = 1,
    CMS_MANIFEST_FLAG_CATEGORY = 2,
    CMS_MANIFEST_FLAG_FEATURE = 3,
    CMS_MANIFEST_FLAG_APPLICATION = 4,
    CMS_MANIFEST_FLAG_USEMANIFESTFORTRUST = 8,
};

enum CMS_USAGE_PATTERN
{
    CMS_USAGE_PATTERN_SCOPE_APPLICATION = 1,
    CMS_USAGE_PATTERN_SCOPE_PROCESS = 2,
    CMS_USAGE_PATTERN_SCOPE_MACHINE = 3,
    CMS_USAGE_PATTERN_SCOPE_MASK = 7,
};
    
enum CMS_SCHEMA_VERSION
{
    CMS_SCHEMA_VERSION_V1 = 1,
};
enum CMS_FILE_HASH_ALGORITHM
{
    CMS_FILE_HASH_ALGORITHM_SHA1 = 1,
    CMS_FILE_HASH_ALGORITHM_SHA256 = 2,
    CMS_FILE_HASH_ALGORITHM_SHA384 = 3,
    CMS_FILE_HASH_ALGORITHM_SHA512 = 4,
    CMS_FILE_HASH_ALGORITHM_MD5 = 5,
    CMS_FILE_HASH_ALGORITHM_MD4 = 6,
    CMS_FILE_HASH_ALGORITHM_MD2 = 7,
};
enum CMS_TIME_UNIT_TYPE
{
    CMS_TIME_UNIT_TYPE_HOURS = 1,
    CMS_TIME_UNIT_TYPE_DAYS = 2,
    CMS_TIME_UNIT_TYPE_WEEKS = 3,
    CMS_TIME_UNIT_TYPE_MONTHS = 4,
};

enum CMS_REGISTRY_VALUE_TYPE
{
    CMS_REGISTRY_VALUE_TYPE_NONE = 0,
    CMS_REGISTRY_VALUE_TYPE_SZ = 1,
    CMS_REGISTRY_VALUE_TYPE_EXPAND_SZ = 2,
    CMS_REGISTRY_VALUE_TYPE_MULTI_SZ = 3,
    CMS_REGISTRY_VALUE_TYPE_BINARY = 4,
    CMS_REGISTRY_VALUE_TYPE_DWORD = 5,
    CMS_REGISTRY_VALUE_TYPE_DWORD_LITTLE_ENDIAN = 6,
    CMS_REGISTRY_VALUE_TYPE_DWORD_BIG_ENDIAN = 7,
    CMS_REGISTRY_VALUE_TYPE_LINK = 8,
    CMS_REGISTRY_VALUE_TYPE_RESOURCE_LIST = 9,
    CMS_REGISTRY_VALUE_TYPE_FULL_RESOURCE_DESCRIPTOR = 10,
    CMS_REGISTRY_VALUE_TYPE_RESOURCE_REQUIREMENTS_LIST = 11,
    CMS_REGISTRY_VALUE_TYPE_QWORD = 12,
    CMS_REGISTRY_VALUE_TYPE_QWORD_LITTLE_ENDIAN = 13,
};
enum CMS_REGISTRY_VALUE_HINT
{
    CMS_REGISTRY_VALUE_HINT_REPLACE = 1,
    CMS_REGISTRY_VALUE_HINT_APPEND = 2,
    CMS_REGISTRY_VALUE_HINT_PREPEND = 3,
};
enum CMS_SYSTEM_PROTECTION
{
    CMS_SYSTEM_PROTECTION_READ_ONLY_IGNORE_WRITES = 1,
    CMS_SYSTEM_PROTECTION_READ_ONLY_FAIL_WRITES = 2,
    CMS_SYSTEM_PROTECTION_OS_ONLY_IGNORE_WRITES = 3,
    CMS_SYSTEM_PROTECTION_OS_ONLY_FAIL_WRITES = 4,
    CMS_SYSTEM_PROTECTION_TRANSACTED = 5,
    CMS_SYSTEM_PROTECTION_APPLICATION_VIRTUALIZED = 6,
    CMS_SYSTEM_PROTECTION_USER_VIRTUALIZED = 7,
    CMS_SYSTEM_PROTECTION_APPLICATION_AND_USER_VIRTUALIZED = 8,
    CMS_SYSTEM_PROTECTION_INHERIT = 9,
    CMS_SYSTEM_PROTECTION_NOT_PROTECTED = 10,
};

enum CMS_FILE_WRITABLE_TYPE
{
    CMS_FILE_WRITABLE_TYPE_NOT_WRITABLE = 1,
    CMS_FILE_WRITABLE_TYPE_APPLICATION_DATA = 2,
};
  
enum CMS_HASH_TRANSFORM
{
    CMS_HASH_TRANSFORM_IDENTITY = 1,
    CMS_HASH_TRANSFORM_MANIFESTINVARIANT = 2,
};
enum CMS_HASH_DIGESTMETHOD
{
    CMS_HASH_DIGESTMETHOD_SHA1 = 1,
    CMS_HASH_DIGESTMETHOD_SHA256 = 2,
    CMS_HASH_DIGESTMETHOD_SHA384 = 3,
    CMS_HASH_DIGESTMETHOD_SHA512 = 4,
};

interface __declspec(uuid("285a8862-c84a-11d7-850f-005cd062464f"))
ISection : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE get__NewEnum(IUnknown** ppEnum) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_Count(unsigned int* pCount) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_SectionID(unsigned int* pSectionID) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_SectionName(LPWSTR* ppSectionName) = 0;
};

interface __declspec(uuid("285a8861-c84a-11d7-850f-005cd062464f"))
ISectionEntry : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE GetField(unsigned int fieldId, IUnknown** ppField) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetFieldName(unsigned int fieldId, LPWSTR* ppFieldName) = 0;
};

interface __declspec(uuid("285a8871-c84a-11d7-850f-005cd062464f"))
ISectionWithStringKey : public IUnknown
{
    virtual void STDMETHODCALLTYPE Lookup(LPCWSTR wzStringKey, IUnknown** ppUnknown) = 0;
    virtual bool STDMETHODCALLTYPE get_IsCaseInsensitive() = 0;
};

interface __declspec(uuid("285a8876-c84a-11d7-850f-005cd062464f"))
ISectionWithReferenceIdentityKey : public IUnknown
{
    virtual void STDMETHODCALLTYPE Lookup(IReferenceIdentity* ReferenceIdentityKey, IUnknown** ppUnknown) = 0;
};

//interface __declspec(uuid("00000100-0000-0000-C000-000000000046"))
//IEnumUnknown : public IUnknown
//{
//    virtual HRESULT STDMETHODCALLTYPE Next(
//        unsigned int celt,
//        IUnknown** rgelt,
//        unsigned int* pceltFetched
//    ) = 0;
//
//    virtual HRESULT STDMETHODCALLTYPE Skip(
//        unsigned int celt
//    ) = 0;
//
//    virtual HRESULT STDMETHODCALLTYPE Reset() = 0;
//
//    virtual HRESULT STDMETHODCALLTYPE Clone(
//        IEnumUnknown** ppEnum
//    ) = 0;
//};

template <typename IEnumT, typename T>
interface IEnumStructTemplate : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Next(
        unsigned int celt,
        T* rgelt,
        unsigned int* pceltFetched
    ) = 0;

    virtual HRESULT STDMETHODCALLTYPE Skip(
        unsigned int celt
    ) = 0;

    virtual HRESULT STDMETHODCALLTYPE Reset() = 0;

    virtual HRESULT STDMETHODCALLTYPE Clone(
        IEnumT** ppEnum
    ) = 0;
};

struct CMS_WINDOWS_CLASS_ENTRY
{
    LPWSTR ClassName;
    LPWSTR HostDll;
    bool fVersioned;
};

interface __declspec(uuid("8AD3FC86-AFD3-477a-8FD5-146C291195BA")) IWindowClassEntry : public IUnknown
{
    // Define the AllData property
    STDMETHOD(get_AllData)(/* [out, retval] */ CMS_WINDOWS_CLASS_ENTRY* pAllData) = 0;

    // Define the ClassName property
    STDMETHOD(get_ClassName)(/* [out, retval] */ LPWSTR* pClassName) = 0;

    // Define the HostDll property
    STDMETHOD(get_HostDll)(/* [out, retval] */ LPWSTR* pHostDll) = 0;

    // Define the fVersioned property
    STDMETHOD(get_fVersioned)(/* [out, retval] */ VARIANT_BOOL* pfVersioned) = 0;
};

#define DEFINE_IENUM_STRUCT(name, guid) \
    interface __declspec(uuid(guid)) IEnum##name                               \
        : public IEnumStructTemplate<IEnum##name, name> {}

interface __declspec(uuid("a504e5b0-8ccf-4cb4-9902-c9d1b9abd033"))
ICMS : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE get_Identity(IDefinitionIdentity** ppIdentity) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_FileSection(ISection** ppFileSection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_CategoryMembershipSection(ISection** ppCategoryMembershipSection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_COMRedirectionSection(ISection** ppCOMRedirectionSection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_ProgIdRedirectionSection(ISection** ppProgIdRedirectionSection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_CLRSurrogateSection(ISection** ppCLRSurrogateSection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_AssemblyReferenceSection(ISection** ppAssemblyReferenceSection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_WindowClassSection(ISection** ppWindowClassSection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_StringSection(ISection** ppStringSection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_EntryPointSection(ISection** ppEntryPointSection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_PermissionSetSection(ISection** ppPermissionSetSection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_MetadataSectionEntry(ISectionEntry** ppMetadataSectionEntry) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_AssemblyRequestSection(ISection** ppAssemblyRequestSection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_RegistryKeySection(ISection** ppRegistryKeySection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_DirectorySection(ISection** ppDirectorySection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_FileAssociationSection(ISection** ppFileAssociationSection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_CompatibleFrameworksSection(ISection** ppCompatibleFrameworksSection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_EventSection(ISection** ppEventSection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_EventMapSection(ISection** ppEventMapSection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_EventTagSection(ISection** ppEventTagSection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_CounterSetSection(ISection** ppCounterSetSection) = 0;
    virtual HRESULT STDMETHODCALLTYPE get_CounterSection(ISection** ppCounterSection) = 0;
};

struct CDF_BLOBID { int Index; };
struct CDF_STRINGID { int Index; };
struct CDF_GUIDID { int Index; };
struct CDF_IDENTITYID { int Index; };
struct CDF_APPIDID { int Index; };

struct CDF_ULONG_TABLE_ITEM{
  DWORD unk1; // -1
  DWORD unk2; // -1
};
DEFINE_IENUM_STRUCT(CDF_ULONG_TABLE_ITEM, "dfb228a4-c10c-4bf5-addb-bc13699955bd");

struct CDF_STRING_TABLE_ITEM{
  DWORD string_id; // -1
  DWORD unk2; // -1
};
DEFINE_IENUM_STRUCT(CDF_STRING_TABLE_ITEM, "54d3c966-c451-47ac-b06f-41514e830586");
struct CDF_BINARY_TABLE_ITEM{
  DWORD unk1; // -1
  DWORD unk2; // -1
};
DEFINE_IENUM_STRUCT(CDF_BINARY_TABLE_ITEM, "0943e6ce-bc25-423f-ac15-b925215e996c");
struct CDF_GUID_TABLE_ITEM{
  DWORD unk1; // 0
  DWORD unk2; // -1
};
DEFINE_IENUM_STRUCT(CDF_GUID_TABLE_ITEM, "6db54894-dfb8-4e63-acf4-c24394c1a824");
struct CDF_DEFINITION_IDENTITY_TABLE_ITEM{
  DWORD unk1; // -1
  DWORD unk2; // -1
};
DEFINE_IENUM_STRUCT(CDF_DEFINITION_IDENTITY_TABLE_ITEM, "ff0ca21e-7734-42a5-b87d-0d5316477e99");
struct CDF_REFERENCE_IDENTITY_TABLE_ITEM{
  DWORD unk1; // -1
  DWORD unk2; // -1
};
DEFINE_IENUM_STRUCT(CDF_REFERENCE_IDENTITY_TABLE_ITEM, "2aa41b1f-a2ff-41f8-84a5-a8aae6e795f8");
struct CDF_APPID_TABLE_ITEM{
  DWORD unk1; // -1
  DWORD unk2; // -1
};
DEFINE_IENUM_STRUCT(CDF_APPID_TABLE_ITEM, "8a05ee56-3615-46ce-acf8-f34dc46e3b78");

struct __declspec(uuid("E19364F9-E580-4867-936C-F2D4FB7A49DC")) ICDF : IUnknown {
  virtual HRESULT GetTableOfContents(CDF_BLOBID *) = 0;
  virtual HRESULT GetString(CDF_STRINGID, wchar_t **) = 0;
  virtual HRESULT GetGUID(CDF_GUIDID, _GUID *) = 0;
  virtual HRESULT GetBlob(CDF_BLOBID, unsigned __int64 *, void **) = 0;
  virtual HRESULT GetDefinitionIdentity(CDF_IDENTITYID, interface IDefinitionIdentity **) = 0;
  virtual HRESULT GetReferenceIdentity(CDF_IDENTITYID, interface IReferenceIdentity **) = 0;
  virtual HRESULT GetDefinitionAppId(CDF_APPIDID, interface IDefinitionAppId **) = 0;
  virtual HRESULT GetReferenceAppId(CDF_APPIDID, interface IReferenceAppId **) = 0;
  virtual HRESULT EnumerateStringTable(ULONG, CDF_BLOBID,
                               IEnumCDF_STRING_TABLE_ITEM **) = 0;
  virtual HRESULT SearchStringTable(ULONG, CDF_BLOBID, wchar_t const *,
                            CDF_BLOBID *) = 0;
  virtual HRESULT EnumerateBinaryTable(ULONG, CDF_BLOBID,
                               IEnumCDF_BINARY_TABLE_ITEM **) = 0;
  virtual HRESULT SearchBinaryTable(ULONG, CDF_BLOBID, unsigned __int64,
                            BYTE const *const, CDF_BLOBID *) = 0;
  virtual HRESULT EnumerateGUIDTable(ULONG, CDF_BLOBID,
                             IEnumCDF_GUID_TABLE_ITEM **) = 0;
  virtual HRESULT SearchGUIDTable(ULONG, CDF_BLOBID, _GUID const &, CDF_BLOBID *) = 0;
  virtual HRESULT EnumerateULONGTable(ULONG, CDF_BLOBID,
                              IEnumCDF_ULONG_TABLE_ITEM **) = 0;
  virtual HRESULT SearchULONGTable(ULONG, CDF_BLOBID, ULONG, CDF_BLOBID *) = 0;
  virtual HRESULT EnumerateDefinitionIdentityTable(
      ULONG, CDF_BLOBID, IEnumCDF_DEFINITION_IDENTITY_TABLE_ITEM **) = 0;
  virtual HRESULT SearchDefinitionIdentityTable(ULONG, CDF_BLOBID,
                                        IDefinitionIdentity *,
                                        CDF_BLOBID *) = 0;
  virtual HRESULT EnumerateReferenceIdentityTable(
      ULONG, CDF_BLOBID, IEnumCDF_REFERENCE_IDENTITY_TABLE_ITEM **) = 0;
  virtual HRESULT SearchReferenceIdentityTable(ULONG, CDF_BLOBID, IReferenceIdentity *,
                                       CDF_BLOBID *) = 0;
  virtual HRESULT EnumerateAppIdTable(ULONG, CDF_BLOBID,
                              IEnumCDF_APPID_TABLE_ITEM **) = 0;
  virtual HRESULT SearchAppIdTableWithDefinitionAppId(ULONG, CDF_BLOBID,
                                              IDefinitionAppId *,
                                              CDF_BLOBID *) = 0;
  virtual HRESULT SearchAppIdTableWithReferenceAppId(ULONG, CDF_BLOBID,
                                             IReferenceAppId *,
                                             CDF_BLOBID *) = 0;
  virtual HRESULT GetXmlDocument(ULONG, _GUID const &, void **) = 0;
};

struct __declspec(uuid("2BE3FEBD-98B4-462E-AA3F-E9F6C76CB421"))
ICDF_Internal : IUnknown {
  virtual struct WcpManifest *GetManifest() = 0;
  virtual HRESULT Disown() = 0;
};
