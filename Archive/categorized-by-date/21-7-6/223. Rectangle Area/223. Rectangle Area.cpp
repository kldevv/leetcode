/*
Number: 223
Topic: Rectangle Area
Date: 2021/7/6
Rate: Medium
https://leetcode.com/problems/rectangle-area/

Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.

The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).

The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).


Constraints:
* -10^4 <= ax1, ay1, ax2, ay2, bx1, by1, bx2, by2 <= 10^4

*/

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaA = (ax2-ax1) * (ay2-ay1);
        int areaB = (bx2-bx1) * (by2-by1);

        if (bx1 >= ax2 || by1 >= ay2 || bx2 <= ax1 || by2 <= ay1)
            return areaA + areaB;

        vector<int> x = {ax1, ax2, bx1, bx2};
        sort(x.begin(), x.end());
        vector<int> y = {ay1, ay2, by1, by2};
        sort(y.begin(), y.end());

        int areaC = (x[2]-x[1]) * (y[2]-y[1]);
        
        return areaA + areaB - areaC;
    }
};