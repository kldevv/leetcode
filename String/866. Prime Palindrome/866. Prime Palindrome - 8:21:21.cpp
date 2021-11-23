/*
Number: 866
Topic: Prime Palindrome
Date: 2021/8/21
Rate: Medium
https://leetcode.com/problems/prime-palindrome/

Given an integer n, return the smallest prime palindrome greater than or equal to n.

An integer is prime if it has exactly two divisors: 1 and itself. Note that 1 is not a prime number.

For example, 2, 3, 5, 7, 11, and 13 are all primes.
An integer is a palindrome if it reads the same from left to right as it does from right to left.

For example, 101 and 12321 are palindromes.
The test cases are generated so that the answer always exists and is in the range [2, 2 * 108].

Constraints:
* 1 <= n <= 10^8
*/

class Solution {
public:
    int primePalindrome(int n) {
        if (n >= 8 && n <= 11)
            return 11;

        for (int i = 1; i < 100000; i++) {
            string s = to_string(i);
            string r(s.rbegin(), s.rend());
            int cand = stoi(s + r.substr(1));

            if (isPrime(cand) && cand >= n)
                return cand;
        }
        return -1;
    }

    bool isPrime(int n) {
        if (n <= 2 || n % 2 == 0) 
            return (n == 2);
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};