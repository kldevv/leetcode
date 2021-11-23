/*
Number: 1293
Topic: Shortest Path in a Grid with Obstacles Elimination
Date: 2021/8/10
Rate: Hard
https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

Constraints:
* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 40
* 1 <= k <= m * n
* grid[i][j] == 0 or 1
* grid[0][0] == grid[m - 1][n - 1] == 0
*/

class Solution {
private:
    vector<pair<int, int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = (m) ? grid[0].size() : 0;
        if (m == 1 && n == 1)
            return 0;

        queue<vector<int>> q;
        q.push({0, 0, k});
        vector<int> umap(m*n, -1);

        int step = 0;
        int minStepNextRound = max(0, m + n - 2);

        while (q.size()) {
            int t = q.size();
            step += 1;
            for (int v = 0; v < t; v++) {
                int i = q.front()[0];
                int j = q.front()[1];
                int remainK = q.front()[2];
                q.pop();

                int minStep = minStepNextRound;

                for (const pair<int, int>& dir : direction) {
                    int row = i + dir.first;
                    int col = j + dir.second;
                    if (row < 0 || row >= m || col < 0 || col >= n)
                        continue;

                    int remainKK = remainK - grid[row][col];
                    if (umap[row*n + col] >= remainKK)
                        continue;

                    int stepToTarget = m+n-row-col-2;
                    if (remainKK >= stepToTarget-1 && stepToTarget == minStep-1)
                        return step + stepToTarget;

                    minStepNextRound = min(minStepNextRound, stepToTarget);

                    umap[row*n + col] = remainKK;
                    q.push({row, col, remainKK});
                }
            }
        }
        return -1;
    }
};