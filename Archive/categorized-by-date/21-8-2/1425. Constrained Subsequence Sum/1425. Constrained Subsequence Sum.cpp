/*
Number: 1425
Topic: Constrained Subsequence Sum
Date: 2021/8/2
Rate: Hard
https://leetcode.com/problems/constrained-subsequence-sum/

Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.

Constraints:
* 1 <= k <= nums.length <= 105
* -104 <= nums[i] <= 104
*/

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<pair<int, int>> maxSum; // lastIdx, sum
        int out = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            while (maxSum.size() && (i-maxSum.front().first) > k)
                maxSum.pop_front();

            int curSum = nums[i] + ((maxSum.size() && maxSum.front().second > 0) ? maxSum.front().second : 0);
            out = max(out, curSum);

            while (maxSum.size() && maxSum.back().second <= curSum)
                maxSum.pop_back();

            maxSum.emplace_back(i, curSum);
        }
        return out;
    }
};