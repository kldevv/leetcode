'''
Number: 125
Topic: Valid Palindrome
Date: 2021/10/4
Rate: Easy
https://leetcode.com/problems/valid-palindrome/

Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Constraints:
* 1 <= s.length <= 2 * 105
* s consists only of printable ASCII characters.
'''

class Solution:
    def isPalindrome(self, s: str) -> bool:
        n = len(s)
        i, j = 0, n-1
        while i < j:
            while i < j and not s[i].isalnum():
                i += 1
            while i < j and not s[j].isalnum():
                j -= 1
            if i < j and s[i].lower() != s[j].lower():
                return False
            i += 1; j -= 1
        return True
