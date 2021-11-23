'''
Number: 27
Topic: Remove Element
Date: 2021/3/25
Rate: Easy

Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
'''

# loop over array, if the start value is the target value, swap it with the end element, and decrement the end
# unstable (order will be changed)

# time complexity O(n)
class Solution:
	def removeElement(self, nums, val):
	start, end = 0, len(nums) - 1
	while start <= end:
	    if nums[start] == val:
	        nums[start], nums[end], end = nums[end], nums[start], end - 1
	    else:
	        start +=1
	return start

