/*
Number: 1043
Topic: Partition Array for Maximum Sum
Date: 2021/9/6
Rate: Medium
https://leetcode.com/problems/partition-array-for-maximum-sum/

Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

Constraints:
    * 1 <= arr.length <= 500
    * 0 <= arr[i] <= 109
    * 1 <= k <= arr.length
*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> maxSumDP(n+1, 0);
        for (int i = 1; i <= n; i++) {
            int maxVal = 0;
            for (int kk = 1; kk <= k && i - kk >= 0; kk++) {
                maxVal = max(maxVal, arr[i-kk]);
                maxSumDP[i] = max(maxSumDP[i], maxSumDP[i-kk]+maxVal*kk);
            }
        }
        return maxSumDP[n];
    }
};