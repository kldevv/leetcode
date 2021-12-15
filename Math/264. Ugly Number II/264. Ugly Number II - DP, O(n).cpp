/*
Number: 264
Topic: Ugly Number II - DP, O(n)
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
        nthUglyNumber[n]

        uglyNumber u = 2^t2 * 3^t3 * 5^t5

        greedily select the smallest u so far
        > pick the smallest number and increase either t2, t3, or t5

        for U in uglyNumberSoFar:
            if U * {2, 3, 5} is minIncrease:
                nextUgly = U * {2, 3, 5};

        for i in range(n):
            for j in range(T):
                if (dp[pow[j]] * T[j] <= smallestIncrease)
                    pow[j] += 1;
                    smallestIncrease = dp[pow[j]] * T[j];
        return dp[n-1];


        %%%%%%%%%%%%%%%
        Complexity:
            T(n) = O(n)
            S(n) = O(n)
        */
        int factors[3] = {2, 3, 5};
        int pow[3] = {0, 0, 0};

        vector<int> uglySeq(n, 0);
        uglySeq[0] = 1;

        for (int i = 1; i < n; i++) {
            int nextUgly = INT_MAX;
            for (int j = 0; j < 3; j++) {
                if (uglySeq[pow[j]] * factors[j] <= nextUgly) {
                    nextUgly = uglySeq[pow[j]] * factors[j];
                }
            }
            uglySeq[i] = nextUgly;
            for (int j = 0; j < 3; j++) {
                if (uglySeq[pow[j]] * factors[j] == nextUgly) {
                    pow[j] += 1;
                }
            }
        }
        return uglySeq[n - 1];
    }
};