/*
Number: 1010
Topic: Pairs of Songs With Total Durations Divisible by 60
Date: 2021/11/16
Rate: Medium
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

Constraints:
    * 1 <= time.length <= 6 * 104
    * 1 <= time[i] <= 500
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> modResults(60, 0);
        int result = 0;

        for (int song : time) {
            int modResult = song % 60;
            int offsetTo60 = (60 - modResult) % 60;
            result += modResults[offsetTo60];
            modResults[modResult] += 1;
        }

        return result;
    }
};