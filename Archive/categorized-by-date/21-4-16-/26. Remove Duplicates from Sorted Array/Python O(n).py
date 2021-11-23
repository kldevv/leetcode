'''
Number: 27
Topic: Remove Duplicates from Sorted Array
Date: 2021/3/25
Rate: Easy

Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
'''

# loop over every element in the array and reallocate the value if the value is not in the new range array already

# time complexity O(n)
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        iterator = 0
        for element in nums:
            if (iterator < 1) or (element > nums[iterator-1]):  # it must be greater than the last element of the new range array
            	nums[iterator] = element
            	iterator += 1
        return iterator