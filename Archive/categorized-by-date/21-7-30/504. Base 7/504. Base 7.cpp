/*
Number: 504
Topic: Base 7
Date: 2021/7/29
Rate: Easy
https://leetcode.com/problems/base-7/

Given an integer num, return a string of its base 7 representation.

Constraints:
* -107 <= num <= 107
*/

class Solution {
public:
    string convertToBase7(int num) {
        if (num < 0)
            return "-" + convertToBase7(-num);
        if (num < 7)
            return to_string(num);
        return convertToBase7(num / 7) + convertToBase7(num % 7);
    }
};