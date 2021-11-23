/*
Number: 16
Topic: 3Sum Closest
Date: 2021/9/30
Rate: Medium
https://leetcode.com/problems/3sum-closest/

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Constraints:
    * 3 <= nums.length <= 1000
    * -1000 <= nums[i] <= 1000
    * -104 <= target <= 104
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n; i++) {
            int j = i+1, t = n-1;
            while (j < t) {
                int total = nums[i] + nums[j] + nums[t];
                if (abs(total - target) < abs(result - target))
                    result = total;
                if (total > target) {
                    t--;
                } 
                else {
                    j++;
                }
            }
        }
        return result;
    }
};