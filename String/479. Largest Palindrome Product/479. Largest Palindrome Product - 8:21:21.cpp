/*
Number: 479
Topic: Largest Palindrome Product
Date: 2021/8/21
Rate: Hard
https://leetcode.com/problems/largest-palindrome-product/

Given an integer n, return the largest palindromic integer that can be represented as the product of two n-digits integers. Since the answer can be very large, return it modulo 1337.

Constraints:
* 1 <= n <= 8
*/

class Solution {
private:
    int MOD = 1337;
public:
    int largestPalindrome(int n) {
        if (n == 1)
            return 9;

        int upper = pow(10, n) - 1;
        int lower = pow(10, n-1);
        
        for (int i = upper; i >= lower; i--) {
            long cand = buildPalindrome(i);
            for (long j = upper; j*j >= cand; j--) {
                if (cand % j == 0)
                    return cand % MOD;
            }
        }
        return -1;
    }

    long buildPalindrome(int A) {
        string B  = to_string(A);
        reverse(B.begin(), B.end());
        return stol(to_string(A) + B);
    }
};