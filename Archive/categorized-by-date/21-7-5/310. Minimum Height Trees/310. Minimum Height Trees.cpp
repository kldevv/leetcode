/*
Number: 310
Topic: Minimum Height Trees
Date: 2021/7/5
Rate: Medium
https://leetcode.com/problems/minimum-height-trees/

A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

Constraints:
* 1 <= n <= 2 * 10^4
* edges.length == n - 1
* 0 <= ai, bi < n
* ai != bi
* All the pairs (ai, bi) are distinct.
* The given input is guaranteed to be a tree and there will be no repeated edges.

*/


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (edges.empty())
            return {0};

        // 先建立 adjacent 表和 degree 表
        vector<vector<int>> adjacent(n);
        vector<int> degree(n, 0);
        for (auto& edge : edges) {
            adjacent[edge[0]].push_back(edge[1]);
            degree[edge[0]]++;
            adjacent[edge[1]].push_back(edge[0]);
            degree[edge[1]]++;
        }

        // 從 leaf 開始找
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1)
                    q.push(i);
        }

        // 找到只剩下最後兩個或一個 node
        while (n > 2) {
            n -= q.size();

            // leaf 做 topological sort
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                int idx = q.front();
                q.pop();
                for (int j = 0; j < adjacent[idx].size(); j++) {
                    if (--degree[adjacent[idx][j]] == 1)
                        q.push(adjacent[idx][j]);
                }
            }
        }

        // 剩下最後的 leaf 就是答案
        vector<int> out;
        while (!q.empty()) {
            out.push_back(q.front());
            q.pop();
        }

        return out;
    }


};