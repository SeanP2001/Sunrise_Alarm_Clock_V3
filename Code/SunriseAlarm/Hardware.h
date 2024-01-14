/**
 * @file Hardware.h
 * @author Sean Price
 * @brief Defines the Hardware struct
 * @version 0.1
 * @date 13/01/2024
 * 
 * 
 */

#ifndef HARDWARE_H
#define HARDWARE_H

#include <Arduino.h>

#include <SPI.h>
#include <Ds1302.h>
#include <U8g2lib.h>

#include "Device.h"
#include "Buzzer.h"

/**
 * @struct Hardware
 * @brief Represents the hardware components used in the project.
 * 
 * Allows the hardware to be directly accessed when passed to a function.
 */
struct Hardware
{
  U8G2_SSD1327_WS_128X128_F_4W_SW_SPI &display; ///< OLED Display
  Ds1302 &rtc;                                  ///< Real-Time Clock
  Device &light;                                ///< LED Ring Light
  Device &usb1;                                 ///< USB Port 1
  Device &usb2;                                 ///< USB Port 2
  Buzzer &buzzer;                               ///< Buzzer
};

#endif // HARDWARE_H