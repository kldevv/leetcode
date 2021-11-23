/*
Number: 1610
Topic: Maximum Number of Visible Points
Date: 2021/7/29
Rate: Hard
https://leetcode.com/problems/maximum-number-of-visible-points/

ou are given an array points, an integer angle, and your location, where location = [posx, posy] and points[i] = [xi, yi] both denote integral coordinates on the X-Y plane.

Initially, you are facing directly east from your position. You cannot move from your position, but you can rotate. In other words, posx and posy cannot be changed. Your field of view in degrees is represented by angle, determining how wide you can see from any given view direction. Let d be the amount in degrees that you rotate counterclockwise. Then, your field of view is the inclusive range of angles [d - angle/2, d + angle/2].

You can see some set of points if, for each point, the angle formed by the point, your position, and the immediate east direction from your position is in your field of view.

There can be multiple points at one coordinate. There may be points at your location, and you can always see these points regardless of your rotation. Points do not obstruct your vision to other points.

Return the maximum number of points you can see.

Constraints:
* 1 <= points.length <= 105
* points[i].length == 2
* location.length == 2
* 0 <= angle < 360
* 0 <= posx, posy, xi, yi <= 100
*/

class Solution {
private:
    const double PI = acos(-1);
    const double ERROR = 1e-9;

    double toDegree(int deltaX, int deltaY) {
        return atan2(deltaY, deltaX) * 180.0 / PI;
    }

public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int out = 0;
        int oriX = location[0], oriY = location[1];
        vector<double> pointDegree;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            if (x == oriX && y == oriY) {
                out += 1;
                continue;
            }

            double degree = toDegree(x-oriX, y-oriY);

            pointDegree.push_back(degree);
            pointDegree.push_back(degree + 360);
        }

        sort(pointDegree.begin(), pointDegree.end());
        int maxWindowSize = 0;
        int head = 0, tail = 0;
        for (; tail < pointDegree.size(); tail++) {
            while (head < tail && pointDegree[tail]-pointDegree[head] > (double)angle)
                head += 1;
            maxWindowSize = max(maxWindowSize, tail-head+1);
        }
        out += maxWindowSize;
        
        return out;
    }
};