#ifndef Alarm_h
#define Alarm_h

#include "Arduino.h"

class Alarm {
public:
    Alarm();
    bool setAlarm(void (*sleep)(), float delay );
    bool setAlarm(void* (*sleep)(), float delay);
    bool setAlarm(int (*sleep)(), float delay);
    bool setAlarm(double (*sleep)(), float delay);
    bool setAlarm(bool (*sleep)(), float delay);
    bool setAlarm(char (*sleep)(), float delay);
    bool setAlarm(String (*sleep)(), float delay);
    bool setAlarm(long (*sleep)(), float delay);

    bool setAlarm(void (*sleep)(void*), void* args, float delay);
    bool setAlarm(int (*sleep)(void*), void* args, int* result, float delay);
    bool setAlarm(double (*sleep)(void*), void* args, double* result, float delay);
    bool setAlarm(bool (*sleep)(void*), void* args, bool* result, float delay);
    bool setAlarm(char (*sleep)(void*), void* args, char* result, float delay);
    bool setAlarm(String (*sleep)(void*), void* args, String* result, float delay);
    bool setAlarm(long (*sleep)(void*), void* args, long* result, float delay);
    void activate();
private:
    bool isDelayActive;
    bool isDone;
    unsigned long previousMillis;
};

#endif
