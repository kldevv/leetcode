'''
Number: 56
Topic: Merge Intervals
Date: 2021/5/5
Rate: Medium

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

'''

class Solution:
    def merge(self, intervals: [[int]]) -> [[int]]:
        if not intervals:
            return []

        temp = None
        outputInterval = []

        for interval in sorted(intervals, key=lambda i : i[0]):
            if not temp:
                temp = interval
            # 如果頭以大於前一個的尾，則可確定前個 interval 不會再有 overlapping 的情形
            elif temp[1] < interval[0]:
                outputInterval.append(temp)
                temp = interval
            # 若有 overlapping，取最大 interval 的尾巴
            else:
                temp[1] = max(temp[1], interval[1])
        outputInterval.append(temp)
        return outputInterval


'''
grade / pass
tc / O(n) where n = number of intervals
sc / O(1) if in-place
'''



