/*
Number: 85
Topic: Maximal Rectangle_O(m*n)
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
        
        vector<int> heights(n+1, 0);
        heights[n] = -1;

        int maxArea = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == '1') {
                    heights[col] = 1 + ((row > 0) ? heights[col] : 0);
                } else {
                    heights[col] = 0;
                }
                // cout << heights[col] << " ";
            }
            // cout << endl;
            maxArea = max(maxArea, maximalRectangle(heights));
        }
        return maxArea;
    }

    int maximalRectangle(vector<int>& heights) {
        stack<int> candidates;
        candidates.push(-1);

        int maxArea = 0;
        for (int iter = 0; iter < heights.size(); iter++) {
            while (candidates.top() != -1 && heights[candidates.top()] > heights[iter]) {
                int currentHeight = heights[candidates.top()];
                candidates.pop();

                int currentWidth = iter - candidates.top() - 1;

                maxArea = max(maxArea, currentHeight * currentWidth);
            }
            candidates.push(iter);
        }
        return maxArea;
    }
};

