/*
Number: 792
Topic: Number of Matching Subsequences - Brute Force
Date: 2021/11/26
Rate: Medium
https://leetcode.com/problems/number-of-matching-subsequences/

Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
    * For example, "ace" is a subsequence of "abcde".

Constraints:
    * 1 <= s.length <= 5 * 104
    * 1 <= words.length <= 5000
    * 1 <= words[i].length <= 50
    * s and words[i] consist of only lowercase English letters.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int numMatchingSubseq(string s, vector<string>& words) {
        /*
        For word in words:
            if (searchMatchSubsequence(s, word))
                countMatchSubseq += 1
        
        %%%%%%%%%%%%%%%
        Complexity
            - Time: O(words.size() * s.size())
            - Space: O(1)

        */
        int countMatchSubseq = 0;
        for (string word : words) {
            countMatchSubseq += searchMatchSubseq(s, word);
        }
        return countMatchSubseq;
    }

    int searchMatchSubseq(string s, string subseq) {
        /*
        %%%%%%%%%%%%%%%
        Complexity
            - Time: O(s.size())
            - Space: O(1)
        */
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (subseq[j] == s[i])
                j += 1;
            if (j == subseq.size())
                return 1;
        }
        return 0;
    }
};
