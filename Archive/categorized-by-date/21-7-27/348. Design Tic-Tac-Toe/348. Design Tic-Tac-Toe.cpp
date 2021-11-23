/*
Number: 348
Topic: Design Tic-Tac-Toe
Date: 2021/7/26
Rate: Medium
https://leetcode.com/problems/design-tic-tac-toe/

Assume the following rules are for the tic-tac-toe game on an n x n board between two players:

1. A move is guaranteed to be valid and is placed on an empty block.
2. Once a winning condition is reached, no more moves are allowed.
3. A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.

Implement the TicTacToe class:
* TicTacToe(int n) Initializes the object the size of the board n.
* int move(int row, int col, int player) Indicates that player with id player plays at the cell (row, col) of the board. The move is guaranteed to be a valid move.

Follow up:
Could you do better than O(n2) per move() operation?

Constraints:
* 2 <= n <= 100
* player is 1 or 2.
* 0 <= row, col < n
* (row, col) are unique for each different call to move.
* At most n2 calls will be made to move.
*/

class TicTacToe {
private:
    vector<int> row;
    vector<int> col;
    vector<int> diagonal;
    int n;

    void setValue(int i , int j, int increment) {
        this->row[i] += increment;
        this->col[j] += increment;
        
        if (i == j) {
            diagonal[0] += increment;
        }
        if (i+j == this->n-1) {
            diagonal[1] += increment;
        }
    }

    int whoWin(int i, int j) {
        if (row[i] == n || col[j] == n || diagonal[0] == n || diagonal[1] == n)
            return 1;
        if (row[i] == -n || col[j] == -n || diagonal[0] == -n || diagonal[1] == -n)
            return 2;
        return 0;
    }

public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->row = vector<int>(n, 0);
        this->col = vector<int>(n, 0);
        this->diagonal = vector<int>(2, 0);
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (player == 1)
            setValue(row, col, 1);
        else
            setValue(row, col, -1);
        return whoWin(row, col);
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
