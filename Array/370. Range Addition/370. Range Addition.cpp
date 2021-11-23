/*
Number: 370
Topic: Range Addition
Date: 2021/11/15
Rate: Medium
https://leetcode.com/problems/range-addition/

You are given an integer length and an array updates where updates[i] = [startIdxi, endIdxi, inci].

You have an array arr of length length with all zeros, and you have some operation to apply on arr. In the ith operation, you should increment all the elements arr[startIdxi], arr[startIdxi + 1], ..., arr[endIdxi] by inci.

Return arr after applying all the updates.

Constraints:
    * 1 <= length <= 105
    * 0 <= updates.length <= 104
    * 0 <= startIdxi <= endIdxi < length
    * -1000 <= inci <= 1000
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length, 0);
        for (vector<int> update : updates) {
            int startIdx = update[0];
            int endIdx = update[1];
            int val = update[2];

            result[startIdx] += val;
            if (endIdx + 1 < length)
                result[endIdx + 1] -= val;
        }

        for (int i = 1; i < length; i++) {
            result[i] += result[i - 1];
        }
        return result;
    }
};