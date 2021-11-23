'''
Number: 36
Topic: Valid Sudoku
Date: 2021/10/14
Rate: Medium
https://leetcode.com/problems/valid-sudoku/

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
    * Each row must contain the digits 1-9 without repetition.
    * Each column must contain the digits 1-9 without repetition.
    * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:
    * A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    * Only the filled cells need to be validated according to the mentioned rules.


Constraints:
    * board.length == 9
    * board[i].length == 9
    * board[i][j] is a digit 1-9 or '.'.
'''

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        m = len(board)
        n = len(board[0])

        rows = [0] * m
        cols = [0] * n
        sqrt = [0] * (m // 3) * (n // 3)
        for i in range(m):
            for j in range(n):
                if board[i][j] != '.':
                    num = int(board[i][j])
                    if (rows[i] >> num) & 1 or (cols[j] >> num) & 1 or (sqrt[i // 3 * 3 + j // 3] >> num) & 1:
                        return False
                    rows[i] |= (1 << num)
                    cols[j] |= (1 << num)
                    sqrt[i // 3 * 3 + j // 3] |= (1 << num)
        return True
