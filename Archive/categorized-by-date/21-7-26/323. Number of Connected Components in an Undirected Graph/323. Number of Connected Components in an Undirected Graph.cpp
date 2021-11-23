/*
Number: 323
Topic: Number of Connected Components in an Undirected Graph
Date: 2021/7/26
Rate: Medium
https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.

Constraints:
* 1 <= n <= 2000
* 1 <= edges.length <= 5000
* edges[i].length == 2
* 0 <= ai <= bi < n
* ai != bi
* There are no repeated edges.
*/


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> sets(n, 0);
        for (int i = 0; i < n; i++)
            sets[i] = i;
        vector<int> sizes(n, 1);

        int count = n;
        for (int j = 0; j < edges.size(); j++) {
            int x = find(edges[j][0], sets);
            int y = find(edges[j][1], sets);

            if (x != y) {
                // union by size
                if (sizes[x] < sizes[y]) {
                    sizes[y] += sizes[x];
                    sets[x] = y;
                }
                else {
                    sizes[x] += sizes[y];
                    sets[y] = x;
                }
                count -= 1;
            }
        }
        return count;
    }

    int find(int i, vector<int>& sets) {
        if (sets[i] != i)
            sets[i] = find(sets[i], sets); // path compression
        return sets[i];
    }
};