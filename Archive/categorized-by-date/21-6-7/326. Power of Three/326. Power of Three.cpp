/*
Number: 326
Topic: Power of Three
Date: 2021/6/7
Rate: Easy

Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

Constraints:
* -23^1 <= n <= 23^1 - 1
 
Follow up: Could you solve it without loops/recursion?

*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        // 1162261467 is 3^19,  3^20 is bigger than int  
        return (n > 0 && 1162261467%n == 0);
    }
};