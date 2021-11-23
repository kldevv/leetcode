/*
Number: 48
Topic: Rotate Image
Date: 2021/5/8
Rate: Medium
https://leetcode.com/problems/rotate-image/

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Constraints:
* matrix.length == n
* matrix[i].length == n
* 1 <= n <= 20
* -1000 <= matrix[i][j] <= 1000


O(n^2) where n is the side length of the square.
or O(m) where m is the number of cells in the square.

A rotated square is equal to a transposed + reversed square
*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size()-1; i++) {
            for (int n = i+1; n < matrix[i].size(); n++){
                swap(matrix[i][n], matrix[n][i]);
            }
        }
        for (vector<int> &a : matrix){
            reverse(a.begin(), a.end());
        }
        
    }
};