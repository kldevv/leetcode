/*
Number: 1048
Topic: Longest String Chain
Date: 2021/8/6
Rate: Medium
https://leetcode.com/problems/longest-string-chain/

You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

Constraints:
* 1 <= words.length <= 1000
* 1 <= words[i].length <= 16
* words[i] only consists of lowercase English letters.
*/

class Solution {
private:
    static bool comparator(const string& s1, const string& s2) {
        return s1.size() < s2.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comparator);
        unordered_map<string, int> dp;
        int maxLen = 0;
        for (string& word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.size(); i++) {
                string pre = word.substr(0, i) + word.substr(i+1);
                dp[word] = max(dp[word], (dp.count(pre)) ? dp[pre]+1 : 1);
            }
            maxLen = max(maxLen, dp[word]);
        }
        return maxLen;
    }
};

