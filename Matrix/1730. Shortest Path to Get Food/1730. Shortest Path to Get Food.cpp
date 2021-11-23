/*
Number: 1730
Topic: Shortest Path to Get Food
Date: 2021/9/28
Rate: Medium
https://leetcode.com/problems/shortest-path-to-get-food/

You are starving and you want to eat food as quickly as possible. You want to find the shortest path to arrive at any food cell.

You are given an m x n character matrix, grid, of these different types of cells:

    * '*' is your location. There is exactly one '*' cell.
    * '#' is a food cell. There may be multiple food cells.
    * 'O' is free space, and you can travel through these cells.
    * 'X' is an obstacle, and you cannot travel through these cells.

You can travel to any adjacent cell north, east, south, or west of your current location if there is not an obstacle.

Return the length of the shortest path for you to reach any food cell. If there is no path for you to reach food, return -1.


Constraints:
    * m == grid.length
    * n == grid[i].length
    * 1 <= m, n <= 200
    * grid[row][col] is '*', 'X', 'O', or '#'.
    * The grid contains exactly one '*'.
*/

class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = (m) ? grid[0].size() : 0;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<vector<int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '*') {
                    grid[i][j] = 'X';
                    q.push({i, j});
                }
            }
        }

        int step = 0;
        while (q.size()) {
            int qSize = q.size();
            step += 1;
            for (int t = 0; t < qSize; t++) {
                vector<int> coord = q.front();
                q.pop();
                int i = coord[0];
                int j = coord[1];
                for (vector<int> dir : directions) {
                    int ii = i + dir[0];
                    int jj = j + dir[1];
                    if (isValid(ii, jj, grid)) {
                        if (grid[ii][jj] == '#')
                            return step;
                        grid[ii][jj] = 'X';
                        q.push({ii, jj});
                    }
                }
            }
        }
        return -1;
    }

    bool isValid(int i, int j, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = (m) ? grid[0].size() : 0;
        if (i >= m || j >= n || i < 0 || j < 0 || grid[i][j] == 'X')
            return false;
        return true;
    }
};
