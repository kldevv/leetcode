/*
Number: 715
Topic: Range Module
Date: 2021/8/20
Rate: Hard
https://leetcode.com/problems/range-module/

A Range Module is a module that tracks ranges of numbers. Design a data structure to track the ranges represented as half-open intervals and query about them.

A half-open interval [left, right) denotes all the real numbers x where left <= x < right.

Implement the RangeModule class:

RangeModule() Initializes the object of the data structure.
void addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
boolean queryRange(int left, int right) Returns true if every real number in the interval [left, right) is currently being tracked, and false otherwise.
void removeRange(int left, int right) Stops tracking every real number currently being tracked in the half-open interval [left, right).

Constraints:
* 1 <= left < right <= 109
* At most 104 calls will be made to addRange, queryRange, and removeRange.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class RangeModule {
private:
    map<int, int> intervals;
public:
    RangeModule() {

    }
    
    void addRange(int left, int right) {
        removeRange(left, right);
        intervals[left] = right;

        auto it = intervals.find(left);
        // if it overlapped with the front
        if (it != intervals.begin() && prev(it)->second == left) {
            // extend the front
            it--;
            it->second = right;
            // delete the newly added intervals, the front now be asssigned as the newly added intervals
            intervals.erase(left);
        }
        // if it overlapped with the back
        if (it != prev(intervals.end()) && next(it)->first == right) {
            // extend the newly added intervals to cover the back
            it->second = next(it)->second;
            // erase the back
            intervals.erase(right);
        }
    }
    
    bool queryRange(int left, int right) {
        if (intervals.empty())
            return false;

        auto it = intervals.upper_bound(left);
        // the first element is already bigger than left; left can't be contains
        if (it == intervals.begin())
            return false;

        // prev(it) is either equals to left or smaller than left
        return prev(it)->second >= right;
    }
    
    void removeRange(int left, int right) {
        if (intervals.empty())
            return;

        auto it = intervals.lower_bound(left);
        if (it != intervals.begin())
            it--;

        vector<int> toBeDeleted;
        while (it != intervals.end() && it->first < right) {
            if (it->first < left && it->second > left) {
                if (it->second > right)
                    intervals[right] = it->second;
                it->second = left;
            }
            else if (it->first >= left) {
                if (it->second > right)
                    intervals[right] = it->second;
                toBeDeleted.push_back(it->first);
            }
            it++;
        }

        for (int del : toBeDeleted)
            intervals.erase(del);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */