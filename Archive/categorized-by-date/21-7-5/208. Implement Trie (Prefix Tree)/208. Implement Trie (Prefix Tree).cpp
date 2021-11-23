/*
Number: 208
Topic: Implement Trie (Prefix Tree)
Date: 2021/7/5
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

class Node {
public:
    vector<Node*> children;
    bool endOfWord;

    Node() {
        children = vector<Node*> (26, nullptr);
        endOfWord = false;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curNode = head;

        for (const char& c : word) {
            int idx = c - 'a';

            if (!curNode->children[idx]) {
                curNode->children[idx] = new Node();
            }
            curNode = curNode->children[idx];
        }
        curNode->endOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curNode = head;
        for (const char& c : word) {
            int idx = c - 'a';

            if (!curNode->children[idx])
                return false;

            curNode = curNode->children[idx];
        }
        return curNode->endOfWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curNode = head;
        for (const char& c : prefix) {
            int idx = c - 'a';

            if (!curNode->children[idx])
                return false;

            curNode = curNode->children[idx];
        }
        return true;    
    }
private:
    Node* head = new Node();
};



/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */