/*
Number: 547
Topic: Number of Provinces
Date: 2021/9/23
Rate: Medium
https://leetcode.com/problems/number-of-provinces/

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Constraints:
    * 1 <= n <= 200
    * n == isConnected.length
    * n == isConnected[i].length
    * isConnected[i][j] is 1 or 0.
    * isConnected[i][i] == 1
    * isConnected[i][j] == isConnected[j][i]
*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if (n == 0)
            return 0;

        vector<int> lead(n, 0);
        for (int i = 0; i < n; i++) {
            lead[i] = i;
        }

        int result = n;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (isConnected[i][j]) {
                    int lead1 = findGroup(i, lead);
                    int lead2 = findGroup(j, lead);
                    if (lead1 != lead2) {
                        lead[lead2] = lead1;
                        result -= 1;
                    }
                }
            }
        }
        return result;
    }

    int findGroup(int i, const vector<int>& lead) {
        return (lead[i] == i) ? i : findGroup(lead[i], lead);
    }
};