'''
Number: 287
Topic: Find the Duplicate Number
Date: 2021/4/29
Rate: Medium

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.
'''

class Solution:
    def findDuplicate(self, nums: [int]) -> int:
    	hashmap = dict()
    	for num in nums:
    		if num in hashmap:
    			return num
    		else:
    			hashmap[num] = True

'''
grade / pass
tc / O(1)
sc / O(n) or O(1) if in-place hash
'''