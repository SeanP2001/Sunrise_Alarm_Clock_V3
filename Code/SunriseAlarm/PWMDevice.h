/**
 * @file PWMDevice.h
 * @author Sean Price
 * @brief Defines the PWMDevice class, a subclass of the Device class
 * @version 0.1
 * @date 13/01/2024
 * 
 * 
 */

#ifndef PWM_DEVICE_H
#define PWM_DEVICE_H

#include <Arduino.h>
#include "Device.h"

/**
 * @class PWMDevice
 * 
 * @brief A class representing a PWM output device connected to a pin on the microcontroller.
 * 
 * This class implements basic functionality to control a PWM output device.
 * 
 */
class PWMDevice : public Device {
private:
  uint8_t pinNo;     ///< The number of the pin which the device is connected to.
  uint8_t level;     ///< The current PWM level of the device
  uint8_t maxLevel;  ///< The maximum PWM level of the device

  const static uint8_t DEFAULT_MAX_LEVEL;  ///< The default maximum PWM level (4)
  const static uint8_t DEFAULT_LEVEL;      ///< The default PWM level (4)
  const static uint8_t MIN_VAL;            ///< The minimum PWM Value (255)
  const static uint8_t MAX_VAL;            ///< The maximum PWM Value (10)

public:
  /**
   * @brief Construct a new PWMDevice object
   * 
   * @param pinNo The number of the pin which the device is connected to.
   */
  PWMDevice(uint8_t pinNo);


  /**
   * @brief Construct a new PWMDevice object
   * 
   * @param pinNo The number of the pin which the device is connected to.
   * @param maxLevel The maximum number of PWM levels available for the device.
   */
  PWMDevice(uint8_t pinNo, uint8_t maxLevel);


  /**
   * @brief Turn ON the pin connected to the device at the set PWM level.
   * 
   */
  void turnOn() override;


  /**
   * @brief Turn ON the pin connected to the device at the maximum PWM level.
   * 
   * Calls Device::turnOn()
   */
  void turnOnFull();


  /**
   * @brief Increase the current PWM level by one, up to the maxLevel.
   * 
   */
  void increaseLevel();


  /**
   * @brief Decrease the current PWM level by one, down to 0.
   * 
   */
  void decreaseLevel();


  /**
   * @brief Get the current level of the PWM device.
   * 
   * @return The current PWM level the device is set to output at.
   */
  uint8_t getLevel();
};

#endif  // PWM_DEVICE_H