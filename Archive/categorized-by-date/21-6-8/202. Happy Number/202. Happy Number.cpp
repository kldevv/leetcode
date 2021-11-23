/*
Number: 202
Topic: Happy Number
Date: 2021/6/7
Rate: Easy
https://leetcode.com/problems/happy-number/

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

* Starting with any positive integer, replace the number by the sum of the squares of its digits.
* Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
* Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Constraints:
* 1 <= n <= 2^31 - 1

*/
class Solution {
public:
    // 用 Floyd Cycle Detection Algorithm 去找 Happy Number
    bool isHappy(int n) {
        int fast = n, slow = n;
        do {
            fast = digitSquareSum(digitSquareSum(fast));
            slow = digitSquareSum(slow);
            if (fast == 1 || slow == 1)
                return true;
        } while (fast != slow);
        return false;
    }

    int digitSquareSum(int n) {
        int out = 0;
        while (n) {
            out += (n%10) * (n%10);
            n /= 10;
        }
        return out;
    }
};