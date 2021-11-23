/*
Number: 90
Topic: Subsets II
Date: 2021/10/18
Rate: Medium
https://leetcode.com/problems/subsets-ii/

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Constraints:
* 1 <= nums.length <= 10
* -10 <= nums[i] <= 10
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> results;
        if (nums.empty())
            return results;

        results.push_back({});
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = results.size();
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] != nums[i-1])
                start = 0;

            end = results.size();
            for (; start < end; start++) {
                vector<int> toExtend = results[start];
                toExtend.push_back(nums[i]);
                results.push_back(toExtend);
            }
        }
        return results;
    }
};