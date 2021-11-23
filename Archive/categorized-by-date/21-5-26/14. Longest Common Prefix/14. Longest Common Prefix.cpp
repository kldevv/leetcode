/*
Number: 14
Topic: Longest Common Prefix
Date: 2021/5/26
Rate: Easy
https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Constraints:

* 1 <= strs.length <= 200
* 0 <= strs[i].length <= 200
* strs[i] consists of only lower-case English letters.

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for (int i = 0; i < strs[0].size(); i++) {
            // 選第一個 string
            for (int x = 1; x < strs.size(); x++) {
                // 看看其他的 string 的 char 有沒有和第一個一樣，沒有就直接 return
                if (i >= strs[x].size() || strs[x][i] != strs[0][i])
                    return prefix;
            }
            prefix += strs[0][i];
        }
        return prefix;
    }
};