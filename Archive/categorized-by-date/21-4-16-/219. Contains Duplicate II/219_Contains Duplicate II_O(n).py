'''
Number: 219
Topic: Contains Duplicate II
Date: 2021/4/2
Rate: Easy

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

'''

# time complexity O(n)
# space complexity O(n)

class Solution:
    def containsNearbyDuplicate(self, nums:[int], k:int) -> bool:
        hashmap = dict()
        for idx in range(len(nums)):
            if nums[idx] in hashmap:
                if (idx - hashmap[nums[idx]]) <= k:
                    return True

            hashmap[nums[idx]] = idx
        return False








