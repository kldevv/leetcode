/*
Number: 377
Topic: Combination Sum IV
Date: 2021/6/23
Rate: Medium
https://leetcode.com/problems/combination-sum-iv/

Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The answer is guaranteed to fit in a 32-bit integer.

Follow up: What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?


Constraints:
* 1 <= nums.length <= 200
* 1 <= nums[i] <= 1000
* All the elements of nums are unique.
* 1 <= target <= 1000
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // top-down with DP
        vector<int> dp(target, INT_MAX);
        return combinationSum4(nums, target, dp);
    }
    

    int combinationSum4(vector<int>& nums, int target, vector<int>& dp) {
        // target == 0 只有一種組合那就是空集合
        if (target == 0)
            return 1;
        // DP do the work
        if (dp[target-1] != INT_MAX)
            return dp[target-1];


        // 計算到這個 target 時的組合有幾個
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 如果目前的 target 小於所有 nums[i] 就會回傳零
            if (target-nums[i] >= 0)
                // 看看有幾種組合可以走到現在這個 target
                res += combinationSum4(nums, target-nums[i], dp);
        }
        dp[target-1] = res;
        return res;
    }
};