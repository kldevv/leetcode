/*
Number: 52
Topic: N-Queens II
Date: 2021/7/7
Rate: Hard
https://leetcode.com/problems/n-queens-ii/

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Constraints:
* 1 <= n <= 9

*/


class Solution {
public:
    int totalNQueens(int n) {
        // 一個 n X n 的棋盤共有 2*n-1 條 45 度對角線和 2*n-1 條 135 度對角線
        // traverse 棋盤上的每一格，如果這個 col 和對角線都沒有 Queen，就可以擺 Queen，然後到下一個 row
        vector<int> diagonal45(2*n - 1, 1);
        vector<int> diagonal135(2*n - 1, 1);
        vector<int> straight(n, 1);

        int out = 0;
        totalNQueens(n, 0, straight, diagonal45, diagonal135, out);
        return out;
    }

    void totalNQueens(const int& n, int j, vector<int>& straight, vector<int>& diagonal45, vector<int>& diagonal135, int& out) {
        if (j == n) {
            out += 1;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (straight[i] && diagonal45[i+j] && diagonal135[n-1+i-j]) {
                straight[i] = 0;
                diagonal45[i+j] = 0;
                diagonal135[n-1+i-j] = 0;

                totalNQueens(n, j+1, straight, diagonal45, diagonal135, out);

                straight[i] = 1;
                diagonal45[i+j] = 1;
                diagonal135[n-1+i-j] = 1;
            }
        }
    }

};