/*
Number: 198
Topic: House Robber
Date: 2021/6/24
Rate: Medium
https://leetcode.com/problems/house-robber/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Constraints:
* 1 <= nums.length <= 100
* 0 <= nums[i] <= 400

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int cur = 0, pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 目前 cur 代表的是到這格為止可以拿到最大的 val，而他就是 上一期的 val 或是 這一期 value＋到前兩期累積的錢
            int temp = cur;
            cur = max(cur, pre+nums[i]);
            pre = temp;
        }
        return cur;
    }
};
