/*
Number: 718
Topic: Maximum Length of Repeated Subarray_O((m+n) * min(m, n) = mn)_O(1)
Date: 2021/11/7
Rate: Medium
https://leetcode.com/problems/maximum-length-of-repeated-subarray/submissions/

Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

Constraints:
    * 1 <= nums1.length, nums2.length <= 1000
    * 0 <= nums1[i], nums2[i] <= 100
*/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int maxLen = 0;
        for (int shift = 1; shift < m + n - 1; shift++) {
            int startOne = max(m-1-shift, 0);
            int startTwo = min(max(shift-(m-1), 0), n-1);
            int repeatedLen = 0;
            for (; startOne < m && startTwo < n; startOne++, startTwo++) {
                repeatedLen = (nums1[startOne] == nums2[startTwo]) ? repeatedLen + 1 : 0;
                maxLen = max(maxLen, repeatedLen);
            }
        }
        return maxLen;
    }
};