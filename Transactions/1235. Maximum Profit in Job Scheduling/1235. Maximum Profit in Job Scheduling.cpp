/*
Number: 1235
Topic: Maximum Profit in Job Scheduling
Date: 2021/9/15
Rate: Hard
https://leetcode.com/problems/maximum-profit-in-job-scheduling/

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

Constraints:
    * 1 <= startTime.length == endTime.length == profit.length <= 5 * 104
    * 1 <= startTime[i] < endTime[i] <= 109
    * 1 <= profit[i] <= 104
*/

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n  = startTime.size();

        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());

       map<int, int> dp = {{0, 0}};
        for (auto& job : jobs) {
            int curProfit = prev(dp.upper_bound(job[1]))->second + job[2]; // binary search starting time 
            if (curProfit > dp.rbegin()->second) {
                dp[job[0]] = curProfit;
            }
        }
        return dp.rbegin()->second;
    }
};