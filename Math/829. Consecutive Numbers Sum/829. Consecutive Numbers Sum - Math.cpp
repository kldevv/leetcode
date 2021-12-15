/*
Number: 829
Topic: Consecutive Numbers Sum
Date: 2021/11/18
Rate: Hard
https://leetcode.com/problems/consecutive-numbers-sum/

Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.

Constraints:
    * 1 <= n <= 109
*/
#include <cmath>
/* Complexity
TC: O(sqrt(n))
SC: O(1)
*/
class Solution {
   public:
    int consecutiveNumbersSum(int n) {
        /* Math formula
        n = (x + 1) + (x + 2) + ... + (x+k)
        n = xk + (1+2+...+k)
        n = xk + k(1+k)/2
            >> We go through all the k to and check if x is valid

        x = n/k - (1+k)/2

        1. x should be non-negative
            n/k >= (1+k)/2

            2n/k >= (1+k)
            2n + 1/4 >= (k^2+k+(1/2)^2)
            2n + 1/4 >= (k+1/2)^2

            sqrt(2n + 1/4) - 1/2 >= k
                >> We set the upper bound of k

        2. x should be integer
            n/k - (1+k)/2 should be an integer

            (n - k*(1+k)/2) % k == 0
                >> Validity check



        */

        int upperBoundOfK = (int)(std::sqrt(2 * n + 0.25) - 0.5);

        int result = 0;
        for (int k = 1; k <= upperBoundOfK; k++) {
            if ((n - k * (1 + k) / 2) % k == 0)
                result += 1;
        }
        return result;
    }
};