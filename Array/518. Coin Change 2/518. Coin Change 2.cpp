/*
Number: 518
Topic: Coin Change 2
Date: 2021/11/2
Rate: Medium
https://leetcode.com/problems/coin-change-2/

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

Constraints:
    * 1 <= coins.length <= 300
    * 1 <= coins[i] <= 5000
    * All the values of coins are unique.
    * 0 <= amount <= 5000
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (const int& coin : coins) {
            for (int amountTarget = 1; amountTarget <= amount; amountTarget++) {
                if (amountTarget - coin < 0)
                    continue;
                dp[amountTarget] += dp[amountTarget-coin];
            }
        }
        return dp[amount];
    }
};