/*
Number: 76
Topic: Minimum Window Substring
Date: 2021/6/2
Rate: Hard
https://leetcode.com/problems/minimum-window-substring/

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

Constraints:
* m == s.length
* n == t.length
* 1 <= m, n <= 10^5
* s and t consist of uppercase and lowercase English letters.
 
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, end = 0, counter = 0;
        int min_start = 0, min_len = INT_MAX;

        vector<int> map(128, 0);

        // 先做 hash
        for (const char& c : t) {
            map[c]++;
        }

        while (end < s.size()) {
            // 如果是在 t 表裡面的數字，在還有缺數時，會 > 0
            if (map[s[end]] > 0) 
                counter++;
            // end 往前移動一個，把收集到的數字 -1
            map[s[end++]]--;

            // t 表裡的數字都搜集完成了
            while (counter == t.size()) {
                // 更新最小值
                if (end-start < min_len) {
                    min_start = start;
                    min_len = end-start;
                }
                // 剛好 0 時，代表我們搜集 t 表裡的數字是剛剛好的，而這次 move 會把他排除
                // 代表我們又將缺一個數字
                if (map[s[start]] == 0)
                        counter--;
                // 把這個 move 移除的數字+1
                map[s[start++]]++;
            }
        }
        return (min_len == INT_MAX) ? "" : s.substr(min_start, min_len);
    }
};