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
#include "Buzzer.h"


// --------------------------------------- I N S T A N T I A T E   O B J E C T S ---------------------------------------
U8G2_SSD1327_WS_128X128_F_4W_SW_SPI display(U8G2_R0, SCREEN_CLK, SCREEN_DATA, SCREEN_CS, SCREEN_DC, SCREEN_RESET);

Ds1302 rtc(RTC_RESET, RTC_CLK, RTC_DATA);

Device light(LIGHT);
Device usb1(USB_1);
Device usb2(USB_2);

Buzzer buzzer(BUZZER);


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
}


// ------------------------------------------------------ M A I N ------------------------------------------------------
void loop() 
{
  if(leftPressed)
  {
    usb1.toggle();
    leftPressed = false;
  }
  if(middlePressed)
  {
    light.toggle();
    middlePressed = false;
  }
  if(rightPressed)
  {
    usb2.toggle();
    rightPressed = false;
  }

  delay(50); 
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
