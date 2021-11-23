/*
Number: 867
Topic: Transpose Matrix
Date: 2021/11/1
Rate: Easy
https://leetcode.com/problems/transpose-matrix/

Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

Constraints:
    * m == matrix.length
    * n == matrix[i].length
    * 1 <= m, n <= 1000
    * 1 <= m * n <= 105
    * -109 <= matrix[i][j] <= 109
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = (m) ? matrix[0].size() : 0;
        vector<vector<int>> newMatrix(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                newMatrix[j][i] = matrix[i][j];
            }
        }
        return newMatrix;
    }
};
