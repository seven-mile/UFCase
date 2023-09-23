# Basic analysis of `urn:schemas-microsoft-com:asm.v3`

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
