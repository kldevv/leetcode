'''
Number: 27
Topic: Remove Duplicates from Sorted Array
Date: 2021/3/25
Rate: Easy

Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
'''

# loop over every element in the array and reallocate the value that is not in the hashtable already
# using hashtable

# time complexity O(n)
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        keeper = dict()
        iterator = 0
        for i in range(len(nums)):
            if nums[i] not in keeper:
                keeper[nums[i]] = True
                nums[iterator] = nums[i]
                iterator += 1
        return iterator