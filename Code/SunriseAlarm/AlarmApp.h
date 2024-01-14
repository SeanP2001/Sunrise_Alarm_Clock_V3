/**
 * @file AlarmApp.h
 * @author Sean Price
 * @brief Defines the AlarmApp class which is derrived from the App base class.
 * @version 0.1
 * @date 14/01/2024
 * 
 * 
 */

#ifndef ALARM_APP_H
#define ALARM_APP_H

#include <Arduino.h>

#include "App.h"

/**
 * @class AlarmApp
 * @brief Represents an application for controlling a Alarm, derived from the App base class.
 * 
 */
class AlarmApp : public App
{
  private:
    bool alarmSet;      ///< Flag to determine whether the alarm has been set or not
    uint8_t alarmHour;  ///< The hour which the alarm is set to go off at

    Ds1302::DateTime now;  ///< DateTime object to store the current time

    const static char* WeekDays[];
    const static uint8_t WeekDayXPos[];
  

  public:
    /**
     * @brief Construct a new AlarmApp object
     *
     * The alarm is not set by default when AlarmApp object is instantiated.
     * Currently the alarmHour is set by a magic number (7). In future, this setting will be passed to the constructor.
     * 
     * @param hardware Reference to a Hardware struct containing all the hardware-related objects
     */
    AlarmApp(Hardware& hardware); 



    /**
     * @brief Initialises the AlarmApp
     * 
     * During initialisation, the date and time are retrieved from the RTC module.
     * 
     */
    void init() override;



    /**
     * @brief Displays the menu page for the application.
     *
     * Display the current day, time and date. 
     * The bell icon is outlined when not set and filled when the alarm is set.
     */
    void displayMenuPage() override;

    /**
     * @brief Displays the main content of the application.
     * 
     * Currently this function does nothing.
     * 
     */
    void display() override;



    /**
     * @brief Handles left button presses.
     * 
     * Currently this function does nothing.
     * 
     */
    void leftAction() override;

    /**
     * @brief Handles middle button presses.
     * 
     * Currently this function does nothing.
     */
    void middleAction() override;
    
    /**
     * @brief Handles right button presses.
     * 
     * Currently this function does nothing.
     */
    void rightAction() override;



    /**
     * @brief Opens the app, toggles the alarm and closes the app again.
     * 
     */
    void openApp() override;



    /**
     * @brief Check if the alarm is set.
     * 
     * @return true if the alarm is set
     * @return false if the alarm isn't set
     */
    bool isSet();



    /**
     * @brief Perform background tasks associated with the Alarm App.
     * 
     * There are currently no background tasks associated with the Alarm App.
     * In future, this function will check whether the alarm is due to go off, and sound the alarm if it is.
     */
    void backgroundTasks() override;
};

#endif // ALARM_APP_H