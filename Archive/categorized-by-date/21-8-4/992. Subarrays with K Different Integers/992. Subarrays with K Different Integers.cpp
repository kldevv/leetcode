/*
Number: 994
Topic: Subarrays with K Different Integers
Date: 2021/8/4
Rate: Hard
https://leetcode.com/problems/subarrays-with-k-different-integers/

Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

Constraints:
* 1 <= nums.length <= 2 * 104
* 1 <= nums[i], k <= nums.length
*/

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtMostK(nums, k) - subarraysWithAtMostK(nums, k-1);
    }

    int subarraysWithAtMostK(const vector<int>& nums, int k){
        int out = 0;
        int j = 0;
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); i++) {
            if (!dict[nums[i]]++)
                k--;
            while (k < 0) {
                if (!--dict[nums[j++]])
                    k++;
            }
            out += i - j + 1;
        }
        return out;
    }

};