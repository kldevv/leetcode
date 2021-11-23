/*
Number: 887
Topic: Super Egg Drop_O(k*n)_O(n)
Date: 2021/11/8
Rate: Hard
https://leetcode.com/problems/super-egg-drop/

You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

Constraints:
    * 1 <= k <= 100
    * 1 <= n <= 104
*/

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1, vector(2, 0));
        for (int k_i = 1; k_i <= k; k_i++) {
            int x = 1;
            for (int n_j = 0; n_j <= n; n_j++) {
                if (k_i == 1) {
                    dp[n_j][k_i % 2] = n_j;
                    continue;
                }
                if (n_j == 1) {
                    dp[n_j][k_i % 2] = 1;
                    continue;
                }
                if (n_j == 0) {
                    dp[n_j][k_i % 2] = 0;
                    continue;
                }
                while (x < n_j && max(dp[x-1][k_i % 2], dp[n_j-x][(k_i+1) % 2]) > max(dp[x][k_i % 2], dp[n_j-x-1][(k_i+1) % 2]))
                    x++;
                dp[n_j][k_i % 2] = 1 + max(dp[x-1][k_i % 2], dp[n_j-x][(k_i+1) % 2]);
            }
        }
        return dp[n][k%2];
    }
};