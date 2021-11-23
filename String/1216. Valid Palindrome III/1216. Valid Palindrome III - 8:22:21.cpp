/*
Number: 1216
Topic: Valid Palindrome III
Date: 2021/8/22
Rate: Hard
https://leetcode.com/problems/valid-palindrome-iii/

Given a string s and an integer k, return true if s is a k-palindrome.

A string is k-palindrome if it can be transformed into a palindrome by removing at most k characters from it.

Constraints:
* 1 <= s.length <= 1000
* s consists of only lowercase English letters.
* 1 <= k <= s.length
*/

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int maxLen = longestPalindrome(s);
        // cout << maxLen;
        return (s.size()-maxLen <= k);
    }

    int longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 1));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i+len-1 < n; i++) {
                int j = i+len-1;
                if (s[i] == s[j] && i == j-1)
                    dp[i][j] = 2;
                else if (s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};