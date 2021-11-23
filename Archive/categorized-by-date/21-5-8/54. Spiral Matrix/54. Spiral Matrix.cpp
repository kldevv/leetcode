/*
Number: 53
Topic: Maximum Subarray
Date: 2021/5/8
Rate: Easy
https://leetcode.com/problems/maximum-subarray/

Given an m x n matrix, return all elements of the matrix in spiral order.

Constraints:
* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 10
* -100 <= matrix[i][j] <= 100

O(n)
O(1)
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int temp = 0;
        int length = matrix[0].size(), high = matrix.size();
        vector<int> out;
        // 最簡單的想法就是從左到右，從上到，不斷往內縮
        // 另一個更 clever 的想法：每次都拿最上面那層，pop掉，然後anticlockwise rotate matrix，直到全部都被pop掉
        // https://leetcode.com/problems/spiral-matrix/discuss/20571/1-liner-in-Python-%2B-Ruby

        while (out.size() < length*high) {
            for (int i = temp; (i < length-temp) && (out.size()<length*high); i++) {
                out.push_back(matrix[temp][i]);
            }
            for (int n = temp+1; (n < high-1-temp) && (out.size()<length*high); n++) {
                out.push_back(matrix[n][length-1-temp]);
            }
            for (int x = length-1-temp; (x > temp) && (out.size()<length*high); x--) {
                out.push_back(matrix[high-1-temp][x]);
            }
            for (int y = high-temp-1; (y > temp) && (out.size()<length*high); y--) {
                out.push_back(matrix[y][temp]);
            }
            temp++;
        }
        return out;
    }
};