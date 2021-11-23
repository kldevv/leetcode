/*
Number: 1099
Topic: Two Sum Less Than K
Date: 2021/11/15
Rate: Easy
https://leetcode.com/problems/two-sum-less-than-k/

Given an array nums of integers and integer k, return the maximum sum such that there exists i < j with nums[i] + nums[j] = sum and sum < k. If no i, j exist satisfying this equation, return -1.

Constraints:
    * 1 <= nums.length <= 100
    * 1 <= nums[i] <= 1000
    * 1 <= k <= 2000
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = n - 1;
        int result = -1;
        while (i < j) {
            if (nums[i] + nums[j] >= k) {
                j--;
            } else {
                result = max(result, nums[i++] + nums[j]);
            }
        }
        return result;
    }
};