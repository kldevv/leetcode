/*
Number: 1822
Topic: Sign of the Product of an Array
Date: 2021/9/6
Rate: Easy
https://leetcode.com/problems/sign-of-the-product-of-an-array/

There is a function signFunc(x) that returns:
    * 1 if x is positive.
    * -1 if x is negative.
    * 0 if x is equal to 0.
You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product).

Constraints:
    * 1 <= nums.length <= 1000
    * -100 <= nums[i] <= 100
*/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for (int num : nums) {
            if (num == 0)
                return 0;
            sign *= (num > 0) ? 1 : -1;
        }
        return sign;
    }
};