/*
Number: 213
Topic: House Robber II
Date: 2021/6/24
Rate: Medium
https://leetcode.com/problems/house-robber/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Constraints:
* 1 <= nums.length <= 100
* 0 <= nums[i] <= 1000

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return (nums.size() == 1) ? nums[0] : max(rob(nums, 0, n-1), rob(nums, 1, n));
    }

    int rob(vector<int>& nums, int start, int end) {
        int cur = 0, pre = 0;
        for (int i = start; i < end; i++) {
            int temp = max(cur, pre+nums[i]);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
