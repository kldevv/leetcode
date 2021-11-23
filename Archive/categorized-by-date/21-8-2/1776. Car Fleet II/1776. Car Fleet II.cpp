/*
Number: 1776
Topic: Car Fleet II
Date: 2021/8/2
Rate: Hard
https://leetcode.com/problems/car-fleet-ii/

There are n cars traveling at different speeds in the same direction along a one-lane road. You are given an array cars of length n, where cars[i] = [positioni, speedi] represents:

positioni is the distance between the ith car and the beginning of the road in meters. It is guaranteed that positioni < positioni+1.
speedi is the initial speed of the ith car in meters per second.
For simplicity, cars can be considered as points moving along the number line. Two cars collide when they occupy the same position. Once a car collides with another car, they unite and form a single car fleet. The cars in the formed fleet will have the same position and the same speed, which is the initial speed of the slowest car in the fleet.

Return an array answer, where answer[i] is the time, in seconds, at which the ith car collides with the next car, or -1 if the car does not collide with the next car. Answers within 10-5 of the actual answers are accepted.


Constraints:
* 1 <= cars.length <= 105
* 1 <= positioni, speedi <= 106
* positioni < positioni+1
*/

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> collisionTime(n, -1);
        stack<int> carsAhead;

        for (int i = n-1; i >= 0; i--) {
            int curPosition = cars[i][0];
            int curSpeed = cars[i][1];

            while (!carsAhead.empty()) {
                int positionAhead = cars[carsAhead.top()][0];
                int speedAhead = cars[carsAhead.top()][1];

                double curTimeCollided = getCollisionTimes(curPosition, curSpeed, positionAhead, speedAhead);
                double aheadTimeCollided = collisionTime[carsAhead.top()];
                if (curSpeed <= speedAhead || (aheadTimeCollided != -1 && curTimeCollided >= aheadTimeCollided))
                    // 有沒有比前面那輛車子更慢，如果更慢，那後面所有的車子都應該要先撞到我們
                    // 如果跟前面車子碰撞的時間，比前面車子本身碰撞的時間更晚，那我們要看的是和前面還剩下的車子的碰撞時間，把前面更早碰撞的車子刪除掉，因為後面來的車子都要先和我們碰撞才可以，所以他只要檢查和我們碰撞的時間有沒有比較早，如果比較早，他就會撞到我們，如果比較晚，他要比較的撞擊時間，也是和前面車輛撞擊的時間
                    carsAhead.pop();
                else
                    break;
            }
            if (!carsAhead.empty()) {
                int positionAhead = cars[carsAhead.top()][0];
                int speedAhead = cars[carsAhead.top()][1];

                double curTimeCollided = getCollisionTimes(curPosition, curSpeed, positionAhead, speedAhead);
                collisionTime[i] = curTimeCollided;
            }
            carsAhead.push(i);
        }
        return collisionTime;
    }

    double getCollisionTimes(int pos1, int speed1, int pos2, int speed2) {
        return (double)(pos2-pos1) / (speed1-speed2);
    }
};