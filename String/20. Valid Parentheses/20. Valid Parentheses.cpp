/*
Number: 20
Topic: Valid Parentheses
Date: 2021/11/5
Rate: Easy
https://leetcode.com/problems/valid-parentheses/

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

Constraints:
    * 1 <= s.length <= 104
    * s consists of parentheses only '()[]{}'.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> openParentheses;
        for (char c : s) {
            if (isOpen(c)){
                openParentheses.push(c);
            }
            else {
                if (openParentheses.empty() || openParentheses.top() != getOpen(c))
                    return false;
                openParentheses.pop();
            }
        }
        return openParentheses.empty();
    }

    bool isOpen(char c) {
        return (c == '{') || (c == '[') || (c == '(');
    }

    char getOpen(char c) {
        switch (c) {
            case ')':
                return '(';
            case '}':
                return '{';
            case ']':
                return '[';
            default:
                return '*';
        }
    }
};
