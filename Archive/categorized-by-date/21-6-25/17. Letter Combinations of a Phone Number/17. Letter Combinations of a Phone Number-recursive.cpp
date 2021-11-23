/*
Number: 17
Topic: Letter Combinations of a Phone Number
Date: 2021/6/25
Rate: Medium
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Constraints:
* 0 <= digits.length <= 4
* digits[i] is a digit in the range ['2', '9'].

*/
class Solution {
public:
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<string> out;
        string temp = "";
        letterCombinations(digits, 0, temp, out);
        return out;
    }

    void letterCombinations(const string& digits, int i, string temp, vector<string>& out) {
        if (i == digits.size()) {
            out.push_back(temp);
            return;
        }

        for (char c : pad[digits[i]-'0']) {
            letterCombinations(digits, i+1, temp+c, out);
        }
    }
};