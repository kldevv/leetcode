'''
Number: 217
Topic: Contains Duplicate
Date: 2021/4/2
Rate: Easy

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

'''

class Solution:
    def containsDuplicate(self, nums: [int]) -> bool:
        hashmap = dict()
        for idx in range(len(nums)):
            if nums[idx] in hashmap:
                return True
            else:
                hashmap[nums[idx]] = 1
        return False








