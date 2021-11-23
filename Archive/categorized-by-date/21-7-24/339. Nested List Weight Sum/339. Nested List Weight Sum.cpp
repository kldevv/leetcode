/*
Number: 339
Topic: Nested List Weight Sum
Date: 2021/7/24
Rate: Medium
https://leetcode.com/problems/nested-list-weight-sum/

You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists.

The depth of an integer is the number of lists that it is inside of. For example, the nested list [1,[2,2],[[3],2],1] has each integer's value set to its depth.

Return the sum of each integer in nestedList multiplied by its depth.

Constraints:
* 1 <= nestedList.length <= 50
* The values of the integers in the nested list is in the range [-100, 100].
* The maximum depth of any integer is less than or equal to 50.
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        queue<vector<NestedInteger>> q;
        q.push(nestedList);

        int depth = 1;
        int sum = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                vector<NestedInteger> nest = q.front();
                q.pop();

                for (int j = 0; j < nest.size(); j++) {
                    if (nest[j].isInteger())
                        sum += nest[j].getInteger() * depth;
                    else
                        q.push(nest[j].getList());
                }
            }
            depth += 1;
        }
        return sum;
    }
};