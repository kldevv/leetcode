'''
Number: 45
Topic: Jump Game II
Date: 2021/4/17
Rate: Medium

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.
'''

# O(n)
# Greedy

class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        curFarthest, curEnd, jump = 0, 0, 0
        if len(nums) <= 1:
            return 0
        for idx in range(len(nums)):
            curFarthest = max(curFarthest, idx + nums[idx])
            if curFarthest == (len(nums)-1):
                jump += 1
                break
            if idx == curEnd:
                curEnd = curFarthest
                jump += 1
        return jump


