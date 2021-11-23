/*
Number: 62
Topic: Unique Paths
Date: 2021/6/19
Rate: Medium
https://leetcode.com/problems/unique-paths/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Constraints:
* 1 <= m, n <= 100
* It's guaranteed that the answer will be less than or equal to 2 * 109.

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(m, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[j] = dp[j-1] + dp[j];
            }
        }
        return dp[m-1];
    }
};