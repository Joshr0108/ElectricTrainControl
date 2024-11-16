
void motorControl() { 

  joyStickInput = analogRead(joyStickPin); //Read joystick input

  if (collison = 0) { //Check no collision ahead 0=No
  
    if (joyStickInput < 860) { 
      //Set Motor to Backwards
      digitalWrite(controlPin1, LOW);
      digitalWrite(controlPin2, HIGH);
      motorSpeed = 0.3;//Duty ratio?
      analogWrite(enablePin, motorSpeed);
      }

    if (joyStickInput > 870) { 
      //Set Motor to Backwards
      digitalWrite(controlPin1, HIGH);
      digitalWrite(controlPin2, LOW);
      motorSpeed = 0.3;//Duty ratio?
      analogWrite(enablePin, motorSpeed);
      }

    if (joyStickInput = 874) {
      //Turn on Brakes
      digitalWrite(controlPin1, LOW);
      digitalWrite(controlPin2, LOW);
      digitalWrite(enablePin, LOW);
      }
    }
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, LOW);
    digitalWrite(enablePin, LOW);
  }

  Serial.print("Joystick: ");
  Serial.println(joyStickInput);
}






