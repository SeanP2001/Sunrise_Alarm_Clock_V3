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

const uint8_t PWMDevice::DEFAULT_MAX_LEVEL = 4;
const uint8_t PWMDevice::DEFAULT_LEVEL = DEFAULT_MAX_LEVEL;
const uint8_t PWMDevice::MIN_VAL = 10;
const uint8_t PWMDevice::MAX_VAL = 255;


//--------------------------------------------------- C O N S T R U C T O R S ---------------------------------------------------
PWMDevice::PWMDevice(uint8_t pinNo) : Device(pinNo), pinNo(pinNo), level(DEFAULT_LEVEL), maxLevel(DEFAULT_MAX_LEVEL) {}

PWMDevice::PWMDevice(uint8_t pinNo, uint8_t maxLevel) : Device(pinNo), pinNo(pinNo), level(DEFAULT_LEVEL), maxLevel(maxLevel) {}


//-------------------------------------------------------- T U R N   O N --------------------------------------------------------
void PWMDevice::turnOn()
{
  Device::turnOn();

  uint8_t value = MIN_VAL + ((MAX_VAL-MIN_VAL)/maxLevel)*level;

  analogWrite(pinNo, value);
}


//--------------------------------------------------- T U R N   O N   F U L L ---------------------------------------------------
void PWMDevice::turnOnFull()
{
  Device::turnOn();
}


//------------------------------------------------- I N C R E A S E   L E V E L -------------------------------------------------
void PWMDevice::increaseLevel()
{
  if(level < maxLevel)
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


//------------------------------------------------------ G E T   L E V E L ------------------------------------------------------
uint8_t PWMDevice::getLevel()
{
  return level;
}