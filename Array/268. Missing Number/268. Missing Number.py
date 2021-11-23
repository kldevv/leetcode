'''
Number: 268
Topic: Missing Number
Date: 2021/10/4
Rate: Easy
https://leetcode.com/problems/missing-number/

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Constraints:
* n == nums.length
* 1 <= n <= 104
* 0 <= nums[i] <= n
* All the numbers of nums are unique.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
'''

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        offset = 0
        nums += range(0, len(nums)+1)
        for num in nums:
            offset ^= num
        return offset
