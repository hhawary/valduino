/*
  Arduino.h - Main include file for the Arduino SDK
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#ifndef F_CPU
#define F_CPU	32000000UL
#endif

#include "iodefine.h"

#ifndef VALDUINO
#define VALDUINO
#endif

#ifndef Arduino_h
#define Arduino_h

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#ifdef ARDUINO_MAIN
#include <avr/pgmspace.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#endif

#include "binary.h"
//#include "pins_arduino.h"

#ifdef __cplusplus
extern "C"{
#endif

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

#define SERIAL  0x0
#define DISPLAY 0x1

#define LSBFIRST 0
#define MSBFIRST 1

#define CHANGE 1
#define FALLING 2
#define RISING 3

#define DEFAULT 1
#define EXTERNAL 0
#endif

// undefine stdlib's abs if encountered
#ifdef abs
#undef abs
#endif

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

#define interrupts() EI()
#define noInterrupts() DI()


/*
 *  This macro takes the bit number and returns the bit mask
 */
#define _BV(bit) (1<<bit)	//FIXME: Move this macro to a suitable library

#define sei() EI()
#define cli() DI()

#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
//#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )
//#define microsecondsToClockCycles(a) ( (a) * clockCyclesPerMicrosecond() )

#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

typedef unsigned int word;

#define bit(b) (1UL << (b))

typedef bool boolean;
typedef uint8_t byte;

void init(void);
void initVariant(void);

int atexit(void (*func)()) __attribute__((weak));

void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);
int analogRead(uint8_t);
void analogReference(uint8_t mode);
void analogWrite(uint8_t, int);

void setup(void);
void loop(void);


// Get the bit location within the hardware port of the given virtual pin.
// This comes from the pins_*.c file for the active board configuration.
// 
// These perform slightly better as macros compared to inline functions
//
#define digitalPinToPort(P) digital_pin_to_port_PGM[P]
#define digitalPinToBitMask(P) digital_pin_to_bit_mask_PGM[P]
//http://garretlab.web.fc2.com/en/arduino/inside/arduino/Arduino.h/portOutputRegister.html
#define portOutputRegister(P) port_to_output_PGM[P]
#define portInputRegister(P) port_to_output_PGM[P]
#define portPullRegister(P)	port_to_pullup_PGM[P]
#define portModeRegister(P) port_to_mode_PGM[P]
#define digitalPinToTimer(P) digital_pin_to_timer_PGM[P] // Hussein: edit this to select the timer map it with a io port

#define NOT_A_PIN 255
#define NOT_A_PORT 255
//Asmaa: Edit this part to define all the timer channels here

#define NOT_ON_TIMER 0
#define TIMER00 1
#define TIMER01 2
#define TIMER02 3
#define TIMER03 4
#define TIMER04 5
#define TIMER05 6
#define TIMER06 7
#define TIMER07 8

#define TIMER10 9
#define TIMER11 10
#define TIMER12 11
#define TIMER13 12
#define TIMER14 13
#define TIMER15 14
#define TIMER16 15
#define TIMER17 16



#ifdef VALDUINO
#define _P0 0
#define _P1 1
#define _P2 2
#define _P3 3
#define _P4 4
#define _P5 5
#define _P6 6
#define _P7 7
#define _P8 8
#define _P9 9
#define _P10 10
#define _P11 11
#define _P12 12
#define _P13 13
#define _P14 14
#define _P15 15

#endif

#ifdef __cplusplus
} // extern "C"
#endif

// WMath prototypes
long random(long);
//long random(long, long);
void randomSeed(unsigned long);
long map(long, long, long, long, long);

//#include "pins_arduino.h"
//#ifndef Pins_Arduino_h
//#include "pins_arduino.h"
//#endif

