/*
Number: 1417
Topic: Reformat The String
Date: 2021/7/28
Rate: Easy
https://leetcode.com/problems/reformat-the-string/

Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

Return the reformatted string or return an empty string if it is impossible to reformat the string.

Constraints:
* 1 <= s.length <= 500
* s consists of only lowercase English letters and/or digits.

*/
class Solution {
public:
    string reformat(string s) {
        string al = "";
        string num = "";

        for (const char& c : s) {
            if (isalnum(c)) {
                if (isdigit(c))
                    al += c;
                else
                    num += c;
            }
        }

        string out = zigzagConcat(al, num);

        return out;
    }

    string zigzagConcat(string s1, string s2) {
        if (abs((int)s1.size()-(int)s2.size()) > 1)
            return "";

        if (s1.size() < s2.size())
            return zigzagConcat(s2, s1);

        string out;
        int i = 0;
        for (; i < s2.size(); i++) {
            out += s1[i];
            out += s2[i];
        }
        if (i < s1.size())
            out += s1[i];

        return out;
    }
};