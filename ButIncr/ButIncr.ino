/*
 * 
 * Code adapted from Jeremy Rigor - 
 * https://arduino.stackexchange.com/questions/17536/controlling-servo-motors-with-push-button-problem-though
 */
#include <Servo.h>

const int buttonPin = 9;
const int servoPin = 10;

int buttonState = 0;
int directionState = 0;

Servo servoOne;

int pos = 0;

void setup() 
{
  Serial.begin(9600);
  servoOne.attach(10);
  servoOne.write(directionState);
  pinMode(buttonPin, INPUT);
}

void loop() 
{
 Serial.println(pos);
 buttonState = digitalRead(buttonPin);

    if(buttonState == LOW && servoOne.read() <= 60)
    {
      for(pos = 0; pos < 60; pos=pos+1);
      servoOne.write(pos);
      
    }
    else if(buttonState == LOW)
    {
        for(pos = 60; pos > 0; pos=pos-1);
         servoOne.write(pos);
    }
   
}
     
  
