/*
Number: 249
Topic: Group Shifted Strings
Date: 2021/7/18
Rate: Medium
https://leetcode.com/problems/group-shifted-strings/

We can shift a string by shifting each of its letters to its successive letter.

For example, "abc" can be shifted to be "bcd".
We can keep shifting the string to form a sequence.

For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".
Given an array of strings strings, group all strings[i] that belong to the same shifting sequence. You may return the answer in any order.

Constraints:
* 1 <= strings.length <= 200
* 1 <= strings[i].length <= 50
* strings[i] consists of lowercase English letters.

*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> umap;
        // 做 hash function 的 key 分組
        // key 是 string 中每個 character 對於第一個 character 的距離
        // 距離做一個 26 的循環
        for (int i = 0; i < strings.size(); i++) {
            string word = strings[i];
            string encoded(1, '0');
            for (int j = 1; j < word.size(); j++) {
                encoded += "->" + to_string(((int)word[j] + 26 - (int)word[0])%26);
            }
            umap[encoded].push_back(word);
        }

        vector<vector<string>> out;
        for (const auto& p : umap) {
            out.push_back(p.second);
        }
        return out;
    }
};