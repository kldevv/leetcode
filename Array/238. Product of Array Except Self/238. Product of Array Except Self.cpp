/*
Number: 238
Topic: Product of Array Except Self
Date: 2021/12/5
Rate: Medium
https://leetcode.com/problems/product-of-array-except-self/

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Constraints:
    * 2 <= nums.length <= 105
    * -30 <= nums[i] <= 30
    * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
*/

#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        [n0, n1, n2, n3, n4]
        At n_i:
            The result == accumProd(n_0, n_(i-1)) * accumProd(n_(i+1), n_N)

        Iterate i from left to right:
            result[i] = accumProd(n_0, n-(i-1))
            accumProd(n_0, n-(i-1)) * nums[i]

        Vice versa

        */
        int n = nums.size();
        vector<int> result(n, 1);

        int prodLeft = 1;
        for (int i = 0; i < n; i++) {
            result[i] *= prodLeft;
            prodLeft *= nums[i];
        }

        int prodRight = 1;
        for (int j = n - 1; j >= 0; j--) {
            result[j] *= prodRight;
            prodRight *= nums[j];
        }
        return result;
    }
};