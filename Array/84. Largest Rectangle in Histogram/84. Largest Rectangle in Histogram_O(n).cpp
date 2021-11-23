/*
Number: 84
Topic: Largest Rectangle in Histogram_O(nlog(n))
Date: 2021/11/6
Rate: Hard
https://leetcode.com/problems/largest-rectangle-in-histogram/

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Constraints:
    * 1 <= heights.length <= 105
    * 0 <= heights[i] <= 104
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> candidates;
        candidates.push(-1);
        int n = heights.size();
        int maxArea = 0;
        heights.push_back(-1);

        for (int iter = 0; iter <= n; iter++) {
            while (candidates.top() != -1 && heights[candidates.top()] > heights[iter]) {
                int currentHeight = heights[candidates.top()];
                candidates.pop();

                int currentWidth = iter - candidates.top() - 1;

                maxArea = max(maxArea, currentWidth*currentHeight);
            }
            candidates.push(iter);
        }
        return maxArea;
    }
};
