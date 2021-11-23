'''
Number: 200
Topic: Number of Islands
Date: 2021/10/16
Rate: Medium
https://leetcode.com/problems/number-of-islands/

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Constraints:
    * m == grid.length
    * n == grid[i].length
    * 1 <= m, n <= 300
    * grid[i][j] is '0' or '1'.
'''

class Solution:
    def __init__(self):
        self.m = 0;
        self.n = 0;
        self.direction = [[1, 0], [0, 1], [-1, 0], [0, -1]]

    def numIslands(self, grid: List[List[str]]) -> int:
        def invalidIndex(grid, i, j):
            if i < 0 or j < 0 or i >= self.m or j >= self.n or grid[i][j] == '0':
                return True
            return False

        def eraseIsland(grid, i, j):
            if invalidIndex(grid, i, j):
                return

            grid[i][j] = '0'
            for dirs in self.direction:
                ii = i + dirs[0]
                jj = j + dirs[1]
                eraseIsland(grid, ii, jj)

        self.m = len(grid)
        self.n = len(grid[0])
        result = 0
        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j] == '1':
                    result += 1
                    eraseIsland(grid, i, j)
        return result







