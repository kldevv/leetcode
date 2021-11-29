/*
Number: 1839
Topic: Longest Substring Of All Vowels in Order
Date: 2021/11/26
Rate: Medium
https://leetcode.com/problems/number-of-substrings-with-only-1s/

A string is considered beautiful if it satisfies the following conditions:
    * Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
    * The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's before 'i's, etc.).

For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful, but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.

Given a string word consisting of English vowels, return the length of the longest beautiful substring of word. If no such substring exists, return 0.

A substring is a contiguous sequence of characters in a string.

Constraints:
    * 1 <= word.length <= 5 * 105
    * word consists of characters 'a', 'e', 'i', 'o', and 'u'.
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestBeautifulSubstring(string word) {
        /*
        Sliding Windows (inclusive, inclusive):
            - Actions:
                # of collected vowels
                move the close

                - Valid Actions:
                    record the length of the subarrays
                - Invalid Actions:
                    move the open (jump to close)
        */
        int open = 0;
        int close = 0;
        int maxLen = 0;
        unordered_set<char> vowels;

        for (; close < word.size(); close++) {
            if (close > 0 && word[close] < word[close - 1]) {
                vowels.clear();
                open = close;
            }
            vowels.insert(word[close]);
            if (vowels.size() == 5)
                maxLen = max(maxLen, close - open + 1);
        }
        return maxLen;
    }
};