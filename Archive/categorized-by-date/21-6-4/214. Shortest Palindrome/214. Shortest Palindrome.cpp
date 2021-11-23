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
        // tc: O(n^2)
        // brute force
    	if (s.empty())
    		return "";

    	string r = s;
        reverse(r.begin(), r.end());

        // 翻轉字串後比較，翻轉字串的後半和原本字串的前半
        // 如果一樣，就代表有重疊，只需回傳翻轉字串的前半加上原本的字串就可以

        // e.g.
        // s          dedcba
        // r[0:]      abcded    Nope...
        // r[1:]   (a)bcded     Nope...
        // r[2:]  (ab)cded      Nope...
        // r[3:] (abc)ded       Yes! Return abc + dedcba

        // the loop is O(n)
        for (int i = 0; i < s.size(); i++) {
            // checking substring is O(n) by itself
        	if (r.substr(i) == s.substr(0, s.size()-i))
        		return r.substr(0, i) + s;
        }
        return r+s;
    }
};