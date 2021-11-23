/*
Number: 259
Topic: 3Sum Smaller
Date: 2021/11/15
Rate: Medium
https://leetcode.com/problems/3sum-smaller/

Given an array of n integers nums and an integer target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

Constraints:
    * n == nums.length
    * 0 <= n <= 3500
    * -100 <= nums[i] <= 100
    * -100 <= target <= 100
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int threeSumSmaller(vector<int>& nums, int target) {
        // Give array [i_0, i_1, ... , i_n-1]
        // for (first = 0 ~ n-3)
        // set second = first + 1, third = n-1
        // if (second + third > target) -> third--
        // if (second + third <= target) -> result += third-second && second++

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int result = 0;
        for (int i = 0; i < n - 2; i++) {
            int targetFor2 = target - nums[i];
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                if (nums[j] + nums[k] >= targetFor2) {
                    k--;
                } else {
                    result += (k - j);
                    j++;
                }
            }
        }
        return result;
    }
};