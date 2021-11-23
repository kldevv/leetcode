/*
Number: 287
Topic: Find the Duplicate Number
Date: 2021/7/8
Rate: Medium
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Constraints:
* 1 <= n <= 105
* nums.length == n + 1
* 1 <= nums[i] <= n
* All the integers in nums appear only once except for precisely one integer which appears two or more times.

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size()-1;
        while (low < high) {
            int mid = low + (high-low)/2;
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) count++;
            }
            if (count <= mid)
                low = mid+1;
            else
                high = mid;
        }

        return low;
    }
};