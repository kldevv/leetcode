/*
Number: 1648
Topic: Sell Diminishing-Valued Colored Balls
Date: 2021/9/27
Rate: Medium
https://leetcode.com/problems/sell-diminishing-valued-colored-balls/

You have an inventory of different colored balls, and there is a customer that wants orders balls of any color.

The customer weirdly values the colored balls. Each colored ball's value is the number of balls of that color you currently have in your inventory. For example, if you own 6 yellow balls, the customer would pay 6 for the first yellow ball. After the transaction, there are only 5 yellow balls left, so the next yellow ball is then valued at 5 (i.e., the value of the balls decreases as you sell more to the customer).

You are given an integer array, inventory, where inventory[i] represents the number of balls of the ith color that you initially own. You are also given an integer orders, which represents the total number of balls that the customer wants. You can sell the balls in any order.

Return the maximum total value that you can attain after selling orders colored balls. As the answer may be too large, return it modulo 109 + 7.

Constraints:
    * 1 <= inventory.length <= 105
    * 1 <= inventory[i] <= 109
    * 1 <= orders <= min(sum(inventory[i]), 109)
*/

class Solution {
private:
    bool hasEnoughBall(const int equalizer, int numberOfBall, map<int, int, greater<int>>& counter) {
        for (auto& [N, count] : counter) {
            numberOfBall -= (long)count * max((N - equalizer), 0);
            if (numberOfBall <= 0)
                return true;
        }
        return false;
    }
    const int MOD = 1e9 + 7;

public:
    int maxProfit(vector<int>& inventory, int orders) {
        map<int, int, greater<int>> counter;
        for (int i = 0; i < inventory.size(); i++)
            counter[inventory[i]] += 1;

        int lowerBound = 0, upperBound = *max_element(inventory.begin(), inventory.end());
        while (lowerBound <= upperBound) {
            int m = lowerBound + (upperBound-lowerBound)/2;
            if (hasEnoughBall(m, orders, counter))
                lowerBound = m + 1;
            else
                upperBound = m - 1;
        }
        
        int result = 0;
        for (auto& [N, count] : counter) {
            if (N <= lowerBound)
                break;

            result += (long)(N + lowerBound + 1) * (N - lowerBound) / 2 % MOD * count % MOD;
            result %= MOD;

            orders -= (N - lowerBound) * count;
        }

        if (orders)
            result += ((long)orders * lowerBound) % MOD;
        result %= MOD;

        return result;
    }
};

