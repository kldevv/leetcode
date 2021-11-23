/*
Number: ˙77
Topic: Combinations
Date: 2021/10/19
Rate: Medium
https://leetcode.com/problems/combinations/

Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.

Constraints:
    * 1 <= n <= 20
    * 1 <= k <= n
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        vector<int> result;
        dfs(1, n, k, result, results);
        return results;
    }

    void dfs(int start, int end, int k, vector<int>& result, vector<vector<int>>& results) {
        if (result.size() == k) {
            results.push_back(result);
            return;
        }

        for (int i = start; i <= end; i++) {
            result.push_back(i);
            dfs(i+1, end, k, result, results);
            result.pop_back();

            if (result.size()+(end-i+2) < k)
                break;
        }
    }
};