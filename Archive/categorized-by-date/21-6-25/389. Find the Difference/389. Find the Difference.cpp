/*
Number: 278
Topic: First Bad Version
Date: 2021/6/25
Rate: Easy
https://leetcode.com/problems/first-bad-version/


You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Constraints:
* 0 <= s.length <= 1000
* t.length == s.length + 1
* s and t consist of lower-case English letters.


*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        char out = 0;
        for (const char& c : s)
            out ^= c;
        for (const char& c : t)
            out ^= c;
        return out;
    }
};