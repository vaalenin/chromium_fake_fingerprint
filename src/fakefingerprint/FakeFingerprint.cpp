#include "FakeFingerprint.h"

#define NO_STD_OPTIONAL
#include <mysql++/mysql+++.h>

using namespace std;

struct FakeFingerprintFields
{
    int id;
    string country;
    string deviceid;
    string source;
    string sysos;
    string build_id;
    string plugins;
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
    string app_version;
    string user_agent;
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

FakeFingerprint & FakeFingerprint::Instance()
{
    static FakeFingerprint ff;
    return ff;
}

FakeFingerprint::FakeFingerprint()
{
    this->conn = std::make_unique <daotk::mysql::connection> ("144.202.25.57", "lp_zill_xyz", "Axpsk2w34pTkYDa5", "lp_zill_xyz");

    this->conn->query("SELECT id, country, deviceid, source, sysos, build_id, `plugins`, mime_types, platform, product_sub, do_not_track, \
                     screen_height, screen_width, avail_height, avail_width, \
                     os_cpu, app_code_name, app_name, app_version, user_agent, concurrency, product, vendor, vendor_sub, \
                     inner_width, inner_height, navigator_language, navigator_languages, color_depth, device_memory, pixel_ratio, \
                     timezone_offset, session_storage, local_storage, indexed_db, open_database, cpu_class, canvas, webgl, webgl_vendor, \
                     adblock, has_lied_languages, has_lied_resolution, has_lied_os, has_lied_browser, touch_support, js_fonts, ip FROM info")
    .each([&](int id, string country, string deviceid, string source, string sysos, string build_id, string plugins, string mime_types, string platform, string product_sub, string do_not_track, string screen_height, string screen_width, string avail_height, string avail_width, string os_cpu, string app_code_name, string app_name, string app_version, string user_agent, string concurrency, string product, string vendor, string vendor_sub, string inner_width, string inner_height, string navigator_language, string navigator_languages, string color_depth, string device_memory, string pixel_ratio, string timezone_offset, string session_storage, string local_storage, string indexed_db, string open_database, string cpu_class, string canvas, string webgl, string webgl_vendor, string adblock, string has_lied_languages, string has_lied_resolution, string has_lied_os, string has_lied_browser, string touch_support, string js_fonts, string ip)
    {
        this->fields.emplace_back(FakeFingerprintFields{ id, country, deviceid, source, sysos, build_id, plugins, mime_types, platform, product_sub, do_not_track, screen_height, screen_width, avail_height, avail_width, os_cpu, app_code_name, app_name, app_version, user_agent, concurrency, product, vendor, vendor_sub, inner_width, inner_height, navigator_language, navigator_languages, color_depth, device_memory, pixel_ratio, timezone_offset, session_storage, local_storage, indexed_db, open_database, cpu_class, canvas, webgl, webgl_vendor, adblock, has_lied_languages, has_lied_resolution, has_lied_os, has_lied_browser, touch_support, js_fonts, ip });
        return true;
    });

}


FakeFingerprint::~FakeFingerprint()
{
}
