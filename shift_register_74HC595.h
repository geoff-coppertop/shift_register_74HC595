/*
 * shift_register_74HC595.h
 *
 *  Created on: Mar 2, 2014
 *      Author: coppertop
 */

#ifndef SHIFT_REGISTER_74HC595_H_
#define SHIFT_REGISTER_74HC595_H_

#include "Arduino.h"

class shift_register_74hc595
{
   public:
      shift_register_74hc595(int iNbrChainedRegisters_, int iSerPin_, int iSerClkPin_, int iRegClkPin_);

      void clearRegisters(void);
      void writeRegisters(void);
      void setRegisterPin(int iPin_, bool bVal_);
      bool getRegisterPin(int iPin_);

   private:
      bool *pbRegisterState;

      int iNbrRegPins;
      int iSerPin;
      int iSerClkPin;
      int iRegClkPin;
};

#endif /* SHIFT_REGISTER_74HC595_H_ */
