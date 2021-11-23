/*
Number: 15
Topic: 3Sum
Date: 2021/9/30
Rate: Medium
https://leetcode.com/problems/3sum/

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Constraints:
    * 0 <= nums.length <= 3000
    * -105 <= nums[i] <= 105
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> results;
        for (int i = 0; i < nums.size(); i++) {
            // duplicate
            while (i > 0 && i < nums.size() && nums[i-1] == nums[i])
                i += 1;
            
            int j = i+1, t = nums.size()-1;
            while (j < t) {
                int total = nums[i] + nums[j] + nums[t];
                if (total == 0) {
                    results.push_back({nums[i], nums[j], nums[t]});
                    j++;
                    t--;
                } else if (total < 0) {
                    j++;
                } else {
                    t--;
                }
                // duplicate
                while (j < t && j > i+1 && nums[j] == nums[j-1])
                    j++;
                while (j < t && t < nums.size()-1 && nums[t] == nums[t+1])
                    t--;
            }
        }
        return results;
    }
};