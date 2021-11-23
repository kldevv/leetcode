/*
Number: 329
Topic: Longest Increasing Path in a Matrix
Date: 2021/7/8
Rate: Hard
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

Constraints:
* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 200
* 0 <= matrix[i][j] <= 2^31 - 1
*/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int maxLen = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxLen = max(maxLen, longestIncreasingPath(matrix, INT_MIN, i, j, dp));
            }
        }

        return maxLen;
    }

    int longestIncreasingPath(const vector<vector<int>>& matrix, int prev, int i, int j, vector<vector<int>>& dp) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n)
            return 0;

        if (matrix[i][j] <= prev)
            return 0;

        if (dp[i][j])
            return dp[i][j];

        int toUp = longestIncreasingPath(matrix, matrix[i][j], i+1, j, dp);
        int toDown = longestIncreasingPath(matrix, matrix[i][j], i-1, j, dp);
        int toRight = longestIncreasingPath(matrix, matrix[i][j], i, j+1, dp);
        int toLeft = longestIncreasingPath(matrix, matrix[i][j], i, j-1, dp);

        dp[i][j] = max(max(toUp, toDown), max(toRight, toLeft)) + 1;
        return dp[i][j];
    }
};