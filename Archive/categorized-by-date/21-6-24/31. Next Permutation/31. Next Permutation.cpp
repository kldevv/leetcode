/*
Number: 91
Topic: Decode Ways
Date: 2021/6/24
Rate: Medium
https://leetcode.com/problems/decode-ways/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Constraints:
* 1 <= s.length <= 100
* s contains only digits and may contain leading zero(s).
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        for (; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                break;
            }
        }

        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int k = n-1; k > i; k--) {
            if (nums[k] > nums[i]) {
                swap(nums[k], nums[i]);
                break;
            }
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};