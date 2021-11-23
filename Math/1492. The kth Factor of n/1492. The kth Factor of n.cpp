/*
Number: 1492
Topic: The kth Factor of n
Date: 2021/9/25
Rate: Medium
https://leetcode.com/problems/the-kth-factor-of-n/

Given two positive integers n and k.

A factor of an integer n is defined as an integer i where n % i == 0.

Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.

Constraints:
    * 1 <= k <= n <= 1000
*/

class Solution {
public:
    int kthFactor(int n, int k) {
        int divisor = 1;
        for (; divisor*divisor <= n; divisor++) {
            if (n % divisor == 0 && --k == 0)
                return divisor;
        }

        for (--divisor; divisor > 0; divisor--) {
            if (divisor*divisor == n)
                continue;
            if (n % divisor == 0 && --k == 0)
                return n / divisor;            
        }
        return -1;
    }
};