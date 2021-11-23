/*
Number: 318
Topic: Maximum Product of Word Lengths
Date: 2021/6/26
Rate: Medium
https://leetcode.com/problems/maximum-product-of-word-lengths/

Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

Constraints:
* 2 <= words.length <= 1000
* 1 <= words[i].length <= 1000
* words[i] consists only of lowercase English letters.

*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> umap;
        // tc: O(n+N) for n = total_character_num, N = number of strings
        for (const string& s : words) {
            int mask = 0;
            for (const char& c : s) {
                // mask 代表這個字串裡面有出現什麼英文字
                mask |= 1 << (c-'a');
            }
            // 對於相同英文字母組成的字串，我們只要取最大長度的那個就好
            if (umap.count(mask))
                umap[mask] = max(umap[mask], (int)s.size());
            else
                umap[mask] = s.size();
        } 

        int result = 0;
        for (auto& a : umap) {
            for (auto& b : umap) {
                // 兩個英文字母組合完全沒有重疊！
                if (!(a.first & b.first))
                    result = max(result, a.second*b.second);
            }
        }
        return result;
    }
};