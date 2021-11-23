/*
Number: 150
Topic: Evaluate Reverse Polish Notation
Date: 2021/6/26
Rate: Medium
https://leetcode.com/problems/evaluate-reverse-polish-notation/

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

Constraints:
* 1 <= tokens.length <= 10^4
* tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (const string& s : tokens) {
            // 是否為正數或是負數
            if (isdigit(s[0]) || (s[0] == '-' && s.size() > 1)) {
                stk.push(stoi(s));
            // 如果是運算字，把最上面那兩個數字拿出來，做運算，再把結果放回去
            } else {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                switch (s[0]) {
                    case '+':
                        num2 += num1;
                        break;
                    case '-':
                        num2 -= num1;
                        break;
                    case '*':
                        num2 *= num1;
                        break;
                    case '/':
                        num2 /= num1;
                        break;
                    default:
                        break;
                }
                stk.push(num2);
            }
        }
        return stk.top();
    }
};