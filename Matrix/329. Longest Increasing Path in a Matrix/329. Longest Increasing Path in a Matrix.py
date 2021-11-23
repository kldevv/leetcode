'''
Number: 329
Topic: Longest Increasing Path in a Matrix
Date: 2021/10/16
Rate: Hard
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

Constraints:
    * m == matrix.length
    * n == matrix[i].length
    * 1 <= m, n <= 200
    * 0 <= matrix[i][j] <= 231 - 1
'''

class Solution:
    def __init__(self):
        self.dp = [[]]
        self.m = 0
        self.n = 0
        self.maxLen = 0

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        def dfs(matrix, i, j, prev):
            if i < 0 or j < 0 or i >= self.m or j >= self.n or matrix[i][j] <= prev:
                return 0
            if self.dp[i][j] == -1:
                    searchUp = dfs(matrix, i+1, j, matrix[i][j])
                    searchDown = dfs(matrix, i-1, j, matrix[i][j])
                    searchLeft = dfs(matrix, i, j-1, matrix[i][j])
                    searchRight = dfs(matrix, i, j+1, matrix[i][j])

                    self.dp[i][j] = max([searchUp, searchDown, searchLeft, searchRight]) + 1
                    self.maxLen = max(self.maxLen, self.dp[i][j])
            return self.dp[i][j]

        self.m = len(matrix)
        self.n = len(matrix[0])
        self.dp = [[-1] * self.n for _ in range(self.m)]

        for i in range(self.m):
            for j in range(self.n):
                dfs(matrix, i, j, -1)
        result = self.maxLen
        return result




        
                
