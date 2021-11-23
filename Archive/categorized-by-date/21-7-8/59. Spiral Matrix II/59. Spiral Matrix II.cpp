/*
Number: 59
Topic: Spiral Matrix II
Date: 2021/7/8
Rate: Medium
https://leetcode.com/problems/spiral-matrix-ii/

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Constraints:
* 1 <= n <= 20

*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));


        int i = 0, j = 0;
        int walk_i = 0, walk_j = 1;

        for (int t = 1; t <= n*n; t++) {
            matrix[i][j] = t;
            if (matrix[(i+walk_i+n)%n][(j+walk_j+n)%n]) {
                walk_i *= -1;
                swap(walk_i, walk_j);
            }
            i += walk_i;
            j += walk_j;
        }
        return matrix;
    }
};