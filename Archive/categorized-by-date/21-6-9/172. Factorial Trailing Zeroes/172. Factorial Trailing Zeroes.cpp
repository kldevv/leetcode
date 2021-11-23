/*
Number: 306
Topic: Factorial Trailing Zeroes
Date: 2021/6/9
Rate: Easy
https://leetcode.com/problems/factorial-trailing-zeroes/

Given an integer n, return the number of trailing zeroes in n!.

Follow up: Could you write a solution that works in logarithmic time complexity?

Constraints:
* 0 <= n <= 10^4

*/
class Solution {
public:
    int trailingZeroes(int n) {
        int out = 0;
        for (int i = 5; i <= n; i *= 5) {
            // 只有 factor 10 會有 trailing zero
            // 而 10 的 factor 是 5 跟 2，我們有無窮無盡的 2，而 5 比較稀少
            // 所有就看到 n 為止有幾個 5 ，注意 25 = 5^5 有兩個五 5 的 power 都有更多的 5
            out += n/i;
        }
        return out;
        // return (n == 0) ? 0 : n/5 + trailingZeros(n/5); 一樣意思
    }
};