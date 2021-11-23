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
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        // At each i-th index either we start a new subarray or we continue using the current subarray
        // currentSubArraySum = maxSubArraySum ends at (i-1)-th position

        int currentSubArraySum = 0;
        int maxSubArraySum = INT_MIN;
        for (int num : nums) {
            currentSubArraySum = max(currentSubArraySum + num, num);
            maxSubArraySum = max(maxSubArraySum, currentSubArraySum);
        }

        return maxSubArraySum;
    }
};