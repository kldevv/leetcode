/*
Number: 47
Topic: Permutations II
Date: 2021/12/5
Rate: Medium
https://leetcode.com/problems/permutations-ii/

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Constraints:
    * 1 <= nums.length <= 8
    * -10 <= nums[i] <= 10
*/
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        /*
        For each position i, try value from i + 1 to n - 1;
            One value will only be tried once:
                + PermutationUnique(i + 1);
        */
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        permute(nums, 0, results);
        return results;
    }

    void permute(vector<int>& nums, int i, vector<vector<int>>& results) {
        if (i == nums.size()) {
            results.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            // skip duplicate
            if (j == i || nums[j] != nums[i]) {
                swap(nums[i], nums[j]);
                permute(nums, i + 1, results);
            }
        }
    }
};