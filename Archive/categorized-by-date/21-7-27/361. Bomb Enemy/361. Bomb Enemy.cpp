/*
Number: 361
Topic: Bomb Enemy
Date: 2021/7/26
Rate: Medium
https://leetcode.com/problems/bomb-enemy/

Given an m x n matrix grid where each cell is either a wall 'W', an enemy 'E' or empty '0', return the maximum enemies you can kill using one bomb. You can only place the bomb in an empty cell.

The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since it is too strong to be destroyed.

Constraints:
* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 500
* grid[i][j] is either 'W', 'E', or '0'.
*/

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = (m) ? grid[0].size() : 0;
        vector<int> colHit(n, 0);
        int maxHit = 0;

        for (int i = 0; i < m; i++) {
            int rowHit = 0;
            for (int j = 0; j < n; j++) {
                if (!j || grid[i][j-1] == 'W') {
                    rowHit = 0;
                    for (int k = j; k < n && grid[i][k] != 'W'; k++) {
                        rowHit += (grid[i][k] == 'E');
                    }
                }
                if (!i || grid[i-1][j] == 'W') {
                    colHit[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; k++) {
                        colHit[j] += (grid[k][j] == 'E');
                    }
                }

                if (grid[i][j] == '0')
                    maxHit = max(maxHit, rowHit+colHit[j]);
            }
        }
        return maxHit;
    }
};
