/*
Number: 300
Topic: Longest Increasing Subsequence
Date: 2021/7/11
Rate: Medium
https://leetcode.com/problems/longest-increasing-subsequence/

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Constraints:
* 1 <= nums.length <= 2500
* -104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> out = {nums[0]};

        for (int i = 1; i < nums.size(); i++) {
            int val = nums[i];
            int t = binarySearch(out, val);
            if (t >= out.size())
                out.push_back(val);
            else
                out[t] = val;
        }
        return out.size();
    }

    int binarySearch(const vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while (left <= right) {
            int mid = left + (right-left)/2;
            int val = nums[mid];

            if (val == target)
                return mid;
            if (val < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};