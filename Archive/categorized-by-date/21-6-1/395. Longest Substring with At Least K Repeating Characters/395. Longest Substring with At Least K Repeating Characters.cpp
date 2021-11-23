/*
Number: 395
Topic: Longest Substring with At Least K Repeating Characters
Date: 2021/6/1
Rate: Medium
https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/


Given a string s and an integer k, return the length of the longest substring of s such that the frequency
 

Constraints:
* 1 <= s.length <= 104
* s consists of only lowercase English letters.
* 1 <= k <= 105

*/

// 這個寫法的 tc 是 o(n^2) in the worst case，更好的解法是 sliding windows

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() == 0)
            return 0;

        vector<int> map(26, 0);

        for (const char& c : s) {
            map[c-'a']++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]-'a'] < k) {
                // 想法是當第 i 個 char 出現的頻率小於 k 時，最長的 substring 不可能包含 i，因此可以把 string 拆成兩半
                // 而每次進入更小的 string 時，都要再重新數一次頻率
                return max(longestSubstring(s.substr(0, i), k), longestSubstring(s.substr(i+1), k));
            }
        }
        // 直到整個 substring 裡面出現的頻率都大於 k 時，回傳整個長度
        return s.size();
    }
};