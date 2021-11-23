/*
Number: 20
Topic: Valid Parentheses
Date: 2021/5/29
Rate: Easy
https://leetcode.com/problems/valid-parentheses/

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

* Open brackets must be closed by the same type of brackets.
* Open brackets must be closed in the correct order.

Constraints:
* 1 <= s.length <= 104
* s consists of parentheses only '()[]{}'.
 
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> dp;

        for (const char& c : s) {
            switch (c) {
                case '{': dp.push_back('}'); break;
                case '[': dp.push_back(']'); break;
                case '(': dp.push_back(')'); break;
                default:
                    if (dp.empty() || dp.top() != c) 
                        return false;
                    else
                        dp.pop();
            }
        }
        return dp.empty();
    }
};
