/*
Number: 73
Topic: Set Matrix Zeroes
Date: 2021/5/10
Rate: Medium
https://leetcode.com/problems/set-matrix-zeroes/

Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:
* A straight forward solution using O(mn) space is probably a bad idea.
* A simple improvement uses O(m + n) space, but still not the best solution.
* Could you devise a constant space solution?

Constraints:
* m == matrix.length
* n == matrix[0].length
* 1 <= m, n <= 200
* -231 <= matrix[i][j] <= 231 - 1

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 第一次順著 loop 紀錄哪些 row 和 col 要被轉換成 0
        // 1. matrix[col][0] 代表 matrix[...][row] 要轉換成 0
        // 2. matrix[0][row] 代表 matrix[col][...] 要轉換成 0
        bool isColOneZero = false;
        // 因為 matrix[0][0] 同時可以代表 1. 和 2. 這邊選擇讓其代表 row (1.) 
        for (int col = 0; col < matrix.size(); col++) {
            // 不要去碰到 matrix[0][0] 的值，因為要拿來紀錄 row
            // 所以在 loop 第一個 row 時，另外紀錄此 col 的訊息
            if (matrix[col][0] == 0) isColOneZero = true;
            for (int row = 1; row < matrix[0].size(); row++) {
                if (matrix[col][row] == 0) {
                    matrix[col][0] = 0;
                    matrix[0][row] = 0;
                }
            }
        }
        // 逆向填滿，記錄的那格最後才會被處理到
        for (int col = matrix.size()-1; col >= 0; col--) {
            for (int row = matrix[0].size()-1; row > 0; row--) {
                if (!matrix[0][row] || !matrix[col][0]) {
                    matrix[col][row] = 0;
                }
            } 
            if (isColOneZero) {
                    matrix[col][0] = 0;
                }
        }
    }
};


