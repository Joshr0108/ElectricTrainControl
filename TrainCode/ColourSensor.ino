/*
This is the code that will interact with colour sensor
It will detect colour infront of it, green will tell it to go and red to stop
*/

void ISR_INTO() {
  counter++;
}

// Calculate Mean value of sensor recording
int colourAverage(byte s2State, byte s3State) {
    int total = 0;
    int samples = 10;
    digitalWrite(s2, s2State);
    digitalWrite(s3, s3State);
    delay(90); // Settle time
    for (int i = 0; i < samples; i++) {
        noInterrupts();
        total += counter;
        counter = 0;
        interrupts();
        delay(10); // Small delay between samples
    }
    return total / samples;
}

void measureAmbientLight() {
    ambientR = colourAverage(LOW, LOW);   // Ambient Red
    ambientB = colourAverage(HIGH, HIGH); // Ambient Green
    ambientG = colourAverage(LOW, HIGH);  // Ambient Blue
}


// Determine RGB values detected & if that means a card is present
void measureColour() {
  // Calculate raw average reading for each colour
  int rawR = countR = colourAverage(HIGH, HIGH);   // Red
  int rawB = countB = colourAverage(LOW, HIGH); // Green
  int rawG = countG = colourAverage(LOW, LOW);  // Blue

  // Subtract ambient light
  countR = max(0, rawR - ambientR); // Ensure no negative values
  countB = max(0, rawB - ambientB);
  countG = max(0, rawG - ambientG);


  // Print recorded values
  Serial.print("R = "); Serial.print(countR);
  Serial.print(", G = "); Serial.print(countG);
  Serial.print(", B = "); Serial.println(countB);

  // Determine if card present 
  if (countR > 160 && countG > 70  ) { //Values will need adjusting
    colourDetected = 1; // Red
    Serial.println("Red Detected");
  } 
  else if (countG > 40 && countR < 30) { //Values will need ajdusting 
    colourDetected = 2; // Green
    Serial.println("Green Detected");
  } 
  else {
    colourDetected = 0; // No clear color
    Serial.println("No Color Detected");
  }
}


