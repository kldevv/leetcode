/*
Number: 34
Topic: Find First and Last Position of Element in Sorted Array
Date: 2021/7/11
Rate: Medium
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Constraints:
* 0 <= nums.length <= 105
* -109 <= nums[i] <= 109
* nums is a non-decreasing array.
* -109 <= target <= 109
 
Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int num1 = findLeftBound(nums, target);
        int num2 = findRightBound(nums, target);
        return {num1, num2};
    }

    int findLeftBound(const vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            int val = nums[mid];
            
            if (val == target && (mid == 0 || nums[mid-1] != target))
                return mid;
            if (val < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int findRightBound(const vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            int val = nums[mid];

            if (val == target && (mid == n-1 || nums[mid+1] != target))
                return mid;
            if (val <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;        
    }
};