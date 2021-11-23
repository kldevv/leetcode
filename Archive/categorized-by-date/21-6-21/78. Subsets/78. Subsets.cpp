/*
Number: 78
Topic: Subsets
Date: 2021/6/21
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
        vector<vector<int>> out = {{}};

        for (int i = 0; i < nums.size(); i++) {
            int end = out.size();
            for (int j = 0; j < end; j++) {
                vector<int> temp = out[j];
                temp.push_back(nums[i]);
                out.push_back(move(temp));
            }
        }

        return out;
    }
};