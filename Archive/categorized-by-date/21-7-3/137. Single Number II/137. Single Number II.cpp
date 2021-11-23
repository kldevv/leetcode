/*
Number: 137
Topic: Single Number II
Date: 2021/7/3
Rate: Medium
https://leetcode.com/problems/single-number-ii/

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Constraints:
* 1 <= nums.length <= 3 * 104
* -231 <= nums[i] <= 231 - 1
* Each element in nums appears exactly three times except for one element which appears once.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // see post: https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers
        // and post: https://leetcode.com/problems/single-number-ii/discuss/43294/Challenge-me-thx
        int ones = 0, twoes = 0;
        for (const int& num : nums) {
            ones = (ones ^ num) & ~twoes;
            twoes = (twoes ^ num) & ~ones;
        }
        return ones;
    }
};