/*
Number: 37
Topic: Sudoku Solver
Date: 2021/7/9
Rate: Hard
https://leetcode.com/problems/sudoku-solver/

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

1. Each row must contain the digits 1-9 without repetition.
2. Each column must contain the digits 1-9 without repetition.
3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

The '.' character indicates empty cells.

Constraints:
* board.length == 9
* board[i].length == 9
* board[i][j] is a digit or '.'.
* It is guaranteed that the input board has only one solution.

*/

class Solution {
public:
    const int M = 9; // column length
    const int N = 9; // row length
    const int SQUARE = 3; // length square block

    void solveSudoku(vector<vector<char>>& board) {
        // initial 3-section array (0-8 for col / 9-17 for row / 17-26 for block)
        vector<vector<int>> seen(M+N+((M/SQUARE)*(N/SQUARE)), vector<int>(9, 0));
        
        // store the current status
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = i/SQUARE * SQUARE + j/SQUARE;
                    seen[i][num] = seen[M+j][num] = seen[M+N+k][num] = 1;
                }
            }
        }
        solveSudoku(board, 0, 0, seen);
    }

    bool solveSudoku(vector<vector<char>>& board, int i, int j, vector<vector<int>>& seen) {
        if (j == N)
            return solveSudoku(board, i+1, 0, seen);    // reach the end of the column, move to next row.
        if (i == M)
            return true;    // finish all the process, return.
        if (board[i][j] != '.')
            return solveSudoku(board, i, j+1, seen);    // skip numbered space

        int k = i/SQUARE * SQUARE + j/SQUARE;   // get the block identity
        for (int num = 0; num < 9; num++) {     // try number 0-8
            // validity check
            if (seen[i][num] || seen[M+j][num] || seen[M+N+k][num])
                continue;
            // modify status
            seen[i][num] = seen[M+j][num] = seen[M+N+k][num] = 1;
            board[i][j] = num + 1 + '0';
            if (solveSudoku(board, i, j+1, seen))   // recursive call to the next move
                return true;

            // return to the initial status
            seen[i][num] = seen[M+j][num] = seen[M+N+k][num] = 0;
            board[i][j] = '.';
        }
        // fail to find any number for this space
        return false;
    }
};