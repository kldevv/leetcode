'''
Number: 169
Topic: Majority Element
Date: 2021/3/31
Rate: Easy

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array

'''
# The idea is that the majority element appears more frequently than all the other elements combine
# Thus, it will dominate the majority variable and the count variable

# time complexity O(n)
# space complexity O(1)

class Solution:
    def majorityElement(self, nums: [int]) -> int:
    	majority = 0
    	count = 0
    	for element in nums:
    		if count == 0:
    			majority = element
    		if element == majority:
    			count += 1
    		else:
    			count -= 1
    	return majority


