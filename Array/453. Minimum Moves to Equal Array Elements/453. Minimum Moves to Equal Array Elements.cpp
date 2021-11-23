/*
Number: 453
Topic: Minimum Moves to Equal Array Elements
Date: 2021/9/8
Rate: Easy
https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment n - 1 elements of the array by 1.

Constraints:
    * n == nums.length
    * 1 <= nums.length <= 105
    * -109 <= nums[i] <= 109
    * The answer is guaranteed to fit in a 32-bit integer.

*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int minVal = INT_MAX;
        for (const int& num : nums) {
            minVal = min(minVal, num);
            sum += num;
        }
        return sum - minVal*nums.size();
    }
};