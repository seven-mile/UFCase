/* Header file automatically generated from UFCase.Host.Manifest.idl */
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
#ifndef __UFCase2EHost2EManifest_h__
#define __UFCase2EHost2EManifest_h__
#ifndef __UFCase2EHost2EManifest_p_h__
#define __UFCase2EHost2EManifest_p_h__


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

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                interface IAssemblyClass;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass ABI::UFCase::Host::Manifest::IAssemblyClass

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                interface IAssemblyDependencyClass;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass ABI::UFCase::Host::Manifest::IAssemblyDependencyClass

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                interface IAssemblyIdentityClass;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass ABI::UFCase::Host::Manifest::IAssemblyIdentityClass

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                interface IComStreamWrapper;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper ABI::UFCase::Host::Manifest::IComStreamWrapper

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIFileClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIFileClass_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                interface IFileClass;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass ABI::UFCase::Host::Manifest::IFileClass

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIFileClass_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                interface IManifestParserClass;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass ABI::UFCase::Host::Manifest::IManifestParserClass

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                interface IManifestParserStatic;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic ABI::UFCase::Host::Manifest::IManifestParserStatic

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                interface IRegistryKeyClass;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass ABI::UFCase::Host::Manifest::IRegistryKeyClass

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                interface IRegistryValueClass;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass ABI::UFCase::Host::Manifest::IRegistryValueClass

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_FWD_DEFINED__
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                interface IVersionClass;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */
#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass ABI::UFCase::Host::Manifest::IVersionClass

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_FWD_DEFINED__


namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                
                typedef enum RegistryValueType : int RegistryValueType;
                
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */











namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                class Assembly;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */


namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                class AssemblyDependency;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */


namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                class AssemblyIdentity;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */


namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                class File;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */


namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                class ManifestParser;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */


namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                class RegistryKey;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */


namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                class RegistryValue;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */


namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                class Version;
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */






/*
 *
 * Struct UFCase.Host.Manifest.RegistryValueType
 *
 */

namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                /* [v1_enum, version] */
                enum RegistryValueType : int
                {
                    RegistryValueType_RegNone = 0,
                    RegistryValueType_RegSz = 1,
                    RegistryValueType_RegExpandSz = 2,
                    RegistryValueType_RegBinary = 3,
                    RegistryValueType_RegDword = 4,
                    RegistryValueType_RegDwordBigEndian = 5,
                    RegistryValueType_RegLink = 6,
                    RegistryValueType_RegMultiSz = 7,
                    RegistryValueType_RegResourceList = 8,
                    RegistryValueType_RegFullResourceDescriptor = 9,
                    RegistryValueType_RegResourceRequirementsList = 10,
                    RegistryValueType_RegQword = 11,
                };
                
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */


/*
 *
 * Interface UFCase.Host.Manifest.IAssemblyClass
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.Assembly
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IAssemblyClass[] = L"UFCase.Host.Manifest.IAssemblyClass";
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                /* [object, version, uuid("1254A4C8-452B-5744-B544-72BC8D34A2BC"), exclusiveto] */
                MIDL_INTERFACE("1254A4C8-452B-5744-B544-72BC8D34A2BC")
                IAssemblyClass : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Identity(
                        /* [retval, out] */ABI::UFCase::Host::Manifest::IAssemblyIdentityClass * * __returnValue_get_Identity__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Version(
                        /* [retval, out] */ABI::UFCase::Host::Manifest::IVersionClass * * __returnValue_get_Version__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Files(
                        /* [out] */UINT32 * ____returnValue_get_Files__Size,
                        /* [size_is(, *(____returnValue_get_Files__Size)), retval, out] */ABI::UFCase::Host::Manifest::IFileClass * * * __returnValue_get_Files__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Keys(
                        /* [out] */UINT32 * ____returnValue_get_Keys__Size,
                        /* [size_is(, *(____returnValue_get_Keys__Size)), retval, out] */ABI::UFCase::Host::Manifest::IRegistryKeyClass * * * __returnValue_get_Keys__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Dependencies(
                        /* [out] */UINT32 * ____returnValue_get_Dependencies__Size,
                        /* [size_is(, *(____returnValue_get_Dependencies__Size)), retval, out] */ABI::UFCase::Host::Manifest::IAssemblyDependencyClass * * * __returnValue_get_Dependencies__
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IAssemblyClass=__uuidof(IAssemblyClass);
                
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IAssemblyDependencyClass
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.AssemblyDependency
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IAssemblyDependencyClass[] = L"UFCase.Host.Manifest.IAssemblyDependencyClass";
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                /* [object, version, uuid("59EC1B96-C604-5C7C-AFC9-648BA4A9B001"), exclusiveto] */
                MIDL_INTERFACE("59EC1B96-C604-5C7C-AFC9-648BA4A9B001")
                IAssemblyDependencyClass : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Identity(
                        /* [retval, out] */ABI::UFCase::Host::Manifest::IAssemblyIdentityClass * * __returnValue_get_Identity__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Type(
                        /* [retval, out] */HSTRING * __returnValue_get_Type__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Install(
                        /* [retval, out] */HSTRING * __returnValue_get_Install__
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IAssemblyDependencyClass=__uuidof(IAssemblyDependencyClass);
                
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IAssemblyIdentityClass
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.AssemblyIdentity
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IAssemblyIdentityClass[] = L"UFCase.Host.Manifest.IAssemblyIdentityClass";
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                /* [object, version, uuid("26D5B743-6C88-5B41-9F37-35A7DE5F6144"), exclusiveto] */
                MIDL_INTERFACE("26D5B743-6C88-5B41-9F37-35A7DE5F6144")
                IAssemblyIdentityClass : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Name(
                        /* [retval, out] */HSTRING * __returnValue_get_Name__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PublicKeyToken(
                        /* [retval, out] */HSTRING * __returnValue_get_PublicKeyToken__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Language(
                        /* [retval, out] */HSTRING * __returnValue_get_Language__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ProcessorArchitecture(
                        /* [retval, out] */HSTRING * __returnValue_get_ProcessorArchitecture__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Version(
                        /* [retval, out] */HSTRING * __returnValue_get_Version__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Type(
                        /* [retval, out] */HSTRING * __returnValue_get_Type__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_KeyForm(
                        /* [retval, out] */HSTRING * __returnValue_get_KeyForm__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_HashCode(
                        /* [retval, out] */HSTRING * __returnValue_get_HashCode__
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IAssemblyIdentityClass=__uuidof(IAssemblyIdentityClass);
                
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IComStreamWrapper
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IComStreamWrapper[] = L"UFCase.Host.Manifest.IComStreamWrapper";
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                /* [object, version, uuid("3347D112-6F3D-519A-8493-F5E3F1A1079E")] */
                MIDL_INTERFACE("3347D112-6F3D-519A-8493-F5E3F1A1079E")
                IComStreamWrapper : public IInspectable
                {
                public:
                    
                };

                MIDL_CONST_ID IID & IID_IComStreamWrapper=__uuidof(IComStreamWrapper);
                
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IFileClass
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.File
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIFileClass_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIFileClass_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IFileClass[] = L"UFCase.Host.Manifest.IFileClass";
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                /* [object, version, uuid("B3B96E25-DA85-5851-A796-BDFABCB19CFD"), exclusiveto] */
                MIDL_INTERFACE("B3B96E25-DA85-5851-A796-BDFABCB19CFD")
                IFileClass : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DestinationName(
                        /* [retval, out] */HSTRING * __returnValue_get_DestinationName__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DestinationPath(
                        /* [retval, out] */HSTRING * __returnValue_get_DestinationPath__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_SourcePath(
                        /* [retval, out] */HSTRING * __returnValue_get_SourcePath__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_SourceName(
                        /* [retval, out] */HSTRING * __returnValue_get_SourceName__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ImportPath(
                        /* [retval, out] */HSTRING * __returnValue_get_ImportPath__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Hash(
                        /* [retval, out] */HSTRING * __returnValue_get_Hash__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_HashAlgorithm(
                        /* [retval, out] */HSTRING * __returnValue_get_HashAlgorithm__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_SizeInByte(
                        /* [retval, out] */INT32 * __returnValue_get_SizeInByte__
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IFileClass=__uuidof(IFileClass);
                
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIFileClass;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIFileClass_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IManifestParserClass
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.ManifestParser
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IManifestParserClass[] = L"UFCase.Host.Manifest.IManifestParserClass";
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                /* [object, version, uuid("5D779A6F-A8F9-55DF-A5C9-C1E63DD9E4C6"), exclusiveto] */
                MIDL_INTERFACE("5D779A6F-A8F9-55DF-A5C9-C1E63DD9E4C6")
                IManifestParserClass : public IInspectable
                {
                public:
                    
                };

                MIDL_CONST_ID IID & IID_IManifestParserClass=__uuidof(IManifestParserClass);
                
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IManifestParserStatic
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.ManifestParser
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IManifestParserStatic[] = L"UFCase.Host.Manifest.IManifestParserStatic";
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                /* [object, version, uuid("6D41CE8B-48CC-5CA6-A397-4951356131BC"), exclusiveto] */
                MIDL_INTERFACE("6D41CE8B-48CC-5CA6-A397-4951356131BC")
                IManifestParserStatic : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE ParseFromPath(
                        /* [in] */HSTRING path,
                        /* [retval, out] */ABI::UFCase::Host::Manifest::IAssemblyClass * * __returnValue_ParseFromPath__
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE ParseFromStream(
                        /* [in] */ABI::UFCase::Host::Manifest::IComStreamWrapper * stream,
                        /* [retval, out] */ABI::UFCase::Host::Manifest::IAssemblyClass * * __returnValue_ParseFromStream__
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IManifestParserStatic=__uuidof(IManifestParserStatic);
                
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IRegistryKeyClass
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.RegistryKey
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IRegistryKeyClass[] = L"UFCase.Host.Manifest.IRegistryKeyClass";
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                /* [object, version, uuid("46A8BABC-13B9-5B22-A7BC-007EDEA03028"), exclusiveto] */
                MIDL_INTERFACE("46A8BABC-13B9-5B22-A7BC-007EDEA03028")
                IRegistryKeyClass : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Name(
                        /* [retval, out] */HSTRING * __returnValue_get_Name__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Values(
                        /* [out] */UINT32 * ____returnValue_get_Values__Size,
                        /* [size_is(, *(____returnValue_get_Values__Size)), retval, out] */ABI::UFCase::Host::Manifest::IRegistryValueClass * * * __returnValue_get_Values__
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IRegistryKeyClass=__uuidof(IRegistryKeyClass);
                
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IRegistryValueClass
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.RegistryValue
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IRegistryValueClass[] = L"UFCase.Host.Manifest.IRegistryValueClass";
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                /* [object, version, uuid("E2BDF2C4-239A-535A-AD89-2C439B9FBBC0"), exclusiveto] */
                MIDL_INTERFACE("E2BDF2C4-239A-535A-AD89-2C439B9FBBC0")
                IRegistryValueClass : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Name(
                        /* [retval, out] */HSTRING * __returnValue_get_Name__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Type(
                        /* [retval, out] */ABI::UFCase::Host::Manifest::RegistryValueType * __returnValue_get_Type__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Data(
                        /* [retval, out] */IInspectable * * __returnValue_get_Data__
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IRegistryValueClass=__uuidof(IRegistryValueClass);
                
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IVersionClass
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.Version
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IVersionClass[] = L"UFCase.Host.Manifest.IVersionClass";
namespace ABI {
    namespace UFCase {
        namespace Host {
            namespace Manifest {
                /* [object, version, uuid("9B56B015-02B3-5D08-8F39-43E5E5F74EC0"), exclusiveto] */
                MIDL_INTERFACE("9B56B015-02B3-5D08-8F39-43E5E5F74EC0")
                IVersionClass : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Major(
                        /* [retval, out] */INT32 * __returnValue_get_Major__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Minor(
                        /* [retval, out] */INT32 * __returnValue_get_Minor__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Build(
                        /* [retval, out] */INT32 * __returnValue_get_Build__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Revision(
                        /* [retval, out] */INT32 * __returnValue_get_Revision__
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_Value(
                        /* [retval, out] */HSTRING * __returnValue_get_Value__
                        ) = 0;
                    
                };

                MIDL_CONST_ID IID & IID_IVersionClass=__uuidof(IVersionClass);
                
            } /* Manifest */
        } /* Host */
    } /* UFCase */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIVersionClass;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_INTERFACE_DEFINED__) */


/*
 *
 * Class UFCase.Host.Manifest.Assembly
 *
 * RuntimeClass can be activated.
 *
 * Class implements the following interfaces:
 *    UFCase.Host.Manifest.IAssemblyClass ** Default Interface **
 *
 */

#ifndef RUNTIMECLASS_UFCase_Host_Manifest_Assembly_DEFINED
#define RUNTIMECLASS_UFCase_Host_Manifest_Assembly_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Host_Manifest_Assembly[] = L"UFCase.Host.Manifest.Assembly";
#endif


/*
 *
 * Class UFCase.Host.Manifest.AssemblyDependency
 *
 * RuntimeClass can be activated.
 *
 * Class implements the following interfaces:
 *    UFCase.Host.Manifest.IAssemblyDependencyClass ** Default Interface **
 *
 */

#ifndef RUNTIMECLASS_UFCase_Host_Manifest_AssemblyDependency_DEFINED
#define RUNTIMECLASS_UFCase_Host_Manifest_AssemblyDependency_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Host_Manifest_AssemblyDependency[] = L"UFCase.Host.Manifest.AssemblyDependency";
#endif


/*
 *
 * Class UFCase.Host.Manifest.AssemblyIdentity
 *
 * RuntimeClass can be activated.
 *
 * Class implements the following interfaces:
 *    UFCase.Host.Manifest.IAssemblyIdentityClass ** Default Interface **
 *
 */

#ifndef RUNTIMECLASS_UFCase_Host_Manifest_AssemblyIdentity_DEFINED
#define RUNTIMECLASS_UFCase_Host_Manifest_AssemblyIdentity_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Host_Manifest_AssemblyIdentity[] = L"UFCase.Host.Manifest.AssemblyIdentity";
#endif


/*
 *
 * Class UFCase.Host.Manifest.File
 *
 * RuntimeClass can be activated.
 *
 * Class implements the following interfaces:
 *    UFCase.Host.Manifest.IFileClass ** Default Interface **
 *
 */

#ifndef RUNTIMECLASS_UFCase_Host_Manifest_File_DEFINED
#define RUNTIMECLASS_UFCase_Host_Manifest_File_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Host_Manifest_File[] = L"UFCase.Host.Manifest.File";
#endif


/*
 *
 * Class UFCase.Host.Manifest.ManifestParser
 *
 * RuntimeClass can be activated.
 *
 * RuntimeClass contains static methods.
 *
 * Class implements the following interfaces:
 *    UFCase.Host.Manifest.IManifestParserClass ** Default Interface **
 *
 */

#ifndef RUNTIMECLASS_UFCase_Host_Manifest_ManifestParser_DEFINED
#define RUNTIMECLASS_UFCase_Host_Manifest_ManifestParser_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Host_Manifest_ManifestParser[] = L"UFCase.Host.Manifest.ManifestParser";
#endif


/*
 *
 * Class UFCase.Host.Manifest.RegistryKey
 *
 * RuntimeClass can be activated.
 *
 * Class implements the following interfaces:
 *    UFCase.Host.Manifest.IRegistryKeyClass ** Default Interface **
 *
 */

#ifndef RUNTIMECLASS_UFCase_Host_Manifest_RegistryKey_DEFINED
#define RUNTIMECLASS_UFCase_Host_Manifest_RegistryKey_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Host_Manifest_RegistryKey[] = L"UFCase.Host.Manifest.RegistryKey";
#endif


/*
 *
 * Class UFCase.Host.Manifest.RegistryValue
 *
 * RuntimeClass can be activated.
 *
 * Class implements the following interfaces:
 *    UFCase.Host.Manifest.IRegistryValueClass ** Default Interface **
 *
 */

#ifndef RUNTIMECLASS_UFCase_Host_Manifest_RegistryValue_DEFINED
#define RUNTIMECLASS_UFCase_Host_Manifest_RegistryValue_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Host_Manifest_RegistryValue[] = L"UFCase.Host.Manifest.RegistryValue";
#endif


/*
 *
 * Class UFCase.Host.Manifest.Version
 *
 * RuntimeClass can be activated.
 *
 * Class implements the following interfaces:
 *    UFCase.Host.Manifest.IVersionClass ** Default Interface **
 *
 */

#ifndef RUNTIMECLASS_UFCase_Host_Manifest_Version_DEFINED
#define RUNTIMECLASS_UFCase_Host_Manifest_Version_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Host_Manifest_Version[] = L"UFCase.Host.Manifest.Version";
#endif




#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass;

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass;

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass;

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper;

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIFileClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIFileClass_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIFileClass __x_ABI_CUFCase_CHost_CManifest_CIFileClass;

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIFileClass_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass;

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic;

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass;

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass;

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_FWD_DEFINED__

#ifndef ____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_FWD_DEFINED__
#define ____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_FWD_DEFINED__
typedef interface __x_ABI_CUFCase_CHost_CManifest_CIVersionClass __x_ABI_CUFCase_CHost_CManifest_CIVersionClass;

#endif // ____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_FWD_DEFINED__


typedef enum __x_ABI_CUFCase_CHost_CManifest_CRegistryValueType __x_ABI_CUFCase_CHost_CManifest_CRegistryValueType;























/*
 *
 * Struct UFCase.Host.Manifest.RegistryValueType
 *
 */

/* [v1_enum, version] */
enum __x_ABI_CUFCase_CHost_CManifest_CRegistryValueType
{
    RegistryValueType_RegNone = 0,
    RegistryValueType_RegSz = 1,
    RegistryValueType_RegExpandSz = 2,
    RegistryValueType_RegBinary = 3,
    RegistryValueType_RegDword = 4,
    RegistryValueType_RegDwordBigEndian = 5,
    RegistryValueType_RegLink = 6,
    RegistryValueType_RegMultiSz = 7,
    RegistryValueType_RegResourceList = 8,
    RegistryValueType_RegFullResourceDescriptor = 9,
    RegistryValueType_RegResourceRequirementsList = 10,
    RegistryValueType_RegQword = 11,
};


/*
 *
 * Interface UFCase.Host.Manifest.IAssemblyClass
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.Assembly
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IAssemblyClass[] = L"UFCase.Host.Manifest.IAssemblyClass";
/* [object, version, uuid("1254A4C8-452B-5744-B544-72BC8D34A2BC"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClassVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Identity )(
        __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
        /* [retval, out] */__x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * * __returnValue_get_Identity__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Version )(
        __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
        /* [retval, out] */__x_ABI_CUFCase_CHost_CManifest_CIVersionClass * * __returnValue_get_Version__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Files )(
        __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
        /* [out] */UINT32 * ____returnValue_get_Files__Size,
        /* [size_is(, *(____returnValue_get_Files__Size)), retval, out] */__x_ABI_CUFCase_CHost_CManifest_CIFileClass * * * __returnValue_get_Files__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Keys )(
        __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
        /* [out] */UINT32 * ____returnValue_get_Keys__Size,
        /* [size_is(, *(____returnValue_get_Keys__Size)), retval, out] */__x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass * * * __returnValue_get_Keys__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Dependencies )(
        __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * This,
        /* [out] */UINT32 * ____returnValue_get_Dependencies__Size,
        /* [size_is(, *(____returnValue_get_Dependencies__Size)), retval, out] */__x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * * * __returnValue_get_Dependencies__
        );
    END_INTERFACE
    
} __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClassVtbl;

interface __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass
{
    CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClassVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_get_Identity(This,__returnValue_get_Identity__) \
    ( (This)->lpVtbl->get_Identity(This,__returnValue_get_Identity__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_get_Version(This,__returnValue_get_Version__) \
    ( (This)->lpVtbl->get_Version(This,__returnValue_get_Version__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_get_Files(This,____returnValue_get_Files__Size,__returnValue_get_Files__) \
    ( (This)->lpVtbl->get_Files(This,____returnValue_get_Files__Size,__returnValue_get_Files__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_get_Keys(This,____returnValue_get_Keys__Size,__returnValue_get_Keys__) \
    ( (This)->lpVtbl->get_Keys(This,____returnValue_get_Keys__Size,__returnValue_get_Keys__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_get_Dependencies(This,____returnValue_get_Dependencies__Size,__returnValue_get_Dependencies__) \
    ( (This)->lpVtbl->get_Dependencies(This,____returnValue_get_Dependencies__Size,__returnValue_get_Dependencies__) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IAssemblyDependencyClass
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.AssemblyDependency
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IAssemblyDependencyClass[] = L"UFCase.Host.Manifest.IAssemblyDependencyClass";
/* [object, version, uuid("59EC1B96-C604-5C7C-AFC9-648BA4A9B001"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClassVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Identity )(
        __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This,
        /* [retval, out] */__x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * * __returnValue_get_Identity__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Type )(
        __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_Type__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Install )(
        __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_Install__
        );
    END_INTERFACE
    
} __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClassVtbl;

interface __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass
{
    CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClassVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_get_Identity(This,__returnValue_get_Identity__) \
    ( (This)->lpVtbl->get_Identity(This,__returnValue_get_Identity__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_get_Type(This,__returnValue_get_Type__) \
    ( (This)->lpVtbl->get_Type(This,__returnValue_get_Type__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_get_Install(This,__returnValue_get_Install__) \
    ( (This)->lpVtbl->get_Install(This,__returnValue_get_Install__) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIAssemblyDependencyClass_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IAssemblyIdentityClass
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.AssemblyIdentity
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IAssemblyIdentityClass[] = L"UFCase.Host.Manifest.IAssemblyIdentityClass";
/* [object, version, uuid("26D5B743-6C88-5B41-9F37-35A7DE5F6144"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClassVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Name )(
        __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_Name__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_PublicKeyToken )(
        __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_PublicKeyToken__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Language )(
        __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_Language__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ProcessorArchitecture )(
        __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_ProcessorArchitecture__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Version )(
        __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_Version__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Type )(
        __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_Type__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_KeyForm )(
        __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_KeyForm__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_HashCode )(
        __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_HashCode__
        );
    END_INTERFACE
    
} __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClassVtbl;

interface __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass
{
    CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClassVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_get_Name(This,__returnValue_get_Name__) \
    ( (This)->lpVtbl->get_Name(This,__returnValue_get_Name__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_get_PublicKeyToken(This,__returnValue_get_PublicKeyToken__) \
    ( (This)->lpVtbl->get_PublicKeyToken(This,__returnValue_get_PublicKeyToken__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_get_Language(This,__returnValue_get_Language__) \
    ( (This)->lpVtbl->get_Language(This,__returnValue_get_Language__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_get_ProcessorArchitecture(This,__returnValue_get_ProcessorArchitecture__) \
    ( (This)->lpVtbl->get_ProcessorArchitecture(This,__returnValue_get_ProcessorArchitecture__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_get_Version(This,__returnValue_get_Version__) \
    ( (This)->lpVtbl->get_Version(This,__returnValue_get_Version__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_get_Type(This,__returnValue_get_Type__) \
    ( (This)->lpVtbl->get_Type(This,__returnValue_get_Type__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_get_KeyForm(This,__returnValue_get_KeyForm__) \
    ( (This)->lpVtbl->get_KeyForm(This,__returnValue_get_KeyForm__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_get_HashCode(This,__returnValue_get_HashCode__) \
    ( (This)->lpVtbl->get_HashCode(This,__returnValue_get_HashCode__) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIAssemblyIdentityClass_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IComStreamWrapper
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IComStreamWrapper[] = L"UFCase.Host.Manifest.IComStreamWrapper";
/* [object, version, uuid("3347D112-6F3D-519A-8493-F5E3F1A1079E")] */
typedef struct __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapperVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
END_INTERFACE
    
} __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapperVtbl;

interface __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper
{
    CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapperVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IFileClass
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.File
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIFileClass_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIFileClass_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IFileClass[] = L"UFCase.Host.Manifest.IFileClass";
/* [object, version, uuid("B3B96E25-DA85-5851-A796-BDFABCB19CFD"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CHost_CManifest_CIFileClassVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DestinationName )(
        __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_DestinationName__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_DestinationPath )(
        __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_DestinationPath__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_SourcePath )(
        __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_SourcePath__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_SourceName )(
        __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_SourceName__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_ImportPath )(
        __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_ImportPath__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Hash )(
        __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_Hash__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_HashAlgorithm )(
        __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_HashAlgorithm__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_SizeInByte )(
        __x_ABI_CUFCase_CHost_CManifest_CIFileClass * This,
        /* [retval, out] */INT32 * __returnValue_get_SizeInByte__
        );
    END_INTERFACE
    
} __x_ABI_CUFCase_CHost_CManifest_CIFileClassVtbl;

interface __x_ABI_CUFCase_CHost_CManifest_CIFileClass
{
    CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIFileClassVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_get_DestinationName(This,__returnValue_get_DestinationName__) \
    ( (This)->lpVtbl->get_DestinationName(This,__returnValue_get_DestinationName__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_get_DestinationPath(This,__returnValue_get_DestinationPath__) \
    ( (This)->lpVtbl->get_DestinationPath(This,__returnValue_get_DestinationPath__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_get_SourcePath(This,__returnValue_get_SourcePath__) \
    ( (This)->lpVtbl->get_SourcePath(This,__returnValue_get_SourcePath__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_get_SourceName(This,__returnValue_get_SourceName__) \
    ( (This)->lpVtbl->get_SourceName(This,__returnValue_get_SourceName__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_get_ImportPath(This,__returnValue_get_ImportPath__) \
    ( (This)->lpVtbl->get_ImportPath(This,__returnValue_get_ImportPath__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_get_Hash(This,__returnValue_get_Hash__) \
    ( (This)->lpVtbl->get_Hash(This,__returnValue_get_Hash__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_get_HashAlgorithm(This,__returnValue_get_HashAlgorithm__) \
    ( (This)->lpVtbl->get_HashAlgorithm(This,__returnValue_get_HashAlgorithm__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIFileClass_get_SizeInByte(This,__returnValue_get_SizeInByte__) \
    ( (This)->lpVtbl->get_SizeInByte(This,__returnValue_get_SizeInByte__) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIFileClass;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIFileClass_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IManifestParserClass
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.ManifestParser
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IManifestParserClass[] = L"UFCase.Host.Manifest.IManifestParserClass";
/* [object, version, uuid("5D779A6F-A8F9-55DF-A5C9-C1E63DD9E4C6"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClassVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
END_INTERFACE
    
} __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClassVtbl;

interface __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass
{
    CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClassVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIManifestParserClass_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IManifestParserStatic
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.ManifestParser
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IManifestParserStatic[] = L"UFCase.Host.Manifest.IManifestParserStatic";
/* [object, version, uuid("6D41CE8B-48CC-5CA6-A397-4951356131BC"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStaticVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *ParseFromPath )(
        __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic * This,
        /* [in] */HSTRING path,
        /* [retval, out] */__x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * * __returnValue_ParseFromPath__
        );
    HRESULT ( STDMETHODCALLTYPE *ParseFromStream )(
        __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic * This,
        /* [in] */__x_ABI_CUFCase_CHost_CManifest_CIComStreamWrapper * stream,
        /* [retval, out] */__x_ABI_CUFCase_CHost_CManifest_CIAssemblyClass * * __returnValue_ParseFromStream__
        );
    END_INTERFACE
    
} __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStaticVtbl;

interface __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic
{
    CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStaticVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_ParseFromPath(This,path,__returnValue_ParseFromPath__) \
    ( (This)->lpVtbl->ParseFromPath(This,path,__returnValue_ParseFromPath__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_ParseFromStream(This,stream,__returnValue_ParseFromStream__) \
    ( (This)->lpVtbl->ParseFromStream(This,stream,__returnValue_ParseFromStream__) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIManifestParserStatic_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IRegistryKeyClass
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.RegistryKey
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IRegistryKeyClass[] = L"UFCase.Host.Manifest.IRegistryKeyClass";
/* [object, version, uuid("46A8BABC-13B9-5B22-A7BC-007EDEA03028"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClassVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Name )(
        __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_Name__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Values )(
        __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass * This,
        /* [out] */UINT32 * ____returnValue_get_Values__Size,
        /* [size_is(, *(____returnValue_get_Values__Size)), retval, out] */__x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * * * __returnValue_get_Values__
        );
    END_INTERFACE
    
} __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClassVtbl;

interface __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass
{
    CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClassVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_get_Name(This,__returnValue_get_Name__) \
    ( (This)->lpVtbl->get_Name(This,__returnValue_get_Name__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_get_Values(This,____returnValue_get_Values__Size,__returnValue_get_Values__) \
    ( (This)->lpVtbl->get_Values(This,____returnValue_get_Values__Size,__returnValue_get_Values__) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIRegistryKeyClass_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IRegistryValueClass
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.RegistryValue
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IRegistryValueClass[] = L"UFCase.Host.Manifest.IRegistryValueClass";
/* [object, version, uuid("E2BDF2C4-239A-535A-AD89-2C439B9FBBC0"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClassVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Name )(
        __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_Name__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Type )(
        __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This,
        /* [retval, out] */__x_ABI_CUFCase_CHost_CManifest_CRegistryValueType * __returnValue_get_Type__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Data )(
        __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass * This,
        /* [retval, out] */IInspectable * * __returnValue_get_Data__
        );
    END_INTERFACE
    
} __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClassVtbl;

interface __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass
{
    CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClassVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_get_Name(This,__returnValue_get_Name__) \
    ( (This)->lpVtbl->get_Name(This,__returnValue_get_Name__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_get_Type(This,__returnValue_get_Type__) \
    ( (This)->lpVtbl->get_Type(This,__returnValue_get_Type__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_get_Data(This,__returnValue_get_Data__) \
    ( (This)->lpVtbl->get_Data(This,__returnValue_get_Data__) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIRegistryValueClass_INTERFACE_DEFINED__) */


/*
 *
 * Interface UFCase.Host.Manifest.IVersionClass
 *
 * Interface is a part of the implementation of type UFCase.Host.Manifest.Version
 *
 *
 */
#if !defined(____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_INTERFACE_DEFINED__)
#define ____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_UFCase_Host_Manifest_IVersionClass[] = L"UFCase.Host.Manifest.IVersionClass";
/* [object, version, uuid("9B56B015-02B3-5D08-8F39-43E5E5F74EC0"), exclusiveto] */
typedef struct __x_ABI_CUFCase_CHost_CManifest_CIVersionClassVtbl
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
/* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Major )(
        __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
        /* [retval, out] */INT32 * __returnValue_get_Major__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Minor )(
        __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
        /* [retval, out] */INT32 * __returnValue_get_Minor__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Build )(
        __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
        /* [retval, out] */INT32 * __returnValue_get_Build__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Revision )(
        __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
        /* [retval, out] */INT32 * __returnValue_get_Revision__
        );
    /* [propget] */HRESULT ( STDMETHODCALLTYPE *get_Value )(
        __x_ABI_CUFCase_CHost_CManifest_CIVersionClass * This,
        /* [retval, out] */HSTRING * __returnValue_get_Value__
        );
    END_INTERFACE
    
} __x_ABI_CUFCase_CHost_CManifest_CIVersionClassVtbl;

interface __x_ABI_CUFCase_CHost_CManifest_CIVersionClass
{
    CONST_VTBL struct __x_ABI_CUFCase_CHost_CManifest_CIVersionClassVtbl *lpVtbl;
};

#ifdef COBJMACROS
#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_get_Major(This,__returnValue_get_Major__) \
    ( (This)->lpVtbl->get_Major(This,__returnValue_get_Major__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_get_Minor(This,__returnValue_get_Minor__) \
    ( (This)->lpVtbl->get_Minor(This,__returnValue_get_Minor__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_get_Build(This,__returnValue_get_Build__) \
    ( (This)->lpVtbl->get_Build(This,__returnValue_get_Build__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_get_Revision(This,__returnValue_get_Revision__) \
    ( (This)->lpVtbl->get_Revision(This,__returnValue_get_Revision__) )

#define __x_ABI_CUFCase_CHost_CManifest_CIVersionClass_get_Value(This,__returnValue_get_Value__) \
    ( (This)->lpVtbl->get_Value(This,__returnValue_get_Value__) )


#endif /* COBJMACROS */


EXTERN_C const IID IID___x_ABI_CUFCase_CHost_CManifest_CIVersionClass;
#endif /* !defined(____x_ABI_CUFCase_CHost_CManifest_CIVersionClass_INTERFACE_DEFINED__) */


/*
 *
 * Class UFCase.Host.Manifest.Assembly
 *
 * RuntimeClass can be activated.
 *
 * Class implements the following interfaces:
 *    UFCase.Host.Manifest.IAssemblyClass ** Default Interface **
 *
 */

#ifndef RUNTIMECLASS_UFCase_Host_Manifest_Assembly_DEFINED
#define RUNTIMECLASS_UFCase_Host_Manifest_Assembly_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Host_Manifest_Assembly[] = L"UFCase.Host.Manifest.Assembly";
#endif


/*
 *
 * Class UFCase.Host.Manifest.AssemblyDependency
 *
 * RuntimeClass can be activated.
 *
 * Class implements the following interfaces:
 *    UFCase.Host.Manifest.IAssemblyDependencyClass ** Default Interface **
 *
 */

#ifndef RUNTIMECLASS_UFCase_Host_Manifest_AssemblyDependency_DEFINED
#define RUNTIMECLASS_UFCase_Host_Manifest_AssemblyDependency_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Host_Manifest_AssemblyDependency[] = L"UFCase.Host.Manifest.AssemblyDependency";
#endif


/*
 *
 * Class UFCase.Host.Manifest.AssemblyIdentity
 *
 * RuntimeClass can be activated.
 *
 * Class implements the following interfaces:
 *    UFCase.Host.Manifest.IAssemblyIdentityClass ** Default Interface **
 *
 */

#ifndef RUNTIMECLASS_UFCase_Host_Manifest_AssemblyIdentity_DEFINED
#define RUNTIMECLASS_UFCase_Host_Manifest_AssemblyIdentity_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Host_Manifest_AssemblyIdentity[] = L"UFCase.Host.Manifest.AssemblyIdentity";
#endif


/*
 *
 * Class UFCase.Host.Manifest.File
 *
 * RuntimeClass can be activated.
 *
 * Class implements the following interfaces:
 *    UFCase.Host.Manifest.IFileClass ** Default Interface **
 *
 */

#ifndef RUNTIMECLASS_UFCase_Host_Manifest_File_DEFINED
#define RUNTIMECLASS_UFCase_Host_Manifest_File_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Host_Manifest_File[] = L"UFCase.Host.Manifest.File";
#endif


/*
 *
 * Class UFCase.Host.Manifest.ManifestParser
 *
 * RuntimeClass can be activated.
 *
 * RuntimeClass contains static methods.
 *
 * Class implements the following interfaces:
 *    UFCase.Host.Manifest.IManifestParserClass ** Default Interface **
 *
 */

#ifndef RUNTIMECLASS_UFCase_Host_Manifest_ManifestParser_DEFINED
#define RUNTIMECLASS_UFCase_Host_Manifest_ManifestParser_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Host_Manifest_ManifestParser[] = L"UFCase.Host.Manifest.ManifestParser";
#endif


/*
 *
 * Class UFCase.Host.Manifest.RegistryKey
 *
 * RuntimeClass can be activated.
 *
 * Class implements the following interfaces:
 *    UFCase.Host.Manifest.IRegistryKeyClass ** Default Interface **
 *
 */

#ifndef RUNTIMECLASS_UFCase_Host_Manifest_RegistryKey_DEFINED
#define RUNTIMECLASS_UFCase_Host_Manifest_RegistryKey_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Host_Manifest_RegistryKey[] = L"UFCase.Host.Manifest.RegistryKey";
#endif


/*
 *
 * Class UFCase.Host.Manifest.RegistryValue
 *
 * RuntimeClass can be activated.
 *
 * Class implements the following interfaces:
 *    UFCase.Host.Manifest.IRegistryValueClass ** Default Interface **
 *
 */

#ifndef RUNTIMECLASS_UFCase_Host_Manifest_RegistryValue_DEFINED
#define RUNTIMECLASS_UFCase_Host_Manifest_RegistryValue_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Host_Manifest_RegistryValue[] = L"UFCase.Host.Manifest.RegistryValue";
#endif


/*
 *
 * Class UFCase.Host.Manifest.Version
 *
 * RuntimeClass can be activated.
 *
 * Class implements the following interfaces:
 *    UFCase.Host.Manifest.IVersionClass ** Default Interface **
 *
 */

#ifndef RUNTIMECLASS_UFCase_Host_Manifest_Version_DEFINED
#define RUNTIMECLASS_UFCase_Host_Manifest_Version_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_UFCase_Host_Manifest_Version[] = L"UFCase.Host.Manifest.Version";
#endif




#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
#endif // __UFCase2EHost2EManifest_p_h__

#endif // __UFCase2EHost2EManifest_h__
