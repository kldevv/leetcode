/*
Number: 906
Topic: Super Palindromes
Date: 2021/8/22
Rate: Hard
https://leetcode.com/problems/super-palindromes/

Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.

Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].

Constraints:
* 1 <= left.length, right.length <= 18
* left and right consist of only digits.
* left and right cannot have leading zeros.
* left and right represent integers in the range [1, 1018 - 1].
* left is less than or equal to right.
*/
class Solution {
private:
    const double UPPER = 1e4;
public:
    int superpalindromesInRange(string left, string right) {
        // get all palindrome in [1, 10^9]
        // only need 9 digits to get every 18 digit palindrome
        long long leftNum = stoll(left);
        long long rightNum = stoll(right);
        int out = 0;

        for (long long i = 1; i < UPPER; i++) {
            if (i < 10)
                out += inRange(i, leftNum, rightNum);

            string left = to_string(i);
            string right(left.rbegin(), left.rend());
            out += inRange(stoll(left+right), leftNum, rightNum);

            for (int center = 0; center < 10; center++) {
                out += inRange(stoll(left+to_string(center)+right), leftNum, rightNum);
            }
            // cout << i << ": " << out << endl;
        }
        return out;
    }

    bool isPalindrome(long long i) {
        string t = to_string(i);
        string r(t.rbegin(), t.rend());
        if (t == r)
            return true;
        return false;
    }

    bool inRange(long long num, long long left, long long right) {
        long long val = num * num;
        return (val >= left) && (val <= right) && (isPalindrome(val));
    }
};


// brute force
/*
class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        long start = stol(left);
        long end = stol(right);
        int out = 0;

        for (long i = sqrt(start); i*i < end; i++) {
            if (isPalindrome(i) && isPalindrome(i*i))
                out += 1;
        }
        return out;
    }

    bool isPalindrome(long i) {
        string t = to_string(i);
        string r(t.rbegin(), t.rend());
        if (t == r)
            return true;
        return false;

    }
};
*/