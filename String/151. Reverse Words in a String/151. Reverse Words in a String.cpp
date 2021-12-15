/*
Number: 151
Topic: Reverse Words in a String
Date: 2021/12/5
Rate: Medium
https://leetcode.com/problems/reverse-words-in-a-string/

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Constraints:
    * 1 <= s.length <= 104
    * s contains English letters (upper-case and lower-case), digits, and spaces ' '.
    * There is at least one word in s.

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
*/

#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        /*
        Example:
            ..one.is..two...
            two.is.one

            1. stripe extra whitespace
            2. reverse the entire string
            3. reverse words
        */
        stripe(s);
        reverse(s, 0, s.size() - 1);
        reverseSingleWord(s);
        return s;
    }

    void stripe(string& s) {
        int i = 0;
        int j = 0;
        bool delim = false;
        for (; j < s.size(); j++) {
            if (isalnum(s[j]) || (s[j] == ' ' && delim)) {
                if (s[j] == ' ') {
                    delim = false;
                } else {
                    delim = true;
                }
                swap(s[i++], s[j]);
            }
        }
        s = (s[i - 1] == ' ') ? s.substr(0, i - 1) : s.substr(0, i);
    }
    void reverseSingleWord(string& s) {
        int i = 0;
        int j = 0;
        for (; j < s.size(); j++) {
            if (s[j] == ' ') {
                reverse(s, i, j - 1);
                i = j + 1;
            }
        }
        reverse(s, i, s.size() - 1);
    }

    void reverse(string& s, int i, int j) {
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }
};