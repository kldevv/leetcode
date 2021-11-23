/*
Number: 930
Topic: Binary Subarrays With Sum
Date: 2021/8/4
Rate: Medium
https://leetcode.com/problems/binary-subarrays-with-sum/

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

Constraints:
* 1 <= nums.length <= 3 * 104
* nums[i] is either 0 or 1.
* 0 <= goal <= nums.length
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMostK(nums, goal) - atMostK(nums, goal-1);
    }

    int atMostK(const vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int out = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i])
                goal -= 1;
            while (goal < 0) {
                if (nums[j++])
                    goal += 1;
            }
            out += i - j + 1;
        }
        return out;
    }
};