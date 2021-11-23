/*
Number: 291
Topic: Word Pattern II
Date: 2021/7/23
Rate: Medium
https://leetcode.com/problems/word-pattern-ii/

Given a pattern and a string s, return true if s matches the pattern.

A string s matches a pattern if there is some bijective mapping of single characters to strings such that if each character in pattern is replaced by the string it maps to, then the resulting string is s. A bijective mapping means that no two characters map to the same string, and no character maps to two different strings.

Constraints:
* 1 <= pattern.length, s.length <= 20
* pattern and s consist of only lower-case English letters.
*/

class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<char, string> umap;
        unordered_set<string> avoid;
        return wordPatternMatch(pattern, s, 0, 0, umap, avoid);
    }

    bool wordPatternMatch(string& pattern, string& s, int patternIdx, int stringIdx, unordered_map<char, string>& umap, unordered_set<string>& avoid) {
        if (patternIdx == pattern.size() && stringIdx == s.size())
            return true;
        if ((patternIdx == pattern.size()) ^ (stringIdx == s.size()))
            return false;

        char target = pattern[patternIdx];

        if (umap.count(target)) {
            if (umap[target] == s.substr(stringIdx, umap[target].size()))
                return wordPatternMatch(pattern, s, patternIdx+1, stringIdx+umap[target].size(), umap, avoid);
            else
                return false;
        }
        
        for (int length = 1; length <= s.size()-stringIdx; length++) {
            string match = s.substr(stringIdx, length);
            if (avoid.count(match))
                continue;

            umap[target] = match;
            avoid.insert(match);
            if (wordPatternMatch(pattern, s, patternIdx+1, stringIdx+length, umap, avoid))
                return true;

            avoid.erase(match);
            umap.erase(target);
        }
        return false;
    }
};
