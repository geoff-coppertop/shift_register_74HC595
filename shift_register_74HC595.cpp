/*
  shift_register_74hc595.h - Library for running 74HC595 shift registers.
  Created by Geoffrey A. Thomas, February 9, 2014.
 */

#include "Arduino.h"
#include "shift_register_74hc595.h"

// The number of output pins on the 74HC595
#define NBR_REG_PINS 8

shift_register_74hc595::shift_register_74hc595(unsigned int uiNbrChainedRegisters_, unsigned int uiSerPin_, unsigned int uiSerClkPin_, unsigned int uiRegClkPin_)
{
   uiSerPin = uiSerPin_;
   uiSerClkPin = uiSerClkPin_;
   uiRegClkPin = uiRegClkPin_;

   uiNbrRegPins = uiNbrChainedRegisters_ * NBR_REG_PINS;

   pinMode(uiSerPin, OUTPUT);
   pinMode(uiSerClkPin, OUTPUT);
   pinMode(uiRegClkPin, OUTPUT);

   // allocate a space for the buffer to store register state
   pbRegisterState = (bool *)(malloc(sizeof(bool) * uiNbrRegPins));

   //reset all register pins
   clear();
   write();
}


//set all register pins to LOW
void shift_register_74hc595::clear(void)
{
   for(unsigned int i = uiNbrRegPins - 1; i >=  0; i--)
   {
      pbRegisterState[i] = LOW;
   }
}


//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)
void shift_register_74hc595::write(void)
{
   digitalWrite(uiRegClkPin, LOW);

   for(int i = uiNbrRegPins - 1; i >=  0; i--)
   {
      bool bVal = pbRegisterState[i];

      digitalWrite(uiSerClkPin, LOW);
      digitalWrite(uiSerPin, bVal);
      digitalWrite(uiSerClkPin, HIGH);
   }

   digitalWrite(uiRegClkPin, HIGH);
}

//set an individual pin HIGH or LOW
void shift_register_74hc595::setPin(unsigned int uiPin_, bool bVal_)
{
   if(uiPin_ >= uiNbrRegPins)
   {
      return;
   }

   pbRegisterState[uiPin_] = bVal_;
}

bool shift_register_74hc595::getPin(unsigned int uiPin_)
{
   if(uiPin_ >= uiNbrRegPins)
   {
      return LOW;
   }
   else
   {
      return pbRegisterState[uiPin_];
   }
}
