/*
Number: 1062
Topic: Longest Repeating Substring
Date: 2021/8/23
Rate: Medium
https://leetcode.com/problems/longest-repeating-substring/

Given a string s, find out the length of the longest repeating substring(s). Return 0 if no repeating substring exists.

Constraints:
* The string s consists of only lowercase English letters from 'a' - 'z'.
* 1 <= s.length <= 1500
*/

class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        int out = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = n; j > i; j--) {
                if (s[i-1] == s[j-1])
                    dp[j] = dp[j-1] + 1;
                else
                    dp[j] = 0;
                out = max(out, dp[j]);
            }
        }
        return out;
    }

    // origin O(mn) space
    /*
    int longestRepeatingSubstring(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int out = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (s[i-1] == s[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                out = max(out, dp[i][j]);
            }
        }
        return out;
    }
    */
};