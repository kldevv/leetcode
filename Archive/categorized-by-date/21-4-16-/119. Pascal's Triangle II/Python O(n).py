'''
Number: 119
Topic: Pascal's Triangle II
Date: 2021/3/31
Rate: Easy

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

'''

# time complexity O(n)
# space complexity O(n)
class Solution:
    def getRow(self, rowIndex):
            answer = [1]
            for idx in range(1, rowIndex+1):
              answer.append(answer[-1] * (rowIndex-idx+1) // idx)
            return answer


        


