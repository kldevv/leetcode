/*
Number: 1071
Topic: Greatest Common Divisor of Strings
Date: 2021/11/28
Rate: Easy
https://leetcode.com/problems/greatest-common-divisor-of-strings/

For two strings s and t, we say "t divides s" if and only if s = t + ... + t  (t concatenated with itself 1 or more times)

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Constraints:
    * 1 <= str1.length <= 1000
    * 1 <= str2.length <= 1000
    * str1 and str2 consist of English uppercase letters.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
   private:
    int gcd(int A, int B) {
        return (A == 0) ? B : gcd(B % A, A);
    }

   public:
    string gcdOfStrings(string str1, string str2) {
        /*
        Key Observation #1
            str1 = component11 + component12 + component13 + ...
            str2 = component21 + component22 + component23 + ...
            str1 + str2 = component11 + component12 + component13 + ... + component21 + component22 + component23 + ...
            str2 + str1 = component21 + component22 + component23 + ... + component11 + component12 + component13 + ...

            If str1 and str are both divisible by commonDivisor:
                str1 = commonDivisor + commonDivisor + ... = (commonDivisor * x1)
                str2 = commonDivisor + commonDivisor + ... = (commonDivisor * x2)
                str1 + str2 = commonDivisor + commonDivisor + ... + commonDivisor + commonDivisor
                str1 + str2 = commonDivisor + commonDivisor + ... + commonDivisor + commonDivisor

            Thus:
                str1 + str2 = str2 + str1
        

        Key Observation #2
            len(str1) = len(commonDivisor) * x1
            len(str2) = len(commonDivisor) * x2
            maxLen(commonDivisor) = gcd(x1, x2)
            If not so:
                len(commonDivisor) can be increase by multipling the factor n.
                n = x1/c1 = x2/c2
        
        Key Observation #3
            str1 and str2 always starting with their any divisor
        */
        return (str1 + str2 == str2 + str1)
                   ? str1.substr(0, gcd(str1.size(), str2.size()))
                   : "";
    }
};