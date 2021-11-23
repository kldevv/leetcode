/*
Number: 300
Topic: Longest Increasing Subsequence
Date: 2021/6/14
Rate: Medium
https://leetcode.com/problems/longest-increasing-subsequence/

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Constraints:
* 1 <= nums.length <= 2500
* -104 <= nums[i] <= 104


*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // tc: O(nlogN); sc: O(n) solution
        // # patience sort

        // dp[i] 代表 i 長度為 i 的最小元素 (代表我們可以用 dp[i] 拿到一個到目前為止結尾最小為 dp[i] 的 i 長度的 subsequence)
        vector<int> dp;
        for (const int& num : nums) {
            // 拿到一個數字後，看看 dp 裡面是否有比這數字小的（但大於 it - 1 的數字），如果有，就取代原本位置的元素，因為此時某 i 長度結尾最小的元素變成 num 了
            // 做 lower bound binary search
            auto it = lower_bound(dp.begin(), dp.end(), num);
            // 如果此時的 num 比每一個結尾都大，就增加長度
            if (it == dp.end())
                dp.push_back(num);
            // 如果此時的 num 可以更優化某一個結尾，就優化他
            else
                *it = num;
        }

        return dp.size();
    }

};