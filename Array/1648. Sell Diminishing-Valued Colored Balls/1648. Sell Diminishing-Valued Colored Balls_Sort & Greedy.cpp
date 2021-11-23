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
    const int MOD = 1e9 + 7;
public:
    int maxProfit(vector<int>& inventory, int orders) {
        long result = 0;

        sort(inventory.rbegin(), inventory.rend());
        int i = 0;
        int curValue = inventory[i];
        while (orders > 0 && i < inventory.size()) {
            while (i < inventory.size() && inventory[i] == curValue)
                i++;
            int nextValue = (i < inventory.size()) ? inventory[i] : 0;

            int numOfBall = (curValue - nextValue) * (i);
            if (orders >= numOfBall) {
                result += (long)(curValue + nextValue + 1) * (curValue - nextValue) / 2 * (i) % MOD;
            } else {
                int numOfFullRow = orders / (i);
                int offsetBall = orders % (i);
                int offsetLevelValue = curValue - numOfFullRow;
                result += ((long)curValue + (offsetLevelValue+1)) * numOfFullRow / 2 * (i) % MOD;
                result += (long)offsetLevelValue * offsetBall % MOD;
            }
            orders -= numOfBall;
            result %= MOD;
            curValue = nextValue;
        }
        return (int)result;
    }
};