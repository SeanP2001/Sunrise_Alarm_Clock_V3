/**
 * @file PWMDevice.cpp
 * @author Sean Price
 * @brief Implements the PWMDevice class.
 * @version 0.1
 * @date 13/01/2024
 * 
 * 
 */

#include "PWMDevice.h"

const uint8_t PWMDevice::MAX_LEVEL = 4;
const uint8_t PWMDevice::DEFAULT_LEVEL = MAX_LEVEL;
const uint8_t PWMDevice::MIN_VAL = 10;
const uint8_t PWMDevice::MAX_VAL = 255;


//---------------------------------------------------- C O N S T R U C T O R ----------------------------------------------------
PWMDevice::PWMDevice(uint8_t pinNo) : Device(pinNo), pinNo(pinNo), level(DEFAULT_LEVEL) {}


//-------------------------------------------------------- T U R N   O N --------------------------------------------------------
void PWMDevice::turnOn()
{
  Device::turnOn();

  uint8_t value = MIN_VAL + ((MAX_VAL-MIN_VAL)/MAX_LEVEL)*level;

  analogWrite(pinNo, value);
}


//------------------------------------------------- I N C R E A S E   L E V E L -------------------------------------------------
void PWMDevice::increaseLevel()
{
  if(level < MAX_LEVEL)
  {
    level++;
  }
}


//------------------------------------------------- D E C R E A S E   L E V E L -------------------------------------------------
void PWMDevice::decreaseLevel()
{
  if(level > 0)
  {
    level--;
  }
}