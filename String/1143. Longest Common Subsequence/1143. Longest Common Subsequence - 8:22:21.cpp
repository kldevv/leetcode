/*
Number: 1143
Topic: Longest Common Subsequence
Date: 2021/8/22
Rate: Medium
https://leetcode.com/problems/longest-common-subsequence/

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Constraints:
* 1 <= text1.length, text2.length <= 1000
* text1 and text2 consist of only lowercase English characters.
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1])
                    dp[j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    // one layer, sc: O(min(m, n))
    /*
        int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<int> dp(n+1, 0);

        for (int i = 0; i < m; i++) {
            int prev = 0;
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (text1[i] == text2[j-1])
                    dp[j] = prev + 1;
                else
                    dp[j] = max(dp[j], dp[j-1]);
                prev = temp;
            }
        }
        return dp[n];
    }
    */
};


