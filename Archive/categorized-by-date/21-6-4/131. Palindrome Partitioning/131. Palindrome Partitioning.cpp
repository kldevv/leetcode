/*
Number: 131
Topic: Palindrome Partitioning
Date: 2021/6/4
Rate: Medium
https://leetcode.com/problems/palindrome-partitioning/

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

Constraints:
* 1 <= s.length <= 16
* s contains only lowercase English letters.

*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> out;
        vector<string> parts;
        vector<vector<int>> dp;
        for (int i = 0; i < s.size(); i++) {
            vector<int> temp;
            for (int j = 0; j < s.size(); j++) {
                temp.push_back(0);
            }
            dp.push_back(temp);
        }

        partition(s, 0, parts, out, dp);
        return out;
    }

    void partition (string& s, int start, vector<string>& parts, vector<vector<string>>& out, vector<vector<int>>& dp) {
        if (start == s.size()) {
            out.push_back(parts);
            return;
        }

        // backtracking
        for (int i = start; i < s.size(); i++) {
            // recursively 產生所有的 substring，backtrack回文的條件
            if (isPalindrome(s, start, i, dp)) {        
                parts.push_back(s.substr(start, i-start+1));
                partition(s, i+1, parts, out, dp);
                parts.pop_back();
            }
        }
    }

    // 帶 dp 的 palindrome， dp[start][end]，代表 s[start:end+1] 是 palindrome
    bool isPalindrome (string& s, int start, int end, vector<vector<int>>& dp) {
        if (!dp[start][end]) {
            int i = start, j = end;
            while (i < j) {
                if (s[i++] != s[j--]) {
                    dp[start][end] = -1;
                    return false;
                }
            }
            dp[start][end] = 1;
            return true;
        } else if (dp[start][end] == 1)
            return true;
        else
            return false;
    }
};