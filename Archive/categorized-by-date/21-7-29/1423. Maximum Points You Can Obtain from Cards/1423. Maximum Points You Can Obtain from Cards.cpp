/*
Number: 1423
Topic: Maximum Points You Can Obtain from Cards
Date: 2021/7/29
Rate: Medium
https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Constraints:
* 1 <= cardPoints.length <= 105
* 1 <= cardPoints[i] <= 104
* 1 <= k <= cardPoints.length
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        vector<int> sumFromBegin(k+1, 0);
        vector<int> sumFromEnd(k+1, 0);
        for (int i = 1; i <= k; i++) {
            sumFromBegin[i] = sumFromBegin[i-1] + cardPoints[i-1];
            sumFromEnd[i] = sumFromEnd[i-1] + cardPoints[n-i];
        }

        int out = INT_MIN;
        for (int i = 0; i <= k; i++) {
            out = max(out, sumFromBegin[i]+sumFromEnd[k-i]);
        }
        return out;
    }
};