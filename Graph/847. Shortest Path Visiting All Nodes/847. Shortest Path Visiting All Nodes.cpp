/*
Number: 847
Topic: Shortest Path Visiting All Nodes
Date: 2021/9/4
Rate: Medium
https://leetcode.com/problems/path-with-maximum-minimum-value/

You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

Constraints:
    * n == graph.length
    * 1 <= n <= 12
    * 0 <= graph[i].length < n
    * graph[i] does not contain i.
    * If graph[a] contains b, then graph[b] contains a.
    * The input graph is always connected.
*/

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<unordered_set<int>> progress(n, unordered_set<int>());

        queue<tuple<int, int, int>> q;
        for (int i = 0; i < n; i++)
            q.emplace(i, (1 << i), 0);
        

        while (q.size()) {
            auto [val, bitMask, step] = q.front();
            q.pop();

            if (bitMask == ((1 << n) - 1))
                return step;

            for (int nextVal: graph[val]) {
                int nextBitMask = (bitMask | (1 << nextVal));
                if (!progress[nextVal].count(nextBitMask)) {
                    progress[nextVal].insert(nextBitMask);
                    q.emplace(nextVal, nextBitMask, step+1);
                }
            }
        }
        return -1;
    }
};