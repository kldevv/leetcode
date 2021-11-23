/*
Number: 529
Topic: Minesweeper
Date: 2021/9/9
Rate: Medium
https://leetcode.com/problems/minesweeper/

Let's play the minesweeper game (Wikipedia, online game)!

You are given an m x n char matrix board representing the game board where:
    * 'M' represents an unrevealed mine,
    * 'E' represents an unrevealed empty square,
    * 'B' represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
    * digit ('1' to '8') represents how many mines are adjacent to this revealed square, and
    * 'X' represents a revealed mine.
You are also given an integer array click where click = [clickr, clickc] represents the next click position among all the unrevealed squares ('M' or 'E').

Return the board after revealing this position according to the following rules:
    * If a mine 'M' is revealed, then the game is over. You should change it to 'X'.
    * If an empty square 'E' with no adjacent mines is revealed, then change it to a revealed blank 'B' and all of its adjacent unrevealed squares should be revealed recursively.
    * If an empty square 'E' with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.

Constraints:
    * m == board.length
    * n == board[i].length
    * 1 <= m, n <= 50
    * board[i][j] is either 'M', 'E', 'B', or a digit from '1' to '8'.
    * click.length == 2
    * 0 <= clickr < m
    * 0 <= clickc < n
    * board[clickr][clickc] is either 'M' or 'E'.
*/

class Solution {
private:
    vector<vector<int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i = click[0];
        int j = click[1];
        if (board[i][j] == 'M' || board[i][j] == 'X')
            board[i][j] = 'X';
        else if (board[i][j] == 'E')
            updateBoard(board, i, j);

        return board;
    }

    void updateBoard(vector<vector<char>>& board, int i, int j) {
        int m = board.size();
        int n = (m) ? board[0].size() : 0;

        vector<vector<int>> process;
        int bomb = 0;

        for (vector<int>& dir : direction) {
            int ii = i + dir[0];
            int jj = j + dir[1];
            if (ii < 0 || ii >= m || jj < 0 || jj >= n)
                continue;

            if (board[ii][jj] == 'M' || board[ii][jj] == 'X')
                bomb += 1;
            else if (board[ii][jj] == 'E')
                process.push_back({ii, jj});
        }

        if (bomb == 0) {
            board[i][j] = 'B';
            for (vector<int> next : process) {
                updateBoard(board, next[0], next[1]);
            }
        }
        else {
            board[i][j] = (char)(bomb + '0');
        }
    }
};