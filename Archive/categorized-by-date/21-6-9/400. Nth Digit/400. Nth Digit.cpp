/*
Number: 400
Topic: Nth Digit
Date: 2021/6/9
Rate: Medium
https://leetcode.com/problems/nth-digit/

Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].

Constraints:
* 1 <= n <= 231 - 1

*/
class Solution {
public:
    int findNthDigit(int n) {
        // 先計算有多少個 digit
        long base = 9
        int digits = 1;
        // 如果 n 的數量比目前 digit 有的位數還多，就進入到下一個 digit
        while (n - base * digits > 0) {
            n -= base * digits;
            base *= 10;
            digits ++;
        }
        // 看看目前的 n 是目前 digit 的第幾個數字的第幾個字母
        int index = (n - 1) % digits;
        // index << (n-1) 因為，例如當 digit = 2 時， 2th 其實是第一個數字的第二個字母，但是這邊 offset 如果不減 1 就會被設成 0，變成下一個數字的第一個
        // n-1 mode x，的功用就是讓剛好整除的數字可以是最大的，而不能整除餘 1 最小的變成0，
        int offset = (n - 1) / digits;
        // offset << (n-1) 因為 n < 10 時，start 從 1 開始，n >= 10 時，start 從 0(10, 100, 1000) 開始 
        long start = pow(10, digits - 1);

        return to_string(start + offset)[index] - '0';
    }
};