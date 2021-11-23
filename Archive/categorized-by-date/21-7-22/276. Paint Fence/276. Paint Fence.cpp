/*
Number: 276
Topic: Paint Fence
Date: 2021/7/22
Rate: Medium
https://leetcode.com/problems/paint-fence/

You are painting a fence of n posts with k different colors. You must paint the posts following these rules:

* Every post must be painted exactly one color.
* There cannot be three or more consecutive posts with the same color.
Given the two integers n and k, return the number of ways you can paint the fence.

Constraints:
* 1 <= n <= 50
* 1 <= k <= 105
* The testcases are generated such that the answer is in the range [0, 231 - 1] for the given n and k.
*/

class Solution {
public:
    int numWays(int n, int k) {
        if (!n)
            return 0;
        if (n == 1)
            return k;
        if (n == 2)
            return k*k;

        int prePreOptions = k;
        int preOptions = k*k;

        for (int i = 2; i < n; i++) {
            int temp = preOptions;
            preOptions = (preOptions + prePreOptions) * (k-1);
            prePreOptions = temp;
        }
        return preOptions;
    }
};