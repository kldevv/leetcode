/*
Number: 395
Topic: Longest Substring with At Least K Repeating Characters
Date: 2021/6/1
Rate: Medium
https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/


Given a string s and an integer k, return the length of the longest substring of s such that the frequency
 

Constraints:
* 1 <= s.length <= 104
* s consists of only lowercase English letters.
* 1 <= k <= 105

*/

// sliding windows tc: O(n)

class Solution {
public:
    int longestSubstring(string s, int k) {
        // substring 會有 n 個 unique character
        int max_unique = findUnique(s);
        int result = 0;

        for (int curr_unique = 1 ; curr_unique <= max_unique; curr_unique++) {
            // 找到所有包含 [1, max_unique] 個 character 的 substring，其中 substring 中 character 出現頻率大於 k 的，就紀錄它的長度
            int unique = 0, start = 0, end = 0, count = 0, idx = 0;
            vector<int> map(26, 0);
            while (end < s.size()) {
                if (unique <= curr_unique) {
                    idx = s[end++] - 'a';
                    if (!map[idx]) unique++;
                    map[idx]++;
                    if (map[idx] == k) count++;
                } else {
                    idx = s[start++] - 'a';
                    if (map[idx] == 1) unique--;
                    else if (map[idx] == k) count--;
                    map[idx]--;
                }
                if (unique == curr_unique && count == unique) {
                    result = max(result, end-start);
                }       
            }
        }
        return result;
    }

    int findUnique(string s) {
        unordered_set<char> set;
        int count = 0;
        
        for (const char& c : s) {
            if (!set.count(c)) {
                set.insert(c);
                count++;
            }
        }
        return count;
    }
};