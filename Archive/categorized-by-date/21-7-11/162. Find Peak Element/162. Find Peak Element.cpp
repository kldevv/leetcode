/*
Number: 162
Topic: Find Peak Element
Date: 2021/7/11
Rate: Medium
https://leetcode.com/problems/find-peak-element/

A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.

Constraints:
* 1 <= nums.length <= 1000
* -231 <= nums[i] <= 231 - 1
* nums[i] != nums[i + 1] for all valid i.

*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // edge case
        int left = 0, right = n-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            int val = nums[mid];

            if (val < nums[mid+1])
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};