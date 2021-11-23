/*
Number: 48
Topic: Rotate Image
Date: 2021/7/7
Rate: Medium
https://leetcode.com/problems/rotate-image/

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.


Constraints:
* matrix.length == n
* matrix[i].length == n
* 1 <= n <= 20
* -1000 <= matrix[i][j] <= 1000

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);

        int m = matrix.size();
        for (int i = 0; i < m; i++) {
            reverse(matrix[i]);
        }
    }

    void reverse(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        while (i < j) {
            swap(nums[i++], nums[j--]);
        }
    }

    void transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = (m) ? matrix[0].size() : 0;

        for (int i = 0; i < m; i++) {
            for (int j = i+1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};