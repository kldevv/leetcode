/*
Number: 302
Topic: Smallest Rectangle Enclosing Black Pixels
Date: 2021/7/26
Rate: Hard
https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/

You are given an image that is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel.

The black pixels are connected (i.e., there is only one black region). Pixels are connected horizontally and vertically.

Given two integers x and y that represent the location of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

Constraints:
* m == image.length
* n == image[i].length
* 1 <= m, n <= 100
* image[i][j] is either '0' or '1'.
* 1 <= x < m
* 1 <= y < n
* image[x][y] == '1'.
* The black pixels in the image only form one component.
*/

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = (m) ? image[0].size() : 0;

        int left = findBoudary(0, y, LEFT, HORIZONTAL, image);
        int right = findBoudary(y+1, n-1, RIGHT, HORIZONTAL, image);

        int top = findBoudary(0, x, LEFT, VERTICAL, image);
        int bottom = findBoudary(x+1, m-1, RIGHT, VERTICAL, image);

        return (right - left + 1) * (bottom - top + 1);
    }

private:
    const bool LEFT = true;
    const bool RIGHT = false;

    const bool VERTICAL = false;
    const bool HORIZONTAL = true;

    int findBoudary(int start, int end, bool findLeft, bool findHorizontal, const vector<vector<char>>& image) {
        int left = start, right = end;
        while (left <= right) {
            int mid = left + (right-left)/2;
            bool black = hasBlackPixel(mid, findHorizontal, image);

            if (black == findLeft)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return (findLeft) ? left : right;
    }

    bool hasBlackPixel(int mid, bool horizontal, const vector<vector<char>>& image) {
        int m = image.size();
        int n = (m) ? image[0].size() : 0;

        if (horizontal) {
            for (int i = 0; i < m; i++) {
                if (image[i][mid] == '1')
                    return true;
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                if (image[mid][i] == '1')
                    return true;
            }            
        }
        return false;
    }
};