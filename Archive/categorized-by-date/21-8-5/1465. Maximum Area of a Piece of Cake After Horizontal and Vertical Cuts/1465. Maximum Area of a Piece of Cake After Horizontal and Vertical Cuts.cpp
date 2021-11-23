/*
Number: 1465
Topic: Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
Date: 2021/8/4
Rate: Medium
https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.

Constraints:
* 2 <= h, w <= 109
* 1 <= horizontalCuts.length <= min(h - 1, 105)
* 1 <= verticalCuts.length <= min(w - 1, 105)
* 1 <= horizontalCuts[i] < h
* 1 <= verticalCuts[i] < w
* All the elements in horizontalCuts are distinct.
* All the elements in verticalCuts are distinct.
*/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int maxY = horizontalCuts[0];
        int maxX = verticalCuts[0];
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);

        for (int i = 1; i < horizontalCuts.size(); i++) {
            maxY = max(maxY, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        for (int j = 1; j < verticalCuts.size(); j++) {
            maxX = max(maxX, verticalCuts[j] - verticalCuts[j-1]);
        }

        const int BASE = 1e9 + 7;
        return (((long)maxY % BASE) * ((long)maxX % BASE) % BASE);
    }
};