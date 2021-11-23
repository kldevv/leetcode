/*
Number: 70
Topic: Climbing Stairs
Date: 2021/11/5
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
        int oneStepAway = 1;
        int twoStepAway = 1;
        for (int curStep = 2; curStep <= n; curStep++) {
            int temp = oneStepAway + twoStepAway;
            twoStepAway = oneStepAway;
            oneStepAway = temp;
        }
        return oneStepAway;
    }
};

