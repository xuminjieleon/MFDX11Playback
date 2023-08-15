#pragma once

#include <iostream>
#include "mfidl.h"
#include "mfapi.h"


class Enumrator
{
public:
    HRESULT EnumDeviceName(bool video);
    void DebugShowDeviceNames(IMFActivate** ppDevices, UINT count, bool video);
};

