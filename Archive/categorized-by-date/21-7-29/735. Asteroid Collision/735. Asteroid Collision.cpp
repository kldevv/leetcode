/*
Number: 735
Topic: Asteroid Collision
Date: 2021/7/29
Rate: Medium
https://leetcode.com/problems/asteroid-collision/

We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Constraints:
* 2 <= asteroids.length <= 104
* -1000 <= asteroids[i] <= 1000
* asteroids[i] != 0
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> out;
        for (int i = 0; i < asteroids.size(); i++) {
            while (!out.empty() && (out.back() > 0 && asteroids[i] < 0) && (abs(out.back()) < abs(asteroids[i])))
                out.pop_back();
            if ((out.empty() || asteroids[i] > 0 || out.back() < 0))
                out.push_back(asteroids[i]);
            else if (asteroids[i] == -out.back())
                out.pop_back();
        }
        return out;
    }
};