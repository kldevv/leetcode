/*
Number: 316
Topic: Remove Duplicate Letters
Date: 2021/5/29
Rate: Medium
https://leetcode.com/problems/remove-duplicate-letters/

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

* 1 <= s.length <= 104
* s consists of lowercase English letters.

*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> umap;

        for (int i = 0; i < s.size(); i++) {
            // 先儲存每個字母最後出現的地方
            umap[s[i]] = i;
        }

        int start = 0;
        string out;
        // time complexity = O(mn) where m is the cardinality of the character set, while n being the lenght of the array
        // 因為是 lexicographical order，代表一定要用到所有字母才是最長
        while (out.size() < umap.size()) {
            // 搜尋範圍是 start 到每個字母最後出現的地方的最少值，這樣才可以確保每個字母都拿到
            int end = min(umap);
            int _min = 'z'+1, idx = 0;
            for (int i = start; i <= end; i++) {
                // 找搜尋範圍的最小值，而且要沒有被選過
                if (s[i] < _min && umap[s[i]] != INT_MAX) {
                    idx = i;
                    _min = s[i];
                }
            }
            out += _min;
            // 更新最小值，因為該字母已經被選到，所以不需要再 care 他最後出現的地方在哪
            umap[_min] = INT_MAX;
            // 搜索範圍應該要從目前選中的字母的後一個開始，因為要保持 relative order
            start = idx+1;
        }   
        return out;
    }

    int min(unordered_map<char, int> umap) {
        int _min = INT_MAX;
        for (const auto& p : umap) {
            if (p.second < _min)
                _min = p.second;
        }
        return _min;
    }
};
