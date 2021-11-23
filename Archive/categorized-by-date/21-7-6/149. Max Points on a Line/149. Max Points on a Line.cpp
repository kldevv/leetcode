/*
Number: 149
Topic: Max Points on a Line
Date: 2021/7/6
Rate: Hard
https://leetcode.com/problems/max-points-on-a-line/

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

Constraints:
* 1 <= points.length <= 300
* points[i].length == 2
* -104 <= xi, yi <= 104
* All the points are unique.

*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // tc O(n)
        // see post: https://leetcode.com/problems/max-points-on-a-line/discuss/47124/C%2B%2B-slope-counter
        // edge case
        if (points.size() == 1)
            return 1;

        int n = points.size();
        int out = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> umap;
            // allow duplicate points
            int dup = 0;
            for (int j = i+1; j < n; j++) {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                if (x == 0 && y == 0) {
                    dup++;
                    continue;
                }
                // 計算任兩點的斜率
                int normalizer = gcd(x, y);
                x /= normalizer;
                y /= normalizer;

                // 看看有幾個點都有這個斜率
                string key = to_string(x)+"_"+to_string(y);
                if (umap.count(key))
                    umap[key]++;
                else
                    umap[key] = 2;

                out = max(out, umap[key]+dup);
            }
        }
        return out;
    }

private:
    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }
};