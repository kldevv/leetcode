/*
Number: 159
Topic: Longest Substring with At Most Two Distinct Characters
Date: 2021/7/19
Rate: Medium
https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

Constraints:
* 1 <= s.length <= 104
* s consists of English letters.

*/
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int count = 0;
        int i = 0, j = 0;
        int maxLen = 0;

        vector<int> dict(256, 0);
        while (i < s.size()) {
            if (!dict[s[i]])
                count += 1;

            dict[s[i++]] += 1;

            while (count > 2) {
                dict[s[j]] -= 1;
                if (!dict[s[j++]])
                    count -= 1;
            }

            maxLen = max(maxLen, i-j);
        }
        return maxLen;
    }
};