/*
Number: 311
Topic: Sparse Matrix Multiplication
Date: 2021/7/23
Rate: Medium
https://leetcode.com/problems/sparse-matrix-multiplication/

Given two sparse matrices mat1 of size m x k and mat2 of size k x n, return the result of mat1 x mat2. You may assume that multiplication is always possible.

Constraints:
m == mat1.length
k == mat1[i].length == mat2.length
n == mat2[i].length
1 <= m, n, k <= 100
-100 <= mat1[i][j], mat2[i][j] <= 100
*/

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat2.size();
        int n = (k) ? mat2[0].size() : 0;

        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for (int mat1Row = 0; mat1Row < m; mat1Row++) {
            for (int i = 0; i < k; i++) {
                if (!mat1[mat1Row][i])
                    continue;
                for (int mat2Col = 0; mat2Col < n; mat2Col++)
                    matrix[mat1Row][mat2Col] += mat1[mat1Row][i] * mat2[i][mat2Col];
            }
        }
        return matrix;
    }
};