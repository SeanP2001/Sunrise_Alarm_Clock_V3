/**
 * @file USBApp.cpp
 * @author Sean Price
 * @brief Implements the USBApp class.
 * @version 0.1
 * @date 11/02/2024
 * 
 */

#include "USBApp.h"  


//---------------------------------------------------- C O N S T R U C T O R ----------------------------------------------------
USBApp::USBApp(Hardware& hardware) : App(hardware), usb1OnTime(6), usb1OffTime(9), usb2OnTime(6), usb2OffTime(9) {} // WARNING: Temporary Magic Numbers (Will be rectified with settings struct)


//----------------------------------------------------------- I N I T -----------------------------------------------------------
void USBApp::init()
{
  return;
}


//---------------------------------------------- D I S P L A Y   M E N U   P A G E -----------------------------------------------
void USBApp::displayMenuPage()
{ 
  hw.display.drawBitmap(32, 16, 8, 96, usbMenuIcon);

  hw.display.sendBuffer();

  return;
}


//-------------------------------------------------------- D I S P L A Y --------------------------------------------------------
void USBApp::display() 
{
  if(hw.usb1.isOn())
  {
    hw.display.drawBitmap(8, 28, 6, 72, usbOnIcon);
  }
  else
  {
    hw.display.drawBitmap(8, 28, 6, 72, usbOffIcon);
  }

  if(hw.usb2.isOn())
  {
    hw.display.drawBitmap(72, 28, 6, 72, usbOnIcon);
  }
  else
  {
    hw.display.drawBitmap(72, 28, 6, 72, usbOffIcon);
  }

  hw.display.sendBuffer();

  return;
}


//---------------------------------------------------- L E F T   A C T I O N ----------------------------------------------------
void USBApp::leftAction() 
{
  hw.usb1.toggle();
  return;
}


//-------------------------------------------------- M I D D L E   A C T I O N --------------------------------------------------
void USBApp::middleAction() 
{
  hw.display.clearBuffer();
  closeApp();
  return;
}


//--------------------------------------------------- R I G H T   A C T I O N ---------------------------------------------------
void USBApp::rightAction()
{
  hw.usb2.toggle();
  return;
}


//------------------------------------------------------- O P E N   A P P -------------------------------------------------------
void USBApp::openApp() 
{
  App::openApp(); // Call the parent function 

  hw.display.clearBuffer();

  return;
}


//----------------------------------------------- B A C K G R O U N D   T A S K S -----------------------------------------------
void USBApp::backgroundTasks()
{
  hw.rtc.getDateTime(&now);                // Get the current time


  // ------ USB 1 ------
  // If the USB is due to be on (This will all be streamlined when the datetime class is added (comparisons))
  if(usb1OnTime < usb1OffTime)
  {
    if((now.hour >= usb1OnTime) && (now.hour < usb1OffTime))  // if the current hour is between the on and off hour
    {
      hw.usb1.turnOn();
    }
  }
  if(usb1OnTime > usb1OffTime)
  {
    if((now.hour >= usb1OnTime && now.hour <= 23) || (now.hour >= 0 && now.hour < usb1OffTime))     // if it is after the on time at night or before the off time in the morning
    {
      hw.usb1.turnOn();
    }
  }
  
  if((now.hour == usb1OffTime) && now.minute == 0)
  {
    hw.usb1.turnOff();
  }


  // ------ USB 2 ------
  // If the USB is due to be on (This will all be streamlined when the datetime class is added (comparisons))
  if(usb2OnTime < usb2OffTime)
  {
    if((now.hour >= usb2OnTime) && (now.hour < usb2OffTime))  // if the current hour is between the on and off hour
    {
      hw.usb2.turnOn();
    }
  }
  if(usb2OnTime > usb2OffTime)
  {
    if((now.hour >= usb2OnTime && now.hour <= 23) || (now.hour >= 0 && now.hour < usb2OffTime))     // if it is after the on time at night or before the off time in the morning
    {
      hw.usb2.turnOn();
    }
  }
  
  if((now.hour == usb2OffTime) && now.minute == 0)
  {
    hw.usb2.turnOff();
  }

  return;
}