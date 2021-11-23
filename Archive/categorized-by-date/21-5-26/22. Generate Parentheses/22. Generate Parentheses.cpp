/*
Number: 22
Topic: Generate Parentheses
Date: 2021/5/26
Rate: Medium
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Constraints:

* 1 <= n <= 8

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        generateParenthesis(out, "", n, 0);
        return out;
    }

    void generateParenthesis(vector<string>& out, string temp, int left, int right) {
        if (!right && !left) {
            out.push_back(temp);
            return;
        }

        if (left > 0)
            // 加入一個 left 之後，代表剩餘的 left 變得更少了，而剩餘的 right 則可以多一
            generateParenthesis(out, temp+"(", left-1, right+1);
        if (right > 0)
            // 加入一個 rigth 之後，剩餘的 right 變少，而 left 不變
            generateParenthesis(out, temp+")", left, right-1);
    }
};