/*
Number: 191
Topic: Number of 1 Bits
Date: 2021/7/2
Rate: Easy
https://leetcode.com/problems/number-of-1-bits/

Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note:
* Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
* In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.

Constraints:
* The input must be a binary string of length 32.

Follow up: If this function is called many times, how would you optimize it?

*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n) {
            // n &= (n-1) 丟掉最後一個 1 bit
            n &= (n-1);
            result++;
        }
        return result;
    }
};