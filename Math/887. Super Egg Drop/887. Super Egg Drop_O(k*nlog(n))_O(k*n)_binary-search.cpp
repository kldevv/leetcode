/*
Number: 887
Topic: Super Egg Drop_O(k*nlog(n))_O(k*n)_binary-search
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
private:
    vector<vector<int>> dp;
public:
    int superEggDrop(int k, int n) {
        this->dp = vector<vector<int>>(k+1, vector<int>(n+1, -1));
        return superEggDropDP(k, n);
    }

    int superEggDropDP(int K, int N) {
        if (dp[K][N] != -1)
            return dp[K][N];
        if (N == 0)
            return 0;
        if (K == 1)
            return N;
        if (N == 1)
            return 1;

        int low = 1;
        int high = N;
        while (low + 1 < high) {
            int mid = low + (high-low)/2;
            int eggBreak = superEggDropDP(K-1, mid-1);
            int eggNotBreak = superEggDropDP(K, N-mid);

            if (eggBreak < eggNotBreak)
                low = mid;
            else if (eggBreak > eggNotBreak)
                high = mid;
            else {
                low = mid;
                high = mid;
            }
        }

        dp[K][N] = 1 + min(max(superEggDropDP(K-1, low-1), superEggDropDP(K, N-low)), 
            max(superEggDropDP(K-1, high-1), superEggDropDP(K, N-high)));
        return dp[K][N];
    }
};