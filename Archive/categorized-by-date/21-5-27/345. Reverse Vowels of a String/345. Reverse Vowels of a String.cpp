/*
Number: 345
Topic: Reverse Vowels of a String
Date: 2021/5/27
Rate: Easy
https://leetcode.com/problems/reverse-vowels-of-a-string/


Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.

Constraints:

* 1 <= s.length <= 3 * 105
* s consist of printable ASCII characters.
*/


class Solution {
public:
    // two pointer swap
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            while (i < j && !isVowel(s[i])) {
                i++;
            }

            while (i < j && !isVowel(s[j])) {
                j--;
            }
            if (i < j)
                swap(s[i++], s[j--]);
        }
        return s;
    }
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
};






