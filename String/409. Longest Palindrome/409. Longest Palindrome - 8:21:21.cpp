/*
Number: 409
Topic: Longest Palindrome
Date: 2021/8/21
Rate: Easy
https://leetcode.com/problems/longest-palindrome/

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

Constraints:
* 1 <= s.length <= 2000
* s consists of lowercase and/or uppercase English letters only.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int odd = 0;
        for (int c = 'A'; c <= 'z'; c++)
            odd += count(s.begin(), s.end(), c) & 1;
        return s.size() - odd + (odd > 0);
    }
};