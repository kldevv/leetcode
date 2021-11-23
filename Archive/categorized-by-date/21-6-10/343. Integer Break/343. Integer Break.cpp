/*
Number: 343
Topic: Integer Break
Date: 2021/6/10
Rate: Medium
https://leetcode.com/problems/integer-break/

Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

Constraints:
* 2 <= n <= 58

*/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp;
        // 建立一個 array ，來表示當 n 為 i 時的最大可得到的 product
        for (int i = 0; i <= n; i++)
        	// 此時的預設最小值是 i-1 ，因為任 n 都最少要分成兩塊可以變成 (n-1)*1 = n-1
        	dp.push_back(i-1);


        for (int i = 2; i <= n; i++) {
        	for (int j = 1; j < i; j++) {
        		// 每個長度都試著再去做分割，原本預設是切成 (n-1)*1 現在試試看 (n-2)*2 以此類推
        		// 每次拆成兩塊之後，都看看這兩塊能不能拆成比原本更大的 product，如果可以的話，就用那個 product 來做 factor
        		dp[i] = max(dp[i], max(i-j, dp[i-j]) * max(j, dp[j]));
        	}
        }

        return dp[n];
    }
};