/*
Number: 1400
Topic: Construct K Palindrome Strings
Date: 2021/8/22
Rate: Medium
https://leetcode.com/problems/construct-k-palindrome-strings/

Given a string s and an integer k. You should construct k non-empty palindrome strings using all the characters in s.

Return True if you can use all the characters in s to construct k palindrome strings or False otherwise.

Constraints:
* 1 <= s.length <= 10^5
* All characters in s are lower-case English letters.
* 1 <= k <= 10^5
*/

class Solution {
public:
    bool canConstruct(string s, int k) {
        int odd = 0;
        for (int c = 'a'; c <= 'z'; c++) {
            odd += (count(s.begin(), s.end(), c) & 1);
        }
        return k <= s.size() && k >= odd;
    }
};