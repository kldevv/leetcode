/*
Number: 130
Topic: Surrounded Regions
Date: 2021/11/7
Rate: Medium
https://leetcode.com/problems/surrounded-regions/

Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Constraints:
    * m == board.length
    * n == board[i].length
    * 1 <= m, n <= 200
    * board[i][j] is 'X' or 'O'.
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (!board.size() || !board[0].size())
            return;
        int rowLen = board.size();
        int colLen = board[0].size();
        
        for (int row = 0; row < rowLen; row++) {
            mark(board, row, 0, 'O', 'E');
            mark(board, row, colLen-1, 'O', 'E');
        }
        for (int col = 0; col < colLen; col++) {
            mark(board, 0, col, 'O', 'E');
            mark(board, rowLen-1, col, 'O', 'E');
        }
        for (int row = 0; row < rowLen; row++) {
            for (int col = 0; col < colLen; col++) {
                board[row][col] = (board[row][col] == 'O' || board[row][col] == 'X') ? 'X' : 'O';
            }
        }
    }

    void mark(vector<vector<char>>& board, int row, int col, char ori, char dest) {
        if (board[row][col] != ori)
            return;

        board[row][col] = dest;
        if (row+1 < board.size())
            mark(board, row+1, col, ori, dest);
        if (row-1 >= 0)
            mark(board, row-1, col, ori, dest);
        if (col+1 < board[0].size())
            mark(board, row, col+1, ori, dest);
        if (col-1 >= 0)
            mark(board, row, col-1, ori, dest);
    }
};
