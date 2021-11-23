/*
Number: 8
Topic: tring to Integer (atoi)
Date: 2021/9/30
Rate: Medium
https://leetcode.com/problems/string-to-integer-atoi/

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

1. Read in and ignore any leading whitespace.
2. Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
3. Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
5. If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
6. Return the integer as the final result.

Notes:
    * Only the space character ' ' is considered a whitespace character.
    * Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.

Constraints:
    * 0 <= s.length <= 200
    * s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
*/

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long result = 0;
        int sign = 1;

        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < s.size() && isdigit(s[i])) {
            if (result > INT_MAX)
                break;
            result *= 10;
            result += s[i] - '0';
            i++;
        }
        return (sign > 0) ? min((long)INT_MAX, result) : max((long)INT_MIN, result * sign);
    }

};