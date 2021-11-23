/*
Number: 312
Topic: Burst Balloons
Date: 2021/6/22
Rate: Hard
https://leetcode.com/problems/burst-balloons/

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

Constraints:
* n == nums.length
* 1 <= n <= 500
* 0 <= nums[i] <= 100

*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> withoutZero(nums.size()+2, 0);

        // 把 "零" 都先清掉，因為他們會給 0 coins
        // 然後再把頭尾都加ㄧ
        // n 代表新的長度
        int n = 0;
        withoutZero[n++] = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                withoutZero[n++] = nums[i];
        }
        withoutZero[n++] = 1;

        // tc: O(n^3)
        // dp[left][right] 代表把 (left, right) 中間的氣球爆光，可以拿到的最佳 value，不包含 left 和 right
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // k 代表的是 left 和 right 的寬度 e.g k = 2 代表 [left, x, right]
        for (int k = 2; k < n; k++) {
            // 在這個寬度下用一個 sliding windows，掃過所有組合
            for (int left = 0; left+k < n; left++) {
                int right = left + k;
                // 在 left, right 底下找到最後一個爆的氣球 withoutZero[i]，他最後爆掉時，會給 withoutZero[left]*withoutZero[i]*withoutZero[right]，然後加上它爆掉前要先爆光 dp[left][i] + dp[i][right]
                // 找最大值！
                for (int i = left+1; i < right; i++) {
                    // 當 dp[left][left+1] == 0，因為中間沒有氣球可以爆！
                    dp[left][right] = max(dp[left][right], withoutZero[left]*withoutZero[i]*withoutZero[right] + dp[left][i] + dp[i][right]);
                }
            }
        }
        // 回傳爆光 dp[0][n-1] 中間的球！ dp[0]和dp[n-1]是後來加上的 1，所以不用把他們爆掉
        return dp[0][n-1];
    }
};