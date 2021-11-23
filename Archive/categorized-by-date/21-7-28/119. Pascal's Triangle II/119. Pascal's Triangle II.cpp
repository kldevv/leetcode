/*
Number: 119
Topic: Pascal's Triangle II
Date: 2021/7/28
Rate: Easy
https://leetcode.com/problems/pascals-triangle-ii/

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Constraints:
* 0 <= rowIndex <= 33
 
Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?

*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> out(rowIndex+1, 0);
        out[0] = 1;
        for (int i = 0; i < rowIndex; i++) {
            int j = 1;
            int prev = out[0];
            for (; j < out.size() && out[j]; j++) {
                int temp = out[j];
                out[j] += prev;
                prev = temp;
            }
            if (j < out.size())
                out[j] = 1;
        }
        return out;
    }
};