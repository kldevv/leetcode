/*
Number: 393
Topic: UTF-8 Validation
Date: 2021/6/28
Rate: Medium
https://leetcode.com/problems/utf-8-validation/

Given an integer array data representing the data, return whether it is a valid UTF-8 encoding.

A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

1. For a 1-byte character, the first bit is a 0, followed by its Unicode code.
2. For an n-bytes character, the first n bits are all one's, the n + 1 bit is 0, followed by n - 1 bytes with the most significant 2 bits being 10.

This is how the UTF-8 encoding would work:

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

Note: The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.

Constraints:
* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 300
* grid[i][j] is '0' or '1'.

*/

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for (const int& byte : data) {
            // 這個是 utf-8 的 leading byte
            if (count == 0) {
                if ((byte >> 3) == 0b11110)
                    count = 3;
                else if ((byte >> 4) == 0b1110)
                    count = 2;
                else if ((byte >> 5) == 0b110)
                    count = 1;
                else if ((byte >> 7) == 0b1)
                    return false;
            }
            else {
                // 如果不是 leading byte 開頭又不是 10 的話，就搞砸拉
                if (byte >> 6 != 0b10)
                    return false;
                count--;
            }
        }
        return count == 0;
    }
};