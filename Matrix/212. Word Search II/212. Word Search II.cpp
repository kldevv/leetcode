/*
Number: 212
Topic: Word Search II
Date: 2021/12/5
Rate: Hard
https://leetcode.com/problems/word-search-ii/

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Constraints:
    * m == board.length
    * n == board[i].length
    * 1 <= m, n <= 12
    * board[i][j] is a lowercase English letter.
    * 1 <= words.length <= 3 * 104
    * 1 <= words[i].length <= 10
    * words[i] consists of lowercase English letters.
    * All the strings of words are unique.
*/
#include <string>
#include <vector>

using namespace std;

class Node {
   public:
    bool isWord = 0;
    int childrenNum;
    int wordIdx = -1;
    Node* children[26];
    Node() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
            childrenNum = 0;
        }
    }
};

class Trie {
   public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(string s, int idx) {
        Node* iter = root;
        for (char c : s) {
            int i = c - 'a';
            if (iter->children[i] == nullptr) {
                iter->children[i] = new Node();
                iter->childrenNum += 1;
            }
            iter = iter->children[i];
        }
        iter->isWord = true;
        iter->wordIdx = idx;
    }
};

class Solution {
   private:
    vector<vector<int>> directions = {
        {1, 0},
        {0, -1},
        {0, 1},
        {-1, 0}};
    Trie* trie;
    vector<int> collected;
    int collectedNum;
    vector<vector<char>> board;
    int m;
    int n;

   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        /*
        DFS / backtracking

        Edges:
            words.empty() || board.empty() || board[0].empty()
                return {}

        for cells in board:
            findWords();


        return result
        */
        this->trie = new Trie();
        this->collected = vector(words.size(), 0);
        this->collectedNum = 0;
        for (int i = 0; i < words.size(); i++) {
            trie->insert(words[i], i);
        }

        this->board = board;
        this->m = board.size();
        this->n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                findWords(trie->root, i, j);
            }
        }

        vector<string> results;
        for (int i = 0; i < words.size(); i++) {
            if (collected[i] == 1) {
                results.push_back(words[i]);
            }
        }
        return results;
    }

    void findWords(Node* iter, int i, int j) {
        /*
        if (collectNum == wordIdx.size())
            return;
        if iter->isWord:
            collected[iter->wordIdx] = 1;
        if i, j out of bounds or i, j == '*' iter->children[board[i][j]] == nullptr
            return;

        oldChar = board[i][j]
        board[i][j] = '*'
        for dir : directions:
            findWord(next);
        board[i][j] = oldChar

        if (iter->children->childrenNum == 0)
            delete children->childrenNum;
            iter->childrenNum -= 1
        */
        if (collectedNum == collected.size()) {
            return;
        }
        if (iter->isWord) {
            collected[iter->wordIdx] = 1;
        }
        if (!isValid(i, j) || board[i][j] == '*' || iter->children[board[i][j] - 'a'] == nullptr) {
            return;
        }

        Node* iterChild = iter->children[board[i][j] - 'a'];
        char oldChar = board[i][j];
        board[i][j] = '*';
        for (vector<int> dir : directions) {
            int ii = i + dir[0];
            int jj = j + dir[1];
            findWords(iterChild, ii, jj);
        }
        board[i][j] = oldChar;

        // optimize by pruning the tree
        if (iterChild->childrenNum == 0) {
            iter->childrenNum -= 1;
            delete iter->children[board[i][j] - 'a'];
            iter->children[board[i][j] - 'a'] = nullptr;
        }
    }

    bool isValid(int i, int j) {
        return (i >= 0) &&
               (j >= 0) &&
               (i < m) &&
               (j < n);
    }
};