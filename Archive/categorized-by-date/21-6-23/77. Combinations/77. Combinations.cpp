/*
Number: 77
Topic: Combinations
Date: 2021/6/23
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
        vector<vector<int>> out;
        // 用來承裝每次的 combination
        vector<int> combs(k, 0);
        int i = 0;

        while (i >= 0) {
            combs[i]++;
            // 如果這個位數大於 n 了，就往前一個位數跑
            if (combs[i] > n) {
                i--;
            // 所有位數都滿足了，而且也沒有超過 n 就是其中一個 combination
            } else if (i == k-1) {
                out.push_back(combs);
            // 把後面的位數的底墊高，跟前面一樣，這樣就不會有重複的
            } else {
                i++;
                combs[i] = combs[i-1];
            }
        }
        return out;
    }
};