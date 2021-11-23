/*
Number: 792
Topic: Number of Matching Subsequences
Date: 2021/8/6
Rate: Medium
https://leetcode.com/problems/number-of-matching-subsequences/

Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".

Constraints:
* 1 <= s.length <= 5 * 104
* 1 <= words.length <= 5000
* 1 <= words[i].length <= 50
* s and words[i] consist of only lowercase English letters.
*/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<string>> process(128);
        for (string& w : words) {
            process[w[0]].push_back(w);
        }
        
        int out = 0;
        for (const char& c : s) {
            vector<string> matchChar = process[c];
            process[c].clear();
            for (string s : matchChar) {
                if (s.size() == 1)
                    out += 1;
                string incr = s.substr(1);
                process[incr[0]].push_back(incr);
            }
        }
        return out;
    }
};