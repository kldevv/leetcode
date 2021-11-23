/*
Number: 207
Topic: Course Schedule
Date: 2021/7/5
Rate: Medium
https://leetcode.com/problems/course-schedule/

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Constraints:
* 1 <= numCourses <= 105
* 0 <= prerequisites.length <= 5000
* prerequisites[i].length == 2
* 0 <= ai, bi < numCourses
* All the pairs prerequisites[i] are unique.
*/


class Solution {
public:
    // topological sort
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        // 把 prerequisites 存成 graph， graph[i] 代表有 i 為先修的所有 course
        for (const auto& p: prerequisites) {
            // preCourse : afterCourse
            graph[p[1]].push_back(p[0]);
            // degree[i] 為，修 i 之前有幾堂課要修
            degree[p[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                // 先找 degree 為 0 也就是沒有先修課的
                if (!degree[j])
                    break;
            }
            if (j == numCourses)
                return false;

            // 修過了就減一
            degree[j]--;
            for (const int& nextCourse : graph[j]) {
                // 這堂課修過之後，所有以這堂課為先修課的 degree 也減一
                degree[nextCourse]--;
            }
        }
        return true;
    }
};
