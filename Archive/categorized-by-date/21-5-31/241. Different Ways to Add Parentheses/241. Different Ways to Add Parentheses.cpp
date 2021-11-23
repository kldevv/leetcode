/*
Number: 241
Topic: Different Ways to Add Parentheses
Date: 2021/5/29
Rate: Medium
https://leetcode.com/problems/different-ways-to-add-parentheses/

Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

Constraints:
* 1 <= expression.length <= 20
* expression consists of digits and the operator '+', '-', and '*'.
 
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;
        // recursive 算法
        for (int i = 0; i < expression.size(); i++) {
            // 遇到運算子時，運算子前的算式和運算子之後的算式分別再帶入 function
            if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-') {
                vector<int> result1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> result2 = diffWaysToCompute(expression.substr(i+1));
                // 得到運算子前後的結果 (是一個 vector 因為前後的算式也有多種可能)
                for (const int& r1 : result1) {
                    for (const int& r2 : result2) {
                        // 把前後的結果都帶入該運算子得出結果
                        switch (expression[i]) {
                            case '*':
                                result.push_back(r1 * r2);
                                break;
                            case '+':
                                result.push_back(r1 + r2);
                                break;
                            default:
                                result.push_back(r1 - r2);
                                break;                                
                        }
                    }
                }
            }
        }

        // base case 只有數字時
        if (result.empty())
            result.push_back(stoi(expression));

        return result;
    }
};