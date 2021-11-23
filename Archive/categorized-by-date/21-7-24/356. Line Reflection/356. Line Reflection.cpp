/*
Number: 356
Topic: Line Reflection
Date: 2021/7/24
Rate: Medium
https://leetcode.com/problems/line-reflection/

Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points symmetrically, in other words, answer whether or not if there exists a line that after reflecting all points over the given line the set of the original points is the same that the reflected ones.

Note that there can be repeated points.

Follow up:
Could you do better than O(n2) ?

Constraints:
* n == points.length
* 1 <= n <= 10^4
* -10^8 <= points[i][j] <= 10^8
*/

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int n = points.size();
        int maxX = INT_MIN;
        int minX = INT_MAX;
        unordered_set<string> coords;
        for (int i = 0; i < n; i++) {
            string coord = to_string(points[i][0]) + "#" + to_string(points[i][1]);
            coords.insert(coord);
            minX = min(minX, points[i][0]);
            maxX = max(maxX, points[i][0]);
        }

        for (int i = 0; i < n; i++) {
            string rcoord = to_string(maxX-points[i][0]+minX) + "#" + to_string(points[i][1]);
            if (!coords.count(rcoord))
                return false;
        }

        return true;
    }
};