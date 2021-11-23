/*
Number: 167
Topic: Excel Sheet Column Number
Date: 2021/5/29
Rate: Easy
https://leetcode.com/problems/excel-sheet-column-number/

Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

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
* 1 <= columnTitle.length <= 7
* columnTitle consists only of uppercase English letters.
* columnTitle is in the range ["A", "FXSHRXW"].

*/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int idx = columnTitle.size()-1;
        int base = 1;
        int out = 0;
        // keep the rolling base
        // 每上一層級(往左) 就多一個 26 的 base 如 AZ = 1*26^1 + 26, 而 BAZ = 2*26^2 + 1*26^1 + 26
        while (idx >= 0) {
            out += (columnTitle[idx--] - 'A' + 1) * base;
            if (idx < 0)
                base *= 26;
        }
        return out;
    }
};