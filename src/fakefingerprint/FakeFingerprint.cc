#include "FakeFingerprint.h"

#define NO_STD_OPTIONAL
#include <mysql++/mysql+++.h>

using namespace std;

struct FakeFingerprintFields
{
    struct PluginInfo
    {
        string name;
        string filename;
        string description;
    };
    int id;
    string country;
    string deviceid;
    string source;
    string sysos;
    string build_id;
    vector <PluginInfo> plugins;
    string mime_types;
    string platform;
    string product_sub;
    string do_not_track;
    string screen_height;
    string screen_width;
    string avail_height;
    string avail_width;
    string os_cpu;
    string app_code_name;
    string app_name;
    string app_version; //1
    string user_agent; //1
    string concurrency;
    string product;
    string vendor;
    string vendor_sub;
    string inner_width;
    string inner_height;
    string navigator_language;
    string navigator_languages;
    string color_depth;
    string device_memory;
    string pixel_ratio;
    string timezone_offset;
    string session_storage;
    string local_storage;
    string indexed_db;
    string open_database;
    string cpu_class;
    string canvas;
    string webgl;
    string webgl_vendor;
    string adblock;
    string has_lied_languages;
    string has_lied_resolution;
    string has_lied_os;
    string has_lied_browser;
    string touch_support;
    string js_fonts;
    string ip;
};

const FakeFingerprint& FakeFingerprint::Instance()
{
    static FakeFingerprint ff;
    return ff;
}

bool FakeFingerprint::IsEnabled() const
{
    return this->isEnabled;
}

FakeFingerprint::FakeFingerprint()
{
    this->conn = std::make_unique <daotk::mysql::connection> ("144.202.25.57", "lp_zill_xyz", "Axpsk2w34pTkYDa5", "lp_zill_xyz");
    if ((*this->conn))
        this->isEnabled = true;

    if (!this->isEnabled)
        return;

    this->conn->query("SELECT id, country, deviceid, source, sysos, build_id, `plugins`, mime_types, platform, product_sub, do_not_track, \
                     screen_height, screen_width, avail_height, avail_width, \
                     os_cpu, app_code_name, app_name, app_version, user_agent, concurrency, product, vendor, vendor_sub, \
                     inner_width, inner_height, navigator_language, navigator_languages, color_depth, device_memory, pixel_ratio, \
                     timezone_offset, session_storage, local_storage, indexed_db, open_database, cpu_class, canvas, webgl, webgl_vendor, \
                     adblock, has_lied_languages, has_lied_resolution, has_lied_os, has_lied_browser, touch_support, js_fonts, ip FROM info")
    .each([&](int id, string country, string deviceid, string source, string sysos, string build_id, string plugins, string mime_types, string platform, string product_sub, string do_not_track, string screen_height, string screen_width, string avail_height, string avail_width, string os_cpu, string app_code_name, string app_name, string app_version, string user_agent, string concurrency, string product, string vendor, string vendor_sub, string inner_width, string inner_height, string navigator_language, string navigator_languages, string color_depth, string device_memory, string pixel_ratio, string timezone_offset, string session_storage, string local_storage, string indexed_db, string open_database, string cpu_class, string canvas, string webgl, string webgl_vendor, string adblock, string has_lied_languages, string has_lied_resolution, string has_lied_os, string has_lied_browser, string touch_support, string js_fonts, string ip)
    {
        //this->fields.emplace_back(FakeFingerprintFields{ id, country, deviceid, source, sysos, build_id, plugins, mime_types, platform, product_sub, do_not_track, screen_height, screen_width, avail_height, avail_width, os_cpu, app_code_name, app_name, app_version, user_agent, concurrency, product, vendor, vendor_sub, inner_width, inner_height, navigator_language, navigator_languages, color_depth, device_memory, pixel_ratio, timezone_offset, session_storage, local_storage, indexed_db, open_database, cpu_class, canvas, webgl, webgl_vendor, adblock, has_lied_languages, has_lied_resolution, has_lied_os, has_lied_browser, touch_support, js_fonts, ip });
        return true;
    });

    srand(time(nullptr));

    this->currentField = &this->fields[rand() % this->fields.size()];
}

FakeFingerprint::~FakeFingerprint()
{
}

std::string FakeFingerprint::GetCountry() const
{
    return this->currentField->country;
}

std::string FakeFingerprint::GetDeviceID() const
{
    return this->currentField->deviceid;
}

std::string FakeFingerprint::GetSource() const
{
    return this->currentField->source;
}

std::string FakeFingerprint::GetSysOS() const
{
    return this->currentField->sysos;
}

std::string FakeFingerprint::GetSBuildID() const
{
    return this->currentField->build_id;
}

std::string FakeFingerprint::GetPlugins() const
{
    return "";// this->currentField->plugins;
}

std::string FakeFingerprint::GetMIMETypes() const
{
    return this->currentField->mime_types;
}

std::string FakeFingerprint::GetPlatform() const
{
    return this->currentField->platform;
}

std::string FakeFingerprint::GetProductSub() const
{
    return this->currentField->product_sub;
}

std::string FakeFingerprint::GetDoNotTrack() const
{
    return this->currentField->do_not_track;
}

std::string FakeFingerprint::GetScreenHeight() const
{
    return this->currentField->screen_height;
}

std::string FakeFingerprint::GetScreenWidth() const
{
    return this->currentField->screen_width;
}

std::string FakeFingerprint::GetAvailHeight() const
{
    return this->currentField->avail_height;
}

std::string FakeFingerprint::GetAvailWidth() const
{
    return this->currentField->avail_width;
}

std::string FakeFingerprint::GetOSCPU() const
{
    return this->currentField->os_cpu;
}

std::string FakeFingerprint::GetAppCodeName() const
{
    return this->currentField->app_code_name;
}

std::string FakeFingerprint::GetAppName() const
{
    return this->currentField->app_name;
}

std::string FakeFingerprint::GetAppVersion() const
{
    return this->currentField->app_version;
}

std::string FakeFingerprint::GetUserAgent() const
{
    return this->currentField->user_agent;
}

std::string FakeFingerprint::GetConcurrency() const
{
    return this->currentField->concurrency;
}

std::string FakeFingerprint::GetProduct() const
{
    return this->currentField->product;
}

std::string FakeFingerprint::GetVendor() const
{
    return this->currentField->vendor;
}

std::string FakeFingerprint::GetVendorSub() const
{
    return this->currentField->vendor_sub;
}

std::string FakeFingerprint::GetInnerWidth() const
{
    return this->currentField->inner_width;
}

std::string FakeFingerprint::GetInnerHeight() const
{
    return this->currentField->inner_height;
}

std::string FakeFingerprint::GetNavigatorLanguage() const
{
    return this->currentField->navigator_language;
}

std::string FakeFingerprint::GetNavigatorLanguages() const
{
    return this->currentField->navigator_languages;
}

std::string FakeFingerprint::GetColorDepth() const
{
    return this->currentField->color_depth;
}

std::string FakeFingerprint::GetDeviceMemory() const
{
    return this->currentField->device_memory;
}

std::string FakeFingerprint::GetPixelRatio() const
{
    return this->currentField->pixel_ratio;
}

std::string FakeFingerprint::GetTimezoneOffset() const
{
    return this->currentField->timezone_offset;
}

std::string FakeFingerprint::GetSessionStorage() const
{
    return this->currentField->session_storage;
}

std::string FakeFingerprint::GetLocalStorage() const
{
    return this->currentField->local_storage;
}

std::string FakeFingerprint::GetIndexedDB() const
{
    return this->currentField->indexed_db;
}

std::string FakeFingerprint::GetOpenDatabase() const
{
    return this->currentField->open_database;
}

std::string FakeFingerprint::GetCPUClass() const
{
    return this->currentField->cpu_class;
}

std::string FakeFingerprint::GetCanvas() const
{
    return this->currentField->canvas;
}

std::string FakeFingerprint::GetWebGL() const
{
    return this->currentField->webgl;
}

std::string FakeFingerprint::GetWebGLVendor() const
{
    return this->currentField->webgl_vendor;
}

std::string FakeFingerprint::GetADBlock() const
{
    return this->currentField->adblock;
}

std::string FakeFingerprint::GetHasLiedLanguages() const
{
    return this->currentField->has_lied_languages;
}

std::string FakeFingerprint::GetHasLiedResolution() const
{
    return this->currentField->has_lied_resolution;
}

std::string FakeFingerprint::GetHasLiedOS() const
{
    return this->currentField->has_lied_os;
}

std::string FakeFingerprint::GetHasLiedBrowser() const
{
    return this->currentField->has_lied_browser;
}

std::string FakeFingerprint::GetTouchSupport() const
{
    return this->currentField->touch_support;
}

std::string FakeFingerprint::GetJSFonts() const
{
    return this->currentField->js_fonts;
}

std::string FakeFingerprint::GetIP() const
{
    return this->currentField->ip;
}

FakeFingerprint::operator bool() const
{
    return this->IsEnabled ();
}
