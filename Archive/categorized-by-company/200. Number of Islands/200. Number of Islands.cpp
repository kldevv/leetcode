/*
Number: 200
Topic: Number of Islands
Date: 2021/8/27
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

        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result += numIslands(grid, i, j);
            }
        }
        return result;
    }

    int numIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = (m) ? grid[0].size() : 0;
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
            return 0;

        grid[i][j] = '0';
        numIslands(grid, i+1, j);
        numIslands(grid, i, j+1);
        numIslands(grid, i-1, j);
        numIslands(grid, i, j-1);
        return 1;
    }
};