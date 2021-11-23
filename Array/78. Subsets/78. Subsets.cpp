/*
Number: 78
Topic: Subsets
Date: 2021/10/18
Rate: Medium
https://leetcode.com/problems/subsets/

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Constraints:
    * 1 <= nums.length <= 10
    * -10 <= nums[i] <= 10
    * All the numbers of nums are unique.

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        getSubset(nums, {}, 0, results);
        return results;
    }

    void getSubset(vector<int>& nums, vector<int> result, int start, vector<vector<int>>& results) {
        if (start == nums.size()) {
            results.push_back(result);
            return;
        }

        result.push_back(nums[start]);
        getSubset(nums, result, start+1, results);
        result.pop_back();
        getSubset(nums, result, start+1, results);
    }
};
