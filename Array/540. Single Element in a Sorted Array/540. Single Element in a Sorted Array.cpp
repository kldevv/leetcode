/*
Number: 540
Topic: Single Element in a Sorted Array
Date: 2021/9/8
Rate: Medium
https://leetcode.com/problems/single-element-in-a-sorted-array/

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int upperBound = n-1;
        int lowerBound = 0;
        while (lowerBound <= upperBound) {
            int mid = lowerBound + (upperBound-lowerBound)/2;
            if ((mid == 0 || nums[mid-1] != nums[mid]) && (mid == n-1 || nums[mid+1] != nums[mid]))
                return nums[mid];
            if (mid % 2 == 1) {
                if (mid == 0 || nums[mid-1] != nums[mid])
                    upperBound = mid - 1;
                else
                    lowerBound = mid + 1;
            }
            else {
                if (mid == n-1 || nums[mid+1] != nums[mid]) {
                    upperBound = mid - 1;
                }
                else
                    lowerBound = mid + 1;
            }
        }
        return -1;
    }
};