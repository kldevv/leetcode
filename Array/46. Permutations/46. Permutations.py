'''
Number: 46
Topic: Permutations
Date: 2021/10/18
Rate: Medium
https://leetcode.com/problems/permutations/

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Constraints:
    * 1 <= nums.length <= 6
    * -10 <= nums[i] <= 10
    * All the integers of nums are unique.
'''

class Solution:
    def __init__(self):
        self.results = list()

    def permute(self, nums: List[int]) -> List[List[int]]:
        def dfs(nums, start):
            if start == len(nums):
                self.results.append(nums.copy())

            for i in range(start, len(nums)):
                nums[start], nums[i] = nums[i], nums[start]
                dfs(nums, start+1)
                nums[start], nums[i] = nums[i], nums[start]

        dfs(nums, 0)
        return self.results