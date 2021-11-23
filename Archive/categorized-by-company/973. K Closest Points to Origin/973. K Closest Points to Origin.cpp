/*
Number: 973
Topic: K Closest Points to Origin
Date: 2021/8/23
Rate: Medium
https://leetcode.com/problems/k-closest-points-to-origin/

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Constraints:
* 1 <= k <= points.length <= 104
* -104 < xi, yi < 104
*/

class Solution {
private:
    struct comparator {
        bool operator()(vector<int>& A, vector<int>& B) {
            return A[0]*A[0] + A[1]*A[1] < B[0]*B[0] + B[1]*B[1]; 
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin()+k, points.end(), comparator());

        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
};