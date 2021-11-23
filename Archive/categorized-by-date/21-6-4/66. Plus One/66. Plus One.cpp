/*
Number: 66
Topic: Plus One
Date: 2021/6/4
Rate: Easy
https://leetcode.com/problems/plus-one/

Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Constraints:
* 1 <= digits.length <= 100
* 0 <= digits[i] <= 9

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i =  digits.size()-1; i >=0 ; i--) {
            // 如果小於九就加一回傳
            // 如果等於九，就設為 0 ，往前走一位數
            if (digits[i]++ == 9)
                digits[i] = 0;
            else
                return digits;
        }
        // 全部迴圈跑完，代表是 9 / 99 / 999，這種全部都是 9 的。第一位數一定是 0
        // 除此以外都是 0，且多一位數，固＋0在尾巴
        digits[0]++;
        digits.push_back(0);
        return digits;
    }
};