/*
Number: 1004
Topic: Max Consecutive Ones III
Date: 2021/8/4
Rate: Medium
https://leetcode.com/problems/max-consecutive-ones-iii/

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Constraints:
* 1 <= nums.length <= 105
* nums[i] is either 0 or 1.
* 0 <= k <= nums.length
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int out = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!nums[i])
                k--;
            while (k < 0) {
                if (!nums[j++])
                    k++;
            }
            out = max(out, i - j +1);
        }
        return out;
    }
};