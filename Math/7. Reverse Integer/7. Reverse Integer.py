'''
Number: 7
Topic: Reverse Integer
Date: 2021/10/14
Rate: Medium
https://leetcode.com/problems/reverse-integer/

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Constraints:
    * -2^31 <= x <= 2^31 - 1
'''

class Solution:
    def reverse(self, x: int) -> int:
        if x == 0:
            return 0

        sign = 1
        if x < 0:
            sign = -1

        y = 0
        while x != 0:
            offset = (x - int(x / 10) * 10)
            if sign == 1: # number is positive
                if y > (((2 ** 31)-1) - offset) // 10:
                    return 0
            else: # number is negative
                if y < int((((2 ** 31) * -1) + offset) / 10):
                    return 0
            y *= 10
            y += offset
            x = int(x / 10)
        return y