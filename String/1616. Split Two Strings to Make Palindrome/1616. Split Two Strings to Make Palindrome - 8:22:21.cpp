/*
Number: 1616
Topic: Split Two Strings to Make Palindrome
Date: 2021/8/22
Rate: Medium
https://leetcode.com/problems/split-two-strings-to-make-palindrome/

You are given two strings a and b of the same length. Choose an index and split both strings at the same index, splitting a into two strings: aprefix and asuffix where a = aprefix + asuffix, and splitting b into two strings: bprefix and bsuffix where b = bprefix + bsuffix. Check if aprefix + bsuffix or bprefix + asuffix forms a palindrome.

When you split a string s into sprefix and ssuffix, either ssuffix or sprefix is allowed to be empty. For example, if s = "abc", then "" + "abc", "a" + "bc", "ab" + "c" , and "abc" + "" are valid splits.

Return true if it is possible to form a palindrome string, otherwise return false.

Notice that x + y denotes the concatenation of strings x and y.

Constraints:
* 1 <= a.length, b.length <= 105
* a.length == b.length
* a and b consist of lowercase English letters
*/

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        // a_prefix + b_suffix or b_prefix + a_suffix
        return checkOnePlusTwoPalindrome(a, b) || checkOnePlusTwoPalindrome(b, a);
    }

    bool checkOnePlusTwoPalindrome(string& a, string& b) {
        int i = 0, j = a.size()-1;
        
        // skip the palindrome part
        while (i < j && a[i] == b[j])
            i++, j--;

        // the remaining parts have to be a palindrome
        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    }

    bool isPalindrome(string& s, int i, int j) {
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }

};