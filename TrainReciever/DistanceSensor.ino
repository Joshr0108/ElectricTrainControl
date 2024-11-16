/*
This code will interact with distance sensor
It will be used to detect potential collision and stop train if one is detected
*/


void collisionDistance() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW); 

  duration = pulseIn(echoPin, HIGH);

  distance = (duration*0.0343)/2; 

  Serial.print("Distance: ");  
	Serial.println(distance);  

  if (distance < 30) { //If train is closer than 30cm to object tell it to break
    impact = 1;
  }
  else { //Must not be anything < 30 cm away so chance of impact is False
    impact = 0;
  } 
}
