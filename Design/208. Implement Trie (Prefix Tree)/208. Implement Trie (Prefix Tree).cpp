/*
Number: 208
Topic: Implement Trie (Prefix Tree)
Date: 2021/12/4
Rate: Medium
https://leetcode.com/problems/implement-trie-prefix-tree/

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:
    * Trie() Initializes the trie object.
    * void insert(String word) Inserts the string word into the trie.
    * boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
    * boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

Constraints:
    * 1 <= word.length, prefix.length <= 2000
    * word and prefix consist only of lowercase English letters.
    * At most 3 * 104 calls in total will be made to insert, search, and startsWith.
*/

#include <string>
#include <vector>

using namespace std;

class Node {
   public:
    bool isWord;
    Node* children[26];

    Node() {
        isWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
   private:
    Node* root;

   public:
    Trie() {
        /*
        Node {
            children[26];
            isWord;
        }
        */
        root = new Node();
    }

    void insert(string word) {
        /*
        for c_idx in word:
            root = root->children[c_idx];
        root->isWord = true;
        */
        Node* iter = root;
        for (char c : word) {
            int idx = c - 'a';
            if (iter->children[idx] == nullptr) {
                iter->children[idx] = new Node();
            }
            iter = iter->children[idx];
        }
        iter->isWord = true;
    }

    bool search(string word) {
        /*
        for c_idx in word:
            if root->children[c_idx]:
                root = root->children[c_idx];
            else
                > false;
        > root->isWord
        */
        Node* iter = root;
        for (char c : word) {
            int idx = c - 'a';
            if (iter->children[idx] == nullptr) {
                return false;
            }
            iter = iter->children[idx];
        }
        return iter->isWord;
    }

    bool startsWith(string prefix) {
        /*
        for c_idx in word:
            if root->children[c_idx]:
                root = root->children[c_idx];
            else
                > false;
        > true;
        */
        Node* iter = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (iter->children[idx] == nullptr) {
                return false;
            }
            iter = iter->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */