#include "Alarm.h"
Alarm::Alarm() {
    isDelayActive = false;
    isDone = false;
}
bool Alarm::setAlarm(void (*sleep)(), float delay) {
    if (!isDone && isDelayActive)
        previousMillis = millis();
    if (isDelayActive)
        isDone = true;
    if (isDone) {
        if (millis() - previousMillis >= (unsigned long)(delay * 1000) ) {
            sleep();
            isDone = false;
            isDelayActive = false;
            return true;
        }   
  }
  return false;
}
bool Alarm::setAlarm(void* (*sleep)(), float delay) {
    if (!isDone && isDelayActive)
        previousMillis = millis();
    if (isDelayActive)
        isDone = true;
    if (isDone) {
        if (millis() - previousMillis >= (unsigned long)(delay * 1000) ) {
            sleep();
            isDone = false;
            isDelayActive = false;
            return true;
        }   
  }
  return false;
}
bool Alarm::setAlarm(int (*sleep)(), float delay) {
    setAlarm(reinterpret_cast<void* (*)()>(sleep), delay);
}
bool Alarm::setAlarm(double (*sleep)(), float delay) {
    setAlarm(reinterpret_cast<void* (*)()>(sleep), delay);
}
bool Alarm::setAlarm(bool (*sleep)(), float delay) {
    setAlarm(reinterpret_cast<void* (*)()>(sleep), delay);
}
bool Alarm::setAlarm(char (*sleep)(), float delay) {
    setAlarm(reinterpret_cast<void* (*)()>(sleep), delay);
}
bool Alarm::setAlarm(String (*sleep)(), float delay) {
    setAlarm(reinterpret_cast<void* (*)()>(sleep), delay);
}
bool Alarm::setAlarm(long (*sleep)(), float delay) {
    setAlarm(reinterpret_cast<void* (*)()>(sleep), delay);
}

bool Alarm::setAlarm(void (*sleep)(void*), void* args, float delay) {
    if (!isDone && isDelayActive)
        previousMillis = millis();
    if (isDelayActive)
        isDone = true;

    if (isDone) {
        if (millis() - previousMillis >= (unsigned long)(delay * 1000) ) {
            sleep(args);
            isDone = false;
            isDelayActive = false;
            return true;
        }   
  }
  return false;
}


bool Alarm::setAlarm(int (*sleep)(void*), void* args, int* result, float delay) {
    if (!isDone && isDelayActive)
        previousMillis = millis();
    if (isDelayActive)
        isDone = true;

    if (isDone) {
        if (millis() - previousMillis >= (unsigned long)(delay * 1000) ) {
            if( args != nullptr )
                *result = sleep(args);
            else {
                 int (*sleep2)() = reinterpret_cast<int (*)()>(sleep);
                 *result = sleep2();
            }

            isDone = false;
            isDelayActive = false;
            return true;
        }   
  }
  return false;
}

bool Alarm::setAlarm(String (*sleep)(void*), void* args, String* result, float delay) {
    if (!isDone && isDelayActive)
        previousMillis = millis();
    if (isDelayActive)
        isDone = true;

    if (isDone) {
        if (millis() - previousMillis >= (unsigned long)(delay * 1000) ) {
            if( args != nullptr )
                *result = sleep(args);
            else {
                String (*sleep2)() = reinterpret_cast<String (*)()>(sleep);
                *result = sleep2();
            }
            isDone = false;
            isDelayActive = false;
            return true;
        }   
  }
  return false;
}

bool Alarm::setAlarm(double (*sleep)(void*), void* args, double* result, float delay) {
    if (!isDone && isDelayActive)
        previousMillis = millis();
    if (isDelayActive)
        isDone = true;

    if (isDone) {
        if (millis() - previousMillis >= (unsigned long)(delay * 1000) ) {
            if( args != nullptr )
                *result = sleep(args);
            else {
                double (*sleep2)() = reinterpret_cast<double (*)()>(sleep);
                *result = sleep2();
            }
            isDone = false;
            isDelayActive = false;
            return true;
        }   
  }
  return false;
}

bool Alarm::setAlarm(char (*sleep)(void*), void* args, char* result, float delay) {
    if (!isDone && isDelayActive)
        previousMillis = millis();
    if (isDelayActive)
        isDone = true;

    if (isDone) {
        if (millis() - previousMillis >= (unsigned long)(delay * 1000) ) {
            if( args != nullptr )
                *result = sleep(args);
            else {
                char (*sleep2)() = reinterpret_cast<char (*)()>(sleep);
                *result = sleep2();
            }
            isDone = false;
            isDelayActive = false;
            return true;
        }   
  }
  return false;
}
bool Alarm::setAlarm(bool (*sleep)(void*), void* args, bool* result, float delay) {
    if (!isDone && isDelayActive)
        previousMillis = millis();
    if (isDelayActive)
        isDone = true;

    if (isDone) {
        if (millis() - previousMillis >= (unsigned long)(delay * 1000) ) {
            if( args != nullptr )
                *result = sleep(args);
            else {
                bool (*sleep2)() = reinterpret_cast<bool (*)()>(sleep);
                *result = sleep2();
            }
            isDone = false;
            isDelayActive = false;
            return true;
        }   
  }
  return false;
}
bool Alarm::setAlarm(long (*sleep)(void*), void* args, long* result, float delay) {
    if (!isDone && isDelayActive)
        previousMillis = millis();
    if (isDelayActive)
        isDone = true;

    if (isDone) {
        if (millis() - previousMillis >= (unsigned long)(delay * 1000) ) {
            if( args != nullptr )
                *result = sleep(args);
            else {
                long (*sleep2)() = reinterpret_cast<long (*)()>(sleep);
                *result = sleep2();
            }
            isDone = false;
            isDelayActive = false;
            return true;
        }   
  }
  return false;
}

void Alarm::activate() {
    isDelayActive = true;
}