/*
Number: 290
Topic: Word Pattern
Date: 2021/5/27
Rate: Easy
https://leetcode.com/problems/word-pattern/

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Constraints:

* 1 <= pattern.length <= 300
* pattern contains only lower-case English letters.
* 1 <= s.length <= 3000
* s contains only lower-case English letters and spaces ' '.
* s does not contain any leading or trailing spaces.
* All the words in s are separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> umap;
        unordered_map<char, bool> used;       
        int iterator = 0, count = 0, idx = 0;
        while (iterator < s.size() && idx < pattern.size()) {
            // separate words
            while (iterator+count < s.size() && s[iterator+count] != ' ') 
                count++;
            string word = s.substr(iterator, count++);
            iterator += count;
            count = 0;
            // check if there is a bijection
            if (umap.find(word) == umap.end()) {
                if (used.find(pattern[idx]) != used.end())
                    return false;
                umap[word] = pattern[idx];
                used[pattern[idx++]] = true;
            } else if (umap[word] != pattern[idx++]) 
                    return false;
        }
        // 看有沒有其中一個還沒有跑完，代表長度不一樣
        if (idx < pattern.size())
            return false;
        else if (iterator < s.size())
            return false;
        else 
            return true;
        
    }
};





