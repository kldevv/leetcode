/*
Number: 772
Topic: Basic Calculator III
Date: 2021/11/8
Rate: Hard
https://leetcode.com/problems/basic-calculator-iii/

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, '+', '-', '*', '/' operators, and open '(' and closing parentheses ')'. The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Constraints:
    * 1 <= s <= 104
    * s consists of digits, '+', '-', '*', '/', '(', and ')'.
    * s is a valid expression.
*/

class Solution {
public:
    int calculate(string s) {
        int resultBasic = 0;
        int resultPremium = 1;
        int operatorBasic = '+';
        int operatorPremium = '*';

        stack<int> resultStackBasic;
        stack<int> resultStackPremium;
        stack<char> operatorStackBasic;
        stack<char> operatorStackPremium;

        for (int c = 0; c < s.size(); c++) {
            if (isdigit(s[c])) {
                int num = 0;
                while (c < s.size() && isdigit(s[c])) {
                    num *= 10;
                    num += s[c++]-'0';
                }
                resultPremium = (operatorPremium == '*') ? resultPremium*num : resultPremium/num;
                c--;
            }
            else if (s[c] == '(') {
                // store status
                resultStackBasic.push(resultBasic);
                resultStackPremium.push(resultPremium);
                operatorStackBasic.push(operatorBasic);
                operatorStackPremium.push(operatorPremium);
                // reset status
                resultBasic = 0;
                resultPremium = 1;
                operatorBasic = '+';
                operatorPremium = '*';
            }
            else if (s[c] == ')') {
                int num = (operatorBasic == '+') ? resultBasic+resultPremium : resultBasic-resultPremium;
                // restore status
                resultBasic = resultStackBasic.top();
                resultPremium = resultStackPremium.top();
                operatorBasic = operatorStackBasic.top();
                operatorPremium = operatorStackPremium.top();

                resultStackBasic.pop();
                resultStackPremium.pop();
                operatorStackBasic.pop();
                operatorStackPremium.pop();

                resultPremium = (operatorPremium == '*') ? resultPremium*num : resultPremium/num;       
            }
            else if (s[c] == '*' || s[c] == '/') {
                operatorPremium = s[c];
            }
            else if (s[c] == '+' || s[c] == '-') {
                resultBasic = (operatorBasic == '+') ? resultBasic+resultPremium : resultBasic-resultPremium;
                resultPremium = 1;
                operatorPremium = '*';
                operatorBasic = s[c];
            }
        }
        return (operatorBasic == '+') ? resultBasic+resultPremium : resultBasic-resultPremium;
    }
};