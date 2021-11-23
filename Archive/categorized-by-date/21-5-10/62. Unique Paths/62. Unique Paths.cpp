/*
Number: 62
Topic: Unique Paths
Date: 2021/5/10
Rate: Medium
https://leetcode.com/problems/unique-paths/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Constraints:
* 1 <= m, n <= 100
* It's guaranteed that the answer will be less than or equal to 2 * 109.

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if ((m < 2) || (n < 2))
            return 1;
        double big = max(m, n)-1;
        double small = min(m, n)-1;
        return factorial(big+small, big, 1) / factorial(small, 1, 1);
    }
    
    double factorial(double n, double k, double res) {
        if (n == 1) {
            return res;
            // stop early to avoid overflow
        } else if (n == k){
            return res;
        } else {
            // call-taill optimalization
            return factorial(n-1, k, res*n);
        }
    }
};


