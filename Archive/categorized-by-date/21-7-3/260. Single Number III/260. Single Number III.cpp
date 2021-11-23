/*
Number: 137
Topic: Single Number II
Date: 2021/7/3
Rate: Medium
https://leetcode.com/problems/single-number-ii/

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Constraints:
* 1 <= nums.length <= 3 * 104
* -231 <= nums[i] <= 231 - 1
* Each element in nums appears exactly three times except for one element which appears once.
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int mix = 0;

        for (const int& num : nums) {
            mix ^= num;
        }

        int identifier = (mix != INT_MIN) ? mix & (-mix) : 1;

        vector<int> out(2, 0);
        for (const int& num : nums) {
            if (num & identifier)
                out[0] ^= num;
            else
                out[1] ^= num;
        }
        return out;
    }
};