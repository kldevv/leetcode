/*
Number: 489
Topic: Robot Room Cleaner
Date: 2021/8/6
Rate: Hard
https://leetcode.com/problems/robot-room-cleaner/

You are controlling a robot that is located somewhere in a room. The room is modeled as an m x n binary grid where 0 represents a wall and 1 represents an empty slot.

The robot starts at an unknown location in the root that is guaranteed to be empty, and you do not have access to the grid, but you can move the robot using the given API Robot.

You are tasked to use the robot to clean the entire room (i.e., clean every empty cell in the room). The robot with the four given APIs can move forward, turn left, or turn right. Each turn is 90 degrees.

When the robot tries to move into a wall cell, its bumper sensor detects the obstacle, and it stays on the current cell.

Design an algorithm to clean the entire room using the following APIs:

Note that the initial direction of the robot will be facing up. You can assume all four edges of the grid are all surrounded by a wall.

Custom testing:
The input is only given to initialize the room and the robot's position internally. You must solve this problem "blindfolded". In other words, you must control the robot using only the four mentioned APIs without knowing the room layout and the initial robot's position.

Constraints:
* m == room.length
* n == room[i].length
* 1 <= m <= 100
* 1 <= n <= 200
* room[i][j] is either 0 or 1.
* 0 <= row < m
* 0 <= col < n
* room[row][col] == 1
* All the empty cells can be visited from the starting position.
*/

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    void cleanRoom(Robot& robot) {
        unordered_set<string> umap;
        cleanRoom(robot, 0, 0, 1, 0, umap);
    }

    void cleanRoom(Robot& robot, int i, int j, int deltaI, int deltaJ, unordered_set<string>& umap) {
        string coord = to_string(i) + " # " + to_string(j);
        
        if (umap.count(coord))
            return;

        robot.clean();
        umap.insert(coord);

        for (int k = 0; k < 4; k++) {
            if (robot.move()) {
                cleanRoom(robot, i+deltaI, j+deltaJ, deltaI, deltaJ, umap);
                // back to initial status
                robot.turnRight(), robot.turnRight(); // back to the origin position
                robot.move();
                robot.turnRight(), robot.turnRight(); // face the same direction
            }
            // turn right
            robot.turnRight();
            deltaJ *= -1;
            swap(deltaI, deltaJ);
        }
    }
};