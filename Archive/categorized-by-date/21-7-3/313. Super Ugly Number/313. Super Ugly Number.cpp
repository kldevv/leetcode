/*
Number: 313
Topic: Super Ugly Number
Date: 2021/7/3
Rate: Medium
https://leetcode.com/problems/super-ugly-number/

A super ugly number is a positive integer whose prime factors are in the array primes.

Given an integer n and an array of integers primes, return the nth super ugly number.

The nth super ugly number is guaranteed to fit in a 32-bit signed integer.


Constraints:
* 1 <= n <= 106
* 1 <= primes.length <= 100
* 2 <= primes[i] <= 1000
* primes[i] is guaranteed to be a prime number.
* All the values of primes are unique and sorted in ascending order.

*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        // ptr 代表目前的 power
        vector<int> ptr(m, 0);
        // dp[i] 代表第 i 個 ugly number
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            int nextMin = INT_MAX;
            vector<int> minIdx;
            for (int j = 0; j < m; j++) {
                int val = dp[ptr[j]]*primes[j];
                if (val < nextMin) {
                    nextMin = val;
                    minIdx = {j};
                }
                else if (val == nextMin) {
                    minIdx.push_back(j);
                }
            }
            for (const int& idx : minIdx) {
                ptr[idx]++;
            }
            dp[i] = nextMin;
        }
        return dp[n-1];
    }
};