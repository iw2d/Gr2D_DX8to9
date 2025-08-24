#pragma once
#include <atomic>
#include <WzLib/IWzGr2D.h>
#include <WzLib/IWzGr2DLayer.h>
#include "Gr2DLayer.h"


struct __declspec(uuid("e576ea33-d465-4f08-aab1-e78df73ee6d9"))
IWzGr2D_DX8 : IUnknown
{
    virtual HRESULT __stdcall raw_Initialize (
        /*[in]*/ unsigned int uWidth,
        /*[in]*/ unsigned int uHeight,
        /*[in]*/ VARIANT vHwnd = vtEmpty,
        /*[in]*/ VARIANT vBPP = vtEmpty,
        /*[in]*/ VARIANT vRefreshRate = vtEmpty ) = 0;
    virtual HRESULT __stdcall raw_Uninitialize ( ) = 0;
    virtual HRESULT __stdcall get_nextRenderTime (
        /*[out,retval]*/ int * pnTime ) = 0;
    virtual HRESULT __stdcall raw_UpdateCurrentTime (
        /*[in]*/ int tTime ) = 0;
    virtual HRESULT __stdcall raw_RenderFrame ( ) = 0;
    virtual HRESULT __stdcall raw_SetFrameSkip ( ) = 0;
    virtual HRESULT __stdcall raw_ToggleFpsPanel ( ) = 0;
    virtual HRESULT __stdcall raw_DisableFpsPanel ( ) = 0;
    virtual HRESULT __stdcall get_width (
        /*[out,retval]*/ unsigned int * puWidth ) = 0;
    virtual HRESULT __stdcall get_height (
        /*[out,retval]*/ unsigned int * puHeight ) = 0;
    virtual HRESULT __stdcall get_bpp (
        /*[out,retval]*/ unsigned int * puBPP ) = 0;
    virtual HRESULT __stdcall get_refreshRate (
        /*[out,retval]*/ unsigned int * puRefreshRate ) = 0;
    virtual HRESULT __stdcall get_fps100 (
        /*[out,retval]*/ unsigned int * puFps100 ) = 0;
    virtual HRESULT __stdcall get_currentTime (
        /*[out,retval]*/ int * pnCurrentTime ) = 0;
    virtual HRESULT __stdcall get_fullScreen (
        /*[out,retval]*/ int * pnFullScreen ) = 0;
    virtual HRESULT __stdcall put_fullScreen (
        /*[in]*/ int pnFullScreen ) = 0;
    virtual HRESULT __stdcall get_backColor (
        /*[out,retval]*/ unsigned int * puColor ) = 0;
    virtual HRESULT __stdcall put_backColor (
        /*[in]*/ unsigned int puColor ) = 0;
    virtual HRESULT __stdcall get_redTone (
        /*[out,retval]*/ struct IWzVector2D * * ppVector ) = 0;
    virtual HRESULT __stdcall get_greenBlueTone (
        /*[out,retval]*/ struct IWzVector2D * * ppVector ) = 0;
    virtual HRESULT __stdcall get_center (
        /*[out,retval]*/ struct IWzVector2D * * ppVector ) = 0;
    virtual HRESULT __stdcall raw_GetSnapshot (
        /*[in]*/ VARIANT pvBuffer,
        /*[in]*/ unsigned int uBufferSize,
        /*[in]*/ int x,
        /*[in]*/ int y ) = 0;
    virtual HRESULT __stdcall raw_CreateLayer (
        /*[in]*/ int nLeft,
        /*[in]*/ int nTop,
        /*[in]*/ unsigned int uWidth,
        /*[in]*/ unsigned int uHeight,
        /*[in]*/ int nZ,
        /*[in]*/ VARIANT vCanvas,
        /*[in]*/ VARIANT dwFilter,
        /*[out,retval]*/ struct IWzGr2DLayer * * ppLayer ) = 0;
    virtual HRESULT __stdcall raw_InitializeFlashByDevice ( ) = 0;
    virtual HRESULT __stdcall raw_LoadMediaFile (
        /*[in]*/ LPSTR sSource ) = 0;
    virtual HRESULT __stdcall raw_SetFlashAbsLocation (
        /*[in]*/ int nX,
        /*[in]*/ int nY ) = 0;
    virtual HRESULT __stdcall raw_RenderFlash ( ) = 0;
    virtual HRESULT __stdcall raw_ReleaseFlash ( ) = 0;
    virtual HRESULT __stdcall raw_IsRenderFlash (
        /*[out,retval]*/ int * pnRenderFlash ) = 0;
};


class CWzGr2D : public IWzGr2D_DX8 {
private:
    std::atomic<ULONG> m_uRefCount;
    IWzGr2D* m_pInner;

public:
    CWzGr2D(IWzGr2D* pInner) : m_uRefCount(1), m_pInner(pInner) {
        m_pInner->AddRef();
    }
    ~CWzGr2D() {
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

    /*** IWzGr2D methods ***/
    virtual HRESULT __stdcall raw_Initialize(UINT uWidth, UINT uHeight, VARIANT vHwnd, VARIANT vBPP, VARIANT vRefreshRate) override {
        HWND hWnd = reinterpret_cast<HWND>(V_BYREF(&vHwnd));
        if (hWnd == nullptr || !IsWindow(hWnd)) {
            return E_INVALIDARG;
        }
        V_I4(&vBPP) = 0;
        HRESULT hr = m_pInner->raw_Initialize(uWidth, uHeight, vHwnd, vBPP, vRefreshRate);
        if (FAILED(hr)) {
            return hr;
        }
        ShowWindow(hWnd, SW_SHOW);
        UpdateWindow(hWnd);
        SetForegroundWindow(hWnd);
        return S_OK;
    }
    virtual HRESULT __stdcall raw_Uninitialize() override {
        return m_pInner->raw_Uninitialize();
    }
    virtual HRESULT __stdcall get_nextRenderTime(INT* pnTime) override {
        return m_pInner->get_nextRenderTime(pnTime);
    }
    virtual HRESULT __stdcall raw_UpdateCurrentTime(INT tTime) override {
        return m_pInner->raw_UpdateCurrentTime(tTime);
    }
    virtual HRESULT __stdcall raw_RenderFrame() override {
        return m_pInner->raw_RenderFrame();
    }
    virtual HRESULT __stdcall raw_SetFrameSkip() override {
        return m_pInner->raw_SetFrameSkip();
    }
    virtual HRESULT __stdcall raw_ToggleFpsPanel() override {
        return m_pInner->raw_ToggleFpsPanel();
    }
    virtual HRESULT __stdcall raw_DisableFpsPanel() override {
        return m_pInner->raw_DisableFpsPanel();
    }
    virtual HRESULT __stdcall get_width(UINT* puWidth) override {
        return m_pInner->get_width(puWidth);
    }
    virtual HRESULT __stdcall get_height(UINT* puHeight) override {
        return m_pInner->get_height(puHeight);
    }
    virtual HRESULT __stdcall get_bpp(UINT* puBPP) override {
        return m_pInner->get_bpp(puBPP);
    }
    virtual HRESULT __stdcall get_refreshRate(UINT* puRefreshRate) override {
        return m_pInner->get_refreshRate(puRefreshRate);
    }
    virtual HRESULT __stdcall get_fps100(UINT* puFps100) override {
        return m_pInner->get_fps100(puFps100);
    }
    virtual HRESULT __stdcall get_currentTime(INT* pnCurrentTime) override {
        return m_pInner->get_currentTime(pnCurrentTime);
    }
    virtual HRESULT __stdcall get_fullScreen(INT* pnFullScreen) override {
        return m_pInner->get_fullScreen(pnFullScreen);
    }
    virtual HRESULT __stdcall put_fullScreen(INT nFullScreen) override {
        return m_pInner->put_fullScreen(nFullScreen);
    }
    virtual HRESULT __stdcall get_backColor(UINT* puColor) override {
        return m_pInner->get_backColor(puColor);
    }
    virtual HRESULT __stdcall put_backColor(UINT uColor) override {
        return m_pInner->put_backColor(uColor);
    }
    virtual HRESULT __stdcall get_redTone(IWzVector2D** ppVector) override {
        return m_pInner->get_redTone(ppVector);
    }
    virtual HRESULT __stdcall get_greenBlueTone(IWzVector2D** ppVector) override {
        return m_pInner->get_greenBlueTone(ppVector);
    }
    virtual HRESULT __stdcall get_center(IWzVector2D** ppVector) override {
        return m_pInner->get_center(ppVector);
    }
    virtual HRESULT __stdcall raw_GetSnapshot(VARIANT pvBuffer, UINT uBufferSize, INT x, INT y) override {
        return m_pInner->raw_GetSnapshot(pvBuffer, uBufferSize, x, y);
    }
    virtual HRESULT __stdcall raw_CreateLayer(INT nLeft, INT nTop, UINT uWidth, UINT uHeight, INT nZ, VARIANT vCanvas, VARIANT dwFilter, IWzGr2DLayer** ppLayer) override {
        if (ppLayer == nullptr) {
            return E_POINTER;
        }
        IWzGr2DLayer* pInner = nullptr;
        HRESULT hr = m_pInner->raw_CreateLayer(nLeft, nTop, uWidth, uHeight, nZ, vCanvas, dwFilter, &pInner);
        if (FAILED(hr)) {
            return hr;
        }
        *ppLayer = new CWzGr2DLayer(pInner);
        return S_OK;
    }
    virtual HRESULT __stdcall raw_InitializeFlashByDevice() override {
        return S_FALSE;
    }
    virtual HRESULT __stdcall raw_LoadMediaFile(LPSTR sSource) override {
        return S_OK;
    }
    virtual HRESULT __stdcall raw_SetFlashAbsLocation(int nX, int nY) override {
        return S_OK;
    }
    virtual HRESULT __stdcall raw_RenderFlash() override {
        return S_OK;
    }
    virtual HRESULT __stdcall raw_ReleaseFlash() override {
        return S_OK;
    }
    virtual HRESULT __stdcall raw_IsRenderFlash(INT* pnRenderFlash) override {
        if (pnRenderFlash == nullptr) {
            return E_POINTER;
        }
        *pnRenderFlash = 0;
        return S_OK;
    }
};


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
        IWzGr2D* pInner = nullptr;
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
