/*
Number: 317
Topic: Shortest Distance from All Buildings
Date: 2021/7/26
Rate: Hard
https://leetcode.com/problems/shortest-distance-from-all-buildings/

You are given an m x n grid grid of values 0, 1, or 2, where:

* each 0 marks an empty land that you can pass by freely,
* each 1 marks a building that you cannot pass through, and
* each 2 marks an obstacle that you cannot pass through.
You want to build a house on an empty land that reaches all buildings in the shortest total travel distance. You can only move up, down, left, and right.

Return the shortest travel distance for such a house. If it is not possible to build such a house according to the above rules, return -1.

The total travel distance is the sum of the distances between the houses of the friends and the meeting point.

The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

Constraints:
* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 100
* grid[i][j] is either 0, 1, or 2.
* There will be at least one building in the grid.
*/

class Solution {
private:
    const vector<vector<int>> DIRECTION = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = (m) ? grid[0].size() : 0;
        int minDistance = -1;
        vector<vector<int>> totalDist(m, vector<int>(n, 0));
        vector<vector<int>> zeroDist(m, vector<int>(n, 0));

        int target = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    minDistance = -1;
                    vector<vector<int>> curDist = zeroDist;

                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();                        
                        for (const vector<int>& dir : DIRECTION) {
                            int x2 = x + dir[0];
                            int y2 = y + dir[1];
                            if (x2 < 0 || y2 < 0 || x2 >= m || y2 >= n || grid[x2][y2] != target)
                                continue;

                            grid[x2][y2] -= 1;
                            curDist[x2][y2] = curDist[x][y] + 1;
                            totalDist[x2][y2] += curDist[x2][y2];
                            minDistance = (minDistance == -1) ? totalDist[x2][y2] : min(minDistance, totalDist[x2][y2]);
                            q.emplace(x2, y2);
                        }
                    }
                    target -= 1;
                }
            }
        }
        return minDistance;
    }
};