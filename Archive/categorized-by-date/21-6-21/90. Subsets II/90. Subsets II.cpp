/*
Number: 90
Topic: Subsets II
Date: 2021/6/21
Rate: Medium
https://leetcode.com/problems/subsets-ii/

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Constraints:
* 1 <= nums.length <= 10
* -10 <= nums[i] <= 10

*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> out = {{}};
        int start = 0;

        for (int i = 0; i < nums.size(); i++) {
            int end = out.size();

            // 只有在上個元素一樣的時候，跳過上一個元素跑過的，直接從上一個元素新增的開使新增
            // 如果和上一個元素不一樣，就把所得的 set 拿出來，加入這個元素，又是一個新的 set
            if (i == 0 || nums[i] != nums[i-1])
                start = 0;

            for (; start < end; start++) {
                vector<int> temp = out[start];
                temp.push_back(nums[i]);
                out.push_back(move(temp));
            }
        }
        return out;
    }
};