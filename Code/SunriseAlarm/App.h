/**
 * @file App.h
 * @author Sean Price
 * @brief Defines the App base class.
 * @version 0.1
 * @date 13/01/2024
 * 
 * 
 */

#ifndef APP_H
#define APP_H

#include <Arduino.h>

#include "Hardware.h"

/**
 * @class App
 * @brief Abstract base class for applications.
 * 
 */
class App
{
  private:
    bool openFlag;   ///< Flag indicating whether the app is open or not
    
  protected:
    Hardware& hw;    ///< Reference to the Hardware struct containing all the hardware-related objects

    /**
     * @brief Construct a new App object
     * 
     * @param hardware Reference to a Hardware struct containing all the hardware-related objects
     */
    App(Hardware& hardware);  

  public:
    /**
     * @brief Initialise the application.
     * 
     * @details There is no default implementation and a specific behavior must be defined in the derived class.
     */
    virtual void init() = 0;



    /**
     * @brief Display the menu page for the application.
     * 
     * @details There is no default implementation and a specific behavior must be defined in the derived class.
     */
    virtual void displayMenuPage() = 0;

    /**
     * @brief Display the main content of the application.
     * 
     * @details There is no default implementation and a specific behavior must be defined in the derived class.
     */
    virtual void display() = 0;



    /**
     * @brief Perform an action when the left button is pressed.
     * 
     * @details There is no default implementation and a specific behavior must be defined in the derived class.
     */
    virtual void leftAction() = 0;

    /**
     * @brief Perform an action when the middle button is pressed.
     * 
     * @details There is no default implementation and a specific behavior must be defined in the derived class.
     */
    virtual void middleAction() = 0;

    /**
     * @brief Perform an action when the right button is pressed.
     * 
     * @details There is no default implementation and a specific behavior must be defined in the derived class.
     */
    virtual void rightAction() = 0;



    /**
     * @brief Open the application.
     * 
     * @details This is the default implementation but it can be overridden in derived classes.
     */
    virtual void openApp();

    /**
     * @brief Close the application.
     * 
     * @details This is the default implementation but it can be overridden in derived classes.
     */
    virtual void closeApp();

    /**
     * @brief Check if the application is open.
     * 
     * @return true if the application is open
     * @return false if the application isn't open
     */
    bool isOpen() const;



    /**
     * @brief Perform background tasks associated with the application.
     * 
     * @details There is no default implementation and a specific behavior must be defined in the derived class.
     */
    virtual void backgroundTasks() = 0;
};

#endif // APP_H