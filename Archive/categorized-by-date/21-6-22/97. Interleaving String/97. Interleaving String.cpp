/*
Number: 97
Topic: Interleaving String
Date: 2021/6/22
Rate: Medium
https://leetcode.com/problems/interleaving-string/

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

* s = s1 + s2 + ... + sn
* t = t1 + t2 + ... + tm
* |n - m| <= 1
* The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...

Note: a + b is the concatenation of strings a and b.

Constraints:
* 0 <= s1.length, s2.length <= 100
* 0 <= s3.length <= 200
* s1, s2, and s3 consist of lowercase English letters.

*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        if (s1.size() == 0 && s2 == s3)
            return true;
        if (s2.size() == 0 && s1 == s3)
            return true;

        int m = s1.size(), n = s2.size();

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        // dp[i][j] 代表，前 i 個 char in s1 和前 j 個 char in s2 可以組成前 i+j-1 個 char in s3
        dp[0][0] = true;

        for (int i = 1; i <= m; i++) {
            dp[i][0] = (dp[i-1][0] && s1[i-1] == s3[i-1]);
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = (dp[0][j-1] && s2[j-1] == s3[j-1]);
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // 要 dp[i][j] 成功，代表前 s1[:i] 和 s2[:j+1] 可以組成 s3[:i+j]，而且 s1[i] 等於 s3[i+j] 或是反之
                dp[i][j] = ((dp[i-1][j] && (s1[i-1] == s3[i+j-1])) || (dp[i][j-1] && (s2[j-1] == s3[i+j-1])));
            }
        }
        return dp[m][n];
    }


};