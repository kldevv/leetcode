/*
Number: 140
Topic: Word Break II
Date: 2021/6/29
Rate: Hard
https://leetcode.com/problems/word-break-ii/

Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Constraints:

* 1 <= s.length <= 20
* 1 <= wordDict.length <= 1000
* 1 * <= wordDict[i].length <= 10
* s and wordDict[i] consist of only lowercase English letters.
* All the strings of wordDict are unique
*/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> out;
        unordered_set<string> wordSet;
        for (const string& s: wordDict) {
            wordSet.insert(s);
        }

        for (int j = 1; j <= s.size(); j++) {
            string word = s.substr(0, j);
            if (wordSet.count(word)) {
                wordBreak(s, j, word, wordSet, out);
            }
        }
        return out;
    }

    void wordBreak(string s, int i, string temp, const unordered_set<string>& wordSet, vector<string>& out) {
        if (i == s.size()) {
            out.push_back(temp);
        }

        for (int j = 1; i+j <= s.size(); j++) {
            string word = s.substr(i, j);
            if (wordSet.count(word)) {
                wordBreak(s, i+j, temp+' '+word, wordSet, out);
            }
        }
    }
};