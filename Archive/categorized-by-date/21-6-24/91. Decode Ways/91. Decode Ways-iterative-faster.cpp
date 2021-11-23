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
        // dp[i] 等於長度為 i 時有幾個 ways
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        dp[1] = (s[0]-'0' != 0) ? 1 : 0;

        for (int i = 2; i <= s.size(); i++) {
            int num1 = s[i-2]-'0'; 
            int num2 = s[i-1]-'0';

            // 符合規則 1 ，就可以從前面那個接續到現在這個
            if (1 <= num2 && num2 <= 9)
                dp[i] += dp[i-1];
            // 符合規則 2，就可以從再前面那個接續到現在這個
            if (num1 == 1 && num2 <= 9 || num1 == 2 && num2 <= 6)
                dp[i] += dp[i-2];
        }
        return dp[s.size()];
    }
};
