/*
Number: 1548
Topic: The Most Similar Path in a Graph
Date: 2021/8/9
Rate: Hard
https://leetcode.com/problems/the-most-similar-path-in-a-graph/

We have n cities and m bi-directional roads where roads[i] = [ai, bi] connects city ai with city bi. Each city has a name consisting of exactly 3 upper-case English letters given in the string array names. Starting at any city x, you can reach any city y where y != x (i.e. the cities and the roads are forming an undirected connected graph).

You will be given a string array targetPath. You should find a path in the graph of the same length and with the minimum edit distance to targetPath.

You need to return the order of the nodes in the path with the minimum edit distance, The path should be of the same length of targetPath and should be valid (i.e. there should be a direct road between ans[i] and ans[i + 1]). If there are multiple answers return any one of them.

The edit distance is defined as follows:

Follow-up: If each node can be visited only once in the path, What should you change in your solution?

Constraints:
* 2 <= n <= 100
* m == roads.length
* n - 1 <= m <= (n * (n - 1) / 2)
* 0 <= ai, bi <= n - 1
* ai != bi 
* The graph is guaranteed to be connected and each pair of nodes may have at most one direct road.
* names.length == n
* names[i].length == 3
* names[i] consists of upper-case English letters.
* There can be two cities with the same name.
* 1 <= targetPath.length <= 100
* targetPath[i].length == 3
* targetPath[i] consists of upper-case English letters.
*/

class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        vector<vector<int>> graph(n);
        for (vector<int>& v : roads) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }

        int k = targetPath.size();
        vector<vector<int>> dp(n, vector<int>(k, INT_MAX));
        vector<vector<int>> parent(n, vector<int>(k, INT_MAX));
        for (int i = 0; i < n; i++) {
            dp[i][0] = (names[i] != targetPath[0]);
        }

        for (int t = 1; t < k; t++) {
            string targetCity = targetPath[t];
            for (int i = 0; i < n; i++) {
                int minPreCost = INT_MAX;
                for (int connectedCity : graph[i]) {
                    if (dp[connectedCity][t-1] < minPreCost) {
                        minPreCost = dp[connectedCity][t-1];
                        parent[i][t] = connectedCity;
                    }
                }
                dp[i][t] = minPreCost + (names[i] != targetCity);
            }
        }

        int cost = INT_MAX;
        int lastCity;
        for (int i = 0; i < n; i++) {
            if (dp[i][k-1] < cost) {
                lastCity = i;
                cost = dp[i][k-1];
            }
        }

        vector<int> out(k, 0);
        for (int t = k-1; t >= 0; t--) {
            out[t] = lastCity;
            lastCity = parent[lastCity][t];
        }
        return out;
    }
};