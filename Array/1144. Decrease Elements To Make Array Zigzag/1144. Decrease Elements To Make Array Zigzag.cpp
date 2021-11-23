/*
Number: 1144
Topic: Decrease Elements To Make Array Zigzag
Date: 2021/9/14
Rate: Medium
https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/

Given an array nums of integers, a move consists of choosing any element and decreasing it by 1.

An array A is a zigzag array if either:
    * Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
    * OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...
Return the minimum number of moves to transform the given array nums into a zigzag array.

Constraints:
    * 1 <= nums.length <= 1000
    * 1 <= nums[i] <= 1000
*/

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        int results[2] = {0, 0};
        for (int i = 0; i < n; i++) {
            int leftVal = (i > 0) ? nums[i-1] : INT_MAX;
            int rightVal = (i < n-1) ? nums[i+1] : INT_MAX;

            results[i%2] += max(0, nums[i]-min(leftVal, rightVal)+1);
        }
        return min(results[0], results[1]);
    }
};