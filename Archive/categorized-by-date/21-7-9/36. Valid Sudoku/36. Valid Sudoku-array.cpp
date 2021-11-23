/*
Number: 36
Topic: Valid Sudoku
Date: 2021/7/9
Rate: Medium
https://leetcode.com/problems/valid-sudoku/


Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

1. Each row must contain the digits 1-9 without repetition.
2. Each column must contain the digits 1-9 without repetition.
3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:
* A Sudoku board (partially filled) could be valid but is not necessarily solvable.
* Only the filled cells need to be validated according to the mentioned rules.


Constraints:
* board.length == 9
* board[i].length == 9
* board[i][j] is a digit or '.'.

*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> seen(9*3, vector<int>(9, 0));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = i/3*3 + j/3;

                    if (seen[i][num]++ || seen[9+j][num]++ || seen[18+k][num]++)
                        return false;
                }
            }
        }
        return true;
    }
};