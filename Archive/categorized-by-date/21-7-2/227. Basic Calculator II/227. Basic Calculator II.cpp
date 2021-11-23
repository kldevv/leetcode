/*
Number: 227
Topic: Basic Calculator II
Date: 2021/7/2
Rate: Medium
https://leetcode.com/problems/basic-calculator-ii/

Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().


Constraints:
* 1 <= s.length <= 3 * 105
* s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
* s represents a valid expression.
* All the integers in the expression are non-negative integers in the range [0, 231 - 1].
* The answer is guaranteed to fit in a 32-bit integer.

*/

class Solution {
public:
    int calculate(string s) {
        char ops = '+';
        int result = 0;
        int prevNum = 0;

        for (int i = 0; i < s.size(); i++) {
            if (isspace(s[i]))
                continue;
            if (isOperator(s[i]))
                ops = s[i];
            if (isdigit(s[i])) {
                int num = 0;
                while (isdigit(s[i])) {
                    num *= 10;
                    num += s[i++]-'0';
                }
                i--;

                if (ops == '-') {
                    num *= -1;
                }
                if (ops == '*' || ops == '/') {
                    result -= prevNum;
                    (ops == '*') ? prevNum *= num  : prevNum /= num;
                    num = prevNum;
                }
                result += num;
                prevNum = num;
            }
        }
        return result;
    }
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }
};