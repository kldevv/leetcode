/*
Number: 370
Topic: Range Addition
Date: 2021/7/26
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

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> out(length, 0);
        for (int i = 0; i < updates.size(); i++) {
            int start = updates[i][0];
            int end = updates[i][1];
            int inc = updates[i][2];
            out[start] += inc;
            if (end < length-1)
                out[end+1] -= inc;
        }

        for (int j = 1; j < length; j++) {
            out[j] += out[j-1];
        }
        return out;
    }
};