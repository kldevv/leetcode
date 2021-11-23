/*
Number: 46
Topic: Permutations
Date: 2021/6/23
Rate: Medium
https://leetcode.com/problems/permutations/

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.


Constraints:
* 1 <= nums.length <= 6
* -10 <= nums[i] <= 10
* All the integers of nums are unique.

*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
        permute(nums, 0, out);
        return out;
    }

    void permute(vector<int>& nums, int i, vector<vector<int>>& out) {
        // O(n!)
        // 代表已經完成一個 permuation
        if (i == nums.size()) {
            out.push_back(nums);
            return;
        }

        // 和之後的 element 都 swap 位置
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            permute(nums, i+1, out);
            swap(nums[i], nums[j]);
        }
    }
};