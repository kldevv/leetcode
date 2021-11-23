/*
Number: 221
Topic: 
Date: 2021/11/16
Rate: Medium
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Constraints:
    * m == matrix.length
    * n == matrix[i].length
    * 1 <= m, n <= 300
    * matrix[i][j] is '0' or '1'.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();

        int maxLen = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != '0') {
                    if (i >= 1 && j >= 1)
                        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    else
                        dp[i][j] = matrix[i][j] - '0';
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        return maxLen * maxLen;
    }
};