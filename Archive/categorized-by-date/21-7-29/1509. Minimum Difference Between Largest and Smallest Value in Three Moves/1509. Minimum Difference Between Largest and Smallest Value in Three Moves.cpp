/*
Number: 1509
Topic: Minimum Difference Between Largest and Smallest Value in Three Moves
Date: 2021/7/29
Rate: Medium
https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

Given an array nums, you are allowed to choose one element of nums and change it by any value in one move.

Return the minimum difference between the largest and smallest value of nums after perfoming at most 3 moves.

Constraints:
* 1 <= nums.length <= 10^5
* -10^9 <= nums[i] <= 10^9
*/

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size()
        if (n < 5)
            return 0;

        partial_sort(nums.begin(), nums.begin()+4, nums.end());
        nth_element(nums.begin()+4, nums.end()-4, nums.end());
        sort(nums.end()-4, nums.end());

        int out = INT_MAX;
        for (int i = 1; i <= 4; i++) {
            out = min(out, nums[n-i]-nums[4-i]);
        }
        return out;
    }
};