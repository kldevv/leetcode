/*
Number: 188
Topic: Best Time to Buy and Sell Stock IV
Date: 2021/7/13
Rate: Hard
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Constraints:
* 0 <= k <= 100
* 0 <= prices.length <= 1000
* 0 <= prices[i] <= 1000
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int m = prices.size();
        if (!k || !m)
            return 0;

        vector<vector<int>> dp(k+1, vector<int>(m, 0));
        // dp[i][j] 進行 i 次買賣到第 j 天的最大 profit
        for (int i = 1; i <= k; i++) {
            int maxTemp = -prices[0];
            for (int j = 1; j < m; j++) {
                // dp[i][j] =
                // 1. dp[i][j-1] 沒有做買賣
                // 2. max(prices[j]-prices[t] + prices[i-1][t-1]), t in [0 ~ j-1]; 在第 t 天買進，第 j 天賣出
                dp[i][j] = max(dp[i][j-1], prices[j]+maxTemp);
                // 用 maxTemp 來紀錄 max(dp[i-1][t-1]-prices[t]) 就不用從 0 ~ j-1 再搜尋一次
                maxTemp = max(maxTemp, dp[i-1][j-1]-prices[j]);
            }
        }

        return dp[k][m-1];
    }
};
