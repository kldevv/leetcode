/*
Number: 210
Topic: Course Schedule II
Date: 2021/12/2
Rate: Medium
https://leetcode.com/problems/course-schedule-ii/

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
    * For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Constraints:
    * 1 <= numCourses <= 2000
    * 0 <= prerequisites.length <= numCourses * (numCourses - 1)
    * prerequisites[i].length == 2
    * 0 <= ai, bi < numCourses
    * ai != bi
    * All the pairs [ai, bi] are distinct.
*/

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
        Topological sorting

        Input:
            [course, prerequisite]

        For [B, A] in trans:
            invPrerequisite[A] = [B, courses...] // A is prerequisite of courses...
            numOfPrerequisite[B] += 1

        For i = 0 to course num:
            if numOfPrerequisite[i] == 0:
                put i to zeroDegree

        For courseX in zeroDegree:
            take courseX
            erase courses that have courseX as prerequisite
            put courses with zero prerequisite to zeroDegree
        */
        vector<int> numOfPrerequisite(numCourses, 0);
        unordered_map<int, vector<int>> invPrerequisite;

        // get map
        for (vector<int> pr : prerequisites) {
            int course = pr[0];
            int prerequsite = pr[1];

            invPrerequisite[prerequsite].push_back(course);
            numOfPrerequisite[course] += 1;
        }

        // get zero degree
        queue<int> zeroPrereqs;
        for (int course = 0; course < numCourses; course++) {
            if (numOfPrerequisite[course] == 0)
                zeroPrereqs.push(course);
        }

        // take courses
        vector<int> takeOrder;
        while (zeroPrereqs.size()) {
            int take = zeroPrereqs.front();
            zeroPrereqs.pop();
            takeOrder.push_back(take);
            for (int neighborCourse : invPrerequisite[take]) {
                if (--numOfPrerequisite[neighborCourse] == 0)
                    zeroPrereqs.push(neighborCourse);
            }
        }
        return (takeOrder.size() == numCourses) ? takeOrder : vector<int>();
    }
};