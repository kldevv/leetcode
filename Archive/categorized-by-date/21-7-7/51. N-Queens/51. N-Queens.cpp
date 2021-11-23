/*
Number: 51
Topic: N-Queens
Date: 2021/7/7
Rate: Hard
https://leetcode.com/problems/n-queens/

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Constraints:
* 1 <= n <= 9

*/


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // 一個 n X n 的棋盤共有 2*n-1 條 45 度對角線和 2*n-1 條 135 度對角線
        // traverse 棋盤上的每一格，如果這個 col 和對角線都沒有 Queen，就可以擺 Queen，然後到下一個 row
        vector<int> diagonal45(2*n - 1, 1);
        vector<int> diagonal135(2*n - 1, 1);
        vector<int> straight(n, 1);
        
        vector<string> board(n, string(n, '.'));

        vector<vector<string>> out;
        solveNQueens(board, 0, straight, diagonal45, diagonal135, out);
        return out;
    }

    void solveNQueens(vector<string>& board, int j, vector<int>& straight, vector<int>& diagonal45, vector<int>& diagonal135, vector<vector<string>>& out) {
        int n = board.size();
        if (j == n) {
            out.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (straight[i] && diagonal45[i+j] && diagonal135[n-1+i-j]) {
                board[j][i] = 'Q';
                straight[i] = 0;
                diagonal45[i+j] = 0;
                diagonal135[n-1+i-j] = 0;

                solveNQueens(board, j+1, straight, diagonal45, diagonal135, out);

                board[j][i] = '.';
                straight[i] = 1;
                diagonal45[i+j] = 1;
                diagonal135[n-1+i-j] = 1;
            }
        }
    }

};