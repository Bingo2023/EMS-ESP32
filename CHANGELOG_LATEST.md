# Changelog

# [3.5.0]

## **IMPORTANT! BREAKING CHANGES**

- When upgrading to v3.5 for the first time from v3.4 on a BBQKees Gateway board you will need to use the [EMS-EPS Flasher](https://github.com/emsesp/EMS-ESP-Flasher/releases) to correctly re-partition the flash. Make sure you backup the settings and customizations from the WebUI (System->Upload/Download) and restore after the upgrade.
- Support for multiple EMS-ESPs [#759] has been added as an optional setting for MQTT. When enabled, which is now the default, all MQTT Discovery Entity IDs will include the MQTT base name and the shortname of the EMS-ESP device entity. For example what was previously `sensor.boiler_actual_boiler_temperature` will now become `sensor.ems_esp_boiler_boiltemp`. If you still want to use the old format and retain the history and script compatibility in Home Assistant then set this back to the old format.

## Added

- Translations in Web UI and all device entity names (DE, NL, SE, PL, NO, FR) [#22](https://github.com/emsesp/EMS-ESP32/issues/22)
- Add support for Lolin C3 mini [#620](https://github.com/emsesp/EMS-ESP32/pull/620)
- Add support for ESP32-S2 [#667](https://github.com/emsesp/EMS-ESP32/pull/667)
- Add devices: Greenstar 30Ri boiler, Junkers FW500 thermostat, Buderus BC30 controller
- Add program memory info
- Add mqtt queue and connection infos
- Adapt min/max if ems-value is not in this range
- Add heat pump settings for inputs and limits [#600](https://github.com/emsesp/EMS-ESP32/issues/600)
- Add hybrid heatpump [#500](https://github.com/emsesp/EMS-ESP32/issues/500)
- Add translated tags
- Add min/max to customization table [#686](https://github.com/emsesp/EMS-ESP32/issues/686)
- Add MD5 check [#637](https://github.com/emsesp/EMS-ESP32/issues/637)
- Add more bus-ids [#673](https://github.com/emsesp/EMS-ESP32/issues/673)
- Use HA connectivity device class for Status, added boot time [#751](https://github.com/emsesp/EMS-ESP32/issues/751)
- Add commands for analog sensors outputs
- Support for multiple EMS-ESPs with MQTT and HA [[#759](https://github.com/emsesp/EMS-ESP32/issues/759)]
- Settings for heatpump silent mode and additional heater [[#802](https://github.com/emsesp/EMS-ESP32/issues/802)] [[#803](https://github.com/emsesp/EMS-ESP32/issues/803)]
- Zone module MZ100 [#826](https://github.com/emsesp/EMS-ESP32/issues/826)
- Default MQTT hostname is blank [#829](https://github.com/emsesp/EMS-ESP32/issues/829)

## Fixed

- Factory Reset not working [#628](https://github.com/emsesp/EMS-ESP32/issues/628)
- Valid 4 byte values [#820](https://github.com/emsesp/EMS-ESP32/issues/820)
- Commands for multiple thermostats [#826](https://github.com/emsesp/EMS-ESP32/issues/826)
- API queries for multiple devices [#865](https://github.com/emsesp/EMS-ESP32/issues/865)
- Console crash when using call with command `hcx` only. [#841](https://github.com/emsesp/EMS-ESP32/issues/841)

## Changed

- Discovery in HomeAssistant don't work with custom base topic. [#596](https://github.com/emsesp/EMS-ESP32/issues/596) Base topic containing `/` are changed to `_`
- RF room temperature sensor are shown as thermostat
- render mqtt float json values with trailing zero
- removed flash strings, to increase available heap memory
- reload page after restart button is pressed
- analog/dallas values command as list like ems-devices
- analog/dallas HA-entities based on id
- MQTT Base is a mandatory field. Removed MQTT topic length from settings
- HA duration class for time entities [[#822](https://github.com/emsesp/EMS-ESP32/issues/822
- AM200 alternative heatsource as class heatsource [[#857](https://github.com/emsesp/EMS-ESP32/issues/857
