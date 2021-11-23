/*
Number: 1770
Topic: Maximum Score from Performing Multiplication Operations
Date: 2021/6/15
Rate: Medium
https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/


You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. The arrays are 1-indexed.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:

* Choose one integer x from either the start or the end of the array nums.
* Add multipliers[i] * x to your score.
* Remove x from the array nums.

Return the maximum score after performing m operations.

Constraints:
* n == nums.length
* m == multipliers.length
* 1 <= m <= 103
* m <= n <= 105
* -1000 <= nums[i], multipliers[i] <= 1000


*/

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(m, vector<int>(m, INT_MIN));

        return maximumScore(nums, multipliers, 0, 0, dp);
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers, int i, int k, vector<vector<int>>& dp) {
        if (k == multipliers.size())
            return 0;

        if (dp[i][k] != INT_MIN)
            return dp[i][k];
        // 雖說有三個數字 i j k 但實際上的自由度只有 2 而已
        int j = nums.size() - 1 - (k-i);
        int front = nums[i]*multipliers[k] + maximumScore(nums, multipliers, i+1, k+1, dp);
        int end = nums[j]*multipliers[k] + maximumScore(nums, multipliers, i, k+1, dp);
        
        dp[i][k] = max(front, end);
        
        return dp[i][k];
    }
};