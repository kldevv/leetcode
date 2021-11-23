/*
Number: 139
Topic: Word Break
Date: 2021/6/21
Rate: Medium
https://leetcode.com/problems/word-break/

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.


Constraints:
* 1 <= s.length <= 300
* 1 <= wordDict.length <= 1000
* 1 <= wordDict[i].length <= 20
* s and wordDict[i] consist of only lowercase English letters.
* All the strings of wordDict are unique.

*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        // dp[i] 紀錄字串長度為 i 時，是否可以被分解
        vector<bool> dp(n+1, false);
        dp[0] = true;

        // 先把字都裝到 set 裡面，這樣查找時只要 O(1)
        unordered_set<string> set;
        for (const string& word : wordDict) {
            set.insert(word);
        }

        // 建立長度 1 到 n 的 dp
        for (int i = 1; i <= n; i++) {
            // 當長度為 i 時，看看前面 j 位置結尾的字串是否可以被拆解，可以被拆解的話，就看看 j 之後的字串到目前長度有沒有在字典裡
            // 有就代表整個 i 長度可以被拆解成 j, i-j 長度的兩的字，而 j 長度是否又可以被拆解我們就不管他
            // 因為之前已經計算過了
            for (int j = 0; j < i; j++) {
                if (dp[j] && set.count(s.substr(j, i-j))) {
                    dp[i] = true;
                    // 有一種組合就夠了，那就 break
                    break;
                }
            }
        }
        // O(n^3) qq
        return dp[n];
    }
}; 