/**
 * @file Alarm.h
 * @brief A library for handling alarms with optional result handling.
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

#include "Alarm.h"

Alarm::Alarm() {
    activateTimerFirstTime = false;
    isTimerActivated = false;
}


bool Alarm::wakeAlarmUp(float delay) {

    // If timer activated for the first time, the starting point is saved in the variable previousMillis.
    if (activateTimerFirstTime)
        previousMillis = millis();

    /** 
     *  If timer is activated for the first time, the flag that indicates that the timer is activated for the first time is set to false,
     *  and the flag that the alarm is triggered is set to true.
    */
    if (activateTimerFirstTime) {
        isTimerActivated = true;
        activateTimerFirstTime = false;
    }
    
    /**
     * If timer is activated, the code inside the if statement checks if the timer ended, if it ended, it turns of the isTimerActivated flag and 
     * the function returns true, otherwise, the function returns false.
     * 
    */
    if (isTimerActivated) {
        bool isAlarmUp = (millis() - previousMillis) >= static_cast<unsigned long>(delay * 1000);

        if(isAlarmUp) 
            isTimerActivated = false;

        return isAlarmUp;
    }  
    return false;
}
void Alarm::activate() {
    activateTimerFirstTime = true;
}

