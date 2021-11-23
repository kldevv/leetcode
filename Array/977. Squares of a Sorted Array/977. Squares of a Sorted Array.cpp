/*
Number: 977
Topic: Squares of a Sorted Array
Date: 2021/9/8
Rate: Easy
https://leetcode.com/problems/squares-of-a-sorted-array/

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Cosntriants:
    * 1 <= nums.length <= 104
    * -104 <= nums[i] <= 104
    * nums is sorted in non-decreasing order.
 

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        int i = 0, j = n-1;
        for (int t = n-1; t >= 0; t--) {
            if (abs(nums[i]) >= abs(nums[j])) {
                result[t] = nums[i] * nums[i];
                i += 1;
            }
            else if (abs(nums[i]) < abs(nums[j])) {
                result[t] = nums[j] * nums[j];
                j -= 1;
            }
        }
        return result;
    }
};