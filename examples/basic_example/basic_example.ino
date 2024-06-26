/**************************************************************************
 This is an example for the basic use of this library 

 A message will be printed after an interval and at 
 the same time the code will still be running

 Written by Jbareen Muhammed
 **************************************************************************/
#include <Alarm.h>

#define DELAY 5

Alarm timer1;
Alarm timer2;
Alarm timer3;
Alarm timer4;

//Define a structure if you want to pass more than one argument to the function.
struct Arguments {
    String text;
    int number;
};

int count = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  /*******
  you should add the functions you want to call with a delay here in
  the loop and you can activate the timer wherever you want in the code.

  in order for the timers to work in an accurate manner, there 
  should be little to no delays in your code.
  ********/

  /**
  example for a function that takes nothing and returns nothing.
  if the timer ended, setAlarm will return true, if it didn't yet, the function will return false.
  NOTE: Please keep in mind that the alarm will NOT start until you activate it like shown in line 92, 100, 108, 115
  **/
  bool done1 = timer1.setAlarm(printHelloWorld, DELAY);


  if(done1) {
    Serial.println("Function with no arguments executed");
    Serial.println("-----------------------------------------------------------------------");
  }
  /**
  example for a function that takes something and returns something(it can take anything and return anything).
  if you want to send more than one argument then you should define a structure exactly as demonstrated below. 
  **/
  Arguments args;
  args.text = "temperature is:";
  args.number = 33;

  //make a pointer and send it to the function in case the function you want to call returns a value.
  int result;

  bool done2 = timer2.setAlarm(printMessage, &args, &result, DELAY);

  if(done2) {
    Serial.print("function that takes more than one argument executed with output: ");
    Serial.println(result);
    Serial.println("-----------------------------------------------------------------------");
  }

  //the example below is very similar to the example above except we only send one argument so we don't need a struct
  String message = "Hey!!";
  String result2;

  bool done3 = timer3.setAlarm(printMessageSimple, &message, &result2, DELAY); 
  if(done3) {
    Serial.print("function that takes one argument executed with output: ");
    Serial.println( result2 );
    Serial.println("-----------------------------------------------------------------------");
  }

  //this is an example of a function that takes nothing and returns a value.
  int result3;
  bool done4 = timer4.setAlarm(takeNothingReturnSomething, nullptr, &result3, DELAY);

  if (done4) {
    Serial.print("function that takes no arguments and returns a value executed with output: ");
    Serial.println( result3 );
    Serial.println("-----------------------------------------------------------------------");
  }
  //let's say that you want to start the timer after a condition was satisifed
  if(count == 0) {
    timer1.activate();
    Serial.print("Timer started. the function will be executed after ");
    Serial.print(DELAY);
    Serial.println(" seconds");    
  }
  
  //activating the timer when the counter reachs 50.
  if (count == 50) {
    timer2.activate();
    Serial.print("Timer started. the function will be executed after ");
    Serial.print(DELAY);
    Serial.println(" seconds");    
  }

  //activating the timer when the counter reachs 100.
  if (count == 100) {
    timer3.activate();
    Serial.print("Timer started. the function will be executed after ");
    Serial.print(DELAY);
    Serial.println(" seconds");    
  }
  
  if(count == 150) {
    timer4.activate();
    Serial.print("Timer started. the function will be executed after ");
    Serial.print(DELAY);
    Serial.println(" seconds");    
  }
  //The code will continue working and the function that is delayed will be executed after the delay without having to delay the whole execution of the code
  
  /***
  NOTE: if you want to do the same for a function that takes arguments and returns nothing, then you should call setAlarm like this:

  timer.setAlarm(yourFunction, arguments, delayTime)

  ***/
  
  if(count == 200)
    count = 0;

  count++;
  delay(200);
}

void printHelloWorld() {
  Serial.println("hello world after 5 seconds");
}

int printMessage(Arguments args) {
  Serial.print(args.text);
  Serial.println(args.number);
  String num = String(args.number);
  return args.number;
}

//this function is similar to the above function but it takes only one argument
String printMessageSimple(String message) {
  Serial.print("message is: ");
  Serial.println(message);
  return "this is an output";
}
int takeNothingReturnSomething() {
  //some random number
  return 1000;
}