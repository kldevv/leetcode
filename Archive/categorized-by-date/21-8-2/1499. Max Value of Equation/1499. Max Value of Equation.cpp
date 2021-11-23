/*
Number: 1499
Topic: Max Value of Equation
Date: 2021/8/2
Rate: Hard
https://leetcode.com/problems/max-value-of-equation/

You are given an array points containing the coordinates of points on a 2D plane, sorted by the x-values, where points[i] = [xi, yi] such that xi < xj for all 1 <= i < j <= points.length. You are also given an integer k.

Return the maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <= k and 1 <= i < j <= points.length.

It is guaranteed that there exists at least one pair of points that satisfy the constraint |xi - xj| <= k.

Constraints:
* 2 <= points.length <= 105
* points[i].length == 2
* -108 <= xi, yi <= 108
* 0 <= k <= 2 * 108
* xi < xj for all 1 <= i < j <= points.length
* xi form a strictly increasing sequence.
*/

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> deq;
        int maxVal = INT_MIN;
        for (const vector<int>& point : points) {
            int x = point[0], y = point[1];

            while (!deq.empty() && x - deq.front().second > k)
                deq.pop_front();

            if (!deq.empty())
                maxVal = max(maxVal, x+y+deq.front().first);

            while (!deq.empty() && deq.back().first <= y-x)
                deq.pop_back();

            deq.emplace_back(y-x, x);
        }
        return maxVal;
    }
};