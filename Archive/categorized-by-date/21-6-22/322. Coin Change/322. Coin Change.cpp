/*
Number: 322
Topic: Coin Change
Date: 2021/6/22
Rate: Medium
https://leetcode.com/problems/coin-change/

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Constraints:
* 1 <= coins.length <= 12
* 1 <= coins[i] <= 231 - 1
* 0 <= amount <= 10^4

*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // tc: O(coins.size()*amount)
        if (!amount)
            return 0;

        int n = coins.size();
        int invalid = amount+1;
        vector<int> dp(amount+1, invalid);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (i - coins[j] >= 0)
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }

        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};


// we can also do a BFS
// def coinChange(self, coins, amount):
//     level = seen = {0}
//     number = 0
//     while level:
//         if amount in level:
//             return number
//         level = {a+c for a in level for c in coins if a+c <= amount} - seen
//         seen |= level
//         number += 1
//     return -1