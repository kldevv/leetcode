/*
Number: 1513
Topic: Number of Substrings With Only 1s
Date: 2021/11/26
Rate: Medium
https://leetcode.com/problems/number-of-substrings-with-only-1s/

Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 109 + 7.

Constraints:
    * 1 <= s.length <= 105
    * s[i] is either '0' or '1'.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int numSub(string s) {
        /* 
        Sliding Windows (inclusive, inclusive);
        Actions:
            count # of non-1 in the current windows
        Valid Actions:
            record # of subarrays end at tail
            move tail

        Invalid Actions:
            move head

        %%%%%%%%%%%%%%%%%%%%
        Complexity:
            - Time:
                O(s.size())
            - Space:
                O(1)
        */
        const int MOD = 1e9 + 7;
        int head = 0;
        int tail = 0;
        int countValidArr = 0;
        int countNonOne = 0;

        for (; tail < s.size(); tail++) {
            countNonOne += (s[tail] != '1');
            while (head <= tail && countNonOne > 0) {
                countNonOne -= (s[head++] != '1');
            }
            countValidArr += (tail - head + 1);
            countValidArr %= MOD;
        }
        return countValidArr;
    }
};
