'''
Number: 41
Topic: First Missing Positive
Date: 2021/3/25
Rate: Hard

Given an unsorted integer array nums, find the smallest missing positive integer.
'''

# sort the array, and loop over it to see if it is incrementing by 1 or return the missing positive

# time complexity O(nlog(n))
# space complexity O(1)

# can be better, try TC: O(n), SC: O(1)

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # time complexity O(n)
        if 1 not in nums:
            return 1
        # time complexity O(nlog(n))
        nums.sort()
        # time complexity O(n)
        for idx in range(len(nums)):
            if (idx > 0) and (nums[idx] > 0) and (nums[idx-1] > 0) :
                if (nums[idx] - nums[idx - 1]) > 1:
                    return nums[idx - 1] + 1

        return nums[-1] + 1



