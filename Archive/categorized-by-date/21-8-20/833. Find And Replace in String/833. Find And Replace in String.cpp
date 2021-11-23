/*
Number: 833
Topic: Find And Replace in String
Date: 2021/8/20
Rate: Medium
https://leetcode.com/problems/find-and-replace-in-string/

You are given a 0-indexed string s that you must perform k replacement operations on. The replacement operations are given as three 0-indexed parallel arrays, indices, sources, and targets, all of length k.

To complete the ith replacement operation:

1. Check if the substring sources[i] occurs at index indices[i] in the original string s.
If it does not occur, do nothing.

2. Otherwise if it does occur, replace that substring with targets[i].

3. For example, if s = "abcd", indices[i] = 0, sources[i] = "ab", and targets[i] = "eee", then the result of this replacement will be "eeecd".

All replacement operations must occur simultaneously, meaning the replacement operations should not affect the indexing of each other. The testcases will be generated such that the replacements will not overlap.

* For example, a testcase with s = "abc", indices = [0, 1], and sources = ["ab","bc"] will not be generated because the "ab" and "bc" replacements overlap.

Return the resulting string after performing all replacement operations on s.

A substring is a contiguous sequence of characters in a string.

Constraints:
* 1 <= s.length <= 1000
* k == indices.length == sources.length == targets.length
* 1 <= k <= 100
* 0 <= indexes[i] < s.length
* 1 <= sources[i].length, targets[i].length <= 50
* s consists of only lowercase English letters.
* sources[i] and targets[i] consist of only lowercase English letters.
*/

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<vector<int>> sorted;
        for (int i = 0; i < indices.size(); i++) {
            sorted.push_back({indices[i], i});
        }

        sort(sorted.rbegin(), sorted.rend());

        for (vector<int>& idx : sorted) {
            string source = sources[idx[1]];
            string replace = targets[idx[1]];
            if (s.substr(idx[0], source.size()) == source) {
                s = s.substr(0, idx[0]) + replace + s.substr(idx[0]+source.size());
            }
        }
        return s;
    }
};