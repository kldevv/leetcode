/*
Number: 152
Topic: Maximum Product Subarray
Date: 2021/7/17
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
        int minEndAt = nums[0];
        int maxEndAt = nums[0];
        int maxProduct = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int temp = maxEndAt;
            maxEndAt = max(maxEndAt*nums[i], max(minEndAt*nums[i], nums[i]));
            minEndAt = min(temp*nums[i], min(minEndAt*nums[i], nums[i]));

            maxProduct = max(maxProduct, maxEndAt);
        }
        return maxProduct;
    }
};