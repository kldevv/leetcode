/*
Number: 399
Topic: Evaluate Division
Date: 2021/7/5
Rate: Medium
https://leetcode.com/problems/evaluate-division/


You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Constraints:
* 1 <= equations.length <= 20
* equations[i].length == 2
* 1 <= Ai.length, Bi.length <= 5
* values.length == equations.length
* 0.0 < values[i] <= 20.0
* 1 <= queries.length <= 20
* queries[i].length == 2
* 1 <= Cj.length, Dj.length <= 5
* Ai, Bi, Cj, Dj consist of lower case English letters and digits.

*/


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        buildGraph(equations, values, graph);

        vector<double> result(queries.size(), 0.0);
        for (int i = 0; i < queries.size(); i++) {
            string A = queries[i][0];
            string B = queries[i][1];

            unordered_set<string> visited;
            result[i] = getResult(A, B, graph, visited);
        }

        return result;
    }
private:
    void buildGraph(const vector<vector<string>>& equations, const vector<double>& values, unordered_map<string, unordered_map<string, double>>& graph) {
        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];
            graph[A][B] = val;
            graph[B][A] = 1/val;
        }
    }

    double getResult(string A, string B, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited) {
        if (!graph.count(A) || visited.count(A))
            return -1;

        if (graph[A].count(B))
            return graph[A][B];

        visited.insert(A);
        for (const auto& umap : graph[A]) {
            double out = getResult(umap.first, B, graph, visited);
            if (out != -1)
                return umap.second * out;
        }

        return -1;
    }
};