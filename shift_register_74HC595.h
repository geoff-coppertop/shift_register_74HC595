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
      shift_register_74hc595(unsigned int uiNbrChainedRegisters_, unsigned int uiSerPin_, unsigned int uiSerClkPin_, unsigned int uiRegClkPin_);

      void clear(void);
      void write(void);
      void setPin(unsigned int uiPin_, bool bVal_);
      bool getPin(unsigned int uiPin_);

   private:
      bool *pbRegisterState;

      unsigned int uiNbrRegPins;
      unsigned int uiSerPin;
      unsigned int uiSerClkPin;
      unsigned int uiRegClkPin;
};

#endif /* SHIFT_REGISTER_74HC595_H_ */
