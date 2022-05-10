

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0626 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for CbsApi.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0626 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __CbsApi_h__
#define __CbsApi_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if _CONTROL_FLOW_GUARD_XFG
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __CbsSession_FWD_DEFINED__
#define __CbsSession_FWD_DEFINED__

#ifdef __cplusplus
typedef class CbsSession CbsSession;
#else
typedef struct CbsSession CbsSession;
#endif /* __cplusplus */

#endif 	/* __CbsSession_FWD_DEFINED__ */


#ifndef __ICbsIdentity_FWD_DEFINED__
#define __ICbsIdentity_FWD_DEFINED__
typedef interface ICbsIdentity ICbsIdentity;

#endif 	/* __ICbsIdentity_FWD_DEFINED__ */


#ifndef __ICbsFeaturePackage_FWD_DEFINED__
#define __ICbsFeaturePackage_FWD_DEFINED__
typedef interface ICbsFeaturePackage ICbsFeaturePackage;

#endif 	/* __ICbsFeaturePackage_FWD_DEFINED__ */


#ifndef __ICbsPackage_FWD_DEFINED__
#define __ICbsPackage_FWD_DEFINED__
typedef interface ICbsPackage ICbsPackage;

#endif 	/* __ICbsPackage_FWD_DEFINED__ */


#ifndef __ICbsUpdate_FWD_DEFINED__
#define __ICbsUpdate_FWD_DEFINED__
typedef interface ICbsUpdate ICbsUpdate;

#endif 	/* __ICbsUpdate_FWD_DEFINED__ */


#ifndef __ICbsUIHandler_FWD_DEFINED__
#define __ICbsUIHandler_FWD_DEFINED__
typedef interface ICbsUIHandler ICbsUIHandler;

#endif 	/* __ICbsUIHandler_FWD_DEFINED__ */


#ifndef __ICbsCapability_FWD_DEFINED__
#define __ICbsCapability_FWD_DEFINED__
typedef interface ICbsCapability ICbsCapability;

#endif 	/* __ICbsCapability_FWD_DEFINED__ */


#ifndef __IEnumCbsIdentity_FWD_DEFINED__
#define __IEnumCbsIdentity_FWD_DEFINED__
typedef interface IEnumCbsIdentity IEnumCbsIdentity;

#endif 	/* __IEnumCbsIdentity_FWD_DEFINED__ */


#ifndef __IEnumCbsCapability_FWD_DEFINED__
#define __IEnumCbsCapability_FWD_DEFINED__
typedef interface IEnumCbsCapability IEnumCbsCapability;

#endif 	/* __IEnumCbsCapability_FWD_DEFINED__ */


#ifndef __IEnumCbsUpdate_FWD_DEFINED__
#define __IEnumCbsUpdate_FWD_DEFINED__
typedef interface IEnumCbsUpdate IEnumCbsUpdate;

#endif 	/* __IEnumCbsUpdate_FWD_DEFINED__ */


#ifndef __IEnumCbsActivity_FWD_DEFINED__
#define __IEnumCbsActivity_FWD_DEFINED__
typedef interface IEnumCbsActivity IEnumCbsActivity;

#endif 	/* __IEnumCbsActivity_FWD_DEFINED__ */


#ifndef __IEnumCbsFeaturePackage_FWD_DEFINED__
#define __IEnumCbsFeaturePackage_FWD_DEFINED__
typedef interface IEnumCbsFeaturePackage IEnumCbsFeaturePackage;

#endif 	/* __IEnumCbsFeaturePackage_FWD_DEFINED__ */


#ifndef __IEnumCbsSession_FWD_DEFINED__
#define __IEnumCbsSession_FWD_DEFINED__
typedef interface IEnumCbsSession IEnumCbsSession;

#endif 	/* __IEnumCbsSession_FWD_DEFINED__ */


#ifndef __ICSIExternalTransformerExecutor_FWD_DEFINED__
#define __ICSIExternalTransformerExecutor_FWD_DEFINED__
typedef interface ICSIExternalTransformerExecutor ICSIExternalTransformerExecutor;

#endif 	/* __ICSIExternalTransformerExecutor_FWD_DEFINED__ */


#ifndef __ICbsSessionObserverListener_FWD_DEFINED__
#define __ICbsSessionObserverListener_FWD_DEFINED__
typedef interface ICbsSessionObserverListener ICbsSessionObserverListener;

#endif 	/* __ICbsSessionObserverListener_FWD_DEFINED__ */


#ifndef __ICbsSession_FWD_DEFINED__
#define __ICbsSession_FWD_DEFINED__
typedef interface ICbsSession ICbsSession;

#endif 	/* __ICbsSession_FWD_DEFINED__ */


#ifndef __ICbsSession7_FWD_DEFINED__
#define __ICbsSession7_FWD_DEFINED__
typedef interface ICbsSession7 ICbsSession7;

#endif 	/* __ICbsSession7_FWD_DEFINED__ */


#ifndef __ICbsSession8_FWD_DEFINED__
#define __ICbsSession8_FWD_DEFINED__
typedef interface ICbsSession8 ICbsSession8;

#endif 	/* __ICbsSession8_FWD_DEFINED__ */


#ifndef __ICbsSession10_FWD_DEFINED__
#define __ICbsSession10_FWD_DEFINED__
typedef interface ICbsSession10 ICbsSession10;

#endif 	/* __ICbsSession10_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_CbsApi_0000_0000 */
/* [local] */ 

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0001
    {
        CbsStateResolvedInvalid	= -32,
        CbsStateStagedInvalid	= -64,
        CbsStateInstalledInvalid	= -112,
        CbsStatePermanentInvalid	= -128,
        CbsStateAbsent	= 0,
        CbsStateUninstallPending	= 5,
        CbsStateResolving	= 16,
        CbsStateResolved	= 32,
        CbsStateStaging	= 48,
        CbsStateStaged	= 64,
        CbsStateSuperseded	= 80,
        CbsStateInstallPending	= 96,
        CbsStatePartiallyInstalled	= 101,
        CbsStateInstalled	= 112,
        CbsStatePermanent	= 128,
        CbsStateDefault	= 4096,
        CbsStateDetect	= 4100,
        CbsStateCanceled	= 4101
    } 	CbsState;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0002
    {
        UpdateSelectionUnknown	= -1,
        UpdateSelectionOff	= 0,
        UpdateSelectionOn	= 1,
        UpdateSelectionDefault	= 255,
        UpdateSelectionCancel	= 999
    } 	UpdateSelection;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0003
    {
        CbsPackageTypeUnknown	= -2,
        CbsPackageTypeExisting	= -1,
        CbsPackageTypeCabinet	= 0,
        CbsPackageTypeExpanded	= 1,
        CbsPackageTypeManifest	= 2,
        CbsPackageTypeXmlString	= 3,
        CbsPackageTypeExpandedWithMum	= 4
    } 	_CbsPackageType;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0004
    {
        CbsRequiredActionNone	= 0,
        CbsRequiredActionReboot	= 1
    } 	_CbsRequiredAction;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0005
    {
        CbsSessionPropertyRebootRequired	= 1,
        CbsSessionPropertyErrorDetail	= 2,
        CbsSessionPropertyServiceable	= 3,
        CbsSessionPropertyCompressionEnabled	= 4,
        CbsSessionPropertyReport	= 5,
        CbsSessionPropertyCorruptionFlag	= 6,
        CbsSessionPropertyVolatileSize	= 8,
        CbsSessionPropertyNonVolatileSize	= 9,
        CbsSessionPropertySharedWithWindowsSize	= 10,
        CbsSessionPropertyAccordingToExplorer	= 11,
        CbsSessionPropertyLastScavengeDatetime	= 12,
        CbsSessionPropertySupersededPackageCount	= 13,
        CbsSessionPropertyComponentCleanupRecommended	= 14,
        CbsSessionPropertySessionCompletionDatatime	= 15,
        CbsSessionPropertyPackageMinSize	= 16,
        CbsSessionPropertyTotalPackageMinSize	= 18,
        CbsSessionPropertyRepairNeeded	= 22,
        CbsSessionPropertyReOffer	= 23
    } 	_CbsSessionProperty;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0006
    {
        CbsSessionOptionNone	= 0,
        CbsSessionOptionProcessChangesPostReboot	= 0x40,
        CbsSessionOptionLoadPersisted	= 0x80,
        CbsSessionOptionDoScavenge	= 0x400,
        CbsSessionOptionCancelAllPendedTransactions	= 0x800,
        CbsSessionOptionEnableCompression	= 0x2000,
        CbsSessionOptionDisableCompression	= 0x4000,
        CbsSessionOptionDetectAndRepairStoreCorruption	= 0xc000,
        CbsSessionOptionNoPend	= 0x10000,
        CbsSessionOptionUseLocalSourceOnly	= 0x20000,
        CbsSessionOptionUseWindowsUpdate	= 0x40000,
        CbsSessionOptionReportStackInfo	= 0x100000,
        CbsSessionOptionDoSynchronousCleanup	= 0x400000,
        CbsSessionOptionDoAsynchronousCleanup	= 0x800000,
        CbsSessionOptionDelayExecutionIfPendRequired	= 0x2000000,
        CbsSessionOptionAnalyzeComponentStore	= 0x8000000,
        CbsSessionOptionCancelOnlySmartPendedTransactions	= 0x80000000
    } 	_CbsSessionOption;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0007
    {
        CbsSessionEnhancedOptionManuallyRepair	= 0x800
    } 	_CbsSessionEnhancedOption;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0008
    {
        CbsSessionStateUnknown	= 0,
        CbsSessionStateReady	= 16,
        CbsSessionStateQueued	= 32,
        CbsSessionStateStarted	= 48,
        CbsSessionStatePanned	= 64,
        CbsSessionStateResolved	= 80,
        CbsSessionStateStaged	= 96,
        CbsSessionStateExecutionDelayed	= 101,
        CbsSessionStateInstalled	= 112,
        CbsSessionStateShutdownStart	= 144,
        CbsSessionStateShutdownFinish	= 160,
        CbsSessionStateStartup	= 176,
        CbsSessionStateStartupFinish	= 192,
        CbsSessionStateComplete	= 208,
        CbsSessionStateInterrupted	= 224,
        CbsSessionStateCorrupted	= 240,
        CbsSessionStateMarkedForRetry	= 256
    } 	_CbsSessionState;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0009
    {
        CbsOperationTypeNone	= 0,
        CbsOperationTypeExportRepository	= 1,
        CbsOperationTypeUpdateImage	= 2,
        CbsOperationTypePerformPrepareServicingOperation	= 3,
        CbsOperationTypePerformLateAcquisitionOperation	= 4,
        CbsOperationTypeInitICSIStore	= 8
    } 	_CbsOperationType;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0010
    {
        CbsSessionConfigurablePropertyInvalid	= 0
    } 	_CbsSessionConfigurableProperty;

typedef /* [public][public][public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0011
    {
        CbsApplicabilityInvalidValue	= -1,
        CbsApplicabilityNotApplicable	= 0,
        CbsApplicabilityNeedsParent	= 2,
        CbsApplicabilityApplicable	= 4
    } 	_CbsApplicability;

typedef /* [public][public][public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0012
    {
        CbsSelectabilityInvalidValue	= -1,
        CbsSelectabilityAllClass	= 0,
        CbsSelectabilityFixedClass	= 1,
        CbsSelectabilityRootClass	= 2
    } 	_CbsSelectability;

typedef /* [public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0013
    {
        CbsInstallStatePartiallyInstalled	= -19,
        CbsInstallStateCancel	= -18,
        CbsInstallStateSuperseded	= -17,
        CbsInstallStateDefault	= -16,
        CbsInvalidStatePermanent	= -8,
        CbsInvalidStateInstalled	= -7,
        CbsInvalidStateStaged	= -4,
        CbsInvalidStateResolved	= -2,
        CbsInstallStateUnknown	= -1,
        CbsInstallStateAbsent	= 0,
        CbsInstallStateResolving	= 1,
        CbsInstallStateResolved	= 2,
        CbsInstallStateStaging	= 3,
        CbsInstallStateStaged	= 4,
        CbsInstallStateUninstallRequested	= 5,
        CbsInstallStateInstallRequested	= 6,
        CbsInstallStateInstalled	= 7,
        CbsInstallStatePermanent	= 8,
        CbsInstallStateInvalid	= 0x7fffffff
    } 	_CbsInstallState;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0014
    {
        CbsPackagePropertyIdentityString	= 1,
        CbsPackagePropertyDisplayName	= 2,
        CbsPackagePropertyDescription	= 3,
        CbsPackagePropertyRestart	= 4,
        CbsPackagePropertyPsfName	= 5,
        CbsPackagePropertyHidden	= 6,
        CbsPackagePropertyKeyword	= 7,
        CbsPackagePropertyReleaseType	= 8,
        CbsPackagePropertyProductName	= 9,
        CbsPackagePropertyProductVersion	= 10,
        CbsPackagePropertyPermenence	= 11,
        CbsPackagePropertyCompany	= 12,
        CbsPackagePropertyCopyright	= 13,
        CbsPackagePropertySupportInformation	= 14,
        CbsPackagePropertyCreationTimeStamp	= 15,
        CbsPackagePropertyLastUpdateTimeStamp	= 16,
        CbsPackagePropertyInstallTimeStamp	= 17,
        CbsPackagePropertyInstallPackageName	= 18,
        CbsPackagePropertyInstallLocation	= 19,
        CbsPackagePropertyInstallClient	= 20,
        CbsPackagePropertyInstallUserName	= 21,
        CbsPackagePropertyExtendedError	= 22,
        CbsPackagePropertyPended	= 23,
        CbsPackagePropertyHotpatch	= 24,
        CbsPackagePropertyExclusive	= 25,
        CbsPackagePropertyAllowedOffline	= 26,
        CbsPackagePropertyCompletelyOfflineCapable	= 27,
        CbsPackagePropertyScavengeSequence	= 28,
        CbsPackagePropertyPackageSize	= 29,
        CbsPackagePropertySupersededTime	= 30,
        CbsPackagePropertyStackUpdate	= 31,
        CbsPackagePropertyReleaseQuality	= 32,
        CbsPackagePropertyTargetPartition	= 33,
        CbsPackagePropertyBinaryPartition	= 34,
        CbsPackagePropertyCapabilityIdentity	= 35,
        CbsPackagePropertyInternalStagingSizeWithExternalStorage	= 36,
        CbsPackagePropertyInternalStagingSizeWithoutExternalStorage	= 37,
        CbsPackagePropertyInstallSizeWithExternalStorage	= 38,
        CbsPackagePropertyInstallSizeWithoutExternalStorage	= 39,
        CbsPackagePropertyExternalStagingSize	= 40,
        CbsPackagePropertyFeatureFMID	= 41,
        CbsPackagePropertyFeatureGroup	= 42,
        CbsPackagePropertyPermanentUntilReset	= 43,
        CbsPackagePropertySatelliteType	= 44,
        CbsPackagePropertyDeclareSatelliteLanguage	= 45,
        CbsPackagePropertyDeclareSatelliteArch	= 46,
        CbsPackagePropertyRequiresPriorReboot	= 47,
        CbsPackagePropertyRemoveOnReset	= 51
    } 	_CbsPackageProperty;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0015
    {
        CbsResourceTypeInvalid	= 0
    } 	_CbsResourceType;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0016
    {
        CbsCardinalityNone	= 0
    } 	_CbsCardinality;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0017
    {
        CbsUpdatePropertyName	= 1,
        CbsUpdatePropertyDisplayName	= 2,
        CbsUpdatePropertyDescription	= 3,
        CbsUpdatePropertyDisplayFile	= 4,
        CbsUpdatePropertyRestart	= 5,
        CbsUpdatePropertyPsfName	= 6,
        CbsUpdatePropertyDownloadSize	= 7,
        CbsUpdatePropertySetMembership	= 8
    } 	_CbsUpdateProperty;

typedef /* [public][public] */ struct __MIDL___MIDL_itf_CbsApi_0000_0000_0018
    {
    int Data1;
    int Data2;
    } 	tagCbsPackageDecryptionData;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0019
    {
        CbsPackageEncryptionEnumNone	= 0
    } 	tagCbsPackageEncryptionEnum;

typedef /* [public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0020
    {
        CbsDeferChange	= ( 1 << 14 ) ,
        CbsTreatPackageAsPSFX	= ( 1 << 15 ) 
    } 	_CbsPackageChangeOption;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0021
    {
        CbsOperationStageWaiting	= 1,
        CbsOperationStagePlanning	= 5,
        CbsOperationStageDownloading	= 15,
        CbsOperationStageExtracting	= 20,
        CbsOperationStageResolving	= 25,
        CbsOperationStageStaging	= 30,
        CbsOperationStageInstalling	= 40,
        CbsOperationStageInstallingEx	= 50,
        CbsOperationStageReservicingLCU	= 60
    } 	_CbsOperationStage;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_CbsApi_0000_0000_0022
    {
        CbsOnDemandSourceEnumAllowCloud	= 0x4,
        CbsOnDemandSourceEnumTreatLocalSourceAsUUPRepo	= 0x22,
        CbsOnDemandSourceEnumReserveUnavailableFOD	= 0x26,
        CbsOnDemandSourceLanguagePack	= 0x40,
        CbsOnDemandSourceActionList	= 0x10,
        CbsOnDemandSourceWindowsUpdate	= 0x100,
        CbsOnDemandSourceRemovedMarkers	= 0x1000
    } 	_CbsCapabilitySourceFilter;










extern RPC_IF_HANDLE __MIDL_itf_CbsApi_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_CbsApi_0000_0000_v0_0_s_ifspec;

/* interface __MIDL_itf_CbsApi_0000_0001 */
/* [local] */ 









extern RPC_IF_HANDLE __MIDL_itf_CbsApi_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_CbsApi_0000_0001_v0_0_s_ifspec;

#ifndef __ICbsIdentity_INTERFACE_DEFINED__
#define __ICbsIdentity_INTERFACE_DEFINED__

/* interface ICbsIdentity */
/* [object][uuid] */ 


EXTERN_C const IID IID_ICbsIdentity;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("75207396-23F2-4396-85F0-8FDB879ED0ED")
    ICbsIdentity : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsNull( 
            /* [retval][out] */ BOOL *pbIsNull) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsEqual( 
            /* [in] */ ICbsIdentity *pIdentComp,
            /* [retval][out] */ BOOL *pbIsEqual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFromAttributes( 
            /* [string][in] */ LPCTSTR szName,
            /* [string][in] */ LPCTSTR szPublicKeyToken,
            /* [string][in] */ LPCTSTR szProcessor,
            /* [string][in] */ LPCTSTR szLanguage,
            /* [string][in] */ LPCTSTR szVersion) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFromStringId( 
            /* [string][in] */ LPCTSTR szID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStringId( 
            /* [retval][out] */ LPTSTR *pszID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveAsStringId( 
            /* [retval][out] */ LPTSTR *pszID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InternalIsEqualbyAttribute( 
            /* [string][in] */ LPCTSTR szName,
            /* [string][in] */ LPCTSTR szPublicKeyToken,
            /* [string][in] */ LPCTSTR szProcessor,
            /* [string][in] */ LPCTSTR szLanguage,
            /* [string][in] */ LPCTSTR szVersion,
            /* [retval][out] */ BOOL *pbIsEqual) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICbsIdentityVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICbsIdentity * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICbsIdentity * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICbsIdentity * This);
        
        DECLSPEC_XFGVIRT(ICbsIdentity, Clear)
        HRESULT ( STDMETHODCALLTYPE *Clear )( 
            ICbsIdentity * This);
        
        DECLSPEC_XFGVIRT(ICbsIdentity, IsNull)
        HRESULT ( STDMETHODCALLTYPE *IsNull )( 
            ICbsIdentity * This,
            /* [retval][out] */ BOOL *pbIsNull);
        
        DECLSPEC_XFGVIRT(ICbsIdentity, IsEqual)
        HRESULT ( STDMETHODCALLTYPE *IsEqual )( 
            ICbsIdentity * This,
            /* [in] */ ICbsIdentity *pIdentComp,
            /* [retval][out] */ BOOL *pbIsEqual);
        
        DECLSPEC_XFGVIRT(ICbsIdentity, LoadFromAttributes)
        HRESULT ( STDMETHODCALLTYPE *LoadFromAttributes )( 
            ICbsIdentity * This,
            /* [string][in] */ LPCTSTR szName,
            /* [string][in] */ LPCTSTR szPublicKeyToken,
            /* [string][in] */ LPCTSTR szProcessor,
            /* [string][in] */ LPCTSTR szLanguage,
            /* [string][in] */ LPCTSTR szVersion);
        
        DECLSPEC_XFGVIRT(ICbsIdentity, LoadFromStringId)
        HRESULT ( STDMETHODCALLTYPE *LoadFromStringId )( 
            ICbsIdentity * This,
            /* [string][in] */ LPCTSTR szID);
        
        DECLSPEC_XFGVIRT(ICbsIdentity, GetStringId)
        HRESULT ( STDMETHODCALLTYPE *GetStringId )( 
            ICbsIdentity * This,
            /* [retval][out] */ LPTSTR *pszID);
        
        DECLSPEC_XFGVIRT(ICbsIdentity, SaveAsStringId)
        HRESULT ( STDMETHODCALLTYPE *SaveAsStringId )( 
            ICbsIdentity * This,
            /* [retval][out] */ LPTSTR *pszID);
        
        DECLSPEC_XFGVIRT(ICbsIdentity, InternalIsEqualbyAttribute)
        HRESULT ( STDMETHODCALLTYPE *InternalIsEqualbyAttribute )( 
            ICbsIdentity * This,
            /* [string][in] */ LPCTSTR szName,
            /* [string][in] */ LPCTSTR szPublicKeyToken,
            /* [string][in] */ LPCTSTR szProcessor,
            /* [string][in] */ LPCTSTR szLanguage,
            /* [string][in] */ LPCTSTR szVersion,
            /* [retval][out] */ BOOL *pbIsEqual);
        
        END_INTERFACE
    } ICbsIdentityVtbl;

    interface ICbsIdentity
    {
        CONST_VTBL struct ICbsIdentityVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICbsIdentity_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICbsIdentity_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICbsIdentity_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICbsIdentity_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define ICbsIdentity_IsNull(This,pbIsNull)	\
    ( (This)->lpVtbl -> IsNull(This,pbIsNull) ) 

#define ICbsIdentity_IsEqual(This,pIdentComp,pbIsEqual)	\
    ( (This)->lpVtbl -> IsEqual(This,pIdentComp,pbIsEqual) ) 

#define ICbsIdentity_LoadFromAttributes(This,szName,szPublicKeyToken,szProcessor,szLanguage,szVersion)	\
    ( (This)->lpVtbl -> LoadFromAttributes(This,szName,szPublicKeyToken,szProcessor,szLanguage,szVersion) ) 

#define ICbsIdentity_LoadFromStringId(This,szID)	\
    ( (This)->lpVtbl -> LoadFromStringId(This,szID) ) 

#define ICbsIdentity_GetStringId(This,pszID)	\
    ( (This)->lpVtbl -> GetStringId(This,pszID) ) 

#define ICbsIdentity_SaveAsStringId(This,pszID)	\
    ( (This)->lpVtbl -> SaveAsStringId(This,pszID) ) 

#define ICbsIdentity_InternalIsEqualbyAttribute(This,szName,szPublicKeyToken,szProcessor,szLanguage,szVersion,pbIsEqual)	\
    ( (This)->lpVtbl -> InternalIsEqualbyAttribute(This,szName,szPublicKeyToken,szProcessor,szLanguage,szVersion,pbIsEqual) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICbsIdentity_INTERFACE_DEFINED__ */


#ifndef __ICbsFeaturePackage_INTERFACE_DEFINED__
#define __ICbsFeaturePackage_INTERFACE_DEFINED__

/* interface ICbsFeaturePackage */
/* [object][uuid] */ 


EXTERN_C const IID IID_ICbsFeaturePackage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B531E34E-A150-4B01-8D77-858E2F6CFE75")
    ICbsFeaturePackage : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ICbsFeaturePackageVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICbsFeaturePackage * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICbsFeaturePackage * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICbsFeaturePackage * This);
        
        END_INTERFACE
    } ICbsFeaturePackageVtbl;

    interface ICbsFeaturePackage
    {
        CONST_VTBL struct ICbsFeaturePackageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICbsFeaturePackage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICbsFeaturePackage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICbsFeaturePackage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICbsFeaturePackage_INTERFACE_DEFINED__ */


#ifndef __ICbsPackage_INTERFACE_DEFINED__
#define __ICbsPackage_INTERFACE_DEFINED__

/* interface ICbsPackage */
/* [object][uuid] */ 


EXTERN_C const IID IID_ICbsPackage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("75207393-23F2-4396-85F0-8FDB879ED0ED")
    ICbsPackage : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetIdentity( 
            /* [retval][out] */ ICbsIdentity **pIdentity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ _CbsPackageProperty prop,
            /* [retval][out] */ LPTSTR *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumerateUpdates( 
            /* [in] */ _CbsApplicability pApplicability,
            /* [in] */ _CbsSelectability pSelectability,
            /* [retval][out] */ IEnumCbsUpdate **ppUpdateList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUpdate( 
            /* [string][in] */ LPCTSTR szUpdName,
            /* [retval][out] */ ICbsUpdate **ppUpdate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddSource( 
            /* [string][in] */ LPCTSTR basePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveSource( 
            /* [string][in] */ LPCTSTR basePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumerateSources( 
            /* [retval][out] */ IEnumString **pSourceList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EvaluateApplicability( 
            UINT option,
            /* [out] */ _CbsInstallState *pApplicabilityState,
            /* [out] */ _CbsInstallState *pCurrentState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitiateChanges( 
            /* [in] */ UINT installOptions,
            /* [in] */ _CbsInstallState targetState,
            /* [in] */ ICbsUIHandler *pUIHandler) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Status( 
            /* [out] */ _CbsInstallState *pProgressState,
            /* [out] */ DWORD *pLastError) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResourcesToCheck( 
            /* [in] */ _CbsResourceType resType,
            /* [retval][out] */ IEnumString **pResList) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICbsPackageVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICbsPackage * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICbsPackage * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICbsPackage * This);
        
        DECLSPEC_XFGVIRT(ICbsPackage, GetIdentity)
        HRESULT ( STDMETHODCALLTYPE *GetIdentity )( 
            ICbsPackage * This,
            /* [retval][out] */ ICbsIdentity **pIdentity);
        
        DECLSPEC_XFGVIRT(ICbsPackage, GetProperty)
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            ICbsPackage * This,
            /* [in] */ _CbsPackageProperty prop,
            /* [retval][out] */ LPTSTR *pValue);
        
        DECLSPEC_XFGVIRT(ICbsPackage, EnumerateUpdates)
        HRESULT ( STDMETHODCALLTYPE *EnumerateUpdates )( 
            ICbsPackage * This,
            /* [in] */ _CbsApplicability pApplicability,
            /* [in] */ _CbsSelectability pSelectability,
            /* [retval][out] */ IEnumCbsUpdate **ppUpdateList);
        
        DECLSPEC_XFGVIRT(ICbsPackage, GetUpdate)
        HRESULT ( STDMETHODCALLTYPE *GetUpdate )( 
            ICbsPackage * This,
            /* [string][in] */ LPCTSTR szUpdName,
            /* [retval][out] */ ICbsUpdate **ppUpdate);
        
        DECLSPEC_XFGVIRT(ICbsPackage, AddSource)
        HRESULT ( STDMETHODCALLTYPE *AddSource )( 
            ICbsPackage * This,
            /* [string][in] */ LPCTSTR basePath);
        
        DECLSPEC_XFGVIRT(ICbsPackage, RemoveSource)
        HRESULT ( STDMETHODCALLTYPE *RemoveSource )( 
            ICbsPackage * This,
            /* [string][in] */ LPCTSTR basePath);
        
        DECLSPEC_XFGVIRT(ICbsPackage, EnumerateSources)
        HRESULT ( STDMETHODCALLTYPE *EnumerateSources )( 
            ICbsPackage * This,
            /* [retval][out] */ IEnumString **pSourceList);
        
        DECLSPEC_XFGVIRT(ICbsPackage, EvaluateApplicability)
        HRESULT ( STDMETHODCALLTYPE *EvaluateApplicability )( 
            ICbsPackage * This,
            UINT option,
            /* [out] */ _CbsInstallState *pApplicabilityState,
            /* [out] */ _CbsInstallState *pCurrentState);
        
        DECLSPEC_XFGVIRT(ICbsPackage, InitiateChanges)
        HRESULT ( STDMETHODCALLTYPE *InitiateChanges )( 
            ICbsPackage * This,
            /* [in] */ UINT installOptions,
            /* [in] */ _CbsInstallState targetState,
            /* [in] */ ICbsUIHandler *pUIHandler);
        
        DECLSPEC_XFGVIRT(ICbsPackage, Status)
        HRESULT ( STDMETHODCALLTYPE *Status )( 
            ICbsPackage * This,
            /* [out] */ _CbsInstallState *pProgressState,
            /* [out] */ DWORD *pLastError);
        
        DECLSPEC_XFGVIRT(ICbsPackage, ResourcesToCheck)
        HRESULT ( STDMETHODCALLTYPE *ResourcesToCheck )( 
            ICbsPackage * This,
            /* [in] */ _CbsResourceType resType,
            /* [retval][out] */ IEnumString **pResList);
        
        END_INTERFACE
    } ICbsPackageVtbl;

    interface ICbsPackage
    {
        CONST_VTBL struct ICbsPackageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICbsPackage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICbsPackage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICbsPackage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICbsPackage_GetIdentity(This,pIdentity)	\
    ( (This)->lpVtbl -> GetIdentity(This,pIdentity) ) 

#define ICbsPackage_GetProperty(This,prop,pValue)	\
    ( (This)->lpVtbl -> GetProperty(This,prop,pValue) ) 

#define ICbsPackage_EnumerateUpdates(This,pApplicability,pSelectability,ppUpdateList)	\
    ( (This)->lpVtbl -> EnumerateUpdates(This,pApplicability,pSelectability,ppUpdateList) ) 

#define ICbsPackage_GetUpdate(This,szUpdName,ppUpdate)	\
    ( (This)->lpVtbl -> GetUpdate(This,szUpdName,ppUpdate) ) 

#define ICbsPackage_AddSource(This,basePath)	\
    ( (This)->lpVtbl -> AddSource(This,basePath) ) 

#define ICbsPackage_RemoveSource(This,basePath)	\
    ( (This)->lpVtbl -> RemoveSource(This,basePath) ) 

#define ICbsPackage_EnumerateSources(This,pSourceList)	\
    ( (This)->lpVtbl -> EnumerateSources(This,pSourceList) ) 

#define ICbsPackage_EvaluateApplicability(This,option,pApplicabilityState,pCurrentState)	\
    ( (This)->lpVtbl -> EvaluateApplicability(This,option,pApplicabilityState,pCurrentState) ) 

#define ICbsPackage_InitiateChanges(This,installOptions,targetState,pUIHandler)	\
    ( (This)->lpVtbl -> InitiateChanges(This,installOptions,targetState,pUIHandler) ) 

#define ICbsPackage_Status(This,pProgressState,pLastError)	\
    ( (This)->lpVtbl -> Status(This,pProgressState,pLastError) ) 

#define ICbsPackage_ResourcesToCheck(This,resType,pResList)	\
    ( (This)->lpVtbl -> ResourcesToCheck(This,resType,pResList) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICbsPackage_INTERFACE_DEFINED__ */


#ifndef __ICbsUpdate_INTERFACE_DEFINED__
#define __ICbsUpdate_INTERFACE_DEFINED__

/* interface ICbsUpdate */
/* [object][uuid] */ 


EXTERN_C const IID IID_ICbsUpdate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("75207394-23F2-4396-85F0-8FDB879ED0ED")
    ICbsUpdate : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ _CbsUpdateProperty prop,
            /* [retval][out] */ LPTSTR *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPackage( 
            /* [retval][out] */ ICbsPackage **ppPackage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParentUpdate( 
            /* [in] */ UINT index,
            /* [out] */ LPTSTR *ppParent,
            /* [out] */ LPTSTR *ppSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCapability( 
            /* [out] */ _CbsApplicability *pApplicability,
            /* [out] */ _CbsSelectability *pSelectability) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeclaredSet( 
            /* [in] */ UINT unk,
            /* [out] */ LPTSTR *pDeclaredSet,
            /* [out] */ _CbsCardinality *Cardinality) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInstallState( 
            /* [out] */ _CbsInstallState *pCurrentState,
            /* [out] */ _CbsInstallState *pIntendedState,
            /* [out] */ _CbsInstallState *pRequestState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInstallState( 
            /* [in] */ UINT options,
            /* [in] */ _CbsInstallState requestedState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRealInstallState( 
            /* [out] */ CbsState *pCurrentState,
            /* [out] */ CbsState *pIntendedState,
            /* [out] */ UpdateSelection *pRequestState) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICbsUpdateVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICbsUpdate * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICbsUpdate * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICbsUpdate * This);
        
        DECLSPEC_XFGVIRT(ICbsUpdate, GetProperty)
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            ICbsUpdate * This,
            /* [in] */ _CbsUpdateProperty prop,
            /* [retval][out] */ LPTSTR *pValue);
        
        DECLSPEC_XFGVIRT(ICbsUpdate, GetPackage)
        HRESULT ( STDMETHODCALLTYPE *GetPackage )( 
            ICbsUpdate * This,
            /* [retval][out] */ ICbsPackage **ppPackage);
        
        DECLSPEC_XFGVIRT(ICbsUpdate, GetParentUpdate)
        HRESULT ( STDMETHODCALLTYPE *GetParentUpdate )( 
            ICbsUpdate * This,
            /* [in] */ UINT index,
            /* [out] */ LPTSTR *ppParent,
            /* [out] */ LPTSTR *ppSet);
        
        DECLSPEC_XFGVIRT(ICbsUpdate, GetCapability)
        HRESULT ( STDMETHODCALLTYPE *GetCapability )( 
            ICbsUpdate * This,
            /* [out] */ _CbsApplicability *pApplicability,
            /* [out] */ _CbsSelectability *pSelectability);
        
        DECLSPEC_XFGVIRT(ICbsUpdate, GetDeclaredSet)
        HRESULT ( STDMETHODCALLTYPE *GetDeclaredSet )( 
            ICbsUpdate * This,
            /* [in] */ UINT unk,
            /* [out] */ LPTSTR *pDeclaredSet,
            /* [out] */ _CbsCardinality *Cardinality);
        
        DECLSPEC_XFGVIRT(ICbsUpdate, GetInstallState)
        HRESULT ( STDMETHODCALLTYPE *GetInstallState )( 
            ICbsUpdate * This,
            /* [out] */ _CbsInstallState *pCurrentState,
            /* [out] */ _CbsInstallState *pIntendedState,
            /* [out] */ _CbsInstallState *pRequestState);
        
        DECLSPEC_XFGVIRT(ICbsUpdate, SetInstallState)
        HRESULT ( STDMETHODCALLTYPE *SetInstallState )( 
            ICbsUpdate * This,
            /* [in] */ UINT options,
            /* [in] */ _CbsInstallState requestedState);
        
        DECLSPEC_XFGVIRT(ICbsUpdate, GetRealInstallState)
        HRESULT ( STDMETHODCALLTYPE *GetRealInstallState )( 
            ICbsUpdate * This,
            /* [out] */ CbsState *pCurrentState,
            /* [out] */ CbsState *pIntendedState,
            /* [out] */ UpdateSelection *pRequestState);
        
        END_INTERFACE
    } ICbsUpdateVtbl;

    interface ICbsUpdate
    {
        CONST_VTBL struct ICbsUpdateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICbsUpdate_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICbsUpdate_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICbsUpdate_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICbsUpdate_GetProperty(This,prop,pValue)	\
    ( (This)->lpVtbl -> GetProperty(This,prop,pValue) ) 

#define ICbsUpdate_GetPackage(This,ppPackage)	\
    ( (This)->lpVtbl -> GetPackage(This,ppPackage) ) 

#define ICbsUpdate_GetParentUpdate(This,index,ppParent,ppSet)	\
    ( (This)->lpVtbl -> GetParentUpdate(This,index,ppParent,ppSet) ) 

#define ICbsUpdate_GetCapability(This,pApplicability,pSelectability)	\
    ( (This)->lpVtbl -> GetCapability(This,pApplicability,pSelectability) ) 

#define ICbsUpdate_GetDeclaredSet(This,unk,pDeclaredSet,Cardinality)	\
    ( (This)->lpVtbl -> GetDeclaredSet(This,unk,pDeclaredSet,Cardinality) ) 

#define ICbsUpdate_GetInstallState(This,pCurrentState,pIntendedState,pRequestState)	\
    ( (This)->lpVtbl -> GetInstallState(This,pCurrentState,pIntendedState,pRequestState) ) 

#define ICbsUpdate_SetInstallState(This,options,requestedState)	\
    ( (This)->lpVtbl -> SetInstallState(This,options,requestedState) ) 

#define ICbsUpdate_GetRealInstallState(This,pCurrentState,pIntendedState,pRequestState)	\
    ( (This)->lpVtbl -> GetRealInstallState(This,pCurrentState,pIntendedState,pRequestState) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICbsUpdate_INTERFACE_DEFINED__ */


#ifndef __ICbsUIHandler_INTERFACE_DEFINED__
#define __ICbsUIHandler_INTERFACE_DEFINED__

/* interface ICbsUIHandler */
/* [object][uuid] */ 


EXTERN_C const IID IID_ICbsUIHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("75207392-23F2-4396-85F0-8FDB879ED0ED")
    ICbsUIHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initiate( 
            /* [in] */ IEnumCbsUpdate *pUpdList,
            /* [in] */ int *__MIDL__ICbsUIHandler0000) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Terminate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Error( 
            HRESULT hr,
            /* [string][in] */ LPCTSTR szUnk,
            /* [in] */ int *unkArg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResolveSource( 
            /* [in] */ LPCTSTR __MIDL__ICbsUIHandler0001,
            /* [in] */ ICbsIdentity *pIdent,
            /* [in] */ LPCTSTR __MIDL__ICbsUIHandler0002,
            /* [out][in] */ LPTSTR *__MIDL__ICbsUIHandler0003,
            /* [out] */ int *__MIDL__ICbsUIHandler0004) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Progress( 
            /* [in] */ _CbsInstallState stIns,
            /* [in] */ UINT curProg,
            /* [in] */ UINT totProg,
            /* [out] */ int *__MIDL__ICbsUIHandler0005) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnteringStage( 
            /* [in] */ UINT __MIDL__ICbsUIHandler0006,
            /* [in] */ _CbsOperationStage __MIDL__ICbsUIHandler0007,
            /* [in] */ int __MIDL__ICbsUIHandler0008,
            /* [in] */ int __MIDL__ICbsUIHandler0009) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProgressEx( 
            /* [in] */ _CbsInstallState stIns,
            /* [in] */ UINT curProg,
            /* [in] */ UINT totProg,
            /* [in] */ UINT __MIDL__ICbsUIHandler0010,
            /* [out] */ int *__MIDL__ICbsUIHandler0011) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICbsUIHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICbsUIHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICbsUIHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICbsUIHandler * This);
        
        DECLSPEC_XFGVIRT(ICbsUIHandler, Initiate)
        HRESULT ( STDMETHODCALLTYPE *Initiate )( 
            ICbsUIHandler * This,
            /* [in] */ IEnumCbsUpdate *pUpdList,
            /* [in] */ int *__MIDL__ICbsUIHandler0000);
        
        DECLSPEC_XFGVIRT(ICbsUIHandler, Terminate)
        HRESULT ( STDMETHODCALLTYPE *Terminate )( 
            ICbsUIHandler * This);
        
        DECLSPEC_XFGVIRT(ICbsUIHandler, Error)
        HRESULT ( STDMETHODCALLTYPE *Error )( 
            ICbsUIHandler * This,
            HRESULT hr,
            /* [string][in] */ LPCTSTR szUnk,
            /* [in] */ int *unkArg);
        
        DECLSPEC_XFGVIRT(ICbsUIHandler, ResolveSource)
        HRESULT ( STDMETHODCALLTYPE *ResolveSource )( 
            ICbsUIHandler * This,
            /* [in] */ LPCTSTR __MIDL__ICbsUIHandler0001,
            /* [in] */ ICbsIdentity *pIdent,
            /* [in] */ LPCTSTR __MIDL__ICbsUIHandler0002,
            /* [out][in] */ LPTSTR *__MIDL__ICbsUIHandler0003,
            /* [out] */ int *__MIDL__ICbsUIHandler0004);
        
        DECLSPEC_XFGVIRT(ICbsUIHandler, Progress)
        HRESULT ( STDMETHODCALLTYPE *Progress )( 
            ICbsUIHandler * This,
            /* [in] */ _CbsInstallState stIns,
            /* [in] */ UINT curProg,
            /* [in] */ UINT totProg,
            /* [out] */ int *__MIDL__ICbsUIHandler0005);
        
        DECLSPEC_XFGVIRT(ICbsUIHandler, EnteringStage)
        HRESULT ( STDMETHODCALLTYPE *EnteringStage )( 
            ICbsUIHandler * This,
            /* [in] */ UINT __MIDL__ICbsUIHandler0006,
            /* [in] */ _CbsOperationStage __MIDL__ICbsUIHandler0007,
            /* [in] */ int __MIDL__ICbsUIHandler0008,
            /* [in] */ int __MIDL__ICbsUIHandler0009);
        
        DECLSPEC_XFGVIRT(ICbsUIHandler, ProgressEx)
        HRESULT ( STDMETHODCALLTYPE *ProgressEx )( 
            ICbsUIHandler * This,
            /* [in] */ _CbsInstallState stIns,
            /* [in] */ UINT curProg,
            /* [in] */ UINT totProg,
            /* [in] */ UINT __MIDL__ICbsUIHandler0010,
            /* [out] */ int *__MIDL__ICbsUIHandler0011);
        
        END_INTERFACE
    } ICbsUIHandlerVtbl;

    interface ICbsUIHandler
    {
        CONST_VTBL struct ICbsUIHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICbsUIHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICbsUIHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICbsUIHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICbsUIHandler_Initiate(This,pUpdList,__MIDL__ICbsUIHandler0000)	\
    ( (This)->lpVtbl -> Initiate(This,pUpdList,__MIDL__ICbsUIHandler0000) ) 

#define ICbsUIHandler_Terminate(This)	\
    ( (This)->lpVtbl -> Terminate(This) ) 

#define ICbsUIHandler_Error(This,hr,szUnk,unkArg)	\
    ( (This)->lpVtbl -> Error(This,hr,szUnk,unkArg) ) 

#define ICbsUIHandler_ResolveSource(This,__MIDL__ICbsUIHandler0001,pIdent,__MIDL__ICbsUIHandler0002,__MIDL__ICbsUIHandler0003,__MIDL__ICbsUIHandler0004)	\
    ( (This)->lpVtbl -> ResolveSource(This,__MIDL__ICbsUIHandler0001,pIdent,__MIDL__ICbsUIHandler0002,__MIDL__ICbsUIHandler0003,__MIDL__ICbsUIHandler0004) ) 

#define ICbsUIHandler_Progress(This,stIns,curProg,totProg,__MIDL__ICbsUIHandler0005)	\
    ( (This)->lpVtbl -> Progress(This,stIns,curProg,totProg,__MIDL__ICbsUIHandler0005) ) 

#define ICbsUIHandler_EnteringStage(This,__MIDL__ICbsUIHandler0006,__MIDL__ICbsUIHandler0007,__MIDL__ICbsUIHandler0008,__MIDL__ICbsUIHandler0009)	\
    ( (This)->lpVtbl -> EnteringStage(This,__MIDL__ICbsUIHandler0006,__MIDL__ICbsUIHandler0007,__MIDL__ICbsUIHandler0008,__MIDL__ICbsUIHandler0009) ) 

#define ICbsUIHandler_ProgressEx(This,stIns,curProg,totProg,__MIDL__ICbsUIHandler0010,__MIDL__ICbsUIHandler0011)	\
    ( (This)->lpVtbl -> ProgressEx(This,stIns,curProg,totProg,__MIDL__ICbsUIHandler0010,__MIDL__ICbsUIHandler0011) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICbsUIHandler_INTERFACE_DEFINED__ */


#ifndef __ICbsCapability_INTERFACE_DEFINED__
#define __ICbsCapability_INTERFACE_DEFINED__

/* interface ICbsCapability */
/* [object][uuid] */ 


EXTERN_C const IID IID_ICbsCapability;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9EEAE39F-E52B-4F18-9C14-F827BB3BAF0F")
    ICbsCapability : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetIdentity( 
            /* [retval][out] */ ICbsIdentity **pIdent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ _CbsPackageProperty __MIDL__ICbsCapability0000,
            /* [retval][out] */ LPTSTR *__MIDL__ICbsCapability0001) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumerateUpdates( 
            /* [in] */ _CbsApplicability pApplicability,
            /* [in] */ _CbsSelectability pSelectability,
            /* [retval][out] */ IEnumCbsUpdate **ppUpdateList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUpdate( 
            /* [string][in] */ LPCTSTR szUpdName,
            /* [retval][out] */ ICbsUpdate **ppUpdate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddSource( 
            /* [string][in] */ LPCTSTR basePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveSource( 
            /* [string][in] */ LPCTSTR basePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumerateSources( 
            /* [retval][out] */ IEnumString **pSourceList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EvaluateApplicability( 
            /* [in] */ UINT option,
            /* [out] */ _CbsInstallState *pApplicabilityState,
            /* [out] */ _CbsInstallState *pCurrentState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitiateChanges( 
            /* [in] */ UINT installOptions,
            /* [in] */ _CbsInstallState targetState,
            /* [in] */ ICbsUIHandler *pUIHandler) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Status( 
            /* [out] */ _CbsInstallState *pProgressState,
            /* [out] */ DWORD *pLastError) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResourcesToCheck( 
            /* [in] */ _CbsResourceType resType,
            /* [retval][out] */ IEnumString **pResList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCapability( 
            /* [out] */ LPTSTR *pszNamespace,
            /* [out] */ LPTSTR *pszLang,
            /* [out] */ LPTSTR *pszArch,
            /* [out] */ ULONG *dwVerMajor,
            /* [out] */ ULONG *dwVerMinor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDependencies( 
            /* [retval][out] */ IEnumCbsCapability **pDependenciesList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSources( 
            /* [out] */ UINT *__MIDL__ICbsCapability0002) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDownloadSize( 
            /* [retval][out] */ ULONG *nBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInstallSize( 
            /* [retval][out] */ ULONG *nBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInstallState( 
            /* [retval][out] */ _CbsInstallState *pState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOwnerInformation( 
            /* [in] */ UINT reserved,
            /* [out] */ int *__MIDL__ICbsCapability0003,
            /* [out] */ UINT *__MIDL__ICbsCapability0004,
            /* [out] */ LPTSTR *__MIDL__ICbsCapability0005) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumerateFeaturePackages( 
            /* [retval][out] */ IEnumCbsFeaturePackage **ppFeaturePkgList) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICbsCapabilityVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICbsCapability * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICbsCapability * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICbsCapability * This);
        
        DECLSPEC_XFGVIRT(ICbsCapability, GetIdentity)
        HRESULT ( STDMETHODCALLTYPE *GetIdentity )( 
            ICbsCapability * This,
            /* [retval][out] */ ICbsIdentity **pIdent);
        
        DECLSPEC_XFGVIRT(ICbsCapability, GetProperty)
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            ICbsCapability * This,
            /* [in] */ _CbsPackageProperty __MIDL__ICbsCapability0000,
            /* [retval][out] */ LPTSTR *__MIDL__ICbsCapability0001);
        
        DECLSPEC_XFGVIRT(ICbsCapability, EnumerateUpdates)
        HRESULT ( STDMETHODCALLTYPE *EnumerateUpdates )( 
            ICbsCapability * This,
            /* [in] */ _CbsApplicability pApplicability,
            /* [in] */ _CbsSelectability pSelectability,
            /* [retval][out] */ IEnumCbsUpdate **ppUpdateList);
        
        DECLSPEC_XFGVIRT(ICbsCapability, GetUpdate)
        HRESULT ( STDMETHODCALLTYPE *GetUpdate )( 
            ICbsCapability * This,
            /* [string][in] */ LPCTSTR szUpdName,
            /* [retval][out] */ ICbsUpdate **ppUpdate);
        
        DECLSPEC_XFGVIRT(ICbsCapability, AddSource)
        HRESULT ( STDMETHODCALLTYPE *AddSource )( 
            ICbsCapability * This,
            /* [string][in] */ LPCTSTR basePath);
        
        DECLSPEC_XFGVIRT(ICbsCapability, RemoveSource)
        HRESULT ( STDMETHODCALLTYPE *RemoveSource )( 
            ICbsCapability * This,
            /* [string][in] */ LPCTSTR basePath);
        
        DECLSPEC_XFGVIRT(ICbsCapability, EnumerateSources)
        HRESULT ( STDMETHODCALLTYPE *EnumerateSources )( 
            ICbsCapability * This,
            /* [retval][out] */ IEnumString **pSourceList);
        
        DECLSPEC_XFGVIRT(ICbsCapability, EvaluateApplicability)
        HRESULT ( STDMETHODCALLTYPE *EvaluateApplicability )( 
            ICbsCapability * This,
            /* [in] */ UINT option,
            /* [out] */ _CbsInstallState *pApplicabilityState,
            /* [out] */ _CbsInstallState *pCurrentState);
        
        DECLSPEC_XFGVIRT(ICbsCapability, InitiateChanges)
        HRESULT ( STDMETHODCALLTYPE *InitiateChanges )( 
            ICbsCapability * This,
            /* [in] */ UINT installOptions,
            /* [in] */ _CbsInstallState targetState,
            /* [in] */ ICbsUIHandler *pUIHandler);
        
        DECLSPEC_XFGVIRT(ICbsCapability, Status)
        HRESULT ( STDMETHODCALLTYPE *Status )( 
            ICbsCapability * This,
            /* [out] */ _CbsInstallState *pProgressState,
            /* [out] */ DWORD *pLastError);
        
        DECLSPEC_XFGVIRT(ICbsCapability, ResourcesToCheck)
        HRESULT ( STDMETHODCALLTYPE *ResourcesToCheck )( 
            ICbsCapability * This,
            /* [in] */ _CbsResourceType resType,
            /* [retval][out] */ IEnumString **pResList);
        
        DECLSPEC_XFGVIRT(ICbsCapability, GetCapability)
        HRESULT ( STDMETHODCALLTYPE *GetCapability )( 
            ICbsCapability * This,
            /* [out] */ LPTSTR *pszNamespace,
            /* [out] */ LPTSTR *pszLang,
            /* [out] */ LPTSTR *pszArch,
            /* [out] */ ULONG *dwVerMajor,
            /* [out] */ ULONG *dwVerMinor);
        
        DECLSPEC_XFGVIRT(ICbsCapability, GetDependencies)
        HRESULT ( STDMETHODCALLTYPE *GetDependencies )( 
            ICbsCapability * This,
            /* [retval][out] */ IEnumCbsCapability **pDependenciesList);
        
        DECLSPEC_XFGVIRT(ICbsCapability, GetSources)
        HRESULT ( STDMETHODCALLTYPE *GetSources )( 
            ICbsCapability * This,
            /* [out] */ UINT *__MIDL__ICbsCapability0002);
        
        DECLSPEC_XFGVIRT(ICbsCapability, GetDownloadSize)
        HRESULT ( STDMETHODCALLTYPE *GetDownloadSize )( 
            ICbsCapability * This,
            /* [retval][out] */ ULONG *nBytes);
        
        DECLSPEC_XFGVIRT(ICbsCapability, GetInstallSize)
        HRESULT ( STDMETHODCALLTYPE *GetInstallSize )( 
            ICbsCapability * This,
            /* [retval][out] */ ULONG *nBytes);
        
        DECLSPEC_XFGVIRT(ICbsCapability, GetInstallState)
        HRESULT ( STDMETHODCALLTYPE *GetInstallState )( 
            ICbsCapability * This,
            /* [retval][out] */ _CbsInstallState *pState);
        
        DECLSPEC_XFGVIRT(ICbsCapability, GetOwnerInformation)
        HRESULT ( STDMETHODCALLTYPE *GetOwnerInformation )( 
            ICbsCapability * This,
            /* [in] */ UINT reserved,
            /* [out] */ int *__MIDL__ICbsCapability0003,
            /* [out] */ UINT *__MIDL__ICbsCapability0004,
            /* [out] */ LPTSTR *__MIDL__ICbsCapability0005);
        
        DECLSPEC_XFGVIRT(ICbsCapability, EnumerateFeaturePackages)
        HRESULT ( STDMETHODCALLTYPE *EnumerateFeaturePackages )( 
            ICbsCapability * This,
            /* [retval][out] */ IEnumCbsFeaturePackage **ppFeaturePkgList);
        
        END_INTERFACE
    } ICbsCapabilityVtbl;

    interface ICbsCapability
    {
        CONST_VTBL struct ICbsCapabilityVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICbsCapability_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICbsCapability_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICbsCapability_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICbsCapability_GetIdentity(This,pIdent)	\
    ( (This)->lpVtbl -> GetIdentity(This,pIdent) ) 

#define ICbsCapability_GetProperty(This,__MIDL__ICbsCapability0000,__MIDL__ICbsCapability0001)	\
    ( (This)->lpVtbl -> GetProperty(This,__MIDL__ICbsCapability0000,__MIDL__ICbsCapability0001) ) 

#define ICbsCapability_EnumerateUpdates(This,pApplicability,pSelectability,ppUpdateList)	\
    ( (This)->lpVtbl -> EnumerateUpdates(This,pApplicability,pSelectability,ppUpdateList) ) 

#define ICbsCapability_GetUpdate(This,szUpdName,ppUpdate)	\
    ( (This)->lpVtbl -> GetUpdate(This,szUpdName,ppUpdate) ) 

#define ICbsCapability_AddSource(This,basePath)	\
    ( (This)->lpVtbl -> AddSource(This,basePath) ) 

#define ICbsCapability_RemoveSource(This,basePath)	\
    ( (This)->lpVtbl -> RemoveSource(This,basePath) ) 

#define ICbsCapability_EnumerateSources(This,pSourceList)	\
    ( (This)->lpVtbl -> EnumerateSources(This,pSourceList) ) 

#define ICbsCapability_EvaluateApplicability(This,option,pApplicabilityState,pCurrentState)	\
    ( (This)->lpVtbl -> EvaluateApplicability(This,option,pApplicabilityState,pCurrentState) ) 

#define ICbsCapability_InitiateChanges(This,installOptions,targetState,pUIHandler)	\
    ( (This)->lpVtbl -> InitiateChanges(This,installOptions,targetState,pUIHandler) ) 

#define ICbsCapability_Status(This,pProgressState,pLastError)	\
    ( (This)->lpVtbl -> Status(This,pProgressState,pLastError) ) 

#define ICbsCapability_ResourcesToCheck(This,resType,pResList)	\
    ( (This)->lpVtbl -> ResourcesToCheck(This,resType,pResList) ) 

#define ICbsCapability_GetCapability(This,pszNamespace,pszLang,pszArch,dwVerMajor,dwVerMinor)	\
    ( (This)->lpVtbl -> GetCapability(This,pszNamespace,pszLang,pszArch,dwVerMajor,dwVerMinor) ) 

#define ICbsCapability_GetDependencies(This,pDependenciesList)	\
    ( (This)->lpVtbl -> GetDependencies(This,pDependenciesList) ) 

#define ICbsCapability_GetSources(This,__MIDL__ICbsCapability0002)	\
    ( (This)->lpVtbl -> GetSources(This,__MIDL__ICbsCapability0002) ) 

#define ICbsCapability_GetDownloadSize(This,nBytes)	\
    ( (This)->lpVtbl -> GetDownloadSize(This,nBytes) ) 

#define ICbsCapability_GetInstallSize(This,nBytes)	\
    ( (This)->lpVtbl -> GetInstallSize(This,nBytes) ) 

#define ICbsCapability_GetInstallState(This,pState)	\
    ( (This)->lpVtbl -> GetInstallState(This,pState) ) 

#define ICbsCapability_GetOwnerInformation(This,reserved,__MIDL__ICbsCapability0003,__MIDL__ICbsCapability0004,__MIDL__ICbsCapability0005)	\
    ( (This)->lpVtbl -> GetOwnerInformation(This,reserved,__MIDL__ICbsCapability0003,__MIDL__ICbsCapability0004,__MIDL__ICbsCapability0005) ) 

#define ICbsCapability_EnumerateFeaturePackages(This,ppFeaturePkgList)	\
    ( (This)->lpVtbl -> EnumerateFeaturePackages(This,ppFeaturePkgList) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICbsCapability_INTERFACE_DEFINED__ */


#ifndef __IEnumCbsIdentity_INTERFACE_DEFINED__
#define __IEnumCbsIdentity_INTERFACE_DEFINED__

/* interface IEnumCbsIdentity */
/* [object][uuid] */ 


EXTERN_C const IID IID_IEnumCbsIdentity;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("75207397-23F2-4396-85F0-8FDB879ED0ED")
    IEnumCbsIdentity : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ ICbsIdentity **rgpCol,
            /* [out] */ ULONG *pbFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumCbsIdentity **__MIDL__IEnumCbsIdentity0000) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumCbsIdentityVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumCbsIdentity * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumCbsIdentity * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumCbsIdentity * This);
        
        DECLSPEC_XFGVIRT(IEnumCbsIdentity, Next)
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumCbsIdentity * This,
            /* [in] */ ULONG celt,
            /* [out] */ ICbsIdentity **rgpCol,
            /* [out] */ ULONG *pbFetched);
        
        DECLSPEC_XFGVIRT(IEnumCbsIdentity, Skip)
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumCbsIdentity * This,
            /* [in] */ ULONG celt);
        
        DECLSPEC_XFGVIRT(IEnumCbsIdentity, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumCbsIdentity * This);
        
        DECLSPEC_XFGVIRT(IEnumCbsIdentity, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumCbsIdentity * This,
            /* [out] */ IEnumCbsIdentity **__MIDL__IEnumCbsIdentity0000);
        
        END_INTERFACE
    } IEnumCbsIdentityVtbl;

    interface IEnumCbsIdentity
    {
        CONST_VTBL struct IEnumCbsIdentityVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumCbsIdentity_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumCbsIdentity_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumCbsIdentity_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumCbsIdentity_Next(This,celt,rgpCol,pbFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgpCol,pbFetched) ) 

#define IEnumCbsIdentity_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumCbsIdentity_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumCbsIdentity_Clone(This,__MIDL__IEnumCbsIdentity0000)	\
    ( (This)->lpVtbl -> Clone(This,__MIDL__IEnumCbsIdentity0000) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumCbsIdentity_INTERFACE_DEFINED__ */


#ifndef __IEnumCbsCapability_INTERFACE_DEFINED__
#define __IEnumCbsCapability_INTERFACE_DEFINED__

/* interface IEnumCbsCapability */
/* [object][uuid] */ 


EXTERN_C const IID IID_IEnumCbsCapability;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("25F05277-E733-4455-80B7-FA9C2DC9E678")
    IEnumCbsCapability : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ ICbsCapability **rgpCol,
            /* [out] */ ULONG *pbFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumCbsCapability **__MIDL__IEnumCbsCapability0000) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumCbsCapabilityVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumCbsCapability * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumCbsCapability * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumCbsCapability * This);
        
        DECLSPEC_XFGVIRT(IEnumCbsCapability, Next)
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumCbsCapability * This,
            /* [in] */ ULONG celt,
            /* [out] */ ICbsCapability **rgpCol,
            /* [out] */ ULONG *pbFetched);
        
        DECLSPEC_XFGVIRT(IEnumCbsCapability, Skip)
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumCbsCapability * This,
            /* [in] */ ULONG celt);
        
        DECLSPEC_XFGVIRT(IEnumCbsCapability, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumCbsCapability * This);
        
        DECLSPEC_XFGVIRT(IEnumCbsCapability, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumCbsCapability * This,
            /* [out] */ IEnumCbsCapability **__MIDL__IEnumCbsCapability0000);
        
        END_INTERFACE
    } IEnumCbsCapabilityVtbl;

    interface IEnumCbsCapability
    {
        CONST_VTBL struct IEnumCbsCapabilityVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumCbsCapability_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumCbsCapability_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumCbsCapability_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumCbsCapability_Next(This,celt,rgpCol,pbFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgpCol,pbFetched) ) 

#define IEnumCbsCapability_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumCbsCapability_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumCbsCapability_Clone(This,__MIDL__IEnumCbsCapability0000)	\
    ( (This)->lpVtbl -> Clone(This,__MIDL__IEnumCbsCapability0000) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumCbsCapability_INTERFACE_DEFINED__ */


#ifndef __IEnumCbsUpdate_INTERFACE_DEFINED__
#define __IEnumCbsUpdate_INTERFACE_DEFINED__

/* interface IEnumCbsUpdate */
/* [object][uuid] */ 


EXTERN_C const IID IID_IEnumCbsUpdate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("75207395-23F2-4396-85F0-8FDB879ED0ED")
    IEnumCbsUpdate : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ ICbsUpdate **rgpCol,
            /* [out] */ ULONG *pbFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumCbsUpdate **__MIDL__IEnumCbsUpdate0000) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumCbsUpdateVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumCbsUpdate * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumCbsUpdate * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumCbsUpdate * This);
        
        DECLSPEC_XFGVIRT(IEnumCbsUpdate, Next)
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumCbsUpdate * This,
            /* [in] */ ULONG celt,
            /* [out] */ ICbsUpdate **rgpCol,
            /* [out] */ ULONG *pbFetched);
        
        DECLSPEC_XFGVIRT(IEnumCbsUpdate, Skip)
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumCbsUpdate * This,
            /* [in] */ ULONG celt);
        
        DECLSPEC_XFGVIRT(IEnumCbsUpdate, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumCbsUpdate * This);
        
        DECLSPEC_XFGVIRT(IEnumCbsUpdate, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumCbsUpdate * This,
            /* [out] */ IEnumCbsUpdate **__MIDL__IEnumCbsUpdate0000);
        
        END_INTERFACE
    } IEnumCbsUpdateVtbl;

    interface IEnumCbsUpdate
    {
        CONST_VTBL struct IEnumCbsUpdateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumCbsUpdate_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumCbsUpdate_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumCbsUpdate_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumCbsUpdate_Next(This,celt,rgpCol,pbFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgpCol,pbFetched) ) 

#define IEnumCbsUpdate_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumCbsUpdate_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumCbsUpdate_Clone(This,__MIDL__IEnumCbsUpdate0000)	\
    ( (This)->lpVtbl -> Clone(This,__MIDL__IEnumCbsUpdate0000) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumCbsUpdate_INTERFACE_DEFINED__ */


#ifndef __IEnumCbsActivity_INTERFACE_DEFINED__
#define __IEnumCbsActivity_INTERFACE_DEFINED__

/* interface IEnumCbsActivity */
/* [object][uuid] */ 


EXTERN_C const IID IID_IEnumCbsActivity;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A454308D-1FC4-48E4-B6C0-2A9580804686")
    IEnumCbsActivity : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumCbsActivityVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumCbsActivity * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumCbsActivity * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumCbsActivity * This);
        
        END_INTERFACE
    } IEnumCbsActivityVtbl;

    interface IEnumCbsActivity
    {
        CONST_VTBL struct IEnumCbsActivityVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumCbsActivity_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumCbsActivity_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumCbsActivity_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumCbsActivity_INTERFACE_DEFINED__ */


#ifndef __IEnumCbsFeaturePackage_INTERFACE_DEFINED__
#define __IEnumCbsFeaturePackage_INTERFACE_DEFINED__

/* interface IEnumCbsFeaturePackage */
/* [object][uuid] */ 


EXTERN_C const IID IID_IEnumCbsFeaturePackage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D2F9F360-5BC7-4B1E-AAD5-DD151733C7C8")
    IEnumCbsFeaturePackage : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ ICbsFeaturePackage **rgpCol,
            /* [out] */ ULONG *pbFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumCbsUpdate **__MIDL__IEnumCbsFeaturePackage0000) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumCbsFeaturePackageVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumCbsFeaturePackage * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumCbsFeaturePackage * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumCbsFeaturePackage * This);
        
        DECLSPEC_XFGVIRT(IEnumCbsFeaturePackage, Next)
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumCbsFeaturePackage * This,
            /* [in] */ ULONG celt,
            /* [out] */ ICbsFeaturePackage **rgpCol,
            /* [out] */ ULONG *pbFetched);
        
        DECLSPEC_XFGVIRT(IEnumCbsFeaturePackage, Skip)
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumCbsFeaturePackage * This,
            /* [in] */ ULONG celt);
        
        DECLSPEC_XFGVIRT(IEnumCbsFeaturePackage, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumCbsFeaturePackage * This);
        
        DECLSPEC_XFGVIRT(IEnumCbsFeaturePackage, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumCbsFeaturePackage * This,
            /* [out] */ IEnumCbsUpdate **__MIDL__IEnumCbsFeaturePackage0000);
        
        END_INTERFACE
    } IEnumCbsFeaturePackageVtbl;

    interface IEnumCbsFeaturePackage
    {
        CONST_VTBL struct IEnumCbsFeaturePackageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumCbsFeaturePackage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumCbsFeaturePackage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumCbsFeaturePackage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumCbsFeaturePackage_Next(This,celt,rgpCol,pbFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgpCol,pbFetched) ) 

#define IEnumCbsFeaturePackage_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumCbsFeaturePackage_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumCbsFeaturePackage_Clone(This,__MIDL__IEnumCbsFeaturePackage0000)	\
    ( (This)->lpVtbl -> Clone(This,__MIDL__IEnumCbsFeaturePackage0000) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumCbsFeaturePackage_INTERFACE_DEFINED__ */


#ifndef __IEnumCbsSession_INTERFACE_DEFINED__
#define __IEnumCbsSession_INTERFACE_DEFINED__

/* interface IEnumCbsSession */
/* [object][uuid] */ 


EXTERN_C const IID IID_IEnumCbsSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6943A742-8AE2-4EB1-8A07-747C5CFD3B9E")
    IEnumCbsSession : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumCbsSessionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumCbsSession * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumCbsSession * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumCbsSession * This);
        
        END_INTERFACE
    } IEnumCbsSessionVtbl;

    interface IEnumCbsSession
    {
        CONST_VTBL struct IEnumCbsSessionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumCbsSession_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumCbsSession_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumCbsSession_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumCbsSession_INTERFACE_DEFINED__ */


#ifndef __ICSIExternalTransformerExecutor_INTERFACE_DEFINED__
#define __ICSIExternalTransformerExecutor_INTERFACE_DEFINED__

/* interface ICSIExternalTransformerExecutor */
/* [object][uuid] */ 


EXTERN_C const IID IID_ICSIExternalTransformerExecutor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1C8ADB85-982E-47F9-999F-B0C3BF9D0449")
    ICSIExternalTransformerExecutor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Commit( 
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0000,
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0001,
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0002,
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0003) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ ULONG __MIDL__ICSIExternalTransformerExecutor0004,
            /* [in] */ UINT64 __MIDL__ICSIExternalTransformerExecutor0005,
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0006,
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0007,
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0008) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Install( 
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0009,
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0010) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICSIExternalTransformerExecutorVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICSIExternalTransformerExecutor * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICSIExternalTransformerExecutor * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICSIExternalTransformerExecutor * This);
        
        DECLSPEC_XFGVIRT(ICSIExternalTransformerExecutor, Commit)
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            ICSIExternalTransformerExecutor * This,
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0000,
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0001,
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0002,
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0003);
        
        DECLSPEC_XFGVIRT(ICSIExternalTransformerExecutor, Initialize)
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            ICSIExternalTransformerExecutor * This,
            /* [in] */ ULONG __MIDL__ICSIExternalTransformerExecutor0004,
            /* [in] */ UINT64 __MIDL__ICSIExternalTransformerExecutor0005,
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0006,
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0007,
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0008);
        
        DECLSPEC_XFGVIRT(ICSIExternalTransformerExecutor, Install)
        HRESULT ( STDMETHODCALLTYPE *Install )( 
            ICSIExternalTransformerExecutor * This,
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0009,
            /* [in] */ LPCTSTR __MIDL__ICSIExternalTransformerExecutor0010);
        
        END_INTERFACE
    } ICSIExternalTransformerExecutorVtbl;

    interface ICSIExternalTransformerExecutor
    {
        CONST_VTBL struct ICSIExternalTransformerExecutorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICSIExternalTransformerExecutor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICSIExternalTransformerExecutor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICSIExternalTransformerExecutor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICSIExternalTransformerExecutor_Commit(This,__MIDL__ICSIExternalTransformerExecutor0000,__MIDL__ICSIExternalTransformerExecutor0001,__MIDL__ICSIExternalTransformerExecutor0002,__MIDL__ICSIExternalTransformerExecutor0003)	\
    ( (This)->lpVtbl -> Commit(This,__MIDL__ICSIExternalTransformerExecutor0000,__MIDL__ICSIExternalTransformerExecutor0001,__MIDL__ICSIExternalTransformerExecutor0002,__MIDL__ICSIExternalTransformerExecutor0003) ) 

#define ICSIExternalTransformerExecutor_Initialize(This,__MIDL__ICSIExternalTransformerExecutor0004,__MIDL__ICSIExternalTransformerExecutor0005,__MIDL__ICSIExternalTransformerExecutor0006,__MIDL__ICSIExternalTransformerExecutor0007,__MIDL__ICSIExternalTransformerExecutor0008)	\
    ( (This)->lpVtbl -> Initialize(This,__MIDL__ICSIExternalTransformerExecutor0004,__MIDL__ICSIExternalTransformerExecutor0005,__MIDL__ICSIExternalTransformerExecutor0006,__MIDL__ICSIExternalTransformerExecutor0007,__MIDL__ICSIExternalTransformerExecutor0008) ) 

#define ICSIExternalTransformerExecutor_Install(This,__MIDL__ICSIExternalTransformerExecutor0009,__MIDL__ICSIExternalTransformerExecutor0010)	\
    ( (This)->lpVtbl -> Install(This,__MIDL__ICSIExternalTransformerExecutor0009,__MIDL__ICSIExternalTransformerExecutor0010) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICSIExternalTransformerExecutor_INTERFACE_DEFINED__ */


#ifndef __ICbsSessionObserverListener_INTERFACE_DEFINED__
#define __ICbsSessionObserverListener_INTERFACE_DEFINED__

/* interface ICbsSessionObserverListener */
/* [object][uuid] */ 


EXTERN_C const IID IID_ICbsSessionObserverListener;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E3AFD5FD-3B03-453D-91CE-EBBDA9B8BEA1")
    ICbsSessionObserverListener : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ICbsSessionObserverListenerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICbsSessionObserverListener * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICbsSessionObserverListener * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICbsSessionObserverListener * This);
        
        END_INTERFACE
    } ICbsSessionObserverListenerVtbl;

    interface ICbsSessionObserverListener
    {
        CONST_VTBL struct ICbsSessionObserverListenerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICbsSessionObserverListener_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICbsSessionObserverListener_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICbsSessionObserverListener_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICbsSessionObserverListener_INTERFACE_DEFINED__ */


#ifndef __ICbsSession_INTERFACE_DEFINED__
#define __ICbsSession_INTERFACE_DEFINED__

/* interface ICbsSession */
/* [object][uuid] */ 


EXTERN_C const IID IID_ICbsSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("75207391-23F2-4396-85F0-8FDB879ED0ED")
    ICbsSession : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ _CbsSessionOption sessionOptions,
            /* [string][in] */ LPCTSTR clientID,
            /* [string][in] */ LPCTSTR bootDrive,
            /* [in] */ LPCTSTR winDir) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finalize( 
            /* [out] */ _CbsRequiredAction *pRequiredAction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreatePackage( 
            /* [in] */ UINT options,
            /* [in] */ _CbsPackageType packageType,
            /* [string][in] */ LPCTSTR szPkgPath,
            /* [string][in] */ LPCTSTR szSandboxPath,
            /* [retval][out] */ ICbsPackage **pPackage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenPackage( 
            /* [in] */ UINT options,
            /* [in] */ ICbsIdentity *pPackageIdentity,
            /* [string][in] */ LPCTSTR unkArgAboutLog,
            /* [retval][out] */ ICbsPackage **pPackage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumeratePackages( 
            /* [in] */ UINT options,
            /* [out] */ IEnumCbsIdentity **pPackageList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateCbsIdentity( 
            /* [retval][out] */ ICbsIdentity **ppIdentity) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICbsSessionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICbsSession * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICbsSession * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICbsSession * This);
        
        DECLSPEC_XFGVIRT(ICbsSession, Initialize)
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            ICbsSession * This,
            /* [in] */ _CbsSessionOption sessionOptions,
            /* [string][in] */ LPCTSTR clientID,
            /* [string][in] */ LPCTSTR bootDrive,
            /* [in] */ LPCTSTR winDir);
        
        DECLSPEC_XFGVIRT(ICbsSession, Finalize)
        HRESULT ( STDMETHODCALLTYPE *Finalize )( 
            ICbsSession * This,
            /* [out] */ _CbsRequiredAction *pRequiredAction);
        
        DECLSPEC_XFGVIRT(ICbsSession, CreatePackage)
        HRESULT ( STDMETHODCALLTYPE *CreatePackage )( 
            ICbsSession * This,
            /* [in] */ UINT options,
            /* [in] */ _CbsPackageType packageType,
            /* [string][in] */ LPCTSTR szPkgPath,
            /* [string][in] */ LPCTSTR szSandboxPath,
            /* [retval][out] */ ICbsPackage **pPackage);
        
        DECLSPEC_XFGVIRT(ICbsSession, OpenPackage)
        HRESULT ( STDMETHODCALLTYPE *OpenPackage )( 
            ICbsSession * This,
            /* [in] */ UINT options,
            /* [in] */ ICbsIdentity *pPackageIdentity,
            /* [string][in] */ LPCTSTR unkArgAboutLog,
            /* [retval][out] */ ICbsPackage **pPackage);
        
        DECLSPEC_XFGVIRT(ICbsSession, EnumeratePackages)
        HRESULT ( STDMETHODCALLTYPE *EnumeratePackages )( 
            ICbsSession * This,
            /* [in] */ UINT options,
            /* [out] */ IEnumCbsIdentity **pPackageList);
        
        DECLSPEC_XFGVIRT(ICbsSession, CreateCbsIdentity)
        HRESULT ( STDMETHODCALLTYPE *CreateCbsIdentity )( 
            ICbsSession * This,
            /* [retval][out] */ ICbsIdentity **ppIdentity);
        
        END_INTERFACE
    } ICbsSessionVtbl;

    interface ICbsSession
    {
        CONST_VTBL struct ICbsSessionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICbsSession_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICbsSession_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICbsSession_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICbsSession_Initialize(This,sessionOptions,clientID,bootDrive,winDir)	\
    ( (This)->lpVtbl -> Initialize(This,sessionOptions,clientID,bootDrive,winDir) ) 

#define ICbsSession_Finalize(This,pRequiredAction)	\
    ( (This)->lpVtbl -> Finalize(This,pRequiredAction) ) 

#define ICbsSession_CreatePackage(This,options,packageType,szPkgPath,szSandboxPath,pPackage)	\
    ( (This)->lpVtbl -> CreatePackage(This,options,packageType,szPkgPath,szSandboxPath,pPackage) ) 

#define ICbsSession_OpenPackage(This,options,pPackageIdentity,unkArgAboutLog,pPackage)	\
    ( (This)->lpVtbl -> OpenPackage(This,options,pPackageIdentity,unkArgAboutLog,pPackage) ) 

#define ICbsSession_EnumeratePackages(This,options,pPackageList)	\
    ( (This)->lpVtbl -> EnumeratePackages(This,options,pPackageList) ) 

#define ICbsSession_CreateCbsIdentity(This,ppIdentity)	\
    ( (This)->lpVtbl -> CreateCbsIdentity(This,ppIdentity) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICbsSession_INTERFACE_DEFINED__ */


#ifndef __ICbsSession7_INTERFACE_DEFINED__
#define __ICbsSession7_INTERFACE_DEFINED__

/* interface ICbsSession7 */
/* [object][uuid] */ 


EXTERN_C const IID IID_ICbsSession7;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DC95A094-EE0E-4974-9600-027D2321C2D4")
    ICbsSession7 : public ICbsSession
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [out] */ UINT *pCurrentPhase,
            /* [out] */ _CbsSessionState *pLastSuccessfulSessionState,
            /* [out] */ BOOL *pbCompleted,
            /* [out] */ HRESULT *phrStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resume( 
            /* [in] */ ICbsUIHandler *pUIHandler) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSessionId( 
            /* [retval][out] */ LPTSTR *pszIdentity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ _CbsSessionProperty prop,
            /* [retval][out] */ LPTSTR *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddPhaseBreak( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FinalizeEx( 
            /* [in] */ UINT __MIDL__ICbsSession70000,
            /* [retval][out] */ _CbsRequiredAction *pRequiredAction) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICbsSession7Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICbsSession7 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICbsSession7 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICbsSession7 * This);
        
        DECLSPEC_XFGVIRT(ICbsSession, Initialize)
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            ICbsSession7 * This,
            /* [in] */ _CbsSessionOption sessionOptions,
            /* [string][in] */ LPCTSTR clientID,
            /* [string][in] */ LPCTSTR bootDrive,
            /* [in] */ LPCTSTR winDir);
        
        DECLSPEC_XFGVIRT(ICbsSession, Finalize)
        HRESULT ( STDMETHODCALLTYPE *Finalize )( 
            ICbsSession7 * This,
            /* [out] */ _CbsRequiredAction *pRequiredAction);
        
        DECLSPEC_XFGVIRT(ICbsSession, CreatePackage)
        HRESULT ( STDMETHODCALLTYPE *CreatePackage )( 
            ICbsSession7 * This,
            /* [in] */ UINT options,
            /* [in] */ _CbsPackageType packageType,
            /* [string][in] */ LPCTSTR szPkgPath,
            /* [string][in] */ LPCTSTR szSandboxPath,
            /* [retval][out] */ ICbsPackage **pPackage);
        
        DECLSPEC_XFGVIRT(ICbsSession, OpenPackage)
        HRESULT ( STDMETHODCALLTYPE *OpenPackage )( 
            ICbsSession7 * This,
            /* [in] */ UINT options,
            /* [in] */ ICbsIdentity *pPackageIdentity,
            /* [string][in] */ LPCTSTR unkArgAboutLog,
            /* [retval][out] */ ICbsPackage **pPackage);
        
        DECLSPEC_XFGVIRT(ICbsSession, EnumeratePackages)
        HRESULT ( STDMETHODCALLTYPE *EnumeratePackages )( 
            ICbsSession7 * This,
            /* [in] */ UINT options,
            /* [out] */ IEnumCbsIdentity **pPackageList);
        
        DECLSPEC_XFGVIRT(ICbsSession, CreateCbsIdentity)
        HRESULT ( STDMETHODCALLTYPE *CreateCbsIdentity )( 
            ICbsSession7 * This,
            /* [retval][out] */ ICbsIdentity **ppIdentity);
        
        DECLSPEC_XFGVIRT(ICbsSession7, GetStatus)
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            ICbsSession7 * This,
            /* [out] */ UINT *pCurrentPhase,
            /* [out] */ _CbsSessionState *pLastSuccessfulSessionState,
            /* [out] */ BOOL *pbCompleted,
            /* [out] */ HRESULT *phrStatus);
        
        DECLSPEC_XFGVIRT(ICbsSession7, Resume)
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            ICbsSession7 * This,
            /* [in] */ ICbsUIHandler *pUIHandler);
        
        DECLSPEC_XFGVIRT(ICbsSession7, GetSessionId)
        HRESULT ( STDMETHODCALLTYPE *GetSessionId )( 
            ICbsSession7 * This,
            /* [retval][out] */ LPTSTR *pszIdentity);
        
        DECLSPEC_XFGVIRT(ICbsSession7, GetProperty)
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            ICbsSession7 * This,
            /* [in] */ _CbsSessionProperty prop,
            /* [retval][out] */ LPTSTR *pValue);
        
        DECLSPEC_XFGVIRT(ICbsSession7, AddPhaseBreak)
        HRESULT ( STDMETHODCALLTYPE *AddPhaseBreak )( 
            ICbsSession7 * This);
        
        DECLSPEC_XFGVIRT(ICbsSession7, FinalizeEx)
        HRESULT ( STDMETHODCALLTYPE *FinalizeEx )( 
            ICbsSession7 * This,
            /* [in] */ UINT __MIDL__ICbsSession70000,
            /* [retval][out] */ _CbsRequiredAction *pRequiredAction);
        
        END_INTERFACE
    } ICbsSession7Vtbl;

    interface ICbsSession7
    {
        CONST_VTBL struct ICbsSession7Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICbsSession7_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICbsSession7_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICbsSession7_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICbsSession7_Initialize(This,sessionOptions,clientID,bootDrive,winDir)	\
    ( (This)->lpVtbl -> Initialize(This,sessionOptions,clientID,bootDrive,winDir) ) 

#define ICbsSession7_Finalize(This,pRequiredAction)	\
    ( (This)->lpVtbl -> Finalize(This,pRequiredAction) ) 

#define ICbsSession7_CreatePackage(This,options,packageType,szPkgPath,szSandboxPath,pPackage)	\
    ( (This)->lpVtbl -> CreatePackage(This,options,packageType,szPkgPath,szSandboxPath,pPackage) ) 

#define ICbsSession7_OpenPackage(This,options,pPackageIdentity,unkArgAboutLog,pPackage)	\
    ( (This)->lpVtbl -> OpenPackage(This,options,pPackageIdentity,unkArgAboutLog,pPackage) ) 

#define ICbsSession7_EnumeratePackages(This,options,pPackageList)	\
    ( (This)->lpVtbl -> EnumeratePackages(This,options,pPackageList) ) 

#define ICbsSession7_CreateCbsIdentity(This,ppIdentity)	\
    ( (This)->lpVtbl -> CreateCbsIdentity(This,ppIdentity) ) 


#define ICbsSession7_GetStatus(This,pCurrentPhase,pLastSuccessfulSessionState,pbCompleted,phrStatus)	\
    ( (This)->lpVtbl -> GetStatus(This,pCurrentPhase,pLastSuccessfulSessionState,pbCompleted,phrStatus) ) 

#define ICbsSession7_Resume(This,pUIHandler)	\
    ( (This)->lpVtbl -> Resume(This,pUIHandler) ) 

#define ICbsSession7_GetSessionId(This,pszIdentity)	\
    ( (This)->lpVtbl -> GetSessionId(This,pszIdentity) ) 

#define ICbsSession7_GetProperty(This,prop,pValue)	\
    ( (This)->lpVtbl -> GetProperty(This,prop,pValue) ) 

#define ICbsSession7_AddPhaseBreak(This)	\
    ( (This)->lpVtbl -> AddPhaseBreak(This) ) 

#define ICbsSession7_FinalizeEx(This,__MIDL__ICbsSession70000,pRequiredAction)	\
    ( (This)->lpVtbl -> FinalizeEx(This,__MIDL__ICbsSession70000,pRequiredAction) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICbsSession7_INTERFACE_DEFINED__ */


#ifndef __ICbsSession8_INTERFACE_DEFINED__
#define __ICbsSession8_INTERFACE_DEFINED__

/* interface ICbsSession8 */
/* [object][uuid] */ 


EXTERN_C const IID IID_ICbsSession8;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F568C899-AF4F-4EAA-B12A-B8E5F1B219DE")
    ICbsSession8 : public ICbsSession7
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddSource( 
            /* [in] */ UINT options,
            /* [string][in] */ LPCTSTR basePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterCbsUIHandler( 
            /* [in] */ ICbsUIHandler *pUIHandler) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICbsSession8Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICbsSession8 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICbsSession8 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICbsSession8 * This);
        
        DECLSPEC_XFGVIRT(ICbsSession, Initialize)
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            ICbsSession8 * This,
            /* [in] */ _CbsSessionOption sessionOptions,
            /* [string][in] */ LPCTSTR clientID,
            /* [string][in] */ LPCTSTR bootDrive,
            /* [in] */ LPCTSTR winDir);
        
        DECLSPEC_XFGVIRT(ICbsSession, Finalize)
        HRESULT ( STDMETHODCALLTYPE *Finalize )( 
            ICbsSession8 * This,
            /* [out] */ _CbsRequiredAction *pRequiredAction);
        
        DECLSPEC_XFGVIRT(ICbsSession, CreatePackage)
        HRESULT ( STDMETHODCALLTYPE *CreatePackage )( 
            ICbsSession8 * This,
            /* [in] */ UINT options,
            /* [in] */ _CbsPackageType packageType,
            /* [string][in] */ LPCTSTR szPkgPath,
            /* [string][in] */ LPCTSTR szSandboxPath,
            /* [retval][out] */ ICbsPackage **pPackage);
        
        DECLSPEC_XFGVIRT(ICbsSession, OpenPackage)
        HRESULT ( STDMETHODCALLTYPE *OpenPackage )( 
            ICbsSession8 * This,
            /* [in] */ UINT options,
            /* [in] */ ICbsIdentity *pPackageIdentity,
            /* [string][in] */ LPCTSTR unkArgAboutLog,
            /* [retval][out] */ ICbsPackage **pPackage);
        
        DECLSPEC_XFGVIRT(ICbsSession, EnumeratePackages)
        HRESULT ( STDMETHODCALLTYPE *EnumeratePackages )( 
            ICbsSession8 * This,
            /* [in] */ UINT options,
            /* [out] */ IEnumCbsIdentity **pPackageList);
        
        DECLSPEC_XFGVIRT(ICbsSession, CreateCbsIdentity)
        HRESULT ( STDMETHODCALLTYPE *CreateCbsIdentity )( 
            ICbsSession8 * This,
            /* [retval][out] */ ICbsIdentity **ppIdentity);
        
        DECLSPEC_XFGVIRT(ICbsSession7, GetStatus)
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            ICbsSession8 * This,
            /* [out] */ UINT *pCurrentPhase,
            /* [out] */ _CbsSessionState *pLastSuccessfulSessionState,
            /* [out] */ BOOL *pbCompleted,
            /* [out] */ HRESULT *phrStatus);
        
        DECLSPEC_XFGVIRT(ICbsSession7, Resume)
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            ICbsSession8 * This,
            /* [in] */ ICbsUIHandler *pUIHandler);
        
        DECLSPEC_XFGVIRT(ICbsSession7, GetSessionId)
        HRESULT ( STDMETHODCALLTYPE *GetSessionId )( 
            ICbsSession8 * This,
            /* [retval][out] */ LPTSTR *pszIdentity);
        
        DECLSPEC_XFGVIRT(ICbsSession7, GetProperty)
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            ICbsSession8 * This,
            /* [in] */ _CbsSessionProperty prop,
            /* [retval][out] */ LPTSTR *pValue);
        
        DECLSPEC_XFGVIRT(ICbsSession7, AddPhaseBreak)
        HRESULT ( STDMETHODCALLTYPE *AddPhaseBreak )( 
            ICbsSession8 * This);
        
        DECLSPEC_XFGVIRT(ICbsSession7, FinalizeEx)
        HRESULT ( STDMETHODCALLTYPE *FinalizeEx )( 
            ICbsSession8 * This,
            /* [in] */ UINT __MIDL__ICbsSession70000,
            /* [retval][out] */ _CbsRequiredAction *pRequiredAction);
        
        DECLSPEC_XFGVIRT(ICbsSession8, AddSource)
        HRESULT ( STDMETHODCALLTYPE *AddSource )( 
            ICbsSession8 * This,
            /* [in] */ UINT options,
            /* [string][in] */ LPCTSTR basePath);
        
        DECLSPEC_XFGVIRT(ICbsSession8, RegisterCbsUIHandler)
        HRESULT ( STDMETHODCALLTYPE *RegisterCbsUIHandler )( 
            ICbsSession8 * This,
            /* [in] */ ICbsUIHandler *pUIHandler);
        
        END_INTERFACE
    } ICbsSession8Vtbl;

    interface ICbsSession8
    {
        CONST_VTBL struct ICbsSession8Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICbsSession8_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICbsSession8_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICbsSession8_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICbsSession8_Initialize(This,sessionOptions,clientID,bootDrive,winDir)	\
    ( (This)->lpVtbl -> Initialize(This,sessionOptions,clientID,bootDrive,winDir) ) 

#define ICbsSession8_Finalize(This,pRequiredAction)	\
    ( (This)->lpVtbl -> Finalize(This,pRequiredAction) ) 

#define ICbsSession8_CreatePackage(This,options,packageType,szPkgPath,szSandboxPath,pPackage)	\
    ( (This)->lpVtbl -> CreatePackage(This,options,packageType,szPkgPath,szSandboxPath,pPackage) ) 

#define ICbsSession8_OpenPackage(This,options,pPackageIdentity,unkArgAboutLog,pPackage)	\
    ( (This)->lpVtbl -> OpenPackage(This,options,pPackageIdentity,unkArgAboutLog,pPackage) ) 

#define ICbsSession8_EnumeratePackages(This,options,pPackageList)	\
    ( (This)->lpVtbl -> EnumeratePackages(This,options,pPackageList) ) 

#define ICbsSession8_CreateCbsIdentity(This,ppIdentity)	\
    ( (This)->lpVtbl -> CreateCbsIdentity(This,ppIdentity) ) 


#define ICbsSession8_GetStatus(This,pCurrentPhase,pLastSuccessfulSessionState,pbCompleted,phrStatus)	\
    ( (This)->lpVtbl -> GetStatus(This,pCurrentPhase,pLastSuccessfulSessionState,pbCompleted,phrStatus) ) 

#define ICbsSession8_Resume(This,pUIHandler)	\
    ( (This)->lpVtbl -> Resume(This,pUIHandler) ) 

#define ICbsSession8_GetSessionId(This,pszIdentity)	\
    ( (This)->lpVtbl -> GetSessionId(This,pszIdentity) ) 

#define ICbsSession8_GetProperty(This,prop,pValue)	\
    ( (This)->lpVtbl -> GetProperty(This,prop,pValue) ) 

#define ICbsSession8_AddPhaseBreak(This)	\
    ( (This)->lpVtbl -> AddPhaseBreak(This) ) 

#define ICbsSession8_FinalizeEx(This,__MIDL__ICbsSession70000,pRequiredAction)	\
    ( (This)->lpVtbl -> FinalizeEx(This,__MIDL__ICbsSession70000,pRequiredAction) ) 


#define ICbsSession8_AddSource(This,options,basePath)	\
    ( (This)->lpVtbl -> AddSource(This,options,basePath) ) 

#define ICbsSession8_RegisterCbsUIHandler(This,pUIHandler)	\
    ( (This)->lpVtbl -> RegisterCbsUIHandler(This,pUIHandler) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICbsSession8_INTERFACE_DEFINED__ */


#ifndef __ICbsSession10_INTERFACE_DEFINED__
#define __ICbsSession10_INTERFACE_DEFINED__

/* interface ICbsSession10 */
/* [object][uuid] */ 


EXTERN_C const IID IID_ICbsSession10;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F112757A-565B-4260-BD05-9FA34417349A")
    ICbsSession10 : public ICbsSession8
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateWindowsUpdatePackage( 
            /* [in] */ UINT __MIDL__ICbsSession100000,
            /* [string][in] */ LPCTSTR __MIDL__ICbsSession100001,
            /* [in] */ GUID __MIDL__ICbsSession100002,
            /* [in] */ UINT __MIDL__ICbsSession100003,
            /* [in] */ _CbsPackageType __MIDL__ICbsSession100004,
            /* [string][in] */ LPCTSTR __MIDL__ICbsSession100005,
            /* [string][in] */ LPCTSTR __MIDL__ICbsSession100006,
            /* [in] */ UINT __MIDL__ICbsSession100007,
            /* [in] */ const tagCbsPackageDecryptionData *__MIDL__ICbsSession100008,
            /* [in] */ tagCbsPackageEncryptionEnum __MIDL__ICbsSession100009,
            /* [retval][out] */ ICbsPackage **__MIDL__ICbsSession100010) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumerateCapabilities( 
            /* [in] */ _CbsCapabilitySourceFilter sourceFilter,
            /* [string][in] */ LPCTSTR szNamespace,
            /* [string][in] */ LPCTSTR szLang,
            /* [string][in] */ LPCTSTR szArch,
            /* [in] */ ULONG dwMajor,
            /* [in] */ ULONG dwMinor,
            /* [retval][out] */ IEnumCbsCapability **__MIDL__ICbsSession100011) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitializeEx( 
            /* [in] */ UINT sessionOptions,
            /* [string][in] */ LPCTSTR sourceName,
            /* [string][in] */ LPCTSTR bootDrive,
            /* [string][in] */ LPCTSTR winDir,
            /* [string][in] */ LPCTSTR externalDir) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateExternalTransformerExecutor( 
            /* [retval][out] */ ICSIExternalTransformerExecutor **ppCsiExecutor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ObserveSessions( 
            /* [in] */ UINT options,
            /* [in] */ ICbsSessionObserverListener *pListener,
            /* [retval][out] */ IEnumCbsSession **__MIDL__ICbsSession100012) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetActivities( 
            /* [in] */ INT64 options,
            /* [retval][out] */ IEnumCbsActivity **__MIDL__ICbsSession100013) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEnhancedOptions( 
            /* [in] */ _CbsSessionEnhancedOption enhancedOptions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProperty( 
            /* [in] */ _CbsSessionConfigurableProperty prop,
            /* [string][in] */ LPCTSTR value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PerformOperation( 
            /* [in] */ UINT reserved,
            /* [in] */ _CbsOperationType type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetClientToken( 
            /* [in] */ INT64 token) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICbsSession10Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICbsSession10 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICbsSession10 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICbsSession10 * This);
        
        DECLSPEC_XFGVIRT(ICbsSession, Initialize)
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            ICbsSession10 * This,
            /* [in] */ _CbsSessionOption sessionOptions,
            /* [string][in] */ LPCTSTR clientID,
            /* [string][in] */ LPCTSTR bootDrive,
            /* [in] */ LPCTSTR winDir);
        
        DECLSPEC_XFGVIRT(ICbsSession, Finalize)
        HRESULT ( STDMETHODCALLTYPE *Finalize )( 
            ICbsSession10 * This,
            /* [out] */ _CbsRequiredAction *pRequiredAction);
        
        DECLSPEC_XFGVIRT(ICbsSession, CreatePackage)
        HRESULT ( STDMETHODCALLTYPE *CreatePackage )( 
            ICbsSession10 * This,
            /* [in] */ UINT options,
            /* [in] */ _CbsPackageType packageType,
            /* [string][in] */ LPCTSTR szPkgPath,
            /* [string][in] */ LPCTSTR szSandboxPath,
            /* [retval][out] */ ICbsPackage **pPackage);
        
        DECLSPEC_XFGVIRT(ICbsSession, OpenPackage)
        HRESULT ( STDMETHODCALLTYPE *OpenPackage )( 
            ICbsSession10 * This,
            /* [in] */ UINT options,
            /* [in] */ ICbsIdentity *pPackageIdentity,
            /* [string][in] */ LPCTSTR unkArgAboutLog,
            /* [retval][out] */ ICbsPackage **pPackage);
        
        DECLSPEC_XFGVIRT(ICbsSession, EnumeratePackages)
        HRESULT ( STDMETHODCALLTYPE *EnumeratePackages )( 
            ICbsSession10 * This,
            /* [in] */ UINT options,
            /* [out] */ IEnumCbsIdentity **pPackageList);
        
        DECLSPEC_XFGVIRT(ICbsSession, CreateCbsIdentity)
        HRESULT ( STDMETHODCALLTYPE *CreateCbsIdentity )( 
            ICbsSession10 * This,
            /* [retval][out] */ ICbsIdentity **ppIdentity);
        
        DECLSPEC_XFGVIRT(ICbsSession7, GetStatus)
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            ICbsSession10 * This,
            /* [out] */ UINT *pCurrentPhase,
            /* [out] */ _CbsSessionState *pLastSuccessfulSessionState,
            /* [out] */ BOOL *pbCompleted,
            /* [out] */ HRESULT *phrStatus);
        
        DECLSPEC_XFGVIRT(ICbsSession7, Resume)
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            ICbsSession10 * This,
            /* [in] */ ICbsUIHandler *pUIHandler);
        
        DECLSPEC_XFGVIRT(ICbsSession7, GetSessionId)
        HRESULT ( STDMETHODCALLTYPE *GetSessionId )( 
            ICbsSession10 * This,
            /* [retval][out] */ LPTSTR *pszIdentity);
        
        DECLSPEC_XFGVIRT(ICbsSession7, GetProperty)
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            ICbsSession10 * This,
            /* [in] */ _CbsSessionProperty prop,
            /* [retval][out] */ LPTSTR *pValue);
        
        DECLSPEC_XFGVIRT(ICbsSession7, AddPhaseBreak)
        HRESULT ( STDMETHODCALLTYPE *AddPhaseBreak )( 
            ICbsSession10 * This);
        
        DECLSPEC_XFGVIRT(ICbsSession7, FinalizeEx)
        HRESULT ( STDMETHODCALLTYPE *FinalizeEx )( 
            ICbsSession10 * This,
            /* [in] */ UINT __MIDL__ICbsSession70000,
            /* [retval][out] */ _CbsRequiredAction *pRequiredAction);
        
        DECLSPEC_XFGVIRT(ICbsSession8, AddSource)
        HRESULT ( STDMETHODCALLTYPE *AddSource )( 
            ICbsSession10 * This,
            /* [in] */ UINT options,
            /* [string][in] */ LPCTSTR basePath);
        
        DECLSPEC_XFGVIRT(ICbsSession8, RegisterCbsUIHandler)
        HRESULT ( STDMETHODCALLTYPE *RegisterCbsUIHandler )( 
            ICbsSession10 * This,
            /* [in] */ ICbsUIHandler *pUIHandler);
        
        DECLSPEC_XFGVIRT(ICbsSession10, CreateWindowsUpdatePackage)
        HRESULT ( STDMETHODCALLTYPE *CreateWindowsUpdatePackage )( 
            ICbsSession10 * This,
            /* [in] */ UINT __MIDL__ICbsSession100000,
            /* [string][in] */ LPCTSTR __MIDL__ICbsSession100001,
            /* [in] */ GUID __MIDL__ICbsSession100002,
            /* [in] */ UINT __MIDL__ICbsSession100003,
            /* [in] */ _CbsPackageType __MIDL__ICbsSession100004,
            /* [string][in] */ LPCTSTR __MIDL__ICbsSession100005,
            /* [string][in] */ LPCTSTR __MIDL__ICbsSession100006,
            /* [in] */ UINT __MIDL__ICbsSession100007,
            /* [in] */ const tagCbsPackageDecryptionData *__MIDL__ICbsSession100008,
            /* [in] */ tagCbsPackageEncryptionEnum __MIDL__ICbsSession100009,
            /* [retval][out] */ ICbsPackage **__MIDL__ICbsSession100010);
        
        DECLSPEC_XFGVIRT(ICbsSession10, EnumerateCapabilities)
        HRESULT ( STDMETHODCALLTYPE *EnumerateCapabilities )( 
            ICbsSession10 * This,
            /* [in] */ _CbsCapabilitySourceFilter sourceFilter,
            /* [string][in] */ LPCTSTR szNamespace,
            /* [string][in] */ LPCTSTR szLang,
            /* [string][in] */ LPCTSTR szArch,
            /* [in] */ ULONG dwMajor,
            /* [in] */ ULONG dwMinor,
            /* [retval][out] */ IEnumCbsCapability **__MIDL__ICbsSession100011);
        
        DECLSPEC_XFGVIRT(ICbsSession10, InitializeEx)
        HRESULT ( STDMETHODCALLTYPE *InitializeEx )( 
            ICbsSession10 * This,
            /* [in] */ UINT sessionOptions,
            /* [string][in] */ LPCTSTR sourceName,
            /* [string][in] */ LPCTSTR bootDrive,
            /* [string][in] */ LPCTSTR winDir,
            /* [string][in] */ LPCTSTR externalDir);
        
        DECLSPEC_XFGVIRT(ICbsSession10, CreateExternalTransformerExecutor)
        HRESULT ( STDMETHODCALLTYPE *CreateExternalTransformerExecutor )( 
            ICbsSession10 * This,
            /* [retval][out] */ ICSIExternalTransformerExecutor **ppCsiExecutor);
        
        DECLSPEC_XFGVIRT(ICbsSession10, ObserveSessions)
        HRESULT ( STDMETHODCALLTYPE *ObserveSessions )( 
            ICbsSession10 * This,
            /* [in] */ UINT options,
            /* [in] */ ICbsSessionObserverListener *pListener,
            /* [retval][out] */ IEnumCbsSession **__MIDL__ICbsSession100012);
        
        DECLSPEC_XFGVIRT(ICbsSession10, GetActivities)
        HRESULT ( STDMETHODCALLTYPE *GetActivities )( 
            ICbsSession10 * This,
            /* [in] */ INT64 options,
            /* [retval][out] */ IEnumCbsActivity **__MIDL__ICbsSession100013);
        
        DECLSPEC_XFGVIRT(ICbsSession10, SetEnhancedOptions)
        HRESULT ( STDMETHODCALLTYPE *SetEnhancedOptions )( 
            ICbsSession10 * This,
            /* [in] */ _CbsSessionEnhancedOption enhancedOptions);
        
        DECLSPEC_XFGVIRT(ICbsSession10, SetProperty)
        HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            ICbsSession10 * This,
            /* [in] */ _CbsSessionConfigurableProperty prop,
            /* [string][in] */ LPCTSTR value);
        
        DECLSPEC_XFGVIRT(ICbsSession10, PerformOperation)
        HRESULT ( STDMETHODCALLTYPE *PerformOperation )( 
            ICbsSession10 * This,
            /* [in] */ UINT reserved,
            /* [in] */ _CbsOperationType type);
        
        DECLSPEC_XFGVIRT(ICbsSession10, SetClientToken)
        HRESULT ( STDMETHODCALLTYPE *SetClientToken )( 
            ICbsSession10 * This,
            /* [in] */ INT64 token);
        
        END_INTERFACE
    } ICbsSession10Vtbl;

    interface ICbsSession10
    {
        CONST_VTBL struct ICbsSession10Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICbsSession10_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICbsSession10_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICbsSession10_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICbsSession10_Initialize(This,sessionOptions,clientID,bootDrive,winDir)	\
    ( (This)->lpVtbl -> Initialize(This,sessionOptions,clientID,bootDrive,winDir) ) 

#define ICbsSession10_Finalize(This,pRequiredAction)	\
    ( (This)->lpVtbl -> Finalize(This,pRequiredAction) ) 

#define ICbsSession10_CreatePackage(This,options,packageType,szPkgPath,szSandboxPath,pPackage)	\
    ( (This)->lpVtbl -> CreatePackage(This,options,packageType,szPkgPath,szSandboxPath,pPackage) ) 

#define ICbsSession10_OpenPackage(This,options,pPackageIdentity,unkArgAboutLog,pPackage)	\
    ( (This)->lpVtbl -> OpenPackage(This,options,pPackageIdentity,unkArgAboutLog,pPackage) ) 

#define ICbsSession10_EnumeratePackages(This,options,pPackageList)	\
    ( (This)->lpVtbl -> EnumeratePackages(This,options,pPackageList) ) 

#define ICbsSession10_CreateCbsIdentity(This,ppIdentity)	\
    ( (This)->lpVtbl -> CreateCbsIdentity(This,ppIdentity) ) 


#define ICbsSession10_GetStatus(This,pCurrentPhase,pLastSuccessfulSessionState,pbCompleted,phrStatus)	\
    ( (This)->lpVtbl -> GetStatus(This,pCurrentPhase,pLastSuccessfulSessionState,pbCompleted,phrStatus) ) 

#define ICbsSession10_Resume(This,pUIHandler)	\
    ( (This)->lpVtbl -> Resume(This,pUIHandler) ) 

#define ICbsSession10_GetSessionId(This,pszIdentity)	\
    ( (This)->lpVtbl -> GetSessionId(This,pszIdentity) ) 

#define ICbsSession10_GetProperty(This,prop,pValue)	\
    ( (This)->lpVtbl -> GetProperty(This,prop,pValue) ) 

#define ICbsSession10_AddPhaseBreak(This)	\
    ( (This)->lpVtbl -> AddPhaseBreak(This) ) 

#define ICbsSession10_FinalizeEx(This,__MIDL__ICbsSession70000,pRequiredAction)	\
    ( (This)->lpVtbl -> FinalizeEx(This,__MIDL__ICbsSession70000,pRequiredAction) ) 


#define ICbsSession10_AddSource(This,options,basePath)	\
    ( (This)->lpVtbl -> AddSource(This,options,basePath) ) 

#define ICbsSession10_RegisterCbsUIHandler(This,pUIHandler)	\
    ( (This)->lpVtbl -> RegisterCbsUIHandler(This,pUIHandler) ) 


#define ICbsSession10_CreateWindowsUpdatePackage(This,__MIDL__ICbsSession100000,__MIDL__ICbsSession100001,__MIDL__ICbsSession100002,__MIDL__ICbsSession100003,__MIDL__ICbsSession100004,__MIDL__ICbsSession100005,__MIDL__ICbsSession100006,__MIDL__ICbsSession100007,__MIDL__ICbsSession100008,__MIDL__ICbsSession100009,__MIDL__ICbsSession100010)	\
    ( (This)->lpVtbl -> CreateWindowsUpdatePackage(This,__MIDL__ICbsSession100000,__MIDL__ICbsSession100001,__MIDL__ICbsSession100002,__MIDL__ICbsSession100003,__MIDL__ICbsSession100004,__MIDL__ICbsSession100005,__MIDL__ICbsSession100006,__MIDL__ICbsSession100007,__MIDL__ICbsSession100008,__MIDL__ICbsSession100009,__MIDL__ICbsSession100010) ) 

#define ICbsSession10_EnumerateCapabilities(This,sourceFilter,szNamespace,szLang,szArch,dwMajor,dwMinor,__MIDL__ICbsSession100011)	\
    ( (This)->lpVtbl -> EnumerateCapabilities(This,sourceFilter,szNamespace,szLang,szArch,dwMajor,dwMinor,__MIDL__ICbsSession100011) ) 

#define ICbsSession10_InitializeEx(This,sessionOptions,sourceName,bootDrive,winDir,externalDir)	\
    ( (This)->lpVtbl -> InitializeEx(This,sessionOptions,sourceName,bootDrive,winDir,externalDir) ) 

#define ICbsSession10_CreateExternalTransformerExecutor(This,ppCsiExecutor)	\
    ( (This)->lpVtbl -> CreateExternalTransformerExecutor(This,ppCsiExecutor) ) 

#define ICbsSession10_ObserveSessions(This,options,pListener,__MIDL__ICbsSession100012)	\
    ( (This)->lpVtbl -> ObserveSessions(This,options,pListener,__MIDL__ICbsSession100012) ) 

#define ICbsSession10_GetActivities(This,options,__MIDL__ICbsSession100013)	\
    ( (This)->lpVtbl -> GetActivities(This,options,__MIDL__ICbsSession100013) ) 

#define ICbsSession10_SetEnhancedOptions(This,enhancedOptions)	\
    ( (This)->lpVtbl -> SetEnhancedOptions(This,enhancedOptions) ) 

#define ICbsSession10_SetProperty(This,prop,value)	\
    ( (This)->lpVtbl -> SetProperty(This,prop,value) ) 

#define ICbsSession10_PerformOperation(This,reserved,type)	\
    ( (This)->lpVtbl -> PerformOperation(This,reserved,type) ) 

#define ICbsSession10_SetClientToken(This,token)	\
    ( (This)->lpVtbl -> SetClientToken(This,token) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICbsSession10_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


