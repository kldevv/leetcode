/*
Number: 286
Topic: Walls and Gates
Date: 2021/7/18
Rate: Medium
https://leetcode.com/problems/walls-and-gates/

You are given an m x n grid rooms initialized with these three possible values.

* -1 A wall or an obstacle.
* 0 A gate.
* INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Constraints:
* m == rooms.length
* n == rooms[i].length
* 1 <= m, n <= 250
* rooms[i][j] is -1, 0, or 231 - 1.
*/
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = (m) ? rooms[0].size() : 0;
        

        queue<pair<int, int>> nextMove;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!rooms[i][j])
                    nextMove.emplace(i, j);
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        while (!nextMove.empty()) {
            int i = nextMove.front().first;
            int j = nextMove.front().second;
            nextMove.pop();

            for (const pair<int, int>& dir : directions) {
                int x = i + dir.first;
                int y = j + dir.second;

                if (x < 0 || x >= m || y < 0 || y >= n || rooms[x][y] != INT_MAX)
                    continue;

                rooms[x][y] = rooms[i][j] + 1;
                nextMove.emplace(x, y);
            }
        }
    }
};