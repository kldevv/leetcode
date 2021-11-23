/*
Number: 168
Topic: Excel Sheet Column Title
Date: 2021/5/29
Rate: Easy
https://leetcode.com/problems/excel-sheet-column-title/

Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...


Constraints:
* 1 <= columnNumber <= 2^31 - 1

*/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        return (columnNumber == 0) ? "" : convertToTitle((columnNumber-1)/26) + (char)((columnNumber-1)%26+'A');
    }
};