/*
Number: 342
Topic: Power of Four
Date: 2021/6/7
Rate: Easy

Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

Constraints:
* -23^1 <= n <= 23^1 - 1
 
Follow up: Could you solve it without loops/recursion?

*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        // 0xaaaaaaaa = 10101010101010101010101010101010 (偶数位为1，奇数位为0）
        // 0x55555555 = 1010101010101010101010101010101 (偶数位为0，奇数位为1）
        // 0x33333333 = 110011001100110011001100110011 (1和0每隔两位交替出现)
        // 0xcccccccc = 11001100110011001100110011001100 (0和1每隔两位交替出现)
        // 0x0f0f0f0f = 00001111000011110000111100001111 (1和0每隔四位交替出现)
        // 0xf0f0f0f0 = 11110000111100001111000011110000 (0和1每隔四位交替出现)

        // power of 4 has 3 features:
        // 1. >0
        // 2. Only have 1, 1 bit (as the power of 2)
        // 3. 1 bit apears in the odd position, e.g. 1 = 0001, 4 = 0100
        return num > 0 && (num&(num-1)) == 0 && (num & 0x55555555) != 0;
    }
};