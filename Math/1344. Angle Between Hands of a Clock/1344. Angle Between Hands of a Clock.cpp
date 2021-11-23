/*
Number: 1344
Topic: Angle Between Hands of a Clock
Date: 2021/9/28
Rate: Medium
https://leetcode.com/problems/angle-between-hands-of-a-clock/

Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.

Constraints:
    * 1 <= hour <= 12
    * 0 <= minutes <= 59
    * Answers within 10^-5 of the actual value will be accepted as correct.
*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minA = minutesAngel(minutes);
        double hrA = hourAngel(hour, minutes);
        return min(abs(minA - hrA), 360 - abs(minA - hrA));
    }
    
    double minutesAngel(int minutes) {
        return (double) 360 / 60 * minutes;
    }
    
    double hourAngel(int hour, int minutes) {
        return (double) 360 / (12 * 60) * ((hour * 60) + minutes);
    }
};