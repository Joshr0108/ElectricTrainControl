/*
This file uploads to Ardunio MEGA on Train
To install package, Sketch ->Include Library -> Manage Libraries

Check 'if statement' in colour sensor is good values e.g. countR > 150
*/

//Required Packages
#include <SPI.h>
#include <nRF24L01.h> //Might need to install package 'RF24 by TMRh20
#include <RF24.h>


// Defines & Constants
  //Colour Sensor
volatile byte counter = 0;
byte countR = 0, countG = 0, countB = 0;
byte ambientR = 0, ambientG = 0, ambientB = 0;
int colourDetected = 0; // 0 = no colour, 1 = red, 2 = green
int flag = 0; 
  //Distance Sensor
float duration, distance;
int impact = 0;
  //Motor Control
int motorSpeed = 0;
  // Reciever
const byte address[6] = "00001"; //This should be same as other file
  // Is train running or not?
bool isTrainRunning = false;
  // Test
int i = 0;
//int test = 0; Used to debug and detect state of motor  


// User Variables - Pins to plug into Ardunio MEGA
  //Colour Sensor
int s0 = 21, s1 = 20, s2 = 19, s3 = 18;
int out=2; //Changed from 3 as set to interrupt pin 0 which is 2
  //Distance Sensor
const int trigPin = 36; //Try 22 if not working still
const int echoPin = 34; //Try 23 if not working stil
  //H-Bridge
const int enablePin = 44; // changed from 2 to avoid conflicts     
const int controlPin1 = 22;   
const int controlPin2 = 23;   
  //JoyStick
int joystickInput = 0;
  // Reciever 
RF24 radio(7, 8); // CE, CSN pins on Arduino Mega
  // test
int test = 0;



void setup() {
  Serial.begin(9600);
  //Wireless
  radio.begin();                       // Wireless Recieve
  radio.openReadingPipe(0, address);   // | Open communication channel
  radio.setPALevel(RF24_PA_MIN);       // | Sets power level to low
  radio.startListening();              // | Turns on reciver
  //Motor
  pinMode(controlPin1, OUTPUT); // Motor Control 
  pinMode(controlPin2, OUTPUT); // |
  pinMode(enablePin, OUTPUT);   // |
  digitalWrite(enablePin, LOW); // |
  //Colour Sensor
  pinMode(s0,OUTPUT);                                             // Output to Colour Sensor
  pinMode(s1,OUTPUT);                                             // |
  pinMode(s2,OUTPUT);                                             // |
  pinMode(s3,OUTPUT);                                             // |
  pinMode(out,INPUT);                                             // |
  digitalWrite(s1,HIGH);                                          // | Set Scaling to 100%
  digitalWrite(s0,HIGH);                                          // | |
  attachInterrupt(digitalPinToInterrupt(out),                     // |
   ISR_INTO, CHANGE);                                             // |
  measureAmbientLight();
  //Distance Sensor
  pinMode (trigPin, OUTPUT);  // Distance Sensor
  pinMode(echoPin, INPUT);    // |
}



void loop() {
  if (i == 10) {     // Test colour sensor every ten loops
    measureColour(); // | Measure colour sensor values
    i = 0;           // | Reset loop counter
  }

  collisionDistance();

  // Check for collision
  if (impact == 1) { 
    // Stop train if collision is detected
    brake();
    isTrainRunning = false;
  } 
  // Check for red card
  else if (colourDetected == 1) { 
    // Stop train if red card is detected
    brake();
    isTrainRunning = false;
  } 
  // Check for green card detected while stopped
  else if (!isTrainRunning && colourDetected == 2) { 
    // Start train if green card is detected after being stopped
    reciever();
    isTrainRunning = true;
  } 

  // Continuously update joystick input if train is running
  if (isTrainRunning) {
    reciever();
  }
  
  delay(50);
  //reciever();
  // Add 1 to loop counter
  i += 1; 
}