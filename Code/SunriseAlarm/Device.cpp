/**
 * @file Device.cpp
 * @author Sean Price
 * @brief Implements the Device class
 * @version 0.1
 * @date 13/01/2024
 * 
 * 
 */

#include "Device.h"

//---------------------------------------------------- C O N S T R U C T O R ----------------------------------------------------
Device::Device(uint8_t pinNo) : pinNo(pinNo), state(false) {pinMode(pinNo, OUTPUT);}

//-------------------------------------------------------- T U R N   O N --------------------------------------------------------
void Device::turnOn()
{
  state = true;
  digitalWrite(pinNo, HIGH);
}

//------------------------------------------------------- T U R N   O F F -------------------------------------------------------
void Device::turnOff()
{
  state = false;
  digitalWrite(pinNo, LOW);
}

//---------------------------------------------------------- I S   O N ----------------------------------------------------------
bool Device::isOn()
{
  return state;
}

//--------------------------------------------------------- T O G G L E ---------------------------------------------------------
void Device::toggle()
{
  if(isOn())
  {
    turnOff();
  }
  else
  {
    turnOn();
  }
}