/*
Number: 387
Topic: First Unique Character in a String
Date: 2021/5/26
Rate: Easy
https://leetcode.com/problems/first-unique-character-in-a-string/

Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.

Constraints:

* 1 <= s.length <= 105
* s consists of only lowercase English letters.

*/

class Solution {
public:
    int firstUniqChar(string s) {
        // hashmap 儲存是否已經有這個單詞
        unordered_map<char, int> m;
        for (const char& c : s) {
            m[c]++;
        }
        // 第二次 loop over，如果只有經過一次，就回傳
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == 1)
                return i;
        }
        return -1;
    }
};