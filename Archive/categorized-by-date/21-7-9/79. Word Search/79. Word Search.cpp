/*
Number: 79
Topic: Word Search
Date: 2021/7/9
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
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = (m) ? board[0].size() : 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (exist(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, int i, int j, const string& word, int pos) {
        int m = board.size();
        int n = (m) ? board[0].size() : 0;
        int t = word.size();

        if (pos == t)
            return true;

        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        if (board[i][j] != word[pos])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';
        bool out = (exist(board, i+1, j, word, pos+1) || exist(board, i-1, j, word, pos+1) || exist(board, i, j+1, word, pos+1) || exist(board, i, j-1, word, pos+1));
        board[i][j] = temp;
        return out;
    }
};