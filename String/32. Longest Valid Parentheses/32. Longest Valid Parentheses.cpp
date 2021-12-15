/*
Number: 32
Topic: Longest Valid Parentheses
Date: 2021/11/29
Rate: Hard
https://leetcode.com/problems/longest-valid-parentheses/

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Constraints:
    * 0 <= s.length <= 3 * 104
    * s[i] is '(', or ')'.
*/
#include <stack>
#include <string>

using namespace std;

class Solution {
   public:
    int longestValidParentheses(string s) {
        /*
        stack[idx of parenthesis to be match]
        currentValidLen = closeParenthesePos - prev(openParenthesePos)

        Base:
            invalidParenthesis.empty() = -1
        Recurrence Relation:
            if close*
                if stack.top == open*
                    stack.pop()
                    currentLen = currentIdx - stack.top()
                else 
                    stack.push()
            if open*
                stack.push()
        */

        stack<int> invalidParenthesesIdx;
        invalidParenthesesIdx.push(-1);
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {  // open*
                invalidParenthesesIdx.push(i);
            } else {  // close*
                int lastInvalidParentheseIdx = invalidParenthesesIdx.top();

                if (lastInvalidParentheseIdx != -1 && s[lastInvalidParentheseIdx] == '(') {
                    invalidParenthesesIdx.pop();
                    maxLen = max(maxLen, i - invalidParenthesesIdx.top());
                } else {
                    invalidParenthesesIdx.push(i);
                }
            }
        }
        return maxLen;
    }
};