/*
Number: 263
Topic: Ugly Number
Date: 2021/12/4
Rate: Easy
https://leetcode.com/problems/ugly-number/


An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return true if n is an ugly number.

Constraints:
    * -231 <= n <= 231 - 1
*/

class Solution {
   public:
    bool isUgly(int n) {
        /*
        T = [2, 3, 5]
        for t in T:
            while (n % t == 0)
                n /= t
        return t == 1
        */
        if (n == 0)
            return false;
        int divisor[3] = {2, 3, 5};
        for (int i = 0; i < 3; i++) {
            while (n % divisor[i] == 0) {
                n /= divisor[i];
            }
        }
        return n == 1;
    }
};