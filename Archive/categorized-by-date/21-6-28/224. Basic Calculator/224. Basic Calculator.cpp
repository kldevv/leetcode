/*
Number: 224
Topic: Basic Calculator
Date: 2021/6/28
Rate: Hard
https://leetcode.com/problems/decode-string/

Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Constraints:
* 1 <= s.length <= 3 * 105
* s consists of digits, '+', '-', '(', ')', and ' '.
* s represents a valid expression.
* Every number and running calculation will fit in a signed 32-bit integer.

*/

class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sign = 1;
        stack<int> numStk;
        stack<int> signStk;

        for (int i = 0; i < s.size(); i++) {
            int num = 0;
            while (isdigit(s[i])) {
                num *= 10;
                num += s[i++] - '0';
            }

            result += sign*num; // 看看要怎麼對付新的數字，以最後一個 +/- 為主

            if (s[i] == '+')
                sign = 1;
            if (s[i] == '-')
                sign = -1;

            if (s[i] == '(') { 
                numStk.push(result); // 遇到上括弧，把括弧前的結果存進 stack 裡，專心對付括弧內的東西
                signStk.push(sign); // 也要記住要怎麼對付括弧內的結果
                result = 0;
                sign = 1;
            }

            if (s[i] == ')' && !signStk.empty()) { // 如果一開頭的 (5)+1 這種我們就不理他，因為上括弧前面沒有運算子
                result = numStk.top() + signStk.top()*result; // 把括弧前的結果拿出來，看看要怎麼對付括弧內的結果
                signStk.pop();
                numStk.pop();
            }
        }
        return result;
    }
};