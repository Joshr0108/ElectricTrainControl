/*
This file uploads to Ardunio Nano
To install package, Sketch ->Include Library -> Manage Libraries
*/

//Required Packages
#include <SPI.h>
#include <nRF24L01.h> //Might need to install package 'RF24 by TMRh20
#include <RF24.h>


//Defines & Constants
int joystickInput = 0;
const byte address[6] = "00001";


//User Variables
  //Joystick
const int joystickPin = A0; // Pin to recieve input from joystick
  //Transmitter
RF24 radio(7, 8);           // CE, CSN pins on Arduino Nano


//Setup
void setup() {
  Serial.begin(9600);
  //Joystick
  pinMode( joystickPin, INPUT );    //State joystick pin is recieving signal
  //Transmitter
  radio.begin();
  radio.openWritingPipe(address);   //Open communication channel
  radio.setPALevel(RF24_PA_MIN);    //Sets power level to low
  radio.stopListening();            //Turns off reciver
}


//Loop
void loop() {
  joystickInput = analogRead(joystickPin);            // Read joystick value
  radio.write(&joystickInput, sizeof(joystickInput)); // Transmit joystick value
  delay(50);                                          // Delay so it doesn't send too much data
}