

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for C:\Users\7mile\AppData\Local\Temp\UFCase.Isolation.idl-fe4fc7ca:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628 
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

#ifndef __UFCase2EIsolation_p_h__
#define __UFCase2EIsolation_p_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef ____FIIterator_1_UFCase__CIsolation__CComponentFileModel_FWD_DEFINED__
#define ____FIIterator_1_UFCase__CIsolation__CComponentFileModel_FWD_DEFINED__
typedef interface __FIIterator_1_UFCase__CIsolation__CComponentFileModel __FIIterator_1_UFCase__CIsolation__CComponentFileModel;

#endif 	/* ____FIIterator_1_UFCase__CIsolation__CComponentFileModel_FWD_DEFINED__ */


#ifndef ____FIIterable_1_UFCase__CIsolation__CComponentFileModel_FWD_DEFINED__
#define ____FIIterable_1_UFCase__CIsolation__CComponentFileModel_FWD_DEFINED__
typedef interface __FIIterable_1_UFCase__CIsolation__CComponentFileModel __FIIterable_1_UFCase__CIsolation__CComponentFileModel;

#endif 	/* ____FIIterable_1_UFCase__CIsolation__CComponentFileModel_FWD_DEFINED__ */


#ifndef ____FIIterator_1_UFCase__CIsolation__CFeatureModel_FWD_DEFINED__
#define ____FIIterator_1_UFCase__CIsolation__CFeatureModel_FWD_DEFINED__
typedef interface __FIIterator_1_UFCase__CIsolation__CFeatureModel __FIIterator_1_UFCase__CIsolation__CFeatureModel;

#endif 	/* ____FIIterator_1_UFCase__CIsolation__CFeatureModel_FWD_DEFINED__ */


#ifndef ____FIIterable_1_UFCase__CIsolation__CFeatureModel_FWD_DEFINED__
#define ____FIIterable_1_UFCase__CIsolation__CFeatureModel_FWD_DEFINED__
typedef interface __FIIterable_1_UFCase__CIsolation__CFeatureModel __FIIterable_1_UFCase__CIsolation__CFeatureModel;

#endif 	/* ____FIIterable_1_UFCase__CIsolation__CFeatureModel_FWD_DEFINED__ */


#ifndef ____FIIterator_1_UFCase__CIsolation__CPackageModel_FWD_DEFINED__
#define ____FIIterator_1_UFCase__CIsolation__CPackageModel_FWD_DEFINED__
typedef interface __FIIterator_1_UFCase__CIsolation__CPackageModel __FIIterator_1_UFCase__CIsolation__CPackageModel;

#endif 	/* ____FIIterator_1_UFCase__CIsolation__CPackageModel_FWD_DEFINED__ */


#ifndef ____FIIterable_1_UFCase__CIsolation__CPackageModel_FWD_DEFINED__
#define ____FIIterable_1_UFCase__CIsolation__CPackageModel_FWD_DEFINED__
typedef interface __FIIterable_1_UFCase__CIsolation__CPackageModel __FIIterable_1_UFCase__CIsolation__CPackageModel;

#endif 	/* ____FIIterable_1_UFCase__CIsolation__CPackageModel_FWD_DEFINED__ */


#ifndef ____FIVectorView_1_UFCase__CIsolation__CPackageModel_FWD_DEFINED__
#define ____FIVectorView_1_UFCase__CIsolation__CPackageModel_FWD_DEFINED__
typedef interface __FIVectorView_1_UFCase__CIsolation__CPackageModel __FIVectorView_1_UFCase__CIsolation__CPackageModel;

#endif 	/* ____FIVectorView_1_UFCase__CIsolation__CPackageModel_FWD_DEFINED__ */


#ifndef ____FIVector_1_UFCase__CIsolation__CPackageModel_FWD_DEFINED__
#define ____FIVector_1_UFCase__CIsolation__CPackageModel_FWD_DEFINED__
typedef interface __FIVector_1_UFCase__CIsolation__CPackageModel __FIVector_1_UFCase__CIsolation__CPackageModel;

#endif 	/* ____FIVector_1_UFCase__CIsolation__CPackageModel_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CIsolation_CIComponentModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIComponentModel_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CIComponentModel __x_ABI_CUFCase_CIsolation_CIComponentModel;

#endif 	/* ____x_ABI_CUFCase_CIsolation_CIComponentModel_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CIsolation_CIFeatureModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIFeatureModel_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CIFeatureModel __x_ABI_CUFCase_CIsolation_CIFeatureModel;

#endif 	/* ____x_ABI_CUFCase_CIsolation_CIFeatureModel_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CIsolation_CIHost_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIHost_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CIHost __x_ABI_CUFCase_CIsolation_CIHost;

#endif 	/* ____x_ABI_CUFCase_CIsolation_CIHost_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CIsolation_CIHostManager_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIHostManager_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CIHostManager __x_ABI_CUFCase_CIsolation_CIHostManager;

#endif 	/* ____x_ABI_CUFCase_CIsolation_CIHostManager_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton;

#endif 	/* ____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CIsolation_CIImageModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIImageModel_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CIImageModel __x_ABI_CUFCase_CIsolation_CIImageModel;

#endif 	/* ____x_ABI_CUFCase_CIsolation_CIImageModel_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CIsolation_CIPackageModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIPackageModel_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CIPackageModel __x_ABI_CUFCase_CIsolation_CIPackageModel;

#endif 	/* ____x_ABI_CUFCase_CIsolation_CIPackageModel_FWD_DEFINED__ */


#ifndef ____FIAsyncActionProgressHandler_1_UINT32_FWD_DEFINED__
#define ____FIAsyncActionProgressHandler_1_UINT32_FWD_DEFINED__
typedef interface __FIAsyncActionProgressHandler_1_UINT32 __FIAsyncActionProgressHandler_1_UINT32;

#endif 	/* ____FIAsyncActionProgressHandler_1_UINT32_FWD_DEFINED__ */


#ifndef ____FIAsyncActionWithProgressCompletedHandler_1_UINT32_FWD_DEFINED__
#define ____FIAsyncActionWithProgressCompletedHandler_1_UINT32_FWD_DEFINED__
typedef interface __FIAsyncActionWithProgressCompletedHandler_1_UINT32 __FIAsyncActionWithProgressCompletedHandler_1_UINT32;

#endif 	/* ____FIAsyncActionWithProgressCompletedHandler_1_UINT32_FWD_DEFINED__ */


#ifndef ____FIAsyncActionWithProgress_1_UINT32_FWD_DEFINED__
#define ____FIAsyncActionWithProgress_1_UINT32_FWD_DEFINED__
typedef interface __FIAsyncActionWithProgress_1_UINT32 __FIAsyncActionWithProgress_1_UINT32;

#endif 	/* ____FIAsyncActionWithProgress_1_UINT32_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CIsolation_CISessionModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CISessionModel_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CISessionModel __x_ABI_CUFCase_CIsolation_CISessionModel;

#endif 	/* ____x_ABI_CUFCase_CIsolation_CISessionModel_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CIsolation_CIStoreModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIStoreModel_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CIStoreModel __x_ABI_CUFCase_CIsolation_CIStoreModel;

#endif 	/* ____x_ABI_CUFCase_CIsolation_CIStoreModel_FWD_DEFINED__ */


/* header files for imported files */
#include "inspectable.h"
#include "AsyncInfo.h"
#include "EventToken.h"
#include "Windows.Foundation.h"
#include "UFCase.Host.Manifest.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_UFCase2EIsolation_0000_0000 */
/* [local] */ 



























typedef enum __x_ABI_CUFCase_CIsolation_CCbsInstallState __x_ABI_CUFCase_CIsolation_CCbsInstallState;

typedef enum __x_ABI_CUFCase_CIsolation_CCbsOperationType __x_ABI_CUFCase_CIsolation_CCbsOperationType;

typedef enum __x_ABI_CUFCase_CIsolation_CCsiComponentStatus __x_ABI_CUFCase_CIsolation_CCsiComponentStatus;

typedef enum __x_ABI_CUFCase_CIsolation_CImageType __x_ABI_CUFCase_CIsolation_CImageType;

typedef struct __x_ABI_CUFCase_CIsolation_CComponentFileModel __x_ABI_CUFCase_CIsolation_CComponentFileModel;

typedef struct __x_ABI_CUFCase_CIsolation_CImageVersion __x_ABI_CUFCase_CIsolation_CImageVersion;










extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0000_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation2Eidl_0000_0220 */




extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0220_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0220_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation_0000_0001 */
/* [local] */ 

#ifndef DEF___FIIterator_1_UFCase__CIsolation__CComponentFileModel
#define DEF___FIIterator_1_UFCase__CIsolation__CComponentFileModel
#if !defined(__cplusplus) || defined(RO_NO_TEMPLATE_NAME)


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0001_v0_0_s_ifspec;

#ifndef ____FIIterator_1_UFCase__CIsolation__CComponentFileModel_INTERFACE_DEFINED__
#define ____FIIterator_1_UFCase__CIsolation__CComponentFileModel_INTERFACE_DEFINED__

/* interface __FIIterator_1_UFCase__CIsolation__CComponentFileModel */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID___FIIterator_1_UFCase__CIsolation__CComponentFileModel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3c2f62e6-ceef-59c0-9e0f-0266eb1744ca")
    __FIIterator_1_UFCase__CIsolation__CComponentFileModel : public IInspectable
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Current( 
            /* [retval][out] */ struct __x_ABI_CUFCase_CIsolation_CComponentFileModel *current) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_HasCurrent( 
            /* [retval][out] */ boolean *hasCurrent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveNext( 
            /* [retval][out] */ boolean *hasCurrent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMany( 
            /* [in] */ unsigned int capacity,
            /* [size_is][length_is][out] */ struct __x_ABI_CUFCase_CIsolation_CComponentFileModel *items,
            /* [retval][out] */ unsigned int *actual) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __FIIterator_1_UFCase__CIsolation__CComponentFileModelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__FIIterator_1_UFCase__CIsolation__CComponentFileModel, get_Current)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Current )( 
            __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This,
            /* [retval][out] */ struct __x_ABI_CUFCase_CIsolation_CComponentFileModel *current);
        
        DECLSPEC_XFGVIRT(__FIIterator_1_UFCase__CIsolation__CComponentFileModel, get_HasCurrent)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasCurrent )( 
            __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This,
            /* [retval][out] */ boolean *hasCurrent);
        
        DECLSPEC_XFGVIRT(__FIIterator_1_UFCase__CIsolation__CComponentFileModel, MoveNext)
        HRESULT ( STDMETHODCALLTYPE *MoveNext )( 
            __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This,
            /* [retval][out] */ boolean *hasCurrent);
        
        DECLSPEC_XFGVIRT(__FIIterator_1_UFCase__CIsolation__CComponentFileModel, GetMany)
        HRESULT ( STDMETHODCALLTYPE *GetMany )( 
            __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This,
            /* [in] */ unsigned int capacity,
            /* [size_is][length_is][out] */ struct __x_ABI_CUFCase_CIsolation_CComponentFileModel *items,
            /* [retval][out] */ unsigned int *actual);
        
        END_INTERFACE
    } __FIIterator_1_UFCase__CIsolation__CComponentFileModelVtbl;

    interface __FIIterator_1_UFCase__CIsolation__CComponentFileModel
    {
        CONST_VTBL struct __FIIterator_1_UFCase__CIsolation__CComponentFileModelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __FIIterator_1_UFCase__CIsolation__CComponentFileModel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterator_1_UFCase__CIsolation__CComponentFileModel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterator_1_UFCase__CIsolation__CComponentFileModel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterator_1_UFCase__CIsolation__CComponentFileModel_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterator_1_UFCase__CIsolation__CComponentFileModel_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterator_1_UFCase__CIsolation__CComponentFileModel_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterator_1_UFCase__CIsolation__CComponentFileModel_get_Current(This,current)	\
    ( (This)->lpVtbl -> get_Current(This,current) ) 

#define __FIIterator_1_UFCase__CIsolation__CComponentFileModel_get_HasCurrent(This,hasCurrent)	\
    ( (This)->lpVtbl -> get_HasCurrent(This,hasCurrent) ) 

#define __FIIterator_1_UFCase__CIsolation__CComponentFileModel_MoveNext(This,hasCurrent)	\
    ( (This)->lpVtbl -> MoveNext(This,hasCurrent) ) 

#define __FIIterator_1_UFCase__CIsolation__CComponentFileModel_GetMany(This,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,capacity,items,actual) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____FIIterator_1_UFCase__CIsolation__CComponentFileModel_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_UFCase2EIsolation_0000_0002 */
/* [local] */ 

#endif /* pinterface */
#endif /* DEF___FIIterator_1_UFCase__CIsolation__CComponentFileModel */


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0002_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation2Eidl_0000_0221 */




extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0221_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0221_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation_0000_0003 */
/* [local] */ 

#ifndef DEF___FIIterable_1_UFCase__CIsolation__CComponentFileModel
#define DEF___FIIterable_1_UFCase__CIsolation__CComponentFileModel
#if !defined(__cplusplus) || defined(RO_NO_TEMPLATE_NAME)


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0003_v0_0_s_ifspec;

#ifndef ____FIIterable_1_UFCase__CIsolation__CComponentFileModel_INTERFACE_DEFINED__
#define ____FIIterable_1_UFCase__CIsolation__CComponentFileModel_INTERFACE_DEFINED__

/* interface __FIIterable_1_UFCase__CIsolation__CComponentFileModel */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID___FIIterable_1_UFCase__CIsolation__CComponentFileModel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("abe0626b-7b6f-55e0-bdb5-477c4b37a8ef")
    __FIIterable_1_UFCase__CIsolation__CComponentFileModel : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE First( 
            /* [retval][out] */ __FIIterator_1_UFCase__CIsolation__CComponentFileModel **first) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __FIIterable_1_UFCase__CIsolation__CComponentFileModelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __FIIterable_1_UFCase__CIsolation__CComponentFileModel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __FIIterable_1_UFCase__CIsolation__CComponentFileModel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __FIIterable_1_UFCase__CIsolation__CComponentFileModel * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __FIIterable_1_UFCase__CIsolation__CComponentFileModel * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __FIIterable_1_UFCase__CIsolation__CComponentFileModel * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __FIIterable_1_UFCase__CIsolation__CComponentFileModel * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__FIIterable_1_UFCase__CIsolation__CComponentFileModel, First)
        HRESULT ( STDMETHODCALLTYPE *First )( 
            __FIIterable_1_UFCase__CIsolation__CComponentFileModel * This,
            /* [retval][out] */ __FIIterator_1_UFCase__CIsolation__CComponentFileModel **first);
        
        END_INTERFACE
    } __FIIterable_1_UFCase__CIsolation__CComponentFileModelVtbl;

    interface __FIIterable_1_UFCase__CIsolation__CComponentFileModel
    {
        CONST_VTBL struct __FIIterable_1_UFCase__CIsolation__CComponentFileModelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __FIIterable_1_UFCase__CIsolation__CComponentFileModel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterable_1_UFCase__CIsolation__CComponentFileModel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterable_1_UFCase__CIsolation__CComponentFileModel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterable_1_UFCase__CIsolation__CComponentFileModel_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterable_1_UFCase__CIsolation__CComponentFileModel_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterable_1_UFCase__CIsolation__CComponentFileModel_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterable_1_UFCase__CIsolation__CComponentFileModel_First(This,first)	\
    ( (This)->lpVtbl -> First(This,first) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____FIIterable_1_UFCase__CIsolation__CComponentFileModel_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_UFCase2EIsolation_0000_0004 */
/* [local] */ 

#endif /* pinterface */
#endif /* DEF___FIIterable_1_UFCase__CIsolation__CComponentFileModel */


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0004_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation2Eidl_0000_0222 */




extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0222_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0222_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation_0000_0005 */
/* [local] */ 

#ifndef DEF___FIIterator_1_UFCase__CIsolation__CFeatureModel
#define DEF___FIIterator_1_UFCase__CIsolation__CFeatureModel
#if !defined(__cplusplus) || defined(RO_NO_TEMPLATE_NAME)


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0005_v0_0_s_ifspec;

#ifndef ____FIIterator_1_UFCase__CIsolation__CFeatureModel_INTERFACE_DEFINED__
#define ____FIIterator_1_UFCase__CIsolation__CFeatureModel_INTERFACE_DEFINED__

/* interface __FIIterator_1_UFCase__CIsolation__CFeatureModel */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID___FIIterator_1_UFCase__CIsolation__CFeatureModel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fdae1372-766b-5f3c-bc67-7b204817278a")
    __FIIterator_1_UFCase__CIsolation__CFeatureModel : public IInspectable
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Current( 
            /* [retval][out] */ __x_ABI_CUFCase_CIsolation_CIFeatureModel **current) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_HasCurrent( 
            /* [retval][out] */ boolean *hasCurrent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveNext( 
            /* [retval][out] */ boolean *hasCurrent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMany( 
            /* [in] */ unsigned int capacity,
            /* [size_is][length_is][out] */ __x_ABI_CUFCase_CIsolation_CIFeatureModel **items,
            /* [retval][out] */ unsigned int *actual) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __FIIterator_1_UFCase__CIsolation__CFeatureModelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __FIIterator_1_UFCase__CIsolation__CFeatureModel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __FIIterator_1_UFCase__CIsolation__CFeatureModel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __FIIterator_1_UFCase__CIsolation__CFeatureModel * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __FIIterator_1_UFCase__CIsolation__CFeatureModel * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __FIIterator_1_UFCase__CIsolation__CFeatureModel * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __FIIterator_1_UFCase__CIsolation__CFeatureModel * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__FIIterator_1_UFCase__CIsolation__CFeatureModel, get_Current)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Current )( 
            __FIIterator_1_UFCase__CIsolation__CFeatureModel * This,
            /* [retval][out] */ __x_ABI_CUFCase_CIsolation_CIFeatureModel **current);
        
        DECLSPEC_XFGVIRT(__FIIterator_1_UFCase__CIsolation__CFeatureModel, get_HasCurrent)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasCurrent )( 
            __FIIterator_1_UFCase__CIsolation__CFeatureModel * This,
            /* [retval][out] */ boolean *hasCurrent);
        
        DECLSPEC_XFGVIRT(__FIIterator_1_UFCase__CIsolation__CFeatureModel, MoveNext)
        HRESULT ( STDMETHODCALLTYPE *MoveNext )( 
            __FIIterator_1_UFCase__CIsolation__CFeatureModel * This,
            /* [retval][out] */ boolean *hasCurrent);
        
        DECLSPEC_XFGVIRT(__FIIterator_1_UFCase__CIsolation__CFeatureModel, GetMany)
        HRESULT ( STDMETHODCALLTYPE *GetMany )( 
            __FIIterator_1_UFCase__CIsolation__CFeatureModel * This,
            /* [in] */ unsigned int capacity,
            /* [size_is][length_is][out] */ __x_ABI_CUFCase_CIsolation_CIFeatureModel **items,
            /* [retval][out] */ unsigned int *actual);
        
        END_INTERFACE
    } __FIIterator_1_UFCase__CIsolation__CFeatureModelVtbl;

    interface __FIIterator_1_UFCase__CIsolation__CFeatureModel
    {
        CONST_VTBL struct __FIIterator_1_UFCase__CIsolation__CFeatureModelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __FIIterator_1_UFCase__CIsolation__CFeatureModel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterator_1_UFCase__CIsolation__CFeatureModel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterator_1_UFCase__CIsolation__CFeatureModel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterator_1_UFCase__CIsolation__CFeatureModel_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterator_1_UFCase__CIsolation__CFeatureModel_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterator_1_UFCase__CIsolation__CFeatureModel_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterator_1_UFCase__CIsolation__CFeatureModel_get_Current(This,current)	\
    ( (This)->lpVtbl -> get_Current(This,current) ) 

#define __FIIterator_1_UFCase__CIsolation__CFeatureModel_get_HasCurrent(This,hasCurrent)	\
    ( (This)->lpVtbl -> get_HasCurrent(This,hasCurrent) ) 

#define __FIIterator_1_UFCase__CIsolation__CFeatureModel_MoveNext(This,hasCurrent)	\
    ( (This)->lpVtbl -> MoveNext(This,hasCurrent) ) 

#define __FIIterator_1_UFCase__CIsolation__CFeatureModel_GetMany(This,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,capacity,items,actual) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____FIIterator_1_UFCase__CIsolation__CFeatureModel_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_UFCase2EIsolation_0000_0006 */
/* [local] */ 

#endif /* pinterface */
#endif /* DEF___FIIterator_1_UFCase__CIsolation__CFeatureModel */


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0006_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0006_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation2Eidl_0000_0223 */




extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0223_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0223_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation_0000_0007 */
/* [local] */ 

#ifndef DEF___FIIterable_1_UFCase__CIsolation__CFeatureModel
#define DEF___FIIterable_1_UFCase__CIsolation__CFeatureModel
#if !defined(__cplusplus) || defined(RO_NO_TEMPLATE_NAME)


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0007_v0_0_s_ifspec;

#ifndef ____FIIterable_1_UFCase__CIsolation__CFeatureModel_INTERFACE_DEFINED__
#define ____FIIterable_1_UFCase__CIsolation__CFeatureModel_INTERFACE_DEFINED__

/* interface __FIIterable_1_UFCase__CIsolation__CFeatureModel */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID___FIIterable_1_UFCase__CIsolation__CFeatureModel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ac8feca1-7324-5ab9-bb20-9b3eeb2d3e13")
    __FIIterable_1_UFCase__CIsolation__CFeatureModel : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE First( 
            /* [retval][out] */ __FIIterator_1_UFCase__CIsolation__CFeatureModel **first) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __FIIterable_1_UFCase__CIsolation__CFeatureModelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __FIIterable_1_UFCase__CIsolation__CFeatureModel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __FIIterable_1_UFCase__CIsolation__CFeatureModel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __FIIterable_1_UFCase__CIsolation__CFeatureModel * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __FIIterable_1_UFCase__CIsolation__CFeatureModel * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __FIIterable_1_UFCase__CIsolation__CFeatureModel * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __FIIterable_1_UFCase__CIsolation__CFeatureModel * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__FIIterable_1_UFCase__CIsolation__CFeatureModel, First)
        HRESULT ( STDMETHODCALLTYPE *First )( 
            __FIIterable_1_UFCase__CIsolation__CFeatureModel * This,
            /* [retval][out] */ __FIIterator_1_UFCase__CIsolation__CFeatureModel **first);
        
        END_INTERFACE
    } __FIIterable_1_UFCase__CIsolation__CFeatureModelVtbl;

    interface __FIIterable_1_UFCase__CIsolation__CFeatureModel
    {
        CONST_VTBL struct __FIIterable_1_UFCase__CIsolation__CFeatureModelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __FIIterable_1_UFCase__CIsolation__CFeatureModel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterable_1_UFCase__CIsolation__CFeatureModel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterable_1_UFCase__CIsolation__CFeatureModel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterable_1_UFCase__CIsolation__CFeatureModel_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterable_1_UFCase__CIsolation__CFeatureModel_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterable_1_UFCase__CIsolation__CFeatureModel_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterable_1_UFCase__CIsolation__CFeatureModel_First(This,first)	\
    ( (This)->lpVtbl -> First(This,first) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____FIIterable_1_UFCase__CIsolation__CFeatureModel_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_UFCase2EIsolation_0000_0008 */
/* [local] */ 

#endif /* pinterface */
#endif /* DEF___FIIterable_1_UFCase__CIsolation__CFeatureModel */


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0008_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0008_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation2Eidl_0000_0224 */




extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0224_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0224_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation_0000_0009 */
/* [local] */ 

#ifndef DEF___FIIterator_1_UFCase__CIsolation__CPackageModel
#define DEF___FIIterator_1_UFCase__CIsolation__CPackageModel
#if !defined(__cplusplus) || defined(RO_NO_TEMPLATE_NAME)


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0009_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0009_v0_0_s_ifspec;

#ifndef ____FIIterator_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__
#define ____FIIterator_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__

/* interface __FIIterator_1_UFCase__CIsolation__CPackageModel */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID___FIIterator_1_UFCase__CIsolation__CPackageModel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("42f6edef-e12b-5dc0-a465-71eb9a214348")
    __FIIterator_1_UFCase__CIsolation__CPackageModel : public IInspectable
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Current( 
            /* [retval][out] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **current) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_HasCurrent( 
            /* [retval][out] */ boolean *hasCurrent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveNext( 
            /* [retval][out] */ boolean *hasCurrent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMany( 
            /* [in] */ unsigned int capacity,
            /* [size_is][length_is][out] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **items,
            /* [retval][out] */ unsigned int *actual) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __FIIterator_1_UFCase__CIsolation__CPackageModelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __FIIterator_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __FIIterator_1_UFCase__CIsolation__CPackageModel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __FIIterator_1_UFCase__CIsolation__CPackageModel * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __FIIterator_1_UFCase__CIsolation__CPackageModel * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __FIIterator_1_UFCase__CIsolation__CPackageModel * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __FIIterator_1_UFCase__CIsolation__CPackageModel * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__FIIterator_1_UFCase__CIsolation__CPackageModel, get_Current)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Current )( 
            __FIIterator_1_UFCase__CIsolation__CPackageModel * This,
            /* [retval][out] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **current);
        
        DECLSPEC_XFGVIRT(__FIIterator_1_UFCase__CIsolation__CPackageModel, get_HasCurrent)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasCurrent )( 
            __FIIterator_1_UFCase__CIsolation__CPackageModel * This,
            /* [retval][out] */ boolean *hasCurrent);
        
        DECLSPEC_XFGVIRT(__FIIterator_1_UFCase__CIsolation__CPackageModel, MoveNext)
        HRESULT ( STDMETHODCALLTYPE *MoveNext )( 
            __FIIterator_1_UFCase__CIsolation__CPackageModel * This,
            /* [retval][out] */ boolean *hasCurrent);
        
        DECLSPEC_XFGVIRT(__FIIterator_1_UFCase__CIsolation__CPackageModel, GetMany)
        HRESULT ( STDMETHODCALLTYPE *GetMany )( 
            __FIIterator_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ unsigned int capacity,
            /* [size_is][length_is][out] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **items,
            /* [retval][out] */ unsigned int *actual);
        
        END_INTERFACE
    } __FIIterator_1_UFCase__CIsolation__CPackageModelVtbl;

    interface __FIIterator_1_UFCase__CIsolation__CPackageModel
    {
        CONST_VTBL struct __FIIterator_1_UFCase__CIsolation__CPackageModelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __FIIterator_1_UFCase__CIsolation__CPackageModel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterator_1_UFCase__CIsolation__CPackageModel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterator_1_UFCase__CIsolation__CPackageModel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterator_1_UFCase__CIsolation__CPackageModel_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterator_1_UFCase__CIsolation__CPackageModel_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterator_1_UFCase__CIsolation__CPackageModel_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterator_1_UFCase__CIsolation__CPackageModel_get_Current(This,current)	\
    ( (This)->lpVtbl -> get_Current(This,current) ) 

#define __FIIterator_1_UFCase__CIsolation__CPackageModel_get_HasCurrent(This,hasCurrent)	\
    ( (This)->lpVtbl -> get_HasCurrent(This,hasCurrent) ) 

#define __FIIterator_1_UFCase__CIsolation__CPackageModel_MoveNext(This,hasCurrent)	\
    ( (This)->lpVtbl -> MoveNext(This,hasCurrent) ) 

#define __FIIterator_1_UFCase__CIsolation__CPackageModel_GetMany(This,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,capacity,items,actual) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____FIIterator_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_UFCase2EIsolation_0000_0010 */
/* [local] */ 

#endif /* pinterface */
#endif /* DEF___FIIterator_1_UFCase__CIsolation__CPackageModel */


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0010_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0010_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation2Eidl_0000_0225 */




extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0225_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0225_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation_0000_0011 */
/* [local] */ 

#ifndef DEF___FIIterable_1_UFCase__CIsolation__CPackageModel
#define DEF___FIIterable_1_UFCase__CIsolation__CPackageModel
#if !defined(__cplusplus) || defined(RO_NO_TEMPLATE_NAME)


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0011_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0011_v0_0_s_ifspec;

#ifndef ____FIIterable_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__
#define ____FIIterable_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__

/* interface __FIIterable_1_UFCase__CIsolation__CPackageModel */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID___FIIterable_1_UFCase__CIsolation__CPackageModel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("74190d90-0318-5822-887e-647d3e14a48b")
    __FIIterable_1_UFCase__CIsolation__CPackageModel : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE First( 
            /* [retval][out] */ __FIIterator_1_UFCase__CIsolation__CPackageModel **first) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __FIIterable_1_UFCase__CIsolation__CPackageModelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __FIIterable_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __FIIterable_1_UFCase__CIsolation__CPackageModel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __FIIterable_1_UFCase__CIsolation__CPackageModel * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __FIIterable_1_UFCase__CIsolation__CPackageModel * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __FIIterable_1_UFCase__CIsolation__CPackageModel * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __FIIterable_1_UFCase__CIsolation__CPackageModel * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__FIIterable_1_UFCase__CIsolation__CPackageModel, First)
        HRESULT ( STDMETHODCALLTYPE *First )( 
            __FIIterable_1_UFCase__CIsolation__CPackageModel * This,
            /* [retval][out] */ __FIIterator_1_UFCase__CIsolation__CPackageModel **first);
        
        END_INTERFACE
    } __FIIterable_1_UFCase__CIsolation__CPackageModelVtbl;

    interface __FIIterable_1_UFCase__CIsolation__CPackageModel
    {
        CONST_VTBL struct __FIIterable_1_UFCase__CIsolation__CPackageModelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __FIIterable_1_UFCase__CIsolation__CPackageModel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterable_1_UFCase__CIsolation__CPackageModel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterable_1_UFCase__CIsolation__CPackageModel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterable_1_UFCase__CIsolation__CPackageModel_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterable_1_UFCase__CIsolation__CPackageModel_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterable_1_UFCase__CIsolation__CPackageModel_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterable_1_UFCase__CIsolation__CPackageModel_First(This,first)	\
    ( (This)->lpVtbl -> First(This,first) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____FIIterable_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_UFCase2EIsolation_0000_0012 */
/* [local] */ 

#endif /* pinterface */
#endif /* DEF___FIIterable_1_UFCase__CIsolation__CPackageModel */


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0012_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0012_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation2Eidl_0000_0226 */




extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0226_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0226_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation_0000_0013 */
/* [local] */ 

#ifndef DEF___FIVectorView_1_UFCase__CIsolation__CPackageModel
#define DEF___FIVectorView_1_UFCase__CIsolation__CPackageModel
#if !defined(__cplusplus) || defined(RO_NO_TEMPLATE_NAME)


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0013_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0013_v0_0_s_ifspec;

#ifndef ____FIVectorView_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__
#define ____FIVectorView_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__

/* interface __FIVectorView_1_UFCase__CIsolation__CPackageModel */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID___FIVectorView_1_UFCase__CIsolation__CPackageModel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ebc2dec9-269f-5e42-87da-327f66aa61b6")
    __FIVectorView_1_UFCase__CIsolation__CPackageModel : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAt( 
            /* [in] */ unsigned int index,
            /* [retval][out] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **item) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ unsigned int *size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IndexOf( 
            /* [in] */ __x_ABI_CUFCase_CIsolation_CIPackageModel *item,
            /* [out] */ unsigned int *index,
            /* [retval][out] */ boolean *found) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMany( 
            /* [in] */ unsigned int startIndex,
            /* [in] */ unsigned int capacity,
            /* [size_is][length_is][out] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **items,
            /* [retval][out] */ unsigned int *actual) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __FIVectorView_1_UFCase__CIsolation__CPackageModelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __FIVectorView_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __FIVectorView_1_UFCase__CIsolation__CPackageModel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __FIVectorView_1_UFCase__CIsolation__CPackageModel * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __FIVectorView_1_UFCase__CIsolation__CPackageModel * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __FIVectorView_1_UFCase__CIsolation__CPackageModel * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __FIVectorView_1_UFCase__CIsolation__CPackageModel * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__FIVectorView_1_UFCase__CIsolation__CPackageModel, GetAt)
        HRESULT ( STDMETHODCALLTYPE *GetAt )( 
            __FIVectorView_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ unsigned int index,
            /* [retval][out] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **item);
        
        DECLSPEC_XFGVIRT(__FIVectorView_1_UFCase__CIsolation__CPackageModel, get_Size)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            __FIVectorView_1_UFCase__CIsolation__CPackageModel * This,
            /* [retval][out] */ unsigned int *size);
        
        DECLSPEC_XFGVIRT(__FIVectorView_1_UFCase__CIsolation__CPackageModel, IndexOf)
        HRESULT ( STDMETHODCALLTYPE *IndexOf )( 
            __FIVectorView_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ __x_ABI_CUFCase_CIsolation_CIPackageModel *item,
            /* [out] */ unsigned int *index,
            /* [retval][out] */ boolean *found);
        
        DECLSPEC_XFGVIRT(__FIVectorView_1_UFCase__CIsolation__CPackageModel, GetMany)
        HRESULT ( STDMETHODCALLTYPE *GetMany )( 
            __FIVectorView_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ unsigned int startIndex,
            /* [in] */ unsigned int capacity,
            /* [size_is][length_is][out] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **items,
            /* [retval][out] */ unsigned int *actual);
        
        END_INTERFACE
    } __FIVectorView_1_UFCase__CIsolation__CPackageModelVtbl;

    interface __FIVectorView_1_UFCase__CIsolation__CPackageModel
    {
        CONST_VTBL struct __FIVectorView_1_UFCase__CIsolation__CPackageModelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __FIVectorView_1_UFCase__CIsolation__CPackageModel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIVectorView_1_UFCase__CIsolation__CPackageModel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIVectorView_1_UFCase__CIsolation__CPackageModel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIVectorView_1_UFCase__CIsolation__CPackageModel_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIVectorView_1_UFCase__CIsolation__CPackageModel_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIVectorView_1_UFCase__CIsolation__CPackageModel_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIVectorView_1_UFCase__CIsolation__CPackageModel_GetAt(This,index,item)	\
    ( (This)->lpVtbl -> GetAt(This,index,item) ) 

#define __FIVectorView_1_UFCase__CIsolation__CPackageModel_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define __FIVectorView_1_UFCase__CIsolation__CPackageModel_IndexOf(This,item,index,found)	\
    ( (This)->lpVtbl -> IndexOf(This,item,index,found) ) 

#define __FIVectorView_1_UFCase__CIsolation__CPackageModel_GetMany(This,startIndex,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,startIndex,capacity,items,actual) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____FIVectorView_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_UFCase2EIsolation_0000_0014 */
/* [local] */ 

#endif /* pinterface */
#endif /* DEF___FIVectorView_1_UFCase__CIsolation__CPackageModel */


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0014_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0014_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation2Eidl_0000_0227 */




extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0227_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0227_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation_0000_0015 */
/* [local] */ 

#ifndef DEF___FIVector_1_UFCase__CIsolation__CPackageModel
#define DEF___FIVector_1_UFCase__CIsolation__CPackageModel
#if !defined(__cplusplus) || defined(RO_NO_TEMPLATE_NAME)


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0015_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0015_v0_0_s_ifspec;

#ifndef ____FIVector_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__
#define ____FIVector_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__

/* interface __FIVector_1_UFCase__CIsolation__CPackageModel */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID___FIVector_1_UFCase__CIsolation__CPackageModel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("88b85353-1699-5fa2-8b7c-21c66dba1f4a")
    __FIVector_1_UFCase__CIsolation__CPackageModel : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAt( 
            /* [in] */ unsigned int index,
            /* [retval][out] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **item) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ unsigned int *size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetView( 
            /* [retval][out] */ __FIVectorView_1_UFCase__CIsolation__CPackageModel **view) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IndexOf( 
            /* [in] */ __x_ABI_CUFCase_CIsolation_CIPackageModel *item,
            /* [out] */ unsigned int *index,
            /* [retval][out] */ boolean *found) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAt( 
            /* [in] */ unsigned int index,
            /* [in] */ __x_ABI_CUFCase_CIsolation_CIPackageModel *item) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertAt( 
            /* [in] */ unsigned int index,
            /* [in] */ __x_ABI_CUFCase_CIsolation_CIPackageModel *item) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveAt( 
            /* [in] */ unsigned int index) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Append( 
            /* [in] */ __x_ABI_CUFCase_CIsolation_CIPackageModel *item) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveAtEnd( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMany( 
            /* [in] */ unsigned int startIndex,
            /* [in] */ unsigned int capacity,
            /* [size_is][length_is][out] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **items,
            /* [retval][out] */ unsigned int *actual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReplaceAll( 
            /* [in] */ unsigned int count,
            /* [size_is][in] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __FIVector_1_UFCase__CIsolation__CPackageModelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__FIVector_1_UFCase__CIsolation__CPackageModel, GetAt)
        HRESULT ( STDMETHODCALLTYPE *GetAt )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ unsigned int index,
            /* [retval][out] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **item);
        
        DECLSPEC_XFGVIRT(__FIVector_1_UFCase__CIsolation__CPackageModel, get_Size)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This,
            /* [retval][out] */ unsigned int *size);
        
        DECLSPEC_XFGVIRT(__FIVector_1_UFCase__CIsolation__CPackageModel, GetView)
        HRESULT ( STDMETHODCALLTYPE *GetView )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This,
            /* [retval][out] */ __FIVectorView_1_UFCase__CIsolation__CPackageModel **view);
        
        DECLSPEC_XFGVIRT(__FIVector_1_UFCase__CIsolation__CPackageModel, IndexOf)
        HRESULT ( STDMETHODCALLTYPE *IndexOf )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ __x_ABI_CUFCase_CIsolation_CIPackageModel *item,
            /* [out] */ unsigned int *index,
            /* [retval][out] */ boolean *found);
        
        DECLSPEC_XFGVIRT(__FIVector_1_UFCase__CIsolation__CPackageModel, SetAt)
        HRESULT ( STDMETHODCALLTYPE *SetAt )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ unsigned int index,
            /* [in] */ __x_ABI_CUFCase_CIsolation_CIPackageModel *item);
        
        DECLSPEC_XFGVIRT(__FIVector_1_UFCase__CIsolation__CPackageModel, InsertAt)
        HRESULT ( STDMETHODCALLTYPE *InsertAt )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ unsigned int index,
            /* [in] */ __x_ABI_CUFCase_CIsolation_CIPackageModel *item);
        
        DECLSPEC_XFGVIRT(__FIVector_1_UFCase__CIsolation__CPackageModel, RemoveAt)
        HRESULT ( STDMETHODCALLTYPE *RemoveAt )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ unsigned int index);
        
        DECLSPEC_XFGVIRT(__FIVector_1_UFCase__CIsolation__CPackageModel, Append)
        HRESULT ( STDMETHODCALLTYPE *Append )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ __x_ABI_CUFCase_CIsolation_CIPackageModel *item);
        
        DECLSPEC_XFGVIRT(__FIVector_1_UFCase__CIsolation__CPackageModel, RemoveAtEnd)
        HRESULT ( STDMETHODCALLTYPE *RemoveAtEnd )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This);
        
        DECLSPEC_XFGVIRT(__FIVector_1_UFCase__CIsolation__CPackageModel, Clear)
        HRESULT ( STDMETHODCALLTYPE *Clear )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This);
        
        DECLSPEC_XFGVIRT(__FIVector_1_UFCase__CIsolation__CPackageModel, GetMany)
        HRESULT ( STDMETHODCALLTYPE *GetMany )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ unsigned int startIndex,
            /* [in] */ unsigned int capacity,
            /* [size_is][length_is][out] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **items,
            /* [retval][out] */ unsigned int *actual);
        
        DECLSPEC_XFGVIRT(__FIVector_1_UFCase__CIsolation__CPackageModel, ReplaceAll)
        HRESULT ( STDMETHODCALLTYPE *ReplaceAll )( 
            __FIVector_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ unsigned int count,
            /* [size_is][in] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **value);
        
        END_INTERFACE
    } __FIVector_1_UFCase__CIsolation__CPackageModelVtbl;

    interface __FIVector_1_UFCase__CIsolation__CPackageModel
    {
        CONST_VTBL struct __FIVector_1_UFCase__CIsolation__CPackageModelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __FIVector_1_UFCase__CIsolation__CPackageModel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIVector_1_UFCase__CIsolation__CPackageModel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIVector_1_UFCase__CIsolation__CPackageModel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIVector_1_UFCase__CIsolation__CPackageModel_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIVector_1_UFCase__CIsolation__CPackageModel_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIVector_1_UFCase__CIsolation__CPackageModel_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIVector_1_UFCase__CIsolation__CPackageModel_GetAt(This,index,item)	\
    ( (This)->lpVtbl -> GetAt(This,index,item) ) 

#define __FIVector_1_UFCase__CIsolation__CPackageModel_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define __FIVector_1_UFCase__CIsolation__CPackageModel_GetView(This,view)	\
    ( (This)->lpVtbl -> GetView(This,view) ) 

#define __FIVector_1_UFCase__CIsolation__CPackageModel_IndexOf(This,item,index,found)	\
    ( (This)->lpVtbl -> IndexOf(This,item,index,found) ) 

#define __FIVector_1_UFCase__CIsolation__CPackageModel_SetAt(This,index,item)	\
    ( (This)->lpVtbl -> SetAt(This,index,item) ) 

#define __FIVector_1_UFCase__CIsolation__CPackageModel_InsertAt(This,index,item)	\
    ( (This)->lpVtbl -> InsertAt(This,index,item) ) 

#define __FIVector_1_UFCase__CIsolation__CPackageModel_RemoveAt(This,index)	\
    ( (This)->lpVtbl -> RemoveAt(This,index) ) 

#define __FIVector_1_UFCase__CIsolation__CPackageModel_Append(This,item)	\
    ( (This)->lpVtbl -> Append(This,item) ) 

#define __FIVector_1_UFCase__CIsolation__CPackageModel_RemoveAtEnd(This)	\
    ( (This)->lpVtbl -> RemoveAtEnd(This) ) 

#define __FIVector_1_UFCase__CIsolation__CPackageModel_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define __FIVector_1_UFCase__CIsolation__CPackageModel_GetMany(This,startIndex,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,startIndex,capacity,items,actual) ) 

#define __FIVector_1_UFCase__CIsolation__CPackageModel_ReplaceAll(This,count,value)	\
    ( (This)->lpVtbl -> ReplaceAll(This,count,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____FIVector_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_UFCase2EIsolation_0000_0016 */
/* [local] */ 

#endif /* pinterface */
#endif /* DEF___FIVector_1_UFCase__CIsolation__CPackageModel */
/* [v1_enum] */ 
enum __x_ABI_CUFCase_CIsolation_CCbsInstallState
    {
        CbsInstallState_CbsInstallStatePartiallyInstalled	= -19,
        CbsInstallState_CbsInstallStateCancel	= -18,
        CbsInstallState_CbsInstallStateSuperseded	= -17,
        CbsInstallState_CbsInstallStateDefault	= -16,
        CbsInstallState_CbsInvalidStatePermanent	= -8,
        CbsInstallState_CbsInvalidStateInstalled	= -7,
        CbsInstallState_CbsInvalidStateStaged	= -4,
        CbsInstallState_CbsInvalidStateResolved	= -2,
        CbsInstallState_CbsInstallStateUnknown	= -1,
        CbsInstallState_CbsInstallStateAbsent	= 0,
        CbsInstallState_CbsInstallStateResolving	= 1,
        CbsInstallState_CbsInstallStateResolved	= 2,
        CbsInstallState_CbsInstallStateStaging	= 3,
        CbsInstallState_CbsInstallStateStaged	= 4,
        CbsInstallState_CbsInstallStateUninstallRequested	= 5,
        CbsInstallState_CbsInstallStateInstallRequested	= 6,
        CbsInstallState_CbsInstallStateInstalled	= 7,
        CbsInstallState_CbsInstallStatePermanent	= 8,
        CbsInstallState_CbsInstallStateInvalid	= 2147483647
    } ;
/* [v1_enum] */ 
enum __x_ABI_CUFCase_CIsolation_CCbsOperationType
    {
        CbsOperationType_ExportRepository	= 1,
        CbsOperationType_UpdateImage	= 2,
        CbsOperationType_PerformPrepareServicingOperation	= 3,
        CbsOperationType_PerformLateAcquisitionOperation	= 4,
        CbsOperationType_InitICSIStore	= 8
    } ;
/* [v1_enum] */ 
enum __x_ABI_CUFCase_CIsolation_CCsiComponentStatus
    {
        CsiComponentStatus_Prestaged	= 1,
        CsiComponentStatus_Staged	= 2,
        CsiComponentStatus_Pinned	= 3,
        CsiComponentStatus_Installed	= 4,
        CsiComponentStatus_InstalledMismatch	= 5
    } ;
/* [v1_enum] */ 
enum __x_ABI_CUFCase_CIsolation_CImageType
    {
        ImageType_Online	= 0,
        ImageType_Offline	= 1
    } ;
struct __x_ABI_CUFCase_CIsolation_CComponentFileModel
    {
    HSTRING Name;
    HSTRING Status;
    } ;
struct __x_ABI_CUFCase_CIsolation_CImageVersion
    {
    UINT32 Major;
    UINT32 Minor;
    UINT32 Build;
    UINT32 Revision;
    } ;


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0016_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0016_v0_0_s_ifspec;

#ifndef ____x_ABI_CUFCase_CIsolation_CIComponentModel_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIComponentModel_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CIsolation_CIComponentModel */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIComponentModel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("792DF753-4ACE-5718-A4D4-EB96A6454C5A")
    __x_ABI_CUFCase_CIsolation_CIComponentModel : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAttribute( 
            /* [in] */ HSTRING name,
            /* [out][retval] */ HSTRING *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttribute2( 
            /* [in] */ HSTRING name_space,
            /* [in] */ HSTRING name,
            /* [out][retval] */ HSTRING *result) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_TextForm( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_KeyForm( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Manifest( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CookedManifest( 
            /* [out][retval] */ __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass **value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CCsiComponentStatus *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_PayloadPath( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileCollection( 
            /* [in] */ UINT32 dwFlags,
            /* [out][retval] */ __FIIterable_1_UFCase__CIsolation__CComponentFileModel **result) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CIsolation_CIComponentModelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CIsolation_CIComponentModel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CIsolation_CIComponentModel * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIComponentModel, GetAttribute)
        HRESULT ( STDMETHODCALLTYPE *GetAttribute )( 
            __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
            /* [in] */ HSTRING name,
            /* [out][retval] */ HSTRING *result);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIComponentModel, GetAttribute2)
        HRESULT ( STDMETHODCALLTYPE *GetAttribute2 )( 
            __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
            /* [in] */ HSTRING name_space,
            /* [in] */ HSTRING name,
            /* [out][retval] */ HSTRING *result);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIComponentModel, get_TextForm)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_TextForm )( 
            __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIComponentModel, get_KeyForm)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_KeyForm )( 
            __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIComponentModel, get_Manifest)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Manifest )( 
            __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIComponentModel, get_CookedManifest)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CookedManifest )( 
            __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
            /* [out][retval] */ __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass **value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIComponentModel, get_Status)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CCsiComponentStatus *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIComponentModel, get_PayloadPath)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_PayloadPath )( 
            __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIComponentModel, GetFileCollection)
        HRESULT ( STDMETHODCALLTYPE *GetFileCollection )( 
            __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
            /* [in] */ UINT32 dwFlags,
            /* [out][retval] */ __FIIterable_1_UFCase__CIsolation__CComponentFileModel **result);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CIsolation_CIComponentModelVtbl;

    interface __x_ABI_CUFCase_CIsolation_CIComponentModel
    {
        CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CIComponentModelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CIsolation_CIComponentModel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CIsolation_CIComponentModel_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CUFCase_CIsolation_CIComponentModel_GetAttribute(This,name,result)	\
    ( (This)->lpVtbl -> GetAttribute(This,name,result) ) 

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_GetAttribute2(This,name_space,name,result)	\
    ( (This)->lpVtbl -> GetAttribute2(This,name_space,name,result) ) 

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_get_TextForm(This,value)	\
    ( (This)->lpVtbl -> get_TextForm(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_get_KeyForm(This,value)	\
    ( (This)->lpVtbl -> get_KeyForm(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_get_Manifest(This,value)	\
    ( (This)->lpVtbl -> get_Manifest(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_get_CookedManifest(This,value)	\
    ( (This)->lpVtbl -> get_CookedManifest(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_get_Status(This,value)	\
    ( (This)->lpVtbl -> get_Status(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_get_PayloadPath(This,value)	\
    ( (This)->lpVtbl -> get_PayloadPath(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_GetFileCollection(This,dwFlags,result)	\
    ( (This)->lpVtbl -> GetFileCollection(This,dwFlags,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CIsolation_CIComponentModel_INTERFACE_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CIsolation_CIFeatureModel_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIFeatureModel_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CIsolation_CIFeatureModel */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIFeatureModel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4DB90A80-741A-5540-BC15-4E9F46A5A56B")
    __x_ABI_CUFCase_CIsolation_CIFeatureModel : public IInspectable
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentState( 
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CCbsInstallState *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_RequestedState( 
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CCbsInstallState *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DisplayName( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DisplayFile( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Restart( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_PsfName( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DownloadSize( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_SetMembership( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ContentPackage( 
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Enable( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Disable( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParentFeatureCollection( 
            /* [out][retval] */ __FIIterable_1_UFCase__CIsolation__CFeatureModel **result) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CIsolation_CIFeatureModelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIFeatureModel, get_CurrentState)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentState )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CCbsInstallState *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIFeatureModel, get_RequestedState)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_RequestedState )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CCbsInstallState *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIFeatureModel, get_Name)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIFeatureModel, get_DisplayName)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayName )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIFeatureModel, get_Description)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIFeatureModel, get_DisplayFile)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayFile )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIFeatureModel, get_Restart)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Restart )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIFeatureModel, get_PsfName)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_PsfName )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIFeatureModel, get_DownloadSize)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadSize )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIFeatureModel, get_SetMembership)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_SetMembership )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIFeatureModel, get_ContentPackage)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ContentPackage )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIFeatureModel, Enable)
        HRESULT ( STDMETHODCALLTYPE *Enable )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIFeatureModel, Disable)
        HRESULT ( STDMETHODCALLTYPE *Disable )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIFeatureModel, GetParentFeatureCollection)
        HRESULT ( STDMETHODCALLTYPE *GetParentFeatureCollection )( 
            __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
            /* [out][retval] */ __FIIterable_1_UFCase__CIsolation__CFeatureModel **result);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CIsolation_CIFeatureModelVtbl;

    interface __x_ABI_CUFCase_CIsolation_CIFeatureModel
    {
        CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CIFeatureModelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_CurrentState(This,value)	\
    ( (This)->lpVtbl -> get_CurrentState(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_RequestedState(This,value)	\
    ( (This)->lpVtbl -> get_RequestedState(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_Name(This,value)	\
    ( (This)->lpVtbl -> get_Name(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_DisplayName(This,value)	\
    ( (This)->lpVtbl -> get_DisplayName(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_Description(This,value)	\
    ( (This)->lpVtbl -> get_Description(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_DisplayFile(This,value)	\
    ( (This)->lpVtbl -> get_DisplayFile(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_Restart(This,value)	\
    ( (This)->lpVtbl -> get_Restart(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_PsfName(This,value)	\
    ( (This)->lpVtbl -> get_PsfName(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_DownloadSize(This,value)	\
    ( (This)->lpVtbl -> get_DownloadSize(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_SetMembership(This,value)	\
    ( (This)->lpVtbl -> get_SetMembership(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_ContentPackage(This,value)	\
    ( (This)->lpVtbl -> get_ContentPackage(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_Enable(This)	\
    ( (This)->lpVtbl -> Enable(This) ) 

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_Disable(This)	\
    ( (This)->lpVtbl -> Disable(This) ) 

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_GetParentFeatureCollection(This,result)	\
    ( (This)->lpVtbl -> GetParentFeatureCollection(This,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CIsolation_CIFeatureModel_INTERFACE_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CIsolation_CIHost_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIHost_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CIsolation_CIHost */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIHost;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6BD59CFB-CCEA-5E36-B07D-DAA8833D5E09")
    __x_ABI_CUFCase_CIsolation_CIHost : public IInspectable
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [out][retval] */ GUID *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Bootdrive( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Ping( void) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Image( 
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIImageModel **value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CIsolation_CIHostVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CIsolation_CIHost * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CIsolation_CIHost * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CIsolation_CIHost * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CIsolation_CIHost * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CIsolation_CIHost * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CIsolation_CIHost * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIHost, get_Id)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __x_ABI_CUFCase_CIsolation_CIHost * This,
            /* [out][retval] */ GUID *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIHost, get_Bootdrive)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Bootdrive )( 
            __x_ABI_CUFCase_CIsolation_CIHost * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIHost, Ping)
        HRESULT ( STDMETHODCALLTYPE *Ping )( 
            __x_ABI_CUFCase_CIsolation_CIHost * This);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIHost, get_Image)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Image )( 
            __x_ABI_CUFCase_CIsolation_CIHost * This,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIImageModel **value);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CIsolation_CIHostVtbl;

    interface __x_ABI_CUFCase_CIsolation_CIHost
    {
        CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CIHostVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CIsolation_CIHost_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CIsolation_CIHost_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CIsolation_CIHost_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CIsolation_CIHost_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CIsolation_CIHost_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CIsolation_CIHost_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CUFCase_CIsolation_CIHost_get_Id(This,value)	\
    ( (This)->lpVtbl -> get_Id(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIHost_get_Bootdrive(This,value)	\
    ( (This)->lpVtbl -> get_Bootdrive(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIHost_Ping(This)	\
    ( (This)->lpVtbl -> Ping(This) ) 

#define __x_ABI_CUFCase_CIsolation_CIHost_get_Image(This,value)	\
    ( (This)->lpVtbl -> get_Image(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CIsolation_CIHost_INTERFACE_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CIsolation_CIHostManager_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIHostManager_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CIsolation_CIHostManager */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIHostManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE58A347-7042-5FAD-B3D6-741CA21CE176")
    __x_ABI_CUFCase_CIsolation_CIHostManager : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RegisterHost( 
            /* [in] */ __x_ABI_CUFCase_CIsolation_CIHost *host) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnregisterHost( 
            /* [in] */ __x_ABI_CUFCase_CIsolation_CIHost *host) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CIsolation_CIHostManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CIsolation_CIHostManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CIsolation_CIHostManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CIsolation_CIHostManager * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CIsolation_CIHostManager * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CIsolation_CIHostManager * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CIsolation_CIHostManager * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIHostManager, RegisterHost)
        HRESULT ( STDMETHODCALLTYPE *RegisterHost )( 
            __x_ABI_CUFCase_CIsolation_CIHostManager * This,
            /* [in] */ __x_ABI_CUFCase_CIsolation_CIHost *host);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIHostManager, UnregisterHost)
        HRESULT ( STDMETHODCALLTYPE *UnregisterHost )( 
            __x_ABI_CUFCase_CIsolation_CIHostManager * This,
            /* [in] */ __x_ABI_CUFCase_CIsolation_CIHost *host);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CIsolation_CIHostManagerVtbl;

    interface __x_ABI_CUFCase_CIsolation_CIHostManager
    {
        CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CIHostManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CIsolation_CIHostManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CIsolation_CIHostManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CIsolation_CIHostManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CIsolation_CIHostManager_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CIsolation_CIHostManager_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CIsolation_CIHostManager_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CUFCase_CIsolation_CIHostManager_RegisterHost(This,host)	\
    ( (This)->lpVtbl -> RegisterHost(This,host) ) 

#define __x_ABI_CUFCase_CIsolation_CIHostManager_UnregisterHost(This,host)	\
    ( (This)->lpVtbl -> UnregisterHost(This,host) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CIsolation_CIHostManager_INTERFACE_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIHostManagerSingleton;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("806A41FC-6AEA-5877-A7EA-4B012E59F865")
    __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Current( 
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIHostManager **result) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CIsolation_CIHostManagerSingletonVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIHostManagerSingleton, Current)
        HRESULT ( STDMETHODCALLTYPE *Current )( 
            __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton * This,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIHostManager **result);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CIsolation_CIHostManagerSingletonVtbl;

    interface __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton
    {
        CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CIHostManagerSingletonVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_Current(This,result)	\
    ( (This)->lpVtbl -> Current(This,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_INTERFACE_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CIsolation_CIImageModel_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIImageModel_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CIsolation_CIImageModel */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIImageModel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("13F4D846-68DA-53E9-88C6-495AA1B7B4A4")
    __x_ABI_CUFCase_CIsolation_CIImageModel : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OpenSession( 
            /* [in] */ UINT32 option,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CISessionModel **result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SxsStore( 
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIStoreModel **result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Bootdrive( 
            /* [out][retval] */ HSTRING *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WinDir( 
            /* [out][retval] */ HSTRING *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRegistryHive( 
            /* [in] */ HSTRING hive_id,
            /* [out][retval] */ HSTRING *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Type( 
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CImageType *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Version( 
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CImageVersion *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Edition( 
            /* [out][retval] */ HSTRING *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Architecture( 
            /* [out][retval] */ HSTRING *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsWinPE( 
            /* [out][retval] */ boolean *result) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CIsolation_CIImageModelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CIsolation_CIImageModel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CIsolation_CIImageModel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CIsolation_CIImageModel * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CIsolation_CIImageModel * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CIsolation_CIImageModel * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CIsolation_CIImageModel * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIImageModel, OpenSession)
        HRESULT ( STDMETHODCALLTYPE *OpenSession )( 
            __x_ABI_CUFCase_CIsolation_CIImageModel * This,
            /* [in] */ UINT32 option,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CISessionModel **result);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIImageModel, SxsStore)
        HRESULT ( STDMETHODCALLTYPE *SxsStore )( 
            __x_ABI_CUFCase_CIsolation_CIImageModel * This,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIStoreModel **result);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIImageModel, Bootdrive)
        HRESULT ( STDMETHODCALLTYPE *Bootdrive )( 
            __x_ABI_CUFCase_CIsolation_CIImageModel * This,
            /* [out][retval] */ HSTRING *result);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIImageModel, WinDir)
        HRESULT ( STDMETHODCALLTYPE *WinDir )( 
            __x_ABI_CUFCase_CIsolation_CIImageModel * This,
            /* [out][retval] */ HSTRING *result);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIImageModel, GetRegistryHive)
        HRESULT ( STDMETHODCALLTYPE *GetRegistryHive )( 
            __x_ABI_CUFCase_CIsolation_CIImageModel * This,
            /* [in] */ HSTRING hive_id,
            /* [out][retval] */ HSTRING *result);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIImageModel, Type)
        HRESULT ( STDMETHODCALLTYPE *Type )( 
            __x_ABI_CUFCase_CIsolation_CIImageModel * This,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CImageType *result);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIImageModel, Version)
        HRESULT ( STDMETHODCALLTYPE *Version )( 
            __x_ABI_CUFCase_CIsolation_CIImageModel * This,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CImageVersion *result);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIImageModel, Edition)
        HRESULT ( STDMETHODCALLTYPE *Edition )( 
            __x_ABI_CUFCase_CIsolation_CIImageModel * This,
            /* [out][retval] */ HSTRING *result);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIImageModel, Architecture)
        HRESULT ( STDMETHODCALLTYPE *Architecture )( 
            __x_ABI_CUFCase_CIsolation_CIImageModel * This,
            /* [out][retval] */ HSTRING *result);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIImageModel, IsWinPE)
        HRESULT ( STDMETHODCALLTYPE *IsWinPE )( 
            __x_ABI_CUFCase_CIsolation_CIImageModel * This,
            /* [out][retval] */ boolean *result);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CIsolation_CIImageModelVtbl;

    interface __x_ABI_CUFCase_CIsolation_CIImageModel
    {
        CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CIImageModelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CIsolation_CIImageModel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CIsolation_CIImageModel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CIsolation_CIImageModel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CIsolation_CIImageModel_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CIsolation_CIImageModel_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CIsolation_CIImageModel_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CUFCase_CIsolation_CIImageModel_OpenSession(This,option,result)	\
    ( (This)->lpVtbl -> OpenSession(This,option,result) ) 

#define __x_ABI_CUFCase_CIsolation_CIImageModel_SxsStore(This,result)	\
    ( (This)->lpVtbl -> SxsStore(This,result) ) 

#define __x_ABI_CUFCase_CIsolation_CIImageModel_Bootdrive(This,result)	\
    ( (This)->lpVtbl -> Bootdrive(This,result) ) 

#define __x_ABI_CUFCase_CIsolation_CIImageModel_WinDir(This,result)	\
    ( (This)->lpVtbl -> WinDir(This,result) ) 

#define __x_ABI_CUFCase_CIsolation_CIImageModel_GetRegistryHive(This,hive_id,result)	\
    ( (This)->lpVtbl -> GetRegistryHive(This,hive_id,result) ) 

#define __x_ABI_CUFCase_CIsolation_CIImageModel_Type(This,result)	\
    ( (This)->lpVtbl -> Type(This,result) ) 

#define __x_ABI_CUFCase_CIsolation_CIImageModel_Version(This,result)	\
    ( (This)->lpVtbl -> Version(This,result) ) 

#define __x_ABI_CUFCase_CIsolation_CIImageModel_Edition(This,result)	\
    ( (This)->lpVtbl -> Edition(This,result) ) 

#define __x_ABI_CUFCase_CIsolation_CIImageModel_Architecture(This,result)	\
    ( (This)->lpVtbl -> Architecture(This,result) ) 

#define __x_ABI_CUFCase_CIsolation_CIImageModel_IsWinPE(This,result)	\
    ( (This)->lpVtbl -> IsWinPE(This,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CIsolation_CIImageModel_INTERFACE_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CIsolation_CIPackageModel_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIPackageModel_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CIsolation_CIPackageModel */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIPackageModel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("43786F4F-0F87-5FDF-9E9A-661F8226D32E")
    __x_ABI_CUFCase_CIsolation_CIPackageModel : public IInspectable
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CISessionModel **value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CCbsInstallState *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Identity( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ReleaseType( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_RestartRequired( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProductName( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProductVersion( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Company( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Copyright( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_SupportInformation( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CreationTime( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_LastUpdateTime( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_InstallTime( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_InstallPackageName( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_InstallLocation( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_InstallClient( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_InstallUserName( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsApplicable( 
            /* [out][retval] */ boolean *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ManifestFilePath( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_RegistryPath( 
            /* [out][retval] */ HSTRING *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Install( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Remove( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stage( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenFeature( 
            /* [in] */ HSTRING name,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIFeatureModel **result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFeatureCollection( 
            /* [in] */ UINT32 applicability,
            /* [in] */ UINT32 selectability,
            /* [out][retval] */ __FIIterable_1_UFCase__CIsolation__CFeatureModel **result) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CIsolation_CIPackageModelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_Session)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CISessionModel **value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_State)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CCbsInstallState *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_Name)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_Description)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_Identity)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Identity )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_ReleaseType)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReleaseType )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_RestartRequired)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_RestartRequired )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_ProductName)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProductName )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_ProductVersion)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProductVersion )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_Company)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Company )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_Copyright)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Copyright )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_SupportInformation)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_SupportInformation )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_CreationTime)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CreationTime )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_LastUpdateTime)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastUpdateTime )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_InstallTime)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_InstallTime )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_InstallPackageName)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_InstallPackageName )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_InstallLocation)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_InstallLocation )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_InstallClient)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_InstallClient )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_InstallUserName)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_InstallUserName )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_IsApplicable)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsApplicable )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ boolean *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_ManifestFilePath)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ManifestFilePath )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, get_RegistryPath)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_RegistryPath )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [out][retval] */ HSTRING *value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, Install)
        HRESULT ( STDMETHODCALLTYPE *Install )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, Remove)
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, Stage)
        HRESULT ( STDMETHODCALLTYPE *Stage )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, OpenFeature)
        HRESULT ( STDMETHODCALLTYPE *OpenFeature )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [in] */ HSTRING name,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIFeatureModel **result);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIPackageModel, GetFeatureCollection)
        HRESULT ( STDMETHODCALLTYPE *GetFeatureCollection )( 
            __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
            /* [in] */ UINT32 applicability,
            /* [in] */ UINT32 selectability,
            /* [out][retval] */ __FIIterable_1_UFCase__CIsolation__CFeatureModel **result);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CIsolation_CIPackageModelVtbl;

    interface __x_ABI_CUFCase_CIsolation_CIPackageModel
    {
        CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CIPackageModelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CIsolation_CIPackageModel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CIsolation_CIPackageModel_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_Session(This,value)	\
    ( (This)->lpVtbl -> get_Session(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_State(This,value)	\
    ( (This)->lpVtbl -> get_State(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_Name(This,value)	\
    ( (This)->lpVtbl -> get_Name(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_Description(This,value)	\
    ( (This)->lpVtbl -> get_Description(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_Identity(This,value)	\
    ( (This)->lpVtbl -> get_Identity(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_ReleaseType(This,value)	\
    ( (This)->lpVtbl -> get_ReleaseType(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_RestartRequired(This,value)	\
    ( (This)->lpVtbl -> get_RestartRequired(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_ProductName(This,value)	\
    ( (This)->lpVtbl -> get_ProductName(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_ProductVersion(This,value)	\
    ( (This)->lpVtbl -> get_ProductVersion(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_Company(This,value)	\
    ( (This)->lpVtbl -> get_Company(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_Copyright(This,value)	\
    ( (This)->lpVtbl -> get_Copyright(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_SupportInformation(This,value)	\
    ( (This)->lpVtbl -> get_SupportInformation(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_CreationTime(This,value)	\
    ( (This)->lpVtbl -> get_CreationTime(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_LastUpdateTime(This,value)	\
    ( (This)->lpVtbl -> get_LastUpdateTime(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_InstallTime(This,value)	\
    ( (This)->lpVtbl -> get_InstallTime(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_InstallPackageName(This,value)	\
    ( (This)->lpVtbl -> get_InstallPackageName(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_InstallLocation(This,value)	\
    ( (This)->lpVtbl -> get_InstallLocation(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_InstallClient(This,value)	\
    ( (This)->lpVtbl -> get_InstallClient(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_InstallUserName(This,value)	\
    ( (This)->lpVtbl -> get_InstallUserName(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_IsApplicable(This,value)	\
    ( (This)->lpVtbl -> get_IsApplicable(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_ManifestFilePath(This,value)	\
    ( (This)->lpVtbl -> get_ManifestFilePath(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_RegistryPath(This,value)	\
    ( (This)->lpVtbl -> get_RegistryPath(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_Install(This)	\
    ( (This)->lpVtbl -> Install(This) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_Remove(This)	\
    ( (This)->lpVtbl -> Remove(This) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_Stage(This)	\
    ( (This)->lpVtbl -> Stage(This) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_OpenFeature(This,name,result)	\
    ( (This)->lpVtbl -> OpenFeature(This,name,result) ) 

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_GetFeatureCollection(This,applicability,selectability,result)	\
    ( (This)->lpVtbl -> GetFeatureCollection(This,applicability,selectability,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CIsolation_CIPackageModel_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_UFCase2EIsolation2Eidl_0000_0228 */




extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0228_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0228_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation_0000_0024 */
/* [local] */ 

#ifndef DEF___FIAsyncActionProgressHandler_1_UINT32
#define DEF___FIAsyncActionProgressHandler_1_UINT32
#if !defined(__cplusplus) || defined(RO_NO_TEMPLATE_NAME)



extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0024_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0024_v0_0_s_ifspec;

#ifndef ____FIAsyncActionProgressHandler_1_UINT32_INTERFACE_DEFINED__
#define ____FIAsyncActionProgressHandler_1_UINT32_INTERFACE_DEFINED__

/* interface __FIAsyncActionProgressHandler_1_UINT32 */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID___FIAsyncActionProgressHandler_1_UINT32;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b7f0b891-6d95-5c32-a91f-65f7a311b0e9")
    __FIAsyncActionProgressHandler_1_UINT32 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ __FIAsyncActionWithProgress_1_UINT32 *asyncInfo,
            /* [in] */ UINT32 progressInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __FIAsyncActionProgressHandler_1_UINT32Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __FIAsyncActionProgressHandler_1_UINT32 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __FIAsyncActionProgressHandler_1_UINT32 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __FIAsyncActionProgressHandler_1_UINT32 * This);
        
        DECLSPEC_XFGVIRT(__FIAsyncActionProgressHandler_1_UINT32, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            __FIAsyncActionProgressHandler_1_UINT32 * This,
            /* [in] */ __FIAsyncActionWithProgress_1_UINT32 *asyncInfo,
            /* [in] */ UINT32 progressInfo);
        
        END_INTERFACE
    } __FIAsyncActionProgressHandler_1_UINT32Vtbl;

    interface __FIAsyncActionProgressHandler_1_UINT32
    {
        CONST_VTBL struct __FIAsyncActionProgressHandler_1_UINT32Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __FIAsyncActionProgressHandler_1_UINT32_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIAsyncActionProgressHandler_1_UINT32_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIAsyncActionProgressHandler_1_UINT32_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIAsyncActionProgressHandler_1_UINT32_Invoke(This,asyncInfo,progressInfo)	\
    ( (This)->lpVtbl -> Invoke(This,asyncInfo,progressInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____FIAsyncActionProgressHandler_1_UINT32_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_UFCase2EIsolation_0000_0025 */
/* [local] */ 

#endif /* pinterface */
#endif /* DEF___FIAsyncActionProgressHandler_1_UINT32 */


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0025_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0025_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation2Eidl_0000_0229 */




extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0229_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0229_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation_0000_0026 */
/* [local] */ 

#ifndef DEF___FIAsyncActionWithProgressCompletedHandler_1_UINT32
#define DEF___FIAsyncActionWithProgressCompletedHandler_1_UINT32
#if !defined(__cplusplus) || defined(RO_NO_TEMPLATE_NAME)



extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0026_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0026_v0_0_s_ifspec;

#ifndef ____FIAsyncActionWithProgressCompletedHandler_1_UINT32_INTERFACE_DEFINED__
#define ____FIAsyncActionWithProgressCompletedHandler_1_UINT32_INTERFACE_DEFINED__

/* interface __FIAsyncActionWithProgressCompletedHandler_1_UINT32 */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID___FIAsyncActionWithProgressCompletedHandler_1_UINT32;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1f29e65e-49e0-577d-ac96-bcf0087e563d")
    __FIAsyncActionWithProgressCompletedHandler_1_UINT32 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ __FIAsyncActionWithProgress_1_UINT32 *asyncInfo,
            /* [in] */ AsyncStatus status) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __FIAsyncActionWithProgressCompletedHandler_1_UINT32Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __FIAsyncActionWithProgressCompletedHandler_1_UINT32 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __FIAsyncActionWithProgressCompletedHandler_1_UINT32 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __FIAsyncActionWithProgressCompletedHandler_1_UINT32 * This);
        
        DECLSPEC_XFGVIRT(__FIAsyncActionWithProgressCompletedHandler_1_UINT32, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            __FIAsyncActionWithProgressCompletedHandler_1_UINT32 * This,
            /* [in] */ __FIAsyncActionWithProgress_1_UINT32 *asyncInfo,
            /* [in] */ AsyncStatus status);
        
        END_INTERFACE
    } __FIAsyncActionWithProgressCompletedHandler_1_UINT32Vtbl;

    interface __FIAsyncActionWithProgressCompletedHandler_1_UINT32
    {
        CONST_VTBL struct __FIAsyncActionWithProgressCompletedHandler_1_UINT32Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __FIAsyncActionWithProgressCompletedHandler_1_UINT32_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIAsyncActionWithProgressCompletedHandler_1_UINT32_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIAsyncActionWithProgressCompletedHandler_1_UINT32_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIAsyncActionWithProgressCompletedHandler_1_UINT32_Invoke(This,asyncInfo,status)	\
    ( (This)->lpVtbl -> Invoke(This,asyncInfo,status) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____FIAsyncActionWithProgressCompletedHandler_1_UINT32_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_UFCase2EIsolation_0000_0027 */
/* [local] */ 

#endif /* pinterface */
#endif /* DEF___FIAsyncActionWithProgressCompletedHandler_1_UINT32 */


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0027_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0027_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation2Eidl_0000_0230 */




extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0230_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation2Eidl_0000_0230_v0_0_s_ifspec;

/* interface __MIDL_itf_UFCase2EIsolation_0000_0028 */
/* [local] */ 

#ifndef DEF___FIAsyncActionWithProgress_1_UINT32
#define DEF___FIAsyncActionWithProgress_1_UINT32
#if !defined(__cplusplus) || defined(RO_NO_TEMPLATE_NAME)


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0028_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0028_v0_0_s_ifspec;

#ifndef ____FIAsyncActionWithProgress_1_UINT32_INTERFACE_DEFINED__
#define ____FIAsyncActionWithProgress_1_UINT32_INTERFACE_DEFINED__

/* interface __FIAsyncActionWithProgress_1_UINT32 */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID___FIAsyncActionWithProgress_1_UINT32;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("429f47f0-1388-5b75-b44c-44ddc4f525c0")
    __FIAsyncActionWithProgress_1_UINT32 : public IInspectable
    {
    public:
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Progress( 
            /* [in] */ __FIAsyncActionProgressHandler_1_UINT32 *handler) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Progress( 
            /* [retval][out] */ __FIAsyncActionProgressHandler_1_UINT32 **handler) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Completed( 
            /* [in] */ __FIAsyncActionWithProgressCompletedHandler_1_UINT32 *handler) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Completed( 
            /* [retval][out] */ __FIAsyncActionWithProgressCompletedHandler_1_UINT32 **handler) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResults( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __FIAsyncActionWithProgress_1_UINT32Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __FIAsyncActionWithProgress_1_UINT32 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __FIAsyncActionWithProgress_1_UINT32 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __FIAsyncActionWithProgress_1_UINT32 * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __FIAsyncActionWithProgress_1_UINT32 * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __FIAsyncActionWithProgress_1_UINT32 * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __FIAsyncActionWithProgress_1_UINT32 * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__FIAsyncActionWithProgress_1_UINT32, put_Progress)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Progress )( 
            __FIAsyncActionWithProgress_1_UINT32 * This,
            /* [in] */ __FIAsyncActionProgressHandler_1_UINT32 *handler);
        
        DECLSPEC_XFGVIRT(__FIAsyncActionWithProgress_1_UINT32, get_Progress)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Progress )( 
            __FIAsyncActionWithProgress_1_UINT32 * This,
            /* [retval][out] */ __FIAsyncActionProgressHandler_1_UINT32 **handler);
        
        DECLSPEC_XFGVIRT(__FIAsyncActionWithProgress_1_UINT32, put_Completed)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Completed )( 
            __FIAsyncActionWithProgress_1_UINT32 * This,
            /* [in] */ __FIAsyncActionWithProgressCompletedHandler_1_UINT32 *handler);
        
        DECLSPEC_XFGVIRT(__FIAsyncActionWithProgress_1_UINT32, get_Completed)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Completed )( 
            __FIAsyncActionWithProgress_1_UINT32 * This,
            /* [retval][out] */ __FIAsyncActionWithProgressCompletedHandler_1_UINT32 **handler);
        
        DECLSPEC_XFGVIRT(__FIAsyncActionWithProgress_1_UINT32, GetResults)
        HRESULT ( STDMETHODCALLTYPE *GetResults )( 
            __FIAsyncActionWithProgress_1_UINT32 * This);
        
        END_INTERFACE
    } __FIAsyncActionWithProgress_1_UINT32Vtbl;

    interface __FIAsyncActionWithProgress_1_UINT32
    {
        CONST_VTBL struct __FIAsyncActionWithProgress_1_UINT32Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __FIAsyncActionWithProgress_1_UINT32_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIAsyncActionWithProgress_1_UINT32_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIAsyncActionWithProgress_1_UINT32_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIAsyncActionWithProgress_1_UINT32_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIAsyncActionWithProgress_1_UINT32_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIAsyncActionWithProgress_1_UINT32_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIAsyncActionWithProgress_1_UINT32_put_Progress(This,handler)	\
    ( (This)->lpVtbl -> put_Progress(This,handler) ) 

#define __FIAsyncActionWithProgress_1_UINT32_get_Progress(This,handler)	\
    ( (This)->lpVtbl -> get_Progress(This,handler) ) 

#define __FIAsyncActionWithProgress_1_UINT32_put_Completed(This,handler)	\
    ( (This)->lpVtbl -> put_Completed(This,handler) ) 

#define __FIAsyncActionWithProgress_1_UINT32_get_Completed(This,handler)	\
    ( (This)->lpVtbl -> get_Completed(This,handler) ) 

#define __FIAsyncActionWithProgress_1_UINT32_GetResults(This)	\
    ( (This)->lpVtbl -> GetResults(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____FIAsyncActionWithProgress_1_UINT32_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_UFCase2EIsolation_0000_0029 */
/* [local] */ 

#endif /* pinterface */
#endif /* DEF___FIAsyncActionWithProgress_1_UINT32 */


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0029_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EIsolation_0000_0029_v0_0_s_ifspec;

#ifndef ____x_ABI_CUFCase_CIsolation_CISessionModel_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CISessionModel_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CIsolation_CISessionModel */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CISessionModel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D4B1314D-679D-5256-B032-D3FD6CAB4782")
    __x_ABI_CUFCase_CIsolation_CISessionModel : public IInspectable
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Image( 
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIImageModel **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddSource( 
            /* [in] */ HSTRING source) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveChanges( 
            /* [out][retval] */ __FIAsyncActionWithProgress_1_UINT32 **operation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenPackage( 
            /* [in] */ HSTRING identity,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPackageCollection( 
            /* [in] */ UINT32 option,
            /* [out][retval] */ __FIVector_1_UFCase__CIsolation__CPackageModel **result) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_FoundationPackage( 
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProductPackage( 
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PerformOperation( 
            /* [in] */ __x_ABI_CUFCase_CIsolation_CCbsOperationType op) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CIsolation_CISessionModelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CIsolation_CISessionModel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CIsolation_CISessionModel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CIsolation_CISessionModel * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CIsolation_CISessionModel * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CIsolation_CISessionModel * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CIsolation_CISessionModel * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CISessionModel, get_Image)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Image )( 
            __x_ABI_CUFCase_CIsolation_CISessionModel * This,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIImageModel **value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CISessionModel, AddSource)
        HRESULT ( STDMETHODCALLTYPE *AddSource )( 
            __x_ABI_CUFCase_CIsolation_CISessionModel * This,
            /* [in] */ HSTRING source);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CISessionModel, SaveChanges)
        HRESULT ( STDMETHODCALLTYPE *SaveChanges )( 
            __x_ABI_CUFCase_CIsolation_CISessionModel * This,
            /* [out][retval] */ __FIAsyncActionWithProgress_1_UINT32 **operation);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CISessionModel, OpenPackage)
        HRESULT ( STDMETHODCALLTYPE *OpenPackage )( 
            __x_ABI_CUFCase_CIsolation_CISessionModel * This,
            /* [in] */ HSTRING identity,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **result);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CISessionModel, GetPackageCollection)
        HRESULT ( STDMETHODCALLTYPE *GetPackageCollection )( 
            __x_ABI_CUFCase_CIsolation_CISessionModel * This,
            /* [in] */ UINT32 option,
            /* [out][retval] */ __FIVector_1_UFCase__CIsolation__CPackageModel **result);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CISessionModel, get_FoundationPackage)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_FoundationPackage )( 
            __x_ABI_CUFCase_CIsolation_CISessionModel * This,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CISessionModel, get_ProductPackage)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProductPackage )( 
            __x_ABI_CUFCase_CIsolation_CISessionModel * This,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIPackageModel **value);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CISessionModel, PerformOperation)
        HRESULT ( STDMETHODCALLTYPE *PerformOperation )( 
            __x_ABI_CUFCase_CIsolation_CISessionModel * This,
            /* [in] */ __x_ABI_CUFCase_CIsolation_CCbsOperationType op);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CIsolation_CISessionModelVtbl;

    interface __x_ABI_CUFCase_CIsolation_CISessionModel
    {
        CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CISessionModelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CIsolation_CISessionModel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CIsolation_CISessionModel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CIsolation_CISessionModel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CIsolation_CISessionModel_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CIsolation_CISessionModel_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CIsolation_CISessionModel_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CUFCase_CIsolation_CISessionModel_get_Image(This,value)	\
    ( (This)->lpVtbl -> get_Image(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CISessionModel_AddSource(This,source)	\
    ( (This)->lpVtbl -> AddSource(This,source) ) 

#define __x_ABI_CUFCase_CIsolation_CISessionModel_SaveChanges(This,operation)	\
    ( (This)->lpVtbl -> SaveChanges(This,operation) ) 

#define __x_ABI_CUFCase_CIsolation_CISessionModel_OpenPackage(This,identity,result)	\
    ( (This)->lpVtbl -> OpenPackage(This,identity,result) ) 

#define __x_ABI_CUFCase_CIsolation_CISessionModel_GetPackageCollection(This,option,result)	\
    ( (This)->lpVtbl -> GetPackageCollection(This,option,result) ) 

#define __x_ABI_CUFCase_CIsolation_CISessionModel_get_FoundationPackage(This,value)	\
    ( (This)->lpVtbl -> get_FoundationPackage(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CISessionModel_get_ProductPackage(This,value)	\
    ( (This)->lpVtbl -> get_ProductPackage(This,value) ) 

#define __x_ABI_CUFCase_CIsolation_CISessionModel_PerformOperation(This,op)	\
    ( (This)->lpVtbl -> PerformOperation(This,op) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CIsolation_CISessionModel_INTERFACE_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CIsolation_CIStoreModel_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIStoreModel_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CIsolation_CIStoreModel */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIStoreModel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE3C8E81-A790-528D-A986-80E6A9722BAA")
    __x_ABI_CUFCase_CIsolation_CIStoreModel : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OpenComponent( 
            /* [in] */ HSTRING definition,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIComponentModel **result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetComponentCollection( 
            /* [out][retval] */ __FIIterable_1_IInspectable **result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetComponentCollection2( 
            /* [in] */ HSTRING reference,
            /* [out][retval] */ __FIIterable_1_IInspectable **result) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CIsolation_CIStoreModelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CIsolation_CIStoreModel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CIsolation_CIStoreModel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CIsolation_CIStoreModel * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CIsolation_CIStoreModel * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CIsolation_CIStoreModel * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CIsolation_CIStoreModel * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIStoreModel, OpenComponent)
        HRESULT ( STDMETHODCALLTYPE *OpenComponent )( 
            __x_ABI_CUFCase_CIsolation_CIStoreModel * This,
            /* [in] */ HSTRING definition,
            /* [out][retval] */ __x_ABI_CUFCase_CIsolation_CIComponentModel **result);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIStoreModel, GetComponentCollection)
        HRESULT ( STDMETHODCALLTYPE *GetComponentCollection )( 
            __x_ABI_CUFCase_CIsolation_CIStoreModel * This,
            /* [out][retval] */ __FIIterable_1_IInspectable **result);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CIsolation_CIStoreModel, GetComponentCollection2)
        HRESULT ( STDMETHODCALLTYPE *GetComponentCollection2 )( 
            __x_ABI_CUFCase_CIsolation_CIStoreModel * This,
            /* [in] */ HSTRING reference,
            /* [out][retval] */ __FIIterable_1_IInspectable **result);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CIsolation_CIStoreModelVtbl;

    interface __x_ABI_CUFCase_CIsolation_CIStoreModel
    {
        CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CIStoreModelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CIsolation_CIStoreModel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CIsolation_CIStoreModel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CIsolation_CIStoreModel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CIsolation_CIStoreModel_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CIsolation_CIStoreModel_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CIsolation_CIStoreModel_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CUFCase_CIsolation_CIStoreModel_OpenComponent(This,definition,result)	\
    ( (This)->lpVtbl -> OpenComponent(This,definition,result) ) 

#define __x_ABI_CUFCase_CIsolation_CIStoreModel_GetComponentCollection(This,result)	\
    ( (This)->lpVtbl -> GetComponentCollection(This,result) ) 

#define __x_ABI_CUFCase_CIsolation_CIStoreModel_GetComponentCollection2(This,reference,result)	\
    ( (This)->lpVtbl -> GetComponentCollection2(This,reference,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CIsolation_CIStoreModel_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  HSTRING_UserSize(     unsigned long *, unsigned long            , HSTRING * ); 
unsigned char * __RPC_USER  HSTRING_UserMarshal(  unsigned long *, unsigned char *, HSTRING * ); 
unsigned char * __RPC_USER  HSTRING_UserUnmarshal(unsigned long *, unsigned char *, HSTRING * ); 
void                      __RPC_USER  HSTRING_UserFree(     unsigned long *, HSTRING * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


