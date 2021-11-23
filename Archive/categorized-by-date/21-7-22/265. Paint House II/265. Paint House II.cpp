/*
Number: 265
Topic: Paint House II
Date: 2021/7/22
Rate: Medium
https://leetcode.com/problems/paint-house-ii/

There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an n x k cost matrix costs.

* For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on...

Return the minimum cost to paint all houses.

Constraints:
* costs.length == n
* costs[i].length == k
* 1 <= n <= 100
* 1 <= k <= 20
* 1 <= costs[i][j] <= 20

Follow up: Could you solve it in O(nk) runtime?

*/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = (n) ? costs[0].size() : 0;
        int lastMinIdx = 0;
        int lastMinVal = 0, lastMinVal2 = 0;

        for (int i = 0; i < n; i++) {
            int minIdx = 0, minIdx2 = 0;
            int minVal = INT_MAX, minVal2 = INT_MAX;
            for (int j = 0; j < k; j++) {
                int preCost = (j != lastMinIdx) ? lastMinVal : lastMinVal2;

                if (costs[i][j] + preCost < minVal) {
                    minVal2 = minVal;
                    minVal = costs[i][j] + preCost;
                    minIdx = j;
                }
                else if (costs[i][j] + preCost < minVal2) {
                    minVal2 = costs[i][j] + preCost;
                }
            }            
            lastMinIdx = minIdx;
            lastMinVal = minVal, lastMinVal2 = minVal2;
        }
        return lastMinVal;
    }
};