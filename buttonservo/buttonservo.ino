/*

  Some code from "button" by Tom Igoe

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 9;     // the number of the pushbutton pin

// variables will change:

#include <Servo.h>
int servoPin1 = 10;           //Pin that the servo is attached to.
int moveRate = 10;        //the time between updates in milliseconds
int minAngle = 0;     //sets the low point of the movement range
int maxAngle = 180;   //sets the high point of the movement range
int moveIncrement = 180;    // how much to move the motor each cycle
int servoAngle1;
int buttonState = 0;         // variable for reading the pushbutton status

Servo servo1;

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  servo1.attach(servoPin1);  //attach the servo to the corresponding control pin
  servoAngle1 = minAngle;

}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {                                          //it subtracts the value of the moment in time the last blink happened, and sees if that number is larger than your set blinking value
    servo1.write(servoAngle1);

    servoAngle1 += moveIncrement;

    if (servoAngle1 <= minAngle || servoAngle1 >= maxAngle)
    {
      moveIncrement = -moveIncrement;
    }
  }
}

