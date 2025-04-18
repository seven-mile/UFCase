# Usage:
#   python merge_dlldata.py file1 dlldata1.c file2 dlldata2.c ... > merged_dlldata.c

import re
import sys

# Regex patterns
extern_pattern = re.compile(r"EXTERN_PROXY_FILE\(\s*(\w+)\s*\)")
reference_pattern = re.compile(r"REFERENCE_PROXY_FILE\(\s*(\w+)\s*\)")

def parse_file(path):
    """Parse a dlldata file and return sets of externs and references."""
    externs = set()
    references = []
    with open(path, 'r') as f:
        in_list = False
        for line in f:
            m1 = extern_pattern.search(line)
            if m1:
                externs.add(m1.group(1))
            m2 = reference_pattern.search(line)
            if m2:
                references.append(m2.group(1))
    return externs, references

# Collect from all input files
all_externs = []
all_references = []
for filename in sys.argv[1:]:
    externs, references = parse_file(filename)
    all_externs.extend(sorted(externs))
    all_references.extend(sorted(references))

# Deduplicate while preserving order
def unique(seq):
    seen = set()
    out = []
    for item in seq:
        if item not in seen:
            seen.add(item)
            out.append(item)
    return out

unique_externs = unique(all_externs)
unique_references = unique(all_references)

# Generate merged output
print("/*********************************************************")
print("   DllData file -- merged by merge_dlldata.py")
print("*********************************************************/\n")
print("#define PROXY_DELEGATION\n")
# print("#include <rpcproxy.h>\n")
print('#include "../UFCase.Host/rpcproxy_arm64.h"')
print("#ifdef __cplusplus")
print("extern \"C\"   {")
print("#endif\n")

# Print externs
for name in unique_externs:
    print(f"EXTERN_PROXY_FILE( {name} )")
print("\n// Proxy file list")
print("PROXYFILE_LIST_START")
print("/* Start of list */")
for name in unique_references:
    print(f"  REFERENCE_PROXY_FILE( {name} ),")
print("/* End of list */")
print("PROXYFILE_LIST_END\n")
print("DLLDATA_ROUTINES( aProxyFileList, GET_DLL_CLSID )\n")
print("#ifdef __cplusplus")
print("}  /* extern \"C\" */")
print("#endif\n")
print("/* end of merged dlldata file */")
