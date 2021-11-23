'''
Number: 31
Topic: Next Permutation
Date: 2021/10/18
Rate: Medium
https://leetcode.com/problems/next-permutation/

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

Constraints:
    * 1 <= nums.length <= 100
    * 0 <= nums[i] <= 100
'''

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) < 2:
            return

        for rev_i in range(len(nums)-2, -1, -1):
            if nums[rev_i] < nums[rev_i+1]:
                for rev_i2 in range(len(nums)-1, rev_i, -1):
                    if nums[rev_i2] > nums[rev_i]:
                        nums[rev_i2], nums[rev_i] = nums[rev_i], nums[rev_i2]
                        i = rev_i + 1
                        j = len(nums) - 1
                        while i < j:
                            nums[i], nums[j] = nums[j], nums[i]
                            i += 1
                            j -= 1
                        return
        nums.reverse()

