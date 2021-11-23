/*
Number: 30.
Topic: Substring with Concatenation of All Words
Date: 2021/6/2
Rate: Hard
https://leetcode.com/problems/substring-with-concatenation-of-all-words/

You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.

Constraints:
* 1 <= s.length <= 104
* s consists of lower-case English letters.
* 1 <= words.length <= 5000
* 1 <= words[i].length <= 30
* words[i] consists of lower-case English letters.

*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int word_len = words[0].size();
        int word_num = words.size();
        vector<int> out;
        unordered_map<string, int> umap;
        unordered_map<string, int> seen;

        if (s.size() < word_len*word_num)
            return out;

        for (const string& word : words)
            umap[word]++;

        for (int i = 0; i < s.size()-word_len*word_num+1; i++) {
            int j = 0;
            seen.clear();
            for (; j < word_num; j++) {
                string word = s.substr(i+j*word_len, word_len);
                if (umap.count(word)) {
                    if (++seen[word] > umap[word])
                        break;
                } else {
                    break;
                }
            }
            if (j == word_num) {
                out.push_back(i);
            }
        }
        return out;
    }
};