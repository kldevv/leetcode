/*
Number: 74
Topic: Search a 2D Matrix
Date: 2021/5/11
Rate: Medium
https://leetcode.com/problems/search-a-2d-matrix/

Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.

Constraints:
* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 100
* -104 <= matrix[i][j], target <= 104


*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        // 如果 target 超出範圍，直接回傳 false
        if ((target < matrix[0][0]) || (target > matrix[m-1][n-1]))
            return false;
        // 對每一個排的第一個元素做 binary search
        int left = 0, right = m-1;
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (matrix[mid][0] == target) 
                return true;
            else if (matrix[mid][0] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        // 找到有可能的那一個 row
        // 再對那一個 row 做 binary search
        int col = right;
        left = 0, right = n-1;
        if (target > matrix[col][right]) 
            return false;

        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (matrix[col][mid] == target) 
                return true;
            else if (matrix[col][mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return false;
    }
};

// 下面的解法把 matrix 換成 array，雖然 tc 一樣，但是想法很有趣，故紀錄。

/*

treat it as an array
n * m matrix convert to an array => matrix[x][y] => a[x * m + y]

an array convert to n * m matrix => a[x] =>matrix[x / m][x % m];


class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l != r){
            int mid = (l + r - 1) >> 1;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else 
                r = mid;
        }
        return matrix[r / m][r % m] == target;
    }
};

*/

