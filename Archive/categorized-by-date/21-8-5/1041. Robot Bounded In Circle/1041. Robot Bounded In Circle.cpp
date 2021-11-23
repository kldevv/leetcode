/*
Number: 1041
Topic: Robot Bounded In Circle
Date: 2021/8/4
Rate: Medium
https://leetcode.com/problems/fruit-into-baskets/

On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:

* "G": go straight 1 unit;
* "L": turn 90 degrees to the left;
* "R": turn 90 degrees to the right.

The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

Constraints:
* 1 <= instructions.length <= 100
* instructions[i] is 'G', 'L' or, 'R'.
*/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        int deltaY = 1;
        int deltaX = 0;
        for (char& move : instructions) {
            if (move == 'G') {
                x += deltaX;
                y += deltaY;
            }
            if (move == 'L') {
                deltaX *= -1;
                swap(deltaY, deltaX);
            }
            if (move == 'R') {
                swap(deltaY, deltaX);
                deltaX *= -1;
            }
        }
        return (!x) && (!y) || (deltaY != 1);
    }
};