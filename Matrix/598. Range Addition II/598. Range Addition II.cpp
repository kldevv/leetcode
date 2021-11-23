/*
Number: 598
Topic: Range Addition II
Date: 2021/11/15
Rate: Easy
https://leetcode.com/problems/range-addition-ii/

You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.

Count and return the number of maximum integers in the matrix after performing all the operations.

Constraints:
    * 1 <= m, n <= 4 * 104
    * 0 <= ops.length <= 104
    * ops[i].length == 2
    * 1 <= ai <= m
    * 1 <= bi <= n
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minRow = m;
        int minCol = n;

        for (vector<int> op : ops) {
            minRow = min(minRow, op[0]);
            minCol = min(minCol, op[1]);
        }
        return minRow * minCol;
    }
};