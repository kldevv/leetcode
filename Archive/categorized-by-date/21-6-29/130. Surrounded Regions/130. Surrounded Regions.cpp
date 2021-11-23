/*
Number: 130
Topic: Surrounded Regions
Date: 2021/6/29
Rate: Medium
https://leetcode.com/problems/surrounded-regions/

Given an m x n matrix board containing 'X' and 'O', capture all regions surrounded by 'X'.

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
        int m = board.size();
        int n = (m) ? board[0].size() : 0;

        for (int j = m-1; j <= m; j++) {
            for (int i = 0; i < n; i++) {
                if (board[j%m][i] == 'O')
                    virusFlip(board, j%m, i, 'O', '1');
            }
        }

        for (int i = n-1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[j][i%n] == 'O')
                    virusFlip(board, j, i%n, 'O', '1');
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (board[j][i] == 'O')
                    virusFlip(board, j, i, 'O', 'X');
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (board[j][i] == '1')
                    virusFlip(board, j, i, '1', 'O');
            }
        }
    }

    void virusFlip(vector<vector<char>>& board, int j , int i, const char& from, const char& to) {
        int m = board.size();
        int n = (m) ? board[0].size() : 0;

        if (i < 0 || i >= n || j < 0 || j >= m || board[j][i] != from)
            return;

        board[j][i] = to;
        virusFlip(board, j+1, i, from, to);
        virusFlip(board, j-1, i, from, to);
        virusFlip(board, j, i+1, from, to);
        virusFlip(board, j, i-1, from, to);
    }

};