/*
Number: 396
Topic: Rotate Function
Date: 2021/6/10
Rate: Medium
https://leetcode.com/problems/rotate-function/

You are given an integer array nums of length n.

Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
Return the maximum value of F(0), F(1), ..., F(n-1).

Constraints:
* n == nums.length
* 1 <= n <= 3 * 104
* -231 <= nums[i] <= 231 - 1

*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
    	long long sum = 0, stairs = 0;
    	// 先看懂下面邏輯，這邊只是拿到該拿的
        for (int i = 0; i < nums.size(); i++) {
        	sum += nums[i];
        	stairs += i * nums[i];
        }

        // 關查一下 F(0) 和 F(1) 的關係，其實就是把整個 array 的 sum 加一次上去，在把原本在做後面的傢伙 (size-1) 推下去，變成零
        // 最後一項原本是 n-1*arr[n-1]，因為加了一整個 sum 後，那一項變成 n * arr[n-1]，要把她推下去，就減去 n * arr[n-1]
        long long _max = stairs;
        for (int k = 1; k < nums.size(); k++) {
        	stairs = stairs - nums.size()*nums[nums.size()-k] + sum;
        	_max = max(_max, stairs);
        }
        return _max;
    }
};