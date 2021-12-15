/*
<LeetCodePracticeC++>
    
- Name: 1136. Parallel Courses
- Difficulty: Medium
- URL: https://leetcode.com/problems/parallel-courses/
- Description: 
    
    You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given an array relations where relations[i] = [prevCoursei, nextCoursei], representing a prerequisite relationship between course prevCoursei and course nextCoursei: course prevCoursei has to be taken before course nextCoursei.

    In one semester, you can take any number of courses as long as you have taken all the prerequisites in the previous semester for the courses you are taking.

    Return the minimum number of semesters needed to take all courses. If there is no way to take all the courses, return -1.
    
- Constraints:
    - 1 <= n <= 5000
    - 1 <= relations.length <= 5000
    - relations[i].length == 2
    - 1 <= prevCoursei, nextCoursei <= n
    - prevCoursei != nextCoursei
    - All the pairs [prevCoursei, nextCoursei] are unique.

- Date: 12/12/2021

</LeetCodePracticeC++>
*/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        /*
        - Clarification:
            - pair = [prev, next]
            - ranging from 1 to n
        - Idea:
            - BFS + Topological Sort

        - How:
            Init graph, degree, zeroDeg, t = 0;
            
            graph[prev] = [nexts ...]
            degree[course] = int numItsPrev

            while (zeroDeg):
                int k = zeroDeg;
                for i in range(k):
                    Take(zeroDeg.Pop());
                    n -= 1;
                    if degree[neighbor] == 0:
                        ZeroDeg.Add(neighbor);
                    
                    t += 1;
            return t if n == 0 else -1
        */

        // Complexity
        // T(V, E) = O(V + E)
        // S(V, E) = O(V + E)

        vector<vector<int>> graph(n, vector<int>());
        vector<int> degree(n, 0);

        for (vector<int> pair : relations) {
            graph[pair[0]-1].push_back(pair[1]-1);
            degree[pair[1]-1] += 1;
        }

        queue<int> zeroDeg;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) {
                zeroDeg.push(i);
            }
        }

        int semester = 0;
        while (zeroDeg.size()) {
            int thisCoursesNum = zeroDeg.size();
            semester += 1;
            for (int i = 0; i < thisCoursesNum; i++) {
                int toTake = zeroDeg.front();
                zeroDeg.pop();
                n -= 1;
                for (int neighbor : graph[toTake]) {
                    if (--degree[neighbor] == 0) {
                        zeroDeg.push(neighbor);
                    }
                }
            }
        }
        return (n == 0) ? semester : -1;
    }
};
