/*
Number: 696
Topic: Count Binary Substrings
Date: 2021/9/23
Rate: Easy
https://leetcode.com/problems/count-binary-substrings/

Give a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Constraints:
    * 1 <= s.length <= 105
    * s[i] is either '0' or '1'.
*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0;
        int curCount = 1;
        int prevCount = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i-1] == s[i]) {
                curCount += 1;
            } else {
                result += min(curCount, prevCount);
                prevCount = curCount;
                curCount = 1;
            }
        }
        return result + min(curCount, prevCount);
    }
};