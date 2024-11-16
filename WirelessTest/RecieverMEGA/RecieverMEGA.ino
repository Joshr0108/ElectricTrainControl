/*
All Details on 'Getting Started' Moodle file, page 10
Connect 10 microF capacitor across VCC&GND pin
Power with the 3.3V pin
This file uploads to Ardunio MEGA
To install package, Sketch ->Include Library -> Manage Libraries
*/

//Required Packages
#include <SPI.h>
#include <nRF24L01.h> //Might need to install package 'RF24 by TMRh20
#include <RF24.h>

//Radio variables
RF24 radio(7, 8); // CE, CSN pins on Arduino Mega
const byte address[6] = "00001"; //This should be same as other file
//H-Bridge
int motorSpeed = 0;
const int enablePin = 2;      //pins to plug into arduino
const int controlPin1 = 22;   // |
const int controlPin2 = 23;   // |
//Joystick
int joystickInput = 0;
//Test
int test = 0;


void setup() {
  Serial.begin(9600);
  //Wireless
  radio.begin();
  radio.openReadingPipe(0, address);   //Open communication channel
  radio.setPALevel(RF24_PA_MIN);    //Sets power level to low
  radio.startListening();            //Turns on reciver
  //Motor
  pinMode(controlPin1, OUTPUT); // Motor Control 
  pinMode(controlPin2, OUTPUT); // |
  pinMode(enablePin, OUTPUT);   // |
  digitalWrite(enablePin, LOW); // |
}

void loop() {
  delay(50); //Add delay s
  if (radio.available()) { //Check wireless signal is available & print recieved value
    radio.read(&joystickInput, sizeof(joystickInput));
    Serial.print("Received Joystick Value: ");
    Serial.println(joystickInput);
  }
  else { //If no signal recieved -> turn on train brakes
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, LOW);
    digitalWrite(enablePin, LOW);
  }
  delay(50);
  motorControl(); // Call motor function
  //Serial.println(test); <- Test motor state
}
