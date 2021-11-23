/*
Number: 503
Topic: Next Greater Element II
Date: 2021/8/3
Rate: Medium
https://leetcode.com/problems/next-greater-element-ii/

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Constraints:
* 1 <= nums.length <= 104
* -109 <= nums[i] <= 109
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> out(n, -1);

        stack<int> toFill;
        for (int i = 0; i < 2*n; i++) {
            while (toFill.size() && nums[toFill.top()] < nums[i % n]) {
                out[toFill.top()] = nums[i % n];
                toFill.pop();
            }
            if (i < n)
                toFill.push(i);
        }
        return out;
    }
};