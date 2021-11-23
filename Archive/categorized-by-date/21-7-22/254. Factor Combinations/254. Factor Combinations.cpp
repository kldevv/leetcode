/*
Number: 254
Topic: Factor Combinations
Date: 2021/7/22
Rate: Medium
https://leetcode.com/problems/factor-combinations/

Numbers can be regarded as the product of their factors.

* For example, 8 = 2 x 2 x 2 = 2 x 4.

Given an integer n, return all possible combinations of its factors. You may return the answer in any order.

Note that the factors should be in the range [2, n - 1].

Constraints:
* 1 <= n <= 107
*/

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> combs;
        vector<vector<int>> out;

        getFactors(n, 2, combs, out);
        return out;
    }

    void getFactors(int n, int start, vector<int>& combs, vector<vector<int>>& out) {
        for (int i = start; i * i <= n; i++) {
            if (!(n % i)) {
                combs.push_back(i);
                combs.push_back(n/i);
                out.push_back(combs);
                combs.pop_back();
                getFactors(n/i, i, combs, out);
                combs.pop_back();
            }
        }
    }
};