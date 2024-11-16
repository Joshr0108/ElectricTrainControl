/*
Code to recieve joystick value from transmitter
*/ 

void reciever() {

  if (radio.available()) { //Check wireless signal is available & print recieved value
    radio.read(&joystickInput, sizeof(joystickInput));
    Serial.print("Received Joystick Value: ");
    Serial.println(joystickInput);
    motorControl(); // Call motor function - ( this was out if,else statement before so test if error )
  }
  else { //If no signal recieved -> turn on train brakes
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, LOW);
    digitalWrite(enablePin, LOW);
  }

}