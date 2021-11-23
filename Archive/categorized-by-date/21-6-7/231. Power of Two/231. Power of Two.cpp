/*
Number: 231
Topic: Power of Two
Date: 2021/6/7
Rate: Easy

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

Constraints:
* -231 <= n <= 231 - 1
 
Follow up: Could you solve it without loops/recursion?

*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // negative and zero is not a power of 2
        if(n <= 0) 
            return false;
        // the power of 2 must have a bit representation containing only 1, 1:
        //   ( 64 32 16 8 4 2 1 )
        //  2 = 0  0  0  0 0 1 0
        //  4 = 0  0  0  0 1 0 0
        // 64 = 1  0  0  0 0 0 0  
        // if we take them and minus 1, say 64 for example
        // 63 = 0  1  1  1 1 1 1
        // All the bit will be the opposite bit

        // 5 = 101
        // 4 = 100
        // if we have more than 1 bit then the most significant bit will remain same thus their & is not zero.
        return !(n & (n-1));

        // or
        //recap :   x&(-x) : tells the last set bit
        // : x  = x - x&-x removes the last set bit
        // we can use this method
    }
};