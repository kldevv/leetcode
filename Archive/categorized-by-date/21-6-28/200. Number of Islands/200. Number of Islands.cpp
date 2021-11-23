/*
Number: 200
Topic: Number of Islands
Date: 2021/6/28
Rate: Medium
https://leetcode.com/problems/number-of-islands/

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Constraints:
* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 300
* grid[i][j] is '0' or '1'.

*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = (m) ? grid[0].size() : 0;
        int island = 0;
        // amortized TC: O(mn)

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 發現一塊土地
                if (grid[i][j] == '1') {
                    // 把整個島嶼消除，這樣就不會重複計算到同一個島嶼的同個土地了
                    eraseWholeIsland(grid, i, j);
                    island += 1;
                }
            }
        }
        return island;
    }

    void eraseWholeIsland(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = (m) ? grid[0].size() : 0;

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
            return;

        grid[i][j] = '0';
        eraseWholeIsland(grid, i+1, j);
        eraseWholeIsland(grid, i-1, j);
        eraseWholeIsland(grid, i, j+1);
        eraseWholeIsland(grid, i, j-1);
    }
};