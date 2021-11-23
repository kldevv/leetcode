/*
Number: 7
Topic: Reverse Integer
Date: 2021/6/1
Rate: Easy
https://leetcode.com/problems/reverse-integer/

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 

Constraints:
* -2^31 <= x <= 2^31 - 1

*/


class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if (x < 0)
            sign = -1;

        int y = 0;
        while (x) {
            int last_digit = abs(x % 10);
            if (y <= (INT_MAX-last_digit) / 10) {
                y = y*10 + last_digit;
                x /= 10;
            } else {
                return 0;
            }
        }
        return y * sign;
    }
};