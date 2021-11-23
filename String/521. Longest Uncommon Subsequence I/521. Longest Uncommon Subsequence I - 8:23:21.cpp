/*
Number: 521
Topic: Longest Uncommon Subsequence I
Date: 2021/8/23
Rate: Easy
https://leetcode.com/problems/longest-uncommon-subsequence-i/

Given two strings a and b, return the length of the longest uncommon subsequence between a and b. If the longest uncommon subsequence does not exist, return -1.
An uncommon subsequence between two strings is a string that is a subsequence of one but not the other.
A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.

* For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).

Constraints:
* 1 <= a.length, b.length <= 100
* a and b consist of lower-case English letters.
*/

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b)
            return -1;
        return max(a.size(), b.size());
    }
};