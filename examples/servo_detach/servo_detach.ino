/**************************************************************************
 This is an example of how to use this library with the servo

 The servo will be moved to a certain position and after the 
 delay it'll be detached without having to delay the whole proccess 

 Written by Jbareen Muhammed
 **************************************************************************/

#include <Alarm.h>
#include <Servo.h>

#define DELAY 1.5
#define SERVO_PIN 2

Alarm timer;
Servo ser;
int counter = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  
  timer.setAlarm(detach, DELAY);

  /** 
  for example, we want to activate the timer after some condition happens.
  so let's take a counter and for example when that counter reaches a certain
  number we want to move the servo to a position and we want it to be detached after two seconds
  **/

  if(counter == 0) {
    ser.attach(SERVO_PIN);
    ser.write(0);
    //When activating the timer exactly after the delay passes the detach function will be called
    timer.activate();
    Serial.print("Servo will be detached after ");
    Serial.print(DELAY);
    Serial.println(" seconds");  
  }

  if(counter == 8) {
    ser.attach(SERVO_PIN);
    ser.write(90);
    timer.activate();
    Serial.print("Servo will be detached after ");
    Serial.print(DELAY);
    Serial.println(" seconds");  
  }
  if(counter == 16) {
    ser.attach(SERVO_PIN);
    ser.write(180);
    timer.activate();
    Serial.print("Servo will be detached after ");
    Serial.print(DELAY);












    
    Serial.println(" seconds");  
  }

  counter++;

  if(counter == 24)
    counter = 0;

  Serial.println("doing other tasks");
  delay(500);
}

void detach() {
  ser.detach();
  Serial.println("Servo is detached!");
  Serial.println("--------------------");
}