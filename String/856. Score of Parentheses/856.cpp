/*
<LeetCodePracticeC++>
    
- Name: 856. Score of Parentheses
- Difficulty: Medium
- URL: https://leetcode.com/problems/score-of-parentheses/
- Description: 

    Given a balanced parentheses string s, return the score of the string.

    The score of a balanced parentheses string is based on the following rule:

        - "()" has score 1.
        - AB has score A + B, where A and B are balanced parentheses strings.
        - (A) has score 2 * A, where A is a balanced parentheses string.

- Constraints:
    - 2 <= s.length <= 50
    - s consists of only '(' and ')'.
    - s is a balanced parentheses string.

- Date: 12/13/2021

</LeetCodePracticeC++>
*/
#include <stack>
#include <cmath>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        /*
        stack
        (()())(())

        if "(":
            stack.Push()
        else if ")"":
            if stack.top() == currentIdx-1:
                score += pow(2, stack.size()-1)
            stack.pop();
        */
        stack<int> stk;
        int score = 0;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') {
                stk.push(i);
            } else if (c == ')') {
                if (i-1 == stk.top()) {
                    score += pow(2, stk.size()-1);
                }
                stk.pop();
            }
        }
        return score;
    }
};
