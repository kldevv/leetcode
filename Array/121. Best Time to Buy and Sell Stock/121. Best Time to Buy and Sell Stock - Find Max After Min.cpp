/*
Number: 121
Topic: Best Time to Buy and Sell Stock - Find Max After Min
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
        int maxProfit = 0;
        int minPrice = prices[0];

        int currentPrice;

        for (int idx = 0; idx < prices.size(); idx++) {
            currentPrice = prices[idx];

            if (currentPrice <= minPrice) {
                minPrice = currentPrice;
            } else {
                maxProfit = max(maxProfit, currentPrice - minPrice);
            }
        }

        return maxProfit;
    }
};
