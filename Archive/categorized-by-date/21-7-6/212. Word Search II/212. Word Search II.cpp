/*
Number: 212
Topic: Word Search II
Date: 2021/7/6
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
class TrieNode {
public:
    bool endOfWord;
    vector<TrieNode*> children;
    
    TrieNode() {
        endOfWord = false;
        children = vector<TrieNode*>(26, nullptr);
    }

    ~TrieNode() {
        for (auto child : children) {
            delete child;
        }
    }
};

class Trie {
public:
    Trie() {
        this->head = new TrieNode();
    }

    ~Trie() {
        delete head;
    }

    TrieNode* getRoot() {return head;}

    void addWord(string s) {
        TrieNode* curNode = head;

        for (const char& c : s) {
            int idx = c - 'a';
            if (!(curNode->children[idx])) {
                curNode->children[idx] = new TrieNode();
            }
            curNode = curNode->children[idx];
        }
        curNode->endOfWord = true;
    }

    void addWord(const vector<string>& words) {
        for (const string& s : words) {
            addWord(s);
        }
    }

private:
    TrieNode* head;
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* dict = new Trie();
        dict->addWord(words);
        TrieNode* curNode = dict->getRoot();

        int m = board.size();
        int n = (m) ? board[0].size() : 0;

        unordered_set<string> tempOut;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                findWords(board, i, j, curNode, "", tempOut);
            }
        }

        vector<string> out;
        for (string s : tempOut) {
            out.push_back(move(s));
        }
        return out;
    }

    void findWords(vector<vector<char>>& board, int i, int j, TrieNode* curNode, string word, unordered_set<string>& tempOut) {
        int m = board.size();
        int n = (m) ? board[0].size() : 0;

        if (i >= m || i < 0 || j >= n || j < 0)
            return;

        if (board[i][j] == '*')
            return;

        int idx = board[i][j] - 'a';
        if (!(curNode->children[idx]))
            return;

        word += (char)(idx + 'a');
        curNode = curNode->children[idx];
        if (curNode->endOfWord) {
            tempOut.insert(word);
        }

        board[i][j] = '*';
        findWords(board, i+1, j, curNode, word, tempOut);
        findWords(board, i-1, j, curNode, word, tempOut);
        findWords(board, i, j+1, curNode, word, tempOut);
        findWords(board, i, j-1, curNode, word, tempOut);
        board[i][j] = (char)(idx + 'a');
    }

};