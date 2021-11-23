/*
Number: 32
Topic: Longest Valid Parentheses
Date: 2021/5/29
Rate: Hard
https://leetcode.com/problems/longest-valid-parentheses/

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Constraints:
* 0 <= s.length <= 3 * 104
* s[i] is '(', or ')'.
 
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int _max = 0;
        stack<int> idx;
        idx.push(-1);

        for (int i = 0; i < s.size(); i++) {
            // 只要前面有還沒成對的括弧，就拿上一個括弧來比較，如果一樣，就增加長度
            if (idx.top()!=-1 && s[i]==')' && s[idx.top()]=='(') {
                idx.pop();
                // i - idx.top() 代表目前距離上一個 stack 有多遠，只要中間都是有成對的括弧，中間就會一直 pop 然後有一個空白的區間，那個區間就是長度
                // 而拿到長度的方法就是 下括弧的位置 - 上括弧上一個的位置
                // (()(()) 像這個例子，到最後一個 ) 時，前面全部的位置都會被 pop 光，直到剩下第一個 (，此時把最後一個 ) 的位置減去第一個 ( 就是長度了
                _max = max(_max, i-idx.top());
            // 不一樣的話就繼續累積 stack
            } else {
                idx.push(i);
            }
        }
        return _max;



    }
};