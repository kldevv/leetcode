/*
Number: 253
Topic: Meeting Rooms II
Date: 2021/12/3
Rate: Medium
https://leetcode.com/problems/meeting-rooms-ii/

Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

Constraints:
    * 1 <= intervals.length <= 104
    * 0 <= starti < endi <= 106
*/

#include <vector>

using namespace std;

class Solution {
   public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        /*
        Given A[start]
            invalid cases:
                - A[start] <= B[start] && B[start] <= A[end]

        Actions:
            For every A:
                Given
                    A[end]
                Count How Many B that (starting from the last B):
                    B[start] < A[end]
                    &&
                    A[start] < B[end]

        %%%%%%%%%%%%%%%

        */
        vector<int> ends;
        vector<int> starts;
        for (vector<int> interval : intervals) {
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int posOfStart = 0;
        int posOfEnd = 0;

        int minRoomRequired = 0;

        for (; posOfEnd < ends.size(); posOfEnd++) {
            while (posOfStart < starts.size() && starts[posOfStart] < ends[posOfEnd])
                posOfStart += 1;
            minRoomRequired = max(minRoomRequired, posOfStart - posOfEnd);
        }
        return minRoomRequired;
    }
};