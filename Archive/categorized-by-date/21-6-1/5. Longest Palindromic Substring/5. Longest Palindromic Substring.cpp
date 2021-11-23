/*
Number: 5
Topic: Longest Palindromic Substring
Date: 2021/6/1
Rate: Medium
https://leetcode.com/problems/longest-palindromic-substring/

Given a string s, return the longest palindromic substring in s.
 

Constraints:
* 1 <= s.length <= 1000
* s consist of only digits and English letters (lower-case and/or upper-case),

*/


class Solution {
public:
    string longestPalindrome(string s) {
        // tc : O(n^2)
        int n = s.length();
        
        int mxlen = 0, start = 0;
        
        for (int i = 0; i < n; i++) {
            int j = i;
            int k = i;
            // 一樣的話就一定是 palindrome
            while (k+1 < n && s[k] == s[k+1]) k++;
            
            // 前後拓展增加 palindrome 長度
            while (j-1 >= 0 && k+1 < n && s[j-1] == s[k+1]) {
                j--; k++;
            }
            
            if (mxlen < k-j+1) {
                mxlen = k-j+1;
                start = j;
            }
        }
        
        return s.substr(start, mxlen);
    }
};