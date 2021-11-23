/*
Number: 22
Topic: Generate Parentheses
Date: 2021/8/27
Rate: Medium
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Constraints:
* 1 <= n <= 8
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesis(n, 0, "", result);
        return result;
    }

    void generateParenthesis(int n, int k, string s, vector<string>& result) {
        if (n == 0 && k == 0) {
            result.push_back(s);
            return;
        }
        if (n > 0)
            generateParenthesis(n-1, k+1, s+'(', result);
        if (k > 0)
            generateParenthesis(n, k-1, s+')', result);
    }
};