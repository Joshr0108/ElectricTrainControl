/*
This is the code that will interact with colour sensor
It will detect colour infront of it, green will tell it to go and red to stop
*/


void colourSensor()
 {
 flag=0;
 digitalWrite(s1,HIGH);
 digitalWrite(s0,HIGH);
 digitalWrite(s2,LOW);
 digitalWrite(s3,LOW);
 attachInterrupt(0, ISR_INTO, CHANGE);
 timer0_init();

 }
void ISR_INTO()
 {
 counter++;
 }
 void timer0_init(void)
 {
  TCCR2A=0x00;
  TCCR2B=0x07;   //the clock frequency source 1024 points
  TCNT2= 100;    //10 ms overflow again
  TIMSK2 = 0x01; //allow interrupt
 }
 int i=0;
 ISR(TIMER2_OVF_vect)//the timer 2, 10ms interrupt overflow again. Internal overflow interrupt executive function
{
    TCNT2=100;
    flag++;
 if(flag==1)
  {
    countR=counter; //Measure amount of red detected
    digitalWrite(s2,HIGH);
    digitalWrite(s3,HIGH);
    
    //Check for red card
    if (countR > 150/*Find out red value when card present*/) {
      colourDetected = 1; //Set to 1 for red
    }
  }
  else if(flag==2)
   {
    countG=counter; //Measure amount of red
    digitalWrite(s2,LOW);
    digitalWrite(s3,HIGH);

    // Check for green card
    if (countG > 150/*Find out green value when card present*/) {
      colourDetected = 2;
    }
   }
   else if(flag==3)
    {
    countB=counter; //Measure amount of blue
    digitalWrite(s2,LOW);
    digitalWrite(s3,LOW);
    }
    else if(flag==4)
     {
     flag=0;
     }
       counter=0;
}

