/**************************************************************************
 This is an example for one of many features that comes with this library 


 In this example, a certain message will be printed at a certain frequency that you can determine 
 each second. This feature can be useful when you want to do a task certain amount of times a second,
 for example, let's say there is a communication with another arduino board or any other board and you 
 want to send a message x times a second for the other board, this example will show you how it's done using this library.

 Written by Jbareen Muhammed
 **************************************************************************/

#include <Alarm.h>

#define DELAY 0.02 // (1 / DELAY) will give you the frequency, in this example, 1/0.02 = 50, meaning the task will be executed 50 times a second

Alarm timer; 

void setup () {
  Serial.begin(9600);
  //triggering the timer for the first time.
  timer.activate();
}

void loop() {

  /**
  DELAY is set to 0.02, so the task will be executed 50 times per second (1/0.02 = 50). if you want to control the frequency then you should change the DELAY time.
  NOTE: if you wanna execute the task n times a second, use the following forumla to determine the delay time you need: DELAY = 1/n.
  for example, let's say we want to do a task 100 times a second, DELAY = 1/100 = 0.01, the DELAY needs to be 0.01(s).         
  */
  bool isDone = timer.setAlarm(intervaled_function, "Hello world!", nullptr, DELAY);

  /** 
  if isDone is true it means that the timer ended and the function was executed, if so, we run start the timer again, and like so each time the 
  timer ends it'll be activated again, and that's how we achieve a cycle of sending messages. Controlling the delay will allow us to control the 
  frequency 
  */
  if( isDone )
    timer.activate();
}
// the function you want to run x times a second. for example this function will print the message x times a second.
void intervaled_function(String message) {
  Serial.println(message);
}