/*
Number: 49
Topic: Group Anagrams
Date: 2021/5/28
Rate: Medium
https://leetcode.com/problems/group-anagrams/

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Constraints:

* 1 <= strs.length <= 104
* 0 <= strs[i].length <= 100
* strs[i] consists of lower-case English letters.

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for (string& str : strs) {
            string ori = str;
            sortString(str);
            umap[str].push_back(ori);
        }
        vector<vector<string>> out;
        for (const auto& p : umap) {
            out.push_back(p.second); 
        }
        return out;
    }

    void sortString(string& str) {
        // 因為都是小寫
        vector<int>temp (26, 0);
        for (const char& c: str) {
            temp[c - 'a']++;
        }
        int idx = 0;
        for (int i = 0; i < temp.size(); i++) {
            while (idx < str.size() && temp[i]) {
                str[idx++] = i + 'a';
                temp[i]--;
            }
        }
    }
};