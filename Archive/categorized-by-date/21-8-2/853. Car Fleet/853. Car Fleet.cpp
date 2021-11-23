/*
Number: 853
Topic: Car Fleet
Date: 2021/8/2
Rate: Medium
https://leetcode.com/problems/car-fleet/

There are n cars going to the same destination along a one-lane road. The destination is target miles away.

You are given two integer array position and speed, both of length n, where position[i] is the position of the ith car and speed[i] is the speed of the ith car (in miles per hour).

A car can never pass another car ahead of it, but it can catch up to it, and drive bumper to bumper at the same speed.

The distance between these two cars is ignored (i.e., they are assumed to have the same position).

A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.

Return the number of car fleets that will arrive at the destination.

Constraints:
* n == position.length == speed.length
* 1 <= n <= 105
* 0 < target <= 106
* 0 <= position[i] < target
* All the values of position are unique.
* 0 < speed[i] <= 106
*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> timeToFinish; // start postion, rounds to finish line

        for (int i = 0; i < n; i++) {
            timeToFinish.emplace_back(position[i], (double)(target-position[i]) / speed[i]);
        }

        sort(timeToFinish.begin(), timeToFinish.end());

        int carFleet = 0;
        double slowest = 0;
        for (int i = n-1; i >= 0; i--) {
            if (timeToFinish[i].second > slowest) {
                carFleet += 1;
                slowest = timeToFinish[i].second;
            }
        }

        return carFleet;
    }
};