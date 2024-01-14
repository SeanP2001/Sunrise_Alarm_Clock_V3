/**
 * @file App.h
 * @author Sean Price
 * @brief Implements the concrete functions from the App base class.
 * @version 0.1
 * @date 13/01/2024
 * 
 * 
 */

 #include "App.h"

//---------------------------------------------------- C O N S T R U C T O R ----------------------------------------------------
App::App(Hardware& hardware) : hw(hardware), openFlag(false) {} 


//------------------------------------------------------- O P E N   A P P -------------------------------------------------------
void App::openApp()
{
  openFlag = true;
}


//------------------------------------------------------ C L O S E   A P P ------------------------------------------------------
void App::closeApp()
{
  openFlag = false;
}


//-------------------------------------------------------- I S   O P E N --------------------------------------------------------
bool App::isOpen() const
{
  return openFlag;
}