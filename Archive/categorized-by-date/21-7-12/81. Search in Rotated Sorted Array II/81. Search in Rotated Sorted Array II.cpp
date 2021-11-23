/*
Number: 81
Topic: Search in Rotated Sorted Array II
Date: 2021/7/12
Rate: Medium
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

Constraints:
* 1 <= nums.length <= 5000
* -104 <= nums[i] <= 104
* nums is guaranteed to be rotated at some pivot.
* -104 <= target <= 104
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            int val = nums[mid];

            if (val == target)
                return true;

            if (nums[left] < val) { // left part is sorted
                if (nums[left] <= target && target < val) // target in the left part
                    right = mid - 1;
                else // target not in the left part
                    left = mid + 1;
            }
            else if (nums[left] == val) { // Also, nums[right] == val, given val != target
                // extreme case like 1011111
                left += 1;
            }
            else { // right part is sorted
                if (nums[mid] < target && target <= nums[right]) // target in the right part
                    left = mid + 1;
                else // target in the left part
                    right = mid - 1;
            }
        }
        return false;
    }
};