/*
  wiring_analog.c - analog input and output
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

#include "wiring_private.h"
#include "pins_arduino.h"

uint8_t analog_reference = DEFAULT;

void analogReference(uint8_t mode)
{
	// can't actually set the register here because the default setting
	// will connect AVCC and the AREF pin, which would cause a short if
	// there's something connected to AREF.
	analog_reference = mode;
}

int analogRead(uint8_t pin)
{
	/*
	uint8_t low, high;

#if defined(analogPinToChannel)
#if defined(__AVR_ATmega32U4__)
	if (pin >= 18) pin -= 18; // allow for channel or pin numbers
#endif
	pin = analogPinToChannel(pin);
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
	if (pin >= 54) pin -= 54; // allow for channel or pin numbers
#elif defined(__AVR_ATmega32U4__)
	if (pin >= 18) pin -= 18; // allow for channel or pin numbers
#elif defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega644__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644PA__)
	if (pin >= 24) pin -= 24; // allow for channel or pin numbers
#else
	if (pin >= 14) pin -= 14; // allow for channel or pin numbers
#endif

#if defined(ADCSRB) && defined(MUX5)
	// the MUX5 bit of ADCSRB selects whether we're reading from channels
	// 0 to 7 (MUX5 low) or 8 to 15 (MUX5 high).
	ADCSRB = (ADCSRB & ~(1 << MUX5)) | (((pin >> 3) & 0x01) << MUX5);
#endif
  
	// set the analog reference (high two bits of ADMUX) and select the
	// channel (low 4 bits).  this also sets ADLAR (left-adjust result)
	// to 0 (the default).
#if defined(ADMUX)
	ADMUX = (analog_reference << 6) | (pin & 0x07);
#endif

	// without a delay, we seem to read from the wrong channel
	//delay(1);

#if defined(ADCSRA) && defined(ADCL)
	// start the conversion
	sbi(ADCSRA, ADSC);

	// ADSC is cleared when the conversion finishes
	while (bit_is_set(ADCSRA, ADSC));

	// we have to read ADCL first; doing so locks both ADCL
	// and ADCH until ADCH is read.  reading ADCL second would
	// cause the results of each conversion to be discarded,
	// as ADCL and ADCH would be locked when it completed.
	low  = ADCL;
	high = ADCH;
#else
	// we dont have an ADC, return 0
	low  = 0;
	high = 0;
#endif

	// combine the two bytes
	return (high << 8) | low;
	*/
	return 0; // hossam: remove me when you start to code the analog part plz :)
}

// Right now, PWM output only works on the pins with
// hardware support.  These are defined in the appropriate
// pins_*.c file.  For the rest of the pins, we default
// to digital output.

// TODO: Asmaa: edit this section from AVR to RL78
void analogWrite(uint8_t pin, int val)
{
	uint8_t timer = digitalPinToTimer(pin);

	// We need to make sure the PWM output is enabled for those pins
	// that support it, as we turn it off when digitally reading or
	// writing with them.  Also, make sure the pin is in output mode
	// for consistenty with Wiring, which doesn't require a pinMode
	// call for the analog output pins.
	pinMode(pin, OUTPUT);
	if (val <= 0)
	{
		digitalWrite(pin, LOW);
	}
	else if (val >= 255)
	{
		digitalWrite(pin, HIGH);
	}
	else
	{
		switch(digitalPinToTimer(pin))
		{

		// FIXME: Add support for OS Timers :)
			//START Unit 0
			case TIMER01:
				TMIF00 = 0U;    /* clear INTTM00 interrupt flag */
				TMMK00 = 0U;    /* enable INTTM00 interrupt */
				TMIF01 = 0U;    /* clear INTTM01 interrupt flag */
				TMMK01 = 0U;    /* enable INTTM01 interrupt */

				TDR01 = dutyToTDRmp(val, msperiodToTDRmn(1.024));

				TOE0 |= _BV(1); // Enable channel 1 in unit 0
				TS0 |= _BV(0) | _BV(1); // Start channel 0 (master) and channel 1 (slave)

				break;
				// Hussein continue the timers period 2.04ms for [unit0] master channel 2 - ch3 to ch7 (slaves)
				// for unit1 master channel 0 - ch1 to ch7 (slaves)


			case TIMER03:
				TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
				TMMK02 = 0U;    /* enable INTTM02 interrupt */
				TMIF03 = 0U;    /* clear INTTM03 interrupt flag */
				TMMK03 = 0U;    /* enable INTTM03 interrupt */

				TDR03 = dutyToTDRmp(val, msperiodToTDRmn(2.04));

				TOE0 |= _BV(3); // Enable channel 3 in unit 0
				TS0 |= _BV(2) | _BV(3); // Start channel 2 (master) and channel 3 (slave)

				break;

			case TIMER04:
				TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
				TMMK02 = 0U;    /* enable INTTM02 interrupt */
				TMIF04 = 0U;    /* clear INTTM04 interrupt flag */
				TMMK04 = 0U;    /* enable INTTM04 interrupt */

				TDR04 = dutyToTDRmp(val, msperiodToTDRmn(2.04));

				TOE0 |= _BV(4); // Enable channel 4 in unit 0
				TS0 |= _BV(2) | _BV(4); // Start channel 2 (master) and channel 4 (slave)

				break;

			case TIMER05:
				TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
				TMMK02 = 0U;    /* enable INTTM02 interrupt */
				TMIF05 = 0U;    /* clear INTTM05 interrupt flag */
				TMMK05 = 0U;    /* enable INTTM05 interrupt */

				TDR05 = dutyToTDRmp(val, msperiodToTDRmn(2.04));

				TOE0 |= _BV(5); // Enable channel 5 in unit 0
				TS0 |= _BV(2) | _BV(5); // Start channel 2 (master) and channel 5 (slave)

				break;

			case TIMER06:
				TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
				TMMK02 = 0U;    /* enable INTTM02 interrupt */
				TMIF06 = 0U;    /* clear INTTM06 interrupt flag */
				TMMK06 = 0U;    /* enable INTTM06 interrupt */

				TDR06 = dutyToTDRmp(val, msperiodToTDRmn(2.04));

				TOE0 |= _BV(6); // Enable channel 6 in unit 0
				TS0 |= _BV(2) | _BV(6); // Start channel 2 (master) and channel 6 (slave)

				break;
				
			case TIMER07:
				TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
				TMMK02 = 0U;    /* enable INTTM02 interrupt */
				TMIF07 = 0U;    /* clear INTTM07 interrupt flag */
				TMMK07 = 0U;    /* enable INTTM07 interrupt */

				TDR07 = dutyToTDRmp(val, msperiodToTDRmn(2.04));

				TOE0 |= _BV(7); // Enable channel 7 in unit 0
				TS0 |= _BV(2) | _BV(7); // Start channel 2 (master) and channel 7 (slave)

				break;
			//END Unit 0

			//START Unit 1
			case TIMER11:
				TMIF10 = 0U;    /* clear INTTM10 interrupt flag */
				TMMK10 = 0U;    /* enable INTTM10 interrupt */
				TMIF11 = 0U;    /* clear INTTM11 interrupt flag */
				TMMK11 = 0U;    /* enable INTTM11 interrupt */

				TDR11 = dutyToTDRmp(val, msperiodToTDRmn(2.04));

				TOE1 |= _BV(1); // Enable channel 1 in unit 1
				TS1 |= _BV(0) | _BV(1); // Start channel 0 (master) and channel 1 (slave)

				break;

			case TIMER12:
				TMIF10 = 0U;    /* clear INTTM10 interrupt flag */
				TMMK10 = 0U;    /* enable INTTM10 interrupt */
				TMIF12 = 0U;    /* clear INTTM12 interrupt flag */
				TMMK12 = 0U;    /* enable INTTM12 interrupt */

				TDR12 = dutyToTDRmp(val, msperiodToTDRmn(2.04));

				TOE1 |= _BV(2); // Enable channel 2 in unit 1
				TS1 |= _BV(0) | _BV(2); // Start channel 0 (master) and channel 2 (slave)

				break;

			case TIMER13:
				TMIF10 = 0U;    /* clear INTTM10 interrupt flag */
				TMMK10 = 0U;    /* enable INTTM10 interrupt */
				TMIF13 = 0U;    /* clear INTTM13 interrupt flag */
				TMMK13 = 0U;    /* enable INTTM13 interrupt */

				TDR13 = dutyToTDRmp(val, msperiodToTDRmn(2.04));

				TOE1 |= _BV(3); // Enable channel 3 in unit 0
				TS1 |= _BV(0) | _BV(3); // Start channel 0 (master) and channel 3 (slave)

				break;

			case TIMER14:
				TMIF10 = 0U;    /* clear INTTM10 interrupt flag */
				TMMK10 = 0U;    /* enable INTTM10 interrupt */
				TMIF14 = 0U;    /* clear INTTM14 interrupt flag */
				TMMK14 = 0U;    /* enable INTTM14 interrupt */

				TDR14 = dutyToTDRmp(val, msperiodToTDRmn(2.04));

				TOE1 |= _BV(4); // Enable channel 4 in unit 1
				TS1 |= _BV(0) | _BV(4); // Start channel 0 (master) and channel 4 (slave)

				break;

			case TIMER15:
				TMIF10 = 0U;    /* clear INTTM10 interrupt flag */
				TMMK10 = 0U;    /* enable INTTM10 interrupt */
				TMIF15 = 0U;    /* clear INTTM15 interrupt flag */
				TMMK15 = 0U;    /* enable INTTM15 interrupt */

				TDR15 = dutyToTDRmp(val, msperiodToTDRmn(2.04));

				TOE1 |= _BV(5); // Enable channel 5 in unit 1
				TS1 |= _BV(0) | _BV(5); // Start channel 0 (master) and channel 5 (slave)

				break;

			case TIMER16:
				TMIF10 = 0U;    /* clear INTTM10 interrupt flag */
				TMMK10 = 0U;    /* enable INTTM10 interrupt */
				TMIF16 = 0U;    /* clear INTTM16 interrupt flag */
				TMMK16 = 0U;    /* enable INTTM16 interrupt */

				TDR16 = dutyToTDRmp(val, msperiodToTDRmn(2.04));

				TOE1 |= _BV(6); // Enable channel 6 in unit 1
				TS1 |= _BV(0) | _BV(6); // Start channel 0 (master) and channel 6 (slave)

				break;

			case TIMER17:
				TMIF10 = 0U;    /* clear INTTM10 interrupt flag */
				TMMK10 = 0U;    /* enable INTTM10 interrupt */
				TMIF17 = 0U;    /* clear INTTM17 interrupt flag */
				TMMK17 = 0U;    /* enable INTTM17 interrupt */

				TDR17 = dutyToTDRmp(val, msperiodToTDRmn(2.04));

				TOE1 |= _BV(7); // Enable channel 7 in unit 1
				TS1 |= _BV(0) | _BV(7); // Start channel 0 (master) and channel 7 (slave)

				break;
			//END Unit 1

			case NOT_ON_TIMER:
			default:
				if (val < 128) {
					digitalWrite(pin, LOW);
				} else {
					digitalWrite(pin, HIGH);
				}
		}
	}

}

