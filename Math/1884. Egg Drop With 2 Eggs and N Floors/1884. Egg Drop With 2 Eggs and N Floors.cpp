/*
Number: 1884
Topic: Egg Drop With 2 Eggs and N Floors
Date: 2021/12/7
Rate: Medium
https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/

You are given two identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

In each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

Constraints:
    * 1 <= n <= 1000
*/

#include <vector>

using namespace std;

class Solution {
   public:
    int twoEggDrop(int n) {
        /*
        maxNumFloorGuaranteeToCheck(dp)[m][2] >= n

        Base case:
            dp[m][0] = 0, for any m
            dp[0][k] = 0, for any k

        Relations:
            dp[m][2] = dp[m-1][1] + dp[m-1][2] + 1

        */
        vector<vector<int>> maxNumFloorGuaranteeToCheck(n + 1, vector<int>(3, 0));
        int move = 0;
        while (maxNumFloorGuaranteeToCheck[move][2] < n) {
            move += 1;
            maxNumFloorGuaranteeToCheck[move][2] = maxNumFloorGuaranteeToCheck[move - 1][1] + maxNumFloorGuaranteeToCheck[move - 1][2] + 1;
            maxNumFloorGuaranteeToCheck[move][1] = maxNumFloorGuaranteeToCheck[move - 1][0] + maxNumFloorGuaranteeToCheck[move - 1][1] + 1;
        }
        return move;
    }
};