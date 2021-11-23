/*
Number: 935
Topic: Knight Dialer
Date: 2021/11/5
Rate: Medium
https://leetcode.com/problems/knight-dialer/

The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagaram:

A chess knight can move as indicated in the chess diagram below:

We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).

Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 109 + 7.

Constraints:
    * 1 <= n <= 5000
*/

class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> transform = {
            {4, 6},
            {6, 8},
            {7, 9}, 
            {4, 8}, 
            {3, 9, 0}, 
            {}, 
            {1, 7, 0}, 
            {2, 6}, 
            {1, 3}, 
            {4, 2}
        };
        const int MOD = 1e9 + 7;
        vector<long> matrixA(10, 1);
        vector<long> matrixB(10, 0);
        for (int step = 1; step < n; step++) {
            for (int digit = 0; digit < 10; digit++) {
                matrixB[digit] = 0;
                for (int adjacent : transform[digit]) {
                    matrixB[digit] += matrixA[adjacent];
                }
                matrixB[digit] %= MOD;
            }
            swap(matrixA, matrixB);
        }
        int result = 0;
        for (int num : matrixA) {
            result += num;
            result %= MOD;
        }
        return result;
    }
};
