
void collisionDistance() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW); 

  duration = pulseIn(echoPin, HIGH);

  distance = (duration*.0343)/2; 

  Serial.print("Distance: ");  
	Serial.println(distance);  
	delay(100);  

  if (distance < 30) { //If train is closer than 30cm to object tell it to break
    impact = 1
  else
    impact = 0
  } 
}
