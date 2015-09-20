/*
 * Arduino_main.cpp
 *
 *  Created on: Sep 8, 2015
 *      Author: hmhaw
 */
#include "Arduino.h"


//#define led1 1
//#define led2 2
//#define led3 3
//#define sw1	4
//
//uint8_t val;
//
//void setup()
//{
//	pinMode(led1, OUTPUT);
//	pinMode(led2, OUTPUT);
//	pinMode(led3, OUTPUT);
//	pinMode(sw1, INPUT);
//
//	digitalWrite(led3, LOW);
//	analogWrite(50, 128);
//}
//unsigned long long count = 0;
//unsigned int start;
//void loop()
//{
//
//	val = digitalRead(sw1);
//	if(val == HIGH)
//		digitalWrite(led3, HIGH);
//	else
//		digitalWrite(led3, LOW);
//
//	digitalWrite(led1, HIGH);
//	digitalWrite(led2, LOW);
//
//
//
////	start = millis();
////	while ( (millis() - start) < 100){}
//	for(count = 0;count<100000;count++)
//	{
//		NOP();
//		NOP();
//		NOP();
//		NOP();
//	}
//	digitalWrite(led1,LOW);
//	digitalWrite(led2, HIGH);
//
//	start = millis();
//	while ( (millis() - start) < 50){};
//	for(count = 0;count<100000;count++)
//	{
//		NOP();
//		NOP();
//		NOP();
//		NOP();
//	}
//}


/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */


// the setup function runs once when you press reset or power the board
int var = 0;
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(1, OUTPUT);
  analogWrite(51, 64);
  analogWrite(50,200);
  analogWrite(61, 128);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second
  digitalWrite(1, LOW);    // turn the LED off by making the voltage LOW
  delay(100);              // wait for a second
  var += 10;
  analogWrite(50, var%256);
}
