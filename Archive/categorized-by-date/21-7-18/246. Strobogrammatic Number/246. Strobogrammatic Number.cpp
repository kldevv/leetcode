/*
Number: 246
Topic: Strobogrammatic Number
Date: 2021/7/18
Rate: Easy
https://leetcode.com/problems/strobogrammatic-number/

Given a string num which represents an integer, return true if num is a strobogrammatic number.

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Constraints:
* 1 <= num.length <= 50
* num consists of only digits.
* num does not contain any leading zeros except for zero itself.
*/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> umap {{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};

        int i = 0, j = num.size()-1;
        while (i <= j) {
            if (!umap.count(num[i]) || umap[num[i++]] != num[j--])
                return false;
        }
        return true;
    }
};