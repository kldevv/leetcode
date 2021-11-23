/*
Number: 542
Topic: 01 Matrix
Date: 2021/9/1
Rate: Medium
https://leetcode.com/problems/01-matrix/

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Constraints:
* m == mat.length
* n == mat[i].length
* 1 <= m, n <= 104
* 1 <= m * n <= 104
* mat[i][j] is either 0 or 1.
* There is at least one 0 in mat.
*/

class Solution {
private:
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = (m) ? mat[0].size() : 0;

        queue<vector<int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int step = 0;
        vector<vector<int>> result(m, vector<int>(n, -1));
        while (q.size()) {
            int t = q.size();
            for (int s = 0; s < t; s++) {
                int i = q.front()[0];
                int j = q.front()[1];
                q.pop();
                result[i][j] = step;

                for (vector<int>& dir : directions) {
                    int ii = i + dir[0];
                    int jj = j + dir[1];
                    if (ii >= 0 && ii < m && jj >= 0 && jj < n && mat[ii][jj] != 0) {
                        mat[ii][jj] = 0;
                        q.push({ii, jj});
                    }
                }
            }
            step += 1;
        }
        return result;

    }
};