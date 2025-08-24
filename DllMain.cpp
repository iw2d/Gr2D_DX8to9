#include <windows.h>
#include "Gr2D.h"


HMODULE hDX9Module = nullptr;

BOOL WINAPI DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpvReserved) {
    if (fdwReason == DLL_PROCESS_ATTACH) {
        hDX9Module = LoadLibraryW(L"GR2D_DX9.DLL");
        if (!hDX9Module) {
            return FALSE;
        }
        DisableThreadLibraryCalls(hModule);
    } else if (fdwReason == DLL_PROCESS_DETACH) {
        if (hDX9Module) {
            FreeLibrary(hDX9Module);
        }
    }
    return TRUE;
}

extern "C" HRESULT WINAPI DllCanUnloadNow() {
    return reinterpret_cast<HRESULT (WINAPI*)()>(GetProcAddress(hDX9Module, "DllCanUnloadNow"))();
}

extern "C" HRESULT WINAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv) {
    auto sUOL = reinterpret_cast<const wchar_t*>(&rclsid);
    if (wcscmp(sUOL, L"Gr2D_DX8") != 0) {
        return CLASS_E_CLASSNOTAVAILABLE;
    }
    if (ppv == nullptr) {
        return E_POINTER;
    }
    IClassFactory* pInner = nullptr;
    HRESULT hr = reinterpret_cast<HRESULT (WINAPI*)(const wchar_t*, REFIID, void**)>(GetProcAddress(hDX9Module, "DllGetClassObject"))(L"Gr2D_DX9", riid, reinterpret_cast<void**>(&pInner));
    if (FAILED(hr)) {
        return hr;
    }
    *ppv = new CWzGr2DFactory(pInner);
    return S_OK;
}