/*
Number: 242
Topic: Valid Anagram
Date: 2021/5/27
Rate: Easy
https://leetcode.com/problems/valid-anagram/

Given two strings s and t, return true if t is an anagram of s, and false otherwise.



Constraints:

* 1 <= s.length, t.length <= 5 * 104
* s and t consist of lowercase English letters.

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> umap;
        if (s.size() != t.size())
            return false;
        for (const char& c : s) {
            umap[c]++;
        }

        for (const char& c : t) {
            if (umap[c] < 1)
                return false;
            else 
                umap[c]--;
        }

        for (unordered_map<char, int>::iterator it = umap.begin(); it != umap.end(); it++) {
            if (it->second)
                return false;
        }
        return true;
        
    }
};





