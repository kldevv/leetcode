/*
Number: 994
Topic: Rotting Oranges
Date: 2021/8/24
Rate: Medium
https://leetcode.com/problems/rotting-oranges/

You are given an m x n grid where each cell can have one of three values:

* 0 representing an empty cell,
* 1 representing a fresh orange, or
* 2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Constraints:
* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 10
* grid[i][j] is 0, 1, or 2.
*/

class Solution {
private:
    vector<vector<int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = (m) ? grid[0].size() : 0;
        
        queue<int> rootten;
        // get the fresh organge number
        int k = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                k += (grid[i][j] == 1);
                if (grid[i][j] == 2)
                    rootten.push(i*n + j);
            }
        }

        int minute = 0;
        while (rootten.size() && k > 0) {
            minute += 1;
            int t = rootten.size();
            for (int s = 0; s < t; s++) {
                int i = rootten.front() / n;
                int j = rootten.front() % n;
                rootten.pop();
                virusSpread(grid, rootten, i, j, k);
            }
        }
        return (k == 0) ? minute : -1;
    }

    void virusSpread(vector<vector<int>>& grid, queue<int>& rootten, int i, int j, int& k) {
        int m = grid.size(), n = (m) ? grid[0].size() : 0;
        for (vector<int> dir : direction) {
            int x = i + dir[0];
            int y = j + dir[1];
            if (validIndex(m, n, x, y) && grid[x][y] == 1) {
                k -= 1;
                grid[x][y] = 2;
                rootten.push(x*n + y);
            }
        }
    }

    bool validIndex(int m, int n, int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
};