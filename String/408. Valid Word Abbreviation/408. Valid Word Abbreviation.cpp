/*
Number: 408
Topic: Valid Word Abbreviation
Date: 2021/10/19
Rate: Easy
https://leetcode.com/problems/combinations/

A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths. The lengths should not have leading zeros.

For example, a string such as "substitution" could be abbreviated as (but not limited to):
* "s10n" ("s ubstitutio n")
* "sub4u4" ("sub stit u tion")
* "12" ("substitution")
* "su3i1u2on" ("su bst i t u ti on")
* "substitution" (no substrings replaced)

The following are not valid abbreviations:
* "s55n" ("s ubsti tutio n", the replaced substrings are adjacent)
* "s010n" (has leading zeros)
* "s0ubstitution" (replaces an empty substring)

Given a string word and an abbreviation abbr, return whether the string matches the given abbreviation.

A substring is a contiguous non-empty sequence of characters within a string.

Constraints:
    * 1 <= word.length <= 20
    * word consists of only lowercase English letters.
    * 1 <= abbr.length <= 10
    * abbr consists of lowercase English letters and digits.
    * All the integers in abbr will fit in a 32-bit integer.
*/

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int wordIdx = 0;
        int abbrIdx = 0;

        while (wordIdx < word.size() && abbrIdx < abbr.size()) {
            if (word[wordIdx] == abbr[abbrIdx]) {
                wordIdx += 1;
                abbrIdx += 1;
            } else if (isdigit(abbr[abbrIdx])){
                int number = 0;
                while (abbrIdx < abbr.size() && isdigit(abbr[abbrIdx])) {
                    number *= 10;
                    if (!number && abbr[abbrIdx] == '0') {
                        return false;
                    }
                    number += (abbr[abbrIdx])-'0';
                    abbrIdx += 1;
                }
                wordIdx += number;
            } else {
                return false;
            }
        }
        return abbrIdx == abbr.size() && wordIdx == word.size();
    }
};