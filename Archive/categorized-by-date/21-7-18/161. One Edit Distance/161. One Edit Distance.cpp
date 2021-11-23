/*
Number: 161
Topic: One Edit Distance
Date: 2021/7/18
Rate: Medium
https://leetcode.com/problems/one-edit-distance/

Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.

A string s is said to be one distance apart from a string t if you can:

Insert exactly one character into s to get t.
Delete exactly one character from s to get t.
Replace exactly one character of s with a different character to get t.


Constraints:
* 0 <= s.length <= 104
* 0 <= t.length <= 104
* s and t consist of lower-case letters, upper-case letters and/or digits.
*/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (m > n)
            return isOneEditDistance(t, s);

        for (int i = 0; i < m; i++) {
            if (s[i] != t[i]) {
                if (m == n)
                    return s.substr(i+1) == t.substr(i+1);
                else
                    return s.substr(i) == t.substr(i+1);
            }
        }
        return m + 1 == n;
    }
};