/*
Number: 289
Topic: Game of Life
Date: 2021/5/13
Rate: Medium
https://leetcode.com/problems/game-of-life/

According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

1. Any live cell with fewer than two live neighbors dies as if caused by under-population.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies, as if by over-population.
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

Constraints:
* m == board.length
* n == board[i].length
* 1 <= m, n <= 25
* board[i][j] is 0 or 1.


tc: O(mn)
sc: O(mn)
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
       vector<vector<int>> new_board(board);
       int m = board.size();
       int n = m ? board[0].size() : 0;

       // loop over 每一格
       for (int col = 0; col < m; col++) {
            for (int row = 0; row < n; row++) {
                int count = 0;
                for (int v = max(0, col-1); v <= min(col+1, m-1); v++) {
                    for (int h = max(0, row-1); h <= min(row+1, n-1); h++) {
                        // 檢查這一格四周的生存狀態
                        if ((v == col) && (h == row))
                            continue;
                        if (board[v][h] == 1)
                            count++;
                    } 
                }
                if (board[col][row]) {
                    if (count > 3)
                        new_board[col][row] = 0;
                    else if (count >= 2)
                        new_board[col][row] = 1;
                    else
                        new_board[col][row] = 0;
                }  else if (count == 3) {
                    new_board[col][row] = 1;
                }
            }
       }

       board = new_board;
    }
};