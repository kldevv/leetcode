/*
Number: 63
Topic: Unique Paths II
Date: 2021/5/21
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
* obstacleGrid[i][j] is 0 or 1.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> dp;
        if (!obstacleGrid[0][0]) 
            dp.push_back(1);
        else
            dp.push_back(0);

        int m = obstacleGrid.size();
        int n = (m) ? obstacleGrid[0].size() : 0;

        for (int j = 1; j < m; j++) {
            if (!obstacleGrid[j][0])
                dp.push_back(dp[j-1]);
            else
                dp.push_back(0);
        }

        for (int i = 1; i < n; i++) {
            if (!obstacleGrid[0][i]) 
                dp[0] = dp[0];
            else
                dp[0] = 0;

            for (int j = 1; j < m; j++) {
                if (!obstacleGrid[j][i]) 
                    dp[j] = (dp[j-1]+dp[j]);
                else
                    dp[j] = 0;
            }

        }
        return dp[m-1];
    }
};