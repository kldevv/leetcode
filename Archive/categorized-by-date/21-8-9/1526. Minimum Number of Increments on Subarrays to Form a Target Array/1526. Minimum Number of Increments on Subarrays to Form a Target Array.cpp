/*
Number: 1526
Topic: Minimum Number of Increments on Subarrays to Form a Target Array
Date: 2021/8/10
Rate: Hard
https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/

Given an array of positive integers target and an array initial of same size with all zeros.

Return the minimum number of operations to form a target array from initial if you are allowed to do the following operation:

Choose any subarray from initial and increment each value by one.
The answer is guaranteed to fit within the range of a 32-bit signed integer.

Constraints:
* 1 <= target.length <= 10^5
* 1 <= target[i] <= 10^5
*/

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int out = 0;
        int prevNum = 0;
        for (const int& num : target) {
            out += max((num - prevNum), 0);
            prevNum = num;
        }
        return out;
    }
};