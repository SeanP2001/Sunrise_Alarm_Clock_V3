/**
 * @file USBApp.h
 * @author Sean Price
 * @brief Defines the USBApp class which is derrived from the App base class.
 * @version 0.1
 * @date 11/02/2024
 * 
 */

#ifndef USB_APP_H
#define USB_APP_H

#include <Arduino.h>

#include "App.h"


/**
 * @class USBApp
 * @brief Represents an application for controlling USB ports, derived from the App base class.
 * 
 */
class USBApp : public App
{
  private:
    uint8_t usb1OnTime;   ///< The hour which USB 1 is set to turn on
    uint8_t usb1OffTime;  ///< The hour which USB 1 is set to turn off
    uint8_t usb2OnTime;   ///< The hour which USB 2 is set to turn on
    uint8_t usb2OffTime;  ///< The hour which USB 2 is set to turn off

    Ds1302::DateTime now;  ///< DateTime struct to store the current time

  public:
    /**
     * @brief Construct a new USBApp object
     *
     * Currently both USB ports are set to come on at 6 and turn off at 9. In future, these magic numbers will be handled by the settings struct.
     * 
     * @param hardware Reference to a Hardware struct containing all the hardware-related objects, allowing the hardware to be directly accessed within the app functions.
     */
    USBApp(Hardware& hardware); 



    /**
     * @brief Initialises the USBApp
     * 
     * Currently no code runs at initialisation
     */
    void init() override;



    /**
     * @brief Displays the menu page for the application.
     * 
     * Shows the USB icon.
     */
    void displayMenuPage() override;

    /**
     * @brief Displays the main content of the application.
     * 
     * Shows a USB icon for each of the two ports.
     * The icons are filled in when their port is switched on and not filled when switched off.
     */
    void display() override;



    /**
     * @brief Handles left button presses.
     * 
     * Toggles the status of USB 1.
     */
    void leftAction() override;

    /**
     * @brief Handles middle button presses.
     * 
     * Clears the screen and closes the app, returning to the main menu. (Does not turn off the USB ports)
     */
    void middleAction() override;
    
    /**
     * @brief Handles right button presses.
     * 
     * Toggles the status of USB 2.
     */
    void rightAction() override;



    /**
     * @brief Open the application.
     * 
     * Calls the parent function and clears the screen.
     */
    void openApp() override;



    /**
     * @brief Perform background tasks associated with the App.
     * 
     * Turns the USB ports ON or OFF depending on the time.
     */
    void backgroundTasks() override;
};

#endif // USB_APP_H