/*
Number: 264
Topic: Ugly Number II - Naive, TLE
Date: 2021/12/4
Rate: Medium
https://leetcode.com/problems/ugly-number-ii/

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

Constraints:
    * 1 <= n <= 1690
*/

#include <vector>

using namespace std;

class Solution {
   public:
    int nthUglyNumber(int n) {
        /*
        Given:
            if :
            1. i % 2 == 0 && dp[i / 3] is ugly
            2. i % 3 == 0 && dp[i / 3] is ugly
            3. i % 5 == 0 && dp[i / 5] is ugly
                i is ugly
        Base cases:
            1. 1 is ugly

        */
        if (n == 1)
            return 1;

        vector<int> divisors = {2, 3, 5};
        vector<int> dp(2, 0);
        dp[1] = 1;

        int i = 2;
        for (; n > 1; i++) {
            int isUgly = 0;
            for (int divisor : divisors) {
                if (i == 1 || (i % divisor == 0 && dp[(i / divisor)] == 1)) {
                    isUgly = 1;
                }
            }
            n -= isUgly;
            dp.push_back(isUgly);

            if (n == 1)
                break;
        }
        return i;
    }
};