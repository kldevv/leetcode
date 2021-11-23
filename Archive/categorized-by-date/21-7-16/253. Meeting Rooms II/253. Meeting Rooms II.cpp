/*
Number: 253
Topic: Meeting Rooms II
Date: 2021/7/16
Rate: Medium
https://leetcode.com/problems/meeting-rooms-ii/

Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

Constraints:
* 1 <= intervals.length <= 104
* 0 <= starti < endi <= 106
*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // 把開始的時間和結束的時間分別儲存和排列，當作兩種不同的 event
        int n = intervals.size();
        vector<int> start;
        vector<int> end;
        for (int i = 0; i < n; i++) {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }  
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        // 每個開始 event 之前都要有一個結束的 event，這樣的話就可以以互相抵銷
        // 不然就要多一個 meeting room，用來抵銷開始 event 但維持結束 event
        // 越多 meeting room， 開始 event 對到的就是越前面的結束 event。
        int room = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (start[i] < end[j])
                room += 1;
            else
                j++;
        }
        return room;
    }
};