/*
Number: 1268
Topic: Search Suggestions System
Date: 2021/8/25
Rate: Medium
https://leetcode.com/problems/search-suggestions-system/

Given an array of strings products and a string searchWord. We want to design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return list of lists of the suggested products after each character of searchWord is typed. 

Constraints:
* 1 <= products.length <= 1000
* There are no repeated elements in products.
* 1 <= Σ products[i].length <= 2 * 10^4
* All characters of products[i] are lower-case English letters.
* 1 <= searchWord.length <= 1000
* All characters of searchWord are lower-case English letters.
*/


class Trie {
private:
    struct Node {
        vector<Node*> children = vector<Node*>(26, nullptr);
        bool isEndOfWord = false;
    };
    Node* root;
public:
    Trie() {
        this->root = new Node();
    }

    void insert(string s) {
        Node* curNode = root;
        for (char& c : s) {
            if (!(curNode->children[c-'a']))
                curNode->children[c-'a'] = new Node();
            curNode = curNode->children[c-'a'];
        }
        curNode->isEndOfWord = true;
    }

    vector<string> getWordStartWith(string& prefix) {
        vector<string> result;
        Node* curNode = this->root;


        for (char& c : prefix) {
            if (!(curNode->children[c-'a']))
                return result;
            curNode = curNode->children[c-'a'];
        }
        dfsWithPrefix(curNode, prefix, result);
        return result;
    }

    void dfsWithPrefix(Node* curNode, string word, vector<string>& result) {
        if (result.size() == 3)
            return;
        if (curNode->isEndOfWord)
            result.push_back(word);
        for (char c = 'a'; c <= 'z' && result.size() < 3; c++) {
            if (curNode->children[c-'a'])
                dfsWithPrefix(curNode->children[c-'a'], word+c, result);
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = new Trie();
        for (string& pro : products) {
            trie->insert(pro);
        }
        string prefix = "";
        vector<vector<string>> result;
        for (int i = 0; i < searchWord.size(); i++) {
            prefix += searchWord[i];
            result.push_back(trie->getWordStartWith(prefix));
        }

        return result;
    }
};