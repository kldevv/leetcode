/*
Number: 64
Topic: Minimum Path Sum
Date: 2021/5/13
Rate: Medium
https://leetcode.com/problems/minimum-path-sum/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100

*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // dp[j] 代表到在 i row 時 走到 dp[j][i] 最佳的路徑
        // 而 dp[j][i] 只和 do[j-1][i] 和 dp[j][i-1] 有關，故可以壓縮
        vector<int> dp = {grid[0][0]};
        int m = grid.size(), n = grid[0].size();

        // 先填滿第一列的 dp
        for (int j = 1; j < m; j++) {
            dp.push_back(dp[j-1] + grid[j][0]);
        }
        // 再跑每一個 row
        for (int i = 1; i < n; i++) {
            // 當個 row 的不同 col
            for (int j = 0; j < m; j++) {
                // 最佳的路線會是上面(dp[j-1]或左邊那格dp[j](未更新前)的最佳路線加上本格)
                dp[j] = min(dp[j], dp[max(j-1, 0)]) + grid[j][i];
            }
        }

        return dp[m-1];
    }
};