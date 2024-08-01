/**
 * @file Alarm.cpp
 * @brief Implementation of the Alarm class.
 *
 * This file contains the implementation of the Alarm class methods.
 *
 * @authors
 * - Muhammed Jbareen
 *
 * @license MIT License
 * @copyright
 * Copyright (c) 2024 Muhammed Jbareen
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef Alarm_h
#define Alarm_h

#include <Arduino.h>
#include <stddef.h>

class Alarm {
public:

    Alarm();

    /**
     * @brief Sets an alarm with a specified delay, and runs the provided sleep function after this delay.
     * 
     * This function sets an alarm using the provided sleep function.
     * 
     * @tparam Func The type of the sleep function.
     * @param sleepFunction is the target function that should be executed after the delay.
     * @param delay is the delay duration in seconds.
     * 
     * @returns true if delay is over, false otherwise.
     * 
     * @code
     * Alarm alarm;
     * alarm.setAlarm(exampleFunction, 5f); 
     * @endcode 
    */
    template <typename Func> bool setAlarm(Func sleepFunction, float delay);


    /**
     * @brief Sets an alarm with a specified delay and optional result handling, and runs the provided sleep function after this delay.
     * 
     * This function sets an alarm using the provided sleep function, arguments, and delay.
     * An optional result parameter can be provided. If you do not wish to handle the result,
     * you can pass `nullptr`
     * 
     * @tparam Func The type of the sleep function.
     * @tparam Args The type of the arguments to the sleep function.
     * @tparam Result The type of the result, default is `void*`.
     * @param sleepFunction is the target function that should be executed after the delay.
     * @param args are the arguments to be send to the function sleepFunction.
     * @param result is a pointer of the same type that the function sleepFunction returns, if not interested in the result, send nullptr.
     * @param delay is the delay duration in seconds.
     * 
     * @returns true if delay is over, false otherwise.
     * 
     * @code
     * Alarm alarm;
     * alarm.setAlarm(exampleFunction, 5, nullptr, 5f); // Without result handling.
     * 
     * int result;
     * alarm.setAlarm(exampleFunction, 5, &result, 5f); // With result.
     * @endcode 
     * 
    */
    template <typename Func, typename Args, typename Result> 
    bool setAlarm(Func sleepFunction, Args args, Result result, float delay);

     /**
     * @brief Sets an alarm with a specified delay and result handling but for a sleep function that takes no arguments, and runs the provided sleep function after this delay.
     *
     * This function sets an alarm using the provided sleep function and delay.
     *
     * @tparam Func The type of the sleep function.
     * @tparam Result The type of the result.
     * @param sleepFunction The function to be called for setting the alarm.
     * @param result A parameter to store the result. This cannot be `nullptr`.
     * @param delay The delay in seconds before the alarm triggers.
     * @return true if delay is over, false otherwise.
     *
     * @code
     * Alarm alarm;
     * int result;
     * alarm.setAlarm(exampleFunction, &result, 1.0f);
     * @endcode
     */
    template <typename Func, typename Result> 
    bool setAlarm(Func sleepFunction, Result result, float delay);

    /**
     * @brief activates the alarm. 
     * 
     * This function simply activates the alarm. 
    */
    void activate();

private:
    /**
     * we need two boolean variables, because we need to know if the timer was activated for the first time so we can set a starting time
     * only once and not override it.
    */
    bool activateTimerFirstTime;
    bool isTimerActivated;
    unsigned long previousMillis;

    /**
     * @brief checks if the interval ended.
     * 
     * @param delay is the duration of the interval.
     * @returns true if the interval ended, false otherwise.
     * 
    */
    bool wakeAlarmUp(float delay);
};

// Similar functionality to type traits in order to idenitfy pointers.
template <typename T>
struct is_pointer {
    static const bool value = false;
};

template <typename T>
struct is_pointer<T*> {
    static const bool value = true;
};

// Providing a functionality to identify null pointers as they cannot be identifed with the former method.
template <typename T>
struct is_nullptr_t {
    static const bool value = false;
};
template <>
struct is_nullptr_t<nullptr_t> {
    static const bool value = true;
};

/**
 * @brief returns true if delay is over and runs the sleepFunction, otherwise returns false and does nothing.
 * 
 * @param sleepFunction is the target function that should be executed after the delay.
 * @param delay is the delay duration in seconds.
 * 
 * @returns true if delay is over, false otherwise.
 */
template <typename Func>
bool Alarm::setAlarm(Func sleepFunction, float delay) {

    // If alarm is triggered, the condition is satisfied and sleep function is executed.
    if (wakeAlarmUp(delay)) {

        sleepFunction();
        return true;

    }
    return false;
}


template <typename Func, typename Args, typename Result>
bool Alarm::setAlarm(Func sleepFunction, Args args, Result result, float delay) {

    if (wakeAlarmUp(delay)) {

        // If result was a null pointer, sleep function is executed without handling the result. 
        if ( is_nullptr_t<Result>::value )
            sleepFunction(args); 
        else if constexpr(is_pointer<Result>::value) 
            /** 
            we use constexpr in case result was a nullptr (or of a non-pointer type) to avoid getting compilation error for trying to 
            dereference a nullptr( or trying to dereference a non-pointer type).
            */
            *result = sleepFunction(args);

        return true;

    }
    return false;
}

template <typename Func, typename Result>
bool Alarm::setAlarm(Func sleepFunction, Result result, float delay) {
    
    if ( wakeAlarmUp(delay) ) {
        *result = sleepFunction();
        return true;
    }
    return false;
}

#endif  