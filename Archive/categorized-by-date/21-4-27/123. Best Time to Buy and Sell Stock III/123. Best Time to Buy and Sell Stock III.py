
'''
Number: 123
Topic: Best Time to Buy and Sell Stock III
Date: 2021/4/27
Rate: Hard

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
'''

class Solution:
    def maxProfit(self, prices: [int]) -> int:
        start_idx, end_idx, max_profit, min_price = 0, 0, 0, float("inf")
        temp_idx = 0
        for idx, price in enumerate(prices):
            if price < min_price:
                min_price = price
                temp_idx = idx
            cur_profit = price - min_price
            if cur_profit > max_profit:
                max_profit = cur_profit
                start_idx = temp_idx
                end_idx = idx

        max_cut_lose, max_price = 0, 0
        for price in prices[start_idx:end_idx]:
            max_price = max(price, max_price)
            cur_profit = max_price - price
            max_cut_lose = max(cur_profit, max_cut_lose)

        max_additional_profit1, max_additional_profit2 = 0, 0
        min_price = float("inf")
        for price in prices[end_idx+1:]:
            min_price = min(price, min_price)
            cur_profit = price - min_price
            max_additional_profit1 = max(cur_profit, max_additional_profit1)
        min_price = float("inf")
        for price in prices[:start_idx]:
            min_price = min(price, min_price)
            cur_profit = price - min_price
            max_additional_profit2 = max(cur_profit, max_additional_profit2)        

        return max_profit + max(max_cut_lose, max(max_additional_profit1, max_additional_profit2))

# test = [2,4,1]
# print(Solution().maxProfit(test))



