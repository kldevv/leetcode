/*
Number: 201
Topic: Bitwise AND of Numbers Range
Date: 2021/6/28
Rate: Medium
https://leetcode.com/problems/bitwise-and-of-numbers-range/

Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

Constraints:
* 0 <= left <= right <= 231 - 1

*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // 如果 left != right，那麼最後一個 digit 絕對不可以能 match，我們於是把最後一個 bit 拿掉，再考慮前面的 subproblem！
        return (left == right) ? left : (rangeBitwiseAnd(left>>1, right>>1) << 1);
    }
};