/*
Number: 139
Topic: Word Break
Date: 2021/10/1
Rate: Medium
https://leetcode.com/problems/word-break/

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Constraints:
    * 1 <= s.length <= 300
    * 1 <= wordDict.length <= 1000
    * 1 <= wordDict[i].length <= 20
    * s and wordDict[i] consist of only lowercase English letters.
    * All the strings of wordDict are unique.
*/


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size()+1, 0);
        dp[s.size()] = 1;
        return dfs(s, 0, wordSet, dp);
    }

    bool dfs(string& s, int start, unordered_set<string>& wordSet, vector<int>& dp) {
        if (start == s.size())
            return true;

        for (int len = s.size()-start; len >= 1; len--) {
            if (dp[start+len] == -1)
                    continue;
            if (wordSet.count(s.substr(start, len)))
                if (dp[start+len] == 1 || dfs(s, start+len, wordSet, dp))
                    return true;
        }
        dp[start] = -1;
        return false;
    }
};
