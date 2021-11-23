/*
Number: 69
Topic: Sqrt(x)
Date: 2021/6/5
Rate: Easy
https://leetcode.com/problems/sqrtx/

Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

Constraints:
* 0 <= x <= 231 - 1

*/

class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x, mid = 0;

        // binary search
        while (left <= right) {
            mid = left + (right-left)/2;
            // upper boundary
            if (mid <= x/mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        // upper boundary
        return right;
    }
};