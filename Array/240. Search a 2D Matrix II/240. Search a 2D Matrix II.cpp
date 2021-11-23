/*
Number: 240
Topic: Search a 2D Matrix II
Date: 2021/11/15
Rate: Hard
https://leetcode.com/problems/search-a-2d-matrix-ii/

Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:
    * Integers in each row are sorted in ascending from left to right.
    * Integers in each column are sorted in ascending from top to bottom.

Constraints:
    * m == matrix.length
    * n == matrix[i].length
    * 1 <= n, m <= 300
    * -109 <= matrix[i][j] <= 109
    * All the integers in each row are sorted in ascending order.
    * All the integers in each column are sorted in ascending order.
    * -109 <= target <= 109
*/

#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // search from left-bottom

        // If the current search value is too small, move the search val to the right: every element above the original value is also smaller
        // element above < searchVal < target

        // If the current search value is too large, move the search val to the upper: every element to the right of the original value is also too large, and the elements in the area blow are also too large
        // element below & right > searchVal > target
        if (matrix.empty() || matrix[0].empty())
            return false;

        int m = matrix.size();
        int n = matrix[0].size();

        int searchRow = m - 1;
        int searchCol = 0;

        while (searchRow >= 0 && searchCol < n) {
            int val = matrix[searchRow][searchCol];
            if (val == target) {
                return true;
            } else if (val < target) {
                searchCol += 1;
            } else {  // val > target
                searchRow -= 1;
            }
        }
        return false;
    }
};