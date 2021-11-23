/*
Number: 1092
Topic: Shortest Common Supersequence
Date: 2021/8/23
Rate: Hard
https://leetcode.com/problems/shortest-common-supersequence/

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

Constraints:
* 1 <= str1.length, str2.length <= 1000
* str1 and str2 consist of lowercase English letters.
*/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string root = LCS(str1, str2);
        string out = "";

        int i = 0, j = 0;
        for (const char& c : root) {
            while (i < str1.size() && str1[i] != c)
                out += str1[i++];
            while (j < str2.size() && str2[j] != c)
                out += str2[j++];
            out += c;
            i++, j++;
        }

        while (i < str1.size())
            out += str1[i++];
        while (j < str2.size())
            out += str2[j++];

        return out;
    }

    string LCS(string& s1, string& s2) {
        int m = s1.size();
        int n = s2.size();

        vector<string> dp(n+1, "");
        for (int i = 1; i <= m; i++) {
            string prev = "";
            for (int j = 1; j <= n; j++) {
                string temp = dp[j];
                if (s1[i-1] == s2[j-1])
                    dp[j] = prev + s1[i-1];
                else
                    dp[j] = (dp[j].size() > dp[j-1].size()) ? dp[j] : dp[j-1];
                prev = temp;
            }
        }
        return dp[n];
    }
};