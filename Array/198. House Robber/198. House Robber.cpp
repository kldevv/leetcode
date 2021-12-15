/*
Number: 198
Topic: House Robber
Date: 2021/12/5
Rate: Medium
https://leetcode.com/problems/house-robber/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Constraints:
    * 1 <= nums.length <= 100
    * 0 <= nums[i] <= 400
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        /*

        At house n, we can choose either to rob or not to rob

        The maximum profit to rob will be => maximum profit of not rob n-1 house + value(house n)
        The maximum profit not to rob will be => max(maximum profit of not to rob n-1, maximum profit of to rob n-1)

        dp[i][s]: maximum profit at i-th house with s status; s = 1 robbed, s = 0 not robbed
        */

        vector<vector<int>> maximumProfit(2, vector<int>(2, 0));

        for (int i = 0; i < nums.size(); i++) {
            maximumProfit[i % 2][1] = maximumProfit[(i + 1) % 2][0] + nums[i];
            maximumProfit[i % 2][0] = max(maximumProfit[(i + 1) % 2][0], maximumProfit[(i + 1) % 2][1]);
        }
        return max(maximumProfit[(nums.size() - 1) % 2][0], maximumProfit[(nums.size() - 1) % 2][1]);
    }
};