#pragma once

#include <memory>
#define NO_STD_OPTIONAL
#define NDEBUG
#include "mysql++/mysql+++.h"

struct FakeFingerprintFields;

class FakeFingerprint
{
public:
    static const FakeFingerprint& Instance();

    bool IsEnabled() const;

    std::string GetCountry() const;
    std::string GetDeviceID() const;
    std::string GetSource() const;
    std::string GetSysOS() const;
    std::string GetSBuildID() const;
    std::string GetPlugins() const;
    std::string GetMIMETypes() const;
    std::string GetPlatform() const;//1
    std::string GetProductSub() const;//1
    std::string GetDoNotTrack() const;
    std::string GetScreenHeight() const;
    std::string GetScreenWidth() const;
    std::string GetAvailHeight() const;
    std::string GetAvailWidth() const;
    std::string GetOSCPU() const;
    std::string GetAppCodeName() const;//1
    std::string GetAppName() const;//1
    std::string GetAppVersion() const; //1
    std::string GetUserAgent() const; //1
    std::string GetConcurrency() const;
    std::string GetProduct() const;//1
    std::string GetVendor() const;//1
    std::string GetVendorSub() const;//1
    std::string GetInnerWidth() const;
    std::string GetInnerHeight() const;
    std::string GetNavigatorLanguage() const;
    std::string GetNavigatorLanguages() const;
    std::string GetColorDepth() const;
    std::string GetDeviceMemory() const;
    std::string GetPixelRatio() const;
    std::string GetTimezoneOffset() const;
    std::string GetSessionStorage() const;
    std::string GetLocalStorage() const;
    std::string GetIndexedDB() const;
    std::string GetOpenDatabase() const;
    std::string GetCPUClass() const;
    std::string GetCanvas() const;
    std::string GetWebGL() const;
    std::string GetWebGLVendor() const;
    std::string GetADBlock() const;
    std::string GetHasLiedLanguages() const;
    std::string GetHasLiedResolution() const;
    std::string GetHasLiedOS() const;
    std::string GetHasLiedBrowser() const;
    std::string GetTouchSupport() const;
    std::string GetJSFonts() const;
    std::string GetIP() const;

    operator bool() const;
private:
    FakeFingerprint();
    virtual ~FakeFingerprint();

    std::vector <FakeFingerprintFields> fields;
    std::unique_ptr <daotk::mysql::connection> conn;

    bool isEnabled = false;

    FakeFingerprintFields* currentField = nullptr;
};

