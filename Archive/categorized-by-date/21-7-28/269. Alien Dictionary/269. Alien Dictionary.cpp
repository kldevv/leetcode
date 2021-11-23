/*
Number: 269
Topic: Alien Dictionary
Date: 2021/7/28
Rate: Hard
https://leetcode.com/problems/alien-dictionary/

There is a new alien language that uses the English alphabet. However, the order among the letters is unknown to you.

You are given a list of strings words from the alien language's dictionary, where the strings in words are sorted lexicographically by the rules of this new language.

Return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If there is no solution, return "". If there are multiple solutions, return any of them.

A string s is lexicographically smaller than a string t if at the first letter where they differ, the letter in s comes before the letter in t in the alien language. If the first min(s.length, t.length) letters are the same, then s is smaller if and only if s.length < t.length.

Constraints:
* 1 <= words.length <= 100
* 1 <= words[i].length <= 100
* words[i] consists of only lowercase English letters.
*/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> vertices;
        unordered_map<char, int> degrees;

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            for (int j = 0; j < word.size(); j++) {
                degrees[word[j]] = 0;
            }
        }

        for (int i = 1; i < words.size(); i++) {
            string word = words[i-1];
            string word2 = words[i];
            int n = min(word.size(), word2.size());
            if (word.size() > word2.size() && word.substr(0, n) == word2)
                return "";
            for (int j = 0; j < n; j++) {
                if (word[j] != word2[j]) {
                    vertices[word[j]].push_back(word2[j]);
                    degrees[word2[j]] += 1;
                    break;
                }
            }
        }

        queue<char> zeroDegree;
        for (const pair<char, int>& p : degrees) {
            if (!p.second)
                zeroDegree.push(p.first);
        }

        string out = "";
        while (!zeroDegree.empty()) {
            char c = zeroDegree.front();
            out += c;
            zeroDegree.pop();
            
            vector<char> succesor = vertices[c];
            for (const char& suc : succesor) {
                if (!(--degrees[suc]))
                    zeroDegree.push(suc);
            }
        }  
        return (out.size() == degrees.size()) ? out : "";
    }
};
