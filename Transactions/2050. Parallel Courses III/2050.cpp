/*
<LeetCodePracticeC++>
    
- Name: 2050. Parallel Courses III
- Difficulty: Hard
- URL: https://leetcode.com/problems/parallel-courses-iii/
- Description: 

    You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given a 2D integer array relations where relations[j] = [prevCoursej, nextCoursej] denotes that course prevCoursej has to be completed before course nextCoursej (prerequisite relationship). Furthermore, you are given a 0-indexed integer array time where time[i] denotes how many months it takes to complete the (i+1)th course.

    You must find the minimum number of months needed to complete all the courses following these rules:

        - You may start taking a course at any time if the prerequisites are met.
        - Any number of courses can be taken at the same time.
    
    Return the minimum number of months needed to complete all the courses.

    Note: The test cases are generated such that it is possible to complete every course (i.e., the graph is a directed acyclic graph).

- Constraints:
    - 1 <= n <= 5 * 104
    - 0 <= relations.length <= min(n * (n - 1) / 2, 5 * 104)
    - relations[j].length == 2
    - 1 <= prevCoursej, nextCoursej <= n
    - prevCoursej != nextCoursej
    - All the pairs [prevCoursej, nextCoursej] are unique.
    - time.length == n
    - 1 <= time[i] <= 104
    - The given graph is a directed acyclic graph.

- Date: 12/13/2021

</LeetCodePracticeC++>
*/

#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> graph;
    vector<int> memo;
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        /*
        DFS

        Starting from the zero indegree nodes

            DFS to find the maximum weighted path from root to leaf

            memo[course] = int timeNeededToComplete


            if memo[course], return memo[course]

            if graph[course].size() == 0 return time[course]

            for child : graph[course]:
                memo[course] = max(memo[course], recur(child) + time[course])
            
            return memo[course]
        */
        this->graph = vector(n, vector<int>());
        this->memo = vector(n, -1);

        vector<int> degree(n, 0);
        for (vector<int> relation : relations) {
            int prev = relation[0] - 1;
            int next = relation[1] - 1;
            graph[prev].push_back(next);
            degree[next] += 1;
        }

        vector<int> start;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) {
                start.push_back(i);
            }
        }

        int maxTime = INT_MIN;
        for (int course : start) {
            maxTime = max(maxTime, minimumTime(course, time));
        }
        return maxTime;
    }

    int minimumTime(int course, vector<int>& time) {
        if (graph[course].size() == 0)
            return time[course];

        if (memo[course] != -1)
            return memo[course];

        for (int child : graph[course]) {
            memo[course] = max(memo[course], time[course] + minimumTime(child, time));
        }
        return memo[course];
    }
};