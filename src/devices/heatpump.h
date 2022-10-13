/*
 * EMS-ESP - https://github.com/emsesp/EMS-ESP
 * Copyright 2020  Paul Derbyshire
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef EMSESP_HEATPUMP_H
#define EMSESP_HEATPUMP_H

#include "emsesp.h"

namespace emsesp {

class Heatpump : public EMSdevice {
  public:
    Heatpump(uint8_t device_type, uint8_t device_id, uint8_t product_id, const char * version, const char * name, uint8_t flags, uint8_t brand);

  private:
    uint8_t airHumidity_;
    uint8_t dewTemperature_;

    // HM200
    uint8_t controlStrategy_;
    uint8_t lowNoiseMode_;
    uint8_t lowNoiseStart_;
    uint8_t lowNoiseStop_;
    uint8_t hybridDHW_;
    uint8_t energyPriceGas_;
    uint8_t energyPriceEl_;
    uint8_t energyPricePV_;
    int8_t  switchOverTemp_;

    // Function test
    uint8_t airPurgeMode_;
    uint8_t heatPumpOutput_;
    uint8_t coolingCircuit_;
    uint8_t compStartMod_;
    uint8_t heatDrainPan_;
    uint8_t heatCable_;

    void process_HPMonitor1(std::shared_ptr<const Telegram> telegram);
    void process_HPMonitor2(std::shared_ptr<const Telegram> telegram);
    void process_HPSettings(std::shared_ptr<const Telegram> telegram);
    void process_HPFunctionTest(std::shared_ptr<const Telegram> telegram);

    bool set_controlStrategy(const char * value, const int8_t id);
    bool set_lowNoiseMode(const char * value, const int8_t id);
    bool set_lowNoiseStart(const char * value, const int8_t id);
    bool set_lowNoiseStop(const char * value, const int8_t id);
    bool set_hybridDHW(const char * value, const int8_t id);
    bool set_energyPriceGas(const char * value, const int8_t id);
    bool set_energyPriceEl(const char * value, const int8_t id);
    bool set_energyPricePV(const char * value, const int8_t id);
    bool set_switchOverTemp(const char * value, const int8_t id);

    bool set_airPurgeMode(const char * value, const int8_t id);
    bool set_heatPumpOutput(const char * value, const int8_t id);
    bool set_coolingCircuit(const char * value, const int8_t id);
    bool set_compStartMod(const char * value, const int8_t id);
    bool set_heatDrainPan(const char * value, const int8_t id);
    bool set_heatCable(const char * value, const int8_t id);
};

} // namespace emsesp

#endif
