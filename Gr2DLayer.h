#pragma once
#include <atomic>
#include <WzLib/IWzGr2D.h>
#include "Debug.h"


class CWzGr2DLayer : public IWzGr2DLayer {
private:
    std::atomic<ULONG> m_uRefCount;
    IWzGr2DLayer* m_pInner;

public:
    CWzGr2DLayer(IWzGr2DLayer* pInner) : m_uRefCount(1), m_pInner(pInner) {
    }
    ~CWzGr2DLayer() {
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


    /*** IWzSerialize methods ***/
    virtual HRESULT __stdcall get_persistentUOL(BSTR* pVal) override {
        return m_pInner->get_persistentUOL(pVal);
    }
    virtual HRESULT __stdcall raw_Serialize(IWzArchive* pArchive) override {
        return m_pInner->raw_Serialize(pArchive);
    }

    /*** IWzShape2D methods ***/
    virtual HRESULT __stdcall get_item(VARIANT vIndex, VARIANT* pvValue) override {
        return m_pInner->get_item(vIndex, pvValue);
    }
    virtual HRESULT __stdcall get__NewEnum(IUnknown** pVal) override {
        return m_pInner->get__NewEnum(pVal);
    }
    virtual HRESULT __stdcall get_count(UINT* pVal) override {
        return m_pInner->get_count(pVal);
    }
    virtual HRESULT __stdcall get_x(INT* pVal) override {
        return m_pInner->get_x(pVal);
    }
    virtual HRESULT __stdcall put_x(INT newVal) override {
        return m_pInner->put_x(newVal);
    }
    virtual HRESULT __stdcall get_y(INT* pVal) override {
        return m_pInner->get_y(pVal);
    }
    virtual HRESULT __stdcall put_y(INT newVal) override {
        return m_pInner->put_y(newVal);
    }
    virtual HRESULT __stdcall get_x2(INT* pVal) override {
        return m_pInner->get_x2(pVal);
    }
    virtual HRESULT __stdcall put_x2(INT newVal) override {
        return m_pInner->put_x2(newVal);
    }
    virtual HRESULT __stdcall get_y2(INT* pVal) override {
        return m_pInner->get_y2(pVal);
    }
    virtual HRESULT __stdcall put_y2(INT newVal) override {
        return m_pInner->put_y2(newVal);
    }
    virtual HRESULT __stdcall raw_Move(INT nX, INT nY) override {
        return m_pInner->raw_Move(nX, nY);
    }
    virtual HRESULT __stdcall raw_Offset(INT nDX, INT nDY) override {
        return m_pInner->raw_Offset(nDX, nDY);
    }
    virtual HRESULT __stdcall raw_Scale(INT nXMul, INT nXDiv, INT nYMul, INT nYDiv, INT nXOrg, INT nYOrg) override {
        return m_pInner->raw_Scale(nXMul, nXDiv, nYMul, nYDiv, nXOrg, nYOrg);
    }
    virtual HRESULT __stdcall raw_Insert(VARIANT vIndexOrShape, VARIANT vShape) override {
        return m_pInner->raw_Insert(vIndexOrShape, vShape);
    }
    virtual HRESULT __stdcall raw_Remove(VARIANT vIndex, VARIANT* pvRemoved) override {
        return m_pInner->raw_Remove(vIndex, pvRemoved);
    }
    virtual HRESULT __stdcall raw_Init(INT nX, INT nY) override {
        return m_pInner->raw_Init(nX, nY);
    }

    /*** IWzVector2D methods ***/
    virtual HRESULT __stdcall get_currentTime(INT* pnTime) override {
        return m_pInner->get_currentTime(pnTime);
    }
    virtual HRESULT __stdcall put_currentTime(INT nTime) override {
        return m_pInner->put_currentTime(nTime);
    }
    virtual HRESULT __stdcall get_origin(VARIANT* pvOrigin) override {
        return m_pInner->get_origin(pvOrigin);
    }
    virtual HRESULT __stdcall put_origin(VARIANT vOrigin) override {
        return m_pInner->put_origin(vOrigin);
    }
    virtual HRESULT __stdcall get_rx(INT* pVal) override {
        return m_pInner->get_rx(pVal);
    }
    virtual HRESULT __stdcall put_rx(INT newVal) override {
        return m_pInner->put_rx(newVal);
    }
    virtual HRESULT __stdcall get_ry(INT* pVal) override {
        return m_pInner->get_ry(pVal);
    }
    virtual HRESULT __stdcall put_ry(INT newVal) override {
        return m_pInner->put_ry(newVal);
    }
    virtual HRESULT __stdcall get_a(DOUBLE* pVal) override {
        return m_pInner->get_a(pVal);
    }
    virtual HRESULT __stdcall get_ra(DOUBLE* pVal) override {
        return m_pInner->get_ra(pVal);
    }
    virtual HRESULT __stdcall put_ra(DOUBLE newVal) override {
        return m_pInner->put_ra(newVal);
    }
    virtual HRESULT __stdcall get_flipX(INT* pVal) override {
        return m_pInner->get_flipX(pVal);
    }
    virtual HRESULT __stdcall put_flipX(INT newVal) override {
        return m_pInner->put_flipX(newVal);
    }
    virtual HRESULT __stdcall raw__GetSnapshot(INT* px, INT* py, INT* prx, INT* pry, INT* pxOrg, INT* pyOrg, DOUBLE* pa, DOUBLE* paOrg, VARIANT vTime) override {
        return m_pInner->_GetSnapshot(px, py, prx, pry, pxOrg, pyOrg, pa, paOrg, vTime);
    }
    virtual HRESULT __stdcall raw_RelMove(INT nX, INT nY, VARIANT nTime, VARIANT nType) override {
        return m_pInner->raw_RelMove(nX, nY, nTime, nType);
    }
    virtual HRESULT __stdcall raw_RelOffset(INT nDX, INT nDY, VARIANT nTime, VARIANT nType) override {
        return m_pInner->raw_RelOffset(nDX, nDY, nTime, nType);
    }
    virtual HRESULT __stdcall raw_Ratio(IWzVector2D* pOrigin, INT nOriginWidth, INT nOriginHeight, INT nScaleWidth, INT nScaleHeight) override {
        return m_pInner->raw_Ratio(pOrigin, nOriginWidth, nOriginHeight, nScaleWidth, nScaleHeight);
    }
    virtual HRESULT __stdcall raw_WrapClip(VARIANT pOrigin, INT nWrapLeft, INT nWrapTop, UINT uWrapWidth, UINT uWrapHeight, VARIANT bClip) override {
        return m_pInner->raw_WrapClip(pOrigin, nWrapLeft, nWrapTop, uWrapWidth, uWrapHeight, bClip);
    }
    virtual HRESULT __stdcall raw_Rotate(DOUBLE dAngleAmount, VARIANT nTime) override {
        return m_pInner->raw_Rotate(dAngleAmount, nTime);
    }
    virtual HRESULT __stdcall get_looseLevel(UINT* puLevel) override {
        return m_pInner->get_looseLevel(puLevel);
    }
    virtual HRESULT __stdcall put_looseLevel(UINT uLevel) override {
        return m_pInner->put_looseLevel(uLevel);
    }
    virtual HRESULT __stdcall raw_Fly(VARIANT* aVar, INT nArgs) override {
        return m_pInner->raw_Fly(aVar, nArgs);
    }

    /*** IWzGr2DLayer methods ***/
    virtual HRESULT __stdcall get_z(INT* pnZ) override {
        return m_pInner->get_z(pnZ);
    }
    virtual HRESULT __stdcall put_z(INT nZ) override {
        return m_pInner->put_z(nZ);
    }
    virtual HRESULT __stdcall get_width(INT* pnWidth) override {
        return m_pInner->get_width(pnWidth);
    }
    virtual HRESULT __stdcall put_width(INT nWidth) override {
        return m_pInner->put_width(nWidth);
    }
    virtual HRESULT __stdcall get_height(INT* pnHeight) override {
        return m_pInner->get_height(pnHeight);
    }
    virtual HRESULT __stdcall put_height(INT nHeight) override {
        return m_pInner->put_height(nHeight);
    }
    virtual HRESULT __stdcall get_lt(IWzVector2D** ppVector) override {
        return m_pInner->get_lt(ppVector);
    }
    virtual HRESULT __stdcall get_rb(IWzVector2D** ppVector) override {
        return m_pInner->get_rb(ppVector);
    }
    virtual HRESULT __stdcall raw_InterLockedOffset(INT xlt, INT ylt, INT xrb, INT yrb) override {
        return m_pInner->raw_InterLockedOffset(xlt, ylt, xrb, yrb);
    }
    virtual HRESULT __stdcall get_flip(INT* pnFlip) override {
        return m_pInner->get_flip(pnFlip);
    }
    virtual HRESULT __stdcall put_flip(INT nFlip) override {
        return m_pInner->put_flip(nFlip);
    }
    virtual HRESULT __stdcall get_color(UINT* puColor) override {
        return m_pInner->get_color(puColor);
    }
    virtual HRESULT __stdcall put_color(UINT uColor) override {
        return m_pInner->put_color(uColor);
    }
    virtual HRESULT __stdcall get_alpha(IWzVector2D** ppVector) override {
        return m_pInner->get_alpha(ppVector);
    }
    virtual HRESULT __stdcall get_redTone(IWzVector2D** ppVector) override {
        return m_pInner->get_redTone(ppVector);
    }
    virtual HRESULT __stdcall get_greenBlueTone(IWzVector2D** ppVector) override {
        return m_pInner->get_greenBlueTone(ppVector);
    }
    virtual HRESULT __stdcall get_blend(LAYER_BLENDTYPE* pnBlend) override {
        return m_pInner->get_blend(pnBlend);
    }
    virtual HRESULT __stdcall put_blend(LAYER_BLENDTYPE nblend) override {
        return m_pInner->put_blend(nblend);
    }
    virtual HRESULT __stdcall get_overlay(VARIANT* pvLayer) override {
        return m_pInner->get_overlay(pvLayer);
    }
    virtual HRESULT __stdcall put_overlay(VARIANT vLayer) override {
        return m_pInner->put_overlay(vLayer);
    }
    virtual HRESULT __stdcall get_canvas(VARIANT vIndex, IWzCanvas** ppCanvas) override {
        return m_pInner->get_canvas(vIndex, ppCanvas);
    }
    virtual HRESULT __stdcall raw_InsertCanvas(IWzCanvas* pCanvas, VARIANT vDelay, VARIANT vAlpha0, VARIANT vAlpha1, VARIANT vZoom0, VARIANT vZoom1, VARIANT* pvIndex) override {
        return m_pInner->raw_InsertCanvas(pCanvas, vDelay, vAlpha0, vAlpha1, vZoom0, vZoom1, pvIndex);
    }
    virtual HRESULT __stdcall raw_RemoveCanvas(VARIANT vIndex, IWzCanvas** ppCanvas) override {
        return m_pInner->raw_RemoveCanvas(vIndex, ppCanvas);
    }
    virtual HRESULT __stdcall raw_ShiftCanvas(VARIANT vValue) override {
        return m_pInner->raw_ShiftCanvas(vValue);
    }
    virtual HRESULT __stdcall raw_Animate(GR2D_ANITYPE nType, VARIANT vDelayRate, VARIANT vRepeat) override {
        return m_pInner->raw_Animate(nType, vDelayRate, vRepeat);
    }
    virtual HRESULT __stdcall get_animationState(INT* pnState) override {
        return m_pInner->get_animationState(pnState);
    }
    virtual HRESULT __stdcall get_visible(INT* pnVisible) override {
        return m_pInner->get_visible(pnVisible);
    }
    virtual HRESULT __stdcall put_visible(INT nVisible) override {
        return m_pInner->put_visible(nVisible);
    }
    virtual HRESULT __stdcall unk_120(INT a1) {
        // Called in CNpc::Init before CMapleTVMan::SetFlashAbsLocation
        DebugMessage("CWzGr2DLayer::unk_120(%d) - 0x%08X", a1, _ReturnAddress());
        return S_OK;
    }
};
