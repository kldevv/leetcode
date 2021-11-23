/*
Number: 697
Topic: Degree of an Array
Date: 2021/9/6
Rate: Easy
https://leetcode.com/problems/degree-of-an-array/

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Constraints:
    * nums.length will be between 1 and 50,000.
    * nums[i] will be an integer between 0 and 49,999.
*/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count, firstAppear;
        int degree = 0;
        int minLen = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (count[nums[i]] == 0)
                firstAppear[nums[i]] = i;

            if (++count[nums[i]] > degree) {
                degree = count[nums[i]];
                minLen = i-firstAppear[nums[i]]+1;
            }
            if (count[nums[i]] == degree)
                minLen = min(minLen, i-firstAppear[nums[i]]+1);
        }
        return minLen;
    }
};