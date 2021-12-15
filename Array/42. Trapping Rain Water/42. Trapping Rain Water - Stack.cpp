/*
Number: 42
Topic: Trapping Rain Water - Two Pointers
Date: 2021/12/2
Rate: Hard
https://leetcode.com/problems/trapping-rain-water/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Constraints:
    * n == height.length
    * 1 <= n <= 2 * 104
    * 0 <= height[i] <= 105
*/

#include <stack>
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
            >> The amount of water is only directly related to the lower end (right or left)
        Actions:

            Start from 2 ends; [left] [right]

            while [left] < [right]: > stop at one of the highest bars
                If [left] < [right]:
                    leftMax = max(leftMax, [left])
                        [right] >= leftMax => [left]
                            Because we always move the lower end
                            If leftMax > right, the right would have been moved before leftMax be recorded
                            Right is bigger than all the bar to the left of [left].
                    result += (leftMax - left)
                    left += 1
                If [left] > [right]:
                    vice versa
        %%%%%%%%%%%%%%%
        Complexity:
            n = height.size()
            T(n) = O(n)
            S(n) = S(1)
        */
        int maxLeft = 0;
        int maxRight = 0;
        int left = 0;
        int right = height.size() - 1;

        int result = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                maxLeft = max(maxLeft, height[left]);
                result += (maxLeft - height[left]);
                left += 1;
            } else {  // left > right
                maxRight = max(maxRight, height[right]);
                result += (maxRight - height[right]);
                right -= 1;
            }
        }
        return result;
    }
};