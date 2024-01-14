/**
 * @file Device.h
 * @author Sean Price
 * @brief Defines the Device class
 * @version 0.1
 * @date 13/01/2024
 * 
 * 
 */

#ifndef DEVICE_H
#define DEVICE_H

#include <Arduino.h>

/**
 * @class Device
 * @brief A class representing a digital output device connected to a pin on the microcontroller.
 * 
 * This class implements basic functionality to control a digital output device.
 * 
 */
class Device
{
  private:
    uint8_t pinNo;   ///< The number of the pin which the device is connected to.
    bool state;      ///< The current state of the device (ON or OFF).
    
  public:
    /**
     * @brief Construct a new Device object
     * 
     * @param pinNo The number of the pin which the device is connected to.
     */
    Device(uint8_t pinNo);


    /**
     * @brief Turn ON the pin connected to the device.
     * 
     */
    void turnOn();

    /**
     * @brief Turn OFF the pin connected to the device.
     * 
     */
    void turnOff();


    /**
     * @brief Get the current status of the device.
     * 
     * @return true if the device is currently switched ON.
     * @return false if the device is currently switched OFF.
     */
    bool isOn();


    /**
     * @brief Toggle the state of the pin connected to the device.
     * 
     * If the device is ON, turn it OFF.
     * If the device is OFF, turn it ON.
     * 
     */
    void toggle();
};

#endif // DEVICE_H