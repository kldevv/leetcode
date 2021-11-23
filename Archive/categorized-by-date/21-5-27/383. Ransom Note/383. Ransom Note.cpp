/*
Number: 383
Topic: Ransom Note
Date: 2021/5/27
Rate: Easy
https://leetcode.com/problems/ransom-note/

Given two stings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Constraints:

* 1 <= s.length <= 105
* s consists of only lowercase English letters.

*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap;
        if (ransomNote.size() > magazine.size())
            return false;

        for (const char& c : magazine) {
            umap[c]++;
        }

        for (const char& c : ransomNote) {
            if (!umap[c])
                return false;
            else
                umap[c]--;
        }
        return true;

    }
};