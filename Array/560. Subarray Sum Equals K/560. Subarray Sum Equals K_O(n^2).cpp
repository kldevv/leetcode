/*
Number: 560
Topic: Subarray Sum Equals K_O(n^2)
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
        int n = nums.size();
        int count = 0;
        for (int start = 0; start < n; start++) {
            int currentSum = 0;
            for (int end = start; end < n; end++) {
                currentSum += nums[end];
                if (currentSum == k)
                    count += 1;
            }
        }
        return count;
    }
};