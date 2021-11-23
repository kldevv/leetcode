/*
Number: 63
Topic: Unique Paths II
Date: 2021/6/19
Rate: Medium
https://leetcode.com/problems/unique-paths-ii/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

Constraints:
* m == obstacleGrid.length
* n == obstacleGrid[i].length
* 1 <= m, n <= 100
* obstacleGrid[i][j] is 0 or 1


*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // obstacle 1
        // space 0

        int m = obstacleGrid.size();
        int n = (m) ? obstacleGrid[0].size() : 0;

        vector<int> dp(m, 0);
        if (!dp.empty())
            dp[0] = (!obstacleGrid[0][0]) ? 1 : 0;


        for (int i = 1; i < m; i++)
            dp[i] = (!obstacleGrid[i][0]) ? dp[i-1] : 0;

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (i == 0)
                    dp[i] = (!obstacleGrid[0][j]) ? dp[0] : 0;
                else
                    dp[i] = (!obstacleGrid[i][j]) ? dp[i-1]+dp[i] : 0;
            }
        }
        
        return dp[m-1];
    }
};