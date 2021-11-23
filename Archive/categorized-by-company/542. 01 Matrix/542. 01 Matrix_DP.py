'''
Number: 542
Topic: 01 Matrix
Date: 2021/9/1
Rate: Medium
https://leetcode.com/problems/01-matrix/

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Constraints:
* m == mat.length
* n == mat[i].length
* 1 <= m, n <= 104
* 1 <= m * n <= 104
* mat[i][j] is either 0 or 1.
* There is at least one 0 in mat.
'''

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0]) if m != 0 else 0

        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    continue
                top = mat[i-1][j] + 1 if i > 0 else m+n
                left = mat[i][j-1] + 1 if j > 0 else m+n
                mat[i][j] = min(top, left)

        for ri in range(m-1, -1, -1):
            for rj in range(n-1, -1, -1):
                if mat[ri][rj] == 0:
                    continue
                down = mat[ri+1][rj] + 1 if ri < m-1 else m+n
                right = mat[ri][rj+1] + 1 if rj < n-1 else m+n
                mat[ri][rj] = min(mat[ri][rj], down, right)

        return mat