/*
Number: ˙887
Topic: Super Egg Drop_O(kn^2)_brute_force
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
        vector<vector<int>> dp(k+1, vector<int>(n+1, INT_MAX));

        for (int K = 1; K <= k; K++) {
            for (int N = 0; N <= n; N++) {
                if (K == 1) {
                    dp[K][N] = N;
                    continue;
                }
                if (N == 1 || N == 0) {
                    dp[K][N] = (N == 1) ? 1 : 0;
                    continue;
                }
                for (int X = 1; X <= N; X++) {
                    dp[K][N] = min(dp[K][N], 1 + max(dp[K-1][X-1], dp[K][N-X]));
                }
            }
        }
        return dp[k][n];
    }
};