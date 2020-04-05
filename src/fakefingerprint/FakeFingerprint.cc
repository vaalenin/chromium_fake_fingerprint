#include "FakeFingerprint.h"
 
#include "base/pickle.h"

#include "base/memory/read_only_shared_memory_region.h"
#include "base/memory/writable_shared_memory_region.h"
#include "content/public/renderer/render_thread.h"

#include <vector>

#define NO_STD_OPTIONAL
#include <mysql++/mysql+++.h>

using namespace std;

struct PluginInfo
{
    string name;
    string filename;
    string description;
};

struct FakeFingerprintFields
{
    int id;
    string country;
    string deviceid;
    string source;
    string sysos;
    string build_id;
    std::string pluginsText;
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
    /*auto dataVect = this->OpenSharedMemory();
    if (!dataVect.empty())
    {
        this->readedField = std::make_unique <FakeFingerprintFields>();
        base::Pickle p(dataVect.data(), dataVect.size());
        base::PickleIterator pi(p);

        auto res = pi.ReadInt(&this->readedField->id);
        res = pi.ReadString(&this->readedField->country);
        res = pi.ReadString(&this->readedField->deviceid);
        res = pi.ReadString(&this->readedField->source);
        res = pi.ReadString(&this->readedField->sysos);
        res = pi.ReadString(&this->readedField->build_id);
        res = pi.ReadString(&this->readedField->pluginsText);
        res = pi.ReadString(&this->readedField->mime_types);
        res = pi.ReadString(&this->readedField->platform);
        res = pi.ReadString(&this->readedField->product_sub);
        res = pi.ReadString(&this->readedField->do_not_track);
        res = pi.ReadString(&this->readedField->screen_height);
        res = pi.ReadString(&this->readedField->screen_width);
        res = pi.ReadString(&this->readedField->avail_height);
        res = pi.ReadString(&this->readedField->avail_width);
        res = pi.ReadString(&this->readedField->os_cpu);
        res = pi.ReadString(&this->readedField->app_code_name);
        res = pi.ReadString(&this->readedField->app_name);
        res = pi.ReadString(&this->readedField->app_version);
        res = pi.ReadString(&this->readedField->user_agent);
        res = pi.ReadString(&this->readedField->concurrency);
        res = pi.ReadString(&this->readedField->product);
        res = pi.ReadString(&this->readedField->vendor);
        res = pi.ReadString(&this->readedField->vendor_sub);
        res = pi.ReadString(&this->readedField->inner_width);
        res = pi.ReadString(&this->readedField->inner_height);
        res = pi.ReadString(&this->readedField->navigator_language);
        res = pi.ReadString(&this->readedField->navigator_languages);
        res = pi.ReadString(&this->readedField->color_depth);
        res = pi.ReadString(&this->readedField->device_memory);
        res = pi.ReadString(&this->readedField->pixel_ratio);
        res = pi.ReadString(&this->readedField->timezone_offset);
        res = pi.ReadString(&this->readedField->session_storage);
        res = pi.ReadString(&this->readedField->local_storage);
        res = pi.ReadString(&this->readedField->indexed_db);
        res = pi.ReadString(&this->readedField->open_database);
        res = pi.ReadString(&this->readedField->cpu_class);
        res = pi.ReadString(&this->readedField->canvas);
        res = pi.ReadString(&this->readedField->webgl);
        res = pi.ReadString(&this->readedField->webgl_vendor);
        res = pi.ReadString(&this->readedField->adblock);
        res = pi.ReadString(&this->readedField->has_lied_languages);
        res = pi.ReadString(&this->readedField->has_lied_resolution);
        res = pi.ReadString(&this->readedField->has_lied_os);
        res = pi.ReadString(&this->readedField->has_lied_browser);
        res = pi.ReadString(&this->readedField->touch_support);
        res = pi.ReadString(&this->readedField->js_fonts);
        res = pi.ReadString(&this->readedField->ip);

        this->currentField = this->readedField.get();

        return;
    }*/

    this->conn = std::make_unique <daotk::mysql::connection> ("144.202.25.57", "lp_zill_xyz", "Axpsk2w34pTkYDa5", "lp_zill_xyz");
    if ((*this->conn))
        this->isEnabled = true;

    if (!this->isEnabled)
    {
        file.open("d:\\tmp.db", std::ios::app);
        file << "OpenSharedMemory" << std::endl;
        file.close();
        this->OpenSharedMemory();
        return;
    }

   // this->file.open("tmp.db");
    //file.open("d:\\tmp.db");
    //base::Pickle p;
    this->conn->query("SELECT id, country, deviceid, source, sysos, build_id, `plugins`, mime_types, platform, product_sub, do_not_track, \
                     screen_height, screen_width, avail_height, avail_width, \
                     os_cpu, app_code_name, app_name, app_version, user_agent, concurrency, product, vendor, vendor_sub, \
                     inner_width, inner_height, navigator_language, navigator_languages, color_depth, device_memory, pixel_ratio, \
                     timezone_offset, session_storage, local_storage, indexed_db, open_database, cpu_class, canvas, webgl, webgl_vendor, \
                     adblock, has_lied_languages, has_lied_resolution, has_lied_os, has_lied_browser, touch_support, js_fonts, ip FROM info")
    .each([&](int id, string country, string deviceid, string source, string sysos, string build_id, string plugins, string mime_types, string platform, string product_sub, string do_not_track, string screen_height, string screen_width, string avail_height, string avail_width, string os_cpu, string app_code_name, string app_name, string app_version, string user_agent, string concurrency, string product, string vendor, string vendor_sub, string inner_width, string inner_height, string navigator_language, string navigator_languages, string color_depth, string device_memory, string pixel_ratio, string timezone_offset, string session_storage, string local_storage, string indexed_db, string open_database, string cpu_class, string canvas, string webgl, string webgl_vendor, string adblock, string has_lied_languages, string has_lied_resolution, string has_lied_os, string has_lied_browser, string touch_support, string js_fonts, string ip)
    {
        std::string glVendor, glRenderer;
        if (!webgl_vendor.empty())
        {
            glVendor = webgl_vendor.substr(0, webgl_vendor.find('~'));
            glRenderer = webgl_vendor.substr(glVendor.length() + 1);
        }

        //file << id << ", " << country << ", " << deviceid << ", " << source << ", " << sysos << ", " << build_id << ", " << plugins << ", " << mime_types << ", " << platform << ", " << product_sub << ", " << do_not_track << ", " << screen_height << ", " << screen_width << ", " << avail_height << ", " << avail_width << ", " << os_cpu << ", " << app_code_name << ", " << app_name << ", " << app_version << ", " << user_agent << ", " << concurrency << ", " << product << ", " << vendor << ", " << vendor_sub << ", " << inner_width << ", " << inner_height << ", " << navigator_language << ", " << navigator_languages << ", " << color_depth << ", " << device_memory << ", " << pixel_ratio << ", " << timezone_offset << ", " << session_storage << ", " << local_storage << ", " << indexed_db << ", " << open_database << ", " << cpu_class << ", " << canvas << ", " << glRenderer << ", " << glVendor << ", " << adblock << ", " << has_lied_languages << ", " << has_lied_resolution << ", " << has_lied_os << ", " << has_lied_browser << ", " << touch_support << ", " << js_fonts << ", " << ip;
        
        std::vector <PluginInfo> pluginsVec;
        this->fields.emplace_back(FakeFingerprintFields{ id, country, deviceid, source, sysos, build_id, plugins, pluginsVec, mime_types, platform, product_sub, do_not_track, screen_height, screen_width, avail_height, avail_width, os_cpu, app_code_name, app_name, app_version, user_agent, concurrency, product, vendor, vendor_sub, inner_width, inner_height, navigator_language, navigator_languages, color_depth, device_memory, pixel_ratio, timezone_offset, session_storage, local_storage, indexed_db, open_database, cpu_class, canvas, glRenderer, glVendor, adblock, has_lied_languages, has_lied_resolution, has_lied_os, has_lied_browser, touch_support, js_fonts, ip });
        return true;
    });

    //this->CreateSharedMemory(L"FFData", p.size(), p.data());
   // file.write((const char*)p.data(), p.size());

    //file.close();

    srand(time(nullptr));

    this->conn->close();
    this->conn.reset();
    this->currentField = &this->fields[rand() % this->fields.size()];

    base::Pickle p;
    p.WriteInt(this->currentField->id);
    p.WriteString(this->currentField->country);
    p.WriteString(this->currentField->deviceid);
    p.WriteString(this->currentField->source);
    p.WriteString(this->currentField->sysos);
    p.WriteString(this->currentField->build_id);
    p.WriteString(this->currentField->pluginsText);
    p.WriteString(this->currentField->mime_types);
    p.WriteString(this->currentField->platform);
    p.WriteString(this->currentField->product_sub);
    p.WriteString(this->currentField->do_not_track);
    p.WriteString(this->currentField->screen_height);
    p.WriteString(this->currentField->screen_width);
    p.WriteString(this->currentField->avail_height);
    p.WriteString(this->currentField->avail_width);
    p.WriteString(this->currentField->os_cpu);
    p.WriteString(this->currentField->app_code_name);
    p.WriteString(this->currentField->app_name);
    p.WriteString(this->currentField->app_version);
    p.WriteString(this->currentField->user_agent);
    p.WriteString(this->currentField->concurrency);
    p.WriteString(this->currentField->product);
    p.WriteString(this->currentField->vendor);
    p.WriteString(this->currentField->vendor_sub);
    p.WriteString(this->currentField->inner_width);
    p.WriteString(this->currentField->inner_height);
    p.WriteString(this->currentField->navigator_language);
    p.WriteString(this->currentField->navigator_languages);
    p.WriteString(this->currentField->color_depth);
    p.WriteString(this->currentField->device_memory);
    p.WriteString(this->currentField->pixel_ratio);
    p.WriteString(this->currentField->timezone_offset);
    p.WriteString(this->currentField->session_storage);
    p.WriteString(this->currentField->local_storage);
    p.WriteString(this->currentField->indexed_db);
    p.WriteString(this->currentField->open_database);
    p.WriteString(this->currentField->cpu_class);
    p.WriteString(this->currentField->canvas);
    p.WriteString(this->currentField->webgl);
    p.WriteString(this->currentField->webgl_vendor);
    p.WriteString(this->currentField->adblock);
    p.WriteString(this->currentField->has_lied_languages);
    p.WriteString(this->currentField->has_lied_resolution);
    p.WriteString(this->currentField->has_lied_os);
    p.WriteString(this->currentField->has_lied_browser);
    p.WriteString(this->currentField->touch_support);
    p.WriteString(this->currentField->js_fonts);
    p.WriteString(this->currentField->ip);

    this->CreateSharedMemory(p.data(), p.size());

    std::string s1, s2;
    //auto* render = content::RenderThread::Get();
    //render->Send(new FrameHostMsg_GetFFparam(render->GetRoutingID(), s1, s2));
    /*file.open("d:\\tmp.db", std::ios::app);
    file << "CreateSharedMemory" << std::endl;
    file.write((const char*)p.data(), p.size());
    file.close();*/

    
}

FakeFingerprint::~FakeFingerprint()
{

}

void FakeFingerprint::Ping(PingCallback callback)
{
    std::move(callback).Run(4);
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

const std::vector <PluginInfo>& FakeFingerprint::GetPlugins() const
{
    return this->currentField->plugins;
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

int FakeFingerprint::GetScreenHeight() const
{
    return std::stoi (this->currentField->screen_height);
}

int FakeFingerprint::GetScreenWidth() const
{
    return std::stoi(this->currentField->screen_width);
}

int FakeFingerprint::GetAvailHeight() const
{
    return std::stoi(this->currentField->avail_height);
}

int FakeFingerprint::GetAvailWidth() const
{
    return std::stoi(this->currentField->avail_width);
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

unsigned FakeFingerprint::GetConcurrency() const
{
    return std::stoul (this->currentField->concurrency);
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

int FakeFingerprint::GetInnerWidth() const
{
    return std::stoi(this->currentField->inner_width);
}

int FakeFingerprint::GetInnerHeight() const
{
    return std::stoi(this->currentField->inner_height);
}

std::string FakeFingerprint::GetNavigatorLanguage() const
{
    return this->currentField->navigator_language;
}

std::string FakeFingerprint::GetNavigatorLanguages() const
{
    return this->currentField->navigator_languages;
}

int FakeFingerprint::GetColorDepth() const
{
    return std::stoi(this->currentField->color_depth);
}

int FakeFingerprint::GetDeviceMemory() const
{
    return std::stoi(this->currentField->device_memory);
}

std::string FakeFingerprint::GetPixelRatio() const
{
    return this->currentField->pixel_ratio;
}

int FakeFingerprint::GetTimezoneOffset() const
{
    return std::stoi (this->currentField->timezone_offset);
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

struct SystemSharedData
{
    size_t size;
    char data[5000];
};

bool FakeFingerprint::CreateSharedMemory(const void* data, size_t size)
{
    DLOG(INFO) << "FakeFingerprint::CreateSharedMemory";

    this->receiver = ping_responder.BindNewPipeAndPassReceiver();

    auto mappedRegion = base::ReadOnlySharedMemoryRegion::Create(sizeof(SystemSharedData));
    CHECK(mappedRegion.IsValid());
    sharedMemoryRegion = std::move(mappedRegion.region);
    sharedMemoryMapping = std::move(mappedRegion.mapping);

    void* mem = sharedMemoryMapping.memory();
    DCHECK(mem);
    buffer = new (mem) SystemSharedData();
    
     
    if (data)
    {
        memset(&(buffer->data), 0, 5000);
        memcpy(&(buffer->data), data, size);
        buffer->size = size;
    }

   // GetSharedMemory (this->sharedMemoryRegion.Duplicate());
    /*SECURITY_ATTRIBUTES sa = { sizeof(sa), nullptr, FALSE };
    HANDLE sysRawHandle = CreateFileMapping(INVALID_HANDLE_VALUE, &sa, PAGE_READWRITE, 0, sizeof (SystemSharedData), L"SystemSharedData");
    if (!sysRawHandle)
    {
        auto err = GetLastError();
        DLOG(ERROR) << err;
        return {};
    }
    base::win::ScopedHandle sysHandle(sysRawHandle);

    static base::WritableSharedMemoryRegion sysSharedRegion = base::WritableSharedMemoryRegion::Deserialize(base::subtle::PlatformSharedMemoryRegion::Take(std::move(sysHandle), base::subtle::PlatformSharedMemoryRegion::Mode::kWritable, sizeof(SystemSharedData), base::UnguessableToken::Create()));
    if (!sysSharedRegion.IsValid())
        return false;

    auto sysMap = sysSharedRegion.Map();
    memset(sysMap.memory(), 0, sizeof(SystemSharedData));
    auto* sysSharedData = sysMap.GetMemoryAs<SystemSharedData>();
    sysSharedData->size = size;

    HANDLE rawHandle = CreateFileMapping(INVALID_HANDLE_VALUE, &sa, PAGE_READWRITE, 0, static_cast<DWORD>(size), name.c_str());

    base::win::ScopedHandle handle(rawHandle);

    static base::WritableSharedMemoryRegion sharedRegion = base::WritableSharedMemoryRegion::Deserialize(base::subtle::PlatformSharedMemoryRegion::Take(std::move(handle), base::subtle::PlatformSharedMemoryRegion::Mode::kWritable, size, base::UnguessableToken::Create()));
    if (!sharedRegion.IsValid())
        return false;
    
    auto mapping = sharedRegion.Map();
    if (!mapping.IsValid())
        return false;

    memset(mapping.memory(), 0, size);
    memcpy(mapping.memory(), data, size);*/

    return true;
}

void  OnPong(int32_t r)
{

}

void FakeFingerprint::OpenSharedMemory()
{
    DLOG(INFO) << "FakeFingerprint::OpenSharedMemory";

    this->receiver = ping_responder.BindNewPipeAndPassReceiver();
    ping_responder->Ping(base::BindOnce(&OnPong));

    //this->CreateSharedMemory();
    /*this->sharedMemoryRegionRO = this->sharedMemoryRegion.Duplicate();
    this->sharedMemoryMappingRO = this->sharedMemoryRegionRO.Map();

    void* mem = sharedMemoryMapping.memory();
    DCHECK(mem);

    SystemSharedData* buffer = (SystemSharedData*) mem;

    std::vector <char> data;
    data.resize(buffer->size);
    memcpy(data.data(), buffer->data, buffer->size);*/

    //auto region = WritableSharedMemoryRegion::Create(sizeof(SystemSharedData));
    //auto mapping = region.Map();
    //if (!mapping.IsValid())
    //    return base::ScopedFD();
    //memcpy(mapping.memory(), data.data(), data.size());
    //
    //return base::WritableSharedMemoryRegion::TakeHandleForSerialization(std::move(region)).PassPlatformHandle().readonly_fd;

    //DWORD access = FILE_MAP_READ;
    //HANDLE sysRawHandle = OpenFileMapping(access, FALSE, L"SystemSharedData");

    //if (!sysRawHandle)
    //{
    //    auto err = GetLastError();
    //    DLOG(ERROR) << err;
    //    return {};
    //}

    //// The region is writable for this user, so the handle is converted to a
    //// WritableSharedMemoryMapping which is then downgraded to read-only for the
    //// mapping.
    //auto sysRegion = base::WritableSharedMemoryRegion::Deserialize(base::subtle::PlatformSharedMemoryRegion::Take(base::win::ScopedHandle(sysRawHandle), base::subtle::PlatformSharedMemoryRegion::Mode::kWritable, sizeof(SystemSharedData), base::UnguessableToken::Create()));
    //if (!sysRegion.IsValid())
    //{
    //    DLOG(ERROR) << "Unable to deserialize raw file mapping handle to "
    //        << "WritableSharedMemoryRegion";
    //    return {};
    //}
    //auto readonlySysRegion = base::WritableSharedMemoryRegion::ConvertToReadOnly(std::move(sysRegion));

    //if (!readonlySysRegion.IsValid())
    //{
    //    DLOG(ERROR) << "Unable to convert to read-only region";
    //    return {};
    //}
    //base::ReadOnlySharedMemoryMapping sysMapping = readonlySysRegion.Map();
    //if (!sysMapping.IsValid())
    //{
    //    DLOG(ERROR) << "Unable to map region";
    //    return {};
    //}

    //const auto* sysSharedData = sysMapping.GetMemoryAs<SystemSharedData>();

    //auto size = sysSharedData->size;

    //HANDLE rawHandle = OpenFileMapping(access, false, name.c_str());
    //auto region = base::WritableSharedMemoryRegion::Deserialize(base::subtle::PlatformSharedMemoryRegion::Take(base::win::ScopedHandle(rawHandle), base::subtle::PlatformSharedMemoryRegion::Mode::kWritable, size, base::UnguessableToken::Create()));
    //auto readonlyRegion = base::WritableSharedMemoryRegion::ConvertToReadOnly(std::move(region));

    //if (!readonlyRegion.IsValid())
    //{
    //    DLOG(ERROR) << "Unable to convert to read-only region";
    //    return {};
    //}
    //auto mapping = readonlyRegion.Map();
    //if (!mapping.IsValid())
    //{
    //    DLOG(ERROR) << "Unable to map region";
    //    return {};
    //}

    //std::vector <char> data;
    //data.resize(size);
    //memcpy(data.data(), mapping.memory(), size);

    //return data;

    // The region will be closed on return, leaving on the mapping.
}