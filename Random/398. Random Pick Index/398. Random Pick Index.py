'''
Number: 398
Topic: Random Pick Index
Date: 2021/10/5
Rate: Medium
https://leetcode.com/problems/random-pick-index/

Given an integer array nums with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.
Implement the Solution class:
    * Solution(int[] nums) Initializes the object with the array nums.
    * int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, then each index should have an equal probability of returning.

Constraints:
    * 1 <= nums.length <= 2 * 104
    * -231 <= nums[i] <= 231 - 1
    * target is an integer from nums.
    * At most 104 calls will be made to pick.
'''

class Solution:
    def __init__(self, nums: List[int]):
        self.look_up = dict()
        for idx, num in enumerate(nums):
            if num not in self.look_up:
                self.look_up[num] = []
            self.look_up[num].append(idx)

    def pick(self, target: int) -> int:
        n = len(self.look_up[target])
        return self.look_up[target][randint(0, n-1)]
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)