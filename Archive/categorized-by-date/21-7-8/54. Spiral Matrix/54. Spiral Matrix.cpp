/*
Number: 54
Topic: Spiral Matrix
Date: 2021/7/8
Rate: Medium
https://leetcode.com/problems/spiral-matrix/

Given an m x n matrix, return all elements of the matrix in spiral order.


Constraints:
* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 10
* -100 <= matrix[i][j] <= 100

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = (m) ? matrix[0].size() : 0;

        vector<int>out;

        if (m == 1) {
            for (int i = 0; i < n; i++) {
                out.push_back(matrix[0][i]);
            }
            return out;    
        }

        if (n == 1) {
            for (int i = 0; i < m; i++) {
                out.push_back(matrix[i][0]);
            }
            return out;
        }


        int i = 0;
        int j = 0;
        int i_inc = 0;
        int j_inc = 1;
        int total = m * n;

        while (out.size() < total) {
            out.push_back(matrix[i][j]);
            if ((j==n-1 && i==0) || (j==0 && i==m-1) || matrix[i][j+j_inc]==INT_MIN) { 
                swap(j_inc, i_inc);
            }
            else if ((i==m-1 && j==n-1) || matrix[i+i_inc][j]==INT_MIN) {
                i_inc *= -1;
                swap(j_inc, i_inc);
            }
            matrix[i][j] = INT_MIN;
            i += i_inc;
            j += j_inc;
        }

        return out;
    }
};