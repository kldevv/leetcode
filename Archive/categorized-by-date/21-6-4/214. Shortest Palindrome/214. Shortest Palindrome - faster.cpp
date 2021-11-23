/*
Number: 214
Topic: Shortest Palindrome
Date: 2021/6/4
Rate: Hard
https://leetcode.com/problems/shortest-palindrome/

You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

Constraints:
* 0 <= s.length <= 5 * 104
* s consists of lowercase English letters only.

*/

class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());

        string cat = s + '&' + r;
        // 用 KMP table 找到 r 的 suffix(後半段) 和 prefix(前半段) 重疊的部分，把重疊的部分移除，就可以找到 Shortest Palindrome
        int overlap = KMPtable(cat)[cat.size()-1];

        return r.substr(0, r.size()-overlap) + s;
    }

    vector<int> KMPtable(string s) {
        vector<int> table(s.size(), 0);
        int j = 0;

        // 更新每一個 index
        for (int i = 1; i < s.size(); i++) {
            // 接續前一個位置的尾巴，把他當成一的獨立的 substring
            j = table[i-1];
            // 如果新的位置沒有和新的 prefix 符合，就往前找更短的 prefix
            while (j > 0 && s[j] != s[i]) {
                j = table[j-1];
            }
            // 如果符合的話代表可以接續原本的尾巴，讓符合的 prefix 變得更長
            if (s[j] == s[i])
                table[i] = ++j;
        }
        return table;
    }
};