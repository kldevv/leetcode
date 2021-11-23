/*
Number: 209
Topic: Minimum Size Subarray Sum
Date: 2021/5/13
Rate: Medium
https://leetcode.com/problems/minimum-size-subarray-sum/

Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Constraints:
* 1 <= target <= 109
* 1 <= nums.length <= 105
* 1 <= nums[i] <= 105

tc: O(n) 因為 head 跟 tail 都只 loop over 一次 array
*/

class Solution {
public:
    // 用兩個 pointer
    int minSubArrayLen(int target, vector<int>& nums) {
        double sum = 0;
        int head = 0, tail = 0;
        int max_count = INT_MAX;
        bool exist = false;
        for (int i = 0; i < nums.size(); i++) {
            // 尾巴不斷前進
            sum += nums[i];
            tail = i;
            // 如果滿足條件，就開始縮減頭，直到不再滿足
            while (sum >= target) {
                // 紀錄最佳值
                max_count = min(max_count, tail-head+1);
                exist = true;
                sum -= nums[head++];
            }
        }

        return (exist) ? max_count : 0;
    }
};