/*
Number: 665
Topic: Non-decreasing Array
Date: 2021/9/13
Rate: Medium
https://leetcode.com/problems/non-decreasing-array/

Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

Constraints:
    * n == nums.length
    * 1 <= n <= 104
    * -105 <= nums[i] <= 105
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int firstTime = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] > nums[i]) {
                if (firstTime) {
                    firstTime = 0;
                    if (i > 1 && nums[i-2] > nums[i])
                        nums[i] = nums[i-1];
                }
                else
                    return false;
            }
        }
        return true;
    }
};