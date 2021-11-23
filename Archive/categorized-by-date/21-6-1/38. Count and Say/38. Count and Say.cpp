/*
Number: 38
Topic: Count and Say
Date: 2021/6/1
Rate: Medium
https://leetcode.com/problems/count-and-say/


Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221 
 6.     312211
 7.     13112221
 8.     1113213211
 9.     31131211131221
 10.   13211311123113112211
From the examples you can see, the (i+1)th sequence is the "count and say" of the ith sequence!


Constraints:
* 1 <= s.length <= 2 * 10^5
* s consists only of printable ASCII characters.
 
*/

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        if (n == 2)
            return "11";

        int count = 1;
        string out;
        string s = countAndSay(n-1);
        // 開始數數
        for (int i = 1; i < s.size(); i++) {
            // 一樣的就 + 1
            if (s[i] == s[i-1])
                count++;
            // 不一樣的就輸出上一個
            else {
                out += to_string(count) + s[i-1];
                count = 1;
            }
        }
        // 最後一個也要輸出
        out += to_string(count) + s[s.size()-1];

        return out;

    }

};