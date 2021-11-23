/*
Number: 79
Topic: Word Search
Date: 2021/5/11
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
*/

// time complexity O(m*n*4^l) where m*n the space of the board（從任一格開始）, l is the size of word（在最慘的情況下每一條路，都要找l-1）, 4 represents 4-direction-search in each cell（最慘情況下每次走一步都有四種可能因此4^l）
// space complexity O(1)

// Greedy Alogrithm，每次都只考慮這一步是否正確
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int y = 0; y < board.size(); y++) {
            for (int x = 0; x < board[0].size(); x++) {
                if (exist(board, x, y, word, 0)) return true;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, int x, int y, const string& word, int idx) {
        // 超出格子就是錯誤
        if ((y == board.size()) || (x == board[0].size()) || (y == -1) || (x == -1))
            return false;
        // 字不對也是錯誤
        if (board[y][x] != word[idx])
            return false;
        // 字對了，就先把這格變成別的符號，做一個記號，這樣才不會重複選到
        board[y][x] = '%';
        // 字都對了，就開始回傳 true，不用進入到下一步
        if (idx == word.size()-1)
            return true;
        // 這個字對了，開始尋找上下左右的格子
        bool out = (exist(board, x+1, y, word, idx+1)) ? true : 
                                ((exist(board, x, y+1, word, idx+1))) ? true :
                                ((exist(board, x-1, y, word, idx+1))) ? true :
                                ((exist(board, x, y-1, word, idx+1))) ? true : false;
        // 這一輪尋找結束之後要把字改回來
        board[y][x] = word[idx];
        return out;
    }
};

