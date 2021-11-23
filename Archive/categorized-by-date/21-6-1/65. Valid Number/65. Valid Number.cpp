/*
Number: 65
Topic: Valid Number
Date: 2021/6/1
Rate: Medium
https://leetcode.com/problems/text-justification/


A valid number can be split up into these components (in order):

    1. A decimal number or an integer.
    2. (Optional) An 'e' or 'E', followed by an integer.

A decimal number can be split up into these components (in order):

    1. (Optional) A sign character (either '+' or '-').
    2. One of the following formats:
    3. One or more digits, followed by a dot '.'.
    4. One or more digits, followed by a dot '.', followed by one or more digits.
    5. A dot '.', followed by one or more digits.

An integer can be split up into these components (in order):

    1. (Optional) A sign character (either '+' or '-').
    2. One or more digits.
    3. For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

Given a string s, return true if s is a valid number.

Constraints:
* 1 <= s.length <= 20
* s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.
 
*/

class Solution {
public:
    bool isNumber(string s) {
        int i = 0, j = s.size()-1, digits = 0, dot = 0;

        for (; i <= j && isspace(s[i]); i++) {}
        for (; i <= j && isspace(s[j]); j--) {}
        if (i > j) return false;

        if (s[i] == '+' || s[i] == '-') i++;
        if (i > j) return false;

        for (; i <= j && (isdigit(s[i]) || s[i] == '.'); i++) {
            isdigit(s[i]) ? digits++ : dot++;
        }
        if (!digits || dot > 1) return false;
        else if (i > j) return true;

        if (i <= j && tolower(s[i]) == 'e') {
            i++;
            if (s[i] == '+' || s[i] == '-') i++;
        } else {
            return false;
        }
        if (i > j) return false;

        for (; i <= j; i++) {
            if (isdigit(s[i]))
                digits++;
            else
                return false;
        }
        return true;
    }
};