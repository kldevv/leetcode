/*
Number: 724
Topic: Find Pivot Index
Date: 2021/11/2
Rate: Easy
https://leetcode.com/problems/find-pivot-index/

Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

Constraints:
    * 1 <= nums.length <= 104
    * -1000 <= nums[i] <= 1000
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n+1, 0);

        for (int i = 0; i < n; i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            if (prefixSum[i] == (prefixSum[n] - prefixSum[i+1]))
                return i;
        }
        return -1;
    }
};