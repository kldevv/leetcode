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

# Best Case: O(n)
# Worst Case: O(n^2)
# DP

class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) <= 1:
            return 0
        step = {
        (len(nums) - 1):0,
        (len(nums) - 2):1
        }

        n = len(nums) - 2
        for i in range(n, -1, -1):
            smallest_step = -1
            for x in range(1, nums[i] + 1):
                if ((i+x) in step) and ((i + x) <= len(nums) - 1):
                    if smallest_step == -1:
                        smallest_step = step[i + x]
                    if (step[i + x] < smallest_step):
                        smallest_step = step[i + x]
            if smallest_step != -1:
                step[i] = smallest_step + 1
        return step[0]

