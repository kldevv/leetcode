/*
Number: 279
Topic: Perfect Squares
Date: 2021/6/21
Rate: Medium
https://leetcode.com/problems/perfect-squares/


Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.


Constraints:
* 1 <= n <= 10^4

*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        // dp[i] 記載到 i 時最小的 perfect square number 分解
        for (int i = 1; i <= n; i++) {
        	// 檢查 i 減去到 i 的每一個 perfect square 後的數量+1 哪一個會比較小
        	for(int j = 1; (j*j) <= i; j++) {
        		dp[i] = min(dp[i], dp[i-(j*j)] + 1);
        	}
        }
        return dp[n];
    }
};