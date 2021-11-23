/*
Number: 216
Topic: Combination Sum III
Date: 2021/6/23
Rate: Medium
https://leetcode.com/problems/combination-sum-iii/

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

* Only numbers 1 through 9 are used.
* Each number is used at most once.

Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

Constraints:
* 2 <= k <= 9
* 1 <= n <= 60

*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k >= n)
            // 1~9 choose k 不重複，當 k > n 時不可能有答案
            return {};

        vector<vector<int>> out;
        vector<int> combs(k, 0);
        int i = 0, sum = 0;

        // build combination and backtrack
        while (i >= 0) {
            combs[i]++;
            // 計算目前的 sum
            sum += 1;
            if (combs[i] == 10) {
                // 超出範圍了，而且要把最後一位數的 sum 檢掉
                sum -= combs[i--];
            } else if (i == k-1 && sum == n) {
                // 滿足條件就 push back
                out.push_back(combs);
            } else if (i != k-1) {
                i++;
                combs[i] = combs[i-1];
                // 填滿下一位數的底，那也要把 sum 加入進去
                sum += combs[i];
            }
        }
        return out;
    }
};