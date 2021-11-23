/*
Number: 64
Topic: Minimum Path Sum
Date: 2021/6/22
Rate: Medium
https://leetcode.com/problems/minimum-path-sum/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Constraints:
* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 200
* 0 <= grid[i][j] <= 100

*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = (m) ? grid[0].size() : 0;
        
        // dp[j] 記錄在第 i 個 col 時，第 j 個 row 的最小路徑
        vector<int> dp(m, 0);
        dp[0] = grid[0][0];
        for (int j = 1; j < m; j++)
            dp[j] = dp[j-1] + grid[j][0];

        for (int i = 1; i < n; i++) {
            dp[0] += grid[0][i];
            for (int j = 1; j < m; j++) {
                // 每次的最佳解就是從上面來，或是從左邊來，選小者
                dp[j] = grid[j][i] + min(dp[j-1], dp[j]);
            }
        }

        return dp[m-1];
    }
};