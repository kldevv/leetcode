/*
Number: 454
Topic: 4Sum II
Date: 2021/9/23
Rate: Medium
https://leetcode.com/problems/4sum-ii/

Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

    * 0 <= i, j, k, l < n
    * nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

Constraints:
    * n == nums1.length
    * n == nums2.length
    * n == nums3.length
    * n == nums4.length
    * 1 <= n <= 200
    * -2^28 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2^28
*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> counter;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                counter[nums1[i]+nums2[j]] += 1;
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int target = 0 - (nums3[i] + nums4[j]);
                result += counter[target];
            }
        }
        return result;
    }
};



