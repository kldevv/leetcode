/*
Number: 85
Topic: Maximal Rectangle_O(m^2*n)
Date: 2021/11/6
Rate: Hard
https://leetcode.com/problems/maximal-rectangle/

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Constraints:
    * rows == matrix.length
    * cols == matrix[i].length
    * 0 <= row, cols <= 200
    * matrix[i][j] is '0' or '1'.
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = (m) ? matrix[0].size() : 0;
        vector<vector<int>> consecutiveOne(m, vector<int>(n, 0));

        int maxArea = 0;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == '1') {
                    consecutiveOne[row][col] = (col > 0) ? consecutiveOne[row][col-1] + 1 : 1;

                    int currentWidth = INT_MAX;
                    int currentHeight;
                    for (int rRow = row; rRow >= 0; rRow--) {
                        currentWidth = min(currentWidth, consecutiveOne[rRow][col]);
                        currentHeight = row - rRow + 1;
                        maxArea = max(maxArea, currentWidth*currentHeight);
                    } 
                }
            }
        }
        return maxArea;
    }
};