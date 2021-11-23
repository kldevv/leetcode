/*
Number: 1
Topic: Two Sum
Date: 2021/6/5
Rate: Easy
https://leetcode.com/problems/two-sum/

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Constraints:
* 2 <= nums.length <= 104
* -109 <= nums[i] <= 109
* -109 <= target <= 109
* Only one valid answer exists.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
            if (umap.count(nums[i]))
                return {i, umap[nums[i]]};
            umap[target-nums[i]] = i;
        }

        return {};
    }
};