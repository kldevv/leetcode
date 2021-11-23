/*
Number: 8
Topic: String to Integer (atoi)
Date: 2021/6/5
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

Constraints:
* 0 <= s.length <= 200
* s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.

*/

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        for (; i < s.size() && !isdigit(s[i]) && !isSign(s[i]); i++) {
            if (!isspace(s[i]))
                return 0;
        }
        if (isSign(s[i]))
            sign = (s[i++] == '+') ? 1 : -1;

        int result = 0;
        for (; i < s.size() && isdigit(s[i]); i++) {
            int digits = sign*(s[i]-'0');
            // overflow check
            if (sign == 1) {
                if ((INT_MAX-digits)/10 < result )
                    return INT_MAX;
            } else {
                if ((INT_MIN-digits)/10 > result)
                    return INT_MIN;
            }
            result *= 10;
            result += digits;
        }
        return result;
    }

    bool isSign(char c) {
        return (c == '+' || c == '-') ? true : false;
    }
};