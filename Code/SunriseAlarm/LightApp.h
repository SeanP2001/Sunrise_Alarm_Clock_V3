/**
 * @file LightApp.h
 * @author Sean Price
 * @brief Defines the LightApp class which is derrived from the App base class.
 * @version 0.1
 * @date 13/01/2024
 * 
 * 
 */

#ifndef LIGHT_APP_H
#define LIGHT_APP_H

#include <Arduino.h>

#include "App.h"

/**
 * @class LightApp
 * @brief Represents an application for controlling a light, derived from the App base class.
 * 
 */
class LightApp : public App
{
  private:
    uint8_t lightOnTime;   ///< The hour which the light is set to turn on
    uint8_t lightOffTime;  ///< The hour which the light is set to turn off

    Ds1302::DateTime now;  ///< DateTime struct to store the current time

  public:
    /**
     * @brief Construct a new LightApp object
     *
     * Currently the lightOnTime and lightOffTime are set to magic numbers (6 and 9). In future, this setting will be passed to the constructor.
     * 
     * @param hardware Reference to a Hardware struct containing all the hardware-related objects
     */
    LightApp(Hardware& hardware); 



    /**
     * @brief Initialises the LightApp
     * 
     * Nothing happens at initialisation.
     * 
     */
    void init() override;



    /**
     * @brief Displays the menu page for the application.
     * 
     * Shows an icon of a switched off light bulb.
     */
    void displayMenuPage() override;

    /**
     * @brief Displays the main content of the application.
     * 
     * Shows an icon of a glowing light bulb.
     * 
     */
    void display() override;



    /**
     * @brief Handles left button presses.
     * 
     * Decrease the light brightness.
     * 
     */
    void leftAction() override;

    /**
     * @brief Handles middle button presses.
     * 
     * Turns off the light and closes the app.
     */
    void middleAction() override;
    
    /**
     * @brief Handles right button presses.
     * 
     * Increase the light brightness.
     */
    void rightAction() override;



    /**
     * @brief Open the application, turning on the light.
     * 
     */
    void openApp() override;



    /**
     * @brief Perform background tasks associated with the Light App.
     * 
     * Retrieve the date and time from the RTC module. 
     * Check whether the light is due to be on, and turn the light on full if it is.
     */
    void backgroundTasks() override;
};

#endif // LIGHT_APP_H