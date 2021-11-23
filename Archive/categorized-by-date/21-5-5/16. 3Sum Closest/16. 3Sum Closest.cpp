/*
Number: 16
Topic: 3Sum Closest
Date: 2021/5/5
Rate: Medium
https://leetcode.com/problems/3sum-closest/

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

tc / O(n^2)
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() == 3) return accumulate(nums.begin(), nums.end(), 0);
        
        int diff{INT_MAX};
        int best{0};
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++){
            int start = i + 1;
            int end = nums.size() - 1;
            int remain = target - nums[i];

            while (start < end){

                int result = nums[start] + nums[end];

                if (result == remain) return target;
                else if (result < remain){
                    if ((remain-result) < diff){
                        best = nums[i] + result;
                        diff = remain-result;
                    }
                    start++;
                } else if (result > remain){
                    if ((result-remain) < diff){
                        best = nums[i] + result;
                        diff = result-remain;
                    }
                    end--;                    
                }
            }
        }
        return best;
    }
};

