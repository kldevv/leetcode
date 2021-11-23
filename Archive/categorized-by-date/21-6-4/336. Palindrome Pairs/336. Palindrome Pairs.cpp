/*
Number: 336
Topic: Palindrome Pairs
Date: 2021/6/4
Rate: Hard
https://leetcode.com/problems/palindrome-pairs/

Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list, so that the concatenation of the two words words[i] + words[j] is a palindrome.

Constraints:
* 1 <= words.length <= 5000
* 0 <= words[i].length <= 300
* words[i] consists of lower-case English letters.

*/

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> umap;
        vector<vector<int>> out;

        // 先建立 reverse 的字典
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            reverse(s.begin(), s.end());
            umap[s] = i;
        }

        // 對於每一個字來說（除了自己以外）
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            // 每個字都可以被切開成 right 和 left
            for (int j = 0; j < s.size(); j++) {
                string right = s.substr(0, j);
                string left = s.substr(j);
                // 只要 words 裡面有 right 的 reverse，而且 left 自己是 palindrome，組成 umap[right] | left | right 是 palindrome
                if (umap.count(right)) {
                    if (isPalindrome(left) && umap[right] != i)
                        out.push_back({i, umap[right]});
                }
                // 只要 words 裡面有 left 的 reverse，而且 right 自己是 palindrome，組成 left | right | umap[left] 是 palindrome
                if (umap.count(left)) {
                    if (isPalindrome(right) && umap[left] != i)
                        out.push_back({umap[left], i});
                }
            }
        }

        // 特別處理 ""，因爲不會進入上面的 inner loop，而且規則跟其他字不一樣
        if (umap.count("")) {
            for (int i = 0; i < words.size(); i++) {
                string s = words[i];
                // 只要配到的字本身是 palindrome 就可以合在一起，依舊是 palindrome
                if (s != "" && isPalindrome(s)) {
                    out.push_back({umap[""], i});
                }
            }
        }
        return out;
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};