/*
Number: 1167
Topic: Minimum Cost to Connect Sticks
Date: 2021/9/25
Rate: Medium
https://leetcode.com/problems/minimum-cost-to-connect-sticks/

You have some number of sticks with positive integer lengths. These lengths are given as an array sticks, where sticks[i] is the length of the ith stick.

You can connect any two sticks of lengths x and y into one stick by paying a cost of x + y. You must connect all the sticks until there is only one stick remaining.

Return the minimum cost of connecting all the given sticks into one stick in this way.

Constraints:
    * 1 <= sticks.length <= 104
    * 1 <= sticks[i] <= 104
*/

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> minHeap(sticks.begin(), sticks.end());
        int result = 0;
        int A, B;
        while (minHeap.size() > 1) {
            A = minHeap.top(), minHeap.pop();
            B = minHeap.top(), minHeap.pop();
            result += (A + B);
            minHeap.push(A + B);
        }
        return result;
    }
};