/*
Number: 647
Topic: Palindromic Substrings_O(n^2)_(1)
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
        int count = 0;
        for (int center = 0; center < s.size(); center++) {
            count += countPalindromeAroundCenter(s, center, center);
            count += countPalindromeAroundCenter(s, center, center+1);
        }
        return count;
    }

    int countPalindromeAroundCenter(const string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size()) {
            if (s[left--] != s[right++])
                break;
            count += 1;
        }
        return count;
    }
};