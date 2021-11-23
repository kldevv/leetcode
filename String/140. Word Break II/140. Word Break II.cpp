/*
Number: 140
Topic: Word Break II 
Date: 2021/10/1
Rate: Hard
https://leetcode.com/problems/word-break-ii/

Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Constraints:
    * 1 <= s.length <= 20
    * 1 <= wordDict.length <= 1000
    * 1 <= wordDict[i].length <= 10
    * s and wordDict[i] consist of only lowercase English letters.
    * All the strings of wokrdDict are unique.
*/

class Solution {
private:

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> dp;
        return dfs(s, wordSet, dp);
    }

    vector<string> dfs(string s, unordered_set<string>& wordSet, unordered_map<string, vector<string>> dp) {
        if (dp.count(s))
            return dp[s];

        vector<string> result;

        if (wordSet.count(s))
            result.push_back(s);

        for (int suffixStart = 1; suffixStart < s.size(); suffixStart++) {
            string suffix = s.substr(suffixStart);

            if (wordSet.count(suffix)) {
                string prefix = s.substr(0, suffixStart);
                vector<string> prefixes = dfs(prefix, wordSet, dp);

                vector<string> sentences = join(prefixes, suffix);

                result.insert(result.end(), sentences.begin(), sentences.end());
            }
        }
        dp[s] = result;
        return dp[s];
    }

    vector<string> join(vector<string> prefixes, string suffix) {
        vector<string> result;
        for (string prefix : prefixes) {
            string sentence = prefix + " " + suffix;
            result.push_back(sentence);
        }
        return result;
    }
};
