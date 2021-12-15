/*
Number: 22
Topic: Longest Valid Parentheses
Date: 2021/11/29
Rate: Medium
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Constraints:
    * 1 <= n <= 8
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
   private:
    void generateParenthesis(int haveOpen, int haveClose, string& currentResult, vector<string>& finalResults) {
        if (haveOpen == 0 && haveClose == 0) {
            finalResults.push_back(currentResult);
            return;
        }

        if (haveOpen) {
            currentResult += '(';
            generateParenthesis(haveOpen - 1, haveClose + 1, currentResult, finalResults);
            currentResult.pop_back();
        }
        if (haveClose) {
            currentResult += ')';
            generateParenthesis(haveOpen, haveClose - 1, currentResult, finalResults);
            currentResult.pop_back();
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        /*
        Base:
            If haveClose == 0, haveClose == 0:
                return

        Recurrence Relation:
            If haveClose > 0:
                Add close parenthese
                haveClose - 1
                >> recur
            If haveOpen > 0:
                Add open parenthese
                haveOpen - 1
                haveClose + 1
                >> recur
        */
        vector<string> results;
        string medium = "";
        generateParenthesis(n, 0, medium, results);
        return results;
    }
};