// 2022/1/3

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();
        
        int idx = 0;
        while (idx < n && intervals[idx][1] < newInterval[0]) {
            result.push_back(intervals[idx++]);
        }
        while (idx < n && intervals[idx][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);
            idx++;
        }
        result.push_back(newInterval);
        while (idx < n) {
            result.push_back(intervals[idx++]);
        }
        return result;
    }
};