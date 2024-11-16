/*
All Details on 'Getting Started' Moodle file, page 10
Connect 10 microF capacitor across VCC&GND pin
Power with the 3.3V pin
This file uploads to Ardunio Nano
To install package, Sketch ->Include Library -> Manage Libraries
*/

#include <SPI.h>
#include <nRF24L01.h> //Might need to install package 'RF24 by TMRh20
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN pins on Arduino Nano
const byte address[6] = "00001";

//Joystick
const int joystickPin = A0;
int joystickInput = 0;

void setup() {
  Serial.begin(9600);
  //Joystick
  pinMode( joystickPin, INPUT );
  radio.begin();
  radio.openWritingPipe(address);   //Open communication channel
  radio.setPALevel(RF24_PA_MIN);    //Sets power level to low
  radio.stopListening();            //Turns off reciver

}

void loop() {
  joystickInput = analogRead(joystickPin);   // Read joystick value
  radio.write(&joystickInput, sizeof(joystickInput));
  delay(50); 
}
