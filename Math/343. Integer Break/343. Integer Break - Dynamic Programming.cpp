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

// TC: O(n^2)
// SC: O(n)
#include <vector>

using namespace std;

class Solution {
   public:
    int integerBreak(int n) {
        /* Recursive:

        Base Case:
            dp[2] = 1;
        Recurrence Relation:
            dp[n] = MAX(max(factor_1, dp[factor_1]) * max(factor_2, dp[factor_2])) for (factor_1 = 1 to n-1)
            s.t. factor_2 = (n - factor_1)
        
        Requirement:
            Decomposition have to be at least 2 numbers, 1 and n-1
        */

        vector<int> dp(n + 1, 0);
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            for (int factor = 1; factor < i; factor++) {
                dp[i] = max(dp[i], max(i - factor, dp[i - factor]) * max(factor, dp[factor]));
            }
        }
        return dp[n];
    }
};