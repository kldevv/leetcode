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
        // bottom-up DP 
        // 會產生 overflow，因為我們計算了 0~target 所有的組合，有些組合可能其實不會用到
        // dp[i] 當 target = i 時，有幾種可能的組合
        vector<double> dp(target+1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i >= nums[j]) {
                    // 如果 i >= nums[j] 的話，dp[i]有一條路可以從 i-nums[j] 加上nums[j]變成 i，而這條路就是要把所有可能到 i-nums[j] 的路算進來，也就是 dp[i-nums[j]]
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};