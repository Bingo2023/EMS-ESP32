#include <SystemStatus.h>

#include "../../src/emsesp_stub.hpp" // proddy added

using namespace std::placeholders; // for `_1` etc

SystemStatus::SystemStatus(AsyncWebServer * server, SecurityManager * securityManager) {
    server->on(SYSTEM_STATUS_SERVICE_PATH,
               HTTP_GET,
               securityManager->wrapRequest(std::bind(&SystemStatus::systemStatus, this, _1), AuthenticationPredicates::IS_AUTHENTICATED));
}

void SystemStatus::systemStatus(AsyncWebServerRequest * request) {
    AsyncJsonResponse * response = new AsyncJsonResponse(false, MAX_ESP_STATUS_SIZE);
    JsonObject          root     = response->getRoot();
    root["emsesp_version"]       = EMSESP_APP_VERSION;
    root["esp_platform"]         = "ESP32";
    root["max_alloc_heap"]       = ESP.getMaxAllocHeap();
    root["psram_size"]           = ESP.getPsramSize();
    root["free_psram"]           = ESP.getFreePsram();
    root["cpu_freq_mhz"]         = ESP.getCpuFreqMHz();
    root["free_heap"]            = ESP.getFreeHeap();
    root["sdk_version"]          = ESP.getSdkVersion();
    root["flash_chip_size"]      = ESP.getFlashChipSize();
    root["flash_chip_speed"]     = ESP.getFlashChipSpeed();

    root["fs_total"] = emsesp::EMSESP::system_.FStotal();
    root["fs_used"]  = LittleFS.usedBytes();
    root["uptime"]   = uuid::log::format_timestamp_ms(uuid::get_uptime_ms(), 3);

    response->setLength();
    request->send(response);
}
