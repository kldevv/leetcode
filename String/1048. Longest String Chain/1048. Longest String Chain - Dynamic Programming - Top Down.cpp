/*
Number: 1048
Topic: Longest String Chain
Date: 2021/11/17
Rate: Medium
https://leetcode.com/problems/longest-string-chain/

You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.
    * For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".

A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

Constraints:
    * 1 <= words.length <= 1000
    * 1 <= words[i].length <= 16
    * words[i] only consists of lowercase English letters.
*/

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/* Complexity
    TC: O(n * L^2)
        1. O(n) for set initialization
        2. Because memo we only need n times string chain calculations
        3. Each word require L^2 (L position, L string modification) to get predecessor
    SC: O(n)
        1. Set is O(n)
        2. Stack call can be O(n) if we get a string chain with the length of n
*/
class Solution {
   public:
    int longestStrChain(vector<string>& words) {
        /*
        memo[s] is the longest string chain of s
        memo[s] = MAX((pre_s) ? memo[pre_s] + 1 : 0) for each pre_s of s's predecessor
        */

        unordered_set<string> wordSet(words.begin(), words.end());
        unordered_map<string, int> memo;

        int result = 0;
        for (string word : words) {
            result = max(result, longestStrChain(word, wordSet, memo));
        }
        return result;
    }

    int longestStrChain(string word, const unordered_set<string>& words, unordered_map<string, int>& memo) {
        if (!words.count(word)) {
            return 0;
        }
        if (word.size() == 1) {
            return 1;
        }
        if (!memo.count(word)) {  // if word haven't be calculated before
            int prevStrChain = 0;
            for (int i = 0; i < word.size(); i++) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                prevStrChain = max(prevStrChain, longestStrChain(predecessor, words, memo));
            }
            memo[word] = prevStrChain + 1;
        }
        return memo[word];
    }
};