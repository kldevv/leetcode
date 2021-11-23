/*
Number: 391
Topic: Perfect Rectangle
Date: 2021/7/6
Rate: Hard
https://leetcode.com/problems/perfect-rectangle/

Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).

Return true if all the rectangles together form an exact cover of a rectangular region.


Constraints:
* 1 <= rectangles.length <= 2 * 10^4
* rectangles[i].length == 4
* -105 <= xi, yi, ai, bi <= 105

*/

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        double cumArea = 0;
        int minLeft = INT_MAX, maxRight = INT_MIN, maxHigh = INT_MIN, minLow = INT_MAX;
        unordered_map<string, int> umap;
        // 兩個規則：
        // 小長方形面積的加總要等於大長方形
        // 除了四個角角以外的所有點都要出現偶數次
        // e.g. T 字交點會出現 2 次, + 字交點會出現 4 次
        // see post: https://leetcode.com/problems/perfect-rectangle/discuss/87181/Really-Easy-Understanding-Solution(O(n)-Java)


        int left, right, high, low;
        for (const vector<int>& re : rectangles) {
            left = re[0];
            low = re[1];
            right = re[2];
            high = re[3];

            cumArea += (right-left)*(high-low);

            minLeft = min(minLeft, left);
            maxRight = max(maxRight, right);
            minLow = min(minLow, low);
            maxHigh = max(maxHigh, high);

            umap[to_string(left)+"_"+to_string(low)]++;
            umap[to_string(left)+"_"+to_string(high)]++;
            umap[to_string(right)+"_"+to_string(low)]++;
            umap[to_string(right)+"_"+to_string(high)]++;
        }

        string corner1 = to_string(minLeft) + "_" + to_string(minLow);
        string corner2 = to_string(minLeft) + "_" + to_string(maxHigh);
        string corner3 = to_string(maxRight) + "_" + to_string(minLow);
        string corner4 = to_string(maxRight) + "_" + to_string(maxHigh);
        for (auto& p : umap) {
            if (p.first != corner1 && p.first != corner2 && p.first != corner3 && p.first != corner4) {
                if (p.second%2 != 0)
                    return false;
            } else {
                if (p.second != 1)
                    return false;
            }
        }

        double totalArea = (maxRight-minLeft)*(maxHigh-minLow);
        return totalArea == cumArea;
    }
};