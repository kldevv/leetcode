/*
Number: 392
Topic: Is Subsequence
Date: 2021/5/27
Rate: Easy
https://leetcode.com/problems/is-subsequence/

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).


Constraints:

* 0 <= s.length <= 100
* 0 <= t.length <= 104
* s and t consist only of lowercase English letters.

Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?

先 hashmap<char, list> t ， list 裡儲存 value 出現在 t 裡的 index（ascending）
在處理每個 s 時，一個一個的 char in s 帶入 hashmap，並且確保 list 裡要有比上一個 char 在 t 的 index (prev) 更大的值 (可以用binary search)
更新這個值，讓他成為該 list 裡，大於 prev，但最小的值

*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // tc O(s.size()+t.size())
        int s_idx = 0, t_idx = 0;
        if (s.size() == 0)
            return true;
        while (s_idx < s.size()) {
            while(t_idx < t.size()) {
                if (t[t_idx++] == s[s_idx]) {
                    s_idx++;
                    break;
                }
            }
            if (s_idx >= s.size())
                return true;
            if (t_idx >= t.size())
                break;
        }
        return false;
    }
};

