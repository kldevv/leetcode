/*
Number: 680
Topic: Valid Palindrome II
Date: 2021/7/30
Rate: Easy
https://leetcode.com/problems/valid-palindrome-ii/

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Constraints:
* 1 <= s.length <= 105
* s consists of lowercase English letters.
*/

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i] != s[j])
                return validPalindrome(s, i+1, j) || validPalindrome(s, i, j-1);
            i++, j--;
        }
        return true;
    }

    bool validPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
}; 