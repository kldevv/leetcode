/*
Number: 338
Topic: Counting Bits
Date: 2021/6/30
Rate: Easy
https://leetcode.com/problems/counting-bits/

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Follow up:
* It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
* Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?

Constraints:
* 0 <= n <= 10^5

*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> out(n+1, 0);
        // dp[i] 存的是數字 i 時有幾個 1
        // i & i-1 拿到最後一個 bit
        // 我們知道 i & i-1 時有幾個 1，因為我只是把它拿掉最後一個 1 ，所以加 1 就可以
        for (int i = 1; i <= n; i++) {
            out[i] = out[i & (i-1)] + 1;
        }

        return out;
    }
};