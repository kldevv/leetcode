/*
Number: 325
Topic: Maximum Size Subarray Sum Equals k
Date: 2021/7/17
Rate: Medium
https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/

Given an integer array nums and an integer k, return the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Constraints:
* 1 <= nums.length <= 2 * 105
* -104 <= nums[i] <= 104
* -109 <= k <= 109
*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> sumToIdx;

        int sums = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            sums += nums[i];
            if (sums == k)
                maxLen = max(maxLen, i+1);
            else if (sumToIdx.count(sums-k))
                maxLen = max(maxLen, i-sumToIdx[sums-k]);
            
            if (!sumToIdx.count(sums))
                sumToIdx[sums] = i;
        }
        return maxLen;
    }
};