/*
Number: 630
Topic: Course Schedule III
Date: 2021/7/7
Rate: Hard
https://leetcode.com/problems/course-schedule-iii/

There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.

You will start on the 1st day and you cannot take two or more courses simultaneously.

Return the maximum number of courses that you can take.


Constraints:
* 1 <= courses.length <= 104
* 1 <= durationi, lastDayi <= 104

*/
struct comparator {
    bool operator()(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1]; 
    }
};

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comparator());

        priority_queue<int> maxHeap;
        int time = 0;

        for (const vector<int>& course : courses) {
            int duration = course[0];
            int end = course[1];

            time += duration;
            maxHeap.push(duration);

            if (time > end) {
                time -= maxHeap.top();
                maxHeap.pop();
            }
        }
        return maxHeap.size();
    }
};
