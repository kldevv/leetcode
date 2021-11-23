/*
Number: 125
Topic: Valid Palindrome 
Date: 2021/6/1
Rate: Easy
https://leetcode.com/problems/valid-palindrome/


Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Constraints:
* 1 <= s.length <= 2 * 10^5
* s consists only of printable ASCII characters.
 
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0; j = s.size()-1;
        while (i < j) {
            while (!isalnum(s[i]) && i < j)
                i++;
            while (!isalnum(s[j]) && i < j)
                j--;
            if (toupper(s[i]) != toupper(s[j]))
                return false;        
        }
        return true;
    }
};