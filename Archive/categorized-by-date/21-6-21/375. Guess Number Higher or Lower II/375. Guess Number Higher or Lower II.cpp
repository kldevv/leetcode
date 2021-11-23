/*
Number: 375
Topic: Guess Number Higher or Lower II
Date: 2021/6/21
Rate: Medium
https://leetcode.com/problems/guess-number-higher-or-lower-ii/

We are playing the Guessing Game. The game will work as follows:

1. I pick a number between 1 and n.
2. You guess a number.
3. If you guess the right number, you win the game.
4. If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
5. Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.


Constraints:
* 1 <= n <= 200


*/

class Solution {
public:
    vector<vector<int>> dp;

    int getMoneyAmount(int n) {
        // init dp
        // dp[start][end] 代表在 range start~end 之中保證能贏的最小金額
        for (int i = 0; i <= n; i++) {
            vector<int> temp;
            for (int j = 0; j <= n; j++) {
                temp.push_back(0);
            }
            dp.push_back(temp);
        }

        return getMoneyAmount(1, n);
    }

    int getMoneyAmount(int start, int end) {
        if (start >= end)
            return 0;

        // 如果已經在 dp 中就回傳
        if (dp[start][end] != 0)
            return dp[start][end];


        int guarantee = INT_MAX;
        for (int i = start; i <= end; i++) {
            // 找到下一個最佳的 guess，guess 可以再 start~end 當中
            // 選了 guess 後，最糟的情況如果沒猜到，我們的 cost 變成 guess + 剩下前面的 range 保證能贏的 + 後面 range 保證能贏的
            guarantee = min(guarantee, i + max(getMoneyAmount(start, i-1), getMoneyAmount(i+1, end)));
        }

        dp[start][end] = guarantee;
        return guarantee;
    }
};