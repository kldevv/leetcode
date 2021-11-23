/*
Number: 3
Topic: Longest Substring Without Repeating Characters
Date: 2021/5/27
Rate: Medium
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string s, find the length of the longest substring without repeating characters.

Constraints:

* 0 <= s.length <= 5 * 104
* s consists of English letters, digits, symbols and spaces.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // hashmap 儲存最後出現的位置
        unordered_map<char, int> umap;
        int _max = 0, head = -1;
        for (int i = 0; i < s.size(); i++) {
            // 如果有遇到相同的字母，就更新頭的位置
            if (umap.find(s[i]) != umap.end() && head < umap[s[i]]) {
                head = umap[s[i]];
            }
            // 不斷刷新最後出現的地方
            umap[s[i]] = i;
            // 長度等於目前的位置 - 頭的位置
            _max = max(_max, i-head);
        }
        return _max;
    }
};


