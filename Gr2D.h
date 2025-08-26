#pragma once
#include <atomic>
#include <WzLib/IWzGr2D.h>
#include "Gr2D/IWzGr2D_DX8.h"
#include "Gr2DLayer.h"


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

    /*** Custom methods ***/
    virtual HRESULT __stdcall put_screenResolution(UINT uWidth, UINT uHeight) {
        return m_pInner->put_screenResolution(uWidth, uHeight);
    }
};