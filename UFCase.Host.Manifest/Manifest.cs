
using WinRT;

namespace UFCase.Host.Manifest
{
    internal class CmiGlobal
    {
        static Cmi20.CmiFactory? factory;
        static Cmi20.XmlSerializer? serializer;

        public static Cmi20.CmiFactory GetFactory()
        {
            return factory ??= new Cmi20.CmiFactory();
        }

        public static Cmi20.XmlSerializer GetSerializer()
        {
            return serializer ??= GetFactory().CreateObject(Cmi20.CmiObjectType.cmiSerializer);
        }
    }

    public sealed class Version
    {
        public Version() { throw new NotImplementedException(); }

        readonly Cmi20.Version CmiVersion;

        internal Version(Cmi20.Version cmiVersion)
        {
            CmiVersion = cmiVersion;
        }

        public int Major => CmiVersion.Major;
        public int Minor => CmiVersion.Minor;
        public int Build => CmiVersion.Build;
        public int Revision => CmiVersion.Revision;
        public string Value => CmiVersion.Value;
    }

    public sealed class File
    {
        public File() { throw new NotImplementedException(); }

        readonly Cmi20.File CmiFile;

        internal File(Cmi20.File cmiFile)
        {
            CmiFile = cmiFile;
        }

        public string DestinationName => CmiFile.DestinationName;
        public string DestinationPath => CmiFile.DestinationPath;
        public string SourcePath => CmiFile.SourcePath;
        public string SourceName => CmiFile.SourceName;
        public string ImportPath => CmiFile.ImportPath;
        public string Hash => CmiFile.Hash;
        public string HashAlgorithm => CmiFile.HashAlgorithm;
        public int SizeInByte => CmiFile.Size;

    }

    public enum RegistryValueType
    {
        RegNone = 0,
        RegSz = 1,
        RegExpandSz = 2,
        RegBinary = 3,
        RegDword = 4,
        RegDwordBigEndian = 5,
        RegLink = 6,
        RegMultiSz = 7,
        RegResourceList = 8,
        RegFullResourceDescriptor = 9,
        RegResourceRequirementsList = 10,
        RegQword = 11,
    }

    public sealed class RegistryValue
    {
        public RegistryValue() { throw new NotImplementedException(); }

        readonly Cmi20.RegistryValue CmiValue;

        internal RegistryValue(Cmi20.RegistryValue cmiValue)
        {
            CmiValue = cmiValue;
        }

        public string Name => CmiValue.Name;
        public RegistryValueType Type => (RegistryValueType)CmiValue.Type;
        public object? Data
        {
            get
            {
                var obj = CmiValue.Data as object;
                System.Diagnostics.Debug.Print(obj?.GetType().ToString() ?? "null");

                if (CmiValue.Data is null)
                {
                    return null;
                }

                return Type switch
                {
                    RegistryValueType.RegNone => null,
                    RegistryValueType.RegSz or RegistryValueType.RegExpandSz => CmiValue.Data as string,
                    RegistryValueType.RegBinary => CmiValue.Data as byte[],
                    RegistryValueType.RegDword => CmiValue.Data as int?,
                    RegistryValueType.RegDwordBigEndian => throw new NotImplementedException(),
                    RegistryValueType.RegLink => CmiValue.Data as string,
                    RegistryValueType.RegMultiSz => CmiValue.Data as string[],
                    RegistryValueType.RegResourceList => null,
                    RegistryValueType.RegFullResourceDescriptor => null,
                    RegistryValueType.RegResourceRequirementsList => null,
                    RegistryValueType.RegQword => CmiValue.Data as long?,
                    _ => null,
                };
            }
        }
    }

    public sealed class RegistryKey
    {
        public RegistryKey() { throw new NotImplementedException(); }

        readonly Cmi20.RegistryKey CmiKey;

        internal RegistryKey(Cmi20.RegistryKey cmiKey)
        {
            CmiKey = cmiKey;
        }

        public string Name => CmiKey.KeyName;

        public RegistryValue[] Values =>
            CmiKey.RegistryValues
            .Cast<Cmi20.RegistryValue>()
            .Select(i => new RegistryValue(i))
            .ToArray();
    }

    public sealed class AssemblyIdentity
    {
        public AssemblyIdentity() { throw new NotImplementedException(); }

        readonly Cmi20.IIdentity CmiIdentity;

        internal AssemblyIdentity(Cmi20.IIdentity cmiIdentity)
        {
            CmiIdentity = cmiIdentity;
        }

        public string Name => CmiIdentity.Name;
        public string PublicKeyToken => CmiIdentity.PublicKeyToken;
        public string Language => CmiIdentity.Language;
        public string ProcessorArchitecture => CmiIdentity.ProcessorArchitecture;
        public string Version => CmiIdentity.Version.Value;
        public string Type => CmiIdentity.Type;
        public string KeyForm => CmiIdentity.ToString();
        public string HashCode => CmiIdentity.GetHashCode();
    }

    public sealed class AssemblyDependency
    {
        public AssemblyDependency() { throw new NotImplementedException(); }

        readonly Cmi20.AssemblyDependency CmiDependency;
        internal AssemblyDependency(Cmi20.AssemblyDependency cmiDependency)
        {
            CmiDependency = cmiDependency;
        }

        public AssemblyIdentity Identity => new(CmiDependency.DependencyId);
        public string Type => CmiDependency.DependencyType;
        public string Install => CmiDependency.Install;
    }

    public sealed class Assembly
    {
        public Assembly() { throw new NotImplementedException(); }

        readonly Cmi20.Assembly CmiAssembly;
        internal Assembly(Cmi20.Assembly assembly)
        {
            CmiAssembly = assembly;
        }

        public AssemblyIdentity Identity => new(CmiAssembly.Id);
        public Version Version => new(CmiAssembly.Id.Version);

        public File[] Files =>
            CmiAssembly.Files
            .Cast<Cmi20.File>()
            .Select(i => new File(i)).ToArray();

        public RegistryKey[] Keys =>
            CmiAssembly.RegistryKeys
            .Cast<Cmi20.RegistryKey>()
            .Select(i => new RegistryKey(i)).ToArray();


        public AssemblyDependency[] Dependencies
        {
            get
            {
                var cmiDependencies = CmiAssembly.Dependencies;
                var dependencies = new AssemblyDependency[cmiDependencies.Count];
                for (var i = 0; i < dependencies.Length; i++)
                {
                    if (cmiDependencies[i] is not Cmi20.Dependency dep)
                    {
                        continue;
                    }
                    if (dep.SubObject is Cmi20.AssemblyDependency depAsm)
                    {
                        dependencies[i] = new(depAsm);
                    }
                    // ignore other dependencies for now
                }
                return dependencies;
            }
        }

    }

    public interface IComStreamWrapper
    {
    }

    public sealed class ManifestParser
    {
        static public Assembly ParseFromPath(string path)
        {
            return new Assembly(CmiGlobal.GetSerializer().Deserialize(path));
        }

        static public Assembly ParseFromStream(IComStreamWrapper stream)
        {
            var comStream = ((IWinRTObject)stream).NativeObject
                .AsInterface<System.Runtime.InteropServices.ComTypes.IStream>();

            return new Assembly(CmiGlobal.GetSerializer().Deserialize(comStream));
        }
    }
}
