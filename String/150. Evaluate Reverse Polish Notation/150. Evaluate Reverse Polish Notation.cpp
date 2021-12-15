/*
Number: 150
Topic: https://leetcode.com/problems/evaluate-reverse-polish-notation/
Date: 2021/11/17
Rate: Medium
https://leetcode.com/problems/evaluate-reverse-polish-notation/

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

Constraints:
    * 1 <= tokens.length <= 104
    * tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/

#include <cctype>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   private:
    int operation(int a, int b, char ops) {
        switch (ops) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '/':
                return a / b;
            default:
                return a * b;
        }
    }
    bool isNumber(const string& s) {
        int i = 0;
        if (s[0] == '-' && s.size() > 1)
            i += 1;
        for (; i < s.size(); i++) {
            if (!isdigit(s[i]))
                return false;
        }
        return true;
    }

   public:
    int evalRPN(vector<string>& tokens) {
        /*
        stack

        if (token is alpha):
            stack.push(token)

        else:
            int a = stack.top()
            stack.pop()
            int b = stack.top()
            stack.pop()

            stack.push(a OPs b)

        return stack.top()
         */
        stack<int> result;

        for (string token : tokens) {
            if (isNumber(token)) {
                result.push(stoi(token));
            } else {
                int b = result.top();
                result.pop();
                int a = result.top();
                result.pop();
                result.push(operation(a, b, token[0]));
            }
        }
        return result.top();
    }
};