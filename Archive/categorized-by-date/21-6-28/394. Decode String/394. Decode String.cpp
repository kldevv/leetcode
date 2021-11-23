/*
Number: 394
Topic: Decode String
Date: 2021/6/28
Rate: Medium
https://leetcode.com/problems/decode-string/

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Constraints:
* 1 <= s.length <= 30
* s consists of lowercase English letters, digits, and square brackets '[]'.
* s is guaranteed to be a valid input.
* All the integers in s are in the range [1, 300].

*/

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }

    string decodeString(string s, int& i ){
        string out;

        while (i < s.size() && s[i] != ']') {
            if (!isdigit(s[i])) {
                out += s[i++];
            }
            else {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num *= 10;
                    num += s[i++] - '0';
                }

                i++; // skip [
                string sInside = decodeString(s, i);
                i++; // skip ]

                while (num-- > 0) {
                    out += sInside;
                }
            }
        }

        return out;
    }
};