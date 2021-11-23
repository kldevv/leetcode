/*
Number: 647
Topic: Palindromic Substrings_O(n^2)_(n^2)
Date: 2021/11/7
Rate: Medium
https://leetcode.com/problems/palindromic-substrings/

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

Constraints:
    * 1 <= s.length <= 1000
    * s consists of lowercase English letters.
*/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> isValid(n, vector<int>(n, 0));
        int count = 0;

        for (int len = 1; len <= n; len++) {
            for (int start = 0; start + len - 1 < n; start++) {
                int end = start + len - 1;
                if (start == end) {
                    isValid[start][end] = 1;
                }
                else {
                    isValid[start][end] = (start + 1 == end || isValid[start+1][end-1]) && (s[start] == s[end]);
                }
                count += isValid[start][end];
            }
        }
        return count;
    }
};
