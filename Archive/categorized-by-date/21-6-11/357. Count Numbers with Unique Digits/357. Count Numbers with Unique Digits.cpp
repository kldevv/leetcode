/*
Number: 357
Topic: Count Numbers with Unique Digits
Date: 2021/6/11
Rate: Medium
https://leetcode.com/problems/count-numbers-with-unique-digits/

Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.

Constraints:
* 0 <= n <= 8

*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (!n)
            return 1;
        if (n == 1)
            return 10;
        // 第一個數 (1-9 不可為零) * 剩下的位數 (9*8*... 以此類推因為又把零加回來所以從 9 開始) + 少一個位數的
        return 9 * permutation(9, n-1) + countNumbersWithUniqueDigits(n-1);
    }

    int permutation(int n, int k) {
        int out = 1, base = n-k;
        for (int i = n; i > base; i--) {
            out *= i;
        }
        return out;
    }
};