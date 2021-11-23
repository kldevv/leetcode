/*
Number: 210
Topic: Course Schedule II
Date: 2021/7/6
Rate: Medium
https://leetcode.com/problems/course-schedule-ii/

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Constraints:
* 1 <= numCourses <= 2000
* 0 <= prerequisites.length <= numCourses * (numCourses - 1)
* prerequisites[i].length == 2
* 0 <= ai, bi < numCourses
* ai != bi
* All the pairs [ai, bi] are distinct.
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 1)
            return {0};

        vector<vector<int>> preOfCourse(numCourses);
        vector<int> degree(numCourses, 0);

        for (const vector<int>& p : prerequisites) {
            int course = p[0];
            int pre = p[1];
            preOfCourse[pre].push_back(course);
            degree[course]++;
        }


        vector<int> out;

        queue<int> schedule;
        for (int i = 0; i < degree.size(); i++) {
            if (!degree[i])
                schedule.push(i);
        }

        while (!schedule.empty()) {
            int curCourse = schedule.front();
            schedule.pop();
            out.push_back(curCourse);
            numCourses--;

            for (int afterCourse : preOfCourse[curCourse]) {
                if (!(--degree[afterCourse])) {
                    schedule.push(afterCourse);
                }
            }
        }
        if (numCourses != 0)
            out.clear();

        return out;
    }
};