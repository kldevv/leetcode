/*
Number: 320
Topic: Generalized Abbreviation
Date: 2021/7/23
Rate: Medium
https://leetcode.com/problems/generalized-abbreviation/
A word's generalized abbreviation can be constructed by taking any number of non-overlapping substrings and replacing them with their respective lengths. For example, "abcde" can be abbreviated into "a3e" ("bcd" turned into "3"), "1bcd1" ("a" and "e" both turned into "1"), and "23" ("ab" turned into "2" and "cde" turned into "3").

Given a string word, return a list of all the possible generalized abbreviations of word. Return the answer in any order.


Constraints:
* 1 <= word.length <= 15
* word consists of only lowercase English letters.
*/

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> out;
        generateAbbreviations(word, 0, 0, "", out);
        return out;
    }

    void generateAbbreviations(string word, int idx, int count, string abbr, vector<string>& out) {
        if (idx == word.size()) {
            abbr += (count) ? to_string(count) : "";
            out.push_back(abbr);
            return;
        }

        if (count)
            generateAbbreviations(word, idx+1, 0, abbr+to_string(count)+word[idx], out);
        else
            generateAbbreviations(word, idx+1, 0, abbr+word[idx], out);
        
        generateAbbreviations(word, idx+1, count+1, abbr, out);
    }
};