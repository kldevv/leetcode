/*
Number: 1091
Topic: Shortest Path in Binary Matrix
Date: 2021/11/2
Rate: Medium
https://leetcode.com/problems/shortest-path-in-binary-matrix/

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
    * All the visited cells of the path are 0.
    * All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.

Constraints:
    * n == grid.length
    * n == grid[i].length
    * 1 <= n <= 100
    * grid[i][j] is 0 or 1
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions = {
            {1, 1},
            {-1, -1},
            {1, -1},
            {-1, 1},
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        int m = grid.size();
        int n = (m) ? grid[0].size() : 0;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        int step = 1;

        while (q.size()) {
            int qSize = q.size();
            for (int iter = 0; iter < qSize; iter++) {
                auto [i, j] = q.front();
                q.pop();
                if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 1)
                        continue;
                if (i == m-1 && j == n-1)
                    return step;
                for (auto [iDelta, jDelta] : directions) {
                    int ii = i + iDelta;
                    int jj = j + jDelta;
                    q.push(make_pair(ii, jj));
                }
                grid[i][j] = 1;
            }
            step += 1;
        }
        return -1;
    }
};