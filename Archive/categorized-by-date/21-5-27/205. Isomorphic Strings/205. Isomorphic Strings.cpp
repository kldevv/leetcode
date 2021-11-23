/*
Number: 205
Topic: Isomorphic Strings
Date: 2021/5/27
Rate: Easy
https://leetcode.com/problems/isomorphic-strings/


Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Constraints:

* 1 <= s.length <= 5 * 104
* t.length == s.length
* s and t consist of any valid ascii character.
*/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> umap;
        unordered_map<char, bool> used;
        for (int i = 0; i < s.size(); i++) {
            // 如果這個字在 s 沒有出現過
            if (umap.find(s[i]) == umap.end()) {
                // 但是相對應的字在 t 被使用過，就回傳 false ，因為兩個的 key 被 map 到一樣的 value 不是 one-to-one
                if (used.find(t[i]) != used.end()) 
                    return false;
                // 紀錄相對應的字，並且標記此字已經被使用過，確保 one-to-one 的情形
                umap[s[i]] = t[i];
                used[t[i]] = true;
            }
            // 再次出現時，確保新的 value 和之前的 value 一樣
            else if (t[i] != umap[s[i]]) 
                return false;
        }
        return true;
    }
};





