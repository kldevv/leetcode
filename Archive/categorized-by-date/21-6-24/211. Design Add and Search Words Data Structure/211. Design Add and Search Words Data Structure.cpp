/*
Number: 211
Topic: Design Add and Search Words Data Structure
Date: 2021/6/24
Rate: Medium
https://leetcode.com/problems/design-add-and-search-words-data-structure/


Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.


Constraints:
* 1 <= word.length <= 500
* word in addWord consists lower-case English letters.
* word in search consist of  '.' or lower-case English letters.
* At most 50000 calls will be made to addWord and search.

*/

class TrieNode {
public:
    vector<TrieNode*> children;
    bool endOfWord;

    TrieNode(): children(26, nullptr), endOfWord(false) {
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (const char& c : word) {
            if (node->children[c-'a'] == nullptr)
                node->children[c-'a'] = new TrieNode();
            node = node->children[c-'a'];
        }
        node->endOfWord = true;
    }
    
    bool search(string word) {
        return search(word, 0, root);
    }

private:
    TrieNode* root = new TrieNode();

    bool search(const string& word, int i, TrieNode* head) {
        if (head == nullptr)
            return false;

        if (i == word.size())
            return head->endOfWord;

        if (word[i] != '.')
            return search(word, i+1, head->children[word[i]-'a']);

        for (int k = 0; k < head->children.size(); k++) {
            if (search(word, i+1, head->children[k]))
                return true;
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */