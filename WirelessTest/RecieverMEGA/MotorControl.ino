
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

  else { //This 874 was out 0 point in first test
    //Turn on Brakes
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, LOW);
    digitalWrite(enablePin, LOW);
    //test = 2;
  }
  

}


