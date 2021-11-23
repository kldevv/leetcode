/*
Number: 18
Topic: 4Sum
Date: 2021/5/10
Rate: Medium
https://leetcode.com/problems/4sum/

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
* 0 <= a, b, c, d < n
* a, b, c, and d are distinct.
* nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

Constraints:
* 1 <= nums.length <= 200
* -109 <= nums[i] <= 109
* -109 <= target <= 109

O(n^3)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        // 第一層先拿出一個數字出來，更新 target，問題變成 3Sum
        for (int a = 0; a < nums.size()-3; a++) {
            // avoid duplicates
            if (a && (nums[a] == nums[a-1]))
                continue;
            int target_3sum = target - nums[a];
            // 第二層再拿出一個數字出來，更新 target，問題變成 2Sum
            for (int b = a+1; b < nums.size()-2; b++) {
                // avoid duplicates
                if ((b != a+1) && (nums[b] == nums[b-1]))
                    continue;
                int target_2sum = target_3sum - nums[b];
                int c = b+1, d = nums.size()-1;
                while (c < d) {
                    // avoid duplicates
                    if ((c != b+1) && (nums[c] == nums[c-1])) {
                        c++;
                        continue;
                    }
                    // avoid duplicates
                    else if ((d != nums.size()-1) && (nums[d] == nums[d+1])) {
                        d--;
                        continue;
                    }
                    // 2Sum 問題，兩個 pointer O(n) 解法
                    int target_final = target_2sum  - (nums[c]+nums[d]);
                    if (target_final == 0) {
                        out.push_back({nums[a], nums[b], nums[c++], nums[d--]});
                    }
                    else if (target_final > 0)
                        c++;
                    else
                        d--;
                }
            }
        }
        return out;
    }
};