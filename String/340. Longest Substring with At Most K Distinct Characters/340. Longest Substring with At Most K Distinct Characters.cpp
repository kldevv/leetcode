/*
Number: 340
Topic: Longest Substring with At Most K Distinct Characters
Date: 2021/12/3
Rate: Medium
https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

Constraints:
    * 1 <= s.length <= 5 * 104
    * 0 <= k <= 50
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        /*
        Sliding Windows
            - Open (inclusive)
            - Close (inclusive)

        Tracking:
            - How many unique characters are in the window?
                - count => num of char
                - uniqueChar => num of unique char

        Actions:
            if (count[s[close]]++ == 0) uniqueChar += 1

            # invalid:
            while(uniqueChar > k)
                if count[--s[open++] == 0] uniqueChar -= 1

            # valid:
            maxLen = max(., close - open + 1)
            close += 1
        */
        vector<int> charCounter(128, 0);
        int numOfUniqueChar = 0;

        int open = 0;
        int close = 0;

        int maxLen = 0;

        for (; close < s.size(); close++) {
            if (charCounter[s[close]]++ == 0)
                numOfUniqueChar += 1;

            while (open <= close && numOfUniqueChar > k) {
                if (--charCounter[s[open]] == 0) {
                    numOfUniqueChar -= 1;
                }
                open += 1;
            }

            maxLen = max(maxLen, close - open + 1);
        }
        return maxLen;
    }
};