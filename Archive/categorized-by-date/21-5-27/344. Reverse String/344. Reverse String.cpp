/*
Number: 344
Topic: Reverse String
Date: 2021/5/27
Rate: Easy
https://leetcode.com/problems/reverse-string/

Write a function that reverses a string. The input string is given as an array of characters s.

Follow up: Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

Constraints:

* 1 <= s.length <= 105
* s[i] is a printable ascii character.

*/


class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0; i < (s.size()/2); i++) {
            swap(s[i], s[s.size()-i-1]);
        }
    }
};