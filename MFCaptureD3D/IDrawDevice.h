#pragma once

#include "MFCaptureD3D.h"

class IDrawDevice
{

public:

    virtual ~IDrawDevice() {}

    virtual HRESULT CreateDevice(HWND hwnd) = 0;
    virtual HRESULT ResetDevice() = 0;
    virtual void    DestroyDevice() = 0;

    virtual HRESULT SetVideoType(IMFMediaType* pType) = 0;
    virtual HRESULT DrawFrame(IMFMediaBuffer* pBuffer) = 0;

    // What video formats we accept
    virtual BOOL     IsFormatSupported(REFGUID subtype) const = 0;
    virtual HRESULT  GetFormat(DWORD index, GUID* pSubtype)  const = 0;
};