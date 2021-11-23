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
* 1 <= bad <= n <= 23^1 - 1


*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1;
        int j = n;

        // lower_bound binary search
        while (i < j) {
            int m = i + (j-i)/2;
            if (isBadVersion(m))
                j = m;
            else
                i = m+1;
        }
        return j;
    }
};