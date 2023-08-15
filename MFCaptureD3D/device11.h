#pragma once
#include "IDrawDevice.h"


class DrawDevice11 :
    public IDrawDevice
{

private:

    HWND                    m_hwnd;

    IDirect3D9* m_pD3D;
    IDirect3DDevice9* m_pDevice;
    IDirect3DSwapChain9* m_pSwapChain;

    D3DPRESENT_PARAMETERS   m_d3dpp;

    // Format information
    D3DFORMAT               m_format;
    UINT                    m_width;
    UINT                    m_height;
    LONG                    m_lDefaultStride;
    MFRatio                 m_PixelAR;
    MFVideoInterlaceMode    m_interlace;
    RECT                    m_rcDest;       // Destination rectangle

public:

    DrawDevice11();
    virtual ~DrawDevice11();

    HRESULT CreateDevice(HWND hwnd) override;
    HRESULT ResetDevice() override;
    void    DestroyDevice() override;

    HRESULT SetVideoType(IMFMediaType* pType) override;
    HRESULT DrawFrame(IMFMediaBuffer* pBuffer) override;

    // What video formats we accept
    BOOL     IsFormatSupported(REFGUID subtype) const override;
    HRESULT  GetFormat(DWORD index, GUID* pSubtype)  const override;
};

