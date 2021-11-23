/*
Number: 6
Topic: ZigZag Conversion
Date: 2021/5/28
Rate: Medium
https://leetcode.com/problems/zigzag-conversion/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

Constraints:
* 1 <= s.length <= 1000
* s consists of English letters (lower-case and upper-case), ',' and '.'.
* 1 <= numRows <= 1000

*/

class Solution {
public:
    string convert(string s, int numRows) {
        // 把 (numRows)直的下來的 + (numRows-2)橫的上去的視為一組
        int set = max(1, numRows*2 - 2);
        vector<string> out(set, "");
        // 看是被分到哪組
        for (int i = 0; i < s.size(); i++) {
            out[i%set] += s[i];
        }

        for (int i = set-1, n = 1; i >= numRows; i--, n++) {
            string temp;
            for (int x = 0; x < out[n].size(); x++){
                // [1, numRows) 和 [numRows, set) 交互組成 [1, numRows) 的最後字串
                // 因為是 ZigZag 所以實際上是 1 對上 set-1 組， 2 對上 set-2組
                temp += out[n][x];
                if (x < out[i].size())
                    temp += out[i][x];
            }
            out[n] = temp;
        }
        // 全部合在一起
        for (int i = 1; i < numRows; i++) {
            out[0] += out[i];
        }
        return out[0];
    }
};