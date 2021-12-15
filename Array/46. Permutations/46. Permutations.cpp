/*
Number: 46
Topic: Permutations
Date: 2021/12/5
Rate: Medium
https://leetcode.com/problems/permutations/

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Constraints:
    * 1 <= nums.length <= 6
    * -10 <= nums[i] <= 10
    * All the integers of nums are unique.
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        /*
        Base cases:
            i = nums.size():
                Done
        For position i of nums:
            Try :
                value from nums[0] to nums[n-1]
                GetPermutationStartFrom(i+1)
        */
        vector<vector<int>> results;
        permute(nums, 0, results);
        return results;
    }

    void permute(vector<int>& nums, int position, vector<vector<int>>& results) {
        if (position == nums.size()) {
            results.push_back(nums);
        }

        for (int swapIdx = position; swapIdx < nums.size(); swapIdx++) {
            swap(nums[position], nums[swapIdx]);
            permute(nums, position + 1, results);
            swap(nums[position], nums[swapIdx]);
        }
    }
};