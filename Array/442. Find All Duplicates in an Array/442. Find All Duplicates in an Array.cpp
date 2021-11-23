/*
Number: 442
Topic: Find All Duplicates in an Array
Date: 2021/9/13
Rate: Medium
https://leetcode.com/problems/find-all-duplicates-in-an-array/

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

Constraints:
    * n == nums.length
    * 1 <= n <= 105
    * 1 <= nums[i] <= n
    * Each element in nums appears once or twice.
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> results;
        for (int i = 0; i < nums.size(); i++) {
            int value = nums[i] % (n+1);
            int count = nums[value-1] / (n+1);
            if (count > 0)
                results.push_back(value);
            else
                nums[value-1] += (n+1);
        }
        return results;
    }
};