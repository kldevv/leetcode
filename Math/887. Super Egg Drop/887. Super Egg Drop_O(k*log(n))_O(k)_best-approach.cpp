/*
Number: 887
Topic: Super Egg Drop_O(k*log(n))_O(k)
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
        vector<int> dp(k+1, 0);
        int m;
        for (m = 0; dp[k] < n; m++) {
            for (int kk = k; kk > 0; kk--) {
                dp[kk] += dp[kk-1] + 1;
            }
        }
        return m;
    }
};