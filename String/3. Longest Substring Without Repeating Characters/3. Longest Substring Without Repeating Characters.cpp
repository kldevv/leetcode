/*
Number: 3
Topic: Longest Substring Without Repeating Characters
Date: 2021/9/30
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
        vector<int> lastAppearance(256, -1);
        int head = -1;
        int result = 0;
        for (int tail = 0; tail < s.size(); tail++) {
            if (lastAppearance[s[tail]] > head)
                head = lastAppearance[s[tail]];
            result = max(result, tail - head);
            lastAppearance[s[tail]] = tail;
        }
        return result;
    }
};