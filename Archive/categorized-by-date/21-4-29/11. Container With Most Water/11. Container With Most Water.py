'''
Number: 11
Topic: Container With Most Water
Date: 2021/4/29
Rate: Medium

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.
'''

class Solution:
    def maxArea(self, height: [int]) -> int:
        max_area = 0 
        left, right = 0, len(height)-1
        while left < right:
            max_area = max(max_area, (right-left) * min(height[left], height[right]))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return max_area

'''
grade / pass
tc / O(n)
sc / O(1)
'''



