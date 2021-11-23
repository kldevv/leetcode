/*
Number: 240
Topic: Search a 2D Matrix II
Date: 2021/7/9
Rate: Medium
https://leetcode.com/problems/search-a-2d-matrix-ii/

Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

* Integers in each row are sorted in ascending from left to right.
* Integers in each column are sorted in ascending from top to bottom.

Constraints:
* m == matrix.length
* n == matrix[i].length
* 1 <= n, m <= 300
* -109 <= matix[i][j] <= 109
* All the integers in each row are sorted in ascending order.
* All the integers in each column are sorted in ascending order.
* -109 <= target <= 109
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = (m) ? matrix[0].size() : 0;

        if (!m || !n)
            return false;

        int r = 0;
        int c = n - 1;

        // time complexity O(m + n)
        // 搜尋右上角的元素，如果那個元素比我們的 target 大，代表那一列以下的元素都更大，我們可以縮減一排
        // 如果那個元素比我們的 target 小，代表代表那一個 row 的元素都比較小，可以捨去那一個 row
        while (r < m && c >= 0) {
            if (matrix[r][c] == target)
                return true;
            else
                (matrix[r][c] > target) ? c-- : r++;
        }
        return false;
    }
};