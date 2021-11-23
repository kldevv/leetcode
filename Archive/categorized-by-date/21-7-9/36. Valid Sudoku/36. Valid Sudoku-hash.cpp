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
        unordered_set<string> seen;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                string num = to_string(board[i][j]);
                string col = num + " in row " + to_string(i);
                string row = num + " in col " + to_string(j);
                string block = num + " in block " + to_string(i/3) + "-" + to_string(j/3);
                if (seen.count(col) || seen.count(row) || seen.count(block))
                    return false;
                seen.insert(col), seen.insert(row), seen.insert(block);
            }
        }
        return true;
    }
};