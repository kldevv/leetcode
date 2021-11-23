/*
Number: 945
Topic: Minimum Increment to Make Array Unique
Date: 2021/9/8
Rate: Medium
https://leetcode.com/problems/minimum-increment-to-make-array-unique/

You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

Return the minimum number of moves to make every value in nums unique.

Constraints:
    * 1 <= nums.length <= 105
    * 0 <= nums[i] <= 105

*/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int minNext = 0;
        int result = 0;
        for (const int& num : nums) {
            result += max(minNext-num, 0);
            minNext = max(minNext, num) + 1;
        }
        return result;
    }
};