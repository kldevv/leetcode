'''
Number: 42
Topic: Trapping Rain Water
Date: 2021/4/29
Rate: Hard

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining
'''

class Solution:
    def trap(self, height: [int]) -> int:
        left, right = 0, len(height)-1
        total_water = 0
        cur_floor_level = 0
        highest_level = 0

        # 只要沒有 iterate 完就一直執行
        while (left < right):
            # 紀錄比較矮的那一邊的 level 並且往內移動
            if height[left] > height[right]:
                cur_floor_level = height[right]
                right -= 1
            else:
                cur_floor_level = height[left]
                left += 1
            # 如果遇到比較高的 level 就更新 bucket bar 的高度，且不加入新的水
            # 如果遇到比較低的 level 就加入 bucket bar - current level 的水
            highest_level = max(cur_floor_level, highest_level)
            total_water += highest_level - cur_floor_level
        return total_water
        
'''
grade / pass
tc / O(n)
sc / O(1)
'''



