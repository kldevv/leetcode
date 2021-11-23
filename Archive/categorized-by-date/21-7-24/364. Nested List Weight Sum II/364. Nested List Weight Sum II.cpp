/*
Number: 364
Topic: Nested List Weight Sum II
Date: 2021/7/24
Rate: Medium
https://leetcode.com/problems/nested-list-weight-sum-ii/

You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists.

The depth of an integer is the number of lists that it is inside of. For example, the nested list [1,[2,2],[[3],2],1] has each integer's value set to its depth. Let maxDepth be the maximum depth of any integer.

The weight of an integer is maxDepth - (the depth of the integer) + 1.

Return the sum of each integer in nestedList multiplied by its weight.

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
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int weighted = 0;
        int unweighted = 0;

        queue<vector<NestedInteger>> q;
        q.push(nestedList);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                vector<NestedInteger> nest = q.front();
                q.pop();

                for (int j = 0; j < nest.size(); j++) {
                    if (nest[j].isInteger())
                        unweighted += nest[j].getInteger();
                    else
                        q.push(nest[j].getList());
                }
            }
            weighted += unweighted;
        }
        return weighted;
    }
};