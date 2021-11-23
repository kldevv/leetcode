/*
Number: 13
Topic: Roman to Integer
Date: 2021/5/26
Rate: Easy
https://leetcode.com/problems/roman-to-integer/

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

Constraints:

* 1 <= s.length <= 15
* s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
* It is guaranteed that s is a valid roman numeral in the range [1, 3999].

*/

class Solution {
public:
    int romanToInt(string s) {
        int prev = 0, out = 0, sign = 1;
        for (int i = s.size()-1; i >= 0; i--) {
            char roman = s[i];
            int num;
            switch (roman) {
                case 'I':
                    num = 1;
                    break;
                case 'V':
                    num = 5;
                    break;
                case 'X':
                    num = 10;
                    break;
                case 'L':
                    num = 50;
                    break;
                case 'C':
                    num = 100;
                    break;
                case 'D':
                    num = 500;
                    break;
                default:
                    num = 1000;
                    break;
            }

            if (prev > num)
                sign = -1;
            else if (prev < num)
                sign = 1;
            prev = num;
            out += sign * num;
        }
        return out;
    }
};