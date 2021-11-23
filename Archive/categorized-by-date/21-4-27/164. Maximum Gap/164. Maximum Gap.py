
'''
Number: 164
Topic: Maximum Gap
Date: 2021/4/27
Rate: Hard

Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
'''

class Solution:
    def maximumGap(self, nums: [int]) -> int:
        # return 0 if the size is less than 2
        if len(nums) < 2:
            return 0

        # find max and min
        min_, max_ = float("inf"), -float("inf")
        for n in nums:
            min_ = min(n, min_)
            max_ = max(n, max_)

        # get the range and evenly distributed gap
        range_ = max_ - min_
        gap = (range_ // (len(nums)-1)) + bool(range_ % (len(nums)-1))
        # all the numbers are the same
        if gap == 0:
            return 0

        # create dummy list for each bucket
        max_list = [min_-1] * (len(nums))
        min_list = [max_+1] * (len(nums))

        # put the number to the according bucket, only record the number if it is the max or min of its bucket
        for n in nums:
            bucket = (n - min_) // gap
            max_list[bucket] = max(n, max_list[bucket])
            min_list[bucket] = min(n, min_list[bucket])

        # the biggest gap will be the biggest interval of two buckets' min and max
        max_gap = gap
        prev_max = max_list[0]
        for idx in range(1, len(nums)):
            # skip if the bucket is empty
            if ((max_list[idx] == min_-1) & (min_list[idx] == max_+1)):
                continue
            max_gap = max(min_list[idx]-prev_max, max_gap)
            prev_max = max_list[idx]
        return max_gap

