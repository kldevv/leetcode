/*
Number: 320
Topic: Generalized Abbreviation
Date: 2021/10/19
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
        vector<string> results;
        generate(word, 0, 0, "", results);
        return results;
    }

    void generate(string word, int start, int skipCount, string result, vector<string>& results) {
        if (start == word.size()) {
            if (skipCount) {
                result += to_string(skipCount);
            }
            results.push_back(result);
            return;
        }

        generate(word, start+1, skipCount+1, result, results);

        if (skipCount) {
            result += to_string(skipCount);
        }
        generate(word, start+1, 0, result+word[start], results);
    }
};
