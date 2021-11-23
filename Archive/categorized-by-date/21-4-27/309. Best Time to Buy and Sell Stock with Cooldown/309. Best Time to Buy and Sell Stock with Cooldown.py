'''
Number: 309
Topic: 309. Best Time to Buy and Sell Stock with Cooldown
Date: 2021/4/27
Rate: Medium

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
'''

class Solution:
    def maxProfit(self, prices: [int]) -> int:
    	sell_profit, buy_profit, prev_sell_profit, prev_buy_profit = 0, -prices[0], 0, -prices[0]
    	for price in prices:
    		prev_buy_profit = buy_profit
    		buy_profit = max(prev_sell_profit-price, prev_buy_profit)
    		prev_sell_profit = sell_profit
    		sell_profit = max(prev_buy_profit+price, prev_sell_profit)
    		print(sell_profit, buy_profit)
    	return sell_profit

'''
grade/pass
tc/O(n)
sc/O(1)
'''





