/*
Number: 91
Topic: Decode Ways
Date: 2021/6/24
Rate: Medium
https://leetcode.com/problems/decode-ways/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Constraints:
* 1 <= s.length <= 100
* s contains only digits and may contain leading zero(s).
*/

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return numDecodings(s, 0, dp);
    }

    int numDecodings(string s, int i, vector<int>& dp) {
        if (i == s.size())
            return 1;

        if (dp[i] != -1)
            return dp[i];

        int num1 = (i < s.size()) ? s[i]-'0' : 0;
        int num2 = (i+1 < s.size()) ? s[i+1]-'0' : INT_MAX;

        if (num1 == 0)
            return 0;

        int res = numDecodings(s, i+1, dp);numDecodings(s, i+1, dp);

        if ((num1 == 1 && num2 != INT_MAX) || (num1 == 2 && num2 <= 6))
            res += numDecodings(s, i+2, dp);

        dp[i] = res;
        return res;
    }
};
