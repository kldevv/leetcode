/*
Number: 9
Topic: Palindrome Number
Date: 2021/5/29
Rate: Hard
https://leetcode.com/problems/palindrome-number/

Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

Constraints:
* -231 <= x <= 231 - 1
 

Follow up: Could you solve it without converting the integer to a string?

*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x <= 9)
            return true;
        // 翻轉數字後比較
        return (double)x == reverseNum(x);


    }
    double reverseNum(int x) {
        double rev = 0;
        while (x > 0) {
            rev = rev*10 + x%10;
            x /= 10;
        }
        return rev;
    }
};