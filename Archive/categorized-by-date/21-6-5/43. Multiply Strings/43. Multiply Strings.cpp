/*
Number: 43
Topic: Multiply Strings
Date: 2021/6/5
Rate: Medium
https://leetcode.com/problems/multiply-strings/

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Constraints:
* 1 <= num1.length, num2.length <= 200
* num1 and num2 consist of digits only.
* Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        // 先建立一個 container
        string ans(m + n, '0');
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // 對每一層做直式運算
                // 進位的部分直接丟到下一層去
                int sum = (num1[i] - '0') * (num2[j] - '0') + (ans[i + j + 1] - '0');
                ans[i + j + 1] = sum % 10 + '0';
                ans[i + j] += sum / 10;
            }
        }
        // 丟到 leading zero
        for (int i = 0; i < m + n; i++) {
            if (ans[i] != '0') {
                return ans.substr(i);
            }
        }
        return "0";
    }
};