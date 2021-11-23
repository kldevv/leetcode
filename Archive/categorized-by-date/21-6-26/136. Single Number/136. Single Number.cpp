/*
Number: 136
Topic: Single Number
Date: 2021/6/26
Rate: Easy
https://leetcode.com/problems/single-number/

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Constraints:
* 1 <= nums.length <= 3 * 104
* -3 * 104 <= nums[i] <= 3 * 104
* Each element in the array appears twice except for one element which appears only once.

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int out = 0;
        for (const int& n : nums) {
            out ^= n;
        }
        return out;
    }
};