/*
Number: 322
Topic: Coin Change
Date: 2021/6/22
Rate: Medium
https://leetcode.com/problems/coin-change/

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Constraints:
* 1 <= coins.length <= 12
* 1 <= coins[i] <= 2^31 - 1
* 0 <= amount <= 10^4

*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int coinNum = 0;
        unordered_set<int> seen = {0};
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int currAmount = q.front();
                q.pop();

                if (currAmount == amount)
                    return coinNum;

                for (int j = 0; j < coins.size(); j++) {
                    if (currAmount <= amount-coins[j] && !seen.count(currAmount+coins[j])) {
                        q.push(currAmount+coins[j]);
                        seen.insert(currAmount+coins[j]);
                    }
                }
            }
            coinNum += 1;
        }
        return -1;
    }
};


// we can also do a BFS
// def coinChange(self, coins, amount):
//     level = seen = {0}
//     number = 0
//     while level:
//         if amount in level:
//             return number
//         level = {a+c for a in level for c in coins if a+c <= amount} - seen
//         seen |= level
//         number += 1
//     return -1