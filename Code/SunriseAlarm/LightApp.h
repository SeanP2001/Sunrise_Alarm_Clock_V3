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
  public:
    /**
     * @brief Construct a new LightApp object
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
     * @brief Displays the menu icon for the application.
     * 
     * Currently this just prints the word "OFF" to the display.
     * In future this will show an icon of a switched off light bulb.
     */
    void displayMenuIcon() override;

    /**
     * @brief Displays the main content of the application.
     * 
     * Currently this just prints the word "ON" to the display.
     * In future this will show an icon of a glowing light bulb.
     * 
     */
    void display() override;



    /**
     * @brief Handles left button presses.
     * 
     * Currently this function does nothing.
     * In future this will decrease the light brightness.
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
     * Currently this function does nothing.
     * In future this will increase the light brightness.
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
     * There are no background tasks associated with the Light App.
     */
    void backgroundFunctions() override;
};

#endif // LIGHT_APP_H