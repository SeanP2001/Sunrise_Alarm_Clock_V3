/**
 * @file TemplateApp.h
 * @author Sean Price
 * @brief Defines the TemplateApp class which is derrived from the App base class.
 * @version 0.1
 * @date 11/02/2024
 * 
 * This file serves as a template for creating new applications based on the App base class. Follow the instructions below to create and customize your own app.  
 *   
 * HOW TO CREATE A NEW APP  
 * 1. Copy the "TemplateApp.h" and "TemplateApp.cpp" files, changing their names to reflect your app.  
 * 2. Change the header guards, file headers and and include statements to the new file names.  
 * 3. Do a find and replace for the phrase "TemplateApp" replacing it with the name of your app (both files).  
 * 4. Add code to each of the functions.  
 * 5. Include the header file in the main program.  
 * 6. Instantiate the new "____App" object.  
 * 7. Increment the "noOfApps".  
 * 8. Add a reference to the new app object to the next index of the "apps" array. e.g."apps[i] = &____App;".
 */

#ifndef TEMPLATE_APP_H
#define TEMPLATE_APP_H

#include <Arduino.h>

#include "App.h"


/**
 * @class TemplateApp
 * @brief Represents the basic structure of an application, derived from the App base class.
 * 
 */
class TemplateApp : public App
{
  private:
    Ds1302::DateTime now;  ///< DateTime struct to store the current time

  public:
    /**
     * @brief Construct a new TemplateApp object
     * 
     * Add any extra parameters to the constructor arguments
     * 
     * @param hardware Reference to a Hardware struct containing all the hardware-related objects, allowing the hardware to be directly accessed within the app functions.
     */
    TemplateApp(Hardware& hardware); 



    /**
     * @brief Initialises the TemplateApp
     * 
     * Code within this function will execute once during the setup of the main program
     */
    void init() override;



    /**
     * @brief Displays the menu page for the application.
     * 
     * Contains all display related code which is to be shown on the main menu page. 
     * Use "hw.display" to access the display functions
     */
    void displayMenuPage() override;

    /**
     * @brief Displays the main content of the application.
     * 
     * Contains all display related code which is to be shown when the app is open. 
     * May include a state machine switch-case statement if the application has multiple screens.
     */
    void display() override;



    /**
     * @brief Handles left button presses.
     * 
     * 
     */
    void leftAction() override;

    /**
     * @brief Handles middle button presses.
     * 
     * 
     */
    void middleAction() override;
    
    /**
     * @brief Handles right button presses.
     * 
     * 
     */
    void rightAction() override;



    /**
     * @brief Open the application.
     * 
     * Add any code which is to be executed a single time when the app is opened.
     */
    void openApp() override;



    /**
     * @brief Perform background tasks associated with the App.
     * 
     * This code will be executed once every cycle of the main program loop. 
     * Use "hw.rtc.getDateTime(&now);" to get the current time and use this to determine which tasks should run. 
     * Do not add any delays as this will reduce program responsiveness.  
     * An example of a background task is turning on or off an output at a specified time.
     */
    void backgroundTasks() override;
};

#endif // TEMPLATE_APP_H