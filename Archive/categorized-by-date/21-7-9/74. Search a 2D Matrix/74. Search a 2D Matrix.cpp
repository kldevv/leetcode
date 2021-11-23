/*
Number: 74
Topic: Search a 2D Matrix
Date: 2021/7/9
Rate: Medium
https://leetcode.com/problems/search-a-2d-matrix/

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
        int n = (m) ? matrix[0].size() : 0;
        // edge case
        if (target < matrix[0][0] || target > matrix[m-1][n-1])
            return false;

        int low = 0;
        int high = m - 1;

        while (low <= high) {
            int mid = low + (high-low)/2;
            // 先先看在哪一個 row，再對那個 row 做 binary search
            if (matrix[mid][0] <= target && matrix[mid][n - 1] >= target)
                return binarySearch(matrix[mid], target);
            if (matrix[mid][0] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }

    int binarySearch(const vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};
