/*
Number: 122
Topic: Best Time to Buy and Sell Stock II - Accumulate Positive Gains
Date: 2021/11/14
Rate: Medium
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

Constraints:
    * 1 <= prices.length <= 3 * 104
    * 0 <= prices[i] <= 104
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] < prices[i])
                maxProfit += (prices[i] - prices[i - 1]);
        }
        return maxProfit;
    }
};