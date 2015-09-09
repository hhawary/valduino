/*
 * Arduino_main.cpp
 *
 *  Created on: Sep 8, 2015
 *      Author: hmhaw
 */

#include "Arduino.h"

#define led1 1
#define led2 2
#define led3 3
#define sw1	4

uint8_t val;

void setup()
{
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(led3, OUTPUT);
	pinMode(sw1, INPUT);

	digitalWrite(led3, LOW);
}
unsigned long long count = 0;

void loop()
{
	val = digitalRead(sw1);
	if(val == HIGH)
		digitalWrite(led3, HIGH);
	else
		digitalWrite(led3, LOW);

	digitalWrite(led1, HIGH);
	digitalWrite(led2, LOW);

	for(count = 0;count<100000;count++)
	{
		NOP();
		NOP();
		NOP();
		NOP();
	}
	digitalWrite(led1,LOW);
	digitalWrite(led2, HIGH);
	for(count = 0;count<100000;count++)
	{
		NOP();
		NOP();
		NOP();
		NOP();
	}
}
