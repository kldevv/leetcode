/*
Number: 47
Topic: Permutations II
Date: 2021/10/18
Rate: Medium
https://leetcode.com/problems/permutations-ii/

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Constraints:
    * 1 <= nums.length <= 8
    * -10 <= nums[i] <= 10
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        permute(nums, 0, results);
        return results;
    }

    void permute(vector<int> nums, int start, vector<vector<int>>& results) {
        if (start == nums.size()) {
            results.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i != start && nums[i] == nums[start])
                continue;
            swap(nums[i], nums[start]);
            permute(nums, start+1, results);
        }
    }
};

