/*
Number: 89
Topic: Gray Code
Date: 2021/6/30
Rate: Easy
https://leetcode.com/problems/gray-code/

An n-bit gray code sequence is a sequence of 2n integers where:

* Every integer is in the inclusive range [0, 2n - 1],
* The first integer is 0,
* An integer appears no more than once in the sequence,
* The binary representation of every pair of adjacent integers differs by exactly one bit, and
* The binary representation of the first and last integers differs by exactly one bit.

Given an integer n, return any valid n-bit gray code sequence.

Constraints:
* 1 <= n <= 16

*/

class Solution {
public:
    vector<int> grayCode(int n) {
        // tc: O(2^n)
        vector<int> out;
        out.push_back(0);

        for (int i = 0; i < n; i++) {
            int size = out.size();
            for (int j = size-1; j >= 0; j--) {
                out.push_back(out[j] | 1 << i);
            }
        }
        return out;
    }

// 0 000
// 1 001
// 3 011
// 2 010

// 6 110
// 7 111
// 5 101
// 4 100

// n = 3 時，就是把 n = 2 的元素拿出來，加上最前面的 1 在放回去而以
// 因為 n = 2 時，已經把兩個 bit 可以表現的組合都表現完了，而且有頭尾只差一的特性，用對稱的方式，前面加 1，新的數列也會有這種只差一個 1，而且頭尾差 1 的特性
};