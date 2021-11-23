'''
Number: 384
Topic: Shuffle an Array
Date: 2021/10/5
Rate: Medium
https://leetcode.com/problems/shuffle-an-array/

Given an integer array nums, design an algorithm to randomly shuffle the array. All permutations of the array should be equally likely as a result of the shuffling.

Implement the Solution class:
    * Solution(int[] nums) Initializes the object with the integer array nums.
    * int[] reset() Resets the array to its original configuration and returns it.
    * int[] shuffle() Returns a random shuffling of the array.

Constraints:
    * 1 <= nums.length <= 200
    * -106 <= nums[i] <= 106
    * All the elements of nums are unique.
    * At most 5 * 104 calls in total will be made to reset and shuffle.
'''

class Solution:
    def __init__(self, nums: List[int]):
        self.nums = nums
        self.n = len(nums)

    def reset(self) -> List[int]:
        return self.nums

    def shuffle(self) -> List[int]:
        if not self.nums:
            None
        random = self.nums.copy()

        for i in range(self.n):
            j = randint(0, i)
            random[i], random[j] = random[j], random[i]
        return random


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()