'''
Number: 322
Topic: Coin Change
Date: 2021/11/2
Rate: Medium
https://leetcode.com/problems/coin-change/

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Constraints:
    * 1 <= coins.length <= 12
    * 1 <= coins[i] <= 231 - 1
    * 0 <= amount <= 104
'''

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [amount+1] * (amount+1)
        dp[0] = 0
        found = False
        for target_amount in range(1, amount+1):
            for coin in coins:
                if target_amount - coin < 0:
                    continue
                dp[target_amount] = min(dp[target_amount], dp[target_amount-coin]+1)
        return dp[amount] if dp[amount] < amount+1 else -1