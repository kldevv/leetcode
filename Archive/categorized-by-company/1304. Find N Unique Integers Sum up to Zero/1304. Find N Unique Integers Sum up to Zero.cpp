/*
Number: 1304
Topic: Find N Unique Integers Sum up to Zero
Date: 2021/9/1
Rate: Easy
https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

Given an integer n, return any array containing n unique integers such that they add up to 0.

Constraints:
* 1 <= n <= 1000
*/

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        for (int i = 1; i <= n / 2; i++) {
            result.push_back(i);
            result.push_back(i*-1);
        }
        if (result.size() < n)
            result.push_back(0);
        return result;
    }
};