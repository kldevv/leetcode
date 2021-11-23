/*
Number: 304
Topic: Range Sum Query 2D - Immutable
Date: 2021/7/12
Rate: Medium
https://leetcode.com/problems/range-sum-query-2d-immutable/

Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Constraints:
* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 200
* -105 <= matrix[i][j] <= 105
* 0 <= row1 <= row2 < m
* 0 <= col1 <= col2 < n
* At most 104 calls will be made to sumRegion.

*/
class NumMatrix {
private:
    vector<vector<int>> sum;

    int getSum(int i, int j) {
        if (i < 0 || j < 0)
            return 0;
        return sum[i][j];
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sum = matrix;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                sum[i][j] += (getSum(i-1, j) + getSum(i, j-1) - getSum(i-1, j-1));
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2, col2) - getSum(row2, col1-1) - getSum(row1-1, col2) + getSum(row1-1, col1-1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */