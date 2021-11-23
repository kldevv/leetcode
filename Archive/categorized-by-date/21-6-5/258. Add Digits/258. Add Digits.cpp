/*
Number: 258
Topic: Add Digits
Date: 2021/6/5
Rate: Easy
https://leetcode.com/problems/add-digits/

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

Constraints:
* 0 <= num <= 231 - 1

Follow up: Could you do it without any loop/recursion in O(1) runtime?

*/

class Solution {
public:
    // digit root problem
    // refer to: https://leetcode.com/problems/add-digits/discuss/?currentPage=1&orderBy=most_votes&query=
    // also: https://en.wikipedia.org/wiki/Digital_root
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};