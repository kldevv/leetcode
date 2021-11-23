/*
Number: 67
Topic: Add Binary
Date: 2021/6/5
Rate: Easy
https://leetcode.com/problems/add-binary/

Given two binary strings a and b, return their sum as a binary string.

Constraints:
* 1 <= a.length, b.length <= 104
* a and b consist only of '0' or '1' characters.
* Each string does not contain leading zeros except for the zero itself.

*/

class Solution {
public:
    string addBinary(string a, string b) {
        int len_min = min(a.size(), b.size());
        int len_max = max(a.size(), b.size());
        string base = (a.size() > b.size()) ? a : b;
        int sum = 0, digit = 0, carry = 0;

        for (int i = 1; i <= len_max; i++) {
            // 如果兩邊都還有數字，就相加，加上從上一個 digit 的進位
            if (i <= len_min)
                sum = a[a.size()-i]-'0' + b[b.size()-i]-'0' + carry;
            // 沒有的話就純粹跑 digit
            else
                sum = base[len_max-i]-'0' +carry;
            // 更新這層的 digit 與要進位的數字
            carry = sum / 2;
            digit = sum % 2;

            base[len_max-i] = digit+'0';
        }

        if (carry)
            // 如果還有進位沒完成，在最前面加入
            base = "1" + base;

        return base;
    }
};