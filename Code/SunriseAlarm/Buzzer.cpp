/**
 * @file Buzzer.cpp
 * @author Sean Price
 * @brief Implements the Buzzer class.
 * @version 0.1
 * @date 13/01/2024
 * 
 * 
 */

#include "Buzzer.h"

const int Buzzer::DEFAULT_FREQUENCY = 2000; 

//---------------------------------------------------- C O N S T R U C T O R ----------------------------------------------------
Buzzer::Buzzer(uint8_t pinNo) : pinNo(pinNo), sounding(false), freq(DEFAULT_FREQUENCY) {pinMode(pinNo, OUTPUT);}

//------------------------------------------------------ P L A Y   T O N E ------------------------------------------------------
void Buzzer::playTone()
{
  sounding = true;
  tone(pinNo, freq);
}

//------------------------------------------------------ S T O P   T O N E ------------------------------------------------------
void Buzzer::stopTone()
{
  sounding = false;
  noTone(pinNo);
}

//---------------------------------------------------- I S   S O U N D I N G ----------------------------------------------------
bool Buzzer::isSounding()
{
  return sounding;
}

//--------------------------------------------------------- T O G G L E ---------------------------------------------------------
void Buzzer::toggle()
{
  if(isSounding())
  {
    playTone();
  }
  else
  {
    stopTone();
  }
}