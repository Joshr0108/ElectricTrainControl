/* 
Need to add Code that will stop motor at Red
Note - Good We put colour sensor on the side, 
  if distance & colour sensor was on the side the green card infront 
  would tell colour sensor to go but stop distance sensor
*/ 

// Defines & Constants
  //Colour Sensor
byte counter=0;
byte countR=0,countG=0,countB=0;
  //Distance Sensor
float duration, distance;
int impact = 0
  //Motor Control
int motorSpeed = 0;

// User Variables
  //Colour Sensor
int s0=32,s1=30,s2=28,s3=26;
int out=34;
int flag=0;
  //Distance Sensor
const int trigPin = 36;
const int echoPin = 34;
  //H-Bridge
const int enablePin = 2; 
const int controlPin1 = 22;
const int controlPin2 = 23;
  //JoyStick
const int joyStickPin = A0;
int joyStickInput = 0;


void setup() {
  Serial.begin(9600);
  pinMode(s0,OUTPUT); // Output to Colour Sensor
  pinMode(s1,OUTPUT); // |
  pinMode(s2,OUTPUT); // |
  pinMode(s3,OUTPUT); // |
  pinMode (trigPin, OUTPUT);  // Distance Sensor
  pinMode(echoPin, INPUT);    // |
  pinMode(joyStickPin, INPUT);  // Declare input from joystick
  pinMode(controlPin1, OUTPUT); // Motor Control 
  pinMode(controlPin2, OUTPUT); // |
  pinMode(enablePin, OUTPUT);   // |
  digitalWrite(enablePin, LOW); // |
}

void loop() {
  
  //Colour Sensor 
  TCS();
  while(1);


  //Distance Sensor
  collisionDistance();


  //Motor Control
  motorControl();
}
