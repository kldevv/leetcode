/*
Number: 256
Topic: Paint House
Date: 2021/7/22
Rate: Medium
https://leetcode.com/problems/paint-house/

There is a row of n houses, where each house can be painted one of three colors: red, blue, or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.

* For example, costs[0][0] is the cost of painting house 0 with the color red; costs[1][2] is the cost of painting house 1 with color green, and so on...

Return the minimum cost to paint all houses.

Constraints:
* costs.length == n
* costs[i].length == 3
* 1 <= n <= 100
* 1 <= costs[i][j] <= 20

*/

class Solution {
public:
    const int COLOR = 3;
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();

        int preRed = 0, preBlue = 0, preGreen = 0;
        for (int i = 0; i < n; i++) {
            int r = costs[i][0] + min(preBlue, preGreen);
            int b = costs[i][1] + min(preRed, preGreen);
            int g = costs[i][2] + min(preRed, preBlue);
            preRed = r, preBlue = b, preGreen = g;
        }
        return min(preRed, min(preBlue, preGreen));
    }
};