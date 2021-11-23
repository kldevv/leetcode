/*
Number: 526
Topic: Beautiful Arrangement
Date: 2021/9/8
Rate: Medium
https://leetcode.com/problems/beautiful-arrangement/

Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

    * perm[i] is divisible by i.
    * i is divisible by perm[i].

Given an integer n, return the number of the beautiful arrangements that you can construct.
*/

class Solution {
public:
    int countArrangement(int n) {
        vector<int> nums(n+1, 0);
        for (int i = 0; i <= n; i++) {
            nums[i] = i;
        }

        int count = 0;
        countArrangement(nums, n, count);
        return count;
    }

    void countArrangement(vector<int> nums, int start, int& count) {
        if (start == 0) {
            count += 1;
            return;
        }

        for (int i = start; i > 0; i--) {
            swap(nums[start], nums[i]);
            if (start % nums[start] == 0 || nums[start] % start == 0)
                countArrangement(nums, start-1, count);
            swap(nums[i], nums[start]);
        }
    }


};