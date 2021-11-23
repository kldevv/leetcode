/*
Number: 266
Topic: Palindrome Permutation
Date: 2021/7/19
Rate: Easy
https://leetcode.com/problems/palindrome-permutation/

Given a string s, return true if a permutation of the string could form a palindrome.

Constraints:
* 1 <= s.length <= 5000
* s consists of only lowercase English letters.

*/
class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> dict(26, 0);
        for (const char& c : s) {
            dict[c-'a'] += 1;
        }

        int unique = 0;
        for (const int& count : dict) {
            if (count%2)
                unique += 1;
        }
        return unique < 2;
    }
};