'''
Number: 55
Topic: Jump Game
Date: 2021/4/17
Rate: Medium

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
'''

# O(n)
# Greedy solution
# Bringing the finishing line closer
class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) <= 1:
            return True

        jumps = 1
        n = len(nums) - 2
        for i in range(n, -1, -1):
            # the number in the nums[i] must be greater than the jumps it needs to get to the finishing line
            # other it will relie on the nums[i-1] to do the extra jump, thus jump += 1
            if nums[i] >= jumps:
                jumps = 1
            else:
                jumps += 1
        return nums[0] >= jumps


