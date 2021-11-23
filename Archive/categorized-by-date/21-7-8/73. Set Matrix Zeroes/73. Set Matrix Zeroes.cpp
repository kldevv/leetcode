/*
Number: 73
Topic: Set Matrix Zeroes
Date: 2021/7/8
Rate: Medium
https://leetcode.com/problems/set-matrix-zeroes/

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.

Constraints:
* m == matrix.length
* n == matrix[0].length
* 1 <= m, n <= 200
* -231 <= matrix[i][j] <= 231 - 1

Follow up:
* A straight forward solution using O(mn) space is probably a bad idea.
* A simple improvement uses O(m + n) space, but still not the best solution.
* Could you devise a constant space solution?

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = (m) ? matrix[0].size() : 0;

        int i_0 = 1, j_0 = 1;
        if (!matrix[0][0]) {
            i_0 = 0, j_0 = 0;
        }
        else {
            for (int j = 0; j < n; j++) {
                if (!matrix[0][j])
                    j_0 = 0;
            }
            for (int i = 0; i < m; i++) {
                if (!matrix[i][0])
                    i_0 = 0;
            }
        }

        markZeros(matrix);
        fillZeros(matrix, i_0, j_0);
    } 

    void markZeros(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = (m) ? matrix[0].size() : 0;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
    }

    void fillZeros(vector<vector<int>>& matrix, int i_0, int j_0) {
        int m = matrix.size();
        int n = (m) ? matrix[0].size() : 0;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            if (!i_0)
                matrix[i][0] = 0;
        }

        for (int j = 0; j < n; j++) {
            if (!j_0)
                matrix[0][j] = 0;
        }      
    }
};