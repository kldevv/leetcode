/*
Number: 718
Topic: Maximum Length of Repeated Subarray_O(mn)_O(min(m, n))
Date: 2021/11/7
Rate: Medium
https://leetcode.com/problems/maximum-length-of-repeated-subarray/

Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

Constraints:
    * 1 <= nums1.length, nums2.length <= 1000
    * 0 <= nums1[i], nums2[i] <= 100
*/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size())
            return findLength(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();
        int maxLen = 0;
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[j][i % 2] = (nums1[i-1] == nums2[j-1]) ? dp[j-1][(i + 1) % 2] + 1 : 0;
                maxLen = max(dp[j][i % 2], maxLen);
            }
        }
        return maxLen;
    }
};