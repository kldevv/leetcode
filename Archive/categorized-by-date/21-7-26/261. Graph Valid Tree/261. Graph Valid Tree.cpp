/*
Number: 261
Topic: Graph Valid Tree
Date: 2021/7/26
Rate: Medium
https://leetcode.com/problems/graph-valid-tree/

You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.

Constraints:
* 1 <= 2000 <= n
* 0 <= edges.length <= 5000
* edges[i].length == 2
* 0 <= ai, bi < n
* ai != bi
* There are no self-loops or repeated edges.
*/


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> sets(n, -1);
        for (const vector<int>& edge : edges) {
            int x = find(edge[0], sets);
            int y = find(edge[1], sets);

            if (x == y)
                return false;

            sets[x] = y;
        }
        return edges.size() == n-1;
    }

    int find(int i, vector<int>& sets) {
        if (sets[i] == -1)
            return i;
        sets[i] = find(sets[i], sets);
        return sets[i];
    }
};