/*
<LeetCodePracticeC++>
    
- Name: 630. Course Schedule III
- Difficulty: Hard
- URL: https://leetcode.com/problems/course-schedule-iii/
- Description: 

    There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.

    You will start on the 1st day and you cannot take two or more courses simultaneously.

    Return the maximum number of courses that you can take.
    
- Constraints:
    - 1 <= courses.length <= 104
    - 1 <= durationi, lastDayi <= 104

- Date: 12/12/2021

</LeetCodePracticeC++>
*/

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        /*
        Greedy ? 
        
        A (durationA, dueA)
        B (durationB, dueB)
        Assume durationN < dueN for any given course N
        
        Scenarios
            - Can take both courses: -> sort by due -> greedily take course that dues first until we can't match any due
                - 1. (durationA + durationB) <= dueA && (durationA + durationB) <= dueB
                    - Orders doesn't matter
                - 2. (durationA + durationB) <= dueA but (durationA + durationB) > dueB, durationB < dueB
                    - Orders does matter, we take B first (due first)
                - 3. (durationA + durationB) <= dueB but (durationA + durationB) > dueA, durationA < dueA
                    - Orders does matter, we take A first (due first)
                - 2. and 3. are the same, we take course that dues first
            - Can take only one course: -> MaxHeap -> pop the longest duration so far
                - 4. (durationA + durationB) > dueA && (durationA + durationB) > dueB
                    - We take shorter duration
        */
        sort(courses.begin(), courses.end(), 
            [](vector<int>& v1, vector<int>& v2) {
                return v1[1] < v2[1];
            });

        priority_queue<int> maxHeap;
        // Use to store all the durations we have so far.
        // maxHeap.top() will be the most inefficient course,
        // If scenario 4, we discard the most inefficient course.

        int currentTime = 0;
        // To compare with due.

        for (vector<int> courseInfo : courses) {
            int duration = courseInfo[0];
            int due = courseInfo[1];

            maxHeap.push(duration);
            currentTime += duration;

            // scenario 4
            if (maxHeap.size() && due < currentTime) {
                currentTime -= maxHeap.top();
                maxHeap.pop();
            }
        }
        int numCourseTaken = maxHeap.size();

        return numCourseTaken;
    }
};
