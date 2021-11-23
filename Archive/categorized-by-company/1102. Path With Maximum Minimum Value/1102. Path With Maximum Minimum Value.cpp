/*
Number: 1102
Topic: Path With Maximum Minimum Value
Date: 2021/9/2
Rate: Medium
https://leetcode.com/problems/path-with-maximum-minimum-value/

Given an m x n integer matrix grid, return the maximum score of a path starting at (0, 0) and ending at (m - 1, n - 1) moving in the 4 cardinal directions.

The score of a path is the minimum value in that path.

    * For example, the score of the path 8 → 4 → 5 → 9 is 4.

Constraints:
    * m == grid.length
    * n == grid[i].length
    * 1 <= m, n <= 100
    * 0 <= grid[i][j] <= 109
*/

class Solution {
private:
    vector<pair<int, int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = (m) ? grid[0].size() : 0;
        int minScore = grid[0][0];

        priority_queue<tuple<int, int, int>> nextStep;
        nextStep.emplace(grid[0][0], 0, 0);
        grid[0][0] = -1;

        while (nextStep.size()) {
            auto [score, i, j] = nextStep.top();
            nextStep.pop();

            minScore = min(minScore, score);

            if (i == m-1 && j == n-1)
                break;

            for (pair<int, int> dir : direction) {
                int ii = i + dir.first;
                int jj = j + dir.second;
                if (ii >= 0 && ii < m && jj >= 0 && jj < n && grid[ii][jj] >= 0) {
                    nextStep.emplace(grid[ii][jj], ii, jj);
                    grid[ii][jj] = -1;
                }
            }
        }
        return minScore;
    }
};