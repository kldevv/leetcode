/*
Number:58
Topic: Length of Last Word
Date: 2021/5/26
Rate: Easy
https://leetcode.com/problems/length-of-last-word/

Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.

*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = s.size()-1;
        while (i >=0 && s[i] == ' ') {
            i--;
        }
        while (i >= 0) {
            if (s[i--] != ' ') 
                count++;
            else
                break;
        }
        return count;
    }
};