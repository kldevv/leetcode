/*
Number: 70
Topic: Climbing Stairs
Date: 2021/6/18
Rate: Easy
https://leetcode.com/problems/climbing-stairs/


You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Constraints:
* 1 <= n <= 45

*/


class Solution {
public:
    int climbStairs(int n) {
        int thisStep = 0, oneStepBefore = 1, twoStepBefore = 0;
        // n = n-1 + n-2;
        // n-2 = n-1;
        // n-1 = n;
        // from top again;
        for (int i = 1; i < n; i++) {
            thisStep = oneStepBefore + twoStepBefore;
            twoStepBefore = oneStepBefore;
            oneStepBefore = thisStep;
        }
        return thisStep;
    }
};
