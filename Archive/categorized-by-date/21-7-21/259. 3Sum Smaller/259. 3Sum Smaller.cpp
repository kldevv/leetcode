/*
Number: 256
Topic: 3Sum Smaller
Date: 2021/7/21
Rate: Medium
https://leetcode.com/problems/3sum-smaller/

Given an array of n integers nums and an integer target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

Constraints:
* n == nums.length
* 0 <= n <= 3500
* -100 <= nums[i] <= 100
* -100 <= target <= 100
*/

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int count = 0;
        for (int i = 0; i < n; i++) {
            int left = i+1, right = n-1;
            int target2 = target - nums[i];
            while (left < right) {
                if (nums[left]+nums[right] < target2) {
                    count += (right-left);
                    left += 1;
                }
                while (left < right && nums[left]+nums[right] >= target2) {
                    right -= 1;
                }
            }
        }
        return count;
    }
};