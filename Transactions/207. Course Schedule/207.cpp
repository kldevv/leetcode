/*
<LeetCodePracticeC++>
    
- Name: 207. Course Schedule
- Difficulty: Medium
- URL: https://leetcode.com/problems/course-schedule/
- Description: 

    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

        - For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
    
    Return true if you can finish all courses. Otherwise, return false.
    

- Constraints:
    - 1 <= numCourses <= 105
    - 0 <= prerequisites.length <= 5000
    - prerequisites[i].length == 2
    - 0 <= ai, bi < numCourses
    - All the pairs prerequisites[i] are unique.

- Date: 12/12/2021

</LeetCodePracticeC++>
*/

#include <queue> // zeroDeg
#include <vector> // graph

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
        - Clarification:
            - prereqPair = [course, prereq], ranging from 0 to (numCourses-1);
            - return true if finish all course, numCourses;
            - return false otherwise;
            - Will there be [courseA, courseA] ? => return false;
            - What if we take more than numCourses?

        - Topological Sorting 
            - graph:
                - graph[prereq] = [courses ...];
            - degrees:
                - degree[course] = int num;
            
            zeroDeg = queue()
            while (zeroDeg):
                zeroDeg.pop();
                numCourses -= 1;
                Take(zeroDeg);
                    if any degree[course] == 0:
                        zeroDeg.Add(course)
            return numCourses == 0;
        */
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);

        for (vector<int> pair : prerequisites)  {
            graph[pair[1]].push_back(pair[0]);
            degree[pair[0]] += 1;
        }

        queue<int> courseQueue;
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) {
                courseQueue.push(i);
            }
        }

        while (courseQueue.size()) {
            int takeCourse = courseQueue.front();
            courseQueue.pop();
            numCourses -= 1;

            for (int neighbor : graph[takeCourse]) {
                if (--degree[neighbor] == 0) {
                    courseQueue.push(neighbor);
                }
            }
        }

        return numCourses <= 0;
    }
};