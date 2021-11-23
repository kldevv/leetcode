'''
Number: 70
Topic: Climbing Stairs
Date: 2021/11/5
Rate: Easy
https://leetcode.com/problems/climbing-stairs/

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Constraints:
    * 1 <= n <= 45
'''
class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in range(1, n+1):
            dp[i] += dp[i-1]
            if i > 1:
                dp[i] += dp[i-2]
        return dp[n]


