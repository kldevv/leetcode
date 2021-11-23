/*
Number: 53
Topic: Maximum Subarray
Date: 2021/11/15
Rate: Easy
https://leetcode.com/problems/maximum-subarray/

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

Constraints:
    * 1 <= nums.length <= 105
    * -104 <= nums[i] <= 104
    * 
Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        return maxSubArray(nums, 0, n - 1);
    }

    int maxSubArray(vector<int>& nums, int start, int end) {
        if (start > end)
            return INT_MIN;

        int mid = start + (end - start) / 2;

        int bestSubArraySumLeft = 0;
        int currentSubArraySumLeft = 0;
        for (int i = mid - 1; i >= 0; i--) {
            currentSubArraySumLeft += nums[i];
            bestSubArraySumLeft = max(bestSubArraySumLeft, currentSubArraySumLeft);
        }

        int bestSubArraySumRight = 0;
        int currentSubArraySumRight = 0;
        for (int j = mid + 1; j < end; j++) {
            currentSubArraySumRight += nums[j];
            bestSubArraySumRight = max(bestSubArraySumRight, currentSubArraySumRight);
        }
        int maxSubArraySumWithMid = bestSubArraySumLeft + nums[mid] + bestSubArraySumRight;
        int maxSubArraySumLeft = maxSubArray(nums, start, mid - 1);
        int maxSubArraySumRight = maxSubArray(nums, mid + 1, end);

        return max(maxSubArraySumWithMid, max(maxSubArraySumLeft, maxSubArraySumRight));
    }
};