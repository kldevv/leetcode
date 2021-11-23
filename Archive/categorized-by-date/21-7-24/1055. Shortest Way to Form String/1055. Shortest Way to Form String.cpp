/*
Number: 1055
Topic: Shortest Way to Form String
Date: 2021/7/24
Rate: Medium
https://leetcode.com/problems/shortest-way-to-form-string/

From any string, we can form a subsequence of that string by deleting some number of characters (possibly no deletions).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. If the task is impossible, return -1.

Constraints:
* Both the source and target strings consist of only lowercase English letters from "a"-"z".
* The lengths of source and target string are between 1 and 1000.
*/

class Solution {
public:
    int shortestWay(string source, string target) {
        int m = source.size();
        int n = target.size();

        // map[i][t] 代表 character i + 'a' 在 source 字串 position t 之後第一個出現的在什麼位置， 0 代表後沒沒有字串了。
        vector<vector<int>> map(26, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            map[source[j]-'a'][j] = j + 1;
        }
        for (int i = 0; i < map.size(); i++) {
            int pre = 0;
            for (int t = m-1; t >= 0; t--) {
                if (map[i][t])
                    pre = map[i][t];
                map[i][t] = pre;
            }
        }

        int j = 0;
        int substring = 0;
        for (int i = 0; i < n; i++) {
            if (!map[target[i]-'a'][0])
                return -1;

            j = map[target[i]-'a'][j];

            if (!j) { // 代表後面沒有字串了，要重新開始，這一輪也沒有搜尋到東西
                substring += 1;
                i--;
            }
            else if (j == m) { // 代表後面沒有字串了，要重新開始，這一輪搜尋到的是最後一個 character。
                j = 0;
                substring += 1;
            }
        }
        if (j)
            substring += 1;

        return substring;
    }
};