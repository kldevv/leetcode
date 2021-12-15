/*
Number: 42
Topic: Trapping Rain Water - Brute Force
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

        Brute Force:
            For each bar: O(n)
                Find maxLeft; O(n)
                Find maxRight; O(n)
                Calculate the amount = min(maxRight, maxLeft) - currentHeight
                Add amount to the result;

        %%%%%%%%%%%%%%%
        Complexity:
            n = height.size()
            T(n) = O(n^2)
            S(n) = S(1)
        */
        int n = height.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            int current = height[i];

            int maxLeft = current;
            for (int j = i - 1; j >= 0; j--) {
                maxLeft = max(maxLeft, height[j]);
            }

            int maxRight = current;
            for (int k = i + 1; k < n; k++) {
                maxRight = max(maxRight, height[k]);
            }

            result += (min(maxRight, maxLeft) - current);
        }
        return result;
    }
};