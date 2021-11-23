/*
Number: 88
Topic: Merge Sorted Array
Date: 2021/5/22
Rate: Easy
https://leetcode.com/problems/merge-sorted-array/

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume that nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.

Constraints:

* nums1.length == m + n
* nums2.length == n
* 0 <= m, n <= 200
* 1 <= m + n <= 200
* -109 <= nums1[i], nums2[i] <= 109

Follow up: Can you come up with an algorithm that runs in O(m + n) time?
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int z = m + n - 1;
        int a = m - 1;
        int b = n - 1;
        while (a >= 0 && b >= 0) {
            nums1[z--] = ((a < 0) || (nums1[a] < nums2[b])) ? nums2[b--] : nums1[a--];
        }
        while (b >= 0) {
            nums1[z--] = nums2[b--];
        }
    }
};