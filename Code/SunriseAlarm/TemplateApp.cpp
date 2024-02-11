/**
 * @file TemplateApp.cpp
 * @author Sean Price
 * @brief Implements the TemplateApp class.
 * @version 0.1
 * @date 11/02/2024
 * 
 * This file serves as a template for creating new applications based on the App base class. Follow the instructions below to create and customize your own app.
 */

#include "TemplateApp.h"  //<< CHANGE THIS


//---------------------------------------------------- C O N S T R U C T O R ----------------------------------------------------
TemplateApp::TemplateApp(Hardware& hardware) : App(hardware) {}


//----------------------------------------------------------- I N I T -----------------------------------------------------------
void TemplateApp::init()
{
  return;
}


//---------------------------------------------- D I S P L A Y   M E N U   P A G E -----------------------------------------------
void TemplateApp::displayMenuPage()
{ 
  return;
}


//-------------------------------------------------------- D I S P L A Y --------------------------------------------------------
void TemplateApp::display() 
{
  return;
}


//---------------------------------------------------- L E F T   A C T I O N ----------------------------------------------------
void TemplateApp::leftAction() 
{
  return;
}


//-------------------------------------------------- M I D D L E   A C T I O N --------------------------------------------------
void TemplateApp::middleAction() 
{
  return;
}


//--------------------------------------------------- R I G H T   A C T I O N ---------------------------------------------------
void TemplateApp::rightAction()
{
  return;
}


//------------------------------------------------------- O P E N   A P P -------------------------------------------------------
void TemplateApp::openApp() 
{
  App::openApp(); // Call the parent function 

  // Add any other code which executes a single time when the app is opened
  return;
}


//----------------------------------------------- B A C K G R O U N D   T A S K S -----------------------------------------------
void TemplateApp::backgroundTasks()
{
  hw.rtc.getDateTime(&now);                // Get the current time

  // Use the current time 'now' to determine which tasks should run
  return;
}