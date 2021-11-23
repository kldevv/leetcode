/*
Number: 396
Topic: Rotate Function
Date: 2021/7/9
Rate: Medium
https://leetcode.com/problems/rotate-function/


You are given an integer array nums of length n.

Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

* F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
Return the maximum value of F(0), F(1), ..., F(n-1).

The test cases are generated so that the answer fits in a 32-bit integer.

Constraints:
* n == nums.length
* 1 <= n <= 105
* -100 <= nums[i] <= 100

*/
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        int F = 0;
        for (int i = 0; i < n; i++) {
            F += (i * nums[i]);
        }

        int out = F;
        for (int i = n-1; i >= 0; i--) {
            F -= nums[i]*n;
            F += sum;
            out = max(out, F);
        }

        return out;
    }
};