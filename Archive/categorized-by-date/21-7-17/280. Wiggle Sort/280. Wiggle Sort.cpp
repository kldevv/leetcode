/*
Number: 280
Topic: Wiggle Sort
Date: 2021/7/17
Rate: Medium
https://leetcode.com/problems/wiggle-sort/

Given an integer array nums, reorder it such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

You may assume the input array always has a valid answer.

Constraints:
* 1 <= nums.length <= 5 * 104
* 0 <= nums[i] <= 104
* It is guaranteed that there will be an answer for the given input nums.
 

Follow up: Could you do it without sorting the array?
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        /*
        The final sorted nums needs to satisfy two conditions:

        If i is odd, then nums[i] >= nums[i - 1];
        If i is even, then nums[i] <= nums[i - 1].
        The code is just to fix the orderings of nums that do not satisfy 1 and 2.
        */
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (i%2 == (nums[i] < nums[i-1]))
                swap(nums[i], nums[i-1]);
        }
    }
};