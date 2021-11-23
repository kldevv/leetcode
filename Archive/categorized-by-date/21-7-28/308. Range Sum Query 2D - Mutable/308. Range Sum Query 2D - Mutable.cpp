/*
Number: 308
Topic: Range Sum Query 2D - Mutable
Date: 2021/7/28
Rate: Hard
https://leetcode.com/problems/range-sum-query-2d-mutable/

Given a 2D matrix matrix, handle multiple queries of the following types:

Update the value of a cell in matrix.
Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Implement the NumMatrix class:
* NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
* void update(int row, int col, int val) Updates the value of matrix[row][col] to be val.
* int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Constraints:
* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 200
* -105 <= matrix[i][j] <= 105
* 0 <= row < m
* 0 <= col < n
* -105 <= val <= 105
* 0 <= row1 <= row2 < m
* 0 <= col1 <= col2 < n
* At most 104 calls will be made to sumRegion and update.
*/
class NumMatrix {
private:
    vector<vector<int>> num;
    vector<vector<int>> fenwickTree;
    int m, n;

    int sumFromOri(int row, int col) {
        int sum = 0;
        for (int i = row+1; i > 0; i -= i&(-i)) {
            for (int j = col+1; j > 0; j -= j&(-j)) {
                sum += fenwickTree[i][j];
            }
        }
        return sum;
    }

public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->m = matrix.size();
        this->n = (m) ? matrix[0].size() : 0; 
        this->num = vector<vector<int>>(m, vector<int>(n, 0));
        this->fenwickTree = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        // deep copy
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                update(i, j, matrix[i][j]);
            }
        }

        // for (int i = 0; i <= m; i++) {
        //     for (int j = 0; j <= n; j++) {
        //         cout << fenwickTree[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    
    void update(int row, int col, int val) {
        if (row < 0 || col < 0 || row >= m || col >= n)
            return;

        int delta = val - num[row][col];
        num[row][col] = val;
        for (int i = row+1; i <= m; i += i&(-i)) {
            for (int j = col+1; j <= n; j += j&(-j)) {
                fenwickTree[i][j] += delta;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumFromOri(row2, col2) - sumFromOri(row2, col1-1) - sumFromOri(row1-1, col2) + sumFromOri(row1-1, col1-1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */