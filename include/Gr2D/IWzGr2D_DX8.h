#pragma once
#pragma pack(push, 8)

#include <WzLib/IWzGr2D.h>

struct __declspec(uuid("e576ea33-d465-4f08-aab1-e78df73ee6d9"))
/* interface */ IWzGr2D_DX8;

_COM_SMARTPTR_TYPEDEF(IWzGr2D_DX8, __uuidof(IWzGr2D_DX8));

struct __declspec(uuid("e576ea33-d465-4f08-aab1-e78df73ee6d9"))
IWzGr2D_DX8 : IUnknown
{
    __declspec(property(get=GetnextRenderTime))
    int nextRenderTime;
    __declspec(property(get=Getwidth))
    unsigned int width;
    __declspec(property(get=Getheight))
    unsigned int height;
    __declspec(property(get=Getbpp))
    unsigned int bpp;
    __declspec(property(get=GetrefreshRate))
    unsigned int refreshRate;
    __declspec(property(get=Getfps100))
    unsigned int fps100;
    __declspec(property(get=GetcurrentTime))
    int currentTime;
    __declspec(property(get=GetfullScreen,put=PutfullScreen))
    int fullScreen;
    __declspec(property(get=GetbackColor,put=PutbackColor))
    unsigned int backColor;
    __declspec(property(get=GetredTone))
    IWzVector2DPtr redTone;
    __declspec(property(get=GetgreenBlueTone))
    IWzVector2DPtr greenBlueTone;
    __declspec(property(get=Getcenter))
    IWzVector2DPtr center;

    HRESULT Initialize (
        unsigned int uWidth,
        unsigned int uHeight,
        const Ztl_variant_t & vHwnd = vtEmpty,
        const Ztl_variant_t & vBPP = vtEmpty,
        const Ztl_variant_t & vRefreshRate = vtEmpty );
    HRESULT Uninitialize ( );
    int GetnextRenderTime ( );
    HRESULT UpdateCurrentTime (
        int tTime );
    HRESULT RenderFrame ( );
    HRESULT SetFrameSkip ( );
    HRESULT ToggleFpsPanel ( );
    HRESULT DisableFpsPanel ( );
    unsigned int Getwidth ( );
    unsigned int Getheight ( );
    unsigned int Getbpp ( );
    unsigned int GetrefreshRate ( );
    unsigned int Getfps100 ( );
    int GetcurrentTime ( );
    int GetfullScreen ( );
    void PutfullScreen (
        int pnFullScreen );
    unsigned int GetbackColor ( );
    void PutbackColor (
        unsigned int puColor );
    IWzVector2DPtr GetredTone ( );
    IWzVector2DPtr GetgreenBlueTone ( );
    IWzVector2DPtr Getcenter ( );
    HRESULT GetSnapshot (
        const Ztl_variant_t & pvBuffer,
        unsigned int uBufferSize,
        int x,
        int y );
    IWzGr2DLayerPtr CreateLayer (
        int nLeft,
        int nTop,
        unsigned int uWidth,
        unsigned int uHeight,
        int nZ,
        const Ztl_variant_t & vCanvas = vtEmpty,
        const Ztl_variant_t & dwFilter = vtEmpty );
    HRESULT InitializeFlashByDevice ( );
    HRESULT LoadMediaFile (
        LPSTR sSource );
    HRESULT SetFlashAbsLocation (
        int nX,
        int nY );
    HRESULT RenderFlash ( );
    HRESULT ReleaseFlash ( );
    int IsRenderFlash ( );
    HRESULT screenResolution (
        unsigned int uWidth,
        unsigned int uHeight );

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
    virtual HRESULT __stdcall put_screenResolution (
        /*[in]*/ unsigned int uWidth,
        /*[in]*/ unsigned int uHeight ) = 0;
};


inline HRESULT IWzGr2D_DX8::Initialize ( unsigned int uWidth, unsigned int uHeight, const Ztl_variant_t & vHwnd, const Ztl_variant_t & vBPP, const Ztl_variant_t & vRefreshRate ) {
    HRESULT _hr = raw_Initialize(uWidth, uHeight, vHwnd, vBPP, vRefreshRate);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _hr;
}

inline HRESULT IWzGr2D_DX8::Uninitialize ( ) {
    HRESULT _hr = raw_Uninitialize();
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _hr;
}

inline int IWzGr2D_DX8::GetnextRenderTime ( ) {
    int _result = 0;
    HRESULT _hr = get_nextRenderTime(&_result);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _result;
}

inline HRESULT IWzGr2D_DX8::UpdateCurrentTime ( int tTime ) {
    HRESULT _hr = raw_UpdateCurrentTime(tTime);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _hr;
}

inline HRESULT IWzGr2D_DX8::RenderFrame ( ) {
    HRESULT _hr = raw_RenderFrame();
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _hr;
}

inline HRESULT IWzGr2D_DX8::SetFrameSkip ( ) {
    HRESULT _hr = raw_SetFrameSkip();
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _hr;
}

inline HRESULT IWzGr2D_DX8::ToggleFpsPanel ( ) {
    HRESULT _hr = raw_ToggleFpsPanel();
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _hr;
}

inline HRESULT IWzGr2D_DX8::DisableFpsPanel ( ) {
    HRESULT _hr = raw_DisableFpsPanel();
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _hr;
}

inline unsigned int IWzGr2D_DX8::Getwidth ( ) {
    unsigned int _result = 0;
    HRESULT _hr = get_width(&_result);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _result;
}

inline unsigned int IWzGr2D_DX8::Getheight ( ) {
    unsigned int _result = 0;
    HRESULT _hr = get_height(&_result);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _result;
}

inline unsigned int IWzGr2D_DX8::Getbpp ( ) {
    unsigned int _result = 0;
    HRESULT _hr = get_bpp(&_result);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _result;
}

inline unsigned int IWzGr2D_DX8::GetrefreshRate ( ) {
    unsigned int _result = 0;
    HRESULT _hr = get_refreshRate(&_result);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _result;
}

inline unsigned int IWzGr2D_DX8::Getfps100 ( ) {
    unsigned int _result = 0;
    HRESULT _hr = get_fps100(&_result);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _result;
}

inline int IWzGr2D_DX8::GetcurrentTime ( ) {
    int _result = 0;
    HRESULT _hr = get_currentTime(&_result);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _result;
}

inline int IWzGr2D_DX8::GetfullScreen ( ) {
    int _result = 0;
    HRESULT _hr = get_fullScreen(&_result);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _result;
}

inline void IWzGr2D_DX8::PutfullScreen ( int pnFullScreen ) {
    HRESULT _hr = put_fullScreen(pnFullScreen);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
}

inline unsigned int IWzGr2D_DX8::GetbackColor ( ) {
    unsigned int _result = 0;
    HRESULT _hr = get_backColor(&_result);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _result;
}

inline void IWzGr2D_DX8::PutbackColor ( unsigned int puColor ) {
    HRESULT _hr = put_backColor(puColor);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
}

inline IWzVector2DPtr IWzGr2D_DX8::GetredTone ( ) {
    struct IWzVector2D * _result = 0;
    HRESULT _hr = get_redTone(&_result);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return IWzVector2DPtr(_result, false);
}

inline IWzVector2DPtr IWzGr2D_DX8::GetgreenBlueTone ( ) {
    struct IWzVector2D * _result = 0;
    HRESULT _hr = get_greenBlueTone(&_result);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return IWzVector2DPtr(_result, false);
}

inline IWzVector2DPtr IWzGr2D_DX8::Getcenter ( ) {
    struct IWzVector2D * _result = 0;
    HRESULT _hr = get_center(&_result);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return IWzVector2DPtr(_result, false);
}

inline HRESULT IWzGr2D_DX8::GetSnapshot ( const Ztl_variant_t & pvBuffer, unsigned int uBufferSize, int x, int y ) {
    HRESULT _hr = raw_GetSnapshot(pvBuffer, uBufferSize, x, y);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _hr;
}

inline IWzGr2DLayerPtr IWzGr2D_DX8::CreateLayer ( int nLeft, int nTop, unsigned int uWidth, unsigned int uHeight, int nZ, const Ztl_variant_t & vCanvas, const Ztl_variant_t & dwFilter ) {
    struct IWzGr2DLayer * _result = 0;
    HRESULT _hr = raw_CreateLayer(nLeft, nTop, uWidth, uHeight, nZ, vCanvas, dwFilter, &_result);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return IWzGr2DLayerPtr(_result, false);
}

inline HRESULT IWzGr2D_DX8::InitializeFlashByDevice ( ) {
    HRESULT _hr = raw_InitializeFlashByDevice();
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _hr;
}

inline HRESULT IWzGr2D_DX8::LoadMediaFile ( LPSTR sSource ) {
    HRESULT _hr = raw_LoadMediaFile(sSource);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _hr;
}

inline HRESULT IWzGr2D_DX8::SetFlashAbsLocation ( int nX, int nY ) {
    HRESULT _hr = raw_SetFlashAbsLocation(nX, nY);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _hr;
}

inline HRESULT IWzGr2D_DX8::RenderFlash ( ) {
    HRESULT _hr = raw_RenderFlash();
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _hr;
}

inline HRESULT IWzGr2D_DX8::ReleaseFlash ( ) {
    HRESULT _hr = raw_ReleaseFlash();
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _hr;
}

inline int IWzGr2D_DX8::IsRenderFlash ( ) {
    int _result = 0;
    HRESULT _hr = raw_IsRenderFlash(&_result);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _result;
}

inline HRESULT IWzGr2D_DX8::screenResolution ( unsigned int uWidth, unsigned int uHeight ) {
    HRESULT _hr = put_screenResolution(uWidth, uHeight);
    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
    return _hr;
}

#pragma pack(pop)
