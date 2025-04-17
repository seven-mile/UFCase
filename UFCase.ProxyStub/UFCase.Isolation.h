/* Header file automatically generated from UFCase.Isolation.idl */
/*
 * File built with Microsoft(R) MIDLRT Compiler Engine Version 10.00.0231 
 */

#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif /*COM_NO_WINDOWS_H*/
#ifndef __UFCase2EIsolation_h__
#define __UFCase2EIsolation_h__
#ifndef __UFCase2EIsolation_p_h__
#define __UFCase2EIsolation_p_h__


#pragma once

// Ensure that the setting of the /ns_prefix command line switch is consistent for all headers.
// If you get an error from the compiler indicating "warning C4005: 'CHECK_NS_PREFIX_STATE': macro redefinition", this
// indicates that you have included two different headers with different settings for the /ns_prefix MIDL command line switch
#if !defined(DISABLE_NS_PREFIX_CHECKS)
#define CHECK_NS_PREFIX_STATE "always"
#endif // !defined(DISABLE_NS_PREFIX_CHECKS)


#pragma push_macro("MIDL_CONST_ID")
#undef MIDL_CONST_ID
#define MIDL_CONST_ID const __declspec(selectany)


//  API Contract Inclusion Definitions
#if !defined(SPECIFIC_API_CONTRACT_DEFINITIONS)
#if !defined(WINDOWS_APPLICATIONMODEL_CALLS_CALLSPHONECONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_CALLS_CALLSPHONECONTRACT_VERSION 0x70000
#endif // defined(WINDOWS_APPLICATIONMODEL_CALLS_CALLSPHONECONTRACT_VERSION)

#if !defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)
#define WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION 0x40000
#endif // defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)

#if !defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)
#define WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION 0x130000
#endif // defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)

#if !defined(WINDOWS_NETWORKING_SOCKETS_CONTROLCHANNELTRIGGERCONTRACT_VERSION)
#define WINDOWS_NETWORKING_SOCKETS_CONTROLCHANNELTRIGGERCONTRACT_VERSION 0x30000
#endif // defined(WINDOWS_NETWORKING_SOCKETS_CONTROLCHANNELTRIGGERCONTRACT_VERSION)

#if !defined(WINDOWS_PHONE_PHONECONTRACT_VERSION)
#define WINDOWS_PHONE_PHONECONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_PHONE_PHONECONTRACT_VERSION)

#if !defined(WINDOWS_PHONE_PHONEINTERNALCONTRACT_VERSION)
#define WINDOWS_PHONE_PHONEINTERNALCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_PHONE_PHONEINTERNALCONTRACT_VERSION)

#if !defined(WINDOWS_UI_WEBUI_CORE_WEBUICOMMANDBARCONTRACT_VERSION)
#define WINDOWS_UI_WEBUI_CORE_WEBUICOMMANDBARCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_UI_WEBUI_CORE_WEBUICOMMANDBARCONTRACT_VERSION)

#endif // defined(SPECIFIC_API_CONTRACT_DEFINITIONS)


// Header files for imported files
#include "inspectable.h"
#include "AsyncInfo.h"
#include "EventToken.h"
#include "Windows.Foundation.h"
#include "UFCase.Host.Manifest.h"
// Importing Collections header
#include <windows.foundation.collections.h>

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CUFCase_CIsolation_CIComponentModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIComponentModel_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            interface IComponentModel;
        } /* Isolation */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CIsolation_CIComponentModel ABI::UFCase::Isolation::IComponentModel

#endif // ____x_ABI_CUFCase_CIsolation_CIComponentModel_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CIsolation_CIFeatureModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIFeatureModel_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            interface IFeatureModel;
        } /* Isolation */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CIsolation_CIFeatureModel ABI::UFCase::Isolation::IFeatureModel

#endif // ____x_ABI_CUFCase_CIsolation_CIFeatureModel_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CIsolation_CIHost_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIHost_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            interface IHost;
        } /* Isolation */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CIsolation_CIHost ABI::UFCase::Isolation::IHost

#endif // ____x_ABI_CUFCase_CIsolation_CIHost_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CIsolation_CIHostManager_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIHostManager_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            interface IHostManager;
        } /* Isolation */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CIsolation_CIHostManager ABI::UFCase::Isolation::IHostManager

#endif // ____x_ABI_CUFCase_CIsolation_CIHostManager_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            interface IHostManagerSingleton;
        } /* Isolation */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton ABI::UFCase::Isolation::IHostManagerSingleton

#endif // ____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CIsolation_CIImageModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIImageModel_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            interface IImageModel;
        } /* Isolation */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CIsolation_CIImageModel ABI::UFCase::Isolation::IImageModel

#endif // ____x_ABI_CUFCase_CIsolation_CIImageModel_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CIsolation_CIPackageModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIPackageModel_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            interface IPackageModel;
        } /* Isolation */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CIsolation_CIPackageModel ABI::UFCase::Isolation::IPackageModel

#endif // ____x_ABI_CUFCase_CIsolation_CIPackageModel_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CIsolation_CISessionModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CISessionModel_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            interface ISessionModel;
        } /* Isolation */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CIsolation_CISessionModel ABI::UFCase::Isolation::ISessionModel

#endif // ____x_ABI_CUFCase_CIsolation_CISessionModel_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CIsolation_CIStoreModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIStoreModel_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            interface IStoreModel;
        } /* Isolation */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CIsolation_CIStoreModel ABI::UFCase::Isolation::IStoreModel

#endif // ____x_ABI_CUFCase_CIsolation_CIStoreModel_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            struct ComponentFileModel;
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */


#ifndef DEF___FIIterator_1_UFCase__CIsolation__CComponentFileModel_USE
#define DEF___FIIterator_1_UFCase__CIsolation__CComponentFileModel_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("3c2f62e6-ceef-59c0-9e0f-0266eb1744ca"))
IIterator<struct ABI::UFCase::Isolation::ComponentFileModel> : IIterator_impl<struct ABI::UFCase::Isolation::ComponentFileModel> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterator`1<UFCase.Isolation.ComponentFileModel>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<struct ABI::UFCase::Isolation::ComponentFileModel> __FIIterator_1_UFCase__CIsolation__CComponentFileModel_t;
#define __FIIterator_1_UFCase__CIsolation__CComponentFileModel ABI::Windows::Foundation::Collections::__FIIterator_1_UFCase__CIsolation__CComponentFileModel_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterator_1_UFCase__CIsolation__CComponentFileModel ABI::Windows::Foundation::Collections::IIterator<ABI::UFCase::Isolation::ComponentFileModel>
//#define __FIIterator_1_UFCase__CIsolation__CComponentFileModel_t ABI::Windows::Foundation::Collections::IIterator<ABI::UFCase::Isolation::ComponentFileModel>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_UFCase__CIsolation__CComponentFileModel_USE */





#ifndef DEF___FIIterable_1_UFCase__CIsolation__CComponentFileModel_USE
#define DEF___FIIterable_1_UFCase__CIsolation__CComponentFileModel_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("abe0626b-7b6f-55e0-bdb5-477c4b37a8ef"))
IIterable<struct ABI::UFCase::Isolation::ComponentFileModel> : IIterable_impl<struct ABI::UFCase::Isolation::ComponentFileModel> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterable`1<UFCase.Isolation.ComponentFileModel>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<struct ABI::UFCase::Isolation::ComponentFileModel> __FIIterable_1_UFCase__CIsolation__CComponentFileModel_t;
#define __FIIterable_1_UFCase__CIsolation__CComponentFileModel ABI::Windows::Foundation::Collections::__FIIterable_1_UFCase__CIsolation__CComponentFileModel_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterable_1_UFCase__CIsolation__CComponentFileModel ABI::Windows::Foundation::Collections::IIterable<ABI::UFCase::Isolation::ComponentFileModel>
//#define __FIIterable_1_UFCase__CIsolation__CComponentFileModel_t ABI::Windows::Foundation::Collections::IIterable<ABI::UFCase::Isolation::ComponentFileModel>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_UFCase__CIsolation__CComponentFileModel_USE */



namespace ABI {
    namespace UFCase {
        namespace Isolation {
            class FeatureModel;
        } /* Isolation */
    } /* UFCase */
} /* ABI */



#ifndef DEF___FIIterator_1_UFCase__CIsolation__CFeatureModel_USE
#define DEF___FIIterator_1_UFCase__CIsolation__CFeatureModel_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("fdae1372-766b-5f3c-bc67-7b204817278a"))
IIterator<ABI::UFCase::Isolation::FeatureModel*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::UFCase::Isolation::FeatureModel*, ABI::UFCase::Isolation::IFeatureModel*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterator`1<UFCase.Isolation.FeatureModel>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::UFCase::Isolation::FeatureModel*> __FIIterator_1_UFCase__CIsolation__CFeatureModel_t;
#define __FIIterator_1_UFCase__CIsolation__CFeatureModel ABI::Windows::Foundation::Collections::__FIIterator_1_UFCase__CIsolation__CFeatureModel_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterator_1_UFCase__CIsolation__CFeatureModel ABI::Windows::Foundation::Collections::IIterator<ABI::UFCase::Isolation::IFeatureModel*>
//#define __FIIterator_1_UFCase__CIsolation__CFeatureModel_t ABI::Windows::Foundation::Collections::IIterator<ABI::UFCase::Isolation::IFeatureModel*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_UFCase__CIsolation__CFeatureModel_USE */





#ifndef DEF___FIIterable_1_UFCase__CIsolation__CFeatureModel_USE
#define DEF___FIIterable_1_UFCase__CIsolation__CFeatureModel_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("ac8feca1-7324-5ab9-bb20-9b3eeb2d3e13"))
IIterable<ABI::UFCase::Isolation::FeatureModel*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::UFCase::Isolation::FeatureModel*, ABI::UFCase::Isolation::IFeatureModel*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterable`1<UFCase.Isolation.FeatureModel>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::UFCase::Isolation::FeatureModel*> __FIIterable_1_UFCase__CIsolation__CFeatureModel_t;
#define __FIIterable_1_UFCase__CIsolation__CFeatureModel ABI::Windows::Foundation::Collections::__FIIterable_1_UFCase__CIsolation__CFeatureModel_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterable_1_UFCase__CIsolation__CFeatureModel ABI::Windows::Foundation::Collections::IIterable<ABI::UFCase::Isolation::IFeatureModel*>
//#define __FIIterable_1_UFCase__CIsolation__CFeatureModel_t ABI::Windows::Foundation::Collections::IIterable<ABI::UFCase::Isolation::IFeatureModel*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_UFCase__CIsolation__CFeatureModel_USE */



namespace ABI {
    namespace UFCase {
        namespace Isolation {
            class PackageModel;
        } /* Isolation */
    } /* UFCase */
} /* ABI */



#ifndef DEF___FIIterator_1_UFCase__CIsolation__CPackageModel_USE
#define DEF___FIIterator_1_UFCase__CIsolation__CPackageModel_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("42f6edef-e12b-5dc0-a465-71eb9a214348"))
IIterator<ABI::UFCase::Isolation::PackageModel*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::UFCase::Isolation::PackageModel*, ABI::UFCase::Isolation::IPackageModel*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterator`1<UFCase.Isolation.PackageModel>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::UFCase::Isolation::PackageModel*> __FIIterator_1_UFCase__CIsolation__CPackageModel_t;
#define __FIIterator_1_UFCase__CIsolation__CPackageModel ABI::Windows::Foundation::Collections::__FIIterator_1_UFCase__CIsolation__CPackageModel_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterator_1_UFCase__CIsolation__CPackageModel ABI::Windows::Foundation::Collections::IIterator<ABI::UFCase::Isolation::IPackageModel*>
//#define __FIIterator_1_UFCase__CIsolation__CPackageModel_t ABI::Windows::Foundation::Collections::IIterator<ABI::UFCase::Isolation::IPackageModel*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_UFCase__CIsolation__CPackageModel_USE */





#ifndef DEF___FIIterable_1_UFCase__CIsolation__CPackageModel_USE
#define DEF___FIIterable_1_UFCase__CIsolation__CPackageModel_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("74190d90-0318-5822-887e-647d3e14a48b"))
IIterable<ABI::UFCase::Isolation::PackageModel*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::UFCase::Isolation::PackageModel*, ABI::UFCase::Isolation::IPackageModel*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterable`1<UFCase.Isolation.PackageModel>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::UFCase::Isolation::PackageModel*> __FIIterable_1_UFCase__CIsolation__CPackageModel_t;
#define __FIIterable_1_UFCase__CIsolation__CPackageModel ABI::Windows::Foundation::Collections::__FIIterable_1_UFCase__CIsolation__CPackageModel_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterable_1_UFCase__CIsolation__CPackageModel ABI::Windows::Foundation::Collections::IIterable<ABI::UFCase::Isolation::IPackageModel*>
//#define __FIIterable_1_UFCase__CIsolation__CPackageModel_t ABI::Windows::Foundation::Collections::IIterable<ABI::UFCase::Isolation::IPackageModel*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_UFCase__CIsolation__CPackageModel_USE */





#ifndef DEF___FIVectorView_1_UFCase__CIsolation__CPackageModel_USE
#define DEF___FIVectorView_1_UFCase__CIsolation__CPackageModel_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("ebc2dec9-269f-5e42-87da-327f66aa61b6"))
IVectorView<ABI::UFCase::Isolation::PackageModel*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::UFCase::Isolation::PackageModel*, ABI::UFCase::Isolation::IPackageModel*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IVectorView`1<UFCase.Isolation.PackageModel>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::UFCase::Isolation::PackageModel*> __FIVectorView_1_UFCase__CIsolation__CPackageModel_t;
#define __FIVectorView_1_UFCase__CIsolation__CPackageModel ABI::Windows::Foundation::Collections::__FIVectorView_1_UFCase__CIsolation__CPackageModel_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIVectorView_1_UFCase__CIsolation__CPackageModel ABI::Windows::Foundation::Collections::IVectorView<ABI::UFCase::Isolation::IPackageModel*>
//#define __FIVectorView_1_UFCase__CIsolation__CPackageModel_t ABI::Windows::Foundation::Collections::IVectorView<ABI::UFCase::Isolation::IPackageModel*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_UFCase__CIsolation__CPackageModel_USE */





#ifndef DEF___FIVector_1_UFCase__CIsolation__CPackageModel_USE
#define DEF___FIVector_1_UFCase__CIsolation__CPackageModel_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("88b85353-1699-5fa2-8b7c-21c66dba1f4a"))
IVector<ABI::UFCase::Isolation::PackageModel*> : IVector_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::UFCase::Isolation::PackageModel*, ABI::UFCase::Isolation::IPackageModel*>> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IVector`1<UFCase.Isolation.PackageModel>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<ABI::UFCase::Isolation::PackageModel*> __FIVector_1_UFCase__CIsolation__CPackageModel_t;
#define __FIVector_1_UFCase__CIsolation__CPackageModel ABI::Windows::Foundation::Collections::__FIVector_1_UFCase__CIsolation__CPackageModel_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIVector_1_UFCase__CIsolation__CPackageModel ABI::Windows::Foundation::Collections::IVector<ABI::UFCase::Isolation::IPackageModel*>
//#define __FIVector_1_UFCase__CIsolation__CPackageModel_t ABI::Windows::Foundation::Collections::IVector<ABI::UFCase::Isolation::IPackageModel*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_UFCase__CIsolation__CPackageModel_USE */




#ifndef DEF___FIAsyncActionProgressHandler_1_UINT32_USE
#define DEF___FIAsyncActionProgressHandler_1_UINT32_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("b7f0b891-6d95-5c32-a91f-65f7a311b0e9"))
IAsyncActionProgressHandler<UINT32> : IAsyncActionProgressHandler_impl<UINT32> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.AsyncActionProgressHandler`1<UInt32>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncActionProgressHandler<UINT32> __FIAsyncActionProgressHandler_1_UINT32_t;
#define __FIAsyncActionProgressHandler_1_UINT32 ABI::Windows::Foundation::__FIAsyncActionProgressHandler_1_UINT32_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIAsyncActionProgressHandler_1_UINT32 ABI::Windows::Foundation::IAsyncActionProgressHandler<UINT32>
//#define __FIAsyncActionProgressHandler_1_UINT32_t ABI::Windows::Foundation::IAsyncActionProgressHandler<UINT32>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncActionProgressHandler_1_UINT32_USE */




#ifndef DEF___FIAsyncActionWithProgressCompletedHandler_1_UINT32_USE
#define DEF___FIAsyncActionWithProgressCompletedHandler_1_UINT32_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("1f29e65e-49e0-577d-ac96-bcf0087e563d"))
IAsyncActionWithProgressCompletedHandler<UINT32> : IAsyncActionWithProgressCompletedHandler_impl<UINT32> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.AsyncActionWithProgressCompletedHandler`1<UInt32>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncActionWithProgressCompletedHandler<UINT32> __FIAsyncActionWithProgressCompletedHandler_1_UINT32_t;
#define __FIAsyncActionWithProgressCompletedHandler_1_UINT32 ABI::Windows::Foundation::__FIAsyncActionWithProgressCompletedHandler_1_UINT32_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIAsyncActionWithProgressCompletedHandler_1_UINT32 ABI::Windows::Foundation::IAsyncActionWithProgressCompletedHandler<UINT32>
//#define __FIAsyncActionWithProgressCompletedHandler_1_UINT32_t ABI::Windows::Foundation::IAsyncActionWithProgressCompletedHandler<UINT32>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncActionWithProgressCompletedHandler_1_UINT32_USE */




#ifndef DEF___FIAsyncActionWithProgress_1_UINT32_USE
#define DEF___FIAsyncActionWithProgress_1_UINT32_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("429f47f0-1388-5b75-b44c-44ddc4f525c0"))
IAsyncActionWithProgress<UINT32> : IAsyncActionWithProgress_impl<UINT32> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.IAsyncActionWithProgress`1<UInt32>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncActionWithProgress<UINT32> __FIAsyncActionWithProgress_1_UINT32_t;
#define __FIAsyncActionWithProgress_1_UINT32 ABI::Windows::Foundation::__FIAsyncActionWithProgress_1_UINT32_t
/* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIAsyncActionWithProgress_1_UINT32 ABI::Windows::Foundation::IAsyncActionWithProgress<UINT32>
//#define __FIAsyncActionWithProgress_1_UINT32_t ABI::Windows::Foundation::IAsyncActionWithProgress<UINT32>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncActionWithProgress_1_UINT32_USE */





#ifndef DEF___FIIterator_1_IInspectable_USE
#define DEF___FIIterator_1_IInspectable_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("44a94f2d-04f8-5091-b336-be7892dd10be"))
IIterator<IInspectable*> : IIterator_impl<IInspectable*> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterator`1<Object>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<IInspectable*> __FIIterator_1_IInspectable_t;
#define __FIIterator_1_IInspectable ABI::Windows::Foundation::Collections::__FIIterator_1_IInspectable_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterator_1_IInspectable ABI::Windows::Foundation::Collections::IIterator<IInspectable*>
//#define __FIIterator_1_IInspectable_t ABI::Windows::Foundation::Collections::IIterator<IInspectable*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_IInspectable_USE */





#ifndef DEF___FIIterable_1_IInspectable_USE
#define DEF___FIIterable_1_IInspectable_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("092b849b-60b1-52be-a44a-6fe8e933cbe4"))
IIterable<IInspectable*> : IIterable_impl<IInspectable*> 
{
    static const wchar_t* z_get_rc_name_impl() 
    {
        return L"Windows.Foundation.Collections.IIterable`1<Object>"; 
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<IInspectable*> __FIIterable_1_IInspectable_t;
#define __FIIterable_1_IInspectable ABI::Windows::Foundation::Collections::__FIIterable_1_IInspectable_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ } 

////  Define an alias for the C version of the interface for compatibility purposes.
//#define __FIIterable_1_IInspectable ABI::Windows::Foundation::Collections::IIterable<IInspectable*>
//#define __FIIterable_1_IInspectable_t ABI::Windows::Foundation::Collections::IIterable<IInspectable*>
#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_IInspectable_USE */





namespace ABI {
    namespace UFCase {
        namespace Isolation {
            
            typedef enum CbsInstallState : int CbsInstallState;
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */

namespace ABI {
    namespace UFCase {
        namespace Isolation {
            
            typedef enum CbsOperationType : int CbsOperationType;
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */

namespace ABI {
    namespace UFCase {
        namespace Isolation {
            
            typedef enum CsiComponentStatus : int CsiComponentStatus;
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */

namespace ABI {
    namespace UFCase {
        namespace Isolation {
            
            typedef enum ImageType : int ImageType;
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */

namespace ABI {
    namespace UFCase {
        namespace Isolation {
            
            typedef struct ComponentFileModel ComponentFileModel;
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */

namespace ABI {
    namespace UFCase {
        namespace Isolation {
            
            typedef struct ImageVersion ImageVersion;
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */










namespace ABI {
    namespace UFCase {
        namespace Isolation {
            class ComponentModel;
        } /* Isolation */
    } /* UFCase */
} /* ABI */



namespace ABI {
    namespace UFCase {
        namespace Isolation {
            class Host;
        } /* Isolation */
    } /* UFCase */
} /* ABI */


namespace ABI {
    namespace UFCase {
        namespace Isolation {
            class HostManager;
        } /* Isolation */
    } /* UFCase */
} /* ABI */


namespace ABI {
    namespace UFCase {
        namespace Isolation {
            class HostManagerSingleton;
        } /* Isolation */
    } /* UFCase */
} /* ABI */


namespace ABI {
    namespace UFCase {
        namespace Isolation {
            class ImageModel;
        } /* Isolation */
    } /* UFCase */
} /* ABI */



namespace ABI {
    namespace UFCase {
        namespace Isolation {
            class SessionModel;
        } /* Isolation */
    } /* UFCase */
} /* ABI */


namespace ABI {
    namespace UFCase {
        namespace Isolation {
            class StoreModel;
        } /* Isolation */
    } /* UFCase */
} /* ABI */








/*
 *
 * Struct UFCase.Isolation.CbsInstallState
 *
 */

namespace ABI {
    namespace UFCase {
        namespace Isolation {
            /* [v1_enum, version] */
            enum CbsInstallState : int
            {
                CbsInstallState_CbsInstallStatePartiallyInstalled = -19,
                CbsInstallState_CbsInstallStateCancel = -18,
                CbsInstallState_CbsInstallStateSuperseded = -17,
                CbsInstallState_CbsInstallStateDefault = -16,
                CbsInstallState_CbsInvalidStatePermanent = -8,
                CbsInstallState_CbsInvalidStateInstalled = -7,
                CbsInstallState_CbsInvalidStateStaged = -4,
                CbsInstallState_CbsInvalidStateResolved = -2,
                CbsInstallState_CbsInstallStateUnknown = -1,
                CbsInstallState_CbsInstallStateAbsent = 0,
                CbsInstallState_CbsInstallStateResolving = 1,
                CbsInstallState_CbsInstallStateResolved = 2,
                CbsInstallState_CbsInstallStateStaging = 3,
                CbsInstallState_CbsInstallStateStaged = 4,
                CbsInstallState_CbsInstallStateUninstallRequested = 5,
                CbsInstallState_CbsInstallStateInstallRequested = 6,
                CbsInstallState_CbsInstallStateInstalled = 7,
                CbsInstallState_CbsInstallStatePermanent = 8,
                CbsInstallState_CbsInstallStateInvalid = 2147483647,
            };
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */


/*
 *
 * Struct UFCase.Isolation.CbsOperationType
 *
 */

namespace ABI {
    namespace UFCase {
        namespace Isolation {
            /* [v1_enum, version] */
            enum CbsOperationType : int
            {
                CbsOperationType_ExportRepository = 1,
                CbsOperationType_UpdateImage = 2,
                CbsOperationType_PerformPrepareServicingOperation = 3,
                CbsOperationType_PerformLateAcquisitionOperation = 4,
                CbsOperationType_InitICSIStore = 8,
            };
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */


/*
 *
 * Struct UFCase.Isolation.CsiComponentStatus
 *
 */

namespace ABI {
    namespace UFCase {
        namespace Isolation {
            /* [v1_enum, version] */
            enum CsiComponentStatus : int
            {
                CsiComponentStatus_Prestaged = 1,
                CsiComponentStatus_Staged = 2,
                CsiComponentStatus_Pinned = 3,
                CsiComponentStatus_Installed = 4,
                CsiComponentStatus_InstalledMismatch = 5,
            };
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */


/*
 *
 * Struct UFCase.Isolation.ImageType
 *
 */

namespace ABI {
    namespace UFCase {
        namespace Isolation {
            /* [v1_enum, version] */
            enum ImageType : int
            {
                ImageType_Online = 0,
                ImageType_Offline = 1,
            };
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */


/*
 *
 * Struct UFCase.Isolation.ComponentFileModel
 *
 */

namespace ABI {
    namespace UFCase {
        namespace Isolation {
            /* [version] */
            struct ComponentFileModel
            {
                HSTRING Name;
                HSTRING Status;
            };
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */


/*
 *
 * Struct UFCase.Isolation.ImageVersion
 *
 */

namespace ABI {
    namespace UFCase {
        namespace Isolation {
            /* [version] */
            struct ImageVersion
            {
                UINT32 Major;
                UINT32 Minor;
                UINT32 Build;
                UINT32 Revision;
            };
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */


/*
 *
 * Interface UFCase.Isolation.IComponentModel
 *
 * Interface is a part of the implementation of type UFCase.Isolation.ComponentModel
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CIComponentModel_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CIComponentModel_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_IComponentModel[] = L"UFCase.Isolation.IComponentModel";
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            /* [object, version, uuid("792DF753-4ACE-5718-A4D4-EB96A6454C5A"), exclusiveto] */
            MIDL_INTERFACE("792DF753-4ACE-5718-A4D4-EB96A6454C5A")
            IComponentModel : public IInspectable
            {
            public:
                /* [overload] */virtual HRESULT STDMETHODCALLTYPE GetAttribute(
                    /* [in] */HSTRING name,
                    /* [retval, out] */HSTRING * result
                    ) = 0;
                /* [overload] */virtual HRESULT STDMETHODCALLTYPE GetAttribute2(
                    /* [in] */HSTRING name_space,
                    /* [in] */HSTRING name,
                    /* [retval, out] */HSTRING * result
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_TextForm(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_KeyForm(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Manifest(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_CookedManifest(
                    /* [retval, out] */ABI::UFCase::Host::Manifest::IAssemblyClass * * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Status(
                    /* [retval, out] */ABI::UFCase::Isolation::CsiComponentStatus * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PayloadPath(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE GetFileCollection(
                    /* [in] */UINT32 dwFlags,
                    /* [retval, out] */__FIIterable_1_UFCase__CIsolation__CComponentFileModel * * result
                    ) = 0;
                
            };

            MIDL_CONST_ID IID & IID_IComponentModel=__uuidof(IComponentModel);
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIComponentModel;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CIComponentModel_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Isolation.IFeatureModel
 *
 * Interface is a part of the implementation of type UFCase.Isolation.FeatureModel
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CIFeatureModel_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CIFeatureModel_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_IFeatureModel[] = L"UFCase.Isolation.IFeatureModel";
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            /* [object, version, uuid("4DB90A80-741A-5540-BC15-4E9F46A5A56B"), exclusiveto] */
            MIDL_INTERFACE("4DB90A80-741A-5540-BC15-4E9F46A5A56B")
            IFeatureModel : public IInspectable
            {
            public:
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_CurrentState(
                    /* [retval, out] */ABI::UFCase::Isolation::CbsInstallState * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_RequestedState(
                    /* [retval, out] */ABI::UFCase::Isolation::CbsInstallState * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Name(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DisplayName(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Description(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DisplayFile(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Restart(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PsfName(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DownloadSize(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_SetMembership(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ContentPackage(
                    /* [retval, out] */ABI::UFCase::Isolation::IPackageModel * * value
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE Enable(void) = 0;
                virtual HRESULT STDMETHODCALLTYPE Disable(void) = 0;
                virtual HRESULT STDMETHODCALLTYPE GetParentFeatureCollection(
                    /* [retval, out] */__FIIterable_1_UFCase__CIsolation__CFeatureModel * * result
                    ) = 0;
                
            };

            MIDL_CONST_ID IID & IID_IFeatureModel=__uuidof(IFeatureModel);
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIFeatureModel;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CIFeatureModel_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Isolation.IHost
 *
 * Interface is a part of the implementation of type UFCase.Isolation.Host
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CIHost_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CIHost_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_IHost[] = L"UFCase.Isolation.IHost";
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            /* [object, version, uuid("6BD59CFB-CCEA-5E36-B07D-DAA8833D5E09"), exclusiveto] */
            MIDL_INTERFACE("6BD59CFB-CCEA-5E36-B07D-DAA8833D5E09")
            IHost : public IInspectable
            {
            public:
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Id(
                    /* [retval, out] */GUID * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Bootdrive(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE Ping(void) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Image(
                    /* [retval, out] */ABI::UFCase::Isolation::IImageModel * * value
                    ) = 0;
                
            };

            MIDL_CONST_ID IID & IID_IHost=__uuidof(IHost);
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIHost;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CIHost_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Isolation.IHostManager
 *
 * Interface is a part of the implementation of type UFCase.Isolation.HostManager
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CIHostManager_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CIHostManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_IHostManager[] = L"UFCase.Isolation.IHostManager";
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            /* [object, version, uuid("FE58A347-7042-5FAD-B3D6-741CA21CE176"), exclusiveto] */
            MIDL_INTERFACE("FE58A347-7042-5FAD-B3D6-741CA21CE176")
            IHostManager : public IInspectable
            {
            public:
                virtual HRESULT STDMETHODCALLTYPE RegisterHost(
                    /* [in] */ABI::UFCase::Isolation::IHost * host
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE UnregisterHost(
                    /* [in] */ABI::UFCase::Isolation::IHost * host
                    ) = 0;
                
            };

            MIDL_CONST_ID IID & IID_IHostManager=__uuidof(IHostManager);
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIHostManager;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CIHostManager_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Isolation.IHostManagerSingleton
 *
 * Interface is a part of the implementation of type UFCase.Isolation.HostManagerSingleton
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_IHostManagerSingleton[] = L"UFCase.Isolation.IHostManagerSingleton";
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            /* [object, version, uuid("806A41FC-6AEA-5877-A7EA-4B012E59F865"), exclusiveto] */
            MIDL_INTERFACE("806A41FC-6AEA-5877-A7EA-4B012E59F865")
            IHostManagerSingleton : public IInspectable
            {
            public:
                virtual HRESULT STDMETHODCALLTYPE Current(
                    /* [retval, out] */ABI::UFCase::Isolation::IHostManager * * result
                    ) = 0;
                
            };

            MIDL_CONST_ID IID & IID_IHostManagerSingleton=__uuidof(IHostManagerSingleton);
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIHostManagerSingleton;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Isolation.IImageModel
 *
 * Interface is a part of the implementation of type UFCase.Isolation.ImageModel
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CIImageModel_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CIImageModel_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_IImageModel[] = L"UFCase.Isolation.IImageModel";
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            /* [object, version, uuid("13F4D846-68DA-53E9-88C6-495AA1B7B4A4"), exclusiveto] */
            MIDL_INTERFACE("13F4D846-68DA-53E9-88C6-495AA1B7B4A4")
            IImageModel : public IInspectable
            {
            public:
                virtual HRESULT STDMETHODCALLTYPE OpenSession(
                    /* [in] */UINT32 option,
                    /* [retval, out] */ABI::UFCase::Isolation::ISessionModel * * result
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE SxsStore(
                    /* [retval, out] */ABI::UFCase::Isolation::IStoreModel * * result
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE Bootdrive(
                    /* [retval, out] */HSTRING * result
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE WinDir(
                    /* [retval, out] */HSTRING * result
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE GetRegistryHive(
                    /* [in] */HSTRING hive_id,
                    /* [retval, out] */HSTRING * result
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE Type(
                    /* [retval, out] */ABI::UFCase::Isolation::ImageType * result
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE Version(
                    /* [retval, out] */ABI::UFCase::Isolation::ImageVersion * result
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE Edition(
                    /* [retval, out] */HSTRING * result
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE Architecture(
                    /* [retval, out] */HSTRING * result
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE IsWinPE(
                    /* [retval, out] */::boolean * result
                    ) = 0;
                
            };

            MIDL_CONST_ID IID & IID_IImageModel=__uuidof(IImageModel);
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIImageModel;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CIImageModel_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Isolation.IPackageModel
 *
 * Interface is a part of the implementation of type UFCase.Isolation.PackageModel
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CIPackageModel_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CIPackageModel_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_IPackageModel[] = L"UFCase.Isolation.IPackageModel";
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            /* [object, version, uuid("43786F4F-0F87-5FDF-9E9A-661F8226D32E"), exclusiveto] */
            MIDL_INTERFACE("43786F4F-0F87-5FDF-9E9A-661F8226D32E")
            IPackageModel : public IInspectable
            {
            public:
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Session(
                    /* [retval, out] */ABI::UFCase::Isolation::ISessionModel * * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_State(
                    /* [retval, out] */ABI::UFCase::Isolation::CbsInstallState * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Name(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Description(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Identity(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ReleaseType(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_RestartRequired(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ProductName(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ProductVersion(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Company(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Copyright(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_SupportInformation(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_CreationTime(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_LastUpdateTime(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_InstallTime(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_InstallPackageName(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_InstallLocation(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_InstallClient(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_InstallUserName(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_IsApplicable(
                    /* [retval, out] */::boolean * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ManifestFilePath(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_RegistryPath(
                    /* [retval, out] */HSTRING * value
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE Install(void) = 0;
                virtual HRESULT STDMETHODCALLTYPE Remove(void) = 0;
                virtual HRESULT STDMETHODCALLTYPE Stage(void) = 0;
                virtual HRESULT STDMETHODCALLTYPE OpenFeature(
                    /* [in] */HSTRING name,
                    /* [retval, out] */ABI::UFCase::Isolation::IFeatureModel * * result
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE GetFeatureCollection(
                    /* [in] */UINT32 applicability,
                    /* [in] */UINT32 selectability,
                    /* [retval, out] */__FIIterable_1_UFCase__CIsolation__CFeatureModel * * result
                    ) = 0;
                
            };

            MIDL_CONST_ID IID & IID_IPackageModel=__uuidof(IPackageModel);
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIPackageModel;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CIPackageModel_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Isolation.ISessionModel
 *
 * Interface is a part of the implementation of type UFCase.Isolation.SessionModel
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CISessionModel_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CISessionModel_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_ISessionModel[] = L"UFCase.Isolation.ISessionModel";
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            /* [object, version, uuid("D4B1314D-679D-5256-B032-D3FD6CAB4782"), exclusiveto] */
            MIDL_INTERFACE("D4B1314D-679D-5256-B032-D3FD6CAB4782")
            ISessionModel : public IInspectable
            {
            public:
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Image(
                    /* [retval, out] */ABI::UFCase::Isolation::IImageModel * * value
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE AddSource(
                    /* [in] */HSTRING source
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE SaveChanges(
                    /* [retval, out] */__FIAsyncActionWithProgress_1_UINT32 * * operation
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE OpenPackage(
                    /* [in] */HSTRING identity,
                    /* [retval, out] */ABI::UFCase::Isolation::IPackageModel * * result
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE GetPackageCollection(
                    /* [in] */UINT32 option,
                    /* [retval, out] */__FIVector_1_UFCase__CIsolation__CPackageModel * * result
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_FoundationPackage(
                    /* [retval, out] */ABI::UFCase::Isolation::IPackageModel * * value
                    ) = 0;
                /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ProductPackage(
                    /* [retval, out] */ABI::UFCase::Isolation::IPackageModel * * value
                    ) = 0;
                virtual HRESULT STDMETHODCALLTYPE PerformOperation(
                    /* [in] */ABI::UFCase::Isolation::CbsOperationType op
                    ) = 0;
                
            };

            MIDL_CONST_ID IID & IID_ISessionModel=__uuidof(ISessionModel);
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CISessionModel;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CISessionModel_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Isolation.IStoreModel
 *
 * Interface is a part of the implementation of type UFCase.Isolation.StoreModel
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CIStoreModel_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CIStoreModel_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_IStoreModel[] = L"UFCase.Isolation.IStoreModel";
namespace ABI {
    namespace UFCase {
        namespace Isolation {
            /* [object, version, uuid("FE3C8E81-A790-528D-A986-80E6A9722BAA"), exclusiveto] */
            MIDL_INTERFACE("FE3C8E81-A790-528D-A986-80E6A9722BAA")
            IStoreModel : public IInspectable
            {
            public:
                virtual HRESULT STDMETHODCALLTYPE OpenComponent(
                    /* [in] */HSTRING definition,
                    /* [retval, out] */ABI::UFCase::Isolation::IComponentModel * * result
                    ) = 0;
                /* [overload] */virtual HRESULT STDMETHODCALLTYPE GetComponentCollection(
                    /* [retval, out] */__FIIterable_1_IInspectable * * result
                    ) = 0;
                /* [overload] */virtual HRESULT STDMETHODCALLTYPE GetComponentCollection2(
                    /* [in] */HSTRING reference,
                    /* [retval, out] */__FIIterable_1_IInspectable * * result
                    ) = 0;
                
            };

            MIDL_CONST_ID IID & IID_IStoreModel=__uuidof(IStoreModel);
            
        } /* Isolation */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIStoreModel;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CIStoreModel_INTERFACE_DEFINED__) */


/*
 *
 * Class UFCase.Isolation.ComponentModel
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.IComponentModel ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_ComponentModel_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_ComponentModel_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_ComponentModel[] = L"UFCase.Isolation.ComponentModel";
#endif


/*
 *
 * Class UFCase.Isolation.FeatureModel
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.IFeatureModel ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_FeatureModel_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_FeatureModel_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_FeatureModel[] = L"UFCase.Isolation.FeatureModel";
#endif


/*
 *
 * Class UFCase.Isolation.Host
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.IHost ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_Host_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_Host_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_Host[] = L"UFCase.Isolation.Host";
#endif


/*
 *
 * Class UFCase.Isolation.HostManager
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.IHostManager ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_HostManager_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_HostManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_HostManager[] = L"UFCase.Isolation.HostManager";
#endif


/*
 *
 * Class UFCase.Isolation.HostManagerSingleton
 *
 * RuntimeClass can be activated.
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.IHostManagerSingleton ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_HostManagerSingleton_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_HostManagerSingleton_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_HostManagerSingleton[] = L"UFCase.Isolation.HostManagerSingleton";
#endif


/*
 *
 * Class UFCase.Isolation.ImageModel
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.IImageModel ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_ImageModel_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_ImageModel_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_ImageModel[] = L"UFCase.Isolation.ImageModel";
#endif


/*
 *
 * Class UFCase.Isolation.PackageModel
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.IPackageModel ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_PackageModel_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_PackageModel_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_PackageModel[] = L"UFCase.Isolation.PackageModel";
#endif


/*
 *
 * Class UFCase.Isolation.SessionModel
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.ISessionModel ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_SessionModel_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_SessionModel_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_SessionModel[] = L"UFCase.Isolation.SessionModel";
#endif


/*
 *
 * Class UFCase.Isolation.StoreModel
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.IStoreModel ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_StoreModel_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_StoreModel_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_StoreModel[] = L"UFCase.Isolation.StoreModel";
#endif



#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CUFCase_CIsolation_CIComponentModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIComponentModel_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CIComponentModel __x_ABI_CUFCase_CIsolation_CIComponentModel;

#endif // ____x_ABI_CUFCase_CIsolation_CIComponentModel_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CIsolation_CIFeatureModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIFeatureModel_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CIFeatureModel __x_ABI_CUFCase_CIsolation_CIFeatureModel;

#endif // ____x_ABI_CUFCase_CIsolation_CIFeatureModel_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CIsolation_CIHost_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIHost_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CIHost __x_ABI_CUFCase_CIsolation_CIHost;

#endif // ____x_ABI_CUFCase_CIsolation_CIHost_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CIsolation_CIHostManager_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIHostManager_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CIHostManager __x_ABI_CUFCase_CIsolation_CIHostManager;

#endif // ____x_ABI_CUFCase_CIsolation_CIHostManager_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton;

#endif // ____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CIsolation_CIImageModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIImageModel_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CIImageModel __x_ABI_CUFCase_CIsolation_CIImageModel;

#endif // ____x_ABI_CUFCase_CIsolation_CIImageModel_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CIsolation_CIPackageModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIPackageModel_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CIPackageModel __x_ABI_CUFCase_CIsolation_CIPackageModel;

#endif // ____x_ABI_CUFCase_CIsolation_CIPackageModel_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CIsolation_CISessionModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CISessionModel_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CISessionModel __x_ABI_CUFCase_CIsolation_CISessionModel;

#endif // ____x_ABI_CUFCase_CIsolation_CISessionModel_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CIsolation_CIStoreModel_FWD_DEFINED__
#define ____x_ABI_CUFCase_CIsolation_CIStoreModel_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CIsolation_CIStoreModel __x_ABI_CUFCase_CIsolation_CIStoreModel;

#endif // ____x_ABI_CUFCase_CIsolation_CIStoreModel_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions
struct __x_ABI_CUFCase_CIsolation_CComponentFileModel;

#if !defined(____FIIterator_1_UFCase__CIsolation__CComponentFileModel_INTERFACE_DEFINED__)
#define ____FIIterator_1_UFCase__CIsolation__CComponentFileModel_INTERFACE_DEFINED__

typedef interface __FIIterator_1_UFCase__CIsolation__CComponentFileModel __FIIterator_1_UFCase__CIsolation__CComponentFileModel;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_UFCase__CIsolation__CComponentFileModel;

typedef struct __FIIterator_1_UFCase__CIsolation__CComponentFileModelVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Current )(__RPC__in __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This, /* [retval][out] */ __RPC__out struct __x_ABI_CUFCase_CIsolation_CComponentFileModel *current);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasCurrent )(__RPC__in __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *MoveNext )(__RPC__in __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIIterator_1_UFCase__CIsolation__CComponentFileModel * This,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) struct __x_ABI_CUFCase_CIsolation_CComponentFileModel *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

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


#endif // ____FIIterator_1_UFCase__CIsolation__CComponentFileModel_INTERFACE_DEFINED__



#if !defined(____FIIterable_1_UFCase__CIsolation__CComponentFileModel_INTERFACE_DEFINED__)
#define ____FIIterable_1_UFCase__CIsolation__CComponentFileModel_INTERFACE_DEFINED__

typedef interface __FIIterable_1_UFCase__CIsolation__CComponentFileModel __FIIterable_1_UFCase__CIsolation__CComponentFileModel;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_UFCase__CIsolation__CComponentFileModel;

typedef  struct __FIIterable_1_UFCase__CIsolation__CComponentFileModelVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterable_1_UFCase__CIsolation__CComponentFileModel * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterable_1_UFCase__CIsolation__CComponentFileModel * This);

    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterable_1_UFCase__CIsolation__CComponentFileModel * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterable_1_UFCase__CIsolation__CComponentFileModel * This,
                                           /* [out] */ __RPC__out ULONG *iidCount,
                                           /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterable_1_UFCase__CIsolation__CComponentFileModel * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterable_1_UFCase__CIsolation__CComponentFileModel * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *First )(__RPC__in __FIIterable_1_UFCase__CIsolation__CComponentFileModel * This, /* [retval][out] */ __RPC__deref_out_opt __FIIterator_1_UFCase__CIsolation__CComponentFileModel **first);

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


#endif // ____FIIterable_1_UFCase__CIsolation__CComponentFileModel_INTERFACE_DEFINED__



#if !defined(____FIIterator_1_UFCase__CIsolation__CFeatureModel_INTERFACE_DEFINED__)
#define ____FIIterator_1_UFCase__CIsolation__CFeatureModel_INTERFACE_DEFINED__

typedef interface __FIIterator_1_UFCase__CIsolation__CFeatureModel __FIIterator_1_UFCase__CIsolation__CFeatureModel;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_UFCase__CIsolation__CFeatureModel;

typedef struct __FIIterator_1_UFCase__CIsolation__CFeatureModelVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterator_1_UFCase__CIsolation__CFeatureModel * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterator_1_UFCase__CIsolation__CFeatureModel * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterator_1_UFCase__CIsolation__CFeatureModel * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterator_1_UFCase__CIsolation__CFeatureModel * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterator_1_UFCase__CIsolation__CFeatureModel * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterator_1_UFCase__CIsolation__CFeatureModel * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Current )(__RPC__in __FIIterator_1_UFCase__CIsolation__CFeatureModel * This, /* [retval][out] */ __RPC__out __x_ABI_CUFCase_CIsolation_CIFeatureModel * *current);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasCurrent )(__RPC__in __FIIterator_1_UFCase__CIsolation__CFeatureModel * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *MoveNext )(__RPC__in __FIIterator_1_UFCase__CIsolation__CFeatureModel * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIIterator_1_UFCase__CIsolation__CFeatureModel * This,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CUFCase_CIsolation_CIFeatureModel * *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

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


#endif // ____FIIterator_1_UFCase__CIsolation__CFeatureModel_INTERFACE_DEFINED__



#if !defined(____FIIterable_1_UFCase__CIsolation__CFeatureModel_INTERFACE_DEFINED__)
#define ____FIIterable_1_UFCase__CIsolation__CFeatureModel_INTERFACE_DEFINED__

typedef interface __FIIterable_1_UFCase__CIsolation__CFeatureModel __FIIterable_1_UFCase__CIsolation__CFeatureModel;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_UFCase__CIsolation__CFeatureModel;

typedef  struct __FIIterable_1_UFCase__CIsolation__CFeatureModelVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterable_1_UFCase__CIsolation__CFeatureModel * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterable_1_UFCase__CIsolation__CFeatureModel * This);

    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterable_1_UFCase__CIsolation__CFeatureModel * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterable_1_UFCase__CIsolation__CFeatureModel * This,
                                           /* [out] */ __RPC__out ULONG *iidCount,
                                           /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterable_1_UFCase__CIsolation__CFeatureModel * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterable_1_UFCase__CIsolation__CFeatureModel * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *First )(__RPC__in __FIIterable_1_UFCase__CIsolation__CFeatureModel * This, /* [retval][out] */ __RPC__deref_out_opt __FIIterator_1_UFCase__CIsolation__CFeatureModel **first);

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


#endif // ____FIIterable_1_UFCase__CIsolation__CFeatureModel_INTERFACE_DEFINED__



#if !defined(____FIIterator_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__)
#define ____FIIterator_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__

typedef interface __FIIterator_1_UFCase__CIsolation__CPackageModel __FIIterator_1_UFCase__CIsolation__CPackageModel;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_UFCase__CIsolation__CPackageModel;

typedef struct __FIIterator_1_UFCase__CIsolation__CPackageModelVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterator_1_UFCase__CIsolation__CPackageModel * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterator_1_UFCase__CIsolation__CPackageModel * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterator_1_UFCase__CIsolation__CPackageModel * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterator_1_UFCase__CIsolation__CPackageModel * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterator_1_UFCase__CIsolation__CPackageModel * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterator_1_UFCase__CIsolation__CPackageModel * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Current )(__RPC__in __FIIterator_1_UFCase__CIsolation__CPackageModel * This, /* [retval][out] */ __RPC__out __x_ABI_CUFCase_CIsolation_CIPackageModel * *current);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasCurrent )(__RPC__in __FIIterator_1_UFCase__CIsolation__CPackageModel * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *MoveNext )(__RPC__in __FIIterator_1_UFCase__CIsolation__CPackageModel * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIIterator_1_UFCase__CIsolation__CPackageModel * This,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CUFCase_CIsolation_CIPackageModel * *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

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


#endif // ____FIIterator_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__



#if !defined(____FIIterable_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__)
#define ____FIIterable_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__

typedef interface __FIIterable_1_UFCase__CIsolation__CPackageModel __FIIterable_1_UFCase__CIsolation__CPackageModel;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_UFCase__CIsolation__CPackageModel;

typedef  struct __FIIterable_1_UFCase__CIsolation__CPackageModelVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterable_1_UFCase__CIsolation__CPackageModel * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterable_1_UFCase__CIsolation__CPackageModel * This);

    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterable_1_UFCase__CIsolation__CPackageModel * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterable_1_UFCase__CIsolation__CPackageModel * This,
                                           /* [out] */ __RPC__out ULONG *iidCount,
                                           /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterable_1_UFCase__CIsolation__CPackageModel * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterable_1_UFCase__CIsolation__CPackageModel * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *First )(__RPC__in __FIIterable_1_UFCase__CIsolation__CPackageModel * This, /* [retval][out] */ __RPC__deref_out_opt __FIIterator_1_UFCase__CIsolation__CPackageModel **first);

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


#endif // ____FIIterable_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__



#if !defined(____FIVectorView_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__)
#define ____FIVectorView_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_UFCase__CIsolation__CPackageModel __FIVectorView_1_UFCase__CIsolation__CPackageModel;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_UFCase__CIsolation__CPackageModel;

typedef struct __FIVectorView_1_UFCase__CIsolation__CPackageModelVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIVectorView_1_UFCase__CIsolation__CPackageModel * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )( __RPC__in __FIVectorView_1_UFCase__CIsolation__CPackageModel * This);

    ULONG ( STDMETHODCALLTYPE *Release )( __RPC__in __FIVectorView_1_UFCase__CIsolation__CPackageModel * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )( __RPC__in __FIVectorView_1_UFCase__CIsolation__CPackageModel * This,
                                            /* [out] */ __RPC__out ULONG *iidCount,
                                            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
        __RPC__in __FIVectorView_1_UFCase__CIsolation__CPackageModel * This,
            /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
        __RPC__in __FIVectorView_1_UFCase__CIsolation__CPackageModel * This,
            /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *GetAt )( 
                                         __RPC__in __FIVectorView_1_UFCase__CIsolation__CPackageModel * This,
                                         /* [in] */ unsigned int index,
                                         /* [retval][out] */ __RPC__out __x_ABI_CUFCase_CIsolation_CIPackageModel * *item);

        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            __RPC__in __FIVectorView_1_UFCase__CIsolation__CPackageModel * This,
            /* [retval][out] */ __RPC__out unsigned int *size);

        HRESULT ( STDMETHODCALLTYPE *IndexOf )( 
                                               __RPC__in __FIVectorView_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ __x_ABI_CUFCase_CIsolation_CIPackageModel * item,
            /* [out] */ __RPC__out unsigned int *index,
            /* [retval][out] */ __RPC__out boolean *found);

        HRESULT ( STDMETHODCALLTYPE *GetMany )( 
                                               __RPC__in __FIVectorView_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ unsigned int startIndex,
            /* [in] */ unsigned int capacity,
            /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CUFCase_CIsolation_CIPackageModel * *items,
            /* [retval][out] */ __RPC__out unsigned int *actual);

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



#endif // ____FIVectorView_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__



#if !defined(____FIVector_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__)
#define ____FIVector_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__

typedef interface __FIVector_1_UFCase__CIsolation__CPackageModel __FIVector_1_UFCase__CIsolation__CPackageModel;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_UFCase__CIsolation__CPackageModel;

typedef struct __FIVector_1_UFCase__CIsolation__CPackageModelVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This, /* [out] */ __RPC__deref_out_opt __x_ABI_CUFCase_CIsolation_CIPackageModel * *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *GetAt )(__RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This,
        /* [in] */ unsigned int index,
        /* [retval][out] */ __RPC__deref_out_opt __x_ABI_CUFCase_CIsolation_CIPackageModel * *item);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
        __RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This,
        /* [retval][out] */ __RPC__out unsigned int *size);

    HRESULT ( STDMETHODCALLTYPE *GetView )(__RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This, /* [retval][out] */ __RPC__deref_out_opt __FIVectorView_1_UFCase__CIsolation__CPackageModel **view);

    HRESULT ( STDMETHODCALLTYPE *IndexOf )(__RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This,
        /* [in] */ __RPC__in __x_ABI_CUFCase_CIsolation_CIPackageModel * item,
        /* [out] */ __RPC__out unsigned int *index,
        /* [retval][out] */ __RPC__out boolean *found);

    HRESULT ( STDMETHODCALLTYPE *SetAt )(__RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This,
        /* [in] */ unsigned int index,
        /* [in] */ __RPC__in __x_ABI_CUFCase_CIsolation_CIPackageModel * item);

    HRESULT ( STDMETHODCALLTYPE *InsertAt )(__RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This,
        /* [in] */ unsigned int index,
        /* [in] */ __RPC__in __x_ABI_CUFCase_CIsolation_CIPackageModel * item);

    HRESULT ( STDMETHODCALLTYPE *RemoveAt )(__RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This, /* [in] */ unsigned int index);
    HRESULT ( STDMETHODCALLTYPE *Append )(__RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This, /* [in] */ __RPC__in __x_ABI_CUFCase_CIsolation_CIPackageModel * item);
    HRESULT ( STDMETHODCALLTYPE *RemoveAtEnd )(__RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This);
    HRESULT ( STDMETHODCALLTYPE *Clear )(__RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This,
        /* [in] */ unsigned int startIndex,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) __x_ABI_CUFCase_CIsolation_CIPackageModel * *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

    HRESULT ( STDMETHODCALLTYPE *ReplaceAll )(__RPC__in __FIVector_1_UFCase__CIsolation__CPackageModel * This,
        /* [in] */ unsigned int count,
        /* [size_is][in] */ __RPC__in_ecount_full(count) __x_ABI_CUFCase_CIsolation_CIPackageModel * *value);

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



#endif // ____FIVector_1_UFCase__CIsolation__CPackageModel_INTERFACE_DEFINED__


#if !defined(____FIAsyncActionProgressHandler_1_UINT32_INTERFACE_DEFINED__)
#define ____FIAsyncActionProgressHandler_1_UINT32_INTERFACE_DEFINED__

typedef interface __FIAsyncActionProgressHandler_1_UINT32 __FIAsyncActionProgressHandler_1_UINT32;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncActionProgressHandler_1_UINT32;

typedef interface __FIAsyncActionWithProgress_1_UINT32 __FIAsyncActionWithProgress_1_UINT32;

typedef struct __FIAsyncActionProgressHandler_1_UINT32Vtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIAsyncActionProgressHandler_1_UINT32 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIAsyncActionProgressHandler_1_UINT32 * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIAsyncActionProgressHandler_1_UINT32 * This);

    HRESULT ( STDMETHODCALLTYPE *Invoke )(__RPC__in __FIAsyncActionProgressHandler_1_UINT32 * This, /* [in] */ __RPC__in_opt __FIAsyncActionWithProgress_1_UINT32 *asyncInfo, /* [in] */ UINT64 progressInfo);
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


#endif // ____FIAsyncActionProgressHandler_1_UINT32_INTERFACE_DEFINED__


#if !defined(____FIAsyncActionWithProgressCompletedHandler_1_UINT32_INTERFACE_DEFINED__)
#define ____FIAsyncActionWithProgressCompletedHandler_1_UINT32_INTERFACE_DEFINED__

typedef interface __FIAsyncActionWithProgressCompletedHandler_1_UINT32 __FIAsyncActionWithProgressCompletedHandler_1_UINT32;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncActionWithProgressCompletedHandler_1_UINT32;

typedef interface __FIAsyncActionWithProgress_1_UINT32 __FIAsyncActionWithProgress_1_UINT32;

typedef struct __FIAsyncActionWithProgressCompletedHandler_1_UINT32Vtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIAsyncActionWithProgressCompletedHandler_1_UINT32 * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIAsyncActionWithProgressCompletedHandler_1_UINT32 * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIAsyncActionWithProgressCompletedHandler_1_UINT32 * This);

    HRESULT ( STDMETHODCALLTYPE *Invoke )(__RPC__in __FIAsyncActionWithProgressCompletedHandler_1_UINT32 * This, /* [in] */ __RPC__in_opt __FIAsyncActionWithProgress_1_UINT32 *asyncInfo, /* [in] */ AsyncStatus status);
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


#endif // ____FIAsyncActionWithProgressCompletedHandler_1_UINT32_INTERFACE_DEFINED__


#if !defined(____FIAsyncActionWithProgress_1_UINT32_INTERFACE_DEFINED__)
#define ____FIAsyncActionWithProgress_1_UINT32_INTERFACE_DEFINED__

typedef interface __FIAsyncActionWithProgress_1_UINT32 __FIAsyncActionWithProgress_1_UINT32;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncActionWithProgress_1_UINT32;

typedef struct __FIAsyncActionWithProgress_1_UINT32Vtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface )(__RPC__in __FIAsyncActionWithProgress_1_UINT32 * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIAsyncActionWithProgress_1_UINT32 * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIAsyncActionWithProgress_1_UINT32 * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIAsyncActionWithProgress_1_UINT32 * This,
            /* [out] */ __RPC__out ULONG *iidCount,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);
    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIAsyncActionWithProgress_1_UINT32 * This,/* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIAsyncActionWithProgress_1_UINT32 * This,/* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Progress )(__RPC__in __FIAsyncActionWithProgress_1_UINT32 * This, /* [in] */ __RPC__in_opt __FIAsyncActionProgressHandler_1_UINT32 *handler);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Progress )(__RPC__in __FIAsyncActionWithProgress_1_UINT32 * This, /* [retval][out] */ __RPC__deref_out_opt __FIAsyncActionProgressHandler_1_UINT32 **handler);
    /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Completed )(__RPC__in __FIAsyncActionWithProgress_1_UINT32 * This, /* [in] */ __RPC__in_opt __FIAsyncActionWithProgressCompletedHandler_1_UINT32 *handler);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Completed )(__RPC__in __FIAsyncActionWithProgress_1_UINT32 * This, /* [retval][out] */ __RPC__deref_out_opt __FIAsyncActionWithProgressCompletedHandler_1_UINT32 **handler);
    HRESULT ( STDMETHODCALLTYPE *GetResults )(__RPC__in __FIAsyncActionWithProgress_1_UINT32 * This);
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


#endif // ____FIAsyncActionWithProgress_1_UINT32_INTERFACE_DEFINED__



#if !defined(____FIIterator_1_IInspectable_INTERFACE_DEFINED__)
#define ____FIIterator_1_IInspectable_INTERFACE_DEFINED__

typedef interface __FIIterator_1_IInspectable __FIIterator_1_IInspectable;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_IInspectable;

typedef struct __FIIterator_1_IInspectableVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterator_1_IInspectable * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);
    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterator_1_IInspectable * This);
    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterator_1_IInspectable * This);
    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterator_1_IInspectable * This,
        /* [out] */ __RPC__out ULONG *iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterator_1_IInspectable * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);
    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterator_1_IInspectable * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Current )(__RPC__in __FIIterator_1_IInspectable * This, /* [retval][out] */ __RPC__out IInspectable * *current);
    /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasCurrent )(__RPC__in __FIIterator_1_IInspectable * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *MoveNext )(__RPC__in __FIIterator_1_IInspectable * This, /* [retval][out] */ __RPC__out boolean *hasCurrent);
    HRESULT ( STDMETHODCALLTYPE *GetMany )(__RPC__in __FIIterator_1_IInspectable * This,
        /* [in] */ unsigned int capacity,
        /* [size_is][length_is][out] */ __RPC__out_ecount_part(capacity, *actual) IInspectable * *items,
        /* [retval][out] */ __RPC__out unsigned int *actual);

    END_INTERFACE
} __FIIterator_1_IInspectableVtbl;

interface __FIIterator_1_IInspectable
{
    CONST_VTBL struct __FIIterator_1_IInspectableVtbl *lpVtbl;
};



#ifdef COBJMACROS


#define __FIIterator_1_IInspectable_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterator_1_IInspectable_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterator_1_IInspectable_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterator_1_IInspectable_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterator_1_IInspectable_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterator_1_IInspectable_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterator_1_IInspectable_get_Current(This,current)	\
    ( (This)->lpVtbl -> get_Current(This,current) ) 

#define __FIIterator_1_IInspectable_get_HasCurrent(This,hasCurrent)	\
    ( (This)->lpVtbl -> get_HasCurrent(This,hasCurrent) ) 

#define __FIIterator_1_IInspectable_MoveNext(This,hasCurrent)	\
    ( (This)->lpVtbl -> MoveNext(This,hasCurrent) ) 

#define __FIIterator_1_IInspectable_GetMany(This,capacity,items,actual)	\
    ( (This)->lpVtbl -> GetMany(This,capacity,items,actual) ) 

#endif /* COBJMACROS */


#endif // ____FIIterator_1_IInspectable_INTERFACE_DEFINED__



#if !defined(____FIIterable_1_IInspectable_INTERFACE_DEFINED__)
#define ____FIIterable_1_IInspectable_INTERFACE_DEFINED__

typedef interface __FIIterable_1_IInspectable __FIIterable_1_IInspectable;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_IInspectable;

typedef  struct __FIIterable_1_IInspectableVtbl
{
    BEGIN_INTERFACE

    HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
        __RPC__in __FIIterable_1_IInspectable * This,
        /* [in] */ __RPC__in REFIID riid,
        /* [annotation][iid_is][out] */ 
        _COM_Outptr_  void **ppvObject);

    ULONG ( STDMETHODCALLTYPE *AddRef )(__RPC__in __FIIterable_1_IInspectable * This);

    ULONG ( STDMETHODCALLTYPE *Release )(__RPC__in __FIIterable_1_IInspectable * This);

    HRESULT ( STDMETHODCALLTYPE *GetIids )(__RPC__in __FIIterable_1_IInspectable * This,
                                           /* [out] */ __RPC__out ULONG *iidCount,
                                           /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);

    HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(__RPC__in __FIIterable_1_IInspectable * This, /* [out] */ __RPC__deref_out_opt HSTRING *className);

    HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(__RPC__in __FIIterable_1_IInspectable * This, /* [out] */ __RPC__out TrustLevel *trustLevel);

    HRESULT ( STDMETHODCALLTYPE *First )(__RPC__in __FIIterable_1_IInspectable * This, /* [retval][out] */ __RPC__deref_out_opt __FIIterator_1_IInspectable **first);

    END_INTERFACE
} __FIIterable_1_IInspectableVtbl;

interface __FIIterable_1_IInspectable
{
    CONST_VTBL struct __FIIterable_1_IInspectableVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_IInspectable_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __FIIterable_1_IInspectable_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __FIIterable_1_IInspectable_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __FIIterable_1_IInspectable_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __FIIterable_1_IInspectable_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __FIIterable_1_IInspectable_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __FIIterable_1_IInspectable_First(This,first)	\
    ( (This)->lpVtbl -> First(This,first) ) 

#endif /* COBJMACROS */


#endif // ____FIIterable_1_IInspectable_INTERFACE_DEFINED__




typedef enum __x_ABI_CUFCase_CIsolation_CCbsInstallState __x_ABI_CUFCase_CIsolation_CCbsInstallState;


typedef enum __x_ABI_CUFCase_CIsolation_CCbsOperationType __x_ABI_CUFCase_CIsolation_CCbsOperationType;


typedef enum __x_ABI_CUFCase_CIsolation_CCsiComponentStatus __x_ABI_CUFCase_CIsolation_CCsiComponentStatus;


typedef enum __x_ABI_CUFCase_CIsolation_CImageType __x_ABI_CUFCase_CIsolation_CImageType;


typedef struct __x_ABI_CUFCase_CIsolation_CComponentFileModel __x_ABI_CUFCase_CIsolation_CComponentFileModel;


typedef struct __x_ABI_CUFCase_CIsolation_CImageVersion __x_ABI_CUFCase_CIsolation_CImageVersion;

























/*
 *
 * Struct UFCase.Isolation.CbsInstallState
 *
 */

/* [v1_enum, version] */
enum __x_ABI_CUFCase_CIsolation_CCbsInstallState
{
    CbsInstallState_CbsInstallStatePartiallyInstalled = -19,
    CbsInstallState_CbsInstallStateCancel = -18,
    CbsInstallState_CbsInstallStateSuperseded = -17,
    CbsInstallState_CbsInstallStateDefault = -16,
    CbsInstallState_CbsInvalidStatePermanent = -8,
    CbsInstallState_CbsInvalidStateInstalled = -7,
    CbsInstallState_CbsInvalidStateStaged = -4,
    CbsInstallState_CbsInvalidStateResolved = -2,
    CbsInstallState_CbsInstallStateUnknown = -1,
    CbsInstallState_CbsInstallStateAbsent = 0,
    CbsInstallState_CbsInstallStateResolving = 1,
    CbsInstallState_CbsInstallStateResolved = 2,
    CbsInstallState_CbsInstallStateStaging = 3,
    CbsInstallState_CbsInstallStateStaged = 4,
    CbsInstallState_CbsInstallStateUninstallRequested = 5,
    CbsInstallState_CbsInstallStateInstallRequested = 6,
    CbsInstallState_CbsInstallStateInstalled = 7,
    CbsInstallState_CbsInstallStatePermanent = 8,
    CbsInstallState_CbsInstallStateInvalid = 2147483647,
};


/*
 *
 * Struct UFCase.Isolation.CbsOperationType
 *
 */

/* [v1_enum, version] */
enum __x_ABI_CUFCase_CIsolation_CCbsOperationType
{
    CbsOperationType_ExportRepository = 1,
    CbsOperationType_UpdateImage = 2,
    CbsOperationType_PerformPrepareServicingOperation = 3,
    CbsOperationType_PerformLateAcquisitionOperation = 4,
    CbsOperationType_InitICSIStore = 8,
};


/*
 *
 * Struct UFCase.Isolation.CsiComponentStatus
 *
 */

/* [v1_enum, version] */
enum __x_ABI_CUFCase_CIsolation_CCsiComponentStatus
{
    CsiComponentStatus_Prestaged = 1,
    CsiComponentStatus_Staged = 2,
    CsiComponentStatus_Pinned = 3,
    CsiComponentStatus_Installed = 4,
    CsiComponentStatus_InstalledMismatch = 5,
};


/*
 *
 * Struct UFCase.Isolation.ImageType
 *
 */

/* [v1_enum, version] */
enum __x_ABI_CUFCase_CIsolation_CImageType
{
    ImageType_Online = 0,
    ImageType_Offline = 1,
};


/*
 *
 * Struct UFCase.Isolation.ComponentFileModel
 *
 */

/* [version] */
struct __x_ABI_CUFCase_CIsolation_CComponentFileModel
{
    HSTRING Name;
    HSTRING Status;
};


/*
 *
 * Struct UFCase.Isolation.ImageVersion
 *
 */

/* [version] */
struct __x_ABI_CUFCase_CIsolation_CImageVersion
{
    UINT32 Major;
    UINT32 Minor;
    UINT32 Build;
    UINT32 Revision;
};


/*
 *
 * Interface UFCase.Isolation.IComponentModel
 *
 * Interface is a part of the implementation of type UFCase.Isolation.ComponentModel
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CIComponentModel_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CIComponentModel_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_IComponentModel[] = L"UFCase.Isolation.IComponentModel";
/* [object, version, uuid("792DF753-4ACE-5718-A4D4-EB96A6454C5A"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CIsolation_CIComponentModelVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIComponentModel * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIComponentModel * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [overload] */HRESULT ( STDMETHODCALLTYPE *GetAttribute )(
        __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
        /* [in] */HSTRING name,
        /* [retval, out] */HSTRING * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *GetAttribute2 )(
        __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
        /* [in] */HSTRING name_space,
        /* [in] */HSTRING name,
        /* [retval, out] */HSTRING * result
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_TextForm )(
        __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_KeyForm )(
        __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Manifest )(
        __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_CookedManifest )(
        __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
        /* [retval, out] */__x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Status )(
        __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CCsiComponentStatus * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PayloadPath )(
        __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
        /* [retval, out] */HSTRING * value
        );
    HRESULT ( STDMETHODCALLTYPE *GetFileCollection )(
        __x_ABI_CUFCase_CIsolation_CIComponentModel * This,
        /* [in] */UINT32 dwFlags,
        /* [retval, out] */__FIIterable_1_UFCase__CIsolation__CComponentFileModel * * result
        );
    END_INTERFACE
    
} __x_ABI_CUFCase_CIsolation_CIComponentModelVtbl;

interface __x_ABI_CUFCase_CIsolation_CIComponentModel
{
    CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CIComponentModelVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CIsolation_CIComponentModel_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_GetAttribute(This,name,result) \
    ( (This)->lpVtbl->GetAttribute(This,name,result) )

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_GetAttribute2(This,name_space,name,result) \
    ( (This)->lpVtbl->GetAttribute2(This,name_space,name,result) )

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_get_TextForm(This,value) \
    ( (This)->lpVtbl->get_TextForm(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_get_KeyForm(This,value) \
    ( (This)->lpVtbl->get_KeyForm(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_get_Manifest(This,value) \
    ( (This)->lpVtbl->get_Manifest(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_get_CookedManifest(This,value) \
    ( (This)->lpVtbl->get_CookedManifest(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_get_Status(This,value) \
    ( (This)->lpVtbl->get_Status(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_get_PayloadPath(This,value) \
    ( (This)->lpVtbl->get_PayloadPath(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIComponentModel_GetFileCollection(This,dwFlags,result) \
    ( (This)->lpVtbl->GetFileCollection(This,dwFlags,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIComponentModel;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CIComponentModel_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Isolation.IFeatureModel
 *
 * Interface is a part of the implementation of type UFCase.Isolation.FeatureModel
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CIFeatureModel_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CIFeatureModel_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_IFeatureModel[] = L"UFCase.Isolation.IFeatureModel";
/* [object, version, uuid("4DB90A80-741A-5540-BC15-4E9F46A5A56B"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CIsolation_CIFeatureModelVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIFeatureModel * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIFeatureModel * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_CurrentState )(
        __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CCbsInstallState * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_RequestedState )(
        __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CCbsInstallState * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Name )(
        __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DisplayName )(
        __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Description )(
        __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DisplayFile )(
        __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Restart )(
        __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PsfName )(
        __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DownloadSize )(
        __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_SetMembership )(
        __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ContentPackage )(
        __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CIPackageModel * * value
        );
    HRESULT ( STDMETHODCALLTYPE *Enable )(
        __x_ABI_CUFCase_CIsolation_CIFeatureModel * This
        );
    HRESULT ( STDMETHODCALLTYPE *Disable )(
        __x_ABI_CUFCase_CIsolation_CIFeatureModel * This
        );
    HRESULT ( STDMETHODCALLTYPE *GetParentFeatureCollection )(
        __x_ABI_CUFCase_CIsolation_CIFeatureModel * This,
        /* [retval, out] */__FIIterable_1_UFCase__CIsolation__CFeatureModel * * result
        );
    END_INTERFACE
    
} __x_ABI_CUFCase_CIsolation_CIFeatureModelVtbl;

interface __x_ABI_CUFCase_CIsolation_CIFeatureModel
{
    CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CIFeatureModelVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_CurrentState(This,value) \
    ( (This)->lpVtbl->get_CurrentState(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_RequestedState(This,value) \
    ( (This)->lpVtbl->get_RequestedState(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_Name(This,value) \
    ( (This)->lpVtbl->get_Name(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_DisplayName(This,value) \
    ( (This)->lpVtbl->get_DisplayName(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_Description(This,value) \
    ( (This)->lpVtbl->get_Description(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_DisplayFile(This,value) \
    ( (This)->lpVtbl->get_DisplayFile(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_Restart(This,value) \
    ( (This)->lpVtbl->get_Restart(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_PsfName(This,value) \
    ( (This)->lpVtbl->get_PsfName(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_DownloadSize(This,value) \
    ( (This)->lpVtbl->get_DownloadSize(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_SetMembership(This,value) \
    ( (This)->lpVtbl->get_SetMembership(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_get_ContentPackage(This,value) \
    ( (This)->lpVtbl->get_ContentPackage(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_Enable(This) \
    ( (This)->lpVtbl->Enable(This) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_Disable(This) \
    ( (This)->lpVtbl->Disable(This) )

#define __x_ABI_CUFCase_CIsolation_CIFeatureModel_GetParentFeatureCollection(This,result) \
    ( (This)->lpVtbl->GetParentFeatureCollection(This,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIFeatureModel;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CIFeatureModel_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Isolation.IHost
 *
 * Interface is a part of the implementation of type UFCase.Isolation.Host
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CIHost_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CIHost_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_IHost[] = L"UFCase.Isolation.IHost";
/* [object, version, uuid("6BD59CFB-CCEA-5E36-B07D-DAA8833D5E09"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CIsolation_CIHostVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHost * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHost * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHost * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHost * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHost * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHost * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Id )(
        __x_ABI_CUFCase_CIsolation_CIHost * This,
        /* [retval, out] */GUID * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Bootdrive )(
        __x_ABI_CUFCase_CIsolation_CIHost * This,
        /* [retval, out] */HSTRING * value
        );
    HRESULT ( STDMETHODCALLTYPE *Ping )(
        __x_ABI_CUFCase_CIsolation_CIHost * This
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Image )(
        __x_ABI_CUFCase_CIsolation_CIHost * This,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CIImageModel * * value
        );
    END_INTERFACE
    
} __x_ABI_CUFCase_CIsolation_CIHostVtbl;

interface __x_ABI_CUFCase_CIsolation_CIHost
{
    CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CIHostVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CIsolation_CIHost_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CIsolation_CIHost_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CIsolation_CIHost_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CIsolation_CIHost_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CIsolation_CIHost_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CIsolation_CIHost_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CUFCase_CIsolation_CIHost_get_Id(This,value) \
    ( (This)->lpVtbl->get_Id(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIHost_get_Bootdrive(This,value) \
    ( (This)->lpVtbl->get_Bootdrive(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIHost_Ping(This) \
    ( (This)->lpVtbl->Ping(This) )

#define __x_ABI_CUFCase_CIsolation_CIHost_get_Image(This,value) \
    ( (This)->lpVtbl->get_Image(This,value) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIHost;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CIHost_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Isolation.IHostManager
 *
 * Interface is a part of the implementation of type UFCase.Isolation.HostManager
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CIHostManager_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CIHostManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_IHostManager[] = L"UFCase.Isolation.IHostManager";
/* [object, version, uuid("FE58A347-7042-5FAD-B3D6-741CA21CE176"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CIsolation_CIHostManagerVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHostManager * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHostManager * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHostManager * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHostManager * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHostManager * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHostManager * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *RegisterHost )(
        __x_ABI_CUFCase_CIsolation_CIHostManager * This,
        /* [in] */__x_ABI_CUFCase_CIsolation_CIHost * host
        );
    HRESULT ( STDMETHODCALLTYPE *UnregisterHost )(
        __x_ABI_CUFCase_CIsolation_CIHostManager * This,
        /* [in] */__x_ABI_CUFCase_CIsolation_CIHost * host
        );
    END_INTERFACE
    
} __x_ABI_CUFCase_CIsolation_CIHostManagerVtbl;

interface __x_ABI_CUFCase_CIsolation_CIHostManager
{
    CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CIHostManagerVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CIsolation_CIHostManager_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CIsolation_CIHostManager_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CIsolation_CIHostManager_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CIsolation_CIHostManager_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CIsolation_CIHostManager_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CIsolation_CIHostManager_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CUFCase_CIsolation_CIHostManager_RegisterHost(This,host) \
    ( (This)->lpVtbl->RegisterHost(This,host) )

#define __x_ABI_CUFCase_CIsolation_CIHostManager_UnregisterHost(This,host) \
    ( (This)->lpVtbl->UnregisterHost(This,host) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIHostManager;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CIHostManager_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Isolation.IHostManagerSingleton
 *
 * Interface is a part of the implementation of type UFCase.Isolation.HostManagerSingleton
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_IHostManagerSingleton[] = L"UFCase.Isolation.IHostManagerSingleton";
/* [object, version, uuid("806A41FC-6AEA-5877-A7EA-4B012E59F865"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CIsolation_CIHostManagerSingletonVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *Current )(
        __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton * This,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CIHostManager * * result
        );
    END_INTERFACE
    
} __x_ABI_CUFCase_CIsolation_CIHostManagerSingletonVtbl;

interface __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton
{
    CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CIHostManagerSingletonVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_Current(This,result) \
    ( (This)->lpVtbl->Current(This,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIHostManagerSingleton;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CIHostManagerSingleton_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Isolation.IImageModel
 *
 * Interface is a part of the implementation of type UFCase.Isolation.ImageModel
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CIImageModel_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CIImageModel_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_IImageModel[] = L"UFCase.Isolation.IImageModel";
/* [object, version, uuid("13F4D846-68DA-53E9-88C6-495AA1B7B4A4"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CIsolation_CIImageModelVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIImageModel * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIImageModel * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIImageModel * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIImageModel * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIImageModel * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIImageModel * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *OpenSession )(
        __x_ABI_CUFCase_CIsolation_CIImageModel * This,
        /* [in] */UINT32 option,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CISessionModel * * result
        );
    HRESULT ( STDMETHODCALLTYPE *SxsStore )(
        __x_ABI_CUFCase_CIsolation_CIImageModel * This,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CIStoreModel * * result
        );
    HRESULT ( STDMETHODCALLTYPE *Bootdrive )(
        __x_ABI_CUFCase_CIsolation_CIImageModel * This,
        /* [retval, out] */HSTRING * result
        );
    HRESULT ( STDMETHODCALLTYPE *WinDir )(
        __x_ABI_CUFCase_CIsolation_CIImageModel * This,
        /* [retval, out] */HSTRING * result
        );
    HRESULT ( STDMETHODCALLTYPE *GetRegistryHive )(
        __x_ABI_CUFCase_CIsolation_CIImageModel * This,
        /* [in] */HSTRING hive_id,
        /* [retval, out] */HSTRING * result
        );
    HRESULT ( STDMETHODCALLTYPE *Type )(
        __x_ABI_CUFCase_CIsolation_CIImageModel * This,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CImageType * result
        );
    HRESULT ( STDMETHODCALLTYPE *Version )(
        __x_ABI_CUFCase_CIsolation_CIImageModel * This,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CImageVersion * result
        );
    HRESULT ( STDMETHODCALLTYPE *Edition )(
        __x_ABI_CUFCase_CIsolation_CIImageModel * This,
        /* [retval, out] */HSTRING * result
        );
    HRESULT ( STDMETHODCALLTYPE *Architecture )(
        __x_ABI_CUFCase_CIsolation_CIImageModel * This,
        /* [retval, out] */HSTRING * result
        );
    HRESULT ( STDMETHODCALLTYPE *IsWinPE )(
        __x_ABI_CUFCase_CIsolation_CIImageModel * This,
        /* [retval, out] */boolean * result
        );
    END_INTERFACE
    
} __x_ABI_CUFCase_CIsolation_CIImageModelVtbl;

interface __x_ABI_CUFCase_CIsolation_CIImageModel
{
    CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CIImageModelVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CIsolation_CIImageModel_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CIsolation_CIImageModel_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CIsolation_CIImageModel_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CIsolation_CIImageModel_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CIsolation_CIImageModel_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CIsolation_CIImageModel_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CUFCase_CIsolation_CIImageModel_OpenSession(This,option,result) \
    ( (This)->lpVtbl->OpenSession(This,option,result) )

#define __x_ABI_CUFCase_CIsolation_CIImageModel_SxsStore(This,result) \
    ( (This)->lpVtbl->SxsStore(This,result) )

#define __x_ABI_CUFCase_CIsolation_CIImageModel_Bootdrive(This,result) \
    ( (This)->lpVtbl->Bootdrive(This,result) )

#define __x_ABI_CUFCase_CIsolation_CIImageModel_WinDir(This,result) \
    ( (This)->lpVtbl->WinDir(This,result) )

#define __x_ABI_CUFCase_CIsolation_CIImageModel_GetRegistryHive(This,hive_id,result) \
    ( (This)->lpVtbl->GetRegistryHive(This,hive_id,result) )

#define __x_ABI_CUFCase_CIsolation_CIImageModel_Type(This,result) \
    ( (This)->lpVtbl->Type(This,result) )

#define __x_ABI_CUFCase_CIsolation_CIImageModel_Version(This,result) \
    ( (This)->lpVtbl->Version(This,result) )

#define __x_ABI_CUFCase_CIsolation_CIImageModel_Edition(This,result) \
    ( (This)->lpVtbl->Edition(This,result) )

#define __x_ABI_CUFCase_CIsolation_CIImageModel_Architecture(This,result) \
    ( (This)->lpVtbl->Architecture(This,result) )

#define __x_ABI_CUFCase_CIsolation_CIImageModel_IsWinPE(This,result) \
    ( (This)->lpVtbl->IsWinPE(This,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIImageModel;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CIImageModel_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Isolation.IPackageModel
 *
 * Interface is a part of the implementation of type UFCase.Isolation.PackageModel
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CIPackageModel_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CIPackageModel_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_IPackageModel[] = L"UFCase.Isolation.IPackageModel";
/* [object, version, uuid("43786F4F-0F87-5FDF-9E9A-661F8226D32E"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CIsolation_CIPackageModelVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIPackageModel * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIPackageModel * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Session )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CISessionModel * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_State )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CCbsInstallState * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Name )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Description )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Identity )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ReleaseType )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_RestartRequired )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ProductName )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ProductVersion )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Company )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Copyright )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_SupportInformation )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_CreationTime )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_LastUpdateTime )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_InstallTime )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_InstallPackageName )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_InstallLocation )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_InstallClient )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_InstallUserName )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_IsApplicable )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */boolean * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ManifestFilePath )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_RegistryPath )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [retval, out] */HSTRING * value
        );
    HRESULT ( STDMETHODCALLTYPE *Install )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This
        );
    HRESULT ( STDMETHODCALLTYPE *Remove )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This
        );
    HRESULT ( STDMETHODCALLTYPE *Stage )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This
        );
    HRESULT ( STDMETHODCALLTYPE *OpenFeature )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [in] */HSTRING name,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CIFeatureModel * * result
        );
    HRESULT ( STDMETHODCALLTYPE *GetFeatureCollection )(
        __x_ABI_CUFCase_CIsolation_CIPackageModel * This,
        /* [in] */UINT32 applicability,
        /* [in] */UINT32 selectability,
        /* [retval, out] */__FIIterable_1_UFCase__CIsolation__CFeatureModel * * result
        );
    END_INTERFACE
    
} __x_ABI_CUFCase_CIsolation_CIPackageModelVtbl;

interface __x_ABI_CUFCase_CIsolation_CIPackageModel
{
    CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CIPackageModelVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CIsolation_CIPackageModel_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_Session(This,value) \
    ( (This)->lpVtbl->get_Session(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_State(This,value) \
    ( (This)->lpVtbl->get_State(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_Name(This,value) \
    ( (This)->lpVtbl->get_Name(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_Description(This,value) \
    ( (This)->lpVtbl->get_Description(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_Identity(This,value) \
    ( (This)->lpVtbl->get_Identity(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_ReleaseType(This,value) \
    ( (This)->lpVtbl->get_ReleaseType(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_RestartRequired(This,value) \
    ( (This)->lpVtbl->get_RestartRequired(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_ProductName(This,value) \
    ( (This)->lpVtbl->get_ProductName(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_ProductVersion(This,value) \
    ( (This)->lpVtbl->get_ProductVersion(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_Company(This,value) \
    ( (This)->lpVtbl->get_Company(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_Copyright(This,value) \
    ( (This)->lpVtbl->get_Copyright(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_SupportInformation(This,value) \
    ( (This)->lpVtbl->get_SupportInformation(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_CreationTime(This,value) \
    ( (This)->lpVtbl->get_CreationTime(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_LastUpdateTime(This,value) \
    ( (This)->lpVtbl->get_LastUpdateTime(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_InstallTime(This,value) \
    ( (This)->lpVtbl->get_InstallTime(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_InstallPackageName(This,value) \
    ( (This)->lpVtbl->get_InstallPackageName(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_InstallLocation(This,value) \
    ( (This)->lpVtbl->get_InstallLocation(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_InstallClient(This,value) \
    ( (This)->lpVtbl->get_InstallClient(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_InstallUserName(This,value) \
    ( (This)->lpVtbl->get_InstallUserName(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_IsApplicable(This,value) \
    ( (This)->lpVtbl->get_IsApplicable(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_ManifestFilePath(This,value) \
    ( (This)->lpVtbl->get_ManifestFilePath(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_get_RegistryPath(This,value) \
    ( (This)->lpVtbl->get_RegistryPath(This,value) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_Install(This) \
    ( (This)->lpVtbl->Install(This) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_Remove(This) \
    ( (This)->lpVtbl->Remove(This) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_Stage(This) \
    ( (This)->lpVtbl->Stage(This) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_OpenFeature(This,name,result) \
    ( (This)->lpVtbl->OpenFeature(This,name,result) )

#define __x_ABI_CUFCase_CIsolation_CIPackageModel_GetFeatureCollection(This,applicability,selectability,result) \
    ( (This)->lpVtbl->GetFeatureCollection(This,applicability,selectability,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIPackageModel;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CIPackageModel_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Isolation.ISessionModel
 *
 * Interface is a part of the implementation of type UFCase.Isolation.SessionModel
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CISessionModel_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CISessionModel_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_ISessionModel[] = L"UFCase.Isolation.ISessionModel";
/* [object, version, uuid("D4B1314D-679D-5256-B032-D3FD6CAB4782"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CIsolation_CISessionModelVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CIsolation_CISessionModel * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CISessionModel * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CISessionModel * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CISessionModel * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CISessionModel * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CISessionModel * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Image )(
        __x_ABI_CUFCase_CIsolation_CISessionModel * This,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CIImageModel * * value
        );
    HRESULT ( STDMETHODCALLTYPE *AddSource )(
        __x_ABI_CUFCase_CIsolation_CISessionModel * This,
        /* [in] */HSTRING source
        );
    HRESULT ( STDMETHODCALLTYPE *SaveChanges )(
        __x_ABI_CUFCase_CIsolation_CISessionModel * This,
        /* [retval, out] */__FIAsyncActionWithProgress_1_UINT32 * * operation
        );
    HRESULT ( STDMETHODCALLTYPE *OpenPackage )(
        __x_ABI_CUFCase_CIsolation_CISessionModel * This,
        /* [in] */HSTRING identity,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CIPackageModel * * result
        );
    HRESULT ( STDMETHODCALLTYPE *GetPackageCollection )(
        __x_ABI_CUFCase_CIsolation_CISessionModel * This,
        /* [in] */UINT32 option,
        /* [retval, out] */__FIVector_1_UFCase__CIsolation__CPackageModel * * result
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_FoundationPackage )(
        __x_ABI_CUFCase_CIsolation_CISessionModel * This,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CIPackageModel * * value
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ProductPackage )(
        __x_ABI_CUFCase_CIsolation_CISessionModel * This,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CIPackageModel * * value
        );
    HRESULT ( STDMETHODCALLTYPE *PerformOperation )(
        __x_ABI_CUFCase_CIsolation_CISessionModel * This,
        /* [in] */__x_ABI_CUFCase_CIsolation_CCbsOperationType op
        );
    END_INTERFACE
    
} __x_ABI_CUFCase_CIsolation_CISessionModelVtbl;

interface __x_ABI_CUFCase_CIsolation_CISessionModel
{
    CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CISessionModelVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CIsolation_CISessionModel_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CIsolation_CISessionModel_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CIsolation_CISessionModel_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CIsolation_CISessionModel_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CIsolation_CISessionModel_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CIsolation_CISessionModel_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CUFCase_CIsolation_CISessionModel_get_Image(This,value) \
    ( (This)->lpVtbl->get_Image(This,value) )

#define __x_ABI_CUFCase_CIsolation_CISessionModel_AddSource(This,source) \
    ( (This)->lpVtbl->AddSource(This,source) )

#define __x_ABI_CUFCase_CIsolation_CISessionModel_SaveChanges(This,operation) \
    ( (This)->lpVtbl->SaveChanges(This,operation) )

#define __x_ABI_CUFCase_CIsolation_CISessionModel_OpenPackage(This,identity,result) \
    ( (This)->lpVtbl->OpenPackage(This,identity,result) )

#define __x_ABI_CUFCase_CIsolation_CISessionModel_GetPackageCollection(This,option,result) \
    ( (This)->lpVtbl->GetPackageCollection(This,option,result) )

#define __x_ABI_CUFCase_CIsolation_CISessionModel_get_FoundationPackage(This,value) \
    ( (This)->lpVtbl->get_FoundationPackage(This,value) )

#define __x_ABI_CUFCase_CIsolation_CISessionModel_get_ProductPackage(This,value) \
    ( (This)->lpVtbl->get_ProductPackage(This,value) )

#define __x_ABI_CUFCase_CIsolation_CISessionModel_PerformOperation(This,op) \
    ( (This)->lpVtbl->PerformOperation(This,op) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CISessionModel;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CISessionModel_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Isolation.IStoreModel
 *
 * Interface is a part of the implementation of type UFCase.Isolation.StoreModel
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CIsolation_CIStoreModel_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CIsolation_CIStoreModel_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Isolation_IStoreModel[] = L"UFCase.Isolation.IStoreModel";
/* [object, version, uuid("FE3C8E81-A790-528D-A986-80E6A9722BAA"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CIsolation_CIStoreModelVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIStoreModel * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIStoreModel * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIStoreModel * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIStoreModel * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIStoreModel * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CIsolation_CIStoreModel * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *OpenComponent )(
        __x_ABI_CUFCase_CIsolation_CIStoreModel * This,
        /* [in] */HSTRING definition,
        /* [retval, out] */__x_ABI_CUFCase_CIsolation_CIComponentModel * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *GetComponentCollection )(
        __x_ABI_CUFCase_CIsolation_CIStoreModel * This,
        /* [retval, out] */__FIIterable_1_IInspectable * * result
        );
    /* [overload] */HRESULT ( STDMETHODCALLTYPE *GetComponentCollection2 )(
        __x_ABI_CUFCase_CIsolation_CIStoreModel * This,
        /* [in] */HSTRING reference,
        /* [retval, out] */__FIIterable_1_IInspectable * * result
        );
    END_INTERFACE
    
} __x_ABI_CUFCase_CIsolation_CIStoreModelVtbl;

interface __x_ABI_CUFCase_CIsolation_CIStoreModel
{
    CONST_VTBL struct __x_ABI_CUFCase_CIsolation_CIStoreModelVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CIsolation_CIStoreModel_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CIsolation_CIStoreModel_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CIsolation_CIStoreModel_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CIsolation_CIStoreModel_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CIsolation_CIStoreModel_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CIsolation_CIStoreModel_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CUFCase_CIsolation_CIStoreModel_OpenComponent(This,definition,result) \
    ( (This)->lpVtbl->OpenComponent(This,definition,result) )

#define __x_ABI_CUFCase_CIsolation_CIStoreModel_GetComponentCollection(This,result) \
    ( (This)->lpVtbl->GetComponentCollection(This,result) )

#define __x_ABI_CUFCase_CIsolation_CIStoreModel_GetComponentCollection2(This,reference,result) \
    ( (This)->lpVtbl->GetComponentCollection2(This,reference,result) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CIsolation_CIStoreModel;
#endif /* !defined(____x_ABI_CUFCase_CIsolation_CIStoreModel_INTERFACE_DEFINED__) */


/*
 *
 * Class UFCase.Isolation.ComponentModel
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.IComponentModel ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_ComponentModel_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_ComponentModel_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_ComponentModel[] = L"UFCase.Isolation.ComponentModel";
#endif


/*
 *
 * Class UFCase.Isolation.FeatureModel
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.IFeatureModel ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_FeatureModel_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_FeatureModel_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_FeatureModel[] = L"UFCase.Isolation.FeatureModel";
#endif


/*
 *
 * Class UFCase.Isolation.Host
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.IHost ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_Host_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_Host_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_Host[] = L"UFCase.Isolation.Host";
#endif


/*
 *
 * Class UFCase.Isolation.HostManager
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.IHostManager ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_HostManager_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_HostManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_HostManager[] = L"UFCase.Isolation.HostManager";
#endif


/*
 *
 * Class UFCase.Isolation.HostManagerSingleton
 *
 * RuntimeClass can be activated.
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.IHostManagerSingleton ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_HostManagerSingleton_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_HostManagerSingleton_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_HostManagerSingleton[] = L"UFCase.Isolation.HostManagerSingleton";
#endif


/*
 *
 * Class UFCase.Isolation.ImageModel
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.IImageModel ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_ImageModel_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_ImageModel_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_ImageModel[] = L"UFCase.Isolation.ImageModel";
#endif


/*
 *
 * Class UFCase.Isolation.PackageModel
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.IPackageModel ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_PackageModel_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_PackageModel_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_PackageModel[] = L"UFCase.Isolation.PackageModel";
#endif


/*
 *
 * Class UFCase.Isolation.SessionModel
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.ISessionModel ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_SessionModel_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_SessionModel_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_SessionModel[] = L"UFCase.Isolation.SessionModel";
#endif


/*
 *
 * Class UFCase.Isolation.StoreModel
 *
 * Class implements the following interfaces:
 *    UFCase.Isolation.IStoreModel ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */

#ifndef RUNTIMECLASS_UFCase_Isolation_StoreModel_DEFINED
#define RUNTIMECLASS_UFCase_Isolation_StoreModel_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Isolation_StoreModel[] = L"UFCase.Isolation.StoreModel";
#endif



#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
#endif // __UFCase2EIsolation_p_h__

#endif // __UFCase2EIsolation_h__
