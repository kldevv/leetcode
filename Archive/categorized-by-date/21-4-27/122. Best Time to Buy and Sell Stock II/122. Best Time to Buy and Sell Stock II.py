
'''
Number: 122
Topic: Best Time to Buy and Sell Stock II
Date: 2021/4/27
Rate: Easy

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
'''

class Solution:
    def maxProfit(self, prices: [int]) -> int:
    	accum_profit, max_profit, min_price = 0, 0, prices[0]
    	for idx in range(1, len(prices)):
    		profit = prices[idx] - min_price
    		if profit > max_profit:
    			max_profit = profit
    		else:
    			accum_profit += max_profit
    			max_profit = 0
    			min_price = prices[idx]
    	accum_profit += max_profit
    	return accum_profit

'''
grade/pass
tc/O(n)
sc/O(1)
'''