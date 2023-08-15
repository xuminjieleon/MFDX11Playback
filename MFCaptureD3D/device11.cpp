#include "device11.h"

DrawDevice11::DrawDevice11() :
    m_hwnd(NULL),
    m_pD3D(NULL),
    m_pDevice(NULL),
    m_pSwapChain(NULL),
    m_format(D3DFMT_UNKNOWN),
    m_width(0),
    m_height(0),
    m_lDefaultStride(0),
    m_interlace(MFVideoInterlace_Unknown)
{
    m_PixelAR.Denominator = m_PixelAR.Numerator = 1;
}
