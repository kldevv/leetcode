/*
Number: 415
Topic: Add Strings
Date: 2021/7/30
Rate: Easy
https://leetcode.com/problems/add-strings/

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

Constraints:
* 1 <= s.length <= 105
* s consists of lowercase English letters.
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size()-1;
        int n2 = num2.size()-1;
        int carry = 0;
        string out;
        while (n1 >= 0 || n2 >= 0 || carry) {
            int sum = 0;
            if (n1 >= 0) {
                sum += num1[n1--]-'0';
            }
            if (n2 >= 0) {
                sum += num2[n2--]-'0';
            }
            sum += carry;
            carry = sum / 10;
            out += to_string(sum % 10);
        }

        reverse(out.begin(), out.end());
        return out;
    }
};