/*
Number: 490
Topic: The Maze
Date: 2021/10/4
Rate: Medium
https://leetcode.com/problems/the-maze/

There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return true if the ball can stop at the destination, otherwise return false.

You may assume that the borders of the maze are all walls (see examples).

Constraints:
    * m == maze.length
    * n == maze[i].length
    * 1 <= m, n <= 100
    * maze[i][j] is 0 or 1.
    * start.length == 2
    * destination.length == 2
    * 0 <= startrow, destinationrow <= m
    * 0 <= startcol, destinationcol <= n
    * Both the ball and the destination exist in an empty space, and they will not be in the same position initially.
    * The maze contains at least 2 empty spaces.
*/

class Solution {
private:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = (m) ? maze[0].size() : 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        return dfs(maze, start[0], start[1], destination, visited);
    }

    bool dfs(vector<vector<int>>& maze, int newRow, int newCol, vector<int>& destination, vector<vector<int>>& visited) {
        int m = maze.size();
        int n = (m) ? maze[0].size() : 0;
        for (vector<int>& dir : directions) {
            int curRow = newRow+dir[0];
            int curCol = newCol+dir[1];

            if (!validIndex(curRow, curCol, maze))
                continue;

            while (validIndex(curRow+dir[0], curCol+dir[1], maze)) {
                curRow += dir[0];
                curCol += dir[1];
            }

            if (destination[0] == curRow && destination[1] == curCol)
                return true;

            if (visited[curRow][curCol] == 1)
                continue;

            visited[curRow][curCol] = 1;
            if (dfs(maze, curRow, curCol, destination, visited))
                return true;
        }
        return false;
    }

    bool validIndex(int i, int j, vector<vector<int>>& maze) {
        int m = maze.size();
        int n = (m) ? maze[0].size() : 0;
        if (i < 0 || j < 0 || i >= m || j >= n || maze[i][j] == 1)
            return false;
        return true;
    }
};