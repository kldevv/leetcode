/*
Number: 1799
Topic: Maximize Score After N Operations
Date: 2021/9/30
Rate: Hard
https://leetcode.com/problems/maximize-score-after-n-operations/

You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

In the ith operation (1-indexed), you will:

    * Choose two elements, x and y.
    * Receive a score of i * gcd(x, y).
    * Remove x and y from nums.

Return the maximum score you can receive after performing n operations.

The function gcd(x, y) is the greatest common divisor of x and y.

Constraints:
    * 1 <= n <= 7
    * nums.length == 2 * n
    * 1 <= nums[i] <= 106
*/

class Solution {
private:
    vector<vector<int>> gcdMemo;
    vector<int> maskMemo;
    int n;
    int m;
public:
    int maxScore(vector<int>& nums) {
        gcdMemo = vector<vector<int>> (14, vector<int>(14, 0));
        maskMemo = vector<int>(1 << 14, 0);
        this->n = nums.size();
        this->m = n / 2;
        return dp(nums, 1, 0);
    }

    int dp(vector<int>& nums, int op, int mask) {
        if (op > m)
            return 0;
        if (maskMemo[mask])
            return maskMemo[mask];

        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1)
                continue;
            for (int j = i+1; j < n; j++) {
                if ((mask >> j) & 1)
                    continue;
                int newMask = mask | (1 << i) | (1 << j);
                int score = gcd(nums, i, j) * op + dp(nums, op+1, newMask);
                maskMemo[mask] = max(maskMemo[mask], score);
            }
        }
        return maskMemo[mask];
    }

    int gcd(vector<int>& nums, int i, int j) {
        if (gcdMemo[i][j] != 0)
            return gcdMemo[i][j];
        else {
            gcdMemo[i][j] = __gcd(nums[i], nums[j]);
            return gcdMemo[i][j];
        }

    }
};