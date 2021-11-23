/*
Number: 309
Topic: Best Time to Buy and Sell Stock with Cooldown - General Approach
Date: 2021/11/15
Rate: Medium
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/#/description

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
    * After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Constraints:
    * 1 <= prices.length <= 5000
    * 0 <= prices[i] <= 1000
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        // maxProfitGains[i][t]: max profit gains at i-th day holding # of t stocks.

        // Base case:
        // * maxProftGains[0][0] = 0
        // * maxProftGains[0][1] = -prices[0]

        // Recurrence relation:
        // * maxProfitGains[i][1] = max(maxProfitGains[i-1][1], maxProfitGains[i-2][0] - prices[i])
        // * maxProfitGains[i][0] = max(maxProfitGains[i-1][0], maxProfitGains[i-1][0] + prices[i])

        int n = prices.size();
        vector<vector<int> > maxProfitGains(n, vector<int>(2, INT_MIN));
        maxProfitGains[0][0] = 0;
        maxProfitGains[0][1] = -prices[0];

        for (int i = 1; i < n; i++) {
            maxProfitGains[i][1] = max(maxProfitGains[i - 1][1], ((i >= 2) ? maxProfitGains[i - 2][0] : 0) - prices[i]);
            maxProfitGains[i][0] = max(maxProfitGains[i - 1][0], maxProfitGains[i - 1][1] + prices[i]);
        }
        return max(0, maxProfitGains[n - 1][0]);
    }
};