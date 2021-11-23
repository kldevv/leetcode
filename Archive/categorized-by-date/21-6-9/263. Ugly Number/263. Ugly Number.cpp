/*
Number: 263
Topic: Ugly Number
Date: 2021/6/9
Rate: Easy
https://leetcode.com/problems/ugly-number/

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return true if n is an ugly number.

Constraints:
* -2^31 <= n <= 2^31 - 1

*/
class Solution {
public:
    bool isUgly(int n) {
    	// 0 == false
    	if (!n)
    		return false;

    	// 嘗試去除 2, 3, 5 直到沒辦法再除，也順便除除 4，反正是 2 的平方，一定沒辦法除盡，但是會讓 code 更簡單
        for (int i = 2; i < 6; i++) {
        	while (n % i == 0) {
        		n /= i;
        	}
        }
        return (n == 1);
    }
};