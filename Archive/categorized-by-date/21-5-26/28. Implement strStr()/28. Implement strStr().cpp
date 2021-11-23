/*
Number: 28
Topic: Implement strStr()
Date: 2021/5/26
Rate: Easy
https://leetcode.com/problems/implement-strstr/

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

Constraints:

0 <= haystack.length, needle.length <= 5 * 10^4
haystack and needle consist of only lower-case English characters

*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        if (haystack.empty())
            return -1;
        // brute  一個一個去對
        for (int i = 0; i < haystack.size(); i++) {
                for (int n = 0; n <= needle.size(); n++) {
                    if (n == needle.size())
                        return i;
                    if (haystack[i+n] != needle[n])
                        break;
                }
            }
        return -1;
    }
};