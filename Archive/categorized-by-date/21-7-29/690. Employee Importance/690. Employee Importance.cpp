/*
Number: 690
Topic: Employee Importance
Date: 2021/7/29
Rate: Easy
https://leetcode.com/problems/employee-importance/

You have a data structure of employee information, which includes the employee's unique id, their importance value, and their direct subordinates' id.

You are given an array of employees employees where:
* employees[i].id is the ID of the ith employee.
* employees[i].importance is the importance value of the ith employee.
* employees[i].subordinates is a list of the IDs of the subordinates of the ith employee.

Given an integer id that represents the ID of an employee, return the total importance value of this employee and all their subordinates.

Constraints:
* 1 <= employees.length <= 2000
* 1 <= employees[i].id <= 2000
* All employees[i].id are unique.
* -100 <= employees[i].importance <= 100
* One employee has at most one direct leader and may have several subordinates.
* id is guaranteed to be a valid employee id.
*/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, int> idToIdx;
        for (int i = 0; i < employees.size(); i++) {
            idToIdx[employees[i]->id] = i;
        }

        int out = 0;

        queue<Employee*> q;
        q.push(employees[idToIdx[id]]);

        while (!q.empty()) {
            Employee* curE = q.front();
            q.pop();

            out += curE->importance;
            for (const int& surId : curE->subordinates) {
                q.push(employees[idToIdx[surId]]);
            }
        }
        return out;
    }
};