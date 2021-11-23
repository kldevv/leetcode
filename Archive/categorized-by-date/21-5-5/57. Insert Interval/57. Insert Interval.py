'''
Number: 57
Topic: Insert Interval
Date: 2021/5/5
Rate: Medium

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
'''




class Solution:
    def insert(self, intervals: [[int]], newInterval: [int]) -> [[int]]:
        insertion_start = newInterval[0]
        insertion_end = newInterval[1]
        if not intervals:
            return [newInterval]

        outputInterval = []
        for idx, interval in enumerate(intervals):
            # 如果目前 interval 的尾端比要插入的 interval 還要小，代表兩者沒有交集
            if interval[1] < insertion_start:
                outputInterval.append(interval)
            # 如果目前 interval 的頭部比要插入的 interval 還要大，代表兩者沒有交集，且之後的 intervals 都不變
            elif interval[0] > insertion_end:
                return outputInterval + [[insertion_start, insertion_end]] + intervals[idx:]
            # 如果有交集，就把頭跟尾巴依照情況展開
            else:
                insertion_start = min(interval[0], insertion_start)
                insertion_end = max(interval[1], insertion_end)
        return outputInterval + [[insertion_start, insertion_end]]
        
'''
grade / pass
tc / O(n) where n = number of intervals
sc / O(1) if in-place
'''



