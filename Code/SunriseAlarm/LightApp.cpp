/**
 * @file LightApp.cpp
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


//---------------------------------------------- D I S P L A Y   M E N U   P A G E -----------------------------------------------
void LightApp::displayMenuPage()
{ 
  hw.display.drawBitmap(16, 16, 12, 96, lightOffIcon);

  // Updates a small part of the display (much faster)
  hw.display.updateDisplayArea(2, 2, 12, 12);  // Works in 8x8 blocks (x, y, w, h) 
}


//-------------------------------------------------------- D I S P L A Y --------------------------------------------------------
void LightApp::display() 
{
  hw.display.drawBitmap(16, 16, 12, 96, lightOnIcon);

  // Updates a small part of the display (much faster)
  hw.display.updateDisplayArea(2, 2, 12, 12);  // Works in 8x8 blocks (x, y, w, h) 
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


//----------------------------------------------- B A C K G R O U N D   T A S K S -----------------------------------------------
void LightApp::backgroundTasks()
{
  return;
}