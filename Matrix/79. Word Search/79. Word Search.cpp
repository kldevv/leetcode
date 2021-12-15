/*
Number: 79
Topic: Word Search
Date: 2021/12/5
Rate: Medium
https://leetcode.com/problems/word-search/

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Constraints:
    * m == board.length
    * n = board[i].length
    * 1 <= m, n <= 6
    * 1 <= word.length <= 15
    * board and word consists of only lowercase and uppercase English letters.


Follow up: Could you use search pruning to make your solution faster with a larger board?
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
   private:
    string word;
    vector<vector<char>> board;
    int m;
    int n;
    vector<vector<int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}};

   public:
    bool
    exist(vector<vector<char>>& board, string word) {
        /*
        Edge cases:
            if (word = "")
                return true;
            if (board.empty())
                return false;

        for cells in board:
            if (dfs())
                return true
        return false
        */
        if (word.empty())
            return true;
        if (board.size() == 0 || board[0].empty())
            return false;

        this->board = board;
        this->word = word;
        this->m = board.size();
        this->n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (exist(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool exist(int i, int j, int s) {
        /*
        if (s == word.size())
            return true;
        if (word[s] != board[i]):
            return false;

        oldChar = board[i];
        board[i] = '*'
        for dir : directions:
            >> recur (i + dir, s + 1)
        board[i] = oldChar
        return false;
        */
        if (s == word.size())
            return true;
        if (i < 0 || i >= m || j < 0 || j >= n || word[s] != board[i][j]) {
            return false;
        }

        char oldChar = board[i][j];
        board[i][j] = '*';
        bool found = false;
        for (vector<int>& dir : directions) {
            int ii = i + dir[0];
            int jj = j + dir[1];
            if (exist(ii, jj, s + 1)) {
                found = true;
                break;
            }
        }
        board[i][j] = oldChar;
        return found;
    }
};