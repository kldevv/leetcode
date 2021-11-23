/*
Number: 1353
Topic: Maximum Number of Events That Can Be Attended
Date: 2021/9/15
Rate: Medium
https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

Given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. Notice that you can only attend one event at any time d.

Return the maximum number of events you can attend.

Constraints:
    * 1 <= events.length <= 105
    * events[i].length == 2
    * 1 <= startDayi <= endDayi <= 105
*/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq; 
        int result = 0;
        int idx = 0;
        int curDay = 0;

        while (pq.size() || idx < n) {
            if (pq.empty())
                curDay = events[idx][0];

            while (idx < n && events[idx][0] <= curDay)
                pq.push(events[idx++][1]);

            pq.pop();
            result += 1;
            curDay += 1;

            while (pq.size() && pq.top() < curDay)
                pq.pop();
        }

        return result;
    }
};