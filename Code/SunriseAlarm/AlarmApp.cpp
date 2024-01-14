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
  hw.display.setFont(u8g2_font_inr16_mf);    // fornt without transparent background (no need to clear buffer)
  hw.display.setCursor(26,56);
  
  hw.display.print("ALARM");

  if(alarmSet)
  {
    hw.display.setCursor(20,80);
    hw.display.print("  ON  ");
  }
  else
  {
    hw.display.setCursor(20,80);
    hw.display.print("      ");
  }

  // Updates a small part of the display (much faster)
  hw.display.updateDisplayArea(3, 5, 9, 5);  // Works in 8x8 blocks (x, y, w, h) 
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
  return;
}