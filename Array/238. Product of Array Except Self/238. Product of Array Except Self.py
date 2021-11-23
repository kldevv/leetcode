'''
Number: 238
Topic: Product of Array Except Self
Date: 2021/10/4
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
'''

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        results = [1] * n
        for i in range(1, n):
            results[i] = results[i-1] * nums[i-1]

        accu = 1
        for j in range(n-2, -1, -1):
            accu *= nums[j+1]
            results[j] *= accu

        return results
