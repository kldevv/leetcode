/*
Number: 526
Topic: Ways to Split Array Into Three Subarrays
Date: 2021/9/14
Rate: Medium
https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/

A split of an integer array is good if:

    * The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
    * The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.

Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.

Constraints:
    * 3 <= nums.length <= 105
    * 0 <= nums[i] <= 104
*/

class Solution {
private:
    const int MOD = (1e9) + 7;
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n+1, 0);
        for (int i = 1; i <= n; i++)
            prefixSum[i] = nums[i-1] + prefixSum[i-1];

        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (prefixSum[i] > (prefixSum[n]-prefixSum[i])/2)
                break;

            int leftBound = findLeftBound(prefixSum, i+1, n-1);
            int rightBound = findRightBound(prefixSum, i+1, n-1);
            if (leftBound == -1 || rightBound == -1)
                continue;

            result = (result+ (rightBound - leftBound + 1) % MOD) % MOD;

        }
        return result;
    }

    int findLeftBound(vector<int>& prefixSum, int left, int right) {
        int end = prefixSum.size() - 1;
        int start = left - 1;
        int leftSum = prefixSum[start];

        int result = -1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            int midSum = prefixSum[mid] - prefixSum[start];
            int rightSum = prefixSum[end] - prefixSum[mid];

            if (leftSum <= midSum && midSum <= rightSum) {
                result = mid;
                right = mid - 1;
            }
            else if (leftSum > midSum)
                left = mid + 1;
            else // midSum < rightSum
                right = mid - 1;
        }
        return result;
    }

    int findRightBound(vector<int>& prefixSum, int left, int right) {
        int end = prefixSum.size() - 1;
        int start = left - 1;
        int leftSum = prefixSum[start];

        int result = -1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            int midSum = prefixSum[mid] - prefixSum[start];
            int rightSum = prefixSum[end] - prefixSum[mid];

            if (leftSum <= midSum && midSum <= rightSum) {
                result = mid;
                left = mid + 1;
            }
            else if (leftSum > midSum)
                left = mid + 1;
            else // midSum < rightSum
                right = mid - 1;
        }
        return result;
    }
};