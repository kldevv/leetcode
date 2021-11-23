'''
Number: 18
Topic: 4Sum
Date: 2021/10/4
Rate: Medium
https://leetcode.com/problems/missing-number/

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
    * 0 <= a, b, c, d < n
    * a, b, c, and d are distinct.
    * nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Constraints:
* 1 <= nums.length <= 200
* -109 <= nums[i] <= 109
* -109 <= target <= 109
'''

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums = sorted(nums)
        n = len(nums)

        results = set()
        for a in range(n):
            for b in range(a+1, n):
                c, d = b + 1, n-1
                while (c < d):
                    total = nums[a] + nums[b] + nums[c] + nums[d]
                    if (total == target):
                        results.add((nums[a], nums[b], nums[c], nums[d]))
                        c += 1
                        d -= 1
                    elif (total < target):
                        c += 1
                    else: # total > target
                        d -= 1
        return list(results)