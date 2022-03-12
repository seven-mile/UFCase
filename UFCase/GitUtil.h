#pragma once

//#pragma comment(lib, "uuid.lib")
namespace winrt::UFCase {

inline com_ptr<IGlobalInterfaceTable> GetGIT() {
    static com_ptr<IGlobalInterfaceTable> git{};
    if (!git) {
        git = create_instance<IGlobalInterfaceTable>(CLSID_StdGlobalInterfaceTable, CLSCTX_INPROC_SERVER);
    }
    return git;
}

}

