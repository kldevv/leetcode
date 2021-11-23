/*
Number: 714
Topic: Best Time to Buy and Sell Stock with Transaction Fee
Date: 2021/11/14
Rate: Medium
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Constraints:
    * 1 <= prices.length <= 5 * 104
    * 1 <= prices[i] < 5 * 104
    * 0 <= fee < 5 * 104
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int holdProfit = INT_MIN;
        int cashProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            holdProfit = max(holdProfit, cashProfit - prices[i]);
            cashProfit = max(cashProfit, holdProfit - fee + prices[i]);
        }
        return cashProfit;
    }
};