/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

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
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

/*
 * To define the PU include iodefine_ext.h
 */
//#ifndef	IODEFINE_EXT_H
#include "iodefine_ext.h"
//#endif

/*
 * To define the P and PM include iodefine.h
 */
#include "iodefine.h"


/*
 *  This macro takes the bit number and returns the bit mask
 */
#define _BV(bit) (1<<bit)	//FIXME: Move this macro to a suitable library

#ifndef VALDUINO
#define VALDUINO
#endif

//HUSSEIN: ADD VALDUINO DEFINE HERE PLZ
#ifdef VALDUINO

//FIXME: add array to program memory
volatile uint8_t digital_pin_to_port_PGM[] = {
	NOT_A_PORT,
	_P15,
	_P15,
	_P15,
	_P15,
	_P4,
	_P4,
	_P4,
	_P4,
	_P4,
	_P4,
	_P4,
	_P4,
	NOT_A_PORT,
	_P12,
	_P12,
	_P13,
	_P12,
	_P12,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	_P6,
	_P6,
	_P6,
	_P6,
	_P6,
	_P6,
	_P6,
	_P6,
	_P15,
	_P15,
	_P0,
	_P15,
	_P15,
	_P14,
	_P13,
	_P7,
	_P7,
	_P7,
	_P7,
	NOT_A_PORT,
	_P7,
	_P7,
	_P7,
	_P7,
	_P0,
	_P3,
	_P3,
	_P1,
	_P1,
	NOT_A_PORT,
	_P1,
	_P3,
	_P5,
	_P5,
	_P5,
	_P5,
	_P1,
	_P1,
	_P1,
	_P1,
	_P1,
	_P5,
	_P5,
	_P5,
	_P10,
	_P10,
	_P10,
	_P10,
	_P3,
	_P3,
	_P5,
	_P8,
	_P8,
	_P8,
	_P8,
	_P8,
	_P8,
	_P8,
	_P8,
	_P9,
	_P9,
	_P9,
	_P9,
	_P9,
	_P9,
	_P9,
	_P9,
	_P10,
	_P10,
	_P10,
	_P10,
	_P0,
	_P12,
	_P12,
	_P0,
	_P12,
	_P12,
};

//FIXME: add array to program memory
volatile uint8_t *  port_to_output_PGM[] = {
	&P0,
	&P1,
	(volatile uint8_t*)NOT_A_PORT,
	&P3,
	&P4,
	&P5,
	&P6,
	&P7,
	&P8,
	&P9,
	&P10,
	(volatile uint8_t*)NOT_A_PORT,
	&P12,
	&P13,
	&P14,
	&P15,
};

//FIXME: add array to program memory
//FIXME: port 13 doesn't have a macro PM13
volatile uint8_t * port_to_mode_PGM[] = {
	&PM0,
	&PM1,
	(volatile uint8_t*)NOT_A_PORT,
	&PM3,
	&PM4,
	&PM5,
	&PM6,
	&PM7,
	&PM8,
	&PM9,
	&PM10,
	(volatile uint8_t*)NOT_A_PORT,
	&PM12,
	(volatile uint8_t*)NOT_A_PORT,
	&PM14,
	&PM15,
};

volatile uint8_t * port_to_pullup_PGM[] = {
	&PU0,
	&PU1,
	(volatile uint8_t*)NOT_A_PORT,
	&PU3,
	&PU4,
	&PU5,
	&PU6,
	&PU7,
	(volatile uint8_t*)NOT_A_PORT,
	(volatile uint8_t*)NOT_A_PORT,
	&PU10,
	(volatile uint8_t*)NOT_A_PORT,
	&PU12,
	(volatile uint8_t*)NOT_A_PORT,
	&PU14,
	&PU15,
};

volatile uint8_t digital_pin_to_bit_mask_PGM[] = {
	NOT_A_PIN,
	_BV(3),	/*P15*/
	_BV(2),
	_BV(1),
	_BV(0),
	_BV(7),	/*P4*/
	_BV(6),
	_BV(5),
	_BV(4),
	_BV(3),
	_BV(2),
	_BV(1),
	_BV(0),
	NOT_A_PIN,
	_BV(4),	/*P12*/
	_BV(3),
	_BV(7),	/*P13*/
	_BV(2),
	_BV(1),
	NOT_A_PIN,
	NOT_A_PIN,
	NOT_A_PIN,
	NOT_A_PIN,
	NOT_A_PIN,
	_BV(0),	/*P6*/
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(4),	/*P15*/
	_BV(5),
	_BV(0),	/*P0*/
	_BV(6),	/*P15*/
	_BV(7),
	_BV(0),	/*P14*/
	_BV(0),	/*P13*/
	_BV(7),	/*P7*/
	_BV(6),
	_BV(5),
	_BV(4),
	NOT_A_PIN,
	_BV(3),	/*P7*/
	_BV(2),
	_BV(1),
	_BV(0),
	_BV(3),	/*P0*/
	_BV(2),	/*P3*/
	_BV(0),
	_BV(7),	/*P1*/
	_BV(6),
	NOT_A_PIN,
	_BV(5),	/*P1*/
	_BV(1),	/*P3*/
	_BV(0),	/*P5*/
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),	/*P1*/
	_BV(3),
	_BV(2),
	_BV(1),
	_BV(0),
	_BV(4),	/*P5*/
	_BV(5),
	_BV(6),
	_BV(7),	/*P10*/
	_BV(6),
	_BV(5),
	_BV(4),
	_BV(3),	/*P3*/
	_BV(4),
	_BV(7),	/*P5*/
	_BV(0),	/*P8*/
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0),	/*P9*/
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0),	/*P10*/
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(2),	/*P0*/
	_BV(7),	/*P12*/
	_BV(6),
	_BV(1),	/*P0*/
	_BV(5),	/*P12*/
	_BV(0),
};

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_MONITOR   Serial
#define SERIAL_PORT_HARDWARE  Serial

#endif
