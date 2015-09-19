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
	pull = portPullRegister(port);				// FIXME: Asmaa: PU configuration

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

// Forcing this inline keeps the callers from having to push their own stuff
// on the stack. It is a good performance win and only takes 1 more byte per
// user than calling. (It will take more bytes on the 168.)
//
// But shouldn't this be moved into pinMode? Seems silly to check and do on
// each digitalread or write.
//
// Mark Sproul:
// - Removed inline. Save 170 bytes on atmega1280
// - changed to a switch statment; added 32 bytes but much easier to read and maintain.
// - Added more #ifdefs, now compiles for atmega645
//
//static inline void turnOffPWM(uint8_t timer) __attribute__ ((always_inline));
//static inline void turnOffPWM(uint8_t timer)
static void turnOffPWM(uint8_t timer)
{
	switch (timer)
	{
	// FIXME: Add support for OS Timers :)
	// START Unit 0
	case TIMER01:
		TMIF00 = 0U;    /* clear INTTM00 interrupt flag */
		TMMK00 = 1U;    /* disable INTTM00 interrupt */
		TMIF01 = 0U;    /* clear INTTM01 interrupt flag */
		TMMK01 = 1U;    /* disable INTTM01 interrupt */

		TOE0 &= ~_BV(1); // Disable channel 1 in unit 0
		TT0 |= _BV(0) | _BV(1); // Stop channel 0 (master) and channel 1 (slave)

		break;
		// Hussein continue the timers period 2.04ms for [unit0] master channel 2 - ch3 to ch7 (slaves)
		// for unit1 master channel 0 - ch1 to ch7 (slaves)


	case TIMER03:
		TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
		TMMK02 = 1U;    /* disable INTTM02 interrupt */
		TMIF03 = 0U;    /* clear INTTM03 interrupt flag */
		TMMK03 = 1U;    /* disable INTTM03 interrupt */

		TOE0 &= ~_BV(3); // Disable channel 3 in unit 0
		TT0 |= _BV(2) | _BV(3); // Stop channel 2 (master) and channel 3 (slave)

		break;

	case TIMER04:
		TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
		TMMK02 = 1U;    /* disable INTTM02 interrupt */
		TMIF04 = 0U;    /* clear INTTM04 interrupt flag */
		TMMK04 = 1U;    /* disable INTTM04 interrupt */

		TOE0 &= ~_BV(4); // Disable channel 4 in unit 0
		TT0 |= _BV(2) | _BV(4); // Stop channel 2 (master) and channel 4 (slave)

		break;

	case TIMER05:
		TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
		TMMK02 = 1U;    /* disable INTTM02 interrupt */
		TMIF05 = 0U;    /* clear INTTM05 interrupt flag */
		TMMK05 = 1U;    /* disable INTTM05 interrupt */

		TOE0 &= ~_BV(5); // Disable channel 5 in unit 0
		TT0 |= _BV(2) | _BV(5); // Stop channel 2 (master) and channel 5 (slave)

		break;

	case TIMER06:
		TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
		TMMK02 = 1U;    /* disable INTTM02 interrupt */
		TMIF06 = 0U;    /* clear INTTM06 interrupt flag */
		TMMK06 = 1U;    /* disable INTTM06 interrupt */

		TOE0 &= ~_BV(6); // Disable channel 6 in unit 0
		TT0 |= _BV(2) | _BV(6); // Stop channel 2 (master) and channel 6 (slave)

		break;

	case TIMER07:
		TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
		TMMK02 = 1U;    /* disable INTTM02 interrupt */
		TMIF07 = 0U;    /* clear INTTM07 interrupt flag */
		TMMK07 = 1U;    /* disable INTTM07 interrupt */

		TOE0 &= ~_BV(7); // Disable channel 7 in unit 0
		TT0 |= _BV(2) | _BV(7); // Stop channel 2 (master) and channel 7 (slave)

		break;
	//END Unit 0

	//START Unit 1
	case TIMER11:
		TMIF10 = 0U;    /* clear INTTM10 interrupt flag */
		TMMK10 = 1U;    /* disable INTTM10 interrupt */
		TMIF11 = 0U;    /* clear INTTM11 interrupt flag */
		TMMK11 = 1U;    /* disable INTTM11 interrupt */

		TOE1 &= ~_BV(1); // Disable channel 1 in unit 1
		TT1 |= _BV(0) | _BV(1); // Stop channel 0 (master) and channel 1 (slave)

		break;

	case TIMER12:
		TMIF10 = 0U;    /* clear INTTM10 interrupt flag */
		TMMK10 = 1U;    /* disable INTTM10 interrupt */
		TMIF12 = 0U;    /* clear INTTM12 interrupt flag */
		TMMK12 = 1U;    /* disable INTTM12 interrupt */

		TOE1 &= ~_BV(2); // Disable channel 2 in unit 1
		TT1 |= _BV(0) | _BV(2); // Stop channel 0 (master) and channel 2 (slave)

		break;

	case TIMER13:
		TMIF10 = 0U;    /* clear INTTM10 interrupt flag */
		TMMK10 = 1U;    /* disable INTTM10 interrupt */
		TMIF13 = 0U;    /* clear INTTM13 interrupt flag */
		TMMK13 = 1U;    /* disable INTTM13 interrupt */

		TOE1 &= ~_BV(3); // Disable channel 3 in unit 0
		TT1 |= _BV(0) | _BV(3); // Stop channel 0 (master) and channel 3 (slave)

		break;

	case TIMER14:
		TMIF10 = 0U;    /* clear INTTM10 interrupt flag */
		TMMK10 = 1U;    /* disable INTTM10 interrupt */
		TMIF14 = 0U;    /* clear INTTM14 interrupt flag */
		TMMK14 = 1U;    /* disable INTTM14 interrupt */

		TOE1 &= ~_BV(4); // Disable channel 4 in unit 1
		TT1 |= _BV(0) | _BV(4); // Stop channel 0 (master) and channel 4 (slave)

		break;

	case TIMER15:
		TMIF10 = 0U;    /* clear INTTM10 interrupt flag */
		TMMK10 = 1U;    /* disable INTTM10 interrupt */
		TMIF15 = 0U;    /* clear INTTM15 interrupt flag */
		TMMK15 = 1U;    /* disable INTTM15 interrupt */

		TOE1 &= ~_BV(5); // Disable channel 5 in unit 1
		TT1 |= _BV(0) | _BV(5); // Stop channel 0 (master) and channel 5 (slave)

		break;

	case TIMER16:
		TMIF10 = 0U;    /* clear INTTM10 interrupt flag */
		TMMK10 = 1U;    /* disable INTTM10 interrupt */
		TMIF16 = 0U;    /* clear INTTM16 interrupt flag */
		TMMK16 = 1U;    /* disable INTTM16 interrupt */

		TOE1 &= ~_BV(6); // Disable channel 6 in unit 1
		TT1 |= _BV(0) | _BV(6); // Stop channel 0 (master) and channel 6 (slave)

		break;

	case TIMER17:
		TMIF10 = 0U;    /* clear INTTM10 interrupt flag */
		TMMK10 = 1U;    /* disable INTTM10 interrupt */
		TMIF17 = 0U;    /* clear INTTM17 interrupt flag */
		TMMK17 = 1U;    /* disable INTTM17 interrupt */

		TOE1 &= ~_BV(7); // Disable channel 7 in unit 1
		TT1 |= _BV(0) | _BV(7); // Stop channel 0 (master) and channel 7 (slave)

		break;
	//END Unit 1
	}
}


void digitalWrite(uint8_t pin, uint8_t val)
{
	uint8_t timer = digitalPinToTimer(pin); // Hussein: After hussein finish this function uncomment this
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	volatile uint8_t *out;

	if (port == NOT_A_PIN) return;

	// If the pin that support PWM output, we need to turn it off
	// before doing a digital write.
	if (timer != NOT_ON_TIMER) turnOffPWM(timer); // Hossam: uncomment this line when finish this function

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
	uint8_t timer = digitalPinToTimer(pin);
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);

	if (port == NOT_A_PORT) return LOW;

	// If the pin that support PWM output, we need to turn it off
	// before getting a digital reading.
	if (timer != NOT_ON_TIMER) turnOffPWM(timer);

	if (*portInputRegister(port) & bit) return HIGH;
	return LOW;
}
