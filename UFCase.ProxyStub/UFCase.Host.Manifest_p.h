

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for C:\Users\7mile\AppData\Local\Temp\UFCase.Host.Manifest.idl-d9dd6edc:
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

#ifndef __UFCase2EHost2EManifest_p_h__
#define __UFCase2EHost2EManifest_p_h__

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

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass;

#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass;

#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass;

#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper;

#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIFileClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIFileClass_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIFileClass __x_ABI_CUFCase_CHost_CManifest_CIFileClass;

#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIFileClass_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass;

#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic;

#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass;

#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass;

#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_FWD_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIVersionClass __x_ABI_CUFCase_CHost_CManifest_CIVersionClass;

#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_FWD_DEFINED__ */


/* header files for imported files */
#include "inspectable.h"
#include "AsyncInfo.h"
#include "EventToken.h"
#include "Windows.Foundation.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_UFCase2EHost2EManifest_0000_0000 */
/* [local] */ 











typedef enum __x_ABI_CUFCase_CHost_CManifest_CRegistryValueType __x_ABI_CUFCase_CHost_CManifest_CRegistryValueType;











/* [v1_enum] */ 
enum __x_ABI_CUFCase_CHost_CManifest_CRegistryValueType
    {
        RegistryValueType_RegNone	= 0,
        RegistryValueType_RegSz	= 1,
        RegistryValueType_RegExpandSz	= 2,
        RegistryValueType_RegBinary	= 3,
        RegistryValueType_RegDword	= 4,
        RegistryValueType_RegDwordBigEndian	= 5,
        RegistryValueType_RegLink	= 6,
        RegistryValueType_RegMultiSz	= 7,
        RegistryValueType_RegResourceList	= 8,
        RegistryValueType_RegFullResourceDescriptor	= 9,
        RegistryValueType_RegResourceRequirementsList	= 10,
        RegistryValueType_RegQword	= 11
    } ;


extern RPC_IF_HANDLE __MIDL_itf_UFCase2EHost2EManifest_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UFCase2EHost2EManifest_0000_0000_v0_0_s_ifspec;

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1254A4C8-452B-5744-B544-72BC8D34A2BC")
    __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass : public IInspectable
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Identity( 
            /* [out][retval] */ __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass **__returnValue_get_Identity__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [out][retval] */ __x_ABI_CUFCase_CHost_CManifest_CIVersionClass **__returnValue_get_Version__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Files( 
            /* [out] */ UINT32 *____returnValue_get_Files__Size,
            /* [out][retval][size_is][size_is] */ __x_ABI_CUFCase_CHost_CManifest_CIFileClass ***__returnValue_get_Files__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Keys( 
            /* [out] */ UINT32 *____returnValue_get_Keys__Size,
            /* [out][retval][size_is][size_is] */ __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass ***__returnValue_get_Keys__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Dependencies( 
            /* [out] */ UINT32 *____returnValue_get_Dependencies__Size,
            /* [out][retval][size_is][size_is] */ __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass ***__returnValue_get_Dependencies__) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClassVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass, get_Identity)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Identity )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
            /* [out][retval] */ __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass **__returnValue_get_Identity__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass, get_Version)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
            /* [out][retval] */ __x_ABI_CUFCase_CHost_CManifest_CIVersionClass **__returnValue_get_Version__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass, get_Files)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Files )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
            /* [out] */ UINT32 *____returnValue_get_Files__Size,
            /* [out][retval][size_is][size_is] */ __x_ABI_CUFCase_CHost_CManifest_CIFileClass ***__returnValue_get_Files__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass, get_Keys)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Keys )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
            /* [out] */ UINT32 *____returnValue_get_Keys__Size,
            /* [out][retval][size_is][size_is] */ __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass ***__returnValue_get_Keys__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass, get_Dependencies)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Dependencies )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
            /* [out] */ UINT32 *____returnValue_get_Dependencies__Size,
            /* [out][retval][size_is][size_is] */ __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass ***__returnValue_get_Dependencies__);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClassVtbl;

    interface __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass
    {
        CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClassVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_get_Identity(This,__returnValue_get_Identity__)	\
    ( (This)->lpVtbl -> get_Identity(This,__returnValue_get_Identity__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_get_Version(This,__returnValue_get_Version__)	\
    ( (This)->lpVtbl -> get_Version(This,__returnValue_get_Version__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_get_Files(This,____returnValue_get_Files__Size,__returnValue_get_Files__)	\
    ( (This)->lpVtbl -> get_Files(This,____returnValue_get_Files__Size,__returnValue_get_Files__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_get_Keys(This,____returnValue_get_Keys__Size,__returnValue_get_Keys__)	\
    ( (This)->lpVtbl -> get_Keys(This,____returnValue_get_Keys__Size,__returnValue_get_Keys__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_get_Dependencies(This,____returnValue_get_Dependencies__Size,__returnValue_get_Dependencies__)	\
    ( (This)->lpVtbl -> get_Dependencies(This,____returnValue_get_Dependencies__Size,__returnValue_get_Dependencies__) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_INTERFACE_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("59EC1B96-C604-5C7C-AFC9-648BA4A9B001")
    __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass : public IInspectable
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Identity( 
            /* [out][retval] */ __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass **__returnValue_get_Identity__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [out][retval] */ HSTRING *__returnValue_get_Type__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Install( 
            /* [out][retval] */ HSTRING *__returnValue_get_Install__) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClassVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass, get_Identity)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Identity )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This,
            /* [out][retval] */ __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass **__returnValue_get_Identity__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass, get_Type)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_Type__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass, get_Install)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Install )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_Install__);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClassVtbl;

    interface __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass
    {
        CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClassVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_get_Identity(This,__returnValue_get_Identity__)	\
    ( (This)->lpVtbl -> get_Identity(This,__returnValue_get_Identity__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_get_Type(This,__returnValue_get_Type__)	\
    ( (This)->lpVtbl -> get_Type(This,__returnValue_get_Type__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_get_Install(This,__returnValue_get_Install__)	\
    ( (This)->lpVtbl -> get_Install(This,__returnValue_get_Install__) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_INTERFACE_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("26D5B743-6C88-5B41-9F37-35A7DE5F6144")
    __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass : public IInspectable
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [out][retval] */ HSTRING *__returnValue_get_Name__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_PublicKeyToken( 
            /* [out][retval] */ HSTRING *__returnValue_get_PublicKeyToken__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Language( 
            /* [out][retval] */ HSTRING *__returnValue_get_Language__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProcessorArchitecture( 
            /* [out][retval] */ HSTRING *__returnValue_get_ProcessorArchitecture__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [out][retval] */ HSTRING *__returnValue_get_Version__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [out][retval] */ HSTRING *__returnValue_get_Type__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_KeyForm( 
            /* [out][retval] */ HSTRING *__returnValue_get_KeyForm__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_HashCode( 
            /* [out][retval] */ HSTRING *__returnValue_get_HashCode__) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClassVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass, get_Name)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_Name__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass, get_PublicKeyToken)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_PublicKeyToken )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_PublicKeyToken__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass, get_Language)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Language )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_Language__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass, get_ProcessorArchitecture)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProcessorArchitecture )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_ProcessorArchitecture__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass, get_Version)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_Version__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass, get_Type)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_Type__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass, get_KeyForm)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_KeyForm )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_KeyForm__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass, get_HashCode)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HashCode )( 
            __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_HashCode__);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClassVtbl;

    interface __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass
    {
        CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClassVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_get_Name(This,__returnValue_get_Name__)	\
    ( (This)->lpVtbl -> get_Name(This,__returnValue_get_Name__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_get_PublicKeyToken(This,__returnValue_get_PublicKeyToken__)	\
    ( (This)->lpVtbl -> get_PublicKeyToken(This,__returnValue_get_PublicKeyToken__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_get_Language(This,__returnValue_get_Language__)	\
    ( (This)->lpVtbl -> get_Language(This,__returnValue_get_Language__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_get_ProcessorArchitecture(This,__returnValue_get_ProcessorArchitecture__)	\
    ( (This)->lpVtbl -> get_ProcessorArchitecture(This,__returnValue_get_ProcessorArchitecture__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_get_Version(This,__returnValue_get_Version__)	\
    ( (This)->lpVtbl -> get_Version(This,__returnValue_get_Version__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_get_Type(This,__returnValue_get_Type__)	\
    ( (This)->lpVtbl -> get_Type(This,__returnValue_get_Type__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_get_KeyForm(This,__returnValue_get_KeyForm__)	\
    ( (This)->lpVtbl -> get_KeyForm(This,__returnValue_get_KeyForm__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_get_HashCode(This,__returnValue_get_HashCode__)	\
    ( (This)->lpVtbl -> get_HashCode(This,__returnValue_get_HashCode__) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_INTERFACE_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3347D112-6F3D-519A-8493-F5E3F1A1079E")
    __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper : public IInspectable
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapperVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper * This,
            /* [out] */ TrustLevel *trustLevel);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapperVtbl;

    interface __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper
    {
        CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_INTERFACE_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIFileClass_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIFileClass_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CHost_CManifest_CIFileClass */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIFileClass;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B3B96E25-DA85-5851-A796-BDFABCB19CFD")
    __x_ABI_CUFCase_CHost_CManifest_CIFileClass : public IInspectable
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DestinationName( 
            /* [out][retval] */ HSTRING *__returnValue_get_DestinationName__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DestinationPath( 
            /* [out][retval] */ HSTRING *__returnValue_get_DestinationPath__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_SourcePath( 
            /* [out][retval] */ HSTRING *__returnValue_get_SourcePath__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_SourceName( 
            /* [out][retval] */ HSTRING *__returnValue_get_SourceName__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ImportPath( 
            /* [out][retval] */ HSTRING *__returnValue_get_ImportPath__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Hash( 
            /* [out][retval] */ HSTRING *__returnValue_get_Hash__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_HashAlgorithm( 
            /* [out][retval] */ HSTRING *__returnValue_get_HashAlgorithm__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_SizeInByte( 
            /* [out][retval] */ INT32 *__returnValue_get_SizeInByte__) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CHost_CManifest_CIFileClassVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIFileClass, get_DestinationName)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DestinationName )( 
            __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_DestinationName__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIFileClass, get_DestinationPath)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DestinationPath )( 
            __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_DestinationPath__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIFileClass, get_SourcePath)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_SourcePath )( 
            __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_SourcePath__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIFileClass, get_SourceName)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_SourceName )( 
            __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_SourceName__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIFileClass, get_ImportPath)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImportPath )( 
            __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_ImportPath__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIFileClass, get_Hash)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Hash )( 
            __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_Hash__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIFileClass, get_HashAlgorithm)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HashAlgorithm )( 
            __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_HashAlgorithm__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIFileClass, get_SizeInByte)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_SizeInByte )( 
            __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
            /* [out][retval] */ INT32 *__returnValue_get_SizeInByte__);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CHost_CManifest_CIFileClassVtbl;

    interface __x_ABI_CUFCase_CHost_CManifest_CIFileClass
    {
        CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIFileClassVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_get_DestinationName(This,__returnValue_get_DestinationName__)	\
    ( (This)->lpVtbl -> get_DestinationName(This,__returnValue_get_DestinationName__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_get_DestinationPath(This,__returnValue_get_DestinationPath__)	\
    ( (This)->lpVtbl -> get_DestinationPath(This,__returnValue_get_DestinationPath__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_get_SourcePath(This,__returnValue_get_SourcePath__)	\
    ( (This)->lpVtbl -> get_SourcePath(This,__returnValue_get_SourcePath__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_get_SourceName(This,__returnValue_get_SourceName__)	\
    ( (This)->lpVtbl -> get_SourceName(This,__returnValue_get_SourceName__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_get_ImportPath(This,__returnValue_get_ImportPath__)	\
    ( (This)->lpVtbl -> get_ImportPath(This,__returnValue_get_ImportPath__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_get_Hash(This,__returnValue_get_Hash__)	\
    ( (This)->lpVtbl -> get_Hash(This,__returnValue_get_Hash__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_get_HashAlgorithm(This,__returnValue_get_HashAlgorithm__)	\
    ( (This)->lpVtbl -> get_HashAlgorithm(This,__returnValue_get_HashAlgorithm__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_get_SizeInByte(This,__returnValue_get_SizeInByte__)	\
    ( (This)->lpVtbl -> get_SizeInByte(This,__returnValue_get_SizeInByte__) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIFileClass_INTERFACE_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5D779A6F-A8F9-55DF-A5C9-C1E63DD9E4C6")
    __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass : public IInspectable
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClassVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass * This,
            /* [out] */ TrustLevel *trustLevel);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClassVtbl;

    interface __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass
    {
        CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClassVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_INTERFACE_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6D41CE8B-48CC-5CA6-A397-4951356131BC")
    __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ParseFromPath( 
            /* [in] */ HSTRING path,
            /* [out][retval] */ __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass **__returnValue_ParseFromPath__) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ParseFromStream( 
            /* [in] */ __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper *stream,
            /* [out][retval] */ __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass **__returnValue_ParseFromStream__) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStaticVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic, ParseFromPath)
        HRESULT ( STDMETHODCALLTYPE *ParseFromPath )( 
            __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic * This,
            /* [in] */ HSTRING path,
            /* [out][retval] */ __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass **__returnValue_ParseFromPath__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic, ParseFromStream)
        HRESULT ( STDMETHODCALLTYPE *ParseFromStream )( 
            __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic * This,
            /* [in] */ __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper *stream,
            /* [out][retval] */ __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass **__returnValue_ParseFromStream__);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStaticVtbl;

    interface __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic
    {
        CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStaticVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_ParseFromPath(This,path,__returnValue_ParseFromPath__)	\
    ( (This)->lpVtbl -> ParseFromPath(This,path,__returnValue_ParseFromPath__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_ParseFromStream(This,stream,__returnValue_ParseFromStream__)	\
    ( (This)->lpVtbl -> ParseFromStream(This,stream,__returnValue_ParseFromStream__) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_INTERFACE_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("46A8BABC-13B9-5B22-A7BC-007EDEA03028")
    __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass : public IInspectable
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [out][retval] */ HSTRING *__returnValue_get_Name__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Values( 
            /* [out] */ UINT32 *____returnValue_get_Values__Size,
            /* [out][retval][size_is][size_is] */ __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass ***__returnValue_get_Values__) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClassVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass, get_Name)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_Name__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass, get_Values)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Values )( 
            __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass * This,
            /* [out] */ UINT32 *____returnValue_get_Values__Size,
            /* [out][retval][size_is][size_is] */ __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass ***__returnValue_get_Values__);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClassVtbl;

    interface __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass
    {
        CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClassVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_get_Name(This,__returnValue_get_Name__)	\
    ( (This)->lpVtbl -> get_Name(This,__returnValue_get_Name__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_get_Values(This,____returnValue_get_Values__Size,__returnValue_get_Values__)	\
    ( (This)->lpVtbl -> get_Values(This,____returnValue_get_Values__Size,__returnValue_get_Values__) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_INTERFACE_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2BDF2C4-239A-535A-AD89-2C439B9FBBC0")
    __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass : public IInspectable
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [out][retval] */ HSTRING *__returnValue_get_Name__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [out][retval] */ __x_ABI_CUFCase_CHost_CManifest_CRegistryValueType *__returnValue_get_Type__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Data( 
            /* [out][retval] */ IInspectable **__returnValue_get_Data__) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClassVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass, get_Name)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_Name__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass, get_Type)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This,
            /* [out][retval] */ __x_ABI_CUFCase_CHost_CManifest_CRegistryValueType *__returnValue_get_Type__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass, get_Data)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Data )( 
            __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This,
            /* [out][retval] */ IInspectable **__returnValue_get_Data__);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClassVtbl;

    interface __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass
    {
        CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClassVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_get_Name(This,__returnValue_get_Name__)	\
    ( (This)->lpVtbl -> get_Name(This,__returnValue_get_Name__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_get_Type(This,__returnValue_get_Type__)	\
    ( (This)->lpVtbl -> get_Type(This,__returnValue_get_Type__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_get_Data(This,__returnValue_get_Data__)	\
    ( (This)->lpVtbl -> get_Data(This,__returnValue_get_Data__) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_INTERFACE_DEFINED__ */


#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_INTERFACE_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_INTERFACE_DEFINED__

/* interface __x_ABI_CUFCase_CHost_CManifest_CIVersionClass */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIVersionClass;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9B56B015-02B3-5D08-8F39-43E5E5F74EC0")
    __x_ABI_CUFCase_CHost_CManifest_CIVersionClass : public IInspectable
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Major( 
            /* [out][retval] */ INT32 *__returnValue_get_Major__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Minor( 
            /* [out][retval] */ INT32 *__returnValue_get_Minor__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Build( 
            /* [out][retval] */ INT32 *__returnValue_get_Build__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Revision( 
            /* [out][retval] */ INT32 *__returnValue_get_Revision__) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [out][retval] */ HSTRING *__returnValue_get_Value__) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct __x_ABI_CUFCase_CHost_CManifest_CIVersionClassVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIVersionClass, get_Major)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Major )( 
            __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
            /* [out][retval] */ INT32 *__returnValue_get_Major__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIVersionClass, get_Minor)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Minor )( 
            __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
            /* [out][retval] */ INT32 *__returnValue_get_Minor__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIVersionClass, get_Build)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Build )( 
            __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
            /* [out][retval] */ INT32 *__returnValue_get_Build__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIVersionClass, get_Revision)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Revision )( 
            __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
            /* [out][retval] */ INT32 *__returnValue_get_Revision__);
        
        DECLSPEC_XFGVIRT(__x_ABI_CUFCase_CHost_CManifest_CIVersionClass, get_Value)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
            /* [out][retval] */ HSTRING *__returnValue_get_Value__);
        
        END_INTERFACE
    } __x_ABI_CUFCase_CHost_CManifest_CIVersionClassVtbl;

    interface __x_ABI_CUFCase_CHost_CManifest_CIVersionClass
    {
        CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIVersionClassVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_get_Major(This,__returnValue_get_Major__)	\
    ( (This)->lpVtbl -> get_Major(This,__returnValue_get_Major__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_get_Minor(This,__returnValue_get_Minor__)	\
    ( (This)->lpVtbl -> get_Minor(This,__returnValue_get_Minor__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_get_Build(This,__returnValue_get_Build__)	\
    ( (This)->lpVtbl -> get_Build(This,__returnValue_get_Build__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_get_Revision(This,__returnValue_get_Revision__)	\
    ( (This)->lpVtbl -> get_Revision(This,__returnValue_get_Revision__) ) 

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_get_Value(This,__returnValue_get_Value__)	\
    ( (This)->lpVtbl -> get_Value(This,__returnValue_get_Value__) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_INTERFACE_DEFINED__ */


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


