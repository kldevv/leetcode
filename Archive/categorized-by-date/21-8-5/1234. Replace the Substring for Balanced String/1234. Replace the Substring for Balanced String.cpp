/*
Number: 1234
Topic: Replace the Substring for Balanced String
Date: 2021/8/4
Rate: Medium
https://leetcode.com/problems/replace-the-substring-for-balanced-string/

You are given a string containing only 4 kinds of characters 'Q', 'W', 'E' and 'R'.

A string is said to be balanced if each of its characters appears n/4 times where n is the length of the string.

Return the minimum length of the substring that can be replaced with any other string of the same length to make the original string s balanced.

Return 0 if the string is already balanced.

Constraints:
* 1 <= s.length <= 10^5
* s.length is a multiple of 4
* s contains only 'Q', 'W', 'E' and 'R'.
*/

class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int k = n / 4;
        vector<int> count(256, 0);
        for (char& c : s) {
            count[c] += 1;
        }

        int j = 0;
        int minLen = n;
        for (int i = 0; i < n; i++) {
            count[s[i]] -= 1;
            while (j < n && max(max(count['Q'], count['W']), max(count['E'], count['R'])) <= k) {
                minLen = min(minLen, i - j + 1);
                count[s[j++]] += 1;
            }
        }
        return minLen;
    }
};