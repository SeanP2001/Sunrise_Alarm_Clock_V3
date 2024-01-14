/**
 * @file Buzzer.h
 * @author Sean Price
 * @brief Defines the Buzzer class.
 * @version 0.1
 * @date 13/01/2024
 * 
 * 
 */

#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

/**
 * @class Buzzer
 * @brief A class representing a buzzer connected to a pin on the microcontroller.
 * 
 * This class implements basic functionality to control a passive buzzer.
 * 
 */
class Buzzer
{
  private:
    uint8_t pinNo;   ///< The number of the pin which the buzzer is connected to.
    bool sounding;   ///< Whether the buzzer is currently sounding (true) or silent (false)
    int freq;        ///< The frequency at which the buzzer sounds

    const static int DEFAULT_FREQUENCY;   ///< By default the buzzer is set to sound at 2kHz
    
  public:
    /**
     * @brief Construct a new Buzzer object
     * 
     * @param pinNo The number of the pin which the buzzer is connected to.
     */
    Buzzer(uint8_t pinNo);


    /**
     * @brief Turn ON the buzzer and make it sound.
     * 
     * Uses the tone() function.
     */
    void playTone();

    /**
     * @brief Turn OFF the buzzer and make it silent.
     * 
     * Uses the noTone() function.
     */
    void stopTone();


    /**
     * @brief Get the current status of the buzzer.
     * 
     * @return true if the buzzer is currently producing a sound.
     * @return false if the buzzer is currently silent.
     */
    bool isSounding();


    /**
     * @brief Toggle the state of the buzzer.
     * 
     * If the buzzer is sounding, stop it.
     * If the buzzer is silent, play a tone.
     * 
     */
    void toggle();
};

#endif // BUZZER_H