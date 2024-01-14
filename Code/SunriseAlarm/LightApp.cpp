/**
 * @file LightApp.h
 * @author Sean Price
 * @brief Implements the LightApp class.
 * @version 0.1
 * @date 13/01/2024
 * 
 * 
 */

#include "LightApp.h"

//---------------------------------------------------- C O N S T R U C T O R ----------------------------------------------------
LightApp::LightApp(Hardware& hardware) : App(hardware) {}


//----------------------------------------------------------- I N I T -----------------------------------------------------------
void LightApp::init()
{
  return;
}


//---------------------------------------------- D I S P L A Y   M E N U   I C O N -----------------------------------------------
void LightApp::displayMenuIcon()
{
  hw.display.setFont(u8g2_font_inr16_mf);    // fornt without transparent background (no need to clear buffer)
  hw.display.setCursor(30,64);
  
  hw.display.print(" OFF ");

  // Updates a small part of the display (much faster)
  hw.display.updateDisplayArea(4, 6, 8, 2);  // Works in 8x8 blocks (x, y, w, h) 
}


//-------------------------------------------------------- D I S P L A Y --------------------------------------------------------
void LightApp::display() 
{
  hw.display.setCursor(20,64);
  hw.display.setFont(u8g2_font_inr16_mf);

  hw.display.print("  ON  ");

  hw.display.updateDisplayArea(4, 6, 8, 2); 
}


//---------------------------------------------------- L E F T   A C T I O N ----------------------------------------------------
void LightApp::leftAction() 
{
  return;
}


//-------------------------------------------------- M I D D L E   A C T I O N --------------------------------------------------
void LightApp::middleAction() 
{
  hw.light.turnOff();
  closeApp();
}


//--------------------------------------------------- R I G H T   A C T I O N ---------------------------------------------------
void LightApp::rightAction()
{
  return;
}


//------------------------------------------------------- O P E N   A P P -------------------------------------------------------
void LightApp::openApp() 
{
  hw.light.turnOn();
  App::openApp();
}


//------------------------------------------- B A C K G R O U N D   F U N C T I O N S -------------------------------------------
void LightApp::backgroundFunctions()
{
  return;
}