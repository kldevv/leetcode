/*
Number: 268
Topic: Missing Number
Date: 2021/7/2
Rate: Easy
https://leetcode.com/problems/missing-number/

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

Constraints:
* n == nums.length
* 1 <= n <= 104
* 0 <= nums[i] <= n
* All the numbers of nums are unique.

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // 把 0~n 的加總減掉 nums 的加總
        return (n*(n+1) / 2) - accumulate(nums.begin(), nums.end(), 0);
    }
};