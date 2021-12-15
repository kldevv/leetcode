/*
Number: 887
Topic: Super Egg Drop_O(k*log(n))_O(k)
Date: 2021/12/7
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

#include <vector>

using namespace std;

class Solution {
   public:
    int superEggDrop(int k, int n) {
        /*
        DP

        Base:
            dp[0][k] = 0, for any k
            dp[m][0] = 0, for any m

        Recurrence Relations:
            - dp[m][k] = the maximum number of floor we guarantee, given m moves and k eggs
            dp[m][k] = dp[m-1][k] + dp[m-1][k-1] + 1
        */
        vector<vector<int>> maxNumFloorGuaranteeToCheck(n + 1, vector<int>(k + 1, 0));
        int move = 0;
        while (maxNumFloorGuaranteeToCheck[move][k] < n) {
            move++;
            for (int eggUsed = 1; eggUsed <= k; eggUsed++) {
                maxNumFloorGuaranteeToCheck[move][eggUsed] = maxNumFloorGuaranteeToCheck[move - 1][eggUsed] + maxNumFloorGuaranteeToCheck[move - 1][eggUsed - 1] + 1;
            }
        }
        return move;
    }
};