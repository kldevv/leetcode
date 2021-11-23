/*
Number: 264
Topic: Ugly Number II
Date: 2021/6/9
Rate: Medium
https://leetcode.com/problems/ugly-number-ii/

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

Constraints:
* 1 <= n <= 1690

*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp = {1};
        // see: https://leetcode.com/problems/ugly-number-ii/discuss/69362/O(n)-Java-solution
        int t2 = 0, t3 = 0, t5 = 0;
        while (dp.size() < n) {
            dp.push_back(min(dp[t2]*2, min(dp[t3]*3, dp[t5]*5)));
                          
            if (dp[i] == dp[t2]*2)
                t2++;
            if (dp[i] == dp[t3]*3)
                t3++;
            if (dp[i] == dp[t5]*5)
                t5++;
        }
        return dp[n-1];
    }
};