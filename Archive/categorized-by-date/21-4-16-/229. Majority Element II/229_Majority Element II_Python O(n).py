'''
Number: 229
Topic: Majority Element II
Date: 2021/3/31
Rate: Medium

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Follow-up: Could you solve the problem in linear time and in O(1) space?

'''
# Majority Voting Algo.

# time complexity O(n)
# space complexity O(1)

class Solution:
    def majorityElement(self, nums: [int]) -> int:
        if not nums:
            return []

        majority_1 = 0
        majority_2 = 1
        count_1 = 0
        count_2 = 0
        for element in nums:
            if element == majority_1:
                count_1 += 1
            elif element == majority_2:
                count_2 += 1
            elif count_1 == 0:
                majority_1 = element
                count_1 = 1
            elif count_2 == 0:
                majority_2 = element
                count_2 = 1
            else:
                count_1 -= 1
                count_2 -= 1

        answer = [majority for majority in (majority_1, majority_2) if nums.count(majority) > len(nums)//3]

        return answer


