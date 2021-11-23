/*
Number: 241
Topic: Different Ways to Add Parentheses
Date: 2021/11/17
Rate: Medium
https://leetcode.com/problems/different-ways-to-add-parentheses/

Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

Constraints:
    * 1 <= expression.length <= 20
    * expression consists of digits and the operator '+', '-', and '*'.
    * All the integer values in the input expression are in the range [0, 99].
*/
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;

        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (ispunct(c)) {
                for (int prev : diffWaysToCompute(expression.substr(0, i))) {
                    for (int post : diffWaysToCompute(expression.substr(i + 1))) {
                        results.push_back((c == '*') ? prev * post : (c == '+') ? prev + post
                                                                                : prev - post);
                    }
                }
            }
        }
        if (results.empty())
            results.push_back(stoi(expression));
        return results;
    }
};
