/*
Number: 221
Topic: Maximal Square
Date: 2021/12/3
Rate: Medium
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Constraints:
    * m == matrix.length
    * n == matrix[i].length
    * 1 <= m, n <= 300
    * matrix[i][j] is '0' or '1'.
*/

#include <vector>

using namespace std;

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /*
        matrix = [
            ["1","0","1","0","0"],
            ["1","0","1","1","1"],
            ["1","1","1","1","1"],
            ["1","0","0","1","0"]
            ]

        dp[i][j] == biggest square lenght with a lower right corner at row i and col j
        At row i and col j
            dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]); <<< space optimization
        */
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(2, vector<int>(n, 0));
        int maxLen = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != '0') {
                    if (i > 0 && j > 0) {
                        dp[(i % 2)][j] = min(dp[(i + 1) % 2][j - 1], min(dp[(i + 1) % 2][j], dp[i % 2][j - 1])) + 1;
                    } else {
                        dp[i % 2][j] = matrix[i][j] - '0';
                    }
                } else {
                    dp[i % 2][j] = 0;
                }
                maxLen = max(maxLen, dp[i % 2][j]);
            }
        }
        return maxLen * maxLen;
    }
};