/*
Number: 305
Topic: Number of Islands II
Date: 2021/7/26
Rate: Hard
https://leetcode.com/problems/number-of-islands-ii/

You are given an empty 2D binary grid grid of size m x n. The grid represents a map where 0's represent water and 1's represent land. Initially, all the cells of grid are water cells (i.e., all the cells are 0's).

We may perform an add land operation which turns the water at position into a land. You are given an array positions where positions[i] = [ri, ci] is the position (ri, ci) at which we should operate the ith operation.

Return an array of integers answer where answer[i] is the number of islands after turning the cell (ri, ci) into a land.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Constraints:
* 1 <= m, n, positions.length <= 104
* 1 <= m * n <= 104
* positions[i].length == 2
* 0 <= ri < m
* 0 <= ci < n
*/


class Solution {
public:
    const vector<vector<int>> DIRECTION = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> roots(m*n , -1);
        vector<int> sizes(m*n , 0);
        int count = 0;
        vector<int> out;

        for (const vector<int>& pos : positions) {
            int i = pos[0] * n + pos[1];
            if (roots[i] != -1) {
                out.push_back(count);
                continue;
            }

            roots[i] = i;
            sizes[i] = 1;
            count += 1;

            int curRoots = findRoots(i, roots);
            for (const vector<int>& dir : DIRECTION) {
                int x = pos[0] + dir[0];
                int y = pos[1] + dir[1];
                int neighbor = x*n + y;

                if (x < 0 || y < 0 || x >= m || y >= n || roots[neighbor] == -1)
                    continue;

                int neighborRoots = findRoots(neighbor, roots);
                if (curRoots != neighborRoots) {
                    unionRoots(curRoots, neighborRoots, roots, sizes);
                    count -= 1;
                    curRoots = roots[curRoots];
                }
            }
            out.push_back(count);
        }
        return out;
    }

    void unionRoots(int root1, int root2, vector<int>& roots, vector<int>& sizes) {
        if (root1 == root2)
            return;

        if (sizes[root1] < sizes[root2]) {
            sizes[root2] += sizes[root1];
            roots[root1] = root2;
        }
        else {
            sizes[root1] += sizes[root2];
            roots[root2] = root1;                   
        }
    }

    int findRoots(int i, vector<int>& roots) {
        if (roots[i] != i)
            roots[i] = findRoots(roots[i], roots);
        return roots[i];
    }
};