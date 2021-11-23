/*
Number: 34
Topic: Find First and Last Position of Element in Sorted Array
Date: 2021/5/6
Rate: Medium
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

Constraints:
* 0 <= nums.length <= 105
* -109 <= nums[i] <= 109
* nums is a non-decreasing array.
* -109 <= target <= 109


tc / Olog(n)
*/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        vector<int> out = {-1, -1};
        // 空的就直接回傳
        if (nums.empty()) return out;

        // 做一次 binary search，找到左邊的點
        while (l <= r){
            int m = l + (r-l)/2;
            // 第一個 element 或是 比左邊那個大(或不一樣)
            bool left_condition = (m == 0) ? true : (nums[m-1] < target);
            if ((nums[m] == target) && left_condition){
                out[0] = m;
                break;
            } else if (nums[m] < target) {
                l = m + 1;
            // 只是把 target 大或是 和 target 一樣但不是第一個 target e.g. [1, 1, 1] 找到第二個 1，就往左邊找
            } else {
                r = m - 1;
            }
        }

        l = 0, r = nums.size() - 1;
        while (l <= r){
            int m = l + (r-l)/2;
            // 最後一個 element 或是 比右邊那個小(或不一樣)
            bool right_condition = (m == nums.size() - 1) ? true : (nums[m+1] > target);
            if ((nums[m] == target) && right_condition){
                out[1] = m;
                break;
            } else if (nums[m] > target) {
                r = m - 1;
            // 只是把 target 小或是 和 target 一樣但不是最後一個 target e.g. [1, 1, 1] 找到第二個 1，就往右邊找
            } else {
                l = m + 1;
            }
        }
        return out;

    }
};