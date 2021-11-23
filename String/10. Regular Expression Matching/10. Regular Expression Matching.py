'''
Number: 10
Topic: Regular Expression Matching
Date: 2021/10/4
Rate: Hard
https://leetcode.com/problems/regular-expression-matching/

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
    * '.' Matches any single character.
    * '*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Constraints:
    * 1 <= s.length <= 20
    * 1 <= p.length <= 30
    * s contains only lowercase English letters.
    * p contains only lowercase English letters, '.', and '*'.
    * It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
'''


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m = len(s)
        n = len(p)
        dp = [[False] * (n+1) for i in range(m+1)]
        dp[0][0] = True

        for j in range(1, n+1):
            if p[j-1] == '*':
                dp[0][j] = dp[0][j-2]

        for i in range(1, m+1):
            for j in range(1, n+1):
                if s[i-1] == p[j-1] or p[j-1] == '.':
                    dp[i][j] = dp[i-1][j-1]
                else if p[j-1] == '*':
                    if s[i-1] != p[j-2] and p[j-2] != '.':
                        dp[i][j] = dp[i][j-2]
                    else:
                        dp[i][j] = dp[i][j-2] or dp[i][j-1] or dp[i-1][j]
        return dp[m][n]