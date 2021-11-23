/*
Number: 123
Topic: Best Time to Buy and Sell Stock III - General Approach
Date: 2021/11/15
Rate: Hard
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Constraints:
    * 1 <= prices.length <= 105
    * 0 <= prices[i] <= 105
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        // prfoit[k][t] = max profit gains in with k transactions remains and t states (0 == hold, 1 == cash)
        // base:
        // 1. profit[2][0] = 0; profit[2][1] = 0
        // recurrence:
        // profit[k][1] = max(profit[k][1], profit[k][0] + prices[i])
        // profit[k][0] = max(profit[k][0], profit[k+1][1] - prices[i])

        vector<vector<int> > profit(3, vector<int>(2, INT_MIN));
        profit[2][0] = 0;
        profit[2][1] = 0;

        for (int i = 0; i < prices.size(); i++) {
            for (int k = 1; k >= 0; k--) {
                // hold
                profit[k][0] = max(profit[k][0], profit[k + 1][1] - prices[i]);
                // cash
                profit[k][1] = max(profit[k][1], profit[k][1] + prices[i]);
            }
        }
        return max(profit[0][1], 0);
    }
};