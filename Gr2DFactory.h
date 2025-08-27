#pragma once
#include <atomic>
#include <WzLib/IWzGr2D_DX9.h>
#include "Gr2D.h"


class CWzGr2DFactory : public IClassFactory {
private:
    std::atomic<ULONG> m_uRefCount;
    IClassFactory* m_pInner;

public:
    CWzGr2DFactory(IClassFactory* pInner) : m_uRefCount(1), m_pInner(pInner) {
    }
    ~CWzGr2DFactory() {
        m_pInner->Release();
        m_pInner = nullptr;
    }

    /*** IUnknown methods ***/
    virtual HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject) override {
        return m_pInner->QueryInterface(riid, ppvObject);
    }
    virtual ULONG __stdcall AddRef() override {
        return ++m_uRefCount;
    }
    virtual ULONG __stdcall Release() override {
        ULONG uCount = --m_uRefCount;
        if (uCount == 0) {
            delete this;
        }
        return uCount;
    }

    /*** IClassFactory methods ***/
    virtual HRESULT __stdcall CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppvObject) {
        IWzGr2D_DX9* pInner = nullptr;
        HRESULT hr = m_pInner->CreateInstance(pUnkOuter, riid, reinterpret_cast<void**>(&pInner));
        if (FAILED(hr)) {
            return hr;
        }
        *ppvObject = new CWzGr2D(pInner);
        return S_OK;
    }
    virtual HRESULT __stdcall LockServer(BOOL fLock) {
        return m_pInner->LockServer(fLock);
    }
};
