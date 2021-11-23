/*
Number: 343
Topic: Integer Break
Date: 2021/11/17
Rate: Medium
https://leetcode.com/problems/integer-break/

Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

Constraints:
    * 2 <= n <= 58
*/

// TC: O(1)
// SC: O(1)
#include <vector>

using namespace std;

class Solution {
   public:
    int integerBreak(int n) {
        /* Math:

        Requirement:
            Decomposition have to be at least 2 numbers, 1 and n-1

        Edge Cases:
            n == 2: return 1
            n == 3: return 2
        General Solution:
            We want to decompose n into 2 parts if the (decomposed) result is larger than the original n:
                For every n is larger than 3
                    If n is a even number:
                        (n / 2) * (n / 2) is the max product we can have
                        If (n / 2)^2 >= n => keep decomposing:
                            If  n >= 4 => keep decomposing

                    If n is an odd number:
                        ((n+1)/2) * ((n-1)/2) is the max product we can have
                        If ((n+1)(n-1) / 4) >= n => keep decomposing:
                            If  n >= 5 => keep decomposing
            
            ** Therefore the optimal factorization consist of only 1, 2, 3, and 1 is effectless


            The decomposition of 6 => 2 * 2 * 2 = 8 < 3 * 3 = 9
                => Every number larger than 6 and have a factorization consist of more than 3# 2
                => Can be turned into 6 = 3 * 3 and have a better result
            
            ** Therefore the optimal factorization consist of at most 2# 2
        */

        // edge cases
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;

        int numberOfThreeFactors = n / 3;

        // get the last part of decomposition
        int lastFactor;
        int modOfThree = n % 3;
        if (modOfThree == 0) {
            lastFactor = 1;
        } else if (modOfThree == 1) {
            // because 2 * 2 = 4 is larger than 3 * 1 = 1
            numberOfThreeFactors -= 1;
            lastFactor = 2 * 2;
        } else {  // modOfThree == 2
            lastFactor = 2;
        }

        return pow(3, numberOfThreeFactors) * lastFactor;
    }
};