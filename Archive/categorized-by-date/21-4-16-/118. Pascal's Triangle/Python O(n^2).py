'''
Number: 118
Topic: Pascal's Triangle
Date: 2021/3/25
Rate: Easy

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

'''

# time complexity O(n^2)
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
    	base = [1]
    	result = [base]
    	for i in range(numRows - 1):
    		this_row = [1]
    		for idx in range(len(result[i]) - 1):
    			this_row.append(result[i][idx] + result[i][idx+1])
    		this_row.append(1)
    		result.append(this_row)

    	return result


