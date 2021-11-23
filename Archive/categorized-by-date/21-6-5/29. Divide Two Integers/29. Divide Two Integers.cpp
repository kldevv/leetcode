/*
Number: 29
Topic: Divide Two Integers
Date: 2021/6/5
Rate: Medium
https://leetcode.com/problems/divide-two-integers/

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, assume that your function returns 231 − 1 when the division result overflows.

Constraints:
* -231 <= dividend, divisor <= 231 - 1
* divisor != 0
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        // edge case 1
        if (divisor == INT_MIN) {
            if (dividend == INT_MIN) {
                return 1;
            } else {
                return 0;
            }
        }
        if (dividend == INT_MIN) {
            if (divisor == -1) {
                return INT_MAX;
            } 
            if (divisor > 0) {
                return -1+divide(dividend+divisor, divisor);
            } else if (divisor < 0) {
                return 1+divide(dividend-divisor, divisor);
            }
        }
        
        // determine sign
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            sign = 0;
        }
        
        // absolute value
        dividend = dividend > 0 ? dividend : -dividend;
        divisor = divisor > 0 ? divisor : -divisor;

        // bit shift right 1 等於變成兩倍
        // 這邊一步一步減去 divisor，而 divisor 又是以兩倍速度成長
        // 當 divisor 變得太大時，就 reset divisor，又從新開始
        // 快慢快的感覺
        // tc O(logN^2)
        int remainder = dividend, quotient = 0, shift = 0;
        while (remainder >= divisor) {
            shift = 0;
            while ((divisor<<shift) <= remainder && (divisor<<shift) > 0) {
                ++shift;
            }
            --shift;
            quotient += (1<<shift);
            remainder -= (divisor<<shift);
        }

        if (!sign) 
            quotient = -quotient;

        return quotient;
    }
};