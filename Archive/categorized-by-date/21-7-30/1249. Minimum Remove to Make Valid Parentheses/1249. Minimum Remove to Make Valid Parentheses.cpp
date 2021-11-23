/*
Number: 1249
Topic: Minimum Remove to Make Valid Parentheses
Date: 2021/7/30
Rate: Medium
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

Given a string s of '(' , ')' and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:
* It is the empty string, contains only lowercase characters, or
* It can be written as AB (A concatenated with B), where A and B are valid strings, or
* It can be written as (A), where A is a valid string.

Constraints:
* 1 <= s.length <= 10^5
* s[i] is one of  '(' , ')' and lowercase English letters.
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> toBeRemoved;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                toBeRemoved.push(i);
            if (s[i] == ')') {
                if (toBeRemoved.empty() || s[toBeRemoved.top()] == ')')
                    toBeRemoved.push(i);
                else
                    toBeRemoved.pop();
            }
        }

        string out;
        for (int i = s.size()-1; i >= 0; i--) {
            if (toBeRemoved.empty() || i != toBeRemoved.top())
                out += s[i];
            else 
                toBeRemoved.pop();
        }
        reverse(out.begin(), out.end());
        return out;
    }
};