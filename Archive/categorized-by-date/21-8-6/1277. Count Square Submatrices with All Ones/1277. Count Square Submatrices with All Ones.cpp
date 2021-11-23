/*
Number: 1277
Topic: Count Square Submatrices with All Ones
Date: 2021/8/6
Rate: Medium
https://leetcode.com/problems/count-square-submatrices-with-all-ones/

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Constraints:
* 1 <= arr.length <= 300
* 1 <= arr[0].length <= 300
* 0 <= arr[i][j] <= 1
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = (m) ? matrix[0].size() : 0;
        vector<int> squareCount(300, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]) {
                    matrix[i][j] = check3(matrix, i, j) + 1;
                    squareCount[matrix[i][j]] += 1;
                }
            }
        }
        int out = 0;
        for (int k = 0; k < squareCount.size(); k++) {
            if (squareCount[k]) {
                out += squareCount[k]*k;
            }
        }
        return out;
    }

    int check3(const vector<vector<int>>& matrix, int i, int j) {
        return min(check(matrix, i-1, j-1), min(check(matrix, i-1, j), check(matrix, i, j-1)));
    }

    int check(const vector<vector<int>>& matrix, int i, int j) {
        int m = matrix.size();
        int n = (m) ? matrix[0].size() : 0;
        if (i < 0 || i >= m || j < 0 || j >= n)
            return 0;
        return matrix[i][j];
    } 
};