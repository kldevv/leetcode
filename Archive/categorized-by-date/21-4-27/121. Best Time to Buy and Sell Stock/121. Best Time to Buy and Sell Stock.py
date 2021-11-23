
'''
Number: 121
Topic: Best Time to Buy and Sell Stock
Date: 2021/4/27
Rate: Easy

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
'''

class Solution:
    def maxProfit(self, prices: [int]) -> int:
        max_profit, min_price = 0, float('inf')
        for idx in range(len(prices)):
        	if prices[idx] < min_price:
        		min_price = prices[idx]
        	cur_profit = prices[idx] - min_price
        	if cur_profit > max_profit:
        		max_profit = cur_profit
        return max_profit

'''
grade/pass
tc/O(n)
sc/O(1)
'''
