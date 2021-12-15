/*
Number: 252
Topic: Meeting Rooms
Date: 2021/12/3
Rate: Easy
https://leetcode.com/problems/meeting-rooms/

Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

Constraints:
    * 0 <= intervals.length <= 104
    * intervals[i].length == 2
    * 0 <= starti < endi <= 106
*/

#include <vector>

using namespace std;

class Solution {
   public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        /*
        Objective:
            Show there is no A[start] <= B[start] < A[end] <= B[end]
            Given:
                A[start] <= B[start]
            Find:
                A[end] > B[start]

        sorted(intervals)
        Invariant:
            prev[start] < this[start]
        Find:
            prev[end] > this[start]
        */
        sort(intervals.begin(), intervals.end(), [](vector<int>& A, vector<int>& B) { return A[0] < B[0]; });

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i - 1][1] > intervals[i][0]) {
                return false;
            }
        }
        return true;
    }
};