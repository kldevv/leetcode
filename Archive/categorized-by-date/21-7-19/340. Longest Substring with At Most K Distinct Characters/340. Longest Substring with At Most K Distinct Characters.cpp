/*
Number: 340
Topic: Longest Substring with At Most K Distinct Characters
Date: 2021/7/19
Rate: Medium
https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

Constraints:
* 1 <= s.length <= 5 * 104
* 0 <= k <= 50

*/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> dict(256, 0);
        int count = 0;
        int i = 0, j = 0;
        int maxLen = 0;
        while (i < s.size()) {
            if (!dict[(int)s[i]])
                count += 1;
            dict[(int)s[i++]] += 1;

            while (count > k) {
                dict[(int)s[j]] -= 1;
                if (!dict[(int)s[j++]])
                    count -= 1;           
            }

            maxLen = max(maxLen, i-j);
        }

        return maxLen;
    }
};