/*
Number: 121
Topic: Best Time to Buy and Sell Stock - General Approach
Date: 2021/11/14
Rate: Easy
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Constraints:
  * 1 <= prices.length <= 105
  * 0 <= prices[i] <= 104
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int> &prices) {
        int holdProfit = INT_MIN;
        int cashProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            holdProfit = max(holdProfit, -prices[i]);
            cashProfit = max(cashProfit, holdProfit + prices[i]);
        }

        return cashProfit;
    }
};
