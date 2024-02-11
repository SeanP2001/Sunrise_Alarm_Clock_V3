/**
 * @file SunriseAlarm.ino
 * @author Sean Price
 * @brief Software to run on the Sunrise Alarm V3
 * @version 0.1
 * @date 13/01/2024
 * 
 * The goal with this software is to make it modular and easy to add functionality in the form of "Apps". 
 * This will make it possible to add new features, without breaking existing functionality.
 */


// ---------------------------------------- D E F I N E   P I N   N U M B E R S ----------------------------------------
#define LEFT_BUTTON 15
#define MIDDLE_BUTTON 14
#define RIGHT_BUTTON 13

#define LIGHT 11
#define USB_1 5
#define USB_2 28

#define BUZZER 22

#define RTC_RESET 8
#define RTC_CLK 6
#define RTC_DATA 7

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 128
#define SCREEN_CLK 18
#define SCREEN_DATA 19
#define SCREEN_CS 16
#define SCREEN_DC 17
#define SCREEN_RESET 20


// --------------------------------------------------- I N C L U D E ---------------------------------------------------
#include <SPI.h>
#include <Ds1302.h>
#include <U8g2lib.h>

#include "Device.h"
#include "PWMDevice.h"
#include "Buzzer.h"
#include "Hardware.h"

#include "App.h"
#include "LightApp.h"
#include "AlarmApp.h"


// -------------------------------------- I N S T A N T I A T E   H A R D W A R E --------------------------------------

U8G2_SSD1327_WS_128X128_F_4W_SW_SPI display(U8G2_R0, SCREEN_CLK, SCREEN_DATA, SCREEN_CS, SCREEN_DC, SCREEN_RESET);

Ds1302 rtc(RTC_RESET, RTC_CLK, RTC_DATA);

PWMDevice light(LIGHT, 4);
Device usb1(USB_1);
Device usb2(USB_2);

Buzzer buzzer(BUZZER);

struct Hardware hw = {display, rtc, light, usb1, usb2, buzzer};  // Put all hardware component in a struct for portabilty


// ---------------------------------- I N S T A N T I A T E   A P P L I C A T I O N S ----------------------------------

AlarmApp alarmApp(hw);
LightApp lightApp(hw);

const int noOfApps = 2;
App* apps[noOfApps];

uint8_t currentApp = 0;


// ------------------------------------------------- V A R I A B L E S -------------------------------------------------
volatile bool leftPressed = false;
volatile bool middlePressed = false;
volatile bool rightPressed = false;


// ----------------------------------------------------- S E T U P -----------------------------------------------------
void setup() 
{
  // Setup Buttons
  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(MIDDLE_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(LEFT_BUTTON), leftISR, RISING);
  attachInterrupt(digitalPinToInterrupt(MIDDLE_BUTTON), middleISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_BUTTON), rightISR, RISING);

  // Initialise Objects
  rtc.init();
  display.begin();

  // Setup Apps
  apps[0] = &alarmApp;
  apps[1] = &lightApp;

  // Run App Initialisations
  for(int i = 0; i < noOfApps; i++)
  {
    apps[i]->init(); 
  }
}

// ------------------------------------------------------ M A I N ------------------------------------------------------
void loop() 
{
  if(millis() % 1000 == 0)                    // Update the display every second
  {
    updateDisplay();
  }
  
  
  if(anyButtonPressed())                      // Handle any button presses (when they occur)
  {
    if(apps[currentApp]->isOpen())            // If an app is open, forward the button presses to the app
    {
      if(leftPressed)
      {
        apps[currentApp]->leftAction();
        leftPressed = false;
      }
      if(middlePressed)
      {
        apps[currentApp]->middleAction();
        middlePressed = false;
      }
      if(rightPressed)
      {
        apps[currentApp]->rightAction();
        rightPressed = false;
      }
    }
    else                                      // When in the menu
    {
      if(leftPressed)                         // Left button presses move to the previous app
      {
        display.clearBuffer();
        display.clearDisplay();

        if(currentApp == 0)
        {
          currentApp = noOfApps - 1;
        }
        else
        {
          currentApp--;
        }

        leftPressed = false;
      }
      
      if(middlePressed)                       // Middle button presses open the current app
      {
        apps[currentApp]->openApp();
        middlePressed = false;
      }
      
      if(rightPressed)                        // Right button presses move to the next app
      {
        display.clearBuffer();
        display.clearDisplay();

        currentApp++;
        if(currentApp >= noOfApps)
        {
          currentApp = 0;
        }
        rightPressed = false;
      }
    }

    updateDisplay();
  }

  
  for(int i = 0; i < noOfApps; i++)           // Run App Background Tasks
  {
    apps[i]->backgroundTasks(); 
  }
}


// -------------------------------------------- U P D A T E   D I S P L A Y --------------------------------------------
void updateDisplay()
{
  if(apps[currentApp]->isOpen())
  {
    apps[currentApp]->display();
  }
  else
  {
    apps[currentApp]->displayMenuPage();
  }
}


// ---------------------------------------- A N Y   B U T T O N   P R E S S E D ----------------------------------------
bool anyButtonPressed()
{
  return (leftPressed || middlePressed || rightPressed);
}


// -------------------------------------------- L E F T   I N T E R R U P T --------------------------------------------
void leftISR() 
{
  leftPressed = true;
}

// ------------------------------------------ M I D D L E   I N T E R R U P T ------------------------------------------
void middleISR() 
{ 
  middlePressed = true;
}

// ------------------------------------------- R I G H T   I N T E R R U P T -------------------------------------------
void rightISR() 
{
  rightPressed = true;
}
