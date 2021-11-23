/*
Number: 862
Topic: Shortest Subarray with Sum at Least K
Date: 2021/8/3
Rate: Hard
https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

Constraints:
* 1 <= nums.length <= 105
* -105 <= nums[i] <= 105
* 1 <= k <= 109
*/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefixSum(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        deque<int> toCompare;
        int minLen = n+1;
        for (int j = 0; j <= n; j++) {
            while (toCompare.size() && prefixSum[j]-prefixSum[toCompare.front()] >= k) {
                minLen = min(minLen, j-toCompare.front());
                toCompare.pop_front();
            }
            while (toCompare.size() && prefixSum[j] <= prefixSum[toCompare.back()])
                toCompare.pop_back();
            toCompare.push_back(j);
        }

        return (minLen == n+1) ? -1 : minLen;
    }
};