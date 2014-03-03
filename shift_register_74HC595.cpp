/*
  shift_register_74hc595.h - Library for running 74HC595 shift registers.
  Created by Geoffrey A. Thomas, February 9, 2014.
 */

#include "Arduino.h"
#include "shift_register_74hc595.h"

// The number of output pins on the 74HC595
#define NBR_REG_PINS 8

shift_register_74hc595::shift_register_74hc595(int iNbrChainedRegisters_, int iSerPin_, int iSerClkPin_, int iRegClkPin_)
{
   iSerPin = iSerPin_;
   iSerClkPin = iSerClkPin_;
   iRegClkPin = iRegClkPin_;

   iNbrRegPins = iNbrChainedRegisters_ * NBR_REG_PINS;

   pinMode(iSerPin, OUTPUT);
   pinMode(iSerClkPin, OUTPUT);
   pinMode(iRegClkPin, OUTPUT);

   // allocate a space for the buffer to store register state
   pbRegisterState = (bool *)(malloc(sizeof(bool) * iNbrRegPins));

   //reset all register pins
   clearRegisters();
   writeRegisters();
}


//set all register pins to LOW
void shift_register_74hc595::clearRegisters(void)
{
   for(int i = iNbrRegPins - 1; i >=  0; i--)
   {
      pbRegisterState[i] = LOW;
   }
}


//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)
void shift_register_74hc595::writeRegisters(void)
{
   digitalWrite(iRegClkPin, LOW);

   for(int i = iNbrRegPins - 1; i >=  0; i--)
   {
      bool bVal = pbRegisterState[i];

      digitalWrite(iSerClkPin, LOW);
      digitalWrite(iSerPin, bVal);
      digitalWrite(iSerClkPin, HIGH);
   }

   digitalWrite(iRegClkPin, HIGH);
}

//set an individual pin HIGH or LOW
void shift_register_74hc595::setRegisterPin(int iPin_, bool bVal_)
{
   pbRegisterState[iPin_] = bVal_;
}

bool shift_register_74hc595::getRegisterPin(int iPin_)
{
   return pbRegisterState[iPin_];
}
