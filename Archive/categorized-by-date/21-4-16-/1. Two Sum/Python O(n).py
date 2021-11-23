class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        diff = dict()
        for idx, pair_1 in enumerate(nums):
            pair_2 = (target - pair_1)
            if pair_2 in diff:
                return [diff[pair_2], idx]
            else:
                diff[pair_1] = idx
        return [None, None]