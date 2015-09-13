/*
  wiring_digital.c - digital input and output functions
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2005-2006 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  Modified 28 September 2010 by Mark Sproul
*/

#ifndef WiringPrivate_h
#include "wiring_private.h"
#endif

//#ifndef Pins_Arduino_h
#include "pins_arduino.h"
//#endif

// FIXME: pinMode to support RL78 uC
void pinMode(uint8_t pin, uint8_t mode)
{
	uint8_t bit = digitalPinToBitMask(pin);		// Hossam: Create this function plz :p
	uint8_t port = digitalPinToPort(pin);		// HUSSEIN: Create this function plz :)
	volatile uint8_t *reg, *out, *pull;

	if (port == NOT_A_PIN) return;

	// JWS: can I let the optimizer do this?
	reg = portModeRegister(port); 				// Hussein: Create this function plz :)
	out = portOutputRegister(port);				// Hussein: Create this function plz :)
	pull = portPullRegister(port);	//FIXME: Asmaa: PU configuration

// Ammar & asmaa & magdy : 3eeeesh ya 3ammaaaaar enta we asmaaaaaaa we magdyyyyyy :D
	if (mode == INPUT) { 
		//uint8_t oldSREG = SREG;
        cli();
		//DI();
        //FIXME: check this info -> Set all the ports by default PM as an input in the init function
		*reg |= bit;
		*out &= ~bit;
		//SREG = oldSREG;
	} else if (mode == INPUT_PULLUP) {
		//uint8_t oldSREG = SREG;
        cli();
		//DI();
		*reg |= bit;
		//*out |= bit;
		*pull |= bit;
		//SREG = oldSREG;
	} else {
		//uint8_t oldSREG = SREG;
        cli();
		//DI();
		*reg &= ~bit;
		//SREG = oldSREG;
	}
}


void digitalWrite(uint8_t pin, uint8_t val)
{
	//uint8_t timer = digitalPinToTimer(pin); // TODO: Hussein: After hussein finish this function uncomment this
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	volatile uint8_t *out;

	if (port == NOT_A_PIN) return;

	// If the pin that support PWM output, we need to turn it off
	// before doing a digital write.
	//if (timer != NOT_ON_TIMER) turnOffPWM(timer); // TODO: Hussein: uncomment this line when finish this function

	out = portOutputRegister(port);

	//uint8_t oldSREG = SREG;
	cli();
	//DI();

	if (val == LOW) {
		*out &= ~bit;
	} else {
		*out |= bit;
	}

	//SREG = oldSREG;
}

int digitalRead(uint8_t pin)
{
	//uint8_t timer = digitalPinToTimer(pin);
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);

	if (port == NOT_A_PIN) return LOW;

	// If the pin that support PWM output, we need to turn it off
	// before getting a digital reading.
	//if (timer != NOT_ON_TIMER) turnOffPWM(timer);

	if (*portInputRegister(port) & bit) return HIGH;
	return LOW;
}
