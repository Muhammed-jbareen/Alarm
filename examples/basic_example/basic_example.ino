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
Alarm timer5;

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
  should be little to no delays in your code(using this library will elimante the need of using delay).
  ********/

  /**
  example for a function that takes nothing and returns nothing(even if the function returns something you can still use the example below if you don't want the result).
  if the timer ended, setAlarm will return true, if it didn't yet, the function will return false.
  NOTE: Please keep in mind that the alarm will NOT start until you activate it like shown in line 92, 100, 108, 115
  **/

  bool done1 = timer1.setAlarm(printHelloWorld, DELAY);

  //if done1 is true that means the timer ennded and the function you sent got executed, if done1 is false it either means that the timer didn't end or is not activated.
  if(done1) {
    Serial.println("Function with no arguments executed");
    Serial.println("-----------------------------------------------------------------------");
  }
  /**
  example for a function that takes arguments and returns a result(it can take anything and return anything).
  if you want to send more than one argument then you should define a structure exactly as demonstrated below. 
  **/
  Arguments args;
  args.text = "temperature is:";
  args.number = 33;

  //make a pointer and send it to the function in case the function you want to call returns a value.
  int result;

  bool done2 = timer2.setAlarm(printMessage, args, &result, DELAY);

  if(done2) {
    Serial.println("function that takes more than one argument executed with output: " + String(result));
    Serial.println("-----------------------------------------------------------------------");
  }

  //the example below is very similar to the example above except we only send one argument so we don't need a struct
  String message = "Hey!!";
  String result2 = "";

  bool done3 = timer3.setAlarm(printMessageSimple, message, &result2, DELAY); 
  if(done3) {
    Serial.println("function that takes one argument executed with output: "+ String(result2) );
    Serial.println("-----------------------------------------------------------------------");
  }

 //this is an example of a function that takes no arguments and returns a value.
 int result3;
 bool done4 = timer4.setAlarm(takeNothingReturnSomething, &result3, DELAY);

  if (done4) {
    Serial.println("function that takes no arguments and returns a value executed with output: " + String(result3));
    Serial.println("-----------------------------------------------------------------------");
  }

  /**
  here is an example of how to call a function that takes arguments and returns nothing, even if the function returns something 
  and you're not interested in the result, you can just send nullptr instead.
  */

  int number = 6;

  bool done5 = timer5.setAlarm(printNumber, number, nullptr, DELAY);
  
  if(done5) {
    Serial.println("function that takes arguments and returns nothing executed");
    Serial.println("-----------------------------------------------------------------------");
  }
  //let's say that you want to start the timer after a condition was satisifed
  if(count == 0) {
    timer1.activate();
    Serial.println("First timer started. the function will be executed after " + String(DELAY) + " seconds");
  }
  
  //activating the second timer when the counter reachs 50.
  if (count == 50) {
    timer2.activate();
    Serial.println("Second timer started. the function will be executed after " + String(DELAY) + " seconds");
  }

  //activating the third timer when the counter reachs 100.
  if (count == 100) {
    timer3.activate();
    Serial.println("Third timer started. the function will be executed after " + String(DELAY) + " seconds");
  }

  //activating the fourth timer when the counter reachs 150.
  if(count == 150) {
    timer4.activate();
    Serial.println("Fourth timer started. the function will be executed after " + String(DELAY) + " seconds");
  }

  //activating the fifth timer when the counter reachs 200.
  if (count == 200) {
    timer5.activate();
    Serial.println("Fifth timer started. the function will be executed after " + String(DELAY) + " seconds");
  }
  //The code will continue working and the function that is delayed will be executed after the delay without having to delay the whole execution of the code
  
  /***
  NOTE: if you want to do the same for a function that takes arguments and returns nothing, then you should call setAlarm like this:

  timer.setAlarm(yourFunction, arguments, nullptr, delayTime)

  ***/
  
  if(count == 250)
    count = 0;

  count++;
  delay(200);
}


/** NOTE: the functions below don't really have any meaning, it's just a demonstration of how to use the library. */

void printHelloWorld() {
  Serial.println("hello world after 5 seconds");
}

int printMessage(Arguments args) {
  Serial.print(args.text);
  Serial.println(args.number);
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

void printNumber(int a) {
  Serial.println("number is " + String(a));
}