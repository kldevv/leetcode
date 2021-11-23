/*
Number: 1991
Topic: Find the Middle Index in Array
Date: 2021/11/2
Rate: Easy
https://leetcode.com/problems/find-the-middle-index-in-array/

Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest amongst all the possible ones).

A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1].

If middleIndex == 0, the left side sum is considered to be 0. Similarly, if middleIndex == nums.length - 1, the right side sum is considered to be 0.

Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.

Constraints:
    * 1 <= nums.length <= 100
    * -1000 <= nums[i] <= 1000
*/

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n+1, 0);

        for (int i = 0; i < n; i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            if (prefixSum[i] == (prefixSum[n] - prefixSum[i+1]))
                return i;
        }
        return -1;        
    }
};