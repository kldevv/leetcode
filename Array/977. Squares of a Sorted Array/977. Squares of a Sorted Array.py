'''
Number: 977
Topic: Squares of a Sorted Array
Date: 2021/9/8
Rate: Easy
https://leetcode.com/problems/squares-of-a-sorted-array/

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Cosntriants:
    * 1 <= nums.length <= 104
    * -104 <= nums[i] <= 104
    * nums is sorted in non-decreasing order.
 

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
'''

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        i, j = 0, n-1
        results = list()
        while i <= j:
            sq_i = nums[i] ** 2
            sq_j = nums[j] ** 2
            if sq_i > sq_j:
                results.append(sq_i)
                i += 1
            else:
                results.append(sq_j)
                j -= 1
        results.reverse()
        return results