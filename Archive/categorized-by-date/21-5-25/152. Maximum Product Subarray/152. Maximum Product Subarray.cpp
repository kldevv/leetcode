/*
Number: 152
Topic: Maximum Product Subarray
Date: 2021/5/25
Rate: Medium
https://leetcode.com/problems/maximum-product-subarray/

Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

It is guaranteed that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

Constraints:

* 1 <= nums.length <= 2 * 104
* -10 <= nums[i] <= 10
* The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int biggest = nums[0];
        int smallest = nums[0];
        int _max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int prev_biggest = biggest;
            biggest = max(smallest*nums[i], max(biggest*nums[i], nums[i]));
            smallest = min(smallest*nums[i], min(prev_biggest*nums[i], nums[i]));
            _max = max(_max, biggest);
        }
        return _max;
    }
};