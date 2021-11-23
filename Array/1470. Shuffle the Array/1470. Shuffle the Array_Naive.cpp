/*
Number: 1470
Topic: Shuffle the Array
Date: 2021/9/8
Rate: Easy
https://leetcode.com/problems/shuffle-the-array/

Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].

Constraints:
    * 1 <= n <= 500
    * nums.length == 2n
    * 1 <= nums[i] <= 10^3

*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(nums[i]);
            result.push_back(nums[i+n]);
        }
        return result;
    }
};