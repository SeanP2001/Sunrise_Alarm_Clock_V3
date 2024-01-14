/**
 * @file AlarmApp.cpp
 * @author Sean Price
 * @brief Implements the AlarmApp class.
 * @version 0.1
 * @date 14/01/2024
 * 
 * 
 */

#include "AlarmApp.h"

const char* AlarmApp::WeekDays[] =
{
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday",
  "Sunday"
};

const uint8_t AlarmApp::WeekDayXPos[] = {45, 46, 38, 43, 49, 42, 47};

//---------------------------------------------------- C O N S T R U C T O R ----------------------------------------------------
AlarmApp::AlarmApp(Hardware& hardware) : App(hardware), alarmSet(false), alarmHour(7) {}  // WARNING: Temporary Magic Number (Will be rectified with settings struct)


//----------------------------------------------------------- I N I T -----------------------------------------------------------
void AlarmApp::init()
{
  hw.rtc.getDateTime(&now); 
  return;
}


//---------------------------------------------- D I S P L A Y   M E N U   P A G E -----------------------------------------------
void AlarmApp::displayMenuPage()
{
  hw.display.clearBuffer();  
  hw.display.setFont(u8g2_font_helvR08_tf);	

  // Print Weekday
  hw.display.setCursor(WeekDayXPos[now.dow - 1],30);
  hw.display.print(WeekDays[now.dow - 1]); // 1-7

  // Print Date
  hw.display.setCursor(38,99);
  if (now.day < 10) hw.display.print('0');
  hw.display.print(now.day);     // 01-31
  hw.display.print('/');
  if (now.month < 10) hw.display.print('0');
  hw.display.print(now.month);   // 01-12
  hw.display.print('/');
  hw.display.print("20");
  hw.display.print(now.year);    // 00-99
  
  // Print Time
  hw.display.setCursor(2,75);
  hw.display.setFont(u8g2_font_fur35_tn);
  if (now.hour < 10) hw.display.print('0');
  hw.display.print(now.hour);    // 00-23
  hw.display.print(':');
  if (now.minute < 10) hw.display.print('0');
  hw.display.print(now.minute);  // 00-59

  // Show bell icon (set or not set)
  if(alarmSet)
  {
    hw.display.drawBitmap(56, 0, 2, 16, alarmOnIcon);
  }
  else
  {
    hw.display.drawBitmap(56, 0, 2, 16, alarmOffIcon);
  }


  hw.display.sendBuffer();
}


//-------------------------------------------------------- D I S P L A Y --------------------------------------------------------
void AlarmApp::display() 
{
  return;
}


//---------------------------------------------------- L E F T   A C T I O N ----------------------------------------------------
void AlarmApp::leftAction() 
{
  return;
}


//-------------------------------------------------- M I D D L E   A C T I O N --------------------------------------------------
void AlarmApp::middleAction() 
{
  return;
}


//--------------------------------------------------- R I G H T   A C T I O N ---------------------------------------------------
void AlarmApp::rightAction()
{
  return;
}


//------------------------------------------------------- O P E N   A P P -------------------------------------------------------
void AlarmApp::openApp() 
{
  App::openApp();
  alarmSet = !alarmSet;

  if(!alarmSet)
  {
    hw.buzzer.stopTone();
  }

  closeApp();
}


//--------------------------------------------------------- I S   S E T ---------------------------------------------------------
bool AlarmApp::isSet()
{
  return alarmSet;
}


//----------------------------------------------- B A C K G R O U N D   T A S K S -----------------------------------------------
void AlarmApp::backgroundTasks()
{
  hw.rtc.getDateTime(&now);                // Update the time

  if((now.hour == alarmHour) && alarmSet)  // If the Alarm is due to go off
  {
    if(now.second % 2 == 0)                // Beep the alarm
    {
      if(!hw.buzzer.isSounding())
      {
        hw.buzzer.playTone();
      }
    }
    else
    {
      if(hw.buzzer.isSounding())
      {
        hw.buzzer.stopTone();
      }
    }
  }

  return;
}