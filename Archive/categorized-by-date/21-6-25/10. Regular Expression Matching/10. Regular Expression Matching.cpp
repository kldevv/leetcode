/*
Number: 10
Topic: Regular Expression Matching
Date: 2021/6/25
Rate: Hard
https://leetcode.com/problems/regular-expression-matching/

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).


Constraints:
* 0 <= s.length <= 20
* 0 <= p.length <= 30
* s contains only lowercase English letters.
* p contains only lowercase English letters, '.', and '*'.
* It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;

        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2] || (i && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                } else {
                    dp[i][j] = i && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }

        return dp[m][n];
    }
};