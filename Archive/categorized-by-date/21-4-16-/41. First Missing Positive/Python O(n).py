'''
Number: 41
Topic: First Missing Positive
Date: 2021/3/25
Rate: Hard

Given an unsorted integer array nums, find the smallest missing positive integer.
'''

# sort the array, and loop over it to see if it is incrementing by 1 or return the missing positive

# [1, 2, 0, 100]
# The possible answer will be in the range from 1 to 5
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # [1, 2, 0, 100, 0]
        leng = len(nums) + 1
        # 5
        for idx in range(leng - 1):
            if (nums[idx] < 0) or (nums[idx] >= (leng)):
                nums[idx] = 0

        # [1, 2, 0, 0, 0]
        for idx in range(leng - 1):
            if nums[idx] != 0:
                nums[(nums[idx] % leng) - 1] += leng

        # 1 % 5 = 1
        # 2 % 5 = 2

        # [1, 6, 5, 0, 0]
        # [Garbage, 1, 2, 3, 4]
        # [Garbage, 1, 1, 0, 0]
        for idx in range(leng - 1):
            if (nums[idx] // leng) == 0:
                return idx + 1
        return leng

# [2, 2, 0]
# [2, 2, 6]
# [0, 0, 2]

