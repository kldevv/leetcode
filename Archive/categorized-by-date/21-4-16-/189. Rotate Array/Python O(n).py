'''
Number: 189
Topic: Remove Duplicates from Sorted Array
Date: 2021/3/25
Rate: Medium

Given an array, rotate the array to the right by k steps, where k is non-negative.

'''

# Let n=7 and k=3.

# Original List                   : 1 2 3 4 5 6 7
# After reversing all numbers     : 7 6 5 4 3 2 1
# After reversing first k numbers : 5 6 7 4 3 2 1
# After revering last n-k numbers : 5 6 7 1 2 3 4 --> Result

# time complexity O(n)
# space complexity O(1)
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        k %= len(nums)
        if k == 0:
            return None
        self.reverse_array(0, len(nums)-1, nums)
        self.reverse_array(0, k-1, nums)
        self.reverse_array(k, len(nums)-1, nums)

        return None

    def reverse_array(self, start: int, end: int, arr: List[int]) -> None:
        while start < end:
            arr[start], arr[end] = arr[end], arr[start]
            start += 1
            end -= 1

        return None

