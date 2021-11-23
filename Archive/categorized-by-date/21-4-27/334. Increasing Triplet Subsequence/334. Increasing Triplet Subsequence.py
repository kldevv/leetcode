'''
Number: 334
Topic: Increasing Triplet Subsequence
Date: 2021/4/27
Rate: Medium

Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. 
If no such indices exists, return false.
'''

class Solution:
    def increasingTriplet(self, nums: [int]) -> bool:
        first = second = float('inf')
            for n in nums:
                if n <= first:
                    first = n
                elif n <= second:
                    second = n
                else:
                    return True
            return False

'''
grade/pass
tc/O(n)
sc/O(1)
'''


