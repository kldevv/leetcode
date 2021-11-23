/*
Number: 144
Topic: Super Pow
Date: 2021/6/11
Rate: Medium
https://leetcode.com/problems/super-pow/

Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.


Constraints:
* 1 <= a <= 231 - 1
* 1 <= b.length <= 2000
* 0 <= b[i] <= 9
* b doesn't contain leading zeros.

*/

class Solution {
public:
    const int MOD = 1337;

    // knowledge:  (a * b % k) = (a%k) * (b%k) % k
    // same: (a^t % k) = (a%k)^t % k

    // e.g. a = 2^123467 % 1337
    // = (2^123460 * 2^7) % 1337 = (2^123460 % 1337) * (2^7 % 1337) % 1337
    // = ((2^12346)^10 % 1337) * (2^7 % 1337) % 1337
    // = ((2^12346) % 1337)^10 % 1337) * (2^7 % 1337) % 1337

    // (2^12346)^10 % 1337 = (((2^12346) % 1337) * ((2^12346) % 1337) * ...) % 1337 = ((2^12346) % 1337)^10 % 1337) 

    int superPow(int a, vector<int>& b) {
        if (b.size() == 1)
            return superPow(a, b.back());

        int last_digit = b.back();
        b.pop_back();

        return superPow(superPow(a, b), 10) * superPow(a, last_digit) % MOD;
        
    }
    int superPow(int a, int b) {
        int out = 1;
        for (int i = 0; i < b; i++) {
            out = (out%MOD) * (a%MOD) % MOD;
        }
        return out;
    }
};