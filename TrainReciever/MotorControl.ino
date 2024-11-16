/*
This is the function that controls the motor
It will make it go forward, backward or brake depending on joystick feedback
*/

// Function to control motor based on joystick input
void motorControl() { 

  if (joystickInput < 510) { 
    //Set Motor to Backwards
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
    motorSpeed = 100;//Duty ratio?
    analogWrite(enablePin, motorSpeed);
    //test = 0; 
    }

  else if (joystickInput > 521) { 
    //Set Motor to Forwards
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
    motorSpeed = 100;//Duty ratio?
    analogWrite(enablePin, motorSpeed);
    //test = 1;
    }

  else { //If joystick not saying forward or back, stop
    //Turn on Brakes
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, LOW);
    digitalWrite(enablePin, LOW);
    //test = 2;
  }
}

// Function to turn on brakes
void brake() { 
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, LOW);
    digitalWrite(enablePin, LOW);
}