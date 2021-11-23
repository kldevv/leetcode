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
        int maxArea = 0;
        largestRectangleArea(heights, 0, heights.size(), maxArea);
        return maxArea;
    }

    void largestRectangleArea(vector<int>& heights, int start, int end, int& maxArea) {
        // start inclusive, end exclusive
        if (start >= end)
            return;

        int minHeight = INT_MAX;
        int minHeightIdx = -1;
        for (int iter = start; iter < end; iter++) {
            if (minHeight > heights[iter]) {
                minHeight = heights[iter];
                minHeightIdx = iter;
            }
        }
        maxArea = max(maxArea, minHeight*(end-start));
        largestRectangleArea(heights, start, minHeightIdx, maxArea);
        largestRectangleArea(heights, minHeightIdx+1, end, maxArea);
    }
};
