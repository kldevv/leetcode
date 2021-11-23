/*
Number: 188
Topic: Best Time to Buy and Sell Stock IV - General Approach
Date: 2021/11/15
Rate: Hard
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/#/description

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Constraints:
    * 0 <= k <= 100
    * 0 <= prices.length <= 1000
    * 0 <= prices[i] <= 1000
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        // maxProfit[k][t]: max profit gains with K transactions remains; t=0: holding zero stock, t=1: holding one stock
        // base case:
        // maxProfit[k][t] = 0
        // recurrence relation:
        // maxProfit[k][1] = max(maxProfit[k][1], maxProfit[k+1][0]-prices[i])
        // maxProfit[k][0] = max(maxProfit[k][0], maxProfit[k][0]+prices[i])

        vector<vector<int> > maxProfit(k + 1, vector<int>(2, INT_MIN));
        maxProfit[k][1] = 0;
        maxProfit[k][0] = 0;

        // int maxProfitRecord = 0;

        for (int i = 0; i < prices.size(); i++) {
            for (int kk = k - 1; kk >= 0; kk--) {
                maxProfit[kk][1] = max(maxProfit[kk][1], maxProfit[kk + 1][0] - prices[i]);
                maxProfit[kk][0] = max(maxProfit[kk][0], maxProfit[kk][1] + prices[i]);
                // maxProfitRecord = max(maxProfit[kk][0], maxProfitRecord);
            }
        }
        return max(0, maxProfit[0][0]);
    }
};