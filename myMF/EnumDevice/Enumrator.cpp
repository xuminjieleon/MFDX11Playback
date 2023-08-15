#include "Enumrator.h"
#include "mferror.h"

HRESULT Enumrator::EnumDeviceName(bool video)
{
    CoInitializeEx(NULL, COINIT_MULTITHREADED);

    UINT32 count = 0;

    IMFAttributes* pConfig = NULL;
    IMFActivate** ppDevices = NULL;

    // Create an attribute store to hold the search criteria.
    HRESULT hr = MFCreateAttributes(&pConfig, 1);

    // Request video capture devices.
    if (SUCCEEDED(hr))
    {
        hr = pConfig->SetGUID(
            MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE,
            video ? MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID : MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_AUDCAP_GUID
        );
    }

    // Enumerate the devices,
    if (SUCCEEDED(hr))
    {
        hr = MFEnumDeviceSources(pConfig, &ppDevices, &count);
    }

    if (SUCCEEDED(hr))
    {
        DebugShowDeviceNames(ppDevices, count, video);
    }

    for (DWORD i = 0; i < count; i++)
    {
        ppDevices[i]->Release();
    }
    CoTaskMemFree(ppDevices);
    CoUninitialize();
    return hr;
}

void Enumrator::DebugShowDeviceNames(IMFActivate** ppDevices, UINT count, bool video)
{
    for (DWORD i = 0; i < count; i++)
    {
        HRESULT hr = S_OK;
        WCHAR* szFriendlyName = NULL;
        WCHAR* szID = NULL;

        // Try to get the display name.
        UINT32 cchName;
        hr = ppDevices[i]->GetAllocatedString(
            MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME,
            &szFriendlyName, &cchName);

        hr = ppDevices[i]->GetAllocatedString(
            video ? MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK : MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_AUDCAP_SYMBOLIC_LINK,
            &szID, &cchName);

        if (SUCCEEDED(hr))
        {
            std::wcout << szFriendlyName << " : " << szID << std::endl;
        }
        CoTaskMemFree(szFriendlyName);
        CoTaskMemFree(szID);
    }
}