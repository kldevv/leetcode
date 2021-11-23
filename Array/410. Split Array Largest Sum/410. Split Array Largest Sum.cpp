/*
Number: 410
Topic: Split Array Largest Sum
Date: 2021/9/8
Rate: Hard
https://leetcode.com/problems/split-array-largest-sum/

Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

Constraints:
    * 1 <= nums.length <= 1000
    * 0 <= nums[i] <= 106
    * 1 <= m <= min(50, nums.length)
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n < m)
            return -1;

        int lower_bound = INT_MIN;
        int upper_bound = 0;
        for (int i = 0; i < n; i++) {
            lower_bound = max(lower_bound, nums[i]);
            upper_bound += nums[i];
        }

        while (lower_bound < upper_bound) {
            int maxSum = lower_bound + (upper_bound-lower_bound)/2;
            int minSplit = getMinSplit(nums, maxSum);

            if (minSplit <= m)
                upper_bound = maxSum;
            else if (minSplit > m)
                lower_bound = maxSum + 1;
        }
        return upper_bound;
    }

    int getMinSplit(vector<int>& nums, int maxSum) {
        int n = nums.size();
        int minCut = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] <= maxSum) {
                sum += nums[i];
            }
            else {
                sum = nums[i];
                minCut += 1;
            }
        }
        return minCut + 1;
    }
};