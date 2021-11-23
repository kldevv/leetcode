'''
Number: 27
Topic: Remove Element
Date: 2021/3/25
Rate: Easy

Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
'''

# loop over every element in the array and reallocate the value that is not the target value

# time complexity O(n)
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
    	iterator = 0
    	for i in range(len(nums)):
    		if nums[i] != val:
    			nums[iterator] = nums[i]
    			iterator += 1

    	return iterator

