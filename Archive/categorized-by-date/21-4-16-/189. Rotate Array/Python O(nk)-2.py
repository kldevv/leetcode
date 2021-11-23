'''
Number: 189
Topic: Remove Duplicates from Sorted Array
Date: 2021/3/25
Rate: Medium

Given an array, rotate the array to the right by k steps, where k is non-negative.

'''

# [1, 2, 3, 4, 5, 6, 7]

# time complexity O(n*K)
# sucks and time limit exceeded

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        k %= len(nums)
        if k == 0:
            return None
        # we need to shift the element back for k times
        for t in range(k):
            # this will shift the element back for one index
            for i in range(len(nums)):
                nums[i], nums[-1] = nums[-1], nums[i]
        return None




