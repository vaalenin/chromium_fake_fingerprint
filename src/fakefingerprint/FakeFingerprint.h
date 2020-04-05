#pragma once
#ifndef FAKEFINGERPRINT_H_
#define FAKEFINGERPRINT_H_

#include <memory>
#include <fstream>
#define NO_STD_OPTIONAL
#define NDEBUG
#include "mysql++/mysql+++.h"

#include "base/memory/read_only_shared_memory_region.h"
#include "content/public/renderer/render_thread.h"
#include "fakefingerprint/public/mojom/FakeFingerprint.mojom.h"
#include "FakeFingerprint_messages.h"

struct SystemSharedData;
struct FakeFingerprintFields;
struct PluginInfo;
class FakeFingerprint: public device::mojom::FakeFingerprintSharedMemory
{
public:
    static const FakeFingerprint& Instance();

    bool IsEnabled() const;

    std::string GetCountry() const;
    std::string GetDeviceID() const;
    std::string GetSource() const;
    std::string GetSysOS() const;
    std::string GetSBuildID() const;
    const std::vector <PluginInfo>& GetPlugins() const;
    std::string GetMIMETypes() const;
    std::string GetPlatform() const;//1
    std::string GetProductSub() const;//1
    std::string GetDoNotTrack() const;//1
    int GetScreenHeight() const; //1
    int GetScreenWidth() const; //1
    int GetAvailHeight() const;//1
    int GetAvailWidth() const;//1
    std::string GetOSCPU() const;
    std::string GetAppCodeName() const;//1
    std::string GetAppName() const;//1
    std::string GetAppVersion() const; //1
    std::string GetUserAgent() const; //1
    unsigned GetConcurrency() const;//1
    std::string GetProduct() const;//1
    std::string GetVendor() const;//1
    std::string GetVendorSub() const;//1
    int GetInnerWidth() const;
    int GetInnerHeight() const;
    std::string GetNavigatorLanguage() const;
    std::string GetNavigatorLanguages() const;
    int GetColorDepth() const;//1
    int GetDeviceMemory() const;//1
    std::string GetPixelRatio() const;
    int GetTimezoneOffset() const;//1
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

   // void GetSharedMemory(::base::ReadOnlySharedMemoryRegion memoryRegion) override;
    void Ping(PingCallback callback) override;
    //void  OnPong(int32_t r);

    operator bool() const;
private:
    FakeFingerprint();
    ~FakeFingerprint() override;

    std::vector <FakeFingerprintFields> fields;
    std::unique_ptr <daotk::mysql::connection> conn;

    bool isEnabled = false;

    FakeFingerprintFields* currentField = nullptr;
    std::unique_ptr<FakeFingerprintFields> readedField;

    base::ReadOnlySharedMemoryRegion sharedMemoryRegion, sharedMemoryRegionRO;
    base::WritableSharedMemoryMapping sharedMemoryMapping;
    base::ReadOnlySharedMemoryMapping sharedMemoryMappingRO;
    SystemSharedData* buffer;

    std::ofstream file;

    bool CreateSharedMemory(const void* data = nullptr, size_t size = 0);
    void OpenSharedMemory();

    mojo::Remote <device::mojom::FakeFingerprintSharedMemory> ping_responder;
    mojo::PendingReceiver <device::mojom::FakeFingerprintSharedMemory> receiver;
};

#endif