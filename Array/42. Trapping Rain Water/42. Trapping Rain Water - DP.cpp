/*
Number: 42
Topic: Trapping Rain Water - Dynamic Programming
Date: 2021/12/2
Rate: Hard
https://leetcode.com/problems/trapping-rain-water/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Constraints:
    * n == height.length
    * 1 <= n <= 2 * 104
    * 0 <= height[i] <= 105
*/

#include <vector>

using namespace std;

class Solution {
   public:
    int trap(vector<int>& height) {
        /*
        Example:
        [0,1,0,2,1,0,1,3,2,1,2,1]
        Ans:
        6

        Observe Patterns:
            The water in the current bar is trapped by the amount of min(maxRight, maxLeft) - currentHeight


        O(n)
        Find maxLeft and maxRight for each idx;

        For each bar: O(n)
            Find maxLeft; > Dynamic Programming with one pass
            Find maxRight; > Dynamic Programming with one pass
            Calculate the amount = min(maxRight, maxLeft) - currentHeight
            Add amount to the result;

        %%%%%%%%%%%%%%%
        Complexity:
            n = height.size()
            T(n) = O(n)
            S(n) = S(n)
        */
        int n = height.size();

        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i - 1]);
            maxRight[n - 1 - i] = max(maxRight[n - 1 - i + 1], height[n - 1 - i + 1]);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            result += max(min(maxLeft[i], maxRight[i]) - height[i], 0);
        }
        return result;
    }
};