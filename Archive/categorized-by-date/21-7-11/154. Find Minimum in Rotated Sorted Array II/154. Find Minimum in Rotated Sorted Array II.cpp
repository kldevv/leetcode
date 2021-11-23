/*
Number: 154
Topic: Find Minimum in Rotated Sorted Array II
Date: 2021/7/11
Rate: Hard
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.

Constraints:
* n == nums.length
* 1 <= n <= 5000
* -5000 <= nums[i] <= 5000
* nums is sorted and rotated between 1 and n times.

Follow up: This problem is similar to Find Minimum in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?
-> The time complexity became O(n), becasue when the array is already sorted, we have to eliminate one element at the time and iterate every element until we got the first one.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            // 如果把 array 分成 [left, mid] 和 [right, mid] 兩個部分
            // case1: 如果 [right, mid] 沒有 sorted，代表最小值在 [mid+1, right] 中，我們排除 mid 因為 nums[mid] 已經比 nums[right] 大
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } 
            // case2: 如果 [left, mid] 和 [right, mid] 都 sorted 或是 left == mid 或 right == mid 就無法判斷，只能一個一個消去
            // 考慮 101111111 時，O(n)
            else if (nums[left] <= nums[mid]) { // given (nums[mid] <= nums[right]
                right -= 1;
            } 
            // case3: 如果 [left, mid] 沒有 sorted，代表最小值在 [left+1, mid] 中，我們排除 left 因為 nums[left] 已經比 nums[mid] 大
            else { // nums[left] > nums[mid]
                left += 1;
                right = mid;
            }
            // case4: 兩個都沒有 sorted，不可能
        }
        return nums[left];
    }
};