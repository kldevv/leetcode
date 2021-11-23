/*
Number: 371
Topic: Sum of Two Integers
Date: 2021/6/29
Rate: Medium
https://leetcode.com/problems/sum-of-two-integers/

Given two integers a and b, return the sum of the two integers without using the operators + and -.

Constraints:
* -1000 <= a, b <= 1000
*/

class Solution {
public:
    int getSum(int a, int b) {
        int c;
        while (b) {
            c = (a ^ b);
            b = (unsigned int)(a & b) << 1;
            a = c;
        }
        return a;
    }
};