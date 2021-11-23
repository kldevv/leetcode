/*
Number: 53
Topic: Maximum Subarray
Date: 2021/5/8
Rate: Easy
https://leetcode.com/problems/maximum-subarray/

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Constraints:
* 1 <= nums.length <= 3 * 10^4
* -10^5 <= nums[i] <= 10^5

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

dynamic programing!!

O(n)
O(1) in-place dynamic programming
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            // nums[i] 代表到 idx=i 時最佳的解，nums[i] 會等於 nums[i-1]（到前一個時的最佳解）+ nums[i]（延長前一個最佳解），或是等於 nums[i]（從這邊開始）
            // 因為 i 期只和 i - 1 有關，甚至可以壓縮成 temp，一個 variable 就可以了
            nums[i] = max(nums[i-1] + nums[i], nums[i]);
            best = max(best, nums[i]);
        }
        return best;
    }
};