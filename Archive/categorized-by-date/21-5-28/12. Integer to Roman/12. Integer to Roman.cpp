/*
Number: 12
Topic: Integer to Roman
Date: 2021/5/28
Rate: Medium
https://leetcode.com/problems/integer-to-roman/

TRoman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

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

    * I can be placed before V (5) and X (10) to make 4 and 9. 
    * X can be placed before L (50) and C (100) to make 40 and 90. 
    * C can be placed before D (500) and M (1000) to make 400 and 900.

Given an integer, convert it to a roman numeral.

Constraints:
* 1 <= num <= 3999

*/

class Solution {
public:
    string intToRoman(int num) {
        string out;
        out += intToRoman(num/1000, '&', '%', 'M');
        num %= 1000;
        out += intToRoman(num/100, 'M', 'D', 'C');
        num %= 100;
        out += intToRoman(num/10, 'C', 'L', 'X');
        num %= 10;
        out += intToRoman(num, 'X', 'V', 'I');        
        return out;
    }

    string intToRoman(int num, char upper, char middle, char buttom) {
        cout << num;
        if (!num)
            return "";

        string out;
        if (num == 9) {
            out += buttom;
            out += upper;
        } else if (num >= 5) {
            out += middle;
            out += string((num-5), buttom);
        } else if (num == 4) {
            out += buttom;
            out += middle;
        } else {
            out += string(num, buttom);            
        }
        return out;
    }
};
