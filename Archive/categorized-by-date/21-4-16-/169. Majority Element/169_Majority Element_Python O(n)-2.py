'''
Number: 169
Topic: Majority Element
Date: 2021/3/31
Rate: Easy

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array

'''

# sort array solution
# dirty and easy

# the idea is that the majority element must appear in the middle of the sorted array
# since the majority element appears more than n /2 times.

# time complexity O(nlog(n))
# space complexity O(1)

class Solution:
    def majorityElement(self, nums: [int]) -> int:
        nums.sort()
        return nums[len(nums) // 2]


