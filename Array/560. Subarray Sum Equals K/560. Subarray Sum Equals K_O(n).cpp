/*
Number: 560
Topic: Subarray Sum Equals K_O(n)
Date: 2021/11/5
Rate: Medium
https://leetcode.com/problems/subarray-sum-equals-k/

Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

Constraints:
    * 1 <= nums.length <= 2 * 104
    * -1000 <= nums[i] <= 1000
    * -107 <= k <= 107
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prevSum;
        int curSum = 0;
        int count = 0;
        prevSum[0] = 1;
        for (int num : nums) {
            curSum += num;
            count += prevSum[curSum-k];
            prevSum[curSum] += 1;
        }
        return count;
    }
};