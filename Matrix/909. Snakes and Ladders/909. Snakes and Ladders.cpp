/*
Number: 909
Topic: Snakes and Ladders
Date: 2021/9/28
Rate: Medium
https://leetcode.com/problems/snakes-and-ladders/

You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

* Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
    * This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
* If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
* The game ends when you reach the square n2.

A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.
    * For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.


Constraints:
    * n == board.length == board[i].length
    * 2 <= n <= 20
    * grid[i][j] is either -1 or in the range [1, n2].
    * The squares labeled 1 and n2 do not have any ladders or snakes.
*/

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));

        queue<int> q;
        q.push(1);
        int step = 0;

        while (q.size()) {
            int qSize = q.size();
            step += 1;
            for (int t = 0; t < qSize; t++) {
                int curr = q.front();
                q.pop();
                for (int inc = min(6, n*n-curr); inc > 0; inc--) {
                    int next = curr + inc;
                    auto [i, j] = convert(next, n);

                    if (visited[i][j])
                        continue;
                    visited[i][j] = 1;

                    if (board[i][j] != -1) {
                        next = board[i][j];
                    }
                    if (next == n*n)
                        return step;
                    q.push(next);
                }
            }
        }
        return -1;
    }

    pair<int, int> convert(int coord, int n) {
        coord -= 1;
        int i = coord / n;
        int j = coord % n;

        if (i % 2)
            j = n - 1 - j;
        return {n - 1 - i, j};
    }
};