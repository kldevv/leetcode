/*
Number: 252
Topic: Meeting Rooms
Date: 2021/7/16
Rate: Easy
https://leetcode.com/problems/meeting-rooms/

Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

Constraints:
* 0 <= intervals.length <= 104
* intervals[i].length == 2
* 0 <= starti < endi <= 106
*/

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        typedef vector<int> A;
        sort(intervals.begin(), intervals.end(), [](A& i, A& j) {return i[0] <= j[0];});
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i-1][1]) // 這個 meeting 的開始時間比上一個結束的時間早
                return false;
        }
        return true;
    }
};