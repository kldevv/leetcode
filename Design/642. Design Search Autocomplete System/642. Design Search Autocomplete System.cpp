/*
Number: 642
Topic: Design Search Autocomplete System
Date: 2021/9/28
Rate: Hard
https://leetcode.com/problems/design-search-autocomplete-system/

Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character '#').

You are given a string array sentences and an integer array times both of length n where sentences[i] is a previously typed sentence and times[i] is the corresponding number of times the sentence was typed. For each input character except '#', return the top 3 historical hot sentences that have the same prefix as the part of the sentence already typed.

Here are the specific rules:
    * The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
    * The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same hot degree, use ASCII-code order (smaller one appears first).
    * If less than 3 hot sentences exist, return as many as you can.
    * When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.

Implement the AutocompleteSystem class:
    * AutocompleteSystem(String[] sentences, int[] times) Initializes the object with the sentences and times arrays.
    * List<String> input(char c) This indicates that the user typed the character c.
        * Returns an empty array [] if c == '#' and stores the inputted sentence in the system.
        * Returns the top 3 historical hot sentences that have the same prefix as the part of the sentence already typed. If there are fewer than 3 matches, return them all.

Constraints:
    * n == sentences.length
    * n == times.length
    * 1 <= n <= 100
    * 1 <= sentences[i].length <= 100
    * 1 <= times[i] <= 50
    * c is a lowercase English letter, a hash '#', or space ' '.
    * Each tested sentence will be a sequence of characters c that end with the character '#'.
    * Each tested sentence will have a length in the range [1, 200].
    * The words in each input sentence are separated by single spaces.
    * At most 5000 calls will be made to input.
*/
struct Node {
    unordered_map<char, Node*> children;
    unordered_map<string, int> counter;
    bool endOfWord = false;
};

struct Trie {
    Node* root;
    Trie() {
        this->root = new Node();
    }
    void add(string s, int count) {
        Node* iter = root;
        for (char c : s) {
            if (!iter->children[c]) {
                iter->children[c] = new Node();
            }
            iter = iter->children[c];
            iter->counter[s] += count;
        }
        iter->endOfWord = true;
    }
};


class AutocompleteSystem {
private:
    Trie* trie;
    string prefix;
public:
    struct comparator {
        bool operator()(pair<string, int>& A, pair<string, int>& B) {
            return (A.second < B.second) || (A.second == B.second && A.first > B.first);
        }
    };
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        this->trie = new Trie();
        this->prefix = "";

        int n = times.size();

        for (int i = 0; i < n; i++) {
            trie->add(sentences[i], times[i]);
        } 
    }
    
    vector<string> input(char c) {
        vector<string> result;
        if (c == '#') {
            trie->add(prefix, 1);
            prefix = "";
            return result;
        }
        
        prefix += c;

        Node* iter = trie->root;
        for (char c : prefix) {
            if (!iter->children[c])
                return result;
            iter = iter->children[c];
        }

        priority_queue<pair<string, int>, vector<pair<string, int>>, comparator> pq(iter->counter.begin(), iter->counter.end());

        for (int i = 0; i < 3 && pq.size(); i++) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */