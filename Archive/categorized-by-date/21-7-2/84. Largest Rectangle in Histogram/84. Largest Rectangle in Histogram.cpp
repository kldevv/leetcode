/*
Number: 84
Topic: Largest Rectangle in Histogram
Date: 2021/7/2
Rate: Hard
https://leetcode.com/problems/largest-rectangle-in-histogram/

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Constraints:
* 1 <= heights.length <= 10^5
* 0 <= heights[i] <= 10^4

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // see post: https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28905/My-concise-C%2B%2B-solution-AC-90-ms
        // 要形成一個 rectangle 要先知道他的 leftBound 和 rightBound
        // iterate through rightBound，把 leftBound 存在 stack 裡
        // 如果 stack 最上面的 value 大於 目前的 rightBound 代表可以找到一個以這個 value 當高的 rectangle
        // 他的 leftBound 就是 stack 裡到下一個值，因為 stack 會是一個 non-decreasing 的數列
        // 所以比他大的都被 pop 掉了，如果 stack 是空的，代表他前面的值都比他還大，所以直接從 -1 開始，他的 leftBound 就是最左邊
        stack<int> indexes;
        int n = heights.size();
        int height = 0;
        int leftBound = 0;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            while (i == n || (!indexes.empty() && heights[indexes.top()] > heights[i])) {
                if (i == n && indexes.empty()) {
                    height = 0;
                    i++;
                }
                else {
                    height = heights[indexes.top()];
                    indexes.pop();
                }
                leftBound = indexes.empty() ? -1 : indexes.top();
                maxArea = max(maxArea, height * (i-leftBound-1));
            }
            indexes.push(i);
        }
        return maxArea;
    }
};