/*
Number: 828
Topic: Count Unique Characters of All Substrings of a Given String
Date: 2021/9/28
Rate: Hard
https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/

Let's define a function countUniqueChars(s) that returns the number of unique characters on s.
    * For example if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
Given a string s, return the sum of countUniqueChars(t) where t is a substring of s.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.

Constraints:
    * 1 <= s.length <= 105
    * s consists of uppercase English letters only.
*/

class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> last2Indx(26, vector<int>(2, -1));
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'A';
            result += (last2Indx[idx][1] - last2Indx[idx][0]) * (i - last2Indx[idx][1]);
            swap(last2Indx[idx][1], last2Indx[idx][0]);
            last2Indx[idx][1] = i;
        }
        for (int i = 0; i < 26; i++) {
            result += (last2Indx[i][1] - last2Indx[i][0]) * (s.size() - last2Indx[i][1]);
        }
        return result;
    }
}; 