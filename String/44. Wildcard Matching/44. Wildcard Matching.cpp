/*
Number: 44
Topic: Wildcard Matching
Date: 2021/12/3
Rate: Hard
https://leetcode.com/problems/wildcard-matching/

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
    * '?' Matches any single character.
    * '*' Matches any sequence of characters (including the empty sequence).
    *
The matching should cover the entire input string (not partial).

Constraints:
    * 0 <= s.length, p.length <= 2000
    * s contains only lowercase English letters.
    * p contains only lowercase English letters, '?' or '*'.
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isMatch(string s, string p) {
        /*
        dp[s][p] = len of s at S match len of p at P

        Edge cases:
            All emtpy:
                dp[0][0] = true;

            S is empty but P is not empty:
                dp[0][p] = dp[0][p-1] && p[p] == '*';

            Pattern is empty but S is not empty :
                dp[s][0] = false;

        Recurrence Relation:
            1. P[p] is a char && dp[s-1][p-1] && S[s] == P[p]
            2. P[p] == '?' && dp[s-1][p-1]
            3. P[p] == '* &&
                dp[s-1][p] (represent a sequence) ||
                dp[s][p-1] (represent 0 char) ||

                dp[s][p] = true
        */
        int lenOfS = s.size();
        int lenOfP = p.size();
        vector<vector<int>> isMatch(lenOfS + 1, vector<int>(lenOfP + 1, 0));

        isMatch[0][0] = 1;
        for (int j = 1; j <= lenOfP; j++) {
            isMatch[0][j] = isMatch[0][j - 1] && (p[j - 1] == '*');
        }

        for (int i = 1; i <= lenOfS; i++) {
            for (int j = 1; j <= lenOfP; j++) {
                if (p[j - 1] == '*') {
                    isMatch[i][j] = isMatch[i - 1][j] || isMatch[i][j - 1];
                } else {
                    isMatch[i][j] = isMatch[i - 1][j - 1] && ((p[j - 1] == '?') || (s[i - 1] == p[j - 1]));
                }
            }
        }
        return isMatch[lenOfS][lenOfP];
    }
};