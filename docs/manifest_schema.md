# Basic analysis of `urn:schemas-microsoft-com:asm.v3`

### Attension

For the exact definition of `asm.v3`(component manifest only), please refer to the type library of [CMIv2.dll].

This documentation is written before I found that CMIv2 provides a data structure definition and a parser implementation of it. Now it is for the rest, like package manifest and application manifest.

### TOC: Element List

```
ParseAccessControl
ParseAction
ParseActions
ParseActivatableClass
ParseAppServerAI
ParseApplicationRequestMinimum
ParseAppxProvisionPackage
ParseAppxRegistration
ParseAssemblyDocument
ParseAssemblyRequest
ParseBcdedit
ParseBcdeditElementType
ParseBeforeApplicationStartup
ParseBfsvc
ParseBindingRedirect
ParseCapabilities
ParseCategoryInstance
ParseCategoryMembership
ParseCleanupCache
ParseComClass
ParseComInterfaceProxyStub
ParseCommandLine
ParseComplexType
ParseComplexTypeElement
ParseConfiguration
ParseConfigurationSchema
ParseConfigureIEOptionalComponentsAI
ParseConfigureNetFx
ParseContainsSettings
ParseCounters
ParseCustomHostRequired
ParseCustomUX
ParseDefaultAssemblyRequest
ParseDependency
ParseDependentAssembly
ParseDependentOS
ParseDeployment
ParseDeploymentProvider
ParseDigestValue
ParseDirectories
ParseDirectory
ParseDirectorySD
ParseEVDAI
ParseEdgeAI
ParseElements
ParseEnableRpcAI
ParseEntryPoint
ParseEvents
ParseExpiration
ParseFailureActions
ParseFeatureSettingsOverride
ParseFile
ParseFileAssociation
ParseFilter
ParseFirewallGroupActivation
ParseFirewallRule
ParseForwardDiffInfo
ParseFveUpdateAI
ParseGac
ParseGenericCommand
ParseGenericCommands
ParseGroupTrustee
ParseHTTPAI
ParseHashTransforms
ParseHotPatchAI
ParseIEFileInstallAI
ParseIPermission
ParseId
ParseIisSetup
ParseImaging
ParseImpactType
ParseInstrumentation
ParseLink
ParseLodctr
ParseLodctrDat
ParseManifestFileSD
ParseManifestRegKeySD
ParseManifestVersionType
ParseMembers
ParseMemberships
ParseMetadata
ParseMigration
ParseModeMemberships
ParseMof
ParseMsdtc
ParseMsdtcActionType
ParseMsix
ParseMsmqAdIntegrationOnlineInstall
ParseMsmqDownlevelClientOnlineInstall
ParseMsmqHttpOnlineInstall
ParseMsmqTriggersOnlineInstall
ParseMsmqWorkgroupOnlineInstall
ParseNetworkComponents
ParseNgen
ParseNoInheritable
ParseNullDiffInfo
ParseOs
ParseOsVersionInfo
ParseOverridable
ParsePackage
ParseParam
ParsePath
ParsePbr
ParsePeerDistAI
ParsePermissionSet
ParsePlugin
ParsePluginInformation
ParsePrivileges
ParseProgid
ParseProviderOrder
ParseRDWebAI
ParseRegistryKey
ParseRegistryKeys
ParseRegistryValue
ParseRequestedExecutionLevel
ParseRequestedExecutionLevelType
ParseRequestedPrivileges
ParseRescache
ParseRestriction
ParseReverseDiffInfo
ParseSchema
ParseSchemaElement
ParseSecureBoot
ParseSecureBootUpdateType
ParseSecurity
ParseSecurityDescriptor
ParseSecurityDescriptorDefinition
ParseSecurityDescriptorDefinitions
ParseSecurityTemplate
ParseSequence
ParseServiceData
ParseServiceErrorControlType
ParseServiceGroup
ParseServiceLaunchProtectedType
ParseServiceModelReg
ParseServiceSidType
ParseServiceStartType
ParseServiceTrigger
ParseServiceTriggerType
ParseSetIEInstalledDateAI
ParseSetupIppAI
ParseSetupLprAI
ParseSetupMpdwAI
ParseSetupMxdwAI
ParseSetupWfsAI
ParseShortCut
ParseSimpleType
ParseSppInstaller
ParseStartAfterInstallType
ParseSubscription
ParseSysprepInformation
ParseSysprepModule
ParseSysprepProvider
ParseSysprepStageType
ParseTask
ParseTaskScheduler
ParseThreadingModel
ParseTimeUnitType
ParseTimezoneAI
ParseTimezoneresourceAI
ParseTransformInvoke
ParseTransforms
ParseTriggerData
ParseTrustInfo
ParseTrustees
ParseTssDisAI
ParseTypelib
ParseUnattendAction
ParseUnattendActions
ParseUpdate
ParseUpgradeAI
ParseUpgradeAINi
ParseVmHostAI
ParseWcpAIRebootAwareTestInstallerMarker
ParseWcpMidgroundInstallerTestMarker
ParseWcpTestInstaller2
ParseWcpTestInstallerMarker
ParseWcpTestInstallerOfflineOnce
ParseWcpTestInstallerOnlineOnly
ParseWindowClass
ParseWinrtThreadingModel
ParseWinsockAppPermittedLspCategories
ParseWinsockNameSpaceOnlineInstall
ParseWinsockTransportOnlineInstall
ParseassemblyIdentityNode
ParsecomInterfaceExternalProxyStubNode
```

```
assembly
assembly/AppServerAI
assembly/AppxProvisionPackage
assembly/EVDAI
assembly/EdgeAI
assembly/EnableRpcAI
assembly/FeatureSettingsOverride
assembly/HTTPAI/AddUrl
assembly/HotPatchAI
assembly/IEFileInstallAI
assembly/IEFileInstallAI/IEFileInstallAIChild
assembly/RDWebAI
assembly/SecureBoot
assembly/SetupIppAI
assembly/SetupLprAI
assembly/SetupMpdwAI
assembly/SetupMxdwAI
assembly/Transforms
assembly/Transforms/TransformInvoke
assembly/Transforms/TransformInvoke/Param
assembly/TssDisAI
assembly/WinsockAppPermittedLspCategories
assembly/WinsockNameSpaceOnlineInstall
assembly/WinsockTransportOnlineInstall
assembly/WinsockTransportOnlineInstall/mappingRow
assembly/WinsockTransportOnlineInstall/protocol
assembly/WinsockTransportOnlineInstall/protocol/providerFlag
assembly/WinsockTransportOnlineInstall/protocol/serviceFlag
assembly/activateable
assembly/application
assembly/assemblyIdentity
assembly/bcdedit
assembly/bfsvc
assembly/category
assembly/cleanupCache
assembly/clrClass
assembly/clrSurrogate
assembly/configuration
assembly/configureNetFx
assembly/configureNetFx/netFxState
assembly/dependency
assembly/dependency/dependentAssembly
assembly/dependency/dependentAssembly/assemblyIdentity
assembly/dependency/dependentAssembly/hash
assembly/dependency/dependentAssembly/hash/DigestMethod
assembly/dependency/dependentAssembly/hash/DigestValue/pcdata
assembly/dependency/dependentAssembly/hash/Transforms/Transform
assembly/dependency/dependentOS
assembly/dependency/dependentOS/osVersionInfo/os
assembly/deployment
assembly/deployment/deploymentProvider
assembly/deployment/subscription/update/expiration
assembly/description
assembly/directories/directory
assembly/directories/directory/securityDescriptor
assembly/directories/directory/systemProtection
assembly/entryPoint
assembly/entryPoint/assemblyIdentity
assembly/entryPoint/commandLine
assembly/file
assembly/file/comClass
assembly/file/comClass/progid/pcdata
assembly/file/comInterfaceProxyStub
assembly/file/gac
assembly/file/hash
assembly/file/hash/DigestMethod
assembly/file/hash/Transforms
assembly/file/ngen
assembly/file/securityDescriptor
assembly/file/signatureInfo/signatureDescriptor
assembly/file/typelib
assembly/file/windowClass
assembly/file/windowClass/pcdata
assembly/fveUpdateAI
assembly/iisSetup
assembly/iisSetup/installGlobalModule
assembly/iisSetup/installHandler
assembly/iisSetup/installModule
assembly/imaging/sysprepInformation/sysprepModule
assembly/localization/resources
assembly/localization/resources/stringTable/string
assembly/memberships/categoryMembership
assembly/memberships/categoryMembership/categoryInstance
assembly/memberships/categoryMembership/id
assembly/migration
assembly/msdtc
assembly/mvid
assembly/networkComponents
assembly/networkComponents/clientDriver
assembly/networkComponents/filterDriver
assembly/networkComponents/netAdapter
assembly/networkComponents/netAdapterDriver
assembly/networkComponents/protocolDriver
assembly/networkComponents/protocolDriver/bind
assembly/networkComponents/protocolDriver/property
assembly/networkComponents/serviceDriver
assembly/registryKeys/registryKey
assembly/registryKeys/registryKey/registryValue
assembly/registryKeys/registryKey/securityDescriptor
assembly/registryKeys/registryKey/systemProtection
assembly/runtime
assembly/serviceModelReg
assembly/trustInfo
assembly/trustInfo/security/accessControl/securityDescriptorDefinitions/securityDescriptorDefinition
assembly/trustInfo/security/accessControl/trustees/groupTrustee
assembly/trustInfo/security/accessControl/trustees/groupTrustee/capabilities/pcdata
assembly/trustInfo/security/accessControl/trustees/groupTrustee/members/pcdata
assembly/trustInfo/security/accessControl/trustees/groupTrustee/privileges/pcdata
assembly/trustInfo/security/applicationRequestMinimum
assembly/trustInfo/security/applicationRequestMinimum/PermissionSet
assembly/trustInfo/security/applicationRequestMinimum/defaultAssemblyRequest
```

### AccessControl

Type: Component

XPath: `/assembly/trustInfo/security/accessControl`

Hint: Partially documented. `/assembly/trustInfo/security/requestedPrivileges` is well known.

```xml
<assembly>
  <trustInfo>
    <security>
      <accessControl>
        <securityDescriptorDefinitions>
          <securityDescriptorDefinition name="WRP_REGKEY_DEFAULT_SDDL" sddl="O:S-1-5-80-956008885-3418522649-1831038044-1853292631-2271478464G:S-1-5-80-956008885-3418522649-1831038044-1853292631-2271478464D:P(A;CI;GA;;;S-1-5-80-956008885-3418522649-1831038044-1853292631-2271478464)(A;CI;GR;;;SY)(A;CI;GR;;;BA)(A;CI;GR;;;BU)(A;CI;GR;;;S-1-15-2-1)(A;CI;GR;;;S-1-15-3-1024-1065365936-1281604716-3511738428-1654721687-432734479-3232135806-4053264122-3456934681)" operationHint="replace" />
          <securityDescriptorDefinition name="WRP_FILE_DEFAULT_SDDL" sddl="O:S-1-5-80-956008885-3418522649-1831038044-1853292631-2271478464G:S-1-5-80-956008885-3418522649-1831038044-1853292631-2271478464D:P(A;;FA;;;S-1-5-80-956008885-3418522649-1831038044-1853292631-2271478464)(A;;GRGX;;;BA)(A;;GRGX;;;SY)(A;;GRGX;;;BU)(A;;GRGX;;;S-1-15-2-1)(A;;GRGX;;;S-1-15-2-2)S:(AU;FASA;0x000D0116;;;WD)" operationHint="replace" />
        </securityDescriptorDefinitions>
      </accessControl>
    </security>
  </trustInfo>
</assembly>
```

And reference the sd definitions using `securityDescriptor` element.

```xml
<assembly>
  <registryKey keyName="HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Appx\AppxAllUserStore\InboxApplications\Microsoft.Windows.StartMenuExperienceHost_10.0.22621.1928_neutral_neutral_cw5n1h2txyewy">
    <registryValue name="Path" valueType="REG_SZ" value="$(runtime.windows)\SystemApps\Microsoft.Windows.StartMenuExperienceHost_cw5n1h2txyewy\AppxManifest.xml" />
    <securityDescriptor name="REGKEY_APPXALLUSERSTORE_SDDL" />
  </registryKey>
  <directories>
    <directory destinationPath="$(runtime.system32)\spp\tokens\skus\ProfessionalSingleLanguage" owner="true">
      <securityDescriptor name="WRP_PARENT_DIR_DEFAULT_SDDL" />
      <systemProtection behavior="notProtected" />
    </directory>
  </directories>
</assembly>
```

### Actions & Action

Type: Component

XPath: `/assembly/memberships/categoryMembership/categoryInstance/serviceData/failureActions/actions/action`

Mainly used in service boot failure action: retry behaviors.

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <assemblyIdentity name="Microsoft-Windows-Messaging-MessagingService" version="10.0.22621.1635" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
  <memberships>
    <categoryMembership>
      <id name="Microsoft.Windows.Categories.Services" version="10.0.22621.1635" publicKeyToken="31bf3856ad364e35" typeName="Service" />
      <categoryInstance>
        <serviceData name="MessagingService" displayName="@%SystemRoot%\system32\MessagingService.dll,-100" errorControl="ignore" start="demand" type="win32UserShareProcess" description="@%SystemRoot%\system32\MessagingService.dll,-101" imagePath="%SystemRoot%\system32\svchost.exe -k UnistackSvcGroup" objectName="LocalSystem" requiredPrivileges="SeChangeNotifyPrivilege,SeCreateGlobalPrivilege" sidType="unrestricted">
          <serviceTrigger action="start" subtype="WNF_STATE_CHANGE" type="WnfStateEvent">
            <triggerData type="binary" value="7518BCA33E039513" />
          </serviceTrigger>
          <failureActions resetPeriod="86400">
            <actions>
              <action delay="10000" type="restartService" />
              <action delay="10000" type="restartService" />
              <action delay="10000" type="restartService" />
              <action delay="10000" type="none" />
            </actions>
          </failureActions>
        </serviceData>
      </categoryInstance>
    </categoryMembership>
  </memberships>
</assembly>
```

TODO: action type

### ActivatableClass

Type: Application

XPath: `/assembly/file/activatableClass`

Hint: Documented. This is for registration-free WinRT. The element resides in application isolation manifests.

Read more: [How Registration-free WinRT Works
](https://blogs.windows.com/windowsdeveloper/2019/04/30/enhancing-non-packaged-desktop-apps-using-windows-runtime-components/)

The registration of WinRT classes is done by registry key values. Check [the manifest of `Microsoft-Windows-DirectUI`(`Windows.UI.Xaml`)](./manifests/com_directui.xml) for an instance.

```xml
<assembly manifestVersion="1.0" xmlns="urn:schemas-microsoft-com:asm.v1">
  <assemblyIdentity version="1.0.0.0" name="MyApplication.app"/>
  <file name="WinRTComponent.dll">
    <activatableClass
      name="WinRTComponent.Class1"
      threadingModel="both"
      xmlns="urn:schemas-microsoft-com:winrt.v1" />
    <activatableClass
      name="WinRTComponent.Class2"
      threadingModel="both"
      xmlns="urn:schemas-microsoft-com:winrt.v1" />
  </file>
</assembly>
```

Refer to [Application Manifests](https://learn.microsoft.com/en-us/windows/win32/sbscs/application-manifests#activatableclass).

### AppServerAI

Type: Unknown

XPath: `/assembly/appServerAI`

TODO: Unknown.

### ApplicationRequestMinimum

Type: Application

XPath: `/assembly/trustInfo/security/applicationRequestMinimum`

Hint: Documented. This is for UAC.

```xml
<trustInfo>
   <security>
      <applicationRequestMinimum>
         <PermissionSet
            ID
            Unrestricted>
            <IPermission
               class
               version
               Unrestricted
            />
         </PermissionSet>
         <defaultAssemblyRequest
            permissionSetReference
         />
         <assemblyRequest
            name
            permissionSetReference
         />
      </applicationRequestMinimum>
      <requestedPrivileges>
         <requestedExecutionLevel
            level
            uiAccess
         />
      </requestedPrivileges>
   </security>
</trustInfo>
```

### AppxProvisionPackage

Type: Component (?)

XPath: `/assembly/appxProvisionPackage`

TODO: Unknown.

### AppxRegistration

Type: Component (?)

XPath: `/assembly/appxRegistration`

Denoting this manifest is a registration assembly of appx. See [comp_appxreg.xml](./manifests/comp_appxreg.xml) for an instance.

But the actual registration is still done by registry manipulations:

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <assemblyIdentity name="Microsoft-Windows-StartMenuExperienceHost.AppxSetup" version="10.0.22621.1928" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
  <!-- appx meta files like AppxManifest.xml AppxBlockMap.xml AppxSignature.p7x. Yes, the actual application files is installed by other assemblies. -->
  <registryKey keyName="HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Appx\AppxAllUserStore\InboxApplications\Microsoft.Windows.StartMenuExperienceHost_10.0.22621.1928_neutral_neutral_cw5n1h2txyewy">
    <registryValue name="Path" valueType="REG_SZ" value="$(runtime.windows)\SystemApps\Microsoft.Windows.StartMenuExperienceHost_cw5n1h2txyewy\AppxManifest.xml" />
    <securityDescriptor name="REGKEY_APPXALLUSERSTORE_SDDL" />
  </registryKey>
  <appxRegistration />
</assembly>
```

### AssemblyDocument

Type: Any

XPath: `/assembly`

Hint: Documented. This is the root element of an assembly manifest.

### AssemblyIdentity

Type: Any

XPath: any

```xml
<assemblyIdentity name="Microsoft.Windows.Common-Controls" version="5.82.22621.608" processorArchitecture="amd64" publicKeyToken="6595b64144ccf1df" type="win32" />
```

```xml
<assemblyIdentity name="Microsoft-Windows-Ethernet-Client-Intel-E1i68x64-FOD-Package" version="10.0.22621.2359" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" />
```

```xml
<assemblyIdentity name="Microsoft-Windows-Security-SPP-Component-SKU-Professional-License-Deployment" version="10.0.22621.2359" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
```

### AssemblyRequest

Type: Application

XPath: `/assembly/trustInfo/security/applicationRequestMinimum/assemblyRequest`

Hint: Documented. This is for isolation.

```xml
<trustInfo>
   <security>
      <applicationRequestMinimum>
         <PermissionSet
            ID
            Unrestricted>
            <IPermission
               class
               version
               Unrestricted
            />
         </PermissionSet>
         <defaultAssemblyRequest
            permissionSetReference
         />
         <assemblyRequest
            name
            permissionSetReference
         />
      </applicationRequestMinimum>
      <requestedPrivileges>
         <requestedExecutionLevel
            level
            uiAccess
         />
      </requestedPrivileges>
   </security>
</trustInfo>
```

### Bcdedit & BcdeditElementType

Type: Component

XPath: `/assembly/bcdedit`

TODO: Unknown.

### BeforeApplicationStartup

TODO: Unknown.

### Bfsvc

TODO: Unknown.

### BindingRedirect

TODO: Unknown.

### Capability (Package)

Type: Package

XPath: `/assembly/package/declareCapability/capability`

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" description="Additional fonts: BIZ UDGothic, BIZ UDMincho Medium, Meiryo, Meiryo UI, MS Gothic, MS PGothic, MS UI Gothic, MS Mincho, MS PMincho, UDDigiKyokashoN, UDDigiKyokashoNK, UDDigiKyokashoNP, Yu Mincho" displayName="Japanese Supplemental Fonts" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved" supportInformation="http://support.microsoft.com/?kbid=777777">
  <assemblyIdentity name="Microsoft-Windows-LanguageFeatures-Fonts-Jpan-Package" version="10.0.22621.2359" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" />
  <package identifier="KB777778" releaseType="OnDemand Pack">
    <declareCapability>
      <capability>
        <capabilityIdentity name="Language.Fonts.Jpan" version="1.0" language="und-Jpan" />
      </capability>
    </declareCapability>
  </package>
</assembly>
```

Only apply to some lang.

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" description="Windows PowerShell Integrated Scripting Environment (ISE) is a graphical editor for PowerShell scripts with syntax-coloring, tab completion, and visual debugging." displayName="Windows PowerShell ISE" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved" supportInformation="http://support.microsoft.com/?kbid=777777">
  <assemblyIdentity name="Microsoft-Windows-PowerShell-ISE-FOD-Package" version="10.0.22621.1" processorArchitecture="amd64" language="zh-CN" buildType="release" publicKeyToken="31bf3856ad364e35" />
  <package identifier="Microsoft-Windows-PowerShell-ISE-FOD-zh-CN" releaseType="OnDemand Pack">
    <declareCapability>
      <capability>
        <capabilityIdentity name="Microsoft.Windows.PowerShell.ISE" version="1.0" language="zh-CN" />
      </capability>
      <satelliteInfo>
        <applyTo type="language" value="zh-CN" />
      </satelliteInfo>
    </declareCapability>
  </package>
</assembly>
```

### Capabilities (Application)

Type: Application (?)

XPath: `/assembly/trustInfo/security/accessControl/trustees/groupTrustee/capabilities`

TODO: Unkown.

Note:

(Win32 Access Control Trustees)[https://learn.microsoft.com/en-us/windows/win32/secauthz/trustees]

attribute of groupTrustee

```
v45 = "privileges";
v49 = "members";
v53 = "capabilities";
```

### CategoryMembership & CategoryInstance

Type: Component

XPath: `/assembly/memberships/categoryMembership/categoryInstance`

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <assemblyIdentity name="Microsoft-Windows-ServicingStack-CmiTrust" version="10.0.22621.1" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
  <memberships>
    <categoryMembership>
      <id name="Microsoft.Windows.Categories" version="1.0.0.0" publicKeyToken="365143bb27e7ac8b" typeName="ServicingStackComponent" />
    </categoryMembership>
  </memberships>
</assembly>
```

* `Microsoft.Windows.Categories`
  * `ServicingStackComponent`
  * `BootCritical`
  * `BootRecovery`
  * `SvcHost` with svchost -k name as subcategory, containing a `serviceGroup` element. See [comp_mig_service_actions.xml](./manifests/comp_mig_service_actions.xml) for more info.
* `Microsoft.Windows.Categories.Services`
  * `Service` with service name as subcategory, containing a `serviceData` element.
* Any other id. See [comp_localization.xml](./manifests/comp_localization.xml) for an instance.

TODO: Find out all types.

### CleanupCache

Type: Component (?)

XPath: `/assembly/cleanupCache`

TODO: Unknown.

### ComClass

Type: Application

XPath: `/assembly/file/comClass`

Hint: Documented. Like WinRT, the actual COM registration is done by direct registry manipulations. This is for isolation manifest.

Refer to [Assembly Manifests](https://learn.microsoft.com/en-us/windows/win32/sbscs/assembly-manifests).

```xml
<assembly>
  <file name="sampleu.dll">
    <comClass description="Font Property Page"
      clsid="{0BE35200-8F91-11CE-9DE3-00AA004BB851}"
      threadingModel = "Both"
      tlbid = "{44EC0535-400F-11D0-9DCD-00A0C90391D3}"/>
    <comClass description="Color Property Page"
      clsid="{0BE35201-8F91-11CE-9DE3-00AA004BB851}" 
      progid="ABC.Registrar"/>
  </file>
</assembly>
```

### ComInterfaceProxyStub

Type: Application

Hint: Documented.

Refer to [Assembly Manifests](https://learn.microsoft.com/en-us/windows/win32/sbscs/assembly-manifests).

```xml
<assembly>
  <comInterfaceProxyStub iid="{B6EA2051-048A-11D1-82B9-00C04FB9942E}" name="IAxWinAmbientDispatch" tlbid="{34EC053A-400F-11D0-9DCD-00A0C90391D3}"/>
</assembly>
```

### ComInterfaceExternalProxyStub

Type: Application

Hint: Documented.

Refer to [Assembly Manifests](https://learn.microsoft.com/en-us/windows/win32/sbscs/assembly-manifests).

```xml
<assembly>
  <comInterfaceExternalProxyStub 
    name="IAxWinAmbientDispatch" 
    iid="{B6EA2051-048A-11D1-82B9-00C04FB9942E}" 
    numMethods="35" 
    baseInterface="{00000000-0000-0000-C000-000000000046}"/>
</assembly>
```

### CommandLine

Type: Application

XPath: `/assembly/entryPoint/commandLine`

Refer to [<entryPoint> element (ClickOnce application)](https://learn.microsoft.com/en-us/visualstudio/deployment/entrypoint-element-clickonce-application).

Hint: Documented. This is for ClickOnce.

```xml
<entryPoint
   name
>
   <assemblyIdentity
      name
      version
      processorArchitecture
      language
   />
   <commandLine
      file
      parameters
   />
   <customHostRequired />
   <customUX />
</entryPoint>
```

### ComplexType & ComplexTypeElement

Type: Component

XPath: under `/assembly/configuration/configurationSchema`

This is a setting type of SMI, which denoting that the element has children.

Refer to [WcmSettingType enumeration (wcmconfig.h)](https://learn.microsoft.com/en-us/windows/win32/api/wcmconfig/ne-wcmconfig-wcmsettingtype).

TODO: Complete the XML instance.

### Configuration & ConfigurationSchema

Type: Component

XPath: `/assembly/configuration/configurationSchema`

This is for [SMI](https://learn.microsoft.com/en-us/previous-versions/windows/desktop/smi/settings-management-infrastructure--smi-).

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved." xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <assemblyIdentity name="Microsoft-Windows-Sidebar" version="10.0.22621.1" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
  <asmv3:configuration xmlns:asmv3="urn:schemas-microsoft-com:asm.v3" xmlns:wcm="http://schemas.microsoft.com/WMIConfig/2002/State">
    <asmv3:configurationSchema>
      <xsd:schema targetNamespace="Microsoft-Windows-Bits-Client">
        <xsd:element default="true" name="SidebarVisible" type="xsd:boolean" wcm:dataOnly="false" wcm:deprecated="This setting has been deprecated." wcm:description="This setting is deprecated, do not use this setting.The Sidebar is not available in Windows 8." wcm:displayName="SidebarVisible" wcm:handler="regkey('HKLM\Software\Microsoft\Windows NT\CurrentVersion\UnattendSettings\Sidebar')" wcm:legacyType="REG_DWORD" wcm:passes="oobeSystem" wcm:scope="allUsers" wcm:visible="true" />
        <xsd:element default="true" name="SidebarOnByDefault" type="xsd:boolean" wcm:dataOnly="false" wcm:deprecated="This setting has been deprecated." wcm:description="This setting is deprecated and should not be used. By default, the Sidebar is not available in Windows 8." wcm:displayName="SidebarOnByDefault" wcm:handler="regkey('HKLM\Software\Microsoft\Windows NT\CurrentVersion\UnattendSettings\Sidebar')" wcm:legacyType="REG_DWORD" wcm:passes="oobeSystem" wcm:scope="allUsers" wcm:visible="true" />
        <xsd:element default="Default" name="LayoutPosition" type="xsd:string" wcm:dataOnly="false" wcm:deprecated="This setting has been deprecated." wcm:description="This setting is deprecated, do not use this setting.Gadgets are not available in Windows 8." wcm:displayName="LayoutPosition" wcm:handler="regkey('HKLM\Software\Microsoft\Windows NT\CurrentVersion\UnattendSettings\Sidebar')" wcm:legacyType="REG_SZ" wcm:passes="oobeSystem" wcm:scope="allUsers" wcm:visible="true" />
        <xsd:element name="Gadget1" type="xsd:string" wcm:dataOnly="false" wcm:deprecated="This setting has been deprecated." wcm:description="Security Note               This setting has been deprecated in Windows® 8. The information about this deprecated setting is provided for reference only.             Gadgets are not available in Windows 8." wcm:displayName="Gadget1" wcm:handler="regkey('HKLM\Software\Microsoft\Windows NT\CurrentVersion\UnattendSettings\Sidebar')" wcm:legacyType="REG_EXPAND_SZ" wcm:passes="oobeSystem" wcm:scope="allUsers" wcm:visible="true" />
        <xsd:element name="Gadget2" type="xsd:string" wcm:dataOnly="false" wcm:deprecated="This setting has been deprecated." wcm:description="             This setting has been deprecated in Windows® 8. The information about this deprecated setting is provided for reference only.           Gadgets are not available in Windows 8." wcm:displayName="Gadget2" wcm:handler="regkey('HKLM\Software\Microsoft\Windows NT\CurrentVersion\UnattendSettings\Sidebar')" wcm:legacyType="REG_EXPAND_SZ" wcm:passes="oobeSystem" wcm:scope="allUsers" wcm:visible="true" />
        <xsd:element name="Gadget3" type="xsd:string" wcm:dataOnly="false" wcm:deprecated="This setting has been deprecated." wcm:description="             This setting has been deprecated in Windows® 8. The information about this deprecated setting is provided for reference only.           Gadgets are not available in Windows 8." wcm:displayName="Gadget3" wcm:handler="regkey('HKLM\Software\Microsoft\Windows NT\CurrentVersion\UnattendSettings\Sidebar')" wcm:legacyType="REG_EXPAND_SZ" wcm:passes="oobeSystem" wcm:scope="allUsers" wcm:visible="true" />
        <xsd:element name="Gadget4" type="xsd:string" wcm:dataOnly="false" wcm:deprecated="This setting has been deprecated." wcm:description="             This setting has been deprecated in Windows® 8. The information about this deprecated setting is provided for reference only.           Gadgets are not available in Windows 8." wcm:displayName="Gadget4" wcm:handler="regkey('HKLM\Software\Microsoft\Windows NT\CurrentVersion\UnattendSettings\Sidebar')" wcm:legacyType="REG_EXPAND_SZ" wcm:passes="oobeSystem" wcm:scope="allUsers" wcm:visible="true" />
        <xsd:element name="Gadget5" type="xsd:string" wcm:dataOnly="false" wcm:deprecated="This setting has been deprecated." wcm:description="             This setting has been deprecated in Windows® 8. The information about this deprecated setting is provided for reference only.           Gadgets are not available in Windows 8." wcm:displayName="Gadget5" wcm:handler="regkey('HKLM\Software\Microsoft\Windows NT\CurrentVersion\UnattendSettings\Sidebar')" wcm:legacyType="REG_EXPAND_SZ" wcm:passes="oobeSystem" wcm:scope="allUsers" wcm:visible="true" />
      </xsd:schema>
    </asmv3:configurationSchema>
  </asmv3:configuration>
</assembly>
```

### ConfigureIEOptionalComponentsAI

TODO: Unknown.

### ConfigureNetFx

TODO: Unknown.

### ContainsSettings

TODO: Unknown.

### Counters

TODO: Unknown.

### CustomHostRequired

TODO: Unknown.

### CustomInformation (Package)

Type: Package

XPath: `/assembly/package/customInformation`

This example is indicated for the detection of settings page "Optional Features".

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" description="Windows PowerShell Integrated Scripting Environment (ISE) is a graphical editor for PowerShell scripts with syntax-coloring, tab completion, and visual debugging." displayName="Windows PowerShell ISE" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved" supportInformation="http://support.microsoft.com/?kbid=777777">
  <assemblyIdentity name="Microsoft-Windows-PowerShell-ISE-FOD-Package" version="10.0.22621.1" processorArchitecture="amd64" language="zh-CN" buildType="release" publicKeyToken="31bf3856ad364e35" />
  <package identifier="Microsoft-Windows-PowerShell-ISE-FOD-zh-CN" releaseType="OnDemand Pack">
    <mum2:customInformation xmlns:mum2="urn:schemas-microsoft-com:asm.v3">
      <mum2:OptionalFeatures SchemaVersion="1.0">
        <mum2:SettingsPageOptions Visibility="all" FeatureType="default" />
      </mum2:OptionalFeatures>
    </mum2:customInformation>
    <declareCapability>
      <capability>
        <capabilityIdentity name="Microsoft.Windows.PowerShell.ISE" version="1.0" language="zh-CN" />
      </capability>
      <satelliteInfo>
        <applyTo type="language" value="zh-CN" />
      </satelliteInfo>
    </declareCapability>
    <update name="aae126adc919fd5aa61d384c96166bd6">
      <component>
        <assemblyIdentity name="Microsoft-Windows-PowerShell-ISE-FOD-Deployment-LanguagePack" version="10.0.22621.1" processorArchitecture="amd64" language="zh-CN" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
      </component>
    </update>
    <packageExtended packageSize="868521" />
  </package>
</assembly>
```

While this example is for mobile deployment and applicability calculation.

```xml
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <assemblyIdentity name="Microsoft-Windows-SenseClient-Package" version="10.0.22621.2359" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" />
  <package identifier="Microsoft-Windows-SenseClient" releaseType="Feature Pack" targetPartition="mainos" binaryPartition="false">
    <mum2:customInformation xmlns:mum2="urn:schemas-microsoft-com:asm.v3">
      <mum2:phoneInformation phoneRelease="Production" phoneOwner="Microsoft" phoneOwnerType="Microsoft" phoneComponent="Windows.SenseClient" phoneSubComponent="" phoneGroupingKey="" />
      <mum2:applicablePartitions>
        <mum2:partition name="mainos" />
      </mum2:applicablePartitions>
    </mum2:customInformation>
  </package>
</assembly>
```

### CustomUX

TODO: Unknown.

### DefaultAssemblyRequest

Type: Application

XPath: `/assembly/trustInfo/security/defaultAssemblyRequest`

Hint: Documented. This is for UAC.

```xml
<trustInfo>
   <security>
      <applicationRequestMinimum>
         <PermissionSet
            ID
            Unrestricted>
            <IPermission
               class
               version
               Unrestricted
            />
         </PermissionSet>
         <defaultAssemblyRequest
            permissionSetReference
         />
         <assemblyRequest
            name
            permissionSetReference
         />
      </applicationRequestMinimum>
      <requestedPrivileges>
         <requestedExecutionLevel
            level
            uiAccess
         />
      </requestedPrivileges>
   </security>
</trustInfo>
```

### Dependency & DependentAssembly & DependentOS

Type: Any

XPath:

```
/assembly/dependency
/assembly/dependency/dependentAssembly
/assembly/dependency/dependentAssembly/assemblyIdentity
/assembly/dependency/dependentAssembly/hash
/assembly/dependency/dependentAssembly/hash/DigestMethod
/assembly/dependency/dependentAssembly/hash/DigestValue/pcdata
/assembly/dependency/dependentAssembly/hash/Transforms/Transform
/assembly/dependency/dependentOS
/assembly/dependency/dependentOS/osVersionInfo/os
```

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <assemblyIdentity name="Microsoft-Windows-SystemSettings-SettingsHandlers-Gpu" version="10.0.22621.2070" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
  <dependency discoverable="no" resourceType="Resources">
    <dependentAssembly>
      <assemblyIdentity name="Microsoft-Windows-SystemSettings-SettingsHandlers-Gpu.Resources" version="10.0.22621.2070" processorArchitecture="amd64" language="*" buildType="release" publicKeyToken="31bf3856ad364e35" />
    </dependentAssembly>
  </dependency>
</assembly>
```

The instance of `dependentOS` is from [ClickOnce application manifest](https://learn.microsoft.com/en-us/visualstudio/deployment/clickonce-application-manifest).

```xml
<assembly>
  <dependency>
    <dependentOS>
      <osVersionInfo>
        <os majorVersion="4" minorVersion="10" buildNumber="0" servicePackMajor="0" />
      </osVersionInfo>
    </dependentOS>
  </dependency>
</assembly>
```

### Deployment & DeploymentProvider & Subscription

Type: Component

XPath:

```
/assembly/deployment
/assembly/deployment/deploymentProvider
/assembly/deployment/subscription/update/expiration
```

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <assemblyIdentity name="Microsoft-Windows-SearchEngine-Client-Package-shell-Deployment" version="10.0.22621.2070" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
  <deployment xmlns="urn:schemas-microsoft-com:asm.v3" />
  <dependency discoverable="yes">
    <dependentAssembly dependencyType="install">
      <assemblyIdentity name="Desktop_Shell-Search-SrchAdmin" version="7.0.22621.2070" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
    </dependentAssembly>
  </dependency>
  <!-- omitted -->
</assembly>
```

An example found on [ClickOnce deployment docs](https://learn.microsoft.com/en-us/visualstudio/deployment/deployment-element-clickonce-deployment).

```xml
<deployment
   install
   minimumRequiredVersion
   mapFileExtensions
   disallowUrlActivation
   trustUrlParameters
>
   <subscription>
         <update>
            <beforeApplicationStartup/>
            <expiration
               maximumAge
               unit
            />
         </update>
   </subscription>
   <deploymentProvider
      codebase
   />
</deployment>
```

### DigestValue

Refer to section `Hash`.

### Directories & Directory & DirectorySD

Type: Component

XPath:

```
/assembly/directories/directory
/assembly/directories/directory/securityDescriptor
/assembly/directories/directory/systemProtection
```

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved." xmlns:prj="http://www.microsoft.com/DRM/XrML2/SL/Tools/APT/ProjectConfig/1.0">
  <assemblyIdentity name="Microsoft-Windows-Security-SPP-Component-SKU-ProfessionalSingleLanguage-License" version="10.0.22621.1635" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
  <directories>
    <directory destinationPath="$(runtime.system32)\spp\tokens\skus\ProfessionalSingleLanguage" owner="true">
      <securityDescriptor name="WRP_PARENT_DIR_DEFAULT_SDDL" />
      <systemProtection behavior="notProtected" />
    </directory>
  </directories>
</assembly>
```

### EVDAI

TODO: Unknown.

### EdgeAI

TODO: Unknown.

### Elements

TODO: Unknown.

### EnableRpcAI

TODO: Unknown.

### EntryPoint

Type: Application

XPath: `/assembly/entryPoint`

Hint: Documented. This is for ClickOnce.

```xml
<entryPoint
   name
>
    <assemblyIdentity
        name
        version
        processorArchitecture
        language
    />
    <commandLine
        file
        parameters
    />
    <customHostRequired />
    <customUX />
</entryPoint>
```

### Events

TODO: Unknown.

### Expiration

TODO: Unknown.

### FailureActions

Type: Application

XPath: `/assembly/memberships/categoryMembership/categoryInstance/serviceData/failureActions`

This is for service boot failure action: retry behaviors.

Refer to `Actions & Action` section.

### FeatureSettingsOverride

TODO: Unknown.

### File (Component)

Type: Component

XPath:

```
/assembly/file
/assembly/file/comClass
/assembly/file/comClass/progid/pcdata
/assembly/file/comInterfaceProxyStub
/assembly/file/gac
/assembly/file/hash
/assembly/file/hash/DigestMethod
/assembly/file/hash/Transforms
/assembly/file/ngen
/assembly/file/securityDescriptor
/assembly/file/signatureInfo/signatureDescriptor
/assembly/file/typelib
/assembly/file/windowClass
/assembly/file/windowClass/pcdata
```

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <assemblyIdentity name="Microsoft-Windows-StartMenuExperienceHost.AppxSetup" version="10.0.22621.1928" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
  <file name="AppxManifest.xml" destinationPath="$(runtime.windows)\SystemApps\Microsoft.Windows.StartMenuExperienceHost_cw5n1h2txyewy\" sourceName="AppxManifest.xml" importPath="$(build.nttree)\StartMenuExperienceHost\" sourcePath=".\">
    <securityDescriptor name="WRP_FILE_DEFAULT_SDDL" />
    <asmv2:hash xmlns:asmv2="urn:schemas-microsoft-com:asm.v2" xmlns:dsig="http://www.w3.org/2000/09/xmldsig#">
      <dsig:Transforms>
        <dsig:Transform Algorithm="urn:schemas-microsoft-com:HashTransforms.Identity" />
      </dsig:Transforms>
      <dsig:DigestMethod Algorithm="http://www.w3.org/2000/09/xmldsig#sha256" />
      <dsig:DigestValue>36xH6om0SpUM0JDkiKpHoYCAtLaomEiOPS64iG+MvGk=</dsig:DigestValue>
    </asmv2:hash>
  </file>
</assembly>
```

### FileAssociation

Type: Application

XPath: `/assembly/fileAssociation`

This is for ClickOnce applications.

```xml
<assembly>
  <fileAssociation xmlns="urn:schemas-microsoft-com:clickonce.v1" extension=".text" description="Text  Document (ClickOnce)" progid="Text.Document" defaultIcon="text.ico" />
</assembly>
```

### Filter

Type: Unknown

### FirewallGroupActivation

Type: Unknown

### FirewallRule

Type: Unknown

### ForwardDiffInfo

Type: Unknown

### FveUpdateAI

Type: Unknown

### Gac

Type: Unknown

### GenericCommand

Type: Unknown

### GenericCommands

Type: Unknown

### GroupTrustee

Type: Unknown

Refer to `Capabilities` section.

(Win32 Access Control Trustees)[https://learn.microsoft.com/en-us/windows/win32/secauthz/trustees]

attribute of groupTrustee

```
v45 = "privileges";
v49 = "members";
v53 = "capabilities";
```

### HTTPAI

Type: Unknown

### Hash & HashTransforms & HashDigestMethod & HashDigestValue

Type: Component

XPath:

```
assembly/dependency/dependentAssembly/hash
assembly/dependency/dependentAssembly/hash/DigestMethod
assembly/dependency/dependentAssembly/hash/DigestValue/pcdata
assembly/dependency/dependentAssembly/hash/Transforms/Transform
```



### HotPatchAI

Type: Unknown

### IEFileInstallAI

Type: Unknown

### IPermission

Type: Unknown

### Id

Type: Unknown

### IisSetup

Type: Unknown

### Imaging

Type: Unknown

### ImpactType

Type: Unknown

### InstallerAssembly

Type: Package

XPath: `/assembly/package/installerAssembly`

The assembly identity of servicing stack.

Is it a version requirement or record? I prefer the latter, because the version of servicing stack is always `6.0.0.0` (seemingly same as the original NT version).

```xml
<?xml version="1.0" encoding="utf-8"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" description="" displayName="default" company="Microsoft Corporation" copyright="Microsoft Corporation" supportInformation="https://support.microsoft.com/help/5030310" creationTimeStamp="2023-09-12T17:06:32Z" lastUpdateTimeStamp="2023-09-12T17:06:32Z">
  <assemblyIdentity name="microsoft-windows-languagefeatures-handwriting-zh-cn-package-Wrapper" version="10.0.22621.2359" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" />
  <package identifier="KB5030310" releaseType="Update" restart="possible">
    <installerAssembly name="Microsoft-Windows-ServicingStack" version="6.0.0.0" language="neutral" processorArchitecture="amd64" versionScope="nonSxS" publicKeyToken="31bf3856ad364e35" />
  </package>
</assembly>
```

### Instrumentation

Type: Component

XPath: `/assembly/instrumentation`

This is a embeded Windows Event Log [Instrumentation Manifest](https://learn.microsoft.com/en-us/windows/win32/wes/writing-an-instrumentation-manifest).

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <assemblyIdentity name="Microsoft-Windows-MediaFoundation-FrameServer" version="10.0.22621.1778" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
  <instrumentation xmlns:win="http://manifests.microsoft.com/win/2004/08/windows/events">
    <events xmlns="http://schemas.microsoft.com/win/2004/08/events">
      <provider guid="{9E22A3ED-7B32-4B99-B6C2-21DD6ACE01E1}" message="$(string.EventProviderName)" messageFileName="%SystemRoot%\system32\FrameServer.dll" name="Microsoft-Windows-MF-FrameServer" resourceFileName="%SystemRoot%\system32\FrameServer.dll" symbol="Microsoft_Windows_MF_FrameServer">
        <channels>
          <channel chid="FrameServer" isolation="Application" message="$(string.FrameServer.ChannelMessage)" name="MF_MediaFoundationFrameServer" symbol="MFFrameServer" type="Analytic" />
        </channels>
      </provider>
      <cmi />
    </events>
  </instrumentation>
</assembly>
```

### Link

Type: Unknown

### Lodctr

Type: Unknown

### LodctrDat

Type: Unknown

### ManifestFileSD

Type: Unknown

### ManifestRegKeySD

Type: Unknown

### ManifestVersionType

Type: Unknown

### Members

Type: Unknown

### Memberships

Type: Unknown

### Metadata

Type: Unknown

### Migration

Type: Unknown

### ModeMemberships

Type: Unknown

### Mof

Type: Unknown

### Msdtc

Type: Unknown

### MsdtcActionType

Type: Unknown

### Msix

Type: Unknown

### MsmqAdIntegrationOnlineInstall

Type: Unknown

### MsmqDownlevelClientOnlineInstall

Type: Unknown

### MsmqHttpOnlineInstall

Type: Unknown

### MsmqTriggersOnlineInstall

Type: Unknown

### MsmqWorkgroupOnlineInstall

Type: Unknown

### NetworkComponents

Type: Unknown

### Ngen

Type: Unknown

### NoInheritable

Type: Component

XPath: `/assembly/noInheritable`

A flag element.

### NullDiffInfo

Type: Unknown

### Os

Type: Unknown

### OsVersionInfo

Type: Unknown

### Overridable

Type: Unknown

### Package

Type: Package

XPath: `/assembly/package`

The element list of package:

```
parent
update
applicable
detectUpdate
selectable
detectNone
component
package
driver
installerAssembly
packageExtended
```

### PackageExtended

Type Package

XPath: `/assembly/package/packageExtended`

Records extra information like the size of the package.

The following size attribute is in bytes.

```xml
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" description="Windows PowerShell Integrated Scripting Environment (ISE) is a graphical editor for PowerShell scripts with syntax-coloring, tab completion, and visual debugging." displayName="Windows PowerShell ISE" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved" supportInformation="http://support.microsoft.com/?kbid=777777">
  <assemblyIdentity name="Microsoft-Windows-PowerShell-ISE-FOD-Package" version="10.0.22621.1" processorArchitecture="amd64" language="zh-CN" buildType="release" publicKeyToken="31bf3856ad364e35" />
  <package identifier="Microsoft-Windows-PowerShell-ISE-FOD-zh-CN" releaseType="OnDemand Pack">
    <packageExtended packageSize="868521" />
  </package>
</assembly>
```

### Param

Type: Unknown

### Path

Type: Unknown

### Pbr

Type: Unknown

### PeerDistAI

Type: Unknown

### PermissionSet

Type: Unknown

### Plugin

Type: Unknown

### PluginInformation

Type: Unknown

### Privileges

Type: Unknown

### Progid

Type: Unknown

### ProviderOrder

Type: Unknown

### RDWebAI

Type: Unknown

### RegistryKeys & RegistryKey & RegistryValue

Type: Component

XPath: `/assembly/registryKeys/registryKey/registryValue`

Let's see the installation of COM dll `cmiv2.dll`.

```xml
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <assemblyIdentity name="Microsoft-Windows-CMI" version="10.0.22621.1" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
  <file name="cmiv2.dll" destinationPath="$(runtime.system32)\AdvancedInstallers\" sourceName="cmiv2.dll" importPath="$(build.nttree)\cmi\" sourcePath=".\">
    <!-- omitted -->
  </file>
  <registryKeys>
    <registryKey keyName="HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Windows\">
      <registryValue name="ComponentizedBuild" valueType="REG_DWORD" value="0x00000001" />
    </registryKey>
    <registryKey keyName="HKEY_CLASSES_ROOT\Interface\{729B9356-1627-4E0D-88E3-28C664F3BEB8}\">
      <registryValue name="" valueType="REG_SZ" value="IRedirectInformation" />
      <securityDescriptor name="WRP_REGKEY_DEFAULT_SDDL" />
    </registryKey>
    <registryKey keyName="HKEY_CLASSES_ROOT\Interface\{6B8E6B8E-7F56-11D7-B569-505054503030}\ProxyStubClsid\">
      <registryValue name="" valueType="REG_SZ" value="{00020424-0000-0000-C000-000000000046}" />
    </registryKey>
    <!-- omitted -->
    <registryKey keyName="HKEY_CLASSES_ROOT\Interface\{F3411F40-70A6-11D7-BA56-505054503030}\ProxyStubClsid32\">
      <registryValue name="" valueType="REG_SZ" value="{00020424-0000-0000-C000-000000000046}" />
    </registryKey>
    <registryKey keyName="HKEY_CLASSES_ROOT\Interface\{F31091F9-B0A8-11D6-B6FC-005056C00008}\">
      <registryValue name="" valueType="REG_SZ" value="IDependency" />
      <securityDescriptor name="WRP_REGKEY_DEFAULT_SDDL" />
    </registryKey>
    <registryKey keyName="HKEY_CLASSES_ROOT\INTERFACE\{6B8E6B97-7F56-11D7-B569-505054503030}">
      <securityDescriptor name="WRP_REGKEY_DEFAULT_SDDL" />
    </registryKey>
  </registryKeys>
</assembly>
```

### RequestedExecutionLevel & RequestedExecutionLevelType & RequestedPrivileges

Type: Application

XPath: `/assembly/trustInfo/security/requestedPrivileges/requestedExecutionLevel`

Hint: Documented. It's a well known part of isolation manifest.

The priviledges part of UFCase itself:

```xml
<assembly manifestVersion="1.0" xmlns="urn:schemas-microsoft-com:asm.v1">
  <assemblyIdentity version="1.5.1.1" name="UFCase.app"/>

  <trustInfo xmlns="urn:schemas-microsoft-com:asm.v2">
    <security>
      <requestedPrivileges xmlns="urn:schemas-microsoft-com:asm.v3">
        <requestedExecutionLevel level="requireAdministrator" uiAccess="false" />
      </requestedPrivileges>
    </security>
  </trustInfo>
</assembly>
```

### Rescache

Type: Component.

XPath: `/assembly/rescache` `/assembly/file/resfile`

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <assemblyIdentity name="Microsoft-Windows-FileExplorer-Common.Resources" version="10.0.22621.608" processorArchitecture="amd64" language="zh-CN" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
  <file name="Windows.FileExplorer.Common.dll.mui" destinationPath="$(runtime.system32)\zh-CN\" sourceName="Windows.FileExplorer.Common.dll.mui" importPath="$(build.nttree)\loc\zh-cn\" sourcePath=".\">
    <resfile xmlns="urn:schemas-microsoft-com:rescache.v1" affinity="boot" cached="true" sequence="12" />
    <securityDescriptor name="WRP_FILE_DEFAULT_SDDL" />
    <asmv2:hash xmlns:asmv2="urn:schemas-microsoft-com:asm.v2" xmlns:dsig="http://www.w3.org/2000/09/xmldsig#">
      <dsig:Transforms>
        <dsig:Transform Algorithm="urn:schemas-microsoft-com:HashTransforms.Identity" />
      </dsig:Transforms>
      <dsig:DigestMethod Algorithm="http://www.w3.org/2000/09/xmldsig#sha256" />
      <dsig:DigestValue>ukDrdme6I5WprDKvw9h29/wzvVm8IBalW6uX6GlPa6w=</dsig:DigestValue>
    </asmv2:hash>
  </file>
  <rescache xmlns="urn:schemas-microsoft-com:rescache.v1" />
</assembly>
```

### Restriction

Type: Unknown

### ReverseDiffInfo

Type: Unknown

### Schema & SchemaElement

Type: Component

XPath: under `/assembly/configuration/configurationSchema/schema`

Refer to the `Configuration & ConfigurationSchema` section.

### SecureBoot

Type: Unknown

### SecureBootUpdateType

Type: Unknown

### Security & SecurityDescriptor & ...

Refer to the `AccessControl` section.

### SecurityTemplate

Type: Unknown

### Sequence

Type: Unknown

### ServiceData

Type: Component

XPath: `/assembly/memberships/categoryMembership/categoryInstance/serviceData`

System critical: `start="boot"`

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <assemblyIdentity name="Microsoft-Windows-CNG" version="10.0.22621.1992" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
  <memberships>
    <categoryMembership>
      <id name="Microsoft.Windows.Categories.Services" version="10.0.22621.1992" publicKeyToken="31bf3856ad364e35" typeName="Service" />
      <categoryInstance subcategory="CNG">
        <serviceData name="CNG" errorControl="critical" start="boot" type="kernelDriver" group="Core" imagePath="System32\Drivers\cng.sys" tag="4" />
      </categoryInstance>
    </categoryMembership>
  </memberships>
</assembly>
```

Ordinary service: trigger start and failure retry.

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <assemblyIdentity name="Microsoft-Windows-Messaging-MessagingService" version="10.0.22621.1635" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
  <memberships>
    <categoryMembership>
      <id name="Microsoft.Windows.Categories.Services" version="10.0.22621.1635" publicKeyToken="31bf3856ad364e35" typeName="Service" />
      <categoryInstance>
        <serviceData name="MessagingService" displayName="@%SystemRoot%\system32\MessagingService.dll,-100" errorControl="ignore" start="demand" type="win32UserShareProcess" description="@%SystemRoot%\system32\MessagingService.dll,-101" imagePath="%SystemRoot%\system32\svchost.exe -k UnistackSvcGroup" objectName="LocalSystem" requiredPrivileges="SeChangeNotifyPrivilege,SeCreateGlobalPrivilege" sidType="unrestricted">
          <serviceTrigger action="start" subtype="WNF_STATE_CHANGE" type="WnfStateEvent">
            <triggerData type="binary" value="7518BCA33E039513" />
          </serviceTrigger>
          <failureActions resetPeriod="86400">
            <actions>
              <action delay="10000" type="restartService" />
              <action delay="10000" type="restartService" />
              <action delay="10000" type="restartService" />
              <action delay="10000" type="none" />
            </actions>
          </failureActions>
        </serviceData>
      </categoryInstance>
    </categoryMembership>
  </memberships>
</assembly>
```

### ServiceErrorControlType

Type: Unknown

### ServiceGroup

Type: Component

XPath: `/assembly/memberships/categoryMembership/categoryInstance/serviceGroup`

Represents a defined svchost.exe that can host many services in one single process.

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <assemblyIdentity name="Microsoft-Windows-Messaging-MessagingService" version="10.0.22621.1635" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
  <memberships>
    <categoryMembership>
      <id name="Microsoft.Windows.Categories" version="1.0.0.0" publicKeyToken="365143bb27e7ac8b" typeName="SvcHost" />
      <categoryInstance subcategory="UnistackSvcGroup">
        <serviceGroup position="last" serviceName="MessagingService" />
      </categoryInstance>
    </categoryMembership>
  </memberships>
</assembly>
```

The example service group contains the following services on my machine:

```
OneSyncSvc_28e87f, 同步主机_28e87f, C:\Windows\System32\APHostService.dll
PimIndexMaintenanceSvc_28e87f, Contact Data_28e87f, C:\Windows\System32\PimIndexMaintenance.dll
UnistoreSvc_28e87f, User Data Storage_28e87f, C:\Windows\System32\unistore.dll
UserDataSvc_28e87f, User Data Access_28e87f, C:\Windows\System32\userdataservice.dll
```

### ServiceLaunchProtectedType

Type: Component

XPath: under `/assembly/memberships/categoryMembership/categoryInstance/serviceData`

Refer to `ServiceData` section.

### ServiceModelReg

Type: Component

XPath: under `/assembly/memberships/categoryMembership/categoryInstance/serviceData`

Refer to `ServiceData` section.

### ServiceSidType

Type: Component

XPath: under `/assembly/memberships/categoryMembership/categoryInstance/serviceData`

Refer to `ServiceData` section.

### ServiceStartType

Type: Component

XPath: under `/assembly/memberships/categoryMembership/categoryInstance/serviceData`

Refer to `ServiceData` section.

### ServiceTrigger

Type: Component

XPath: under `/assembly/memberships/categoryMembership/categoryInstance/serviceData`

Refer to `ServiceData` section.

### ServiceTriggerType

Type: Component

XPath: under `/assembly/memberships/categoryMembership/categoryInstance/serviceData`

Refer to `ServiceData` section.

### SetIEInstalledDateAI

Type: Unknown

### SetupIppAI

Type: Unknown

### SetupLprAI

Type: Unknown

### SetupMpdwAI

Type: Unknown

### SetupMxdwAI

Type: Unknown

### SetupWfsAI

Type: Unknown

### ShortCut

Type: Unknown

### SimpleType

Type: Component

XPath: under `/assembly/configuration/configurationSchema`

This is a setting type of SMI, which denoting that the element is a scalar.

Refer to [WcmSettingType enumeration (wcmconfig.h)](https://learn.microsoft.com/en-us/windows/win32/api/wcmconfig/ne-wcmconfig-wcmsettingtype) and [WcmDataType enumeration (wcmconfig.h)](https://learn.microsoft.com/en-us/windows/win32/api/wcmconfig/ne-wcmconfig-wcmdatatype).

TODO: Complete the XML instance.

### SppInstaller

Type: Component

XPath: `/assembly/sppInstaller`

This is a flag element.

TODO: Unkown.

### StartAfterInstallType

Type: Unknown

### Subscription

Type: Component

XPath: `/assembly/deployment/subscription`

Refer to the `Deployment` section.

### SysprepInformation & SysprepModule & SysprepProvider & SysprepStageType

Type: Component

XPath: `/assembly/imaging/sysprepInformation`

```xml
<assembly>
  <imaging>
    <sysprepInformation>
      <sysprepProvider stage="cleanup">
        <sysprepOrder order="0x0900" />
        <sysprepModule methodName="Sysprep_Cleanup_Shell" moduleName="$(runtime.system32)\shsetup.dll" />
      </sysprepProvider>
      <sysprepProvider stage="generalize">
        <sysprepOrder order="0x1000" />
        <sysprepModule methodName="Sysprep_Generalize_Shell" moduleName="$(runtime.system32)\shsetup.dll" />
      </sysprepProvider>
    </sysprepInformation>
  </imaging>
</assembly>
```

Including extra `fileActions` and `registryActions`:

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" description="d__os_obj_amd64fre_temp_0a21e64d1a11fcc43088299e422825b2_z9j6llmdtk_microsoft-windows-management-service-windowsruntime.man.temp1.missingResource.description" displayName="d__os_obj_amd64fre_temp_0a21e64d1a11fcc43088299e422825b2_z9j6llmdtk_microsoft-windows-management-service-windowsruntime.man.temp1.missingResource.displayName" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <assemblyIdentity name="Microsoft-Windows-Management-Service-WinRT" version="10.0.22621.1" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
  <imaging>
    <sysprepInformation>
      <sysprepProvider stage="generalize">
        <sysprepOrder order="0x3d00" />
        <fileActions>
          <deleteDirectory path="$(runtime.windows)\ServiceState\wmansvc" />
        </fileActions>
        <registryActions>
          <deleteKey path="HKEY_LOCAL_MACHINE\Software\Microsoft\Provisioning\AutopilotPolicy" />
          <deleteKey path="HKEY_LOCAL_MACHINE\Software\Microsoft\Provisioning\Diagnostics\Autopilot" />
          <deleteValue name="41871D20A3BC1475" path="HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Notifications\Data" />
        </registryActions>
      </sysprepProvider>
    </sysprepInformation>
  </imaging>
</assembly>
```

TODO: Find out `SysprepStageType`.

### TaskScheduler & Task

Type: Component

XPath: `/assembly/taskScheduler`

A embeded [Task Scheduler Schema](https://learn.microsoft.com/en-us/windows/win32/taskschd/task-scheduler-schema).

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" description="d__os_obj_amd64fre_temp_0a21e64d1a11fcc43088299e422825b2_z9j6llmdtk_microsoft-windows-management-service-windowsruntime.man.temp1.missingResource.description" displayName="d__os_obj_amd64fre_temp_0a21e64d1a11fcc43088299e422825b2_z9j6llmdtk_microsoft-windows-management-service-windowsruntime.man.temp1.missingResource.displayName" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <assemblyIdentity name="Microsoft-Windows-Management-Service-WinRT" version="10.0.22621.1" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
  <taskScheduler>
    <Task xmlns="http://schemas.microsoft.com/windows/2004/02/mit/task">
      <RegistrationInfo>
        <URI>\Microsoft\Windows\Management\Autopilot\DetectHardwareChange</URI>
        <Author>$(@%SystemRoot%\system32\Autopilot.dll,-600)</Author>
        <Source>$(@%SystemRoot%\system32\Autopilot.dll,-601)</Source>
        <Description>$(@%SystemRoot%\system32\Autopilot.dll,-602)</Description>
      </RegistrationInfo>
      <Principals>
        <Principal id="LocalSystem">
          <UserId>S-1-5-18</UserId>
          <RunLevel>HighestAvailable</RunLevel>
        </Principal>
      </Principals>
      <Triggers>
        <WnfStateChangeTrigger>
          <StateName>7534bca3201d8741</StateName>
        </WnfStateChangeTrigger>
        <WnfStateChangeTrigger>
          <StateName>7540bca3201d8741</StateName>
        </WnfStateChangeTrigger>
      </Triggers>
      <Settings>
        <Enabled>false</Enabled>
        <UseUnifiedSchedulingEngine>true</UseUnifiedSchedulingEngine>
        <AllowStartOnDemand>true</AllowStartOnDemand>
        <MultipleInstancesPolicy>IgnoreNew</MultipleInstancesPolicy>
        <DisallowStartIfOnBatteries>false</DisallowStartIfOnBatteries>
        <StopIfGoingOnBatteries>false</StopIfGoingOnBatteries>
        <Hidden>false</Hidden>
        <RunOnlyIfNetworkAvailable>false</RunOnlyIfNetworkAvailable>
      </Settings>
      <Actions Context="LocalSystem">
        <ComHandler>
          <ClassId>{62B2DD2C-F129-42EE-BF59-55D3FD21C215}</ClassId>
          <Data>DetectHardwareChange</Data>
        </ComHandler>
      </Actions>
    </Task>
    <Task xmlns="http://schemas.microsoft.com/windows/2004/02/mit/task">
      <RegistrationInfo>
        <URI>\Microsoft\Windows\Management\Autopilot\RemediateHardwareChange</URI>
        <Author>$(@%SystemRoot%\system32\Autopilot.dll,-600)</Author>
        <Source>$(@%SystemRoot%\system32\Autopilot.dll,-601)</Source>
        <Description>$(@%SystemRoot%\system32\Autopilot.dll,-603)</Description>
      </RegistrationInfo>
      <Principals>
        <Principal id="LocalSystem">
          <UserId>S-1-5-18</UserId>
          <RunLevel>HighestAvailable</RunLevel>
        </Principal>
      </Principals>
      <Triggers>
        <BootTrigger>
          <Enabled>true</Enabled>
          <Delay>PT1M</Delay>
        </BootTrigger>
      </Triggers>
      <Settings>
        <Enabled>false</Enabled>
        <UseUnifiedSchedulingEngine>true</UseUnifiedSchedulingEngine>
        <AllowStartOnDemand>true</AllowStartOnDemand>
        <MultipleInstancesPolicy>IgnoreNew</MultipleInstancesPolicy>
        <DisallowStartIfOnBatteries>false</DisallowStartIfOnBatteries>
        <StopIfGoingOnBatteries>false</StopIfGoingOnBatteries>
        <Hidden>false</Hidden>
        <RunOnlyIfNetworkAvailable>true</RunOnlyIfNetworkAvailable>
      </Settings>
      <Actions Context="LocalSystem">
        <ComHandler>
          <ClassId>{62B2DD2C-F129-42EE-BF59-55D3FD21C215}</ClassId>
          <Data>RemediateHardwareChange</Data>
        </ComHandler>
      </Actions>
    </Task>
  </taskScheduler>
</assembly>
```

### ThreadingModel

Refer to WinRT `ActivatableClass` section.

### TimeUnitType

Type: Unknown

### TimezoneAI

Type: Unknown

### TimezoneresourceAI

Type: Unknown

### TransformInvoke

Type: Unknown

### Transforms

Type: Unknown

### TriggerData

Type: Component

XPath: `/assembly/memberships/categoryMembership/categoryInstance/serviceTrigger/triggerData`

Refer to `ServiceData` section.

### TrustInfo

Type: Any

Contains a `security` element.

### Trustees

Type: Unknown

Contains `groupTrustee` elements

### TssDisAI

Type: Unknown

### Typelib

Type: Application

XPath: `/assembly/file/typelib`

Hint: Documented. For COM classes.

```xml
<assembly>
  <file name="sampleu.dll">
    <typelib tlbid="{44EC0535-400F-11D0-9DCD-00A0C90391D3}" version="1.0" helpdir=""/>
  </file>
</assembly>
```

### UnattendAction

Type: Unknown

### UnattendActions

Type: Unknown

### Update

Type: Package

XPath: `/assembly/package/update`

The `update` element can have **none** or **multiple** children of `component` `package` `driver` elements.

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <assemblyIdentity name="Microsoft-Windows-Security-SPP-Component-SKU-Professional-License-Package" version="10.0.22621.2359" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
  <package identifier="Microsoft-Windows-Security-SPP-Component-SKU-Professional-License-Package" releaseType="Feature Pack">
    <update name="Microsoft-Windows-Security-SPP-Component-SKU-Professional-License-Deployment">
      <component>
        <assemblyIdentity name="Microsoft-Windows-Security-SPP-Component-SKU-Professional-License-Deployment" version="10.0.22621.2359" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" />
      </component>
    </update>
  </package>
</assembly>
```

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <assemblyIdentity name="Microsoft-Windows-SearchEngine-Client-Package" version="10.0.22621.2359" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" />
  <package identifier="Microsoft-Windows-SearchEngine-Client" releaseType="Feature Pack" restart="required">
    <update name="SearchEngine-Client-Package" displayName="Windows Search" description="Provides content indexing, property caching, and search results for files, e-mail, and other content.">
      <selectable disposition="staged">
        <detectNone default="true" />
      </selectable>
      <package contained="false" integrate="hidden">
        <assemblyIdentity name="Microsoft-Windows-SearchEngine-Client-Package-onecoreuap-Package" version="10.0.22621.1635" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" />
      </package>
    </update>
  </package>
</assembly>
```

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v3" manifestVersion="1.0" description="Windows Ethernet Client Intel E1i68x64 Networking Driver" displayName="Intel E1i68x64 Ethernet Networking Driver" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved" supportInformation="http://support.microsoft.com/?kbid=777777">
  <assemblyIdentity name="Microsoft-Windows-Ethernet-Client-Intel-E1i68x64-FOD-Package" version="10.0.22621.2359" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" />
  <package identifier="KB777778" releaseType="OnDemand Pack">
    <update name="545cdcfc390ac209c3547e4d60abc02e" restart="required">
      <driver inf="net1ic64.inf" ranking="normal">
        <assemblyIdentity name="dual_net1ic64.inf" version="10.0.22621.1" processorArchitecture="amd64" language="neutral" buildType="release" publicKeyToken="31bf3856ad364e35" versionScope="nonSxS" type="dualModeDriver" />
      </driver>
    </update>
  </package>
</assembly>
```

### UpgradeAI

Type: Unknown

### UpgradeAINi

Type: Unknown

### VmHostAI

Type: Unknown

### WcpAIRebootAwareTestInstallerMarker

Type: Unknown

### WcpMidgroundInstallerTestMarker

Type: Unknown

### WcpTestInstaller2

Type: Unknown

### WcpTestInstallerMarker

Type: Unknown

### WcpTestInstallerOfflineOnce

Type: Unknown

### WcpTestInstallerOnlineOnly

Type: Unknown

### WindowClass

Type: Component

XPath: `/assembly/windowClass`

```xml
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0" copyright="Copyright (c) Microsoft Corporation. All Rights Reserved." xmlns:cmiv2="urn:schemas-microsoft-com:asm.v3" cmiv2:copyright="Copyright (c) Microsoft Corporation. All Rights Reserved.">
  <noInheritable />
  <assemblyIdentity name="Microsoft.Windows.Common-Controls" version="5.82.22621.608" processorArchitecture="amd64" publicKeyToken="6595b64144ccf1df" type="win32" />
  <file name="comctl32.dll" cmiv2:importPath="$(build.nttree)\" cmiv2:sourceName="">
    <windowClass versioned="no">ToolbarWindow32</windowClass>
    <windowClass versioned="no">ComboBoxEx32</windowClass>
    <windowClass versioned="no">msctls_trackbar32</windowClass>
    <windowClass versioned="no">msctls_updown32</windowClass>
    <windowClass versioned="no">msctls_progress32</windowClass>
    <windowClass versioned="no">msctls_hotkey32</windowClass>
    <windowClass versioned="no">msctls_statusbar32</windowClass>
    <windowClass versioned="no">SysHeader32</windowClass>
    <windowClass versioned="no">SysListView32</windowClass>
    <windowClass versioned="no">SysTreeView32</windowClass>
    <windowClass versioned="no">SysTabControl32</windowClass>
    <windowClass versioned="no">SysIPAddress32</windowClass>
    <windowClass versioned="no">SysPager</windowClass>
    <windowClass versioned="no">NativeFontCtl</windowClass>
    <windowClass versioned="no">Button</windowClass>
    <windowClass versioned="no">Static</windowClass>
    <windowClass versioned="no">Listbox</windowClass>
    <windowClass versioned="no">ScrollBar</windowClass>
    <windowClass versioned="no">tooltips_class32</windowClass>
    <windowClass versioned="no">ButtonListBox</windowClass>
    <windowClass versioned="no">SysAnimate32</windowClass>
    <windowClass versioned="no">SysMonthCal32</windowClass>
    <windowClass versioned="no">SysDateTimePick32</windowClass>
    <windowClass versioned="no">ReBarWindow32</windowClass>
    <windowClass versioned="no">Edit</windowClass>
    <windowClass versioned="no">Combobox</windowClass>
    <windowClass versioned="no">ComboLBox</windowClass>
    <signatureInfo xmlns="urn:schemas-microsoft-com:asm.v3">
      <signatureDescriptor PETrust="true" pageHash="true" />
    </signatureInfo>
    <asmv2:hash xmlns:asmv2="urn:schemas-microsoft-com:asm.v2" xmlns:dsig="http://www.w3.org/2000/09/xmldsig#">
      <dsig:Transforms>
        <dsig:Transform Algorithm="urn:schemas-microsoft-com:HashTransforms.Identity" />
      </dsig:Transforms>
      <dsig:DigestMethod Algorithm="http://www.w3.org/2000/09/xmldsig#sha256" />
      <dsig:DigestValue>w94NEpcKVF1j0ZnWZ5+bdY0gg0PwkxLxXk8olfiymUQ=</dsig:DigestValue>
    </asmv2:hash>
  </file>
</assembly>
```

### WinrtThreadingModel

Type: Unknown

### WinsockAppPermittedLspCategories

Type: Unknown

### WinsockNameSpaceOnlineInstall

Type: Unknown

### WinsockTransportOnlineInstall

Type: Unknown

# Appendix

### Macro expansion

This is from `%Windows_Kits%\10\Tools\bin\i386\pkggen.cfg.xml`

```xml
<?xml version="1.0" encoding="utf-8"?>
<Macros xmlns="urn:Microsoft.WindowsPhone/PackageSchema.v8.00">
<!--
    This file owned by BaseOS UNP and Security team. If you need to add
    or update the macro, please send code review to osseccr and unpcr.
-->
<!-- device side macros -->
    <!-- global macros for file path under system partition on device -->
    <Macro Id="runtime.root"                Value=""/>
    <Macro Id="runtime.windows"             Value="$(runtime.root)\windows"/>
    <Macro Id="runtime.system32"            Value="$(runtime.windows)\System32"/>
    <Macro Id="runtime.programFiles"        Value="$(runtime.root)\Program Files"/>
    <Macro Id="runtime.programData"         Value="$(runtime.root)\ProgramData"/>
    <Macro Id="runtime.services"            Value="$(runtime.windows)\system32"/>
    <Macro Id="runtime.drivers"             Value="$(runtime.system32)\drivers"/>
    <Macro Id="runtime.apps"                Value="$(runtime.root)\Programs"/>
    <Macro Id="runtime.data"                Value="$(runtime.root)\Data"/>
    <Macro Id="runtime.shareddata"          Value="$(runtime.data)\SharedData"/>
    <Macro Id="runtime.commonfiles"         Value="$(runtime.apps)\CommonFiles"/>
    <Macro Id="runtime.shareddlls"          Value="$(runtime.commonfiles)\System"/>
    <Macro Id="runtime.etw"                 Value="$(runtime.data)\SystemData\ETW"/>
    <Macro Id="runtime.coldBootProvxmlMS"   Value="$(runtime.apps)\PhoneProvisioner\Microsoft"/>
    <Macro Id="runtime.coldBootProvxmlOEM"  Value="$(runtime.apps)\PhoneProvisioner_OEM\OEM"/>
    <Macro Id="runtime.updateProvxmlMS"     Value="$(runtime.windows)\Migrators\DuMigrationProvisionerMicrosoft\provxml"/>
    <Macro Id="runtime.updateProvxmlOEM"    Value="$(runtime.windows)\Migrators\DuMigrationProvisionerOEM\provxml"/>
    <Macro Id="runtime.appProvxmlMS"        Value="$(runtime.system32)\Provisioning\Microsoft"/>
    <Macro Id="runtime.appProvxmlTest"      Value="$(runtime.system32)\Provisioning\Test"/>
    <Macro Id="runtime.appProvxmlOEM"       Value="$(runtime.commonfiles)\Provisioning\OEM"/>
    <Macro Id="runtime.provisioning"        Value="$(runtime.programData)\Microsoft\Provisioning"/>

    <Macro Id="runtime.defaultSvcHost"          Value="$(env.system32)\svchost.exe"/>
    <Macro Id="runtime.clipAppLicenseInstall"   Value="$(runtime.programData)\Microsoft\Windows\ClipSVC\Install\Apps"/>

    <!-- global macros for file path on device using environment variables, can only be used in registry values with type REG_EXPAND_SZ -->
    <Macro Id="env.sysDrive"            Value="%SystemDrive%"/>
    <Macro Id="env.windows"             Value="%SystemRoot%"/>
    <Macro Id="env.system32"            Value="$(env.windows)\System32"/>
    <Macro Id="env.drivers"             Value="$(env.system32)\drivers"/>
    <Macro Id="env.services"            Value="$(env.system32)"/>

    <!-- global macros for file path under data partition on device -->
    <Macro Id="data.root"               Value=""/>
    <Macro Id="data.public"             Value="$(data.root)\Users\Public"/>
    <Macro Id="data.shared"             Value="$(data.root)\SharedData"/>
    <Macro Id="data.tempXaps"           Value="$(data.shared)\Provisioning\tempXaps"/>

    <!-- global macros for registry key paths -->
    <Macro Id="hklm.system"             Value="HKEY_LOCAL_MACHINE\SYSTEM"/>
    <Macro Id="hklm.software"           Value="HKEY_LOCAL_MACHINE\Software"/>
    <Macro Id="hklm.hardware"           Value="HKEY_LOCAL_MACHINE\Hardware"/>
    <Macro Id="hklm.sam"                Value="HKEY_LOCAL_MACHINE\SAM"/>
    <Macro Id="hklm.security"           Value="HKEY_LOCAL_MACHINE\Security"/>
    <Macro Id="hklm.bcd"                 Value="HKEY_LOCAL_MACHINE\BCD"/>
    <Macro Id="hklm.drivers"             Value="HKEY_LOCAL_MACHINE\Drivers"/>
    <Macro Id="hkuser.default"          Value="HKEY_USERS\.Default"/>
    <Macro Id="hkcu.root"               Value="HKEY_CURRENT_USER"/>
    <Macro Id="hkcr.root"               Value="$(hklm.software)\Classes"/>
    <Macro Id="hklm.svchost"            Value="$(hklm.software)\Microsoft\Windows NT\CurrentVersion\SvcHost"/>
    <Macro Id="hklm.policies"           Value="$(hklm.software)\Policies" />
    <Macro Id="hklm.microsoft"          Value="$(hklm.software)\Microsoft" />
    <Macro Id="hklm.windows"            Value="$(hklm.microsoft)\Windows" />
    <Macro Id="hklm.windowsnt"          Value="$(hklm.microsoft)\Windows NT\CurrentVersion" />
    <Macro Id="hklm.currentcontrolset"  Value="$(hklm.system)\ControlSet001" />
    <Macro Id="hklm.services"           Value="$(hklm.currentcontrolset)\services" />
    <Macro Id="hklm.control"            Value="$(hklm.currentcontrolset)\Control" />
    <Macro Id="hklm.autologger"         Value="$(hklm.control)\WMI\Autologger" />

    <Macro Id="hklm.enum"               Value="$(hklm.currentcontrolset)\Enum" />

    <!-- This one is going away soon, please use "hkcr.root" instead if you need to add some registry content under HKCR directly -->
    <Macro Id="hkcr.classes"            Value="$(hklm.software)\Classes"/>

    <!-- global macros for Appx framework packages and their versions. Used in app preinstall scenarios. -->
    <Macro Id="appxframework.Microsoft.VCLibs.110.00"                Value="11.0.51106.1" />
    <Macro Id="appxframework.Microsoft.VCLibs.120.00"                Value="12.0.20708.0" />
    <Macro Id="appxframework.Microsoft.VCLibs.120.00.Phone"          Value="12.0.30113.0" />
    <Macro Id="appxframework.Microsoft.Media.PlayReadyClient.2"      Value="2.10.2077.1" />

    <!-- global macros for DirectX feature level(9.3). Used in APPX install scenarios. -->
    <Macro Id="DirectX.MaxFeatureLevel"  Value="37632" />
    <Macro Id="DirectX.MinFeatureLevel"  Value="37632" />
    <!--
        Generic access rights
    -->
    <Macro Id="EMPTY_ACCESS" Value="" />
    <!-- 0x111FFFFF = STANDARD_RIGHTS_ALL | SPECIFIC_RIGHTS_ALL | ACCESS_SYSTEM_SECURITY | GENERIC_ALL -->
    <Macro Id="ALL_ACCESS" Value="0x111FFFFF" />
    <Macro Id="GENERIC_ALL" Value="GA" />
    <Macro Id="GENERIC_READ" Value="GR" />
    <Macro Id="GENERIC_EXECUTE" Value="GX" />
    <Macro Id="GENERIC_WRITE" Value="GW" />

    <!--
        For following object, generic access rights should be used.
        Generic Mapping table

        1) Event
        GENERIC_READ    = STANDARD_RIGHTS_READ | EVENT_QUERY_STATE
        GENERIC_WRITE   = STANDARD_RIGHTS_WRITE | EVENT_MODIFY_STATE
        GENERIC_EXECUTE = STANDARD_RIGHTS_EXECUTE | SYNCHRONIZE
        GENERIC_ALL     = EVENT_ALL_ACCESS

        2) ETW
        Generic permissions can't be used for ETW, please check
        the specific ETW access right macros below.

        3) Mutex
        GENERIC_READ    = STANDARD_RIGHTS_READ | MUTANT_QUERY_STATE
        GENERIC_WRITE   = STANDARD_RIGHTS_WRITE
        GENERIC_EXECUTE = STANDARD_RIGHTS_EXECUTE | SYNCHRONIZE
        GENERIC_ALL     = MUTANT_ALL_ACCESS

        4) Event
        GENERIC_READ    = STANDARD_RIGHTS_READ | EVENT_QUERY_STATE
        GENERIC_WRITE   = STANDARD_RIGHTS_WRITE | EVENT_MODIFY_STATE
        GENERIC_EXECUTE = STANDARD_RIGHTS_EXECUTE | SYNCHRONIZE
        GENERIC_ALL     = EVENT_ALL_ACCESS

        5) Timer
        GENERIC_READ    = STANDARD_RIGHTS_READ | TIMER_QUERY_STATE
        GENERIC_WRITE   = STANDARD_RIGHTS_WRITE | TIMER_MODIFY_STATE
        GENERIC_EXECUTE = STANDARD_RIGHTS_EXECUTE | SYNCHRONIZE
        GENERIC_ALL     = TIMER_ALL_ACCESS

        6) Semphore
        GENERIC_READ    = STANDARD_RIGHTS_READ | SEMAPHORE_QUERY_STATE
        GENERIC_WRITE   = STANDARD_RIGHTS_WRITE | SEMAPHORE_MODIFY_STATE
        GENERIC_EXECUTE = STANDARD_RIGHTS_EXECUTE | SYNCHRONIZE
        GENERIC_ALL     = SEMAPHORE_ALL_ACCESS

        7) WNF (Windows Notification Framework)
        GENERIC_READ    = SYNCHRONIZE | READ_CONTROL | WNF_STATE_SUBSCRIBE
        GENERIC_WRITE   = WNF_STATE_PUBLISH
        GENERIC_EXECUTE = STANDARD_RIGHTS_ALL
        GENERIC_ALL     = STANDARD_RIGHTS_ALL | WNF_STATE_SUBSCRIBE | WNF_STATE_PUBLISH

        8) Alpc Port
        GENERIC_READ    = READ_CONTROL | PORT_CONNECT
        GENERIC_WRITE   = DELETE | PORT_CONNECt
        GENERIC_EXECUTE = 0
        GENERIC_ALL     = PORT_ALL_ACCESS

        9) Job
        GENERIC_READ    = STANDARD_RIGHTS_READ | JOB_OBJECT_QUERY
        GENERIC_WRITE   = STANDARD_RIGHTS_WRITE | JOB_OBJECT_ASSIGN_PROCESS | JOB_OBJECT_SET_ATTRIBUTES | JOB_OBJECT_TERMINATE
        GENERIC_EXECUTE = STANDARD_RIGHTS_EXECUTE | SYNCHRONIZE
        GENERIC_ALL     = JOB_OBJECT_ALL_ACCESS

        10) NamedPipe

        11) RPC
    -->

    <!--
        Standard access rights
    -->
    <Macro Id="STANDARD_DELETE" Value="SD" />
    <Macro Id="STANDARD_RIGHTS_READ" Value="RC" />
    <Macro Id="STANDARD_RIGHTS_WRITE" Value="RC" />
    <Macro Id="STANDARD_RIGHTS_EXECUTE" Value="RC" />
    <Macro Id="STANDARD_READ_CONTROL" Value="RC" />
    <Macro Id="STANDARD_WRITE_DAC" Value="WD" />
    <Macro Id="STANDARD_WRITE_OWNER" Value="WO" />

    <!--
        File and Directory access rights
        http://msdn.microsoft.com/en-us/library/aa822867(VS.85).aspx
        #define FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)

        #define FILE_GENERIC_READ         (STANDARD_RIGHTS_READ     |\
                                           FILE_READ_DATA           |\
                                           FILE_READ_ATTRIBUTES     |\
                                           FILE_READ_EA             |\
                                           SYNCHRONIZE)


        #define FILE_GENERIC_WRITE        (STANDARD_RIGHTS_WRITE    |\
                                           FILE_WRITE_DATA          |\
                                           FILE_WRITE_ATTRIBUTES    |\
                                           FILE_WRITE_EA            |\
                                           FILE_APPEND_DATA         |\
                                           SYNCHRONIZE)


        #define FILE_GENERIC_EXECUTE      (STANDARD_RIGHTS_EXECUTE  |\
                                           FILE_READ_ATTRIBUTES     |\
                                           FILE_EXECUTE             |\
                                           SYNCHRONIZE)
    -->
    <Macro Id="FILE_ALL_ACCESS" Value="FA" />
    <Macro Id="FILE_GENERIC_READ" Value="FR" />
    <Macro Id="FILE_GENERIC_WRITE" Value="FW" />
    <Macro Id="FILE_GENERIC_EXECUTE" Value="FX" />
    <Macro Id="FILE_LIST_DIRECTORY" Value="CC" />
    <Macro Id="FILE_DELETE_CHILD" Value="DT" />

    <!--
        Registry access rights
        http://msdn.microsoft.com/en-us/library/ms724878%28v=VS.85%29.aspx
        #define KEY_READ                ((STANDARD_RIGHTS_READ       |\
                                          KEY_QUERY_VALUE            |\
                                          KEY_ENUMERATE_SUB_KEYS     |\
                                          KEY_NOTIFY)                 \
                                          &                           \
                                         (~SYNCHRONIZE))


        #define KEY_WRITE               ((STANDARD_RIGHTS_WRITE      |\
                                          KEY_SET_VALUE              |\
                                          KEY_CREATE_SUB_KEY)         \
                                          &                           \
                                         (~SYNCHRONIZE))

        #define KEY_EXECUTE             ((KEY_READ)                   \
                                          &                           \
                                         (~SYNCHRONIZE))

        #define KEY_ALL_ACCESS          ((STANDARD_RIGHTS_ALL        |\
                                          KEY_QUERY_VALUE            |\
                                          KEY_SET_VALUE              |\
                                          KEY_CREATE_SUB_KEY         |\
                                          KEY_ENUMERATE_SUB_KEYS     |\
                                          KEY_NOTIFY                 |\
                                          KEY_CREATE_LINK)            \
                                          &                           \
                                         (~SYNCHRONIZE))
    -->
    <Macro Id="KEY_ALL_ACCESS" Value="KA" />
    <Macro Id="KEY_READ" Value="KR" />
    <Macro Id="KEY_WRITE" Value="KW" />
    <Macro Id="KEY_EXECUTE" Value="KX" />

    <!--
        Service access rights
        http://msdn.microsoft.com/en-us/library/ms685981(VS.85).aspx
        SERVICE_CHANGE_CONFIG should not be used, it will cause
        elevation attack
    -->
    <Macro Id="SERVICE_ALL_ACCESS" Value="CCLCSWRPWPDTLOCR" />
    <Macro Id="SERVICE_QUERY_CONFIG" Value="CC" />
    <Macro Id="SERVICE_QUERY_STATUS" Value="LC" />
    <Macro Id="SERVICE_ENUMERATE_DEPENDENTS" Value="SW" />
    <Macro Id="SERVICE_START" Value="RP" />
    <Macro Id="SERVICE_STOP" Value="WP" />
    <Macro Id="SERVICE_PAUSE_CONTINUE" Value="DT" />
    <Macro Id="SERVICE_INTERROGATE" Value="LO" />
    <Macro Id="SERVICE_USER_DEFINED_CONTROL" Value="CR" />
    <!--
        Used only by PrivateResource in PolicyCompiler.
    -->
    <Macro Id="SERVICE_PRIVATE_RESOURCE_ACCESS" Value="CCLCSWRPLO" />

    <!--
        COM access rights
        http://msdn.microsoft.com/en-us/library/ms693364(VS.85).aspx
        COM_LOCAL_ACCESS = COM_RIGHTS_EXECUTE | COM_RIGHTS_EXECUTE_LOCAL
        COM_LOCAL_LAUNCH = COM_RIGHTS_EXECUTE | COM_RIGHTS_EXECUTE_LOCAL | COM_RIGHTS_ACTIVATE_LOCAL
    -->
    <Macro Id="COM_LOCAL_ACCESS" Value="CCDC" />
    <Macro Id="COM_LOCAL_LAUNCH" Value="CCDCSW" />

    <!--
        Device object access rights
    -->
    <Macro Id="DEVICE_ALL" Value="GA" />
    <Macro Id="DEVICE_READ" Value="GR" />
    <Macro Id="DEVICE_EXECUTE" Value="GX" />
    <Macro Id="DEVICE_WRITE" Value="GW" />

    <!--
        File Mapping access rights
        http://msdn.microsoft.com/en-us/library/aa366559(v=VS.85).aspx
    -->
    <Macro Id="FILE_MAP_QUERY" Value="CC" />
    <Macro Id="FILE_MAP_WRITE" Value="DC" />
    <Macro Id="FILE_MAP_READ" Value="LC" />
    <Macro Id="FILE_MAP_EXECUTE" Value="WP" />
    <!-- FILE_MAP_ALL_ACCESS Includes all access rights to a file mapping object except FILE_MAP_EXECUTE -->
    <Macro Id="FILE_MAP_ALL_ACCESS" Value="CCDCLCSWSDRCWDWO" />

    <!--
        ETW Access Permission
        http://msdn.microsoft.com/en-us/library/windows/desktop/aa363717(v=vs.85).aspx

        A GUID security descriptor contains the following specific rights:
            WMIGUID_QUERY                 0x0001                CC
            WMIGUID_SET                   0x0002                DC
            WMIGUID_NOTIFICATION          0x0004                LC
            WMIGUID_READ_DESCRIPTION      0x0008                SW
            WMIGUID_EXECUTE               0x0010                RP
            TRACELOG_CREATE_REALTIME      0x0020                WP
            TRACELOG_CREATE_ONDISK        0x0040                DT
            TRACELOG_GUID_ENABLE          0x0080                LO
            TRACELOG_ACCESS_KERNEL_LOGGER 0x0100 // unused
            TRACELOG_LOG_EVENT            0x0200
            TRACELOG_ACCESS_REALTIME      0x0400
            TRACELOG_REGISTER_GUIDS       0x0800

        ETW_QUERY_SESSION = STANDARD_RIGHTS_READ | WMIGUID_QUERY | WMIGUID_READ_DESCRIPTION | WMIGUID_NOTIFICATION

        ETW_CONTROL_SESSION = STANDARD_RIGHTS_WRITE | WMIGUID_SET | TRACELOG_CREATE_REALTIME | TRACELOG_CREATE_ONDISK | TRACELOG_GUID_ENABLE

        ETW_LOG_EVENT = STANDARD_RIGHTS_EXECUTE | WMIGUID_EXECUTE | TRACELOG_LOG_EVENT | TRACELOG_REGISTER_GUIDS

        ETWLOG_ALL = STANDARD_RIGHTS_READ | STANDARD_RIGHTS_WRITE | STANDARD_RIGHTS_EXECUTE | WMIGUID_QUERY | WMIGUID_READ_DESCRIPTION | WMIGUID_NOTIFICATION | WMIGUID_SET | TRACELOG_CREATE_REALTIME | TRACELOG_CREATE_ONDISK | TRACELOG_LOG_EVENT | WMIGUID_EXECUTE | TRACELOG_GUID_ENABLE | TRACELOG_ACCESS_REALTIME | TRACELOG_REGISTER_GUIDS

    -->
    <!-- Support ControlTrace() with EVENT_TRACE_CONTROL_QUERY, NtQuerySystemInformation() -->
    <Macro Id="ETW_QUERY_SESSION" Value="RCCCSWLC" />

    <!-- Support StartTrace(), ControlTrace() with EVENT_TRACE_CONTROL_STOP, EVENT_TRACE_CONTROL_FLUSH and EVENT_TRACE_CONTROL_UPDATE -->
    <Macro Id="ETW_CONTROL_SESSION" Value="RCDCWPDTLO" />

    <!--
        Log to sessions. Support NtTraceEvent()
        A session becomes secure when it is started with EVENT_TRACE_SECURE_MODE in LogFileMode. TRACELOG_LOG_EVENT is access right for
        logging into secure session.
        Since we cannot do authenticate providers using old logging APIs (because they use session handle directly),
        legacy ETW/WPP providers cannot log to secure sessions.
        Since the value is a hex code, it can't be used with other ETW access macro in Rights attribute in the same capability rule.
    -->
    <Macro Id="ETW_LOG_EVENT" Value="0x020A10" />

    <!--
        Full Access,
        Since the value is a hex code, it can't be used with other ETW access macro in Rights attribute in the same capability rule.
    -->
    <Macro Id="ETW_ALL" Value="0x120FFF" />

    <!--
        Transient object type macros
    -->
    <Macro Id="OBJECT_MUTEX" Value="Mutex" />
    <Macro Id="OBJECT_EVENT" Value="Event" />
    <Macro Id="OBJECT_SEMAPHORE" Value="Semaphore" />
    <Macro Id="OBJECT_WAITABLETIMER" Value="WaitableTimer" />
    <Macro Id="OBJECT_JOB" Value="JobObject" />
    <Macro Id="OBJECT_FILEMAPPING" Value="FileMapping" />
    <Macro Id="OBJECT_NAMEDPIPE" Value="NamedPipe" />
    <Macro Id="OBJECT_MAILSLOT" Value="MailSlot" />
    <Macro Id="OBJECT_ALPCPORT" Value="AlpcPort" />
    <Macro Id="OBJECT_RPC" Value="Rpc" />
    <Macro Id="OBJECT_WNF" Value="Wnf" />
    <Macro Id="OBJECT_PRIVATE" Value="Private" />
    <Macro Id="OBJECT_TEMPLATE" Value="Template" />

    <!--
        Service control access
    -->
    <Macro Id="SERVICE_CONFIG" Value="[ServiceConfig]" />
    <Macro Id="OBJECT_SERVICE_CONFIG" Value="Private" />
    <Macro Id="SERVICE_CONFIG_CHANGE_STARTUP" Value="0x00000001" />

    <!--
        Windows Capability
        http://msdn.microsoft.com/en-us/library/hh448474(v=VS.85).aspx
    -->
    <Macro Id="WINCAP_INTERNET_CLIENT" Value="S-1-15-3-1" />
    <Macro Id="WINCAP_INTERNET_CLIENT_SERVER" Value="S-1-15-3-2" />
    <Macro Id="WINCAP_PRIVATE_NETWORK_CLIENT_SERVER" Value="S-1-15-3-3" />
    <Macro Id="WINCAP_PICTURES_LIBRARY" Value="S-1-15-3-4" />
    <Macro Id="WINCAP_VIDEOS_LIBRARY" Value="S-1-15-3-5" />
    <Macro Id="WINCAP_MUSIC_LIBRARY" Value="S-1-15-3-6" />
    <Macro Id="WINCAP_DOCUMENTS_LIBRARY" Value="S-1-15-3-7" />
    <Macro Id="WINCAP_ENTERPRISE_AUTHENTICATION" Value="S-1-15-3-8" />
    <Macro Id="WINCAP_SHARED_USER_CERTIFICATES" Value="S-1-15-3-9" />
    <Macro Id="WINCAP_REMOVABLE_STORAGE" Value="S-1-15-3-10" />
    <Macro Id="WINCAP_APPOINTMENTS" Value="S-1-15-3-11"/>
    <Macro Id="WINCAP_CONTACTS" Value="S-1-15-3-12"/>
    <Macro Id="WINCAP_NETWORKING_PROXIMITY" Value="S-1-15-3-4214768333-1334025770-122408079-3919188833"/>
    <Macro Id="WINCAP_APPCONTAINER_PACKAGE_CERTIFICATES" Value="S-1-15-3-395236244-1315033739-1586777234-200431208"/>
    <Macro Id="WINCAP_LOCATION" Value="S-1-15-3-3215430884-1339816292-89257616-1145831019"/>
    <Macro Id="WINCAP_MICROPHONE" Value="S-1-15-3-787448254-1207972858-3558633622-1059886964"/>
    <Macro Id="WINCAP_CAMERA" Value="S-1-15-3-3845273463-1331427702-1186551195-1148109977"/>  
  
    <Macro Id="WINCAP_APPLICATION_VIEW_ACTIVATION" Value="S-1-15-3-1024-2898197306-3300330394-3003314763-2509405055-2905551251-1957103989-1590147722-3620397556"/>
    <Macro Id="WINCAP_ACCESSORY_MANAGER_UAP" Value="S-1-15-3-1024-1069651245-2375841711-1570187833-1826699927-1726783584-1420246439-936999711-2864509111"/>
    <Macro Id="WINCAP_CELLULAR_DEVICE_CONTROL" Value="S-1-15-3-1024-3523901360-1745872541-794127107-675934034-1867954868-1951917511-1111796624-2052600462"/>
    <Macro Id="WINCAP_CELLULAR_DEVICE_IDENTITY" Value="S-1-15-3-1024-11742800-2107441976-3443185924-4134956905-3840447964-3749968454-3843513199-670971053"/>
    <Macro Id="WINCAP_CELLULAR_MESSAGING" Value="S-1-15-3-1024-3659434007-2290108278-1125199667-3679670526-1293081662-2164323352-1777701501-2595986263"/>
    <Macro Id="WINCAP_CELLULAR_TELEPHONY" Value="S-1-15-3-1024-3865473686-2149625755-1853498847-3881918434-2635008397-546295353-2007576859-3570151403"/>
    <Macro Id="WINCAP_CELLULAR_ADMIN" Value="S-1-15-3-1024-967904557-2583589594-4037535010-1468047438-3991165506-1813039402-1264849695-2178032989"/>
    <Macro Id="WINCAP_CELLULAR_MODEMLOGGING" Value="S-1-15-3-1024-3229654978-3658809704-3046875103-3436347169-1607416195-2302426341-3817229838-2612905111"/>
    <Macro Id="WINCAP_CORTANA_SETTINGS" Value="S-1-15-3-1024-1216833578-114521899-3977640588-1343180512-2505059295-473916851-3379430393-3088591068"/>
    <Macro Id="WINCAP_DEVICE_UNLOCK" Value="S-1-15-3-1024-3090417596-1177152433-709977159-3759866339-3648116925-1194977332-3459169701-1652573254"/>
    <Macro Id="WINCAP_ENTERPRISE_DEVICE_LOCKDOWN" Value="S-1-15-3-1024-1720708008-676358685-3694961389-3536049837-28312851-1003502039-653286243-2922628565"/>
    <Macro Id="WINCAP_NETWORK_CONNECTION_MANAGER_PROVISIONING" Value="S-1-15-3-1024-1904668343-1122143141-2896894936-1757704438-2225457261-1832870532-4083204921-4111087458"/>
    <Macro Id="WINCAP_NETWORK_DATA_PLAN_PROVISIONING" Value="S-1-15-3-1024-4214965917-3375290950-3857009211-4120063080-3741332808-2868847822-1843154671-4148511555"/>
    <Macro Id="WINCAP_PACKAGE_MANAGEMENT" Value="S-1-15-3-1024-734518492-402359323-2580938124-1419864735-4212787651-2727913556-228323224-564805089"/>
    <Macro Id="WINCAP_PACKAGE_POLICY_SYSTEM" Value="S-1-15-3-1024-1572800732-1164253991-2733652370-1720403341-3570188209-547973490-1048710288-340345592"/>
    <Macro Id="WINCAP_USER_SIGNIN_SUPPORT" Value="S-1-15-3-1024-1730716382-2949791265-2036182297-688374192-553408039-4133924312-4201181712-267922143"/>
    <Macro Id="WINCAP_VISUALELEMENT_SYSTEM" Value="S-1-15-3-1024-3299255270-1847605585-2201808924-710406709-3613095291-873286183-3101090833-2655911836"/>
    <Macro Id="WINCAP_WINDOWS_HELLO_CREDENTIAL_ACCESS" Value="S-1-15-3-1024-1902118268-936929782-3474333872-803346623-1872623265-3899080591-2872335817-3963487957"/>
    <Macro Id="WINCAP_INPUT_INJECTION" Value="S-1-15-3-1024-918685303-2392273179-1242551144-2277013827-3453391213-358261840-2217007564-611397587"/>

</Macros>
```
