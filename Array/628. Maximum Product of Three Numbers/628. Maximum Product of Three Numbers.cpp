/*
Number: 628
Topic: Maximum Product of Three Numbers
Date: 2021/11/1
Rate: Easy
https://leetcode.com/problems/non-decreasing-array/

Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Constraints:
    * 3 <= nums.length <= 104
    * -1000 <= nums[i] <= 1000
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxOne = INT_MIN;
        int maxTwo = INT_MIN;
        int maxThree = INT_MIN;

        int minOne = 0;
        int minTwo = 0;
        for (const int& num : nums) {
            if (num > maxOne) {
                swap(maxTwo, maxThree);
                swap(maxOne, maxTwo);
                maxOne = num;
            } else if (num > maxTwo) {
                swap(maxTwo, maxThree);
                maxTwo = num;
            } else if (num > maxThree) {
                maxThree = num;
            }

            if (num < minOne) {
                swap(minOne, minTwo);
                minOne = num;
            } else if (num < minTwo) {
                minTwo = num;
            }
        }

        int result = max(maxOne*maxTwo*maxThree, maxOne*minOne*minTwo);
        return result;
    }
};