/*
Number: 306
Topic: Additive Number
Date: 2021/6/9
Rate: Medium
https://leetcode.com/problems/ugly-number-ii/

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

Constraints:
* 1 <= n <= 1690

*/
class Solution {
public:
    bool isAdditiveNumber(string num) {
        // DFS
        // 第三個字串的長度 > i && 第三個字串的長度 > j
        for (int i = 1; i <= num.size()/2 ; i++) {
            // i == 第一個字串的長度
            for (int j = 1; max(i, j) <= num.size()-i-j; j++) {
                // j == 第二個字串的長度
                // recursively check
                if (isValid(0, i, j, num))
                    return true;
            }
        }
        return false;
    }

    bool isValid(int start, int len1, int len2, string& num) {
        // 檢查一二數字相加後，是否等於相對應的第三個數字

        // leading zero
        if (len1 > 1 && num[start] == '0')
            return false;
        // leading zero
        if (len2 > 1 && num[start+len1] == '0')
            return false;
        // 代表只有兩個數字，已經檢查到尾巴
        if (start+len1+len2 == num.size())
            return true;

        string s1 = num.substr(start, len1);    // 第一個數字
        string s2 = num.substr(start+len1, len2);   // 第二個數字

        long number_sum = stol(s1) + stol(s2);  // 第一第二數字相加
        string sum = to_string(number_sum);

        string s3 = num.substr(start+len1+len2, sum.size());    // 長度相同的第三個數字  

        // 如果一二數字相加等於第三數字
        if (sum == s3) {
            return isValid(start+len1, s2.size(), s3.size(), num);  // 就在檢查第二第三數字是否等於第四數字
        }
        return false;
    }

};