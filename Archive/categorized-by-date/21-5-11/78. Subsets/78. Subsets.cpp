/*
Number: 78
Topic: Subsets
Date: 2021/5/11
Rate: Medium
https://leetcode.com/problems/subsets/

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Constraints:

* 1 <= nums.length <= 10
* -10 <= nums[i] <= 10
* All the numbers of nums are unique.
*/

// recursive algo 拿到排列組合
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out = {{}};
        vector<int> temp;
        recurseComb(nums, 0, temp, out);
        return out;
    }

    void recurseComb(const vector<int>& nums, const int start, vector<int>& temp, vector<vector<int>>& out) {
        if (start == nums.size()) return;
        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            out.push_back(temp);
            recurseComb(nums, i+1, temp, out);
            temp.pop_back();
        }
        return;
    }
};

