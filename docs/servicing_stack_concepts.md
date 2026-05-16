# Servicing Stack Concepts

This document explains the servicing concepts that UFCase exposes. It is written for Windows power users who already know Windows Update, DISM, the registry, and the filesystem, but want a clearer map of how those familiar surfaces connect to CBS, WinSxS, packages, components, and manifests.

Much of this area is undocumented. Treat the descriptions here as working notes derived from public behavior, observed manifests, and the internal APIs UFCase uses.

## From Windows Update to CBS

Windows Update is the delivery mechanism most users see. It downloads update metadata and payloads into places such as `SoftwareDistribution`, then the servicing stack decides what is applicable and how the image should change.

The update container format users usually encounter is `*.msu`. An MSU can contain CAB files recursively. Some CABs carry metadata, and others carry package payloads. Once the work reaches Component-Based Servicing (CBS), the central unit is usually a package.

You can see CBS packages with commands such as:

```powershell
Dism /Online /Get-Packages
```

A CBS package has an identity, install state, metadata, a manifest, and payload. UFCase reads package information through CBS APIs and shows package manifest data when the `.mum` file is available under:

```text
%WINDIR%\servicing\Packages
```

CBS also exposes optional features:

```powershell
Dism /Online /Get-Features
```

These features are different from Features on Demand / capabilities:

```powershell
Dism /Online /Get-Capabilities
```

In UFCase, optional features are modeled from the Foundation package and CBS update entries. Capabilities are related to servicing packages too, but they are not the same abstraction as optional features.

## Where Servicing State Lives

Servicing state is not stored in one database. It is spread across the filesystem, registry hives, and internal stores.

Important filesystem locations include:

```text
%WINDIR%\servicing\Packages
%WINDIR%\WinSxS
%WINDIR%\System32\config
%WINDIR%\system32\smi\store\Machine
```

Important registry locations include:

```text
HKLM\COMPONENTS
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Component Based Servicing
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\SideBySide
```

For online images, these are the live hives of the running system. For offline images, UFCase builds paths to the target image's registry hive files and opens them through the servicing stack's offline store support.

This is why a Windows image is more than a directory tree. A useful servicing view needs the package files, the WinSxS payload, and the registry-backed state that says which packages and components are staged, installed, superseded, or absent.

## Packages, Updates, and Features

A CBS package is a high-level servicing unit. Package identities commonly look like:

```text
Microsoft-Windows-...-Package~31bf3856ad364e35~amd64~~10.0.x.y
```

Package manifests usually end with `.mum`. They describe package-level metadata and contain update entries. An update entry can reference different kinds of payload, including component, package, and driver references.

Optional features are represented as CBS updates in the Foundation package. A feature has state, display metadata, parent relationships, and a content package. Enabling or disabling a feature changes requested servicing state; committing changes is a CBS operation and should be treated carefully.

## Components and WinSxS

Components are lower-level native assemblies in the component store. They are the units that ultimately own files, registry values, dependencies, hashes, and registration metadata.

WinSxS is the side-by-side component store. It allows multiple versions of components to exist at the same time and gives Windows a versioned, identity-based store for system files and metadata. A component can be staged without being actively installed, installed as part of a package, or superseded by a newer component.

UFCase enumerates components through WCP / Isolation store APIs and reads extra component state through CSI store APIs. The component page is therefore closer to WinSxS than to the higher-level DISM package view.

## Package and Component Manifests

Manifests are central to UFCase, but it is important to be precise: UFCase currently focuses on package manifests and component manifests, and they are different formats.

Package manifests:

- are usually `.mum` files under `%WINDIR%\servicing\Packages`;
- describe package identity and package metadata;
- list parent packages;
- contain CBS update entries;
- can reference components, packages, and drivers.

Component manifests:

- describe WinSxS component identity and payload;
- include file and registry metadata;
- can include assembly dependencies;
- can include registration data such as COM, services, scheduled tasks, migration data, and other component-specific declarations;
- may be exposed by the component store as XML or through a cooked representation.

The two formats share assembly concepts, identity conventions, and XML namespace patterns such as `urn:schemas-microsoft-com:asm.v1`, `asm.v2`, and `asm.v3`. That shared foundation is why a schema reference is useful across many samples. Still, package manifests and component manifests should not be treated as one single format, and they do not describe every layer of Windows servicing by themselves.

In UFCase, manifests are useful because they expose references that are otherwise hard to discover:

- package manifest component entries can point to components;
- package manifest package and parent entries can point to other packages;
- component manifest dependencies can point to other components;
- component manifest file and registry declarations are the basis for future file/registry cross-reference views.

## How This Connects to Manifest Schema Notes

[Manifest Schema Notes](./manifest_schema.md) is the schema-level companion to this document. It records elements and attributes found in real servicing manifests.

This concepts document explains why those manifests matter in the servicing model. The schema notes explain what the XML contains once you have a manifest in hand.

The schema work is especially valuable because Microsoft's public manifest schema documentation only covers part of the picture. Native Windows component manifests contain many internal elements that are not described by public SxS documentation.

## Internal Interfaces UFCase Uses

UFCase uses a mix of public Win32 APIs, public COM mechanics, and undocumented or internal servicing interfaces. The important internal families are:

- CBS: `ICbsSession`, `ICbsPackage`, `ICbsUpdate`, package enumeration, feature/update state, and servicing operations.
- CbsCore: `CbsCore.dll` and `CbsCoreInitialize` for offline CBS sessions.
- WCP / Isolation: `wcp.dll`, `WcpInitialize`, identity authorities, `IStore2`, and component enumeration.
- CSI: `ICSIStore` for component manifests, component status, payload information, and component files.
- CMI: the `Cmi20` serializer used by `UFCase.Host.Manifest` to parse cooked component manifests into file, registry, identity, and dependency models.

For online images, UFCase can create an online CBS session through the system CBS local server. For offline images, it loads servicing binaries and opens offline stores for the target image. This distinction is one reason UFCase keeps servicing work in isolated host processes.

## Practical Reading Path

If you are trying to understand a Windows image with UFCase:

1. Start with Packages to see the high-level servicing units visible to CBS and DISM.
2. Open a package manifest to see which updates, components, packages, drivers, and parents it references.
3. Follow component references into Components to inspect WinSxS identities, status, files, payload paths, and component manifests.
4. Use component manifests to understand the actual files, registry data, and dependencies a component declares.
5. Use the schema notes when you encounter unfamiliar manifest elements.

This workflow mirrors UFCase's current strengths: it does not hide the internal servicing model, but it gives enough navigation to move from familiar Windows Update and DISM concepts down to the component and manifest level.
