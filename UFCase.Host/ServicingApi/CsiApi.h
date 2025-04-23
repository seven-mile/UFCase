#pragma once

#include "isolation.h"

#include "wcpdef.h"

struct CSI_FILE {};

struct IEnumCSI_FILE : IUnknown {
  virtual HRESULT STDMETHODCALLTYPE
  QueryInterface(REFIID riid, _Out_ LPVOID *ppvObject) override = 0;
  virtual ULONG STDMETHODCALLTYPE AddRef(void) override = 0;
  virtual ULONG STDMETHODCALLTYPE Release(void) override = 0;

  virtual HRESULT STDMETHODCALLTYPE Next(ULONG celt,
                                         _Out_ struct CSIFILE *rgpCol,
                                         _Out_ ULONG *pbFetched) = 0;
  virtual HRESULT STDMETHODCALLTYPE Skip(ULONG celt) = 0;
  virtual HRESULT STDMETHODCALLTYPE Reset(void) = 0;
  virtual HRESULT STDMETHODCALLTYPE Clone(_Out_ IEnumCSI_FILE **) = 0;
};

struct ICSITransaction : IUnknown {
  virtual HRESULT STDMETHODCALLTYPE
  QueryInterface(REFIID riid, _Out_ LPVOID *ppvObject) override = 0;
  virtual ULONG STDMETHODCALLTYPE AddRef(void) override = 0;
  virtual ULONG STDMETHODCALLTYPE Release(void) override = 0;

  virtual HRESULT STDMETHODCALLTYPE
  InstallDeployment(ULONG, IDefinitionIdentity *, wchar_t const *,
                    wchar_t const *, wchar_t const *, wchar_t const *,
                    wchar_t const *, wchar_t const *, ULONG *) = 0;
  virtual HRESULT STDMETHODCALLTYPE
  PinDeployment(ULONG, IDefinitionIdentity *, wchar_t const *, wchar_t const *,
                wchar_t const *, wchar_t const *, wchar_t const *,
                wchar_t const *, unsigned __int64, ULONG *) = 0;
  virtual HRESULT STDMETHODCALLTYPE
  UninstallDeployment(ULONG, IDefinitionIdentity *, wchar_t const *,
                      wchar_t const *, wchar_t const *, ULONG *) = 0;
  virtual HRESULT STDMETHODCALLTYPE
  UnpinDeployment(ULONG, IDefinitionIdentity *, wchar_t const *,
                  wchar_t const *, wchar_t const *, ULONG *) = 0;
  virtual HRESULT STDMETHODCALLTYPE
  EnumMissingComponents(ULONG, IEnumDefinitionIdentity **, ULONG *) = 0;
  virtual HRESULT STDMETHODCALLTYPE AddComponent(ULONG, IDefinitionIdentity *,
                                                 wchar_t const *, ULONG *) = 0;
  virtual HRESULT STDMETHODCALLTYPE EnumMissingFiles(ULONG,
                                                     IEnumCSI_FILE **) = 0;
  virtual HRESULT STDMETHODCALLTYPE AddFile(ULONG, IDefinitionIdentity *,
                                            wchar_t const *, wchar_t const *,
                                            ULONG *) = 0;
  virtual HRESULT STDMETHODCALLTYPE Analyze(ULONG, _GUID const &,
                                            IUnknown **) = 0;
  virtual HRESULT STDMETHODCALLTYPE Commit(ULONG,
                                           struct ICSITransactionCommitSink *,
                                           ULONG *) = 0;
  virtual HRESULT STDMETHODCALLTYPE Abort(ULONG, ULONG *) = 0;
  virtual HRESULT STDMETHODCALLTYPE Scavenge(ULONG, IDefinitionIdentity *,
                                             wchar_t const *, wchar_t const *,
                                             ULONG *) = 0;
};

struct ICSIRepairTransaction : ICSITransaction {
  virtual HRESULT STDMETHODCALLTYPE
  QueryInterface(REFIID riid, _Out_ LPVOID *ppvObject) override = 0;
  virtual ULONG STDMETHODCALLTYPE AddRef(void) override = 0;
  virtual ULONG STDMETHODCALLTYPE Release(void) override = 0;
};

enum ICSISTORE_GET_COMPONENT_INFORMATION_CLASS {
  ICSISTORE_GET_COMPONENT_INFORMATION_CLASS_BASIC = 1,
  ICSISTORE_GET_COMPONENT_INFORMATION_CLASS_PAYLOAD = 2,
};

/// <summary>
/// STAGED      = 0x1, map to 2
/// LOCKED      = 0x2, map to 2
/// PINNED      = 0x4, map to 3
/// INSTALLED   = 0x8, map to 4(v) 5(x)
/// PRESTAGED   = 0x10 map to 1
/// </summary>
typedef enum _CSI_COMPONENT_STATUS {
  CSI_COMPONENT_STATUS_PRESTAGED = 1,
  CSI_COMPONENT_STATUS_STAGED = 2,
  CSI_COMPONENT_STATUS_PINNED = 3,
  CSI_COMPONENT_STATUS_INSTALLED_MATCH = 4,
  CSI_COMPONENT_STATUS_INSTALLED_MISMATCH = 5,
} CSI_COMPONENT_STATUS;

typedef struct _CSI_COMPONENT_BASIC_INFORMATION {
  DWORD cbSize;
  DWORD dwCsiStatus;
  BOOL bIsComplete;
} CSI_COMPONENT_BASIC_INFORMATION;

typedef struct _CSI_COMPONENT_PAYLOAD_INFORMATION {
  DWORD cbSize;
  LPWSTR pszPayloadRoot;
  IUnknown *pComponentLock;
} CSI_COMPONENT_PAYLOAD_INFORMATION;

struct __declspec(uuid("465F1EC1-7F1D-4A85-A30B-AE1090F212DB")) ICSIStore
    : IUnknown {
  virtual HRESULT STDMETHODCALLTYPE
  QueryInterface(REFIID riid, _Out_ LPVOID *ppvObject) override = 0;
  virtual ULONG STDMETHODCALLTYPE AddRef(void) override = 0;
  virtual ULONG STDMETHODCALLTYPE Release(void) override = 0;

  virtual HRESULT STDMETHODCALLTYPE BeginTransaction(
      DWORD, _GUID const &, LPCTSTR client_id, _Out_ ICSITransaction **) = 0;
  virtual HRESULT STDMETHODCALLTYPE CancelPendingTransaction(DWORD,
                                                             _GUID const &,
                                                             LPCTSTR,
                                                             _Out_ ULONG *) = 0;
  virtual HRESULT STDMETHODCALLTYPE BeginRepairTransaction(
      DWORD, _Out_ ICSIRepairTransaction **, _Out_ ULONG *) = 0;
  virtual HRESULT STDMETHODCALLTYPE
  CancelPendingRepairTransaction(ULONG, _Out_ ULONG *) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetComponentManifests(
      DWORD dwFlags, SIZE_T cnt, IDefinitionIdentity *def_idents[],
      _GUID const &, _Out_ IUnknown *manifests[]) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetComponentInstalledVersions(
      DWORD dwFlags, SIZE_T cnt_idents, _Out_ IDefinitionIdentity *def_idents[],
      _Out_ ULONG *cnt_versions, _Out_ COMPONENT_VERSION versions[]) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetComponentInformation(
      DWORD dwFlags, ICSISTORE_GET_COMPONENT_INFORMATION_CLASS dwClass,
      IDefinitionIdentity *, SIZE_T cbSize, _Out_ void *) = 0;
  virtual HRESULT STDMETHODCALLTYPE ReplaceMacros(DWORD, IDefinitionIdentity *,
                                                  LPCTSTR, _Out_ LPTSTR *) = 0;
  virtual HRESULT STDMETHODCALLTYPE
  EnumPendingTransactions(DWORD, _GUID const &, _Out_ IUnknown **) = 0;
  virtual HRESULT STDMETHODCALLTYPE CancelPendingTransactions(
      DWORD, UINT64, _Out_ LPCTSTR const *, _Out_ ULONG *) = 0;
};

template <class T> struct Windows_Vector {};

template <class T> struct Windows_Auto {};

// Impl by CCSDirect
struct __declspec(uuid("0EA177A8-E913-11D9-92E9-00E0816A6477"))
    IRtlComponentStore {
  virtual HRESULT STDMETHODCALLTYPE Release(void) = 0;
  virtual HRESULT STDMETHODCALLTYPE
  CreateInstance(const GUID &, struct Windows_Rtl_IRtlObject **) = 0;

  virtual BOOL STDMETHODCALLTYPE IsStoreOffline(void) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetStoreIdentifier(_GUID *) = 0;
  virtual HRESULT STDMETHODCALLTYPE CreateTransaction(
      ULONG, struct Windows_ComponentStore_Rtl_IRtlTransactionHook *,
      struct Windows_ComponentStore_Rtl_IRtlTransaction **) = 0;
  virtual HRESULT STDMETHODCALLTYPE RepairComponents(
      ULONG,
      struct Windows_Vector<
          struct Windows_ComponentStore_Rtl_RepairOperation const> const &,
      struct Windows_Vector<ULONG> const &,
      struct Windows_ComponentStore_Rtl_IRtlRepairTransactionResult **) = 0;
  virtual HRESULT STDMETHODCALLTYPE
  GetComponentManifest(struct Windows_Identity_Rtl_IRtlDefinitionIdentity *,
                       struct WcpManifest *) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetComponentManifest(
      ULONG, struct Windows_Identity_Rtl_IRtlDefinitionIdentity *,
      tagBLOB *) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetComponentManifest(
      ULONG, struct Windows_Identity_Rtl_IRtlDefinitionIdentity *,
      struct Windows_Cdf_Rtl_IRtlCdf **) = 0;
  virtual HRESULT STDMETHODCALLTYPE EnumerateComponents(
      ULONG, struct Windows_Identity_Rtl_IRtlReferenceIdentity *,
      struct Windows_ComponentStore_Rtl_IRtlComponentEnumerator **) = 0;
  virtual HRESULT STDMETHODCALLTYPE EnumerateWinnersList(
      ULONG, struct Windows_Identity_Rtl_IRtlDefinitionIdentity *,
      struct Windows_ComponentStore_Rtl_IRtlComponentEnumerator **) = 0;
  virtual HRESULT STDMETHODCALLTYPE EnumerateComponentFiles(
      ULONG, struct Windows_AppId_Rtl_IRtlDefinitionAppId *,
      struct Windows_Identity_Rtl_IRtlDefinitionIdentity *,
      struct Windows_ComponentStore_Rtl_IRtlComponentFileEnumerator **) = 0;
  virtual HRESULT STDMETHODCALLTYPE IsComponentComplete(
      ULONG, struct Windows_AppId_Rtl_IRtlDefinitionAppId *,
      struct Windows_Identity_Rtl_IRtlDefinitionIdentity *, bool *) = 0;
  virtual HRESULT STDMETHODCALLTYPE EnumerateComponentTopLevelComponents(
      ULONG, struct Windows_Identity_Rtl_IRtlDefinitionIdentity *,
      struct Windows_AppId_Rtl_IRtlReferenceAppId *,
      struct Windows_ComponentStore_Rtl_IRtlTopLevelComponentEnumerator **) = 0;
  virtual HRESULT STDMETHODCALLTYPE EnumerateTopLevelComponentReferences(
      ULONG, struct Windows_AppId_Rtl_IRtlDefinitionAppId *,
      struct Windows_ComponentStore_Rtl_StoreInstallerReference const *,
      struct Windows_ComponentStore_Rtl_IRtlTopLevelComponentReferenceEnumerator
          **) = 0;
  virtual HRESULT STDMETHODCALLTYPE EnumerateTopLevelComponents(
      ULONG, struct Windows_AppId_Rtl_IRtlReferenceAppId *,
      struct Windows_ComponentStore_Rtl_IRtlTopLevelComponentEnumerator **) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetComponentWinningVersion(
      ULONG, struct Windows_Identity_Rtl_IRtlDefinitionIdentity *,
      struct _FOUR_PART_VERSION *, ULONG *) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetDefaultStorageArea(
      ULONG, struct
      Windows_ComponentStore_Rtl_IRtlComponentStore_StorageAreaInformation
          *) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetComponentStatus(
      ULONG,
      struct Windows_Vector<
          struct Windows_Identity_Rtl_IRtlDefinitionIdentity *> const &,
      struct Windows_Vector<ULONG> const &) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetDeploymentClosureStatus(
      ULONG,
      struct Windows_Vector<
          struct Windows_AppId_Rtl_IRtlDefinitionAppId *> const &,
      struct Windows_Vector<ULONG> const &) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetCompositionalClosure(
      ULONG,
      struct Windows_Vector<
          struct Windows_AppId_Rtl_IRtlDefinitionAppId *> const &,
      struct Windows_ComponentStore_Rtl_IRtlCompositionalClosureEnumerator *
          *) = 0;
  virtual HRESULT STDMETHODCALLTYPE DetermineComponentLockPath(
      ULONG,
      struct Windows_Vector<
          struct Windows_Identity_Rtl_IRtlDefinitionIdentity *> const &,
      struct Windows_Vector<_LUNICODE_STRING> const &) = 0;
  virtual HRESULT STDMETHODCALLTYPE CreateLockIdentifier(
      ULONG,
      struct Windows_ComponentStore_Rtl_ComponentStoreLockIdentifier *) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetTemporaryDirectory(
      ULONG, struct Windows_Rtl_IRtlDirectory **, void **) = 0;
  virtual HRESULT STDMETHODCALLTYPE ReleaseTemporaryDirectory(void *,
                                                              struct UpdateMgr,
                                                              ...) = 0;
  virtual HRESULT STDMETHODCALLTYPE ReleaseTemporaryDirectory(void *) = 0;
  virtual HRESULT STDMETHODCALLTYPE
  GetIsolationLayer(struct Windows_Rtl_IRtlSystemIsolationLayer **) = 0;
  virtual HRESULT STDMETHODCALLTYPE
  GetExternalDirectory(struct Windows_Rtl_IRtlDirectory **) = 0;
  virtual HRESULT STDMETHODCALLTYPE
  GetExternalDirectoryPath(_LUNICODE_STRING const **) = 0;
  virtual HRESULT STDMETHODCALLTYPE HasExternalDirectory(bool *) = 0;
  virtual HRESULT STDMETHODCALLTYPE ReleaseComponentAndPathLocks(
      ULONG,
      struct Windows_Vector<
          struct
          Windows_ComponentStore_Rtl_StoreOperation_UnlockSingleComponent const> const
          &,
      struct Windows_Vector<
          struct
          Windows_ComponentStore_Rtl_StoreOperation_UnlockSingleComponentPath const> const
          &,
      struct Windows_Vector<ULONG> const &,
      struct Windows_Vector<ULONG> const &) = 0;
  virtual HRESULT STDMETHODCALLTYPE EnumStoreCorruptions(
      ULONG,
      struct Windows_Vector<
          struct
          Windows_ComponentStore_Rtl_IRtlComponentStore_StoreCorruptionResult>
          &,
      struct Windows_Rtl_IRtlSystemIsolationLayer *&, ULONG *) = 0;
  virtual HRESULT STDMETHODCALLTYPE RepairStoreCorruptions(
      ULONG,
      struct Windows_Vector<
          struct
          Windows_ComponentStore_Rtl_IRtlComponentStore_StoreCorruptionRepairOp> const
          &,
      struct Windows_Rtl_IRtlSystemIsolationLayer *&,
      struct Windows_Vector<ULONG> &, ULONG *) = 0;
  virtual HRESULT STDMETHODCALLTYPE WofCompressFileIfShouldBeCompressed(
      ULONG, struct Windows_Identity_Rtl_IRtlDefinitionIdentity *,
      _LUNICODE_STRING const &, struct Windows_Rtl_IRtlFile *) = 0;
  virtual HRESULT STDMETHODCALLTYPE EnsureComponentFullyPresent(
      ULONG, struct Windows_Identity_Rtl_IRtlDefinitionIdentity *,
      struct WcpManifest const *, ULONG *) = 0;
  virtual HRESULT STDMETHODCALLTYPE QueryConfigurationOption(_GUID const &,
                                                             ULONG,
                                                             ULONG *) = 0;
  virtual HRESULT STDMETHODCALLTYPE QueryConfigurationOption(_GUID const &,
                                                             bool, bool *) = 0;
  virtual HRESULT STDMETHODCALLTYPE IsMobileStore(void) = 0;
  virtual HRESULT STDMETHODCALLTYPE UseDeconstructedDrivers(void) = 0;
};

struct __declspec(uuid("82462D00-0DA3-4446-8621-3200CD2A570A"))
    IStore_NtInternal : IUnknown {
  virtual HRESULT STDMETHODCALLTYPE
  QueryInterface(REFIID riid, _Out_ LPVOID *ppvObject) override = 0;
  virtual ULONG STDMETHODCALLTYPE AddRef(void) override = 0;
  virtual ULONG STDMETHODCALLTYPE Release(void) override = 0;

  virtual IRtlComponentStore *STDMETHODCALLTYPE GetHandlePtr(void) = 0;
};

/// wcp.dll Lifetime

typedef HRESULT(__stdcall *PWCP_INITIALIZE_FUNCTION)(PVOID *ppCookie);

typedef HRESULT(__stdcall *PWCP_SHUTDOWN_FUNCTION)(PVOID pCookie);

typedef HRESULT(__stdcall *PDISMOUNT_REGISTRY_HIVES_FUNCTION)(PVOID pCookie);

/// dfshim.dll

typedef HRESULT(__stdcall *PCREATE_CMS_FROM_XML_FUNCTION)(
    _In_ char *buffer, _In_ UINT32 bufferSize,
    _In_ IManifestParseErrorCallback *Callback, _In_ _GUID const &riid,
    _Out_ IUnknown **ppvObject);
